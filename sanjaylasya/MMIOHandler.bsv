import MemTypes::*;
import FIFO::*;
import DdrAws::*;

`define PUT_INT_ADDR 32'hf000_fff4
`define PUT_CHAR_ADDR 32'hf000_fff0
`define FINISH_ADDR 32'hf000_fff8

interface MMIOHandler;
    method Action getMMIOReq(Mem req);
    method ActionValue#(Mem) putMMIOResp;
endinterface

interface MMIOInput;
    interface TopIndication ind;
    method Bit#(32) getTick;
endinterface

module mkMMIOHandler#(MMIOInput topIfc)(MMIOHandler);
    FIFO#(Mem) outFifo <- mkFIFO();

    method Action getMMIOReq(Mem req);
        if (req.addr == `PUT_INT_ADDR) topIfc.ind.printInt(topIfc.getTick(), req.data);
        else if (req.addr == `PUT_CHAR_ADDR) topIfc.ind.printChar(topIfc.getTick(), req.data[7:0]);
        else if (req.addr == `FINISH_ADDR) topIfc.ind.returnResult(topIfc.getTick(), req.data);
        if (req.byte_en == 0) outFifo.enq(req);
    endmethod

    method ActionValue#(Mem) putMMIOResp;
        outFifo.deq;
        return outFifo.first;
    endmethod
endmodule
