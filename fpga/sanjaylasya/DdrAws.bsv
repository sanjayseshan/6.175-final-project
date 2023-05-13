// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
import Clocks::*;
import Vector::*;
import BuildVector::*;
import GetPut::*;
import Connectable::*;
import ClientServer::*;
import ConnectalMemory::*;
import ConnectalBramFifo::*;
import FIFOF::*;
import ConnectalMemTypes::*;
import MemReadEngine::*;
import MemWriteEngine::*;
import Pipe::*;
import AxiDdr3Controller::*;
import GetPutWithClocks::*;
import AxiMasterSlave::*;
import Axi4MasterSlave::*;
import AxiDdr3Wrapper::*;
import AxiDma::*;
import ConnectalConfig::*;
import HostInterface::*;
import Probe::*;
import Axi4New::*;
import MemTypes::*;
import DCache::*;


interface TopIndication;
    method Action returnResult(Bit#(32) tick, Bit#(32) res);
    method Action printChar(Bit#(32) tick, Bit#(8) c);
    method Action printInt(Bit#(32) tick, Bit#(32) i);
    method Action error(Bit#(32) code, Bit#(32) data);
    method Action currentPc(Bit#(32)tick, Bit#(32) pc);
    method Action logMemReq(Bit#(32) tick, Bool write, Bit#(32) addr, Bit#(32) data);
    method Action logMemResp(Bit#(32) tick, Bit#(32) id, Bit#(32) data);
    method Action logCacheReq(Bit#(32) tick, Bool fromCache, Bit#(32) addr, Bool valid, Bit#(32) data);
    method Action reportDeadlock(Bit#(32) tick, Bit#(32) pc0, Bit#(32) pc1, Bit#(32) pc2);
endinterface

interface DdrAws;
   method ActionValue#(ReadResp) getRead;
   method Action getWrite;
   method Action startWriteDram(Bit#(16) id, LineAddr address,
      	  	 	  Bit#(512) line);
   method Action startReadDram(Bit#(16) id, LineAddr address);
   interface Axi4 ddr3;
endinterface

interface DdrInput;
    interface TopIndication ind;
    method Bit#(32) getTick;
endinterface

module mkDdrAws#(DdrInput inIfc)(DdrAws);

   Reg#(Bool) flying <- mkReg(False);

   FIFOF#(Axi4ReadRequest#(DdrAddrWidth, DdrIdWidth)) fifo_req_ar <- mkFIFOF();
   FIFOF#(Axi4ReadResponse#(DdrBusWidth, DdrIdWidth)) fifo_resp_read <- mkFIFOF();
   FIFOF#(Axi4WriteRequest#(DdrAddrWidth, DdrIdWidth)) fifo_req_aw <- mkFIFOF();
   FIFOF#(Axi4WriteData#(DdrBusWidth, DdrIdWidth)) fifo_resp_write <- mkFIFOF();
   FIFOF#(Axi4WriteResponse#(DdrIdWidth)) fifo_resp_b <- mkFIFOF();


   let aximaster = (interface Axi4Master;
       		   	      interface req_ar = toGet(fifo_req_ar);
			      interface resp_read = toPut(fifo_resp_read);
			      interface req_aw = toGet(fifo_req_aw);
			      interface resp_write = toGet(fifo_resp_write);
			      interface resp_b = toPut(fifo_resp_b);
		endinterface);

   Axi4 ddr3bits <- mkAxi4MasterBitsEmpty(aximaster);

   method ActionValue#(ReadResp) getRead;
   	fifo_resp_read.deq();
	let respread  = fifo_resp_read.first();
	let resp = respread.data;
	let id = respread.id;
	let last = respread.last;
	let error = respread.resp;
	if (error != 0 || last != 1) begin
	   inIfc.ind.error(zeroExtend(error),zeroExtend(id));
	end
	flying <= False;
	//ind.readDone(id,resp);
        //inIfc.ind.logMemResp(inIfc.getTick(), zeroExtend(id), resp[31:0]);
    return ReadResp{id: id, data: resp};
   endmethod

   method Action getWrite;
   	fifo_resp_b.deq();
	let resp = fifo_resp_b.first();
	let error = resp.resp;
	let id = resp.id;
	flying <= False;
	if (error != 0) begin
	   inIfc.ind.error(zeroExtend(error), zeroExtend(id));
	end
	//ind.writeDone(zeroExtend(id));
    //inIfc.ind.printInt(inIfc.getTick(), zeroExtend(id));
   endmethod

// len = nb pack512 -1
// size axiBusSize
// burst: 1
// prot: 0
// cache:3
// lock: 0
// qos: 0
// resp: 0 if no error
// last: 1 for the last burst.

   method Action startWriteDram(Bit#(16) id, LineAddr address,
      	  	 	  Bit#(512) line
 			  ) if (!flying);
   	     flying <= True;
      fifo_req_aw.enq(Axi4WriteRequest{address: {address, 6'b0},
      				      len: 0,
 				      size: 6,
 				      burst: 1,
 				      prot: 0,
 				      cache: 3,
 				      id: id,
 				      lock: 0,
 				      qos: 0
 				      });
      fifo_resp_write.enq(Axi4WriteData{data: line,
      				       byteEnable: maxBound,
 				       last: 1,
 				       id: id});
        //inIfc.ind.logMemReq(inIfc.getTick(), True, { address, '0}, line[31:0]);
   endmethod

   method Action startReadDram(Bit#(16) id, LineAddr address) if (!flying);
   	     flying <= True;
      fifo_req_ar.enq(Axi4ReadRequest{address: {address, 6'b0},
      				     len: 0,
 				     size: 6,
 				     burst: 1,
 				     prot: 0,
 				     cache: 3,
 				     id: id,
 				     lock: 0,
 				     qos: 0
 				     });
        //inIfc.ind.logMemReq(inIfc.getTick(), False, { address, '0}, 0);
   endmethod

   interface ddr3 = ddr3bits;
endmodule

interface MemController;
    method Action directStore(LineAddr address, Bit#(512) line);
    interface Axi4 ddr3;
endinterface



interface MemInput;
    interface TopIndication ind;
    method Bit#(32) getTick;
    interface Cache dCache;
    interface Cache iCache;
endinterface


module mkMemController#(MemInput inIfc)(MemController);

    let ddrIfc = (interface DdrInput;
                interface TopIndication ind = inIfc.ind;
                method Bit#(32) getTick = inIfc.getTick;
                endinterface);
    let ddrController <- mkDdrAws(ddrIfc);
    Reg#(Bool) checkStore <- mkReg(False);
    Reg#(Bool) sent <- mkReg(False);
    Reg#(Bit#(32)) storeData <- mkReg(0);
    Reg#(LineAddr) storeAddr <- mkReg(0);


    rule checkWrites;
        ddrController.getWrite();
    endrule

    rule getReadResp;
        let res <- ddrController.getRead();
        if (res.id[15] == 1'b1) inIfc.dCache.putFromMem(res.data);
        else inIfc.iCache.putFromMem(res.data);
        inIfc.ind.logMemResp(inIfc.getTick(), zeroExtend(res.id), res.data[31:0]);
    endrule

    rule getDReq;
        let req <- inIfc.dCache.getToMem();
        if (req.write == 1) ddrController.startWriteDram({1'b1, req.addr[14:0]}, req.addr, req.data);
        else ddrController.startReadDram({1'b1, req.addr[14:0]}, req.addr);
        inIfc.ind.logMemReq(inIfc.getTick(), req.write == 1, {1'b1, req.addr[14:0],'0 }, 0);
    endrule

    rule getIReq;
        let req <- inIfc.iCache.getToMem();
        ddrController.startReadDram({1'b0, req.addr[14:0]}, req.addr);
        inIfc.ind.logMemReq(inIfc.getTick(), False, {1'b1, req.addr[14:0],'0 }, 0);
    endrule

    method Action directStore(LineAddr address, Bit#(512) line);
        ddrController.startWriteDram({1'b0, address[14:0]}, address, line);
        //inIfc.ind.logMemReq(inIfc.getTick(), True, { address, '0}, line[31:0]);
    endmethod

    interface ddr3 = ddrController.ddr3;
endmodule
