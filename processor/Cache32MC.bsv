// MULTICORE ENABLED L1 CACHE -- CONNECTS TO PPP
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
  // let offset = 15-addr[5:2];
  let offset = addr[5:2];
  return CacheReqWorking{tag:tag,idx:index,offset:offset,memReq:e};
endfunction

function Vector#(16, Word) lineToWordVec(MainMemResp line);
   
    return unpack(line);
endfunction

function Bit#(512) vecToLine(Vector#(16, Word) v);
  return pack(v);
endfunction


interface Cache32MC;
    method Action putFromProc(CacheReq e, Bit#(1) skip_upgrade);
    method ActionValue#(Word) getToProc();
    method ActionValue#(MainMemReq) getToMem();
    method Action putFromMem(MainMemResp e);
    method ActionValue#(CacheReq) getToUpgrade();
endinterface

module mkCache32MC(Cache32MC);
  BRAM_Configure cfg = defaultValue;
  cfg.loadFormat = tagged Binary "zero.vmh";
  BRAM_Configure cfg2 = defaultValue;
  BRAM1Port#(IndexAddr, CacheReqLine) bram1 <- mkBRAM1Server(cfg);
  BRAM1PortBE#(IndexAddr, Vector#(16, Word), 64) bram2 <- mkBRAM1ServerBE(cfg2);


  Reg#(CacheReqWorking) working <- mkReg(unpack(0));
  Reg#(Vector#(16, Word)) working_data <- mkReg(unpack(0));

  Reg#(Bool) working_v <- mkReg(False);

  FIFOF#(Word) hitQ <- mkFIFOF();
  Reg#(Bit#(2)) mshr <- mkReg(0);

  FIFO#(MainMemReq) memReqQ <- mkFIFO();
  FIFOF#(MainMemResp) memRespQ <- mkFIFOF();

  FIFOF#(StbReq) stb <- mkFIFOF();

  FIFOF#(CacheReq) upgrades <- mkFIFOF();

  Reg#(CacheReqLine) working_line <- mkReg(unpack(0));


  Reg#(Bool) lockL1 <- mkReg(True);

  Reg#(Bool) is_downgrade <- mkReg(False);



  // Reg#(Bit#(32)) cycle <- mkReg(0);
  // rule count;
  //   cycle <= cycle+1;
  //   ////$display("CYCLE ",cycle, " " , fshow(working_v), " ", mshr, fshow(lockL1), fshow(is_downgrade));
  // endrule

  rule req_process (working_v && mshr == 0 && lockL1);
    // ////////$display("req_process");


    let out <- bram1.portA.response.get();
    working_line <= out;
    let data <- bram2.portA.response.get();
    working_data <= data;

    // ////$display(fshow(data));


    if (working.memReq.word_byte == 0) begin

      if (out.tag==working.tag && out.valid != 0) begin
        hitQ.enq(data[working.offset]); // CHANGED FROM out.data
        ////$display("READ HIT %x", data[working.offset]);
        working_v <= False;
      end else begin
        // missReq <= working.memReq;
        mshr <= 1;
      end
    end 

    else begin

    // let data = out.data;
      // ////////$display("WORD BYTE NOT 0 OR 1111");
      let bits = extract_bits(working.memReq.addr, ?);
      let e = working.memReq;
      //$display(fshow(bits.tag),fshow(out.tag), fshow(out.valid), fshow(is_downgrade), fshow(bits.offset));


      if (bits.tag == out.tag && out.valid != 0) begin
        if (!is_downgrade) begin
          let data_upgrade = data;
          if(working.memReq.word_byte[0]==1) data_upgrade[working.offset][7:0] = e.data[7:0];
          if(working.memReq.word_byte[1]==1) data_upgrade[working.offset][15:8] = e.data[15:8];
          if(working.memReq.word_byte[2]==1) data_upgrade[working.offset][23:16] = e.data[23:16];
          if(working.memReq.word_byte[3]==1) data_upgrade[working.offset][31:24] = e.data[31:24];
          memReqQ.enq(MainMemReq{write:1, addr:{bits.tag,bits.idx},data:vecToLine(data_upgrade)}); // original line
          //$display("UPGRADE TO ",fshow({working_line.tag,working.idx}), fshow(e));
        end

        Vector#(16, Word) d_vec=unpack(0);
        d_vec[working.offset] = working.memReq.data; 


        Vector#(16, Bit#(4)) port_w=unpack(0);
        d_vec[working.offset] = working.memReq.data; 
        port_w[working.offset] = working.memReq.word_byte;

        bram2.portA.request.put(BRAMRequestBE{writeen: pack(port_w), // False for read
                        responseOnWrite: False,
                        address: working.idx,
                        datain: d_vec}); // CHANGED DATA

        bram1.portA.request.put(BRAMRequest{write: True, // False for read
                        responseOnWrite: False,
                        address: working.idx,
                        datain: CacheReqLine{valid:1,tag:bits.tag}}); // CHANGED DATA


        working_v <= False;
        is_downgrade <= False;
      end else  begin
        // missReq <= MainMemReq{write:1,addr:{e.tag,e.idx},data:data}; // CHANGED DATA
        if (!is_downgrade) mshr <= 1;
        else begin 
          working_v <= False;
          is_downgrade <= False;
        end
      end
    end
  endrule

  rule startMiss(mshr==1);
    if (working_line.valid == 2) begin
      ////////$display("MISS DIRTY");
      memReqQ.enq(MainMemReq{write:1, addr:{working_line.tag,working.idx},data:vecToLine(working_data)}); // original line
    end
    mshr <= 2;
  endrule

  rule sendFillReq(mshr == 2);

      memReqQ.enq(MainMemReq{write:0, addr:{working.tag,working.idx}, data: unpack(0)});
      mshr <= 3;
  endrule

  Reg#(Bool) start_fill <- mkReg(False);

  rule waitFillResp_Ld(mshr==3 && start_fill && working.memReq.word_byte == 0);

    // let data = fill_data;
    let m_working_req = working.memReq;
    if (memRespQ.notEmpty()) begin
      let data = memRespQ.first;
      bram1.portA.request.put(BRAMRequest{write: True, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: CacheReqLine{valid:1,tag:working.tag}});
      
      bram2.portA.request.put(BRAMRequestBE{writeen: 64'hffffffffffffffff, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: lineToWordVec(data)});

      hitQ.enq(lineToWordVec(data)[working.offset]); // CHANGED FROM data
      working_v <= False;
      mshr <= 0;
      memRespQ.deq();
      start_fill <= False;

    end 
  endrule



  rule waitFillResp_St(mshr==3 && working.memReq.word_byte != 0);
    // ////////$display("waitFillResp_st");

    // let data = fill_data;
    let m_working_req = working.memReq;
    
    // ADDED SECTION
    // added if statement
    if (memRespQ.notEmpty()) begin
      let data = lineToWordVec(memRespQ.first);

      Bit#(64) en_bytes = 64'hffffffffffffffff;

      if(working.memReq.word_byte[0]==1) data[working.offset][7:0] = working.memReq.data[7:0];
      if(working.memReq.word_byte[1]==1) data[working.offset][15:8] = working.memReq.data[15:8];
      if(working.memReq.word_byte[2]==1) data[working.offset][23:16] = working.memReq.data[23:16];
      if(working.memReq.word_byte[3]==1) data[working.offset][31:24] = working.memReq.data[31:24];
      // ////////$display("DATA", fshow(data));
      
      ////////$display("WRITE MISS", fshow(working.memReq.data), fshow(data)); 
      bram1.portA.request.put(BRAMRequest{write: True, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: CacheReqLine{valid:1,tag:working.tag}}); // CHANGED FROM working.memReq.data

      bram2.portA.request.put(BRAMRequestBE{writeen: en_bytes, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: data}); // CHANGED FROM working.memReq.data

      memReqQ.enq(MainMemReq{write:1, addr:{working.tag,working.idx},data:vecToLine(data)}); // original line

                
      working_v <= False;
      mshr <= 0;
      start_fill <= False;
      memRespQ.deq();
    end
  endrule


  // TODO Write a Cache
  method Action putFromProc(CacheReq e, Bit#(1) skip_upgrade) if (!working_v && mshr == 0);

    // //////$display("WORD_BYTE ",e.word_byte, e.word_byte==0);
    if (e.word_byte != 0 && skip_upgrade==0) begin
      upgrades.enq(e);
    end else if (skip_upgrade==1) begin
      is_downgrade <= True;
    end
  
    ////$display("PFPL1 ",fshow(e), fshow(mshr), fshow(skip_upgrade));
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
    ////$display("GTPL1 ", fshow(r), fshow(is_downgrade), fshow(working.memReq));
    return r;
  endmethod

  method ActionValue#(MainMemReq) getToMem();
    memReqQ.deq();
    let r = memReqQ.first;
    // ////$display("GTML1 ",fshow(r));
    return r;
  endmethod

  method Action putFromMem(MainMemResp e) ;
    // if(!start_fill)
    start_fill <= True;
    // ////$display("PFML1 ",fshow(e));
    memRespQ.enq(e);
    // fill_data <= e;
  endmethod

  method ActionValue#(CacheReq) getToUpgrade() if (upgrades.notEmpty());
    upgrades.deq();
    return upgrades.first;
  endmethod

endmodule