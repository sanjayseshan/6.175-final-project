import ClientServer::*;
import GetPut::*;
import Randomizable::*;
import MainMem::*;
import MemTypes::*;
import Cache32MC::*;
// import Cache32::*;
import Cache::*;
import FIFOF::*;
// import PP::*;


interface CacheInterface;
    method Action sendReqData(CacheReq req);
    method ActionValue#(Word) getRespData();
    method  Action sendReqInstr(CacheReq req);
    method ActionValue#(Word) getRespInstr();
    method ActionValue#(MainMemReq) sendReq();
    method ActionValue#(CacheReq) upgrade();
    method Action downgrade(CacheReq req);
    method Action connectL2L1Cache(MainMemResp resp);
endinterface

interface ParentProtocolProcessor;
endinterface

module mkParentProtocolProcessor#(CacheInterface core1, CacheInterface core2)(ParentProtocolProcessor);
    Cache cacheL2 <- mkCache;
    FIFOF#(Bit#(1)) order_req <- mkFIFOF;

    MainMem mainMem <- mkMainMem(); //Initialize both to 0

    rule connectCacheDram;
        let lineReq <- cacheL2.getToMem();
        mainMem.put(lineReq);
    endrule

    rule connectDramCache;
        let resp <- mainMem.get;
        cacheL2.putFromMem(resp);
        ////$display("FROM MEM ",fshow(resp));
    endrule
    

    rule processUpgrade1;
        let upgrade <- core1.upgrade();
        core2.downgrade(upgrade);
        ////$display("UPGRADE1 ",fshow(upgrade));
        // cacheL2.putFromProc(upgrade);
        // if (upgrade.write == 0) order_req.enq(0);
    endrule

    rule processReq1;
        let req <- core1.sendReq();
        cacheL2.putFromProc(req);
        if (req.write == 0) order_req.enq(0);
        // $display("L2REQ1 ",fshow(req));
    endrule

    rule processUpgrade2;
        let upgrade <- core2.upgrade();
        core1.downgrade(upgrade);
        // cacheL2.putFromProc(upgrade);
        // if (upgrade.write == 0) order_req.enq(1);
    endrule

    rule processReq2;
        let req <- core2.sendReq();
        cacheL2.putFromProc(req);
        // $display("L2REQ2 ",fshow(req));
        if (req.write == 0) order_req.enq(1);
    endrule

    // (order_req.notEmpty())
    rule processReqRes;
        let resp <- cacheL2.getToProc();
        // $display("L2 GOT RESP ",fshow(resp));
        if (order_req.first == 0) core1.connectL2L1Cache(resp);
        else core2.connectL2L1Cache(resp);
        order_req.deq();
    endrule
endmodule


module mkCacheInterface#(Bit#(1) id)(CacheInterface);
    let verbose = False;

    Cache32MC cacheD <- mkCache32MC;
    Cache32MC cacheI <- mkCache32MC;

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


    
    // Reg#(Bit#(32)) cycle <- mkReg(0);

    // rule cycle_disp;
    //     cycle <= cycle +1;
    //     ////$display("CYCLE %d\n",cycle,fshow(order_req.notEmpty));
    // endrule


    FIFOF#(MainMemReq) upreqs <- mkFIFOF;

    rule connectCacheInstrPPP;
        let lineReq <- cacheI.getToMem();
        upreqs.enq(lineReq);
        ////$display("INSTR UPREQ ",fshow(lineReq));
        order_req.enq(1);
    endrule

    rule connectCacheDataPPP;
        let lineReq <- cacheD.getToMem();
        upreqs.enq(lineReq);
        if (lineReq.write == 0) order_req.enq(0);
        ////$display("DATA UPREQ ",fshow(lineReq));
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
        cacheD.putFromProc(req, 0);
        //$display(id,"REQUESTING DATA ", fshow(req));
        if (req.word_byte != 0) begin
            respD.enq(0);
        end
    endmethod

    method ActionValue#(Word) getRespData() if (respD.notEmpty());
        respD.deq();
        //$display(id,"RETURNING DATA ",fshow(respD.first));

        return respD.first;
    endmethod


    method Action sendReqInstr(CacheReq req);
        ////$display("REQUESTING INSTR ", fshow(req));

        cacheI.putFromProc(req, 1);
    endmethod

    method ActionValue#(Word) getRespInstr() if (respI.notEmpty());
        ////$display("RETURNING INSTR ",fshow(respI.first));
        respI.deq();
        return respI.first;
    endmethod

    method ActionValue#(MainMemReq) sendReq() if (upreqs.notEmpty());
        upreqs.deq();
        ////$display("sending request to PPP ",fshow(upreqs.first));
        return upreqs.first;
    endmethod

    method ActionValue#(CacheReq) upgrade();

        let req <- cacheD.getToUpgrade();
        //$display(id,"UPGRADING DATA ",fshow(req));
        return req;
    endmethod

    method Action downgrade(CacheReq req);
        ////$display("DOWNGRADE ",fshow(req));
        // $display(id,"DOWNGRADING DATA ",fshow(req));

        cacheD.putFromProc(req, 1);
    endmethod

    method Action connectL2L1Cache(MainMemResp resp);
        ////$display("connectL2L1Cache ",order_req.first);
        if (order_req.first == 0) cacheD.putFromMem(resp);
        if (order_req.first == 1) cacheI.putFromMem(resp);
        order_req.deq();
    endmethod
endmodule
