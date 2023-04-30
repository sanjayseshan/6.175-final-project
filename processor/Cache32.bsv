import BRAM::*;
import FIFO::*;
import FIFOF::*;
import SpecialFIFOs::*;
import MemTypes::*;
import Ehr::*;
// import SearchFIFO::*;
import Vector :: * ;

typedef Bit#(7) IndexAddr;


typedef struct { 
  Bit#(19) tag; 
  IndexAddr idx; 
  CacheReq memReq;
  Bit#(4) offset; 
} CacheReqWorking deriving (Eq, Bits);


typedef struct { 
  Bit#(2) valid;
  Bit#(19) tag;
} CacheReqLine deriving (Eq, Bits);



typedef struct { 
  Bit#(32) addr;
  Bit#(32) data;
  Bit#(4) byte_en;
} StbReq deriving (Eq, Bits);

function CacheReqWorking extract_bits(CacheLineAddr addr, CacheReq e);
  let tag = addr[31:13];
  IndexAddr index = addr[12:6];
  let offset = 15-addr[5:2];
  return CacheReqWorking{tag:tag,idx:index,offset:offset,memReq:e};
endfunction

function Vector#(16, Word) lineToWordVec(MainMemResp line);
    // ADDED SECTION
    // added if statement
    // if (memRespQ.notEmpty()) begin
    //   let data = memRespQ.first;

    //   if (bits.offset==15) begin
    //     data = {working.memReq.data, data[479:0]};
    //   end else if (bits.offset==0) begin
    //     data = {data[511:32], working.memReq.data};
    //   end else begin
    //     data = {data[511:32*(bits.offset+1)], working.memReq.data, data[32*bits.offset-1:0]};
    //   end
      // END OF ADDED SECTION

    Vector#(16, Word) ret;
    for (Integer i=0; i < 16; i = i + 1) begin
      ret[i] = line[511-32*i:511-31-32*i];
    end
    return ret;
endfunction

function Bit#(512) vecToLine(Vector#(16, Word) v);
  return {v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15]};
endfunction


interface Cache32;
    method Action putFromProc(CacheReq e);
    method ActionValue#(Word) getToProc();
    method ActionValue#(MainMemReq) getToMem();
    method Action putFromMem(MainMemResp e);
endinterface

module mkCache32(Cache32);
  BRAM_Configure cfg = defaultValue;
  BRAM1Port#(IndexAddr, CacheReqLine) bram1 <- mkBRAM1Server(cfg);
  BRAM1PortBE#(IndexAddr, Vector#(16, Word), 64) bram2 <- mkBRAM1ServerBE(cfg);


  Reg#(CacheReqWorking) working <- mkReg(unpack(0));
  Reg#(Vector#(16, Word)) working_data <- mkReg(unpack(0));

  Reg#(Bool) working_v <- mkReg(False);

  FIFOF#(Word) hitQ <- mkFIFOF();
  // Reg#(CacheReq) missReq <- mkReg(unpack(0));
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
    //$display("CYCLE ",cycle, " " , fshow(working_v), " ", mshr, fshow(lockL1));
  endrule

  rule req_process (working_v && mshr == 0 && lockL1);
    //$display("req_process");


    let out <- bram1.portA.response.get();
    working_line <= out;
    let data <- bram2.portA.response.get();
    working_data <= data;

    if (working.memReq.word_byte == 0) begin
      let x = stb.first;
      // let x = stb.search_res(working.memReq.addr);
      if (stb.notEmpty() && x.addr == working.memReq.addr) begin
        hitQ.enq(x.data); // CHANGED FROM x.data
        //$display("READ HIT Q");
        working_v <= False;
      end 
      else if (out.tag==working.tag && out.valid != 0) begin
        hitQ.enq(data[working.offset]); // CHANGED FROM out.data
        //$display("READ HIT");
        working_v <= False;
      end else begin
        // missReq <= working.memReq;
        mshr <= 1;
      end
    end else if (working.memReq.word_byte == 4'b1111) begin
      stb.enq(StbReq{addr:working.memReq.addr,data:working.memReq.data, byte_en: working.memReq.word_byte});
      lockL1 <= False;
    end 
    else begin
      // let data = out.data;
      let bits = extract_bits(working.memReq.addr, ?);
      let e = working.memReq;

      if (bits.tag == out.tag) begin
        // if (working.memReq.write == 8) data[bits.offset][31:24] = e.data[31:24];
        // if (working.memReq.write == 4) data[bits.offset][23:16] = e.data[23:16];
        // if (working.memReq.write == 2) data[bits.offset][15:8] = e.data[15:8];
        // if (working.memReq.write == 1) data[bits.offset][7:0] = e.data[7:0];
        // if (working.memReq.write == 3) data[bits.offset][15:0] = e.data[15:0];
        // if (working.memReq.write == 12) data[bits.offset][31:16] = e.data[31:16];
        Vector#(16, Word) d_vec=unpack(0);
        d_vec[working.offset] = working.memReq.data; 

        bram2.portA.request.put(BRAMRequestBE{writeen: zeroExtend(working.memReq.word_byte) << working.offset, // False for read
                        responseOnWrite: False,
                        address: working.idx,
                        datain: d_vec}); // CHANGED DATA
        working_v <= False;

        bram1.portA.request.put(BRAMRequest{write: True, // False for read
                        responseOnWrite: False,
                        address: working.idx,
                        datain: CacheReqLine{valid:2,tag:bits.tag}}); // CHANGED DATA

      end else begin
        // missReq <= MainMemReq{write:1,addr:{e.tag,e.idx},data:data}; // CHANGED DATA
        mshr <= 1;
      end
    end
  endrule

  rule mvStbToL1 (mshr == 0 && !lockL1);
    //$display("mvStbToL1");
    let e = stb.first;
    let bits = extract_bits(e.addr, ?);
    stb.deq();

    // ADDED
    // let data = working_line.data;

    // if (bits.offset==15) begin
    //   data = {e.data, data[479:0]};
    // end 
    // else if (bits.offset==0) begin
    //   data = {data[511:32], e.data};
    // end 
    // else begin
    //   data = {data[511:32*(bits.offset+1)], e.data, data[32*bits.offset-1:0]};
    // end
    // END OF ADDED SECTION

    if (bits.tag == working_line.tag) begin
      // data[bits.offset] = e.data;
      Vector#(16, Word) d_vec = unpack(0);
      d_vec[working.offset] = e.data; 

      bram2.portA.request.put(BRAMRequestBE{writeen: (zeroExtend(e.byte_en) << working.offset), // False for read
                      responseOnWrite: False,
                      address: working.idx,
                      datain: d_vec}); // CHANGED DATA

      bram1.portA.request.put(BRAMRequest{write: True, // False for read
                        responseOnWrite: False,
                        address: working.idx,
                        datain: CacheReqLine{valid:2,tag:bits.tag}}); // CHANGED DATA
      working_v <= False;

    end else begin
      // missReq <= MainMemReq{write:1,addr:{e.tag,e.idx},data:data}; // CHANGED DATA
      mshr <= 1;
    end
    lockL1 <= True;
  endrule

  // rule clearL1Lock;
  //   lockL1[1] <= False;
  // endrule

  rule startMiss(mshr==1);
    //$display("startMiss",mshr,fshow(working.memReq));
    if (working_line.valid == 2) begin
      $display("MISS DIRTY");
      memReqQ.enq(MainMemReq{write:1, addr:{working_line.tag,working.idx},data:vecToLine(working_data)}); // original line
    end
    mshr <= 2;
  endrule

  rule sendFillReq(mshr == 2);
    //$display("sendFillReq");

      $display("MISS GET FROM MEM", fshow(working.memReq), fshow({working.tag,working.idx}));
      memReqQ.enq(MainMemReq{write:0, addr:{working.tag,working.idx}, data: ?});
      mshr <= 3;
  endrule

  Reg#(Bool) start_fill <- mkReg(False);
  // Reg#(Bit#(512)) fill_data <- mkReg(0);

  rule waitFillResp_Ld(mshr==3 && start_fill && working.memReq.word_byte == 0);
    //$display("waitFillResp_ld");

    // let data = fill_data;
    let m_working_req = working.memReq;
    if (memRespQ.notEmpty()) begin
      let data = memRespQ.first;
      //$display("READ MISS", fshow(data)); 
      bram1.portA.request.put(BRAMRequest{write: True, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: CacheReqLine{valid:1,tag:working.tag}});
      
      bram2.portA.request.put(BRAMRequestBE{writeen: 64'hffffffffffffffff << working.offset, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: lineToWordVec(data)});
      $display("OFFSET ",fshow(working.offset),fshow(lineToWordVec(data)[working.offset]));

      hitQ.enq(lineToWordVec(data)[working.offset]); // CHANGED FROM data
      working_v <= False;
      mshr <= 0;
      memRespQ.deq();
      start_fill <= False;

    end 
  endrule



  rule waitFillResp_St(mshr==3 && working.memReq.word_byte != 0);
    //$display("waitFillResp_st");

    // let data = fill_data;
    let m_working_req = working.memReq;
    
    // ADDED SECTION
    // added if statement
    if (memRespQ.notEmpty()) begin
      let data = lineToWordVec(memRespQ.first);

      // if (bits.offset==15) begin
      //   data = {working.memReq.data, data[479:0]};
      // end else if (bits.offset==0) begin
      //   data = {data[511:32], working.memReq.data};
      // end else begin
      //   data = {data[511:32*(bits.offset+1)], working.memReq.data, data[32*bits.offset-1:0]};
      // end
      // END OF ADDED SECTION

      data[working.offset] = working.memReq.data;
      Bit#(64) en_bytes = 64'hffffffffffffffff;
      en_bytes[(zeroExtend(working.offset)+1)*16:zeroExtend(working.offset)*16] = working.memReq.word_byte;

      //$display("WRITE MISS", fshow(working.memReq.data)); 
      bram1.portA.request.put(BRAMRequest{write: True, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: CacheReqLine{valid:2,tag:working.tag}}); // CHANGED FROM working.memReq.data

      bram2.portA.request.put(BRAMRequestBE{writeen: en_bytes, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: data}); // CHANGED FROM working.memReq.data
      working_v <= False;
      mshr <= 0;
      start_fill <= False;
      memRespQ.deq();
    end
  endrule

  // TODO Write a Cache
  method Action putFromProc(CacheReq e) if (!working_v && mshr == 0);
  
    //$display("PFP ",fshow(e), fshow(mshr));
    let req = extract_bits(e.addr, e);
    bram1.portA.request.put(BRAMRequest{write: False, // False for read
                        responseOnWrite: False,
                        address: req.idx,
                        datain: ?});
    working <= req;
    working_v <= True;

    //ADDED
    bram2.portA.request.put(BRAMRequestBE{writeen: 0, // False for read
                        responseOnWrite: False,
                        address: req.idx,
                        datain: ?});
  endmethod

  method ActionValue#(Word) getToProc() if (hitQ.notEmpty());
    hitQ.deq();
    let r = hitQ.first;
    //$display("GTP ", fshow(r));
    return r;
  endmethod

  method ActionValue#(MainMemReq) getToMem();
    memReqQ.deq();
    let r = memReqQ.first;
    //$display("GTM ",fshow(r));
    return r;
  endmethod

  method Action putFromMem(MainMemResp e) if(!start_fill);
    start_fill <= True;
    //$display("PFM ",fshow(e));
    memRespQ.enq(e);
    // fill_data <= e;
  endmethod


endmodule