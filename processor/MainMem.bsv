import RVUtil::*;
import BRAM::*;
import FIFO::*;
import SpecialFIFOs::*;
import DelayLine::*;
import MemTypes::*;
import Cache::*;

interface MainMem;
    method Action put1(MainMemReq req);
    method ActionValue#(MainMemResp) get1();
    method Action put2(MainMemReq req);
    method ActionValue#(MainMemResp) get2();
endinterface

// interface MainMemFast;
//     method Action put(CacheReq req);
//     method ActionValue#(Word) get();
// endinterface

// module mkMainMemFast(MainMemFast);
//     BRAM_Configure cfg = defaultValue();
//     BRAM1Port#(CacheLineAddr, Word) bram <- mkBRAM1Server(cfg);
//     DelayLine#(20, Word) dl <- mkDL(); // Delay by 20 cycles

//     rule deq;
//         let r <- bram.portA.response.get();
//         dl.put(r);
//     endrule    

//     method Action put(CacheReq req);
//         bram.portA.request.put(BRAMRequest{
//                     write: unpack(req.write),
//                     responseOnWrite: False,
//                     address: req.addr,
//                     datain: req.data});
//     endmethod

//     method ActionValue#(Word) get();
//         let r <- dl.get();
//         return r;
//     endmethod
// endmodule

module mkMainMem(MainMem);
    BRAM_Configure cfg = defaultValue();
    cfg.loadFormat = tagged Hex "memlines.vmh";
    BRAM2Port#(LineAddr, MainMemResp) bram <- mkBRAM2Server(cfg);

    // BRAM_Configure cfg = defaultValue();
    // BRAM1Port#(LineAddr, MainMemResp) bram <- mkBRAM1Server(cfg);
    DelayLine#(20, MainMemResp) dl1 <- mkDL(); // Delay by 20 cycles
    DelayLine#(20, MainMemResp) dl2 <- mkDL(); // Delay by 20 cycles

    rule deq1;
        let r <- bram.portA.response.get();
        dl1.put(r);
        // $display("GOT FROM MM TO DL ",fshow(r));
    endrule    

    rule deq2;
        let r <- bram.portB.response.get();
        dl2.put(r);
        // $display("GOT FROM MM TO DL ",fshow(r));
    endrule    

    method Action put1(MainMemReq req);
        bram.portA.request.put(BRAMRequest{
                    write: unpack(req.write),
                    responseOnWrite: False,
                    address: req.addr,
                    datain: req.data});
        // $display("SENT TO MM WITH ",fshow(req));
    endmethod

    method ActionValue#(MainMemResp) get1();
        let r <- dl1.get();
        // $display("GOT FROM DL TO CACHE ",fshow(r));
        return r;
    endmethod

    method Action put2(MainMemReq req);
        bram.portB.request.put(BRAMRequest{
                    write: unpack(req.write),
                    responseOnWrite: False,
                    address: req.addr,
                    datain: req.data});
        $display("SENT TO MM WITH ",fshow(req));
    endmethod

    method ActionValue#(MainMemResp) get2();
        let r <- dl2.get();
        // $display("GOT FROM DL TO CACHE ",fshow(r));
        return r;
    endmethod
endmodule

