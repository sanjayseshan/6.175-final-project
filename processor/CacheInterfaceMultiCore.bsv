import ClientServer::*;
import GetPut::*;
import Randomizable::*;
import MainMem::*;
import MemTypes::*;
import Cache32::*;
import Cache::*;
import FIFOF::*;
import PP::*


interface CacheInterface;
    method Action sendReqData(CacheReq req);
    method ActionValue#(Word) getRespData();
    method Action sendReqInstr(CacheReq req);
    method ActionValue#(Word) getRespInstr();
endinterface

interface ParentProtocolProcessor;
endinterface

module mkParentProtocolProcessor(CacheInterface core1, CacheInterface core2)(ParentProtocolProcessor);
    Cache cacheL2 <- mkCache;

    rule connectCacheDram;
        let lineReq <- cacheL2.getToMem();
        mainMem.put(lineReq);
    endrule

    rule connectDramCache;
        let resp <- mainMem.get;
        cacheL2.putFromMem(resp);
    endrule

endmodule


module mkCacheInterface(CacheInterface);
    let verbose = False;
    MainMem mainMem <- mkMainMem(); //Initialize both to 0
    Cache32 cacheD <- mkCache32;
    Cache32 cacheI <- mkCache32;

    FIFOF#(Bit#(1)) order_req <- mkFIFOF;
    // Cache cache4 <- mkCache;
    
    // rule connectCacheL1L2Data;
    //     let lineReq <- cache.getToMem();
    //     cache2.putFromProc(lineReq);
    // endrule
    // rule connectL2L1CacheData;
    //     let resp <- cache2.getToProc();
    //     cache.putFromMem(resp);
    // endrule


    // rule connectCacheDramInstr;
    //     let lineReq <- cache4.getToMem();
    //     mainMem.put2(lineReq);
    // endrule


    rule connectL2L1Cache;
        let resp <- cacheL2.getToProc();
        if (order_req.first == 0) cacheD.putFromMem(resp);
        else cacheI.putFromMem(resp);
        order_req.deq();
        //$display("GOT INSTR ",fshow(resp));
    endrule


    rule connectCacheL1L2Instr;
        let lineReq <- cacheI.getToMem();
        cacheL2.putFromProc(lineReq);
        order_req.enq(1);
    endrule

    rule connectCacheL1L2Data;
        let lineReq <- cacheD.getToMem();
        cacheL2.putFromProc(lineReq);
        order_req.enq(0);
    endrule

    // rule connectDramCacheInstr;
    //     let resp <- mainMem.get2;
    //     cache4.putFromMem(resp);
    // endrule

    FIFOF#(Word) respI <- mkFIFOF();
    FIFOF#(Word) respD <- mkFIFOF();

    rule respsI;
        let rI <- cacheI.getToProc();
        respI.enq(rI);
    endrule

    rule respsD;
        let rD <- cacheD.getToProc();
        respD.enq(rD);
    endrule


    method Action sendReqData(CacheReq req);
        cacheD.putFromProc(req);
        //$display("REQUESTING DATA ", fshow(req));
        if (req.word_byte != 0) begin
            respD.enq(0);
        end
    endmethod

    method ActionValue#(Word) getRespData() if (respD.notEmpty());
        respD.deq();
        //$display("RETURNING DATA ",fshow(respD.first));

        return respD.first;
    endmethod


    method Action sendReqInstr(CacheReq req);
        cacheI.putFromProc(req);
    endmethod

    method ActionValue#(Word) getRespInstr() if (respI.notEmpty());
        respI.deq();
        return respI.first;
    endmethod


    method ActionValue#(MainMemReq) upgrade();
        let lineReq <- cacheL2.getToMem();
        return lineReq;
    endmethod

    method Action downgrade(MaimMemReq req);

    endmethod
endmodule
