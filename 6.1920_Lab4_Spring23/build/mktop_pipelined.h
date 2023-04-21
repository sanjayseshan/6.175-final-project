/*
 * Generated by Bluespec Compiler, version 2021.07 (build 4cac6eb)
 * 
 * On Sat Mar 11 02:07:43 EST 2023
 * 
 */

/* Generation options: */
#ifndef __mktop_pipelined_h__
#define __mktop_pipelined_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkpipelined.h"


/* Class declaration for the mktop_pipelined module */
class MOD_mktop_pipelined : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_BRAM<tUInt32,tUInt32,tUInt8> INST_bram_memory;
  MOD_Reg<tUInt8> INST_bram_serverAdapterA_cnt;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_cnt_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_cnt_2;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_cnt_3;
  MOD_Fifo<tUInt32> INST_bram_serverAdapterA_outDataCore;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_outData_deqCalled;
  MOD_Wire<tUInt32> INST_bram_serverAdapterA_outData_enqData;
  MOD_Wire<tUInt32> INST_bram_serverAdapterA_outData_outData;
  MOD_Reg<tUInt8> INST_bram_serverAdapterA_s1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_s1_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_writeWithResp;
  MOD_Reg<tUInt8> INST_bram_serverAdapterB_cnt;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_cnt_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_cnt_2;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_cnt_3;
  MOD_Fifo<tUInt32> INST_bram_serverAdapterB_outDataCore;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_outData_deqCalled;
  MOD_Wire<tUInt32> INST_bram_serverAdapterB_outData_enqData;
  MOD_Wire<tUInt32> INST_bram_serverAdapterB_outData_outData;
  MOD_Reg<tUInt8> INST_bram_serverAdapterB_s1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_s1_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_writeWithResp;
  MOD_Reg<tUInt32> INST_cycle_count;
  MOD_Reg<tUWide> INST_dreq;
  MOD_Reg<tUWide> INST_ireq;
  MOD_Fifo<tUWide> INST_mmioreq;
  MOD_mkpipelined INST_rv_core;
 
 /* Constructor */
 public:
  MOD_mktop_pipelined(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_b__h2292;
  tUInt8 DEF_b__h947;
  tUInt8 DEF_bram_serverAdapterB_s1___d100;
  tUInt8 DEF_bram_serverAdapterA_s1___d46;
  tUInt8 DEF_bram_serverAdapterB_cnt_3_whas____d79;
  tUInt8 DEF_bram_serverAdapterB_cnt_2_whas____d77;
  tUInt8 DEF_bram_serverAdapterB_cnt_1_whas____d76;
  tUInt8 DEF_bram_serverAdapterA_cnt_3_whas____d24;
  tUInt8 DEF_bram_serverAdapterA_cnt_2_whas____d22;
  tUInt8 DEF_bram_serverAdapterA_cnt_1_whas____d21;
  tUInt8 DEF_bram_serverAdapterB_s1_00_BIT_0___d101;
  tUInt8 DEF_bram_serverAdapterA_s1_6_BIT_0___d47;
 
 /* Local definitions */
 private:
  tUWide DEF_rv_core_getMMIOReq___d153;
  tUWide DEF_rv_core_getDReq___d134;
  tUWide DEF_rv_core_getIReq___d115;
  tUWide DEF_mmioreq_first____d170;
  tUWide DEF_dreq___d146;
  tUWide DEF_ireq___d127;
  tUInt32 DEF_x_wget__h1709;
  tUInt32 DEF_x_wget__h356;
  tUInt32 DEF_x__h1854;
  tUInt32 DEF_x__h504;
  tUInt8 DEF__0_CONCAT_DONTCARE___d37;
  tUWide DEF_ireq_27_BITS_67_TO_32_28_CONCAT_bram_serverAda_ETC___d130;
  tUWide DEF_dreq_46_BITS_67_TO_32_47_CONCAT_bram_serverAda_ETC___d149;
 
 /* Rules */
 public:
  void RL_bram_serverAdapterA_outData_setFirstCore();
  void RL_bram_serverAdapterA_outData_setFirstEnq();
  void RL_bram_serverAdapterA_outData_enqOnly();
  void RL_bram_serverAdapterA_outData_deqOnly();
  void RL_bram_serverAdapterA_outData_enqAndDeq();
  void RL_bram_serverAdapterA_cnt_finalAdd();
  void RL_bram_serverAdapterA_s1__dreg_update();
  void RL_bram_serverAdapterA_stageReadResponseAlways();
  void RL_bram_serverAdapterA_moveToOutFIFO();
  void RL_bram_serverAdapterA_overRun();
  void RL_bram_serverAdapterB_outData_setFirstCore();
  void RL_bram_serverAdapterB_outData_setFirstEnq();
  void RL_bram_serverAdapterB_outData_enqOnly();
  void RL_bram_serverAdapterB_outData_deqOnly();
  void RL_bram_serverAdapterB_outData_enqAndDeq();
  void RL_bram_serverAdapterB_cnt_finalAdd();
  void RL_bram_serverAdapterB_s1__dreg_update();
  void RL_bram_serverAdapterB_stageReadResponseAlways();
  void RL_bram_serverAdapterB_moveToOutFIFO();
  void RL_bram_serverAdapterB_overRun();
  void RL_tic();
  void RL_requestI();
  void RL_responseI();
  void RL_requestD();
  void RL_responseD();
  void RL_requestMMIO();
  void RL_responseMMIO();
 
 /* Methods */
 public:
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mktop_pipelined &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mktop_pipelined &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mktop_pipelined &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mktop_pipelined &backing);
};

#endif /* ifndef __mktop_pipelined_h__ */
