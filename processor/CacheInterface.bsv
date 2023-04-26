import ClientServer::*;
import GetPut::*;
import Randomizable::*;
import MainMem::*;
import MemTypes::*;
import Cache32::*;
import Cache::*;


module mkCache_nested(Empty);
    let verbose = True;
    MainMem mainMem <- mkMainMem(); //Initialize both to 0
    Cache32 cache <- mkCache32;
    Cache cache2 <- mkCache;
    Cache32 cache3 <- mkCache32;
    Cache cache4 <- mkCache;
    
    rule connectCacheL1L2Data;
        let lineReq <- cache.getToMem();
        cache2.putFromProc(lineReq);
    endrule
    rule connectL2L1CacheData;
        let resp <- cache2.getToProc();
        cache.putFromMem(resp);
    endrule

    rule connectCacheDramData;
        let lineReq <- cache2.getToMem();
        mainMem.put1(lineReq);
    endrule

    rule connectDramCacheData;
        let resp <- mainMem.get1;
        cache2.putFromMem(resp);
    endrule


    rule connectCacheL1L2Instr;
        let lineReq <- cache3.getToMem();
        cache4.putFromProc(lineReq);
    endrule
    rule connectL2L1CacheInstr;
        let resp <- cache4.getToProc();
        cache3.putFromMem(resp);
    endrule

    rule connectCacheDramInstr;
        let lineReq <- cache4.getToMem();
        mainMem.put2(lineReq);
    endrule

    rule connectDramCacheInstr;
        let resp <- mainMem.get2;
        cache4.putFromMem(resp);
    endrule



    method Action sendReqData(CacheReq req);
        cache.putFromProc(req);
    endmethod

    method ActionValue(Word) getRespData();
        let resp1 <- cache.getToProc();
        return resp1;
    endmethod


    method Action sendReqInstr(CacheReq req);
        cache3.putFromProc(req);
    endmethod

    method ActionValue(Word) getRespInstr();
        let resp1 <- cache3.getToProc();
        return resp1;
    endmethod
endmodule
