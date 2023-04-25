/*
 * Generated by Bluespec Compiler, version 2023.01-6-g034050db (build 034050db)
 * 
 * On Tue Apr 25 14:14:14 EDT 2023
 * 
 */

/* Generation options: */
#ifndef __mkDelayLine_h__
#define __mkDelayLine_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkDelayLine module */
class MOD_mkDelayLine : public Module {
 
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
  MOD_Reg<tUInt32> INST_cnt_f;
  MOD_Reg<tUInt32> INST_cnt_s;
  MOD_Reg<tUInt32> INST_ctime;
  MOD_CReg<tUInt32> INST_dl_d_0_rv;
  MOD_CReg<tUInt32> INST_dl_d_10_rv;
  MOD_CReg<tUInt32> INST_dl_d_11_rv;
  MOD_CReg<tUInt32> INST_dl_d_12_rv;
  MOD_CReg<tUInt32> INST_dl_d_13_rv;
  MOD_CReg<tUInt32> INST_dl_d_14_rv;
  MOD_CReg<tUInt32> INST_dl_d_15_rv;
  MOD_CReg<tUInt32> INST_dl_d_16_rv;
  MOD_CReg<tUInt32> INST_dl_d_17_rv;
  MOD_CReg<tUInt32> INST_dl_d_18_rv;
  MOD_CReg<tUInt32> INST_dl_d_19_rv;
  MOD_CReg<tUInt32> INST_dl_d_1_rv;
  MOD_CReg<tUInt32> INST_dl_d_2_rv;
  MOD_CReg<tUInt32> INST_dl_d_3_rv;
  MOD_CReg<tUInt32> INST_dl_d_4_rv;
  MOD_CReg<tUInt32> INST_dl_d_5_rv;
  MOD_CReg<tUInt32> INST_dl_d_6_rv;
  MOD_CReg<tUInt32> INST_dl_d_7_rv;
  MOD_CReg<tUInt32> INST_dl_d_8_rv;
  MOD_CReg<tUInt32> INST_dl_d_9_rv;
 
 /* Constructor */
 public:
  MOD_mkDelayLine(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt32 DEF_dl_d_19_rv_port0__read____d164;
  tUInt32 DEF_cnt_f__h10151;
 
 /* Local definitions */
 private:
  tUInt32 DEF__0_CONCAT_DONTCARE___d7;
 
 /* Rules */
 public:
  void RL_dl_try_move();
  void RL_dl_try_move_1();
  void RL_dl_try_move_2();
  void RL_dl_try_move_3();
  void RL_dl_try_move_4();
  void RL_dl_try_move_5();
  void RL_dl_try_move_6();
  void RL_dl_try_move_7();
  void RL_dl_try_move_8();
  void RL_dl_try_move_9();
  void RL_dl_try_move_10();
  void RL_dl_try_move_11();
  void RL_dl_try_move_12();
  void RL_dl_try_move_13();
  void RL_dl_try_move_14();
  void RL_dl_try_move_15();
  void RL_dl_try_move_16();
  void RL_dl_try_move_17();
  void RL_dl_try_move_18();
  void RL_tic();
  void RL_feed();
  void RL_stream();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkDelayLine &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkDelayLine &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkDelayLine &backing);
};

#endif /* ifndef __mkDelayLine_h__ */
