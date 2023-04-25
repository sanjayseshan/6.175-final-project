import RVUtil::*;
import BRAM::*;
import FIFO::*;
import SpecialFIFOs::*;
import DelayLine::*;
import MemTypes::*;
import Cache::*;

interface MainMem;
    method Action put(MainMemReq req);
    method ActionValue#(MainMemResp) get();
endinterface

interface MainMemFast;
    method Action put(CacheReq req);
    method ActionValue#(Word) get();
endinterface

module mkMainMemFast(MainMemFast);
    BRAM_Configure cfg = defaultValue();
    BRAM1Port#(CacheLineAddr, Word) bram <- mkBRAM1Server(cfg);
    DelayLine#(20, Word) dl <- mkDL(); // Delay by 20 cycles

    rule deq;
        let r <- bram.portA.response.get();
        dl.put(r);
    endrule    

    method Action put(CacheReq req);
        bram.portA.request.put(BRAMRequest{
                    write: unpack(req.write),
                    responseOnWrite: False,
                    address: req.addr,
                    datain: req.data});
    endmethod

    method ActionValue#(Word) get();
        let r <- dl.get();
        return r;
    endmethod
endmodule

module mkMainMem(MainMem);
    BRAM_Configure cfg = defaultValue();
    BRAM1Port#(LineAddr, MainMemResp) bram <- mkBRAM1Server(cfg);
    DelayLine#(40, MainMemResp) dl <- mkDL(); // Delay by 20 cycles

    rule deq;
        let r <- bram.portA.response.get();
        dl.put(r);
        // $display("GOT FROM MM TO DL ",fshow(r));
    endrule    

    method Action put(MainMemReq req);
        bram.portA.request.put(BRAMRequest{
                    write: unpack(req.write),
                    responseOnWrite: False,
                    address: req.addr,
                    datain: req.data});
        // $display("SENT TO MM WITH ",fshow(req));
    endmethod

    method ActionValue#(MainMemResp) get();
        let r <- dl.get();
        // $display("GOT FROM DL TO CACHE ",fshow(r));
        return r;
    endmethod
endmodule

