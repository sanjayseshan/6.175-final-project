import FIFO::*;
import SpecialFIFOs::*;
import RegFile::*;
import RVUtil::*;
import Vector::*;
import KonataHelper::*;
import Printf::*;
import Ehr::*;

import CacheInterface::*;

typedef struct { Bit#(4) byte_en; Bit#(32) addr; Bit#(32) data; } Mem deriving (Eq, FShow, Bits);

interface RVIfc;
    method ActionValue#(Mem) getIReq();
    method Action getIResp(Mem a);
    method ActionValue#(Mem) getDReq();
    method Action getDResp(Mem a);
    method ActionValue#(Mem) getMMIOReq();
    method Action getMMIOResp(Mem a);
endinterface
typedef struct { Bool isUnsigned; Bit#(2) size; Bit#(2) offset; Bool mmio; } MemBusiness deriving (Eq, FShow, Bits);

function Bool isMMIO(Bit#(32) addr);
    Bool x = case (addr) 
        32'hf000fff0: True;
        32'hf000fff4: True;
        32'hf000fff8: True;
        default: False;
    endcase;
    return x;
endfunction

typedef struct { Bit#(32) pc;
                 Bit#(32) ppc;
                 Bit#(1) epoch; 
                 KonataId k_id; // <- This is a unique identifier per instructions, for logging purposes
             } F2D deriving (Eq, FShow, Bits);

typedef struct { 
    DecodedInst dinst;
    Bit#(32) pc;
    Bit#(32) ppc;
    Bit#(1) epoch;
    Bit#(32) rv1; 
    Bit#(32) rv2; 
    // Bit#(5) rv1; 
    // Bit#(5) rv2; 
    KonataId k_id; // <- This is a unique identifier per instructions, for logging purposes
} D2E deriving (Eq, FShow, Bits);

typedef struct { 
    MemBusiness mem_business;
    Bit#(32) data;
    Bit#(32) pc;
    DecodedInst dinst;
    KonataId k_id; // <- This is a unique identifier per instructions, for logging purposes
} E2W deriving (Eq, FShow, Bits);


interface BypassRFile;
    method Action wr(Bit#(5) rindx, Bit#(32) data); 
    method Bit#(32) rd1(Bit#(5) rindx);
    method Bit#(32) rd2(Bit#(5) rindx);
endinterface


interface Scoreboard;
    method Action insert(Bit#(5) rindx); 
    method Action remove1(Bit#(5) rindx);
    method Action remove(Bit#(5) rindx);
    method Bit#(2) ready(Bit#(5) rindx);
    // method Bool search2(Bit#(5) rindx);
endinterface


module mkBypassRFile(BypassRFile);
  Vector#(32,Ehr#(2, Bit#(32))) rfile <- replicateM(mkEhr(0));

  method Action wr(Bit#(5) rindx, Bit#(32) data); 
    if(rindx!=0) (rfile[rindx])[0] <= data;
    // $display("WR REG", fshow(rindx),fshow(data));
  endmethod
  method Bit#(32) rd1(Bit#(5) rindx) = (rfile[rindx])[1];
  method Bit#(32) rd2(Bit#(5) rindx) = (rfile[rindx])[1];
endmodule

module mkScoreboard(Scoreboard);
  Vector#(32,Ehr#(4, Bit#(2))) rfile_sb <- replicateM(mkEhr(0));

  method Action insert(Bit#(5) rindx); 
    // $display("SB_INS",fshow(rindx));
    if(rindx!=0) (rfile_sb[rindx])[3] <= (rfile_sb[rindx])[3]+1;
  endmethod

  method Action remove1(Bit#(5) rindx); 
    // $display("SB_REM",fshow(rindx));
    if(rindx!=0) (rfile_sb[rindx])[1] <= (rfile_sb[rindx])[1]-1;
  endmethod

  method Action remove(Bit#(5) rindx); 
    // $display("SB_REM",fshow(rindx));
    if(rindx!=0) (rfile_sb[rindx])[0] <= (rfile_sb[rindx])[0]-1;
  endmethod

  method Bit#(2) ready(Bit#(5) rindx) = (rfile_sb[rindx])[2];
//   method Bit#(2) search2(Bit#(5) rindx) = (rfile_sb[rindx])[1];

endmodule



(* synthesize *)
module mkpipelined#(Bit#(32) start_pc, Bit#(1) coreId)(RVIfc);
    // Interface with memory and devices
    FIFO#(F2D) f2d <- mkFIFO;
    FIFO#(D2E) d2e <- mkFIFO;
    FIFO#(E2W) e2w <- mkFIFO;

    FIFO#(Mem) toImem <- mkBypassFIFO;
    FIFO#(Mem) fromImem <- mkBypassFIFO;
    FIFO#(Mem) toDmem <- mkBypassFIFO;
    FIFO#(Mem) fromDmem <- mkBypassFIFO;
    FIFO#(Mem) toMMIO <- mkBypassFIFO;
    FIFO#(Mem) fromMMIO <- mkBypassFIFO;

    // Vector#(32, Reg#(Bit#(32))) rf <- replicateM(mkReg(0));

    BypassRFile rf <- mkBypassRFile;
    Scoreboard sb <- mkScoreboard;

	// Code to support Konata visualization
    String dumpFile = "output.log" ;
    let lfh <- mkReg(InvalidFile);
	Reg#(KonataId) fresh_id <- mkReg(0);
	Reg#(KonataId) commit_id <- mkReg(0);

	FIFO#(KonataId) retired <- mkFIFO;
	FIFO#(KonataId) squashed <- mkFIFO;
    Bool debug = True;

    Reg#(Bit#(1)) epoch <- mkReg(0);

    
    // Reg#(Bit#(32)) cycle <- mkReg(0);

    // rule cycle_disp;
    //     cycle <= cycle +1;
    //     $display("CYCLE %d\n",cycle);
    // endrule

    Reg#(Bool) starting <- mkReg(True);
    Reg#(Bit#(32)) pc_fetched_reg <- mkReg(0);
	rule do_tic_logging;
        if (starting) begin
            pc_fetched_reg <= start_pc;
            let f <- $fopen(dumpFile, "w") ;
            lfh <= f;
            $fwrite(f, "Kanata\t0004\nC=\t1\n");
            starting <= False;
        end
		konataTic(lfh);
	endrule
		
    rule fetch if (!starting);
        Bit#(32) pc_fetched = pc_fetched_reg;
        if(debug) $display("C",coreId, "[Fetch] %x", pc_fetched_reg);
        pc_fetched_reg <= pc_fetched_reg + 4;

        // You should put the pc that you fetch in pc_fetched
        // Below is the code to support Konata's visualization
		let iid <- fetch1Konata(lfh, fresh_id, 0);
        labelKonataLeft(lfh, iid, $format("PC %x",pc_fetched));
        // TODO implement fetch
            
        // let req = Mem {byte_en : 0,
		// 	   addr : pc,
		// 	   data : 0};

        
        f2d.enq(F2D{pc: pc_fetched,
                 ppc: pc_fetched+4,
                 epoch: epoch, 
                 k_id: iid
                 });

        let req = Mem {byte_en : 0,
			   addr : pc_fetched,
			   data : 0};
        toImem.enq(req);
        // This will likely end with something like:
        // f2d.enq(F2D{ ..... k_id: iid});
        // iid is the unique identifier used by konata, that we will pass around everywhere for each instruction
    endrule

    // Reg#(Bit#(5)) rs1_idx <- mkReg(0);
    // Reg#(Bit#(5)) rs2_idx <- mkReg(0);

    rule decode if (!starting);
        // TODO

        let from_fetch = f2d.first();

        let resp = fromImem.first();
        let instr = resp.data;

        // let instr = from_fetch.data;
        let decodedInst = decodeInst(instr);

        decodeKonata(lfh, from_fetch.k_id);
        labelKonataLeft(lfh,from_fetch.k_id, $format("Instr bits: %x",decodedInst.inst));


        // decodeKonata(lfh, current_id);
        // labelKonataLeft(lfh,current_id, $format("Instr bits: %x",decodedInst.inst));



		let dInst = decodedInst;
        let rs1_idx = getInstFields(instr).rs1;
        let rs2_idx = getInstFields(instr).rs2;
        let stall1 = sb.ready(rs1_idx);
        let stall2 = sb.ready(rs2_idx);
		if (debug) $display("C",coreId,"[Decode] pc ", fshow(from_fetch.pc), fshow(stall1),fshow(stall2), " ", fshow(decodedInst));

        // rs1_idx <= rs1;
        // rs2_idx <= rs2;



		// rv1 <= rs1;
		// rv2 <= rs2;
        // state <= Execute;
        let rs1 = (rs1_idx ==0 ? 0 : rf.rd1(rs1_idx));
        let rs2 = (rs2_idx == 0 ? 0 : rf.rd2(rs2_idx));

        labelKonataLeft(lfh,from_fetch.k_id, $format(" Potential r1: %x, Potential r2: %x" , rs1, rs2));

        if (stall1 == 0 && stall2 == 0 || (rs1_idx == 0 &&& rs2_idx == 0)) begin


            if(debug)  $display("REG ",fshow(from_fetch.pc),fshow(rs1_idx),fshow(rs1),fshow(rs2_idx),fshow(rs2));

            if (decodedInst.valid_rd && getInstFields(instr).rd != 0) begin
                sb.insert(getInstFields(instr).rd);
            end


            f2d.deq();
            fromImem.deq();

            d2e.enq(D2E{dinst: dInst,
                pc: from_fetch.pc,
                ppc: from_fetch.ppc,
                epoch: from_fetch.epoch,
                rv1: rs1,
                rv2: rs2, 
                k_id: from_fetch.k_id});
        end else begin
            if(debug) $display("C",coreId,"STALL ",fshow(getInstFields(instr).rd),fshow(rs1),fshow(rs2),fshow(rs1_idx),fshow(rs2_idx),"S1 ",stall1," S2 ",stall2);
        end
        // To add a decode event in Konata you will likely do something like:
        //  let from_fetch = f2d.first();
   	    //	decodeKonata(lfh, from_fetch.k_id);
        //  labelKonataLeft(lfh,from_fetch.k_id, $format("Any information you would like to put in the left pane in Konata, attached to the current instruction"));
    endrule                                                             

    rule execute if (!starting);
        // TODO
        let from_dec = d2e.first();
        d2e.deq();

        let pc = from_dec.pc;

        let rs1 = from_dec.rv1;
        let rs2 = from_dec.rv2;

        let dInst = from_dec.dinst;

        if (debug) $display("C",coreId,"[Execute]  pc ", fshow(from_dec.pc) ,fshow(epoch),fshow(from_dec.epoch) , " ", fshow(dInst));
        
        if (from_dec.epoch == epoch) begin

            executeKonata(lfh, from_dec.k_id);
            let imm = getImmediate(dInst);
            Bool mmio = False;
            let data = execALU32(dInst.inst, rs1, rs2, imm, from_dec.pc);
            let isUnsigned = 0;
            let funct3 = getInstFields(dInst.inst).funct3;
            let size = funct3[1:0];
            let addr = rs1 + imm;
            Bit#(2) offset = addr[1:0];
            if (isMemoryInst(dInst)) begin
                // Technical details for load byte/halfword/word
                let shift_amount = {offset, 3'b0};
                let byte_en = 0;
                case (size) matches
                2'b00: byte_en = 4'b0001 << offset;
                2'b01: byte_en = 4'b0011 << offset;
                2'b10: byte_en = 4'b1111 << offset;
                endcase
                data = rs2 << shift_amount;
                addr = {addr[31:2], 2'b0};
                isUnsigned = funct3[2];
                let type_mem = (dInst.inst[5] == 1) ? byte_en : 0;
                let req = Mem {byte_en : type_mem,
                        addr : addr,
                        data : data};
                if (isMMIO(addr)) begin 
                    if (debug) $display("[Execute] MMIO", fshow(req));
                    toMMIO.enq(req);
                    labelKonataLeft(lfh,from_dec.k_id, $format(" MMIO ", fshow(req)));
                    mmio = True;
                end else begin 
                    labelKonataLeft(lfh,from_dec.k_id, $format(" MEM ", fshow(req)));
                    toDmem.enq(req);
                end
            end
            else if (isControlInst(dInst)) begin
                    labelKonataLeft(lfh,from_dec.k_id, $format(" Ctrl instr "));
                    data = pc + 4;
            end else begin 
                labelKonataLeft(lfh,from_dec.k_id, $format(" Standard instr "));
            end
            let controlResult = execControl32(dInst.inst, rs1, rs2, imm, pc);
            let nextPc = controlResult.nextPC;

            if (nextPc != from_dec.ppc) begin
                squashed.enq(from_dec.k_id);
                if(debug) $display("C",coreId,"REDIRECT ",fshow(nextPc), fshow(pc));
                pc_fetched_reg <= nextPc;
                epoch <= epoch + 1;
                // d2e.deq();
                // f2d.deq();
            end 
            // else begin
                


            // end

            let mem_b = MemBusiness { isUnsigned : unpack(isUnsigned), size : size, offset : offset, mmio: mmio};
                // state <= Writeback;

            e2w.enq(E2W{mem_business: mem_b,
            pc:pc,
            data:data,
            dinst:dInst,
            k_id:from_dec.k_id});
 
            
            // pc <= nextPc;
            // rvd <= data;



            labelKonataLeft(lfh,from_dec.k_id, $format(" ALU output: %x" , data));
        end else begin
            if(debug) $display("C",coreId,"ANNUL ",fshow(pc));
            if (dInst.valid_rd) sb.remove1(getInstFields(dInst.inst).rd);
            squashed.enq(from_dec.k_id);
        end
        // Similarly, to register an execute event for an instruction:
    	//	executeKonata(lfh, k_id);
    	// where k_id is the unique konata identifier that has been passed around that came from the fetch stage


    	// Execute is also the place where we advise you to kill mispredicted instructions
    	// (instead of Decode + Execute like in the class)
    	// When you kill (or squash) an instruction, you should register an event for Konata:
    	
        // squashed.enq(current_inst.k_id);

        // This will allow Konata to display those instructions in grey
    endrule

    rule writeback if (!starting);
        // TODO
        let from_exec = e2w.first();
        e2w.deq();

        let dInst = from_exec.dinst;

        let mem_business = from_exec.mem_business;

		writebackKonata(lfh,from_exec.k_id);
        retired.enq(from_exec.k_id);
        let data = from_exec.data;
        let fields = getInstFields(dInst.inst);
        if (isMemoryInst(dInst)) begin // (* // write_val *)
            let resp = ?;
		    if (mem_business.mmio) begin 
                resp = fromMMIO.first();
		        fromMMIO.deq();
		    end else begin 
                resp = fromDmem.first();
		        fromDmem.deq();
		    end
            let mem_data = resp.data;
            mem_data = mem_data >> {mem_business.offset ,3'b0};
            case ({pack(mem_business.isUnsigned), mem_business.size}) matches
	     	3'b000 : data = signExtend(mem_data[7:0]);
	     	3'b001 : data = signExtend(mem_data[15:0]);
	     	3'b100 : data = zeroExtend(mem_data[7:0]);
	     	3'b101 : data = zeroExtend(mem_data[15:0]);
	     	3'b010 : data = mem_data;
             endcase
		end
		if(debug) $display("C",coreId,"[Writeback]", fshow(from_exec.pc),fshow(dInst));
        if (!dInst.legal) begin
			if (debug) $display("[Writeback] Illegal Inst, Drop and fault: ", fshow(dInst));
			// pc_fetched_reg <= 0;	// Fault
	    end

        if (dInst.valid_rd) begin
            let rd_idx = fields.rd;
            if(debug) $display("C",coreId,"WR REG__", fshow(rd_idx),fshow(data),fshow(from_exec.pc));

            if (rd_idx != 0) begin rf.wr(rd_idx,data); end
            sb.remove(rd_idx);
		end

        // if (dInst.valid_rd) begin
        //     sb.remove(fields.rd);
        // end

        // Similarly, to register an execute event for an instruction:
	   	//	writebackKonata(lfh,k_id);


	   	// In writeback is also the moment where an instruction retires (there are no more stages)
	   	// Konata requires us to register the event as well using the following: 
		// retired.enq(k_id);
	endrule
		

	// ADMINISTRATION:

    rule administrative_konata_commit;
		    retired.deq();
		    let f = retired.first();
		    commitKonata(lfh, f, commit_id);
	endrule
		
	rule administrative_konata_flush;
		    squashed.deq();
		    let f = squashed.first();
		    squashKonata(lfh, f);
	endrule
		
    method ActionValue#(Mem) getIReq();
		toImem.deq();
		return toImem.first();
    endmethod
    method Action getIResp(Mem a);
    	fromImem.enq(a);
    endmethod
    method ActionValue#(Mem) getDReq();
		toDmem.deq();
		return toDmem.first();
    endmethod
    method Action getDResp(Mem a);
		fromDmem.enq(a);
    endmethod
    method ActionValue#(Mem) getMMIOReq();
		toMMIO.deq();
		return toMMIO.first();
    endmethod
    method Action getMMIOResp(Mem a);
		fromMMIO.enq(a);
    endmethod
endmodule
