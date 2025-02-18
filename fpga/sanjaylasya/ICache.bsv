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

    // Vector#(16, Word) ret;
    // for (Integer i=0; i < 16; i = i + 1) begin
    //   ret[i] = line[511-32*i:511-31-32*i];
    // end
    return unpack(line);
endfunction

function Bit#(512) vecToLine(Vector#(16, Word) v);
  return pack(v);
  // {v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15]};
endfunction


interface ICache;
    method Action putFromProc(CacheReq e, Bit#(1) skip_upgrade);
    method ActionValue#(Word) getToProc();
    method ActionValue#(MainMemReq) getToMem();
    method Action putFromMem(MainMemResp e);
    method ActionValue#(CacheReq) getToUpgrade();
    // method Action procDowngrade(CacheReq e);
endinterface

module mkICache(ICache);
  BRAM_Configure cfg = defaultValue;
  cfg.loadFormat = tagged Binary "zero.vmh";
  BRAM_Configure cfg2 = defaultValue;
  BRAM1Port#(IndexAddr, CacheReqLine) bram1 <- mkBRAM1Server(cfg);
  BRAM1PortBE#(IndexAddr, Vector#(16, Word), 64) bram2 <- mkBRAM1ServerBE(cfg2);


  Reg#(CacheReqWorking) working <- mkReg(unpack(0));
  Reg#(Vector#(16, Word)) working_data <- mkReg(unpack(0));

  Reg#(Bool) working_v <- mkReg(False);

  FIFOF#(Word) hitQ <- mkFIFOF();
  // Reg#(CacheReq) missReq <- mkReg(unpack(0));
  Reg#(Bit#(2)) mshr <- mkReg(0);

  FIFO#(MainMemReq) memReqQ <- mkFIFO();
  FIFOF#(MainMemResp) memRespQ <- mkFIFOF();

  FIFOF#(StbReq) stb <- mkFIFOF();

  FIFOF#(CacheReq) upgrades <- mkFIFOF();

  Reg#(CacheReqLine) working_line <- mkReg(unpack(0));

  // Ehr#(2, Bool) lockL1 <- mkEhr(False);

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
      // let x = stb.first;
      // // let x = stb.search_res(working.memReq.addr);
      // if (stb.notEmpty() && x.addr == working.memReq.addr) begin
      //   hitQ.enq(x.data); // CHANGED FROM x.data
      //   ////////$display("READ HIT Q %x", x.data);
      //   working_v <= False;
      // end 
      // else 
      ////$display(fshow(working.tag),fshow(out.tag), fshow(out.valid), fshow(is_downgrade), fshow(working.offset));

      if (out.tag==working.tag && out.valid != 0) begin
        hitQ.enq(data[working.offset]); // CHANGED FROM out.data
        ////$display("READ HIT %x", data[working.offset]);
        working_v <= False;
      end else begin
        // missReq <= working.memReq;
        mshr <= 1;
      end
    end 
    // else if (working.memReq.word_byte == 4'b1111) begin
    //   stb.enq(StbReq{addr:working.memReq.addr,data:working.memReq.data, byte_en: working.memReq.word_byte});
    //   lockL1 <= False;
    //   if (!is_downgrade) begin
    //     let data_upgrade = data;
    //     let e = working.memReq;
    //     let bits = extract_bits(working.memReq.addr, ?);

    //     if(working.memReq.word_byte[0]==1) data_upgrade[working.offset][7:0] = e.data[7:0];
    //     if(working.memReq.word_byte[1]==1) data_upgrade[working.offset][15:8] = e.data[15:8];
    //     if(working.memReq.word_byte[2]==1) data_upgrade[working.offset][23:16] = e.data[23:16];
    //     if(working.memReq.word_byte[3]==1) data_upgrade[working.offset][31:24] = e.data[31:24];
    //     memReqQ.enq(MainMemReq{write:1, addr:{bits.tag,bits.idx},data:vecToLine(data_upgrade)}); // original line
    //   //$display("UPGRADE TO ",fshow({working_line.tag,working.idx}), fshow(e));
    //   end
    // end 
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
        // else //$display("PROCESSED DOWNGRADE", fshow(e));

      // ////$display("WRITE HIT");
        // if (working.memReq.write == 8) data[bits.offset][31:24] = e.data[31:24];
        // if (working.memReq.write == 4) data[bits.offset][23:16] = e.data[23:16];
        // if (working.memReq.write == 2) data[bits.offset][15:8] = e.data[15:8];
        // if (working.memReq.write == 1) data[bits.offset][7:0] = e.data[7:0];
        // if (working.memReq.write == 3) data[bits.offset][15:0] = e.data[15:0];
        // if (working.memReq.write == 12) data[bits.offset][31:16] = e.data[31:16];
        Vector#(16, Word) d_vec=unpack(0);
        d_vec[working.offset] = working.memReq.data; 


        Vector#(16, Bit#(4)) port_w=unpack(0);
        d_vec[working.offset] = working.memReq.data; 
        port_w[working.offset] = working.memReq.word_byte;
        // zeroExtend(working.memReq.word_byte) << ((15-working.offset)*4);

        // ////$display(fshow(port_w));
        // ////$display(fshow(d_vec));

        bram2.portA.request.put(BRAMRequestBE{writeen: pack(port_w), // False for read
                        responseOnWrite: False,
                        address: working.idx,
                        datain: d_vec}); // CHANGED DATA

        bram1.portA.request.put(BRAMRequest{write: True, // False for read
                        responseOnWrite: False,
                        address: working.idx,
                        datain: CacheReqLine{valid:1,tag:bits.tag}}); // CHANGED DATA


        
        
                        // mshr <= 1;
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

  // rule mvStbToL1 (mshr == 0 && !lockL1);
  //   // ////////$display("mvStbToL1");
  //   let e = stb.first;
  //   let bits = extract_bits(e.addr, ?);
  //   stb.deq();

  //   // ADDED
  //   // let data = working_line.data;

  //   // if (bits.offset==15) begin
  //   //   data = {e.data, data[479:0]};
  //   // end 
  //   // else if (bits.offset==0) begin
  //   //   data = {data[511:32], e.data};
  //   // end 
  //   // else begin
  //   //   data = {data[511:32*(bits.offset+1)], e.data, data[32*bits.offset-1:0]};
  //   // end
  //   // END OF ADDED SECTION

  //   if (bits.tag == working_line.tag) begin
  //     // data[bits.offset] = e.data;
  //     Vector#(16, Word) d_vec = unpack(0);
  //     d_vec[working.offset] = e.data;

  //     // Bit#(64) stb_en_byte = 0;
  //     // stb_en_byte[(zeroExtend(working.offset)+1)*4-1:zeroExtend(working.offset)*4] = zeroExtend(working.memReq.word_byte);

  //     Bit#(6) offset = {0, working.offset};
  //     bram2.portA.request.put(BRAMRequestBE{writeen: zeroExtend(working.memReq.word_byte) << 4*offset, // False for read // (zeroExtend(working.memReq.word_byte) << working.offset)
  //                     responseOnWrite: False,
  //                     address: working.idx,
  //                     datain: d_vec}); // CHANGED DATA

  //     bram1.portA.request.put(BRAMRequest{write: True, // False for read
  //                       responseOnWrite: False,
  //                       address: working.idx,
  //                       datain: CacheReqLine{valid:2,tag:bits.tag}}); // CHANGED DATA
  //     working_v <= False;
  //     is_downgrade <= False;
  //     // mshr <= 1;

  //   end else  begin
  //     // missReq <= MainMemReq{write:1,addr:{e.tag,e.idx},data:data}; // CHANGED DATA
  //     if (!is_downgrade) mshr <= 1;
  //     else working_v <= False;

  //   end
  //   lockL1 <= True;
  // endrule

  // rule clearL1Lock;
  //   lockL1[1] <= False;
  // endrule

  rule startMiss(mshr==1);
    //////////$display("startMiss",mshr,fshow(working.memReq));
    if (working_line.valid == 2) begin
      ////////$display("MISS DIRTY");
      memReqQ.enq(MainMemReq{write:1, addr:{working_line.tag,working.idx},data:vecToLine(working_data)}); // original line
    end
    mshr <= 2;
  endrule

  rule sendFillReq(mshr == 2);
    //////////$display("sendFillReq");

      ////////$display("MISS GET FROM MEM", fshow(working.memReq), fshow({working.tag,working.idx}));
      memReqQ.enq(MainMemReq{write:0, addr:{working.tag,working.idx}, data: unpack(0)});
      mshr <= 3;
  endrule

  Reg#(Bool) start_fill <- mkReg(False);
  // Reg#(Bit#(512)) fill_data <- mkReg(0);

  rule waitFillResp_Ld(mshr==3 && start_fill && working.memReq.word_byte == 0);
    // ////////$display("waitFillResp_ld");

    // let data = fill_data;
    let m_working_req = working.memReq;
    if (memRespQ.notEmpty()) begin
      let data = memRespQ.first;
      ////////$display("LOAD MISS", fshow(working.memReq.data), fshow(lineToWordVec(data))); 
      bram1.portA.request.put(BRAMRequest{write: True, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: CacheReqLine{valid:1,tag:working.tag}});
      
      bram2.portA.request.put(BRAMRequestBE{writeen: 64'hffffffffffffffff, // False for read
                responseOnWrite: False,
                address: working.idx,
                datain: lineToWordVec(data)});
      ////$display("OFFSET ",fshow(working.offset),fshow(lineToWordVec(data)));

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

      // if (bits.offset==15) begin
      //   data = {working.memReq.data, data[479:0]};
      // end else if (bits.offset==0) begin
      //   data = {data[511:32], working.memReq.data};
      // end else begin
      //   data = {data[511:32*(bits.offset+1)], working.memReq.data, data[32*bits.offset-1:0]};
      // end
      // END OF ADDED SECTION

      // data[working.offset] = working.memReq.data;
      Bit#(64) en_bytes = 64'hffffffffffffffff;
      // en_bytes[(zeroExtend(working.offset)+1)*4:zeroExtend(working.offset)*4] = working.memReq.word_byte;

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
      //$display("UPGRADE TO ",fshow({working_line.tag,working.idx}), fshow(working.memReq));

                
      working_v <= False;
      mshr <= 0;
      start_fill <= False;
      memRespQ.deq();
    end
  endrule

  // Reg#(Bool) downgrade_en <- mkReg(False);
  // Reg#(CacheReqWorking) working_down <- mkReg(unpack(0));

  
  // rule processDowngradeLine (downgrade_en);
  //   let req = extract_bits(working_down.memReq.addr, ?);
    
  //   if(req.tag == working_down.tag) begin
  //     Vector#(16, Word) d_vec = unpack(0);
  //     d_vec[working_down.offset] = working_down.memReq.data; 
      
  //     bram1.portA.request.put(BRAMRequest{write: True, // False for read
  //                       responseOnWrite: False,
  //                       address: req.idx,
  //                       datain: CacheReqLine{valid:2,tag:working_down.tag}});

  //     bram2.portA.request.put(BRAMRequestBE{writeen: zeroExtend(working_down.memReq.word_byte) << working_down.offset, // False for read
  //                       responseOnWrite: False,
  //                       address: working_down.idx,
  //                       datain: d_vec}); // CHANGED DATA    
  //   end

  //   downgrade_en <= False;
  //   // working_v <= False;
  // endrule

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
    // r = MainMemReq { write: 'h0, addr: 'h0000008, data: ? };
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

  // method Action procDowngrade(CacheReq e) if (!downgrade_en && mshr == 0);
  //   //////$display("REQUESTED DOWNGRADE");
  //   let req = extract_bits(e.addr, e);
  //   bram1.portA.request.put(BRAMRequest{write: False, // False for read
  //                       responseOnWrite: False,
  //                       address: req.idx,
  //                       datain: ?});
  //   working_down <= req;
  //   // working_v <= True;
  //   downgrade_en <= True;
  // endmethod

endmodule