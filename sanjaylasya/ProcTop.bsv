import DdrAws::*;
// import Cache32MC::*;
import DCache::*;
import ICache::*;
import pipelined::*;
import MemTypes::*;
import MMIOHandler::*;
import Axi4New::*;


interface TopRequest;
    method Action loadMem(Bit#(32) addr, Bit#(32)v0, Bit#(32)v1, Bit#(32)v2, Bit#(32)v3, 
                          Bit#(32)v4, Bit#(32)v5, Bit#(32)v6, Bit#(32)v7, 
                          Bit#(32)v8, Bit#(32)v9, Bit#(32)v10, Bit#(32)v11, 
                          Bit#(32)v12, Bit#(32)v13, Bit#(32)v14, Bit#(32)v15);
    method Action startProc;
endinterface

interface ProcTop;
    interface TopRequest topRequest;
    interface Axi4 ddr3;
endinterface



module mkProcTop#(TopIndication ind)(ProcTop);

    Reg#(Bit#(32)) tick <- mkReg(0);
 
    let proc <- mkpipelined(0,0);
    let iCache <- mkDCache();
    let dCache <- mkDCache();

    let mmioIfc = (interface MMIOInput;
                    interface ind = ind;
                    method Bit#(32) getTick = tick._read;
                endinterface);
 
    let mmioHandler <- mkMMIOHandler(mmioIfc);
 
    let memInput = (interface MemInput;
             interface ind = ind;
             method getTick = tick._read;
             interface dCache = dCache;
             interface iCache = iCache;
             endinterface);
    let memController <- mkMemController(memInput);
 
    rule updateTick;
        tick <= tick + 1;
    endrule
 
/*
    rule checkDeadlock;
        let deadPcs = proc.checkDeadlock();
        ind.reportDeadlock(tick, deadPcs[0], deadPcs[1], deadPcs[2]);
        //ind.returnResult(tick, 'hFFFFFFFF);
    endrule
*/
 
    rule sendIReqtToCache;
        let req <- proc.getIReq();
        iCache.putFromProc(req, 0);
        ind.currentPc(tick, req.addr);
    endrule
 
    rule sendIRespToProc;
        let req <- iCache.getToProc();
        proc.getIResp(Mem{byte_en:?, addr:?, data:req});
    endrule
 
    rule sendDReqtToCache;
        let req <- proc.getDReq();
        dCache.putFromProc(req, 0);
    endrule
 
    rule sendDRespToProc;
        let req <- dCache.getToProc();
        proc.getDResp(Mem{byte_en:?, addr:?, data:req});
    endrule
 
    rule sendMMIOReq;
       let req <- proc.getMMIOReq();
       mmioHandler.getMMIOReq(req);
    endrule

    rule getMMIOResp;
       let resp <- mmioHandler.putMMIOResp();
       proc.getMMIOResp(resp);
    endrule



    interface topRequest = (interface TopRequest;
        method Action loadMem(Bit#(32) address, Bit#(32) v0, Bit#(32) v1, Bit#(32) v2, Bit#(32) v3,
                                 Bit#(32) v4, Bit#(32) v5, Bit#(32) v6, Bit#(32) v7,
                                 Bit#(32) v8, Bit#(32) v9, Bit#(32) v10, Bit#(32) v11,
                                 Bit#(32) v12, Bit#(32) v13, Bit#(32) v14, Bit#(32) v15
                                    );
            memController.directStore(address[31:6], {v15, v14, v13, v12, v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0});
    
        endmethod
        method Action startProc();
            proc.start();
        endmethod
            endinterface);
    
    interface ddr3 = memController.ddr3;
endmodule
