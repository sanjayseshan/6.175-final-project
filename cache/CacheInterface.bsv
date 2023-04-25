import ClientServer::*;
import GetPut::*;
import Randomizable::*;
import MainMem::*;
import MemTypes::*;
import Cache32::*;
import Cache::*;


module mkBeveren_nested(Empty);
    let verbose = True;
    MainMem mainMem <- mkMainMem(); //Initialize both to 0
    Cache32 cache <- mkCache32;
    Cache cache2 <- mkCache;
    
    rule connectCacheL1L2;
        let lineReq <- cache.getToMem();
        cache2.putFromProc(lineReq);
    endrule
    rule connectL2L1Cache;
        let resp <- cache2.getToProc();
        cache.putFromMem(resp);
    endrule

    rule connectCacheDram;
        let lineReq <- cache2.getToMem();
        mainMem.put(lineReq);
    endrule

    rule connectDramCache;
        let resp <- mainMem.get;
        cache2.putFromMem(resp);
    endrule



    method Action sendReq(CacheReq req);
        cache.putFromProc(req);
    endmethod

    method ActionValue(Word) getResp();
        let resp1 <- cache.getToProc();
    endmethod
endmodule
