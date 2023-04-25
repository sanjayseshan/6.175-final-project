import BRAM::*;
import FIFO::*;
import FIFOF::*;
import SpecialFIFOs::*;
import MemTypes::*;
import Ehr::*;
// import SearchFIFO::*;

typedef Bit#(7) IndexAddr;


typedef struct { 
  Bit#(19) tag; 
  IndexAddr idx; 
  MainMemReq memReq;
  // Bit#(4) offset; 
} CacheReq deriving (Eq, Bits);


typedef struct { 
  Bit#(2) valid;
  Bit#(19) tag;
  Bit#(512) data;
} CacheReqLine deriving (Eq, Bits);

typedef struct { 
  Bit#(26) addr;
  Bit#(512) data;
} StbReq deriving (Eq, Bits);

function CacheReq extract_bits(LineAddr addr, MainMemReq e);
  let tag = addr[25:7];
  // let offset = addr[3:0];
  IndexAddr index = addr[6:0];
  return CacheReq{tag:tag,idx:index,memReq:e};
endfunction


interface Cache;
    method Action putFromProc(MainMemReq e);
    method ActionValue#(MainMemResp) getToProc();
    method ActionValue#(MainMemReq) getToMem();
    method Action putFromMem(MainMemResp e);
endinterface

module mkCache(Cache);
  BRAM_Configure cfg = defaultValue;
  BRAM1Port#(IndexAddr, CacheReqLine) bram <- mkBRAM1Server(cfg);


  Reg#(CacheReq) working <- mkReg(unpack(0));
  Reg#(Bool) working_v <- mkReg(False);

  FIFO#(MainMemResp) hitQ <- mkFIFO();
  Reg#(MainMemReq) missReq <- mkReg(unpack(0));
  Reg#(Bit#(2)) mshr <- mkReg(0);

  FIFO#(MainMemReq) memReqQ <- mkFIFO();
  FIFOF#(MainMemResp) memRespQ <- mkFIFOF();

  FIFOF#(StbReq) stb <- mkFIFOF();

  Reg#(CacheReqLine) working_line <- mkReg(unpack(0));

  // Ehr#(2, Bool) lockL1 <- mkEhr(False);

  Reg#(Bool) lockL1 <- mkReg(True);



  Reg#(Bit#(32)) cycle <- mkReg(0);
  rule count;
    cycle <= cycle+1;
    $display("CYCLE ",cycle, " " , fshow(working_v), " ", mshr, fshow(lockL1));
  endrule

  rule req_process (working_v && mshr == 0 && lockL1);
    $display("req_process");


    let out <- bram.portA.response.get();
    working_line <= out;

    if (working.memReq.write == 0) begin
      let x = stb.first;
      // let x = stb.search_res(working.memReq.addr);
      if (stb.notEmpty() && x.addr == working.memReq.addr) begin
        hitQ.enq(x.data);
        $display("READ HIT Q");
        working_v <= False;
      end 
      else if (out.tag==working.tag && out.valid != 0) begin
        hitQ.enq(out.data);
        $display("READ HIT");
        working_v <= False;
      end else begin
        missReq <= working.memReq;
        mshr <= 1;
      end
    end else begin
      stb.enq(StbReq{addr:working.memReq.addr,data:working.memReq.data});
      lockL1 <= False;
    end
  endrule

  rule mvStbToL1 (mshr == 0 && !lockL1);
    $display("mvStbToL1");
    let e = stb.first;
    let bits = extract_bits(e.addr, ?);
    stb.deq();

    if (bits.tag == working_line.tag) begin
      bram.portA.request.put(BRAMRequest{write: True, // False for read
                      responseOnWrite: False,
                      address: working.idx,
                      datain: CacheReqLine{valid:2,tag:bits.tag,data:e.data}});
      working_v <= False;

    end else begin
      missReq <= MainMemReq{write:1,addr:e.addr,data:e.data};
      mshr <= 1;
    end
    lockL1 <= True;
  endrule

  // rule clearL1Lock;
  //   lockL1[1] <= False;
  // endrule

  rule startMiss(mshr==1);
    $display("startMiss",mshr,fshow(working.memReq));
    if (working_line.valid == 2) begin
      $display("MISS DIRTY");
      memReqQ.enq(MainMemReq{write:1, addr:{working_line.tag,working.idx},data:working_line.data});
    end
    mshr <= 2;
  endrule

  rule sendFillReq(mshr == 2);
    $display("sendFillReq");

      $display("MISS GET FROM MEM");
      memReqQ.enq(working.memReq);
      mshr <= 3;
  endrule

  Reg#(Bool) start_fill <- mkReg(False);
  // Reg#(Bit#(512)) fill_data <- mkReg(0);

  rule waitFillResp_Ld(mshr==3 && start_fill && working.memReq.write == 0);
    $display("waitFillResp_ld");

    // let data = fill_data;
    let m_working_req = working.memReq;
    if (memRespQ.notEmpty()) begin
      let data = memRespQ.first;
      $display("READ MISS", fshow(data)); 
      bram.portA.request.put(BRAMRequest{write: True, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: CacheReqLine{valid:1,tag:working.tag,data:data}});
      hitQ.enq(data);
      working_v <= False;
      mshr <= 0;
      memRespQ.deq();
      start_fill <= False;

    end 
  endrule



  rule waitFillResp_St(mshr==3 && working.memReq.write == 1);
    $display("waitFillResp_st");

    // let data = fill_data;
    let m_working_req = working.memReq;
  
    $display("WRITE MISS", fshow(working.memReq.data)); 
    bram.portA.request.put(BRAMRequest{write: True, // False for read
              responseOnWrite: False,
              address: working.idx,
              datain: CacheReqLine{valid:1,tag:working.tag,data:working.memReq.data}});
    working_v <= False;
    mshr <= 0;
    start_fill <= False;
  endrule

  // TODO Write a Cache
  method Action putFromProc(MainMemReq e) if (!working_v && mshr == 0);
  
    $display("PFP ",fshow(e));
    let req = extract_bits(e.addr, e);
    bram.portA.request.put(BRAMRequest{write: False, // False for read
                        responseOnWrite: False,
                        address: req.idx,
                        datain: ?});
    working <= req;
    working_v <= True;
  endmethod

  method ActionValue#(MainMemResp) getToProc();
    hitQ.deq();
    let r = hitQ.first;
    $display("GTP ", fshow(r));
    return r;
  endmethod

  method ActionValue#(MainMemReq) getToMem() ;
    memReqQ.deq();
    let r = memReqQ.first;
    $display("GTM ",fshow(r));
    return r;
  endmethod

  method Action putFromMem(MainMemResp e) if(!start_fill);
    start_fill <= True;
    $display("PFM ",fshow(e));
    memRespQ.enq(e);
    // fill_data <= e;
  endmethod


endmodule