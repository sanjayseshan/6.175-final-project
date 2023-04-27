import ClientServer::*;
import GetPut::*;
import Randomizable::*;
import MainMem::*;
import MemTypes::*;
import Cache32::*;
import Cache::*;
import FIFOF::*;


interface CacheInterface;
    method Action sendReqData(CacheReq req);
    method ActionValue#(Word) getRespData();
    method Action sendReqInstr(CacheReq req);
    method ActionValue#(Word) getRespInstr();
endinterface


module mkCacheInterface(CacheInterface);
    let verbose = True;
    MainMem mainMem <- mkMainMem(); //Initialize both to 0
    Cache32 cache <- mkCache32;
    Cache cache2 <- mkCache;
    Cache32 cache3 <- mkCache32;
    Cache cache4 <- mkCache;
    
    // rule connectCacheL1L2Data;
    //     let lineReq <- cache.getToMem();
    //     cache2.putFromProc(lineReq);
    // endrule
    // rule connectL2L1CacheData;
    //     let resp <- cache2.getToProc();
    //     cache.putFromMem(resp);
    // endrule

    rule connectCacheDramData;
        let lineReq <- cache.getToMem();
        mainMem.put1(lineReq);
    endrule

    rule connectDramCacheData;
        let resp <- mainMem.get1;
        cache.putFromMem(resp);
    endrule


    rule connectCacheL1L2Instr;
        let lineReq <- cache3.getToMem();
        cache4.putFromProc(lineReq);
    endrule
    rule connectL2L1CacheInstr;
        let resp <- cache4.getToProc();
        cache3.putFromMem(resp);
        $display("GOT INSTR ",fshow(resp));
    endrule

    rule connectCacheDramInstr;
        let lineReq <- cache4.getToMem();
        mainMem.put2(lineReq);
    endrule

    rule connectDramCacheInstr;
        let resp <- mainMem.get2;
        cache4.putFromMem(resp);
    endrule

    FIFOF#(Word) respI <- mkFIFOF();
    FIFOF#(Word) respD <- mkFIFOF();

    rule respsI;
        let rI <- cache3.getToProc();
        respI.enq(rI);
    endrule

    rule respsD;
        let rD <- cache.getToProc();
        respD.enq(rD);
    endrule


    method Action sendReqData(CacheReq req);
        cache.putFromProc(req);
        if (req.write != 0) respD.enq(0);
    endmethod

    method ActionValue#(Word) getRespData() if (respD.notEmpty());
        respD.deq();
        return respD.first;
    endmethod


    method Action sendReqInstr(CacheReq req);
        cache3.putFromProc(req);
    endmethod

    method ActionValue#(Word) getRespInstr() if (respI.notEmpty());
        respI.deq();
        return respI.first;
    endmethod
endmodule
