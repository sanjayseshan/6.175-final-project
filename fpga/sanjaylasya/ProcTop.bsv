import DdrAws::*;
// import Cache32MC::*;
import DCache::*;
import ICache::*;
import pipelined::*;
import MemTypes::*;
import MMIOHandler::*;
import Axi4New::*;
import FIFOF::*;


interface TopRequest;
    method Action loadMem(Bit#(32) addr, Bit#(32)v0, Bit#(32)v1, Bit#(32)v2, Bit#(32)v3, 
                          Bit#(32)v4, Bit#(32)v5, Bit#(32)v6, Bit#(32)v7, 
                          Bit#(32)v8, Bit#(32)v9, Bit#(32)v10, Bit#(32)v11, 
                          Bit#(32)v12, Bit#(32)v13, Bit#(32)v14, Bit#(32)v15);
    method Action startProc;
endinterface

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

interface ProcTop;
    interface TopRequest topRequest;
    interface Axi4 ddr3;
endinterface

module mkParentProtocolProcessor#(CacheInterface core1, CacheInterface core2, TopIndication ind, Cache cacheL2)(ParentProtocolProcessor);
    // Cache cacheL2 <- mkDCache;
    FIFOF#(Bit#(1)) order_req <- mkFIFOF;

    Reg#(Bit#(32)) tick <- mkReg(0);

    // let memInput = (interface MemInput;
    //          interface ind = ind;
    //          method getTick = tick._read;
    //          interface dCache = cacheL2;
    //          interface iCache = ?;
    //          endinterface);
    // let memController <- mkMemController(memInput);

    rule updateTick;
        tick <= tick + 1;
    endrule

    // MainMem mainMem <- mkMainMem(); //Initialize both to 0

    // rule connectCacheDram;
    //     let lineReq <- cacheL2.getToMem();
    //     mainMem.put(lineReq);
    // endrule

    // rule connectDramCache;
    //     let resp <- mainMem.get;
    //     cacheL2.putFromMem(resp);
    //     ////$display("FROM MEM ",fshow(resp));
    // endrule
    

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

    ICache cacheD <- mkICache;
    ICache cacheI <- mkICache;

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

module mkProcTop#(TopIndication ind)(ProcTop);

    Reg#(Bit#(32)) tick <- mkReg(0);
 
    // let proc <- mkpipelined(0,0);
    // let iCache <- mkDCache();
    // let dCache <- mkDCache();


    let mmioIfc = (interface MMIOInput;
                    interface ind = ind;
                    method Bit#(32) getTick = tick._read;
                endinterface);
 
    let mmioHandler <- mkMMIOHandler(mmioIfc);

    Cache cacheL2 <- mkDCache;

    let memInput = (interface MemInput;
             interface ind = ind;
             method getTick = tick._read;
             interface dCache = cacheL2;
             interface iCache = ?;
             endinterface);
    let memController <- mkMemController(memInput);

    CacheInterface cache1 <- mkCacheInterface(0);
    CacheInterface cache2 <- mkCacheInterface(1);
    ParentProtocolProcessor ppp <- mkParentProtocolProcessor(cache1, cache2, ind, cacheL2);

    RVIfc rv_core1 <- mkpipelined(0,0);
    RVIfc rv_core2 <- mkpipelined(4096,1);

    Reg#(Mem) ireq1 <- mkRegU;
    Reg#(Mem) dreq1 <- mkRegU;
    // FIFO#(Mem) mmioreq1 <- mkFIFO;

    Reg#(Mem) ireq2 <- mkRegU;
    Reg#(Mem) dreq2 <- mkRegU;
    // FIFO#(Mem) mmioreq2 <- mkFIFO;

    let debug = False;
    Reg#(Bit#(32)) cycle_count <- mkReg(0);

    rule tic;
	    cycle_count <= cycle_count + 1;
    endrule


    rule requestI1;
        let req <- rv_core1.getIReq;
        // if (debug) $display("Get IReq1", fshow(req));
        ireq1 <= req;

        cache1.sendReqInstr(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data});

            // bram.portB.request.put(BRAMRequestBE{
            //         writeen: req.byte_en,
            //         responseOnWrite: True,
            //         address: truncate(req.addr >> 2),
            //         datain: req.data});
    endrule

    rule responseI1;
        let x <- cache1.getRespInstr();
        // let x <- bram.portB.response.get();
        let req = ireq1;
        // if (debug) $display("Get IResp1 ", fshow(req), fshow(x));
        req.data = x;
        rv_core1.getIResp(req);
    endrule

    rule requestD1;
        let req <- rv_core1.getDReq;
        dreq1 <= req;
        if (debug) $display("Get DReq1 ", fshow(req));
        // $display("DATA ",fshow(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data}));
        cache1.sendReqData(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data});

        // bram.portA.request.put(BRAMRequestBE{
        //   writeen: req.byte_en,
        //   responseOnWrite: True,
        //   address: truncate(req.addr >> 2),
        //   datain: req.data});
    endrule

    rule responseD1;
        // let x <- bram.portA.response.get();
        let x <- cache1.getRespData();

        let req = dreq1;
        if (debug) $display("Get DResp1 ", fshow(req), fshow(x));
        req.data = x;
            rv_core1.getDResp(req);
    endrule



    rule requestI2;
        let req <- rv_core2.getIReq;
        // if (debug) $display("Get IReq2 ", fshow(req));
        ireq2 <= req;

        cache2.sendReqInstr(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data});

            // bram.portB.request.put(BRAMRequestBE{
            //         writeen: req.byte_en,
            //         responseOnWrite: True,
            //         address: truncate(req.addr >> 2),
            //         datain: req.data});
    endrule

    rule responseI2;
        let x <- cache2.getRespInstr();
        // let x <- bram.portB.response.get();
        let req = ireq2;
        // if (debug) $display("Get IResp2 ", fshow(req), fshow(x));
        req.data = x;
        rv_core2.getIResp(req);
    endrule

    rule requestD2;
        let req <- rv_core2.getDReq;
        dreq2 <= req;
        if (debug) $display("Get DReq2 ", fshow(req));
        // $display("DATA ",fshow(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data}));
        cache2.sendReqData(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data});

        // bram.portA.request.put(BRAMRequestBE{
        //   writeen: req.byte_en,
        //   responseOnWrite: True,
        //   address: truncate(req.addr >> 2),
        //   datain: req.data});
    endrule

    rule responseD2;
        // let x <- bram.portA.response.get();
        let x <- cache2.getRespData();

        let req = dreq2;
        if (debug) $display("Get DResp2 ", fshow(req), fshow(x));
        req.data = x;
            rv_core2.getDResp(req);
    endrule
  
 
    rule updateTick;
        tick <= tick + 1;
    endrule
 
/*
    rule checkDeadlock;
        let deadPcs = proc.checkDeadlock();
        ind.reportDeadlock(tick, deadPcs[0], deadPcs[1], deadPcs[2]);
        //ind.returnResult(tick, 'hFFFFFFFF);
    endrule
// */
 
//     rule sendIReqtToCache;
//         let req <- proc.getIReq();
//         iCache.putFromProc(req, 0);
//         ind.currentPc(tick, req.addr);
//     endrule
 
//     rule sendIRespToProc;
//         let req <- iCache.getToProc();
//         proc.getIResp(Mem{byte_en:?, addr:?, data:req});
//     endrule
 
//     rule sendDReqtToCache;
//         let req <- proc.getDReq();
//         dCache.putFromProc(req, 0);
//     endrule
 
//     rule sendDRespToProc;
//         let req <- dCache.getToProc();
//         proc.getDResp(Mem{byte_en:?, addr:?, data:req});
//     endrule
 
    FIFOF#(Bit#(1)) order <- mkFIFOF;

    rule sendMMIOReq1;
       let req <- rv_core1.getMMIOReq();
       mmioHandler.getMMIOReq(req);

       order.enq(0);
    endrule

    rule sendMMIOReq2;
       let req <- rv_core2.getMMIOReq();
       mmioHandler.getMMIOReq(req);

       order.enq(1);
    endrule
    
    rule getMMIOResp;
       let resp <- mmioHandler.putMMIOResp();
       let value = order.first;
       order.deq();
       if (value==0) rv_core1.getMMIOResp(resp);
       else rv_core2.getMMIOResp(resp);

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
            rv_core1.start();
            rv_core2.start();
        endmethod
            endinterface);
    
    interface ddr3 = memController.ddr3;
endmodule
