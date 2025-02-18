// MULTICORE MAIN FILE
import RVUtil::*;
import BRAM::*;
import pipelined::*;
import FIFO::*;
import MemTypes::*;
import CacheInterfaceMultiCore::*;
// typedef Bit#(32) Word;

module mktop_multicore(Empty);
    CacheInterface cache1 <- mkCacheInterface(0);
    CacheInterface cache2 <- mkCacheInterface(1);
    ParentProtocolProcessor ppp <- mkParentProtocolProcessor(cache1, cache2);

    RVIfc rv_core1 <- mkpipelined(0,0);
    RVIfc rv_core2 <- mkpipelined(4096,1);

    Reg#(Mem) ireq1 <- mkRegU;
    Reg#(Mem) dreq1 <- mkRegU;
    FIFO#(Mem) mmioreq1 <- mkFIFO;

    Reg#(Mem) ireq2 <- mkRegU;
    Reg#(Mem) dreq2 <- mkRegU;
    FIFO#(Mem) mmioreq2 <- mkFIFO;

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

    endrule

    rule responseD1;
        // let x <- bram.portA.response.get();
        let x <- cache1.getRespData();

        let req = dreq1;
        if (debug) $display("Get DResp1 ", fshow(req), fshow(x));
        req.data = x;
            rv_core1.getDResp(req);
    endrule
  
    rule requestMMIO1;
        let req <- rv_core1.getMMIOReq;
        if (debug) $display("Get MMIOReq1 ", fshow(req));
        if (req.byte_en == 'hf) begin
            if (req.addr == 'hf000_fff4) begin
                // Write integer to STDERR
                        $fwrite(stderr, "%0d", req.data);
                        $fflush(stderr);
            end
        end
        if (req.addr ==  'hf000_fff0) begin
                // Writing to STDERR
                $fwrite(stderr, "%c", req.data[7:0]);
                $fflush(stderr);
        end else
            if (req.addr == 'hf000_fff8) begin
            // Exiting Simulation
                $display("RAN CYCLES", cycle_count);
                if (req.data == 0) begin
                        $fdisplay(stderr, "  [0;32mPASS[0m");
                end
                else
                    begin
                        $fdisplay(stderr, "  [0;31mFAIL[0m (%0d)", req.data);
                    end
                $fflush(stderr);
                $finish;
            end

        mmioreq1.enq(req);
    endrule

    rule responseMMIO1;
        let req = mmioreq1.first();
        mmioreq1.deq();
        if (debug) $display("Put MMIOResp1 ", fshow(req));
        rv_core1.getMMIOResp(req);
    endrule


    

    rule requestI2;
        let req <- rv_core2.getIReq;
        // if (debug) $display("Get IReq2 ", fshow(req));
        ireq2 <= req;

        cache2.sendReqInstr(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data});


    endrule

    rule responseI2;
        let x <- cache2.getRespInstr();
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
    endrule

    rule responseD2;
        // let x <- bram.portA.response.get();
        let x <- cache2.getRespData();

        let req = dreq2;
        if (debug) $display("Get DResp2 ", fshow(req), fshow(x));
        req.data = x;
            rv_core2.getDResp(req);
    endrule
  
    rule requestMMIO2;
        let req <- rv_core2.getMMIOReq;
        if (debug) $display("Get MMIOReq2 ", fshow(req));
        if (req.byte_en == 'hf) begin
            if (req.addr == 'hf000_fff4) begin
                // Write integer to STDERR
                        $fwrite(stderr, "%0d", req.data);
                        $fflush(stderr);
            end
        end
        if (req.addr ==  'hf000_fff0) begin
                // Writing to STDERR
                $fwrite(stderr, "%c", req.data[7:0]);
                $fflush(stderr);
        end else
            if (req.addr == 'hf000_fff8) begin
            // Exiting Simulation
                if (req.data == 0) begin
                        $fdisplay(stderr, "  [0;32mPASS[0m");
                end
                else
                    begin
                        $fdisplay(stderr, "  [0;31mFAIL[0m (%0d)", req.data);
                    end
                $fflush(stderr);
                $finish;
            end

        mmioreq2.enq(req);
    endrule

    rule responseMMIO2;
        let req = mmioreq2.first();
        mmioreq2.deq();
        if (debug) $display("Put MMIOResp2 ", fshow(req));
        rv_core2.getMMIOResp(req);
    endrule

    
    
endmodule
