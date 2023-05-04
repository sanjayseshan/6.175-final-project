import ClientServer::*;
import GetPut::*;
import Randomizable::*;
import MainMem::*;
import MemTypes::*;
import Cache32MC::*;
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
    FIFOF#(Bit#(1)) order_req <- mkFIFOF;

    rule connectCacheDram;
        let lineReq <- cacheL2.getToMem();
        mainMem.put(lineReq);
    endrule

    rule connectDramCache;
        let resp <- mainMem.get;
        cacheL2.putFromMem(resp);
    endrule
    

    rule processUpgrade1;
        let upgrade <- core1.upgrade();
        core2.downgrade();
        cacheL2.putFromProc(upgrade);
        // if (upgrade.write == 0) order_req.enq(0);
    endrule

    rule processReq1;
        let req <- core1.sendReq();
        cacheL2.putFromProc(req);
        if (req.write == 0) order_req.enq(0);
    endrule

    rule processUpgrade2;
        let upgrade <- core2.upgrade();
        core1.downgrade();
        cacheL2.putFromProc(upgrade);
        // if (upgrade.write == 0) order_req.enq(1);
    endrule

    rule processReq2;
        let req <- core2.sendReq();
        cacheL2.putFromProc(req);
        if (req.write == 0) order_req.enq(1);
    endrule

    rule processReqRes;
        let resp <- cacheL2.getToProc();
        if (order_req.first == 0) core1.connectL2L1Cache(resp);
        else core2.connectL2L1Cache(resp);
        order_req.deq();
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





    FIFOF#(MainMemReq) upreqs <- mkFIFOF;

    rule connectCacheInstrPPP;
        let lineReq <- cacheI.getToMem();
        upreqs.enq(lineReq);
        order_req.enq(1);
    endrule

    rule connectCacheDataPPP;
        let lineReq <- cacheD.getToMem();
        upreqs.enq(lineReq);
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

    method ActionValue#(MainMemReq) sendReq() if (upreqs.notEmpty());
        upreqs.deq();
        return upreqs.first;
    endmethod

    method ActionValue#(CacheReq) upgrade();
        let req <- cacheD.getToUpgrade();
        return req;
    endmethod

    method Action downgrade(CacheReq req);
        cacheD.procDowngrade(req);
    endmethod

    method Action connectL2L1Cache(Word resp);
        if (order_req.first == 0) cacheD.putFromMem(resp);
        else cacheI.putFromMem(resp);
        order_req.deq();
    endmethod
endmodule
