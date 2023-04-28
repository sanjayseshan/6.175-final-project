/*
 * Generated by Bluespec Compiler, version 2023.01-6-g034050db (build 034050db)
 * 
 * On Thu Apr 27 11:39:17 EDT 2023
 * 
 */

/* Generation options: */
#ifndef __mkBeveren_nested_h__
#define __mkBeveren_nested_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkBeveren_nested module */
class MOD_mkBeveren_nested : public Module {
 
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
  MOD_BRAM<tUInt8,tUWide,tUInt8> INST_cache2_bram_memory;
  MOD_Reg<tUInt8> INST_cache2_bram_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_cache2_bram_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_cache2_bram_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_cache2_bram_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_cache2_bram_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_cache2_bram_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_cache2_bram_serverAdapter_outData_dequeueing;
  MOD_Wire<tUWide> INST_cache2_bram_serverAdapter_outData_enqw;
  MOD_Fifo<tUWide> INST_cache2_bram_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_cache2_bram_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_cache2_bram_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_cache2_bram_serverAdapter_writeWithResp;
  MOD_Reg<tUInt32> INST_cache2_cycle;
  MOD_Fifo<tUWide> INST_cache2_hitQ;
  MOD_Reg<tUInt8> INST_cache2_lockL1;
  MOD_Fifo<tUWide> INST_cache2_memReqQ;
  MOD_Fifo<tUWide> INST_cache2_memRespQ;
  MOD_Reg<tUWide> INST_cache2_missReq;
  MOD_Reg<tUInt8> INST_cache2_mshr;
  MOD_Reg<tUInt8> INST_cache2_start_fill;
  MOD_Fifo<tUWide> INST_cache2_stb;
  MOD_Reg<tUWide> INST_cache2_working;
  MOD_Reg<tUWide> INST_cache2_working_line;
  MOD_Reg<tUInt8> INST_cache2_working_v;
  MOD_BRAM<tUInt8,tUWide,tUInt8> INST_cache_bram_memory;
  MOD_Reg<tUInt8> INST_cache_bram_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_cache_bram_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_cache_bram_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_cache_bram_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_cache_bram_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_cache_bram_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_cache_bram_serverAdapter_outData_dequeueing;
  MOD_Wire<tUWide> INST_cache_bram_serverAdapter_outData_enqw;
  MOD_Fifo<tUWide> INST_cache_bram_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_cache_bram_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_cache_bram_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_cache_bram_serverAdapter_writeWithResp;
  MOD_Reg<tUInt32> INST_cache_cycle;
  MOD_Fifo<tUInt32> INST_cache_hitQ;
  MOD_Reg<tUInt8> INST_cache_lockL1;
  MOD_Fifo<tUWide> INST_cache_memReqQ;
  MOD_Fifo<tUWide> INST_cache_memRespQ;
  MOD_Reg<tUInt8> INST_cache_mshr;
  MOD_Reg<tUInt8> INST_cache_start_fill;
  MOD_Fifo<tUInt64> INST_cache_stb;
  MOD_Reg<tUWide> INST_cache_working;
  MOD_Reg<tUWide> INST_cache_working_line;
  MOD_Reg<tUInt8> INST_cache_working_v;
  MOD_Reg<tUInt32> INST_counterIn;
  MOD_Reg<tUInt32> INST_counterOut;
  MOD_Reg<tUInt32> INST_deadlockChecker;
  MOD_Reg<tUInt8> INST_doinit;
  MOD_BRAM<tUInt32,tUWide,tUInt8> INST_mainMem_bram_memory;
  MOD_Reg<tUInt8> INST_mainMem_bram_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_mainMem_bram_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_mainMem_bram_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_mainMem_bram_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_mainMem_bram_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_mainMem_bram_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_mainMem_bram_serverAdapter_outData_dequeueing;
  MOD_Wire<tUWide> INST_mainMem_bram_serverAdapter_outData_enqw;
  MOD_Fifo<tUWide> INST_mainMem_bram_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_mainMem_bram_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_mainMem_bram_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_mainMem_bram_serverAdapter_writeWithResp;
  MOD_CReg<tUWide> INST_mainMem_dl_d_0_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_10_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_11_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_12_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_13_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_14_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_15_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_16_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_17_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_18_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_19_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_1_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_20_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_21_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_22_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_23_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_24_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_25_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_26_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_27_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_28_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_29_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_2_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_30_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_31_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_32_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_33_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_34_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_35_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_36_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_37_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_38_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_39_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_3_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_4_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_5_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_6_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_7_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_8_rv;
  MOD_CReg<tUWide> INST_mainMem_dl_d_9_rv;
  MOD_BRAM<tUInt32,tUInt32,tUInt8> INST_mainRef_bram_memory;
  MOD_Reg<tUInt8> INST_mainRef_bram_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_mainRef_bram_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_mainRef_bram_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_mainRef_bram_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_mainRef_bram_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_mainRef_bram_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_mainRef_bram_serverAdapter_outData_dequeueing;
  MOD_Wire<tUInt32> INST_mainRef_bram_serverAdapter_outData_enqw;
  MOD_Fifo<tUInt32> INST_mainRef_bram_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_mainRef_bram_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_mainRef_bram_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_mainRef_bram_serverAdapter_writeWithResp;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_0_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_10_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_11_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_12_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_13_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_14_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_15_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_16_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_17_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_18_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_19_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_1_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_2_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_3_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_4_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_5_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_6_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_7_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_8_rv;
  MOD_CReg<tUInt64> INST_mainRef_dl_d_9_rv;
  MOD_Wire<tUWide> INST_randomMem_ignore;
  MOD_Reg<tUInt8> INST_randomMem_initialized;
  MOD_Wire<tUWide> INST_randomMem_zaz;
 
 /* Constructor */
 public:
  MOD_mkBeveren_nested(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF_cache2_stb_first__001_BITS_537_TO_512_002_EQ_c_ETC___d1004;
  tUInt8 DEF_NOT_IF_cache2_bram_serverAdapter_outData_ff_i__ETC___d1021;
  tUInt8 DEF_cache2_stb_notEmpty____d997;
  tUInt8 DEF_NOT_cache2_stb_notEmpty__97___d998;
  tUInt8 DEF_cache2_stb_notEmpty__97_AND_cache2_stb_first___ETC___d1005;
  tUInt8 DEF_x__h58904;
  tUInt8 DEF_cache_stb_first__54_BITS_63_TO_32_55_EQ_cache__ETC___d657;
  tUInt8 DEF_NOT_IF_cache_bram_serverAdapter_outData_ff_i_n_ETC___d674;
  tUInt8 DEF_cache_stb_notEmpty____d650;
  tUInt8 DEF_NOT_cache_stb_notEmpty__50___d651;
  tUInt8 DEF_cache_stb_notEmpty__50_AND_cache_stb_first__54_ETC___d658;
  tUWide DEF_cache2_working___d994;
  tUWide DEF_cache2_stb_first____d1001;
  tUWide DEF_cache2_working_line___d1054;
  tUWide DEF_cache2_bram_serverAdapter_outData_enqw_wget____d948;
  tUWide DEF_cache2_bram_serverAdapter_outData_ff_first____d1008;
  tUWide DEF_cache_working_line___d769;
  tUWide DEF_cache_bram_serverAdapter_outData_enqw_wget____d601;
  tUWide DEF_cache_bram_serverAdapter_outData_ff_first____d661;
  tUWide DEF_mainMem_dl_d_39_rv_port0__read____d1120;
  tUWide DEF_mainMem_dl_d_0_rv_port1__read____d588;
  tUWide DEF_cache_working___d647;
  tUInt64 DEF_cache_stb_first____d654;
  tUInt64 DEF_mainRef_dl_d_19_rv_port0__read____d1146;
  tUInt32 DEF_x__h60787;
  tUInt8 DEF_b__h57243;
  tUInt8 DEF_b__h38132;
  tUInt8 DEF_b__h12837;
  tUInt8 DEF_b__h1327;
  tUInt8 DEF_cache2_bram_serverAdapter_s1___d974;
  tUInt8 DEF_cache_bram_serverAdapter_s1___d627;
  tUInt8 DEF_mainMem_bram_serverAdapter_s1___d257;
  tUInt8 DEF_mainRef_bram_serverAdapter_s1___d46;
  tUInt8 DEF_cache2_memRespQ_notEmpty____d1079;
  tUInt8 DEF_cache2_bram_serverAdapter_cnt_3_whas____d953;
  tUInt8 DEF_cache2_bram_serverAdapter_cnt_2_whas____d951;
  tUInt8 DEF_cache2_bram_serverAdapter_cnt_1_whas____d950;
  tUInt8 DEF_cache2_bram_serverAdapter_outData_ff_i_notEmpty____d945;
  tUInt8 DEF_cache_memRespQ_notEmpty____d858;
  tUInt8 DEF_cache_bram_serverAdapter_cnt_3_whas____d606;
  tUInt8 DEF_cache_bram_serverAdapter_cnt_2_whas____d604;
  tUInt8 DEF_cache_bram_serverAdapter_cnt_1_whas____d603;
  tUInt8 DEF_cache_bram_serverAdapter_outData_ff_i_notEmpty____d598;
  tUInt8 DEF_mainMem_bram_serverAdapter_cnt_3_whas____d236;
  tUInt8 DEF_mainMem_bram_serverAdapter_cnt_2_whas____d234;
  tUInt8 DEF_mainMem_bram_serverAdapter_cnt_1_whas____d233;
  tUInt8 DEF_mainMem_bram_serverAdapter_outData_ff_i_notEmpty____d227;
  tUInt8 DEF_mainRef_bram_serverAdapter_cnt_3_whas____d24;
  tUInt8 DEF_mainRef_bram_serverAdapter_cnt_2_whas____d22;
  tUInt8 DEF_mainRef_bram_serverAdapter_cnt_1_whas____d21;
  tUInt8 DEF_mainRef_bram_serverAdapter_outData_ff_i_notEmpty____d15;
  tUInt32 DEF__read_memReq_addr__h47451;
  tUInt32 DEF__read_memReq_addr__h58861;
  tUInt32 DEF_y__h58900;
  tUInt32 DEF_x__h59085;
  tUInt32 DEF__read_tag__h59114;
  tUInt32 DEF_x_wget_tag__h56775;
  tUInt32 DEF_x_first_tag__h58740;
  tUInt32 DEF__read_tag__h47702;
  tUInt32 DEF_x_first_tag__h43505;
  tUInt32 DEF_x_wget_tag__h33976;
  tUInt32 DEF_y__h47492;
  tUInt32 DEF_x__h47672;
  tUInt8 DEF_x__h59357;
  tUInt8 DEF_x_wget_valid__h56774;
  tUInt8 DEF_x_first_valid__h58739;
  tUInt8 DEF_x__h49915;
  tUInt8 DEF_x_first_valid__h43504;
  tUInt8 DEF_x_wget_valid__h33975;
  tUInt8 DEF_cache2_working_94_BIT_538___d995;
  tUInt8 DEF_cache_working_47_BIT_68___d648;
  tUInt8 DEF_cache2_bram_serverAdapter_s1_74_BIT_0___d975;
  tUInt8 DEF_cache_bram_serverAdapter_s1_27_BIT_0___d628;
  tUInt8 DEF_mainMem_bram_serverAdapter_s1_57_BIT_0___d258;
  tUInt8 DEF_mainRef_bram_serverAdapter_s1_6_BIT_0___d47;
  tUInt32 DEF_x__h58899;
  tUInt32 DEF_x_tag__h34013;
  tUInt8 DEF_x_valid__h34012;
  tUInt8 DEF_cache2_stb_first__001_BITS_537_TO_519_053_EQ_c_ETC___d1056;
  tUInt8 DEF_IF_cache2_bram_serverAdapter_outData_ff_i_notE_ETC___d1014;
  tUInt8 DEF_cache_stb_first__54_BITS_63_TO_45_68_EQ_cache__ETC___d771;
  tUInt8 DEF_IF_cache_bram_serverAdapter_outData_ff_i_notEm_ETC___d667;
  tUInt8 DEF_cache2_working_line_054_BITS_532_TO_531_067_EQ_2___d1068;
  tUInt8 DEF_IF_cache2_bram_serverAdapter_outData_ff_i_notE_ETC___d1020;
  tUInt8 DEF_cache_working_line_69_BITS_532_TO_531_38_EQ_2___d839;
  tUInt8 DEF_IF_cache_bram_serverAdapter_outData_ff_i_notEm_ETC___d673;
  tUInt8 DEF_NOT_cache2_stb_first__001_BITS_537_TO_519_053__ETC___d1057;
  tUInt8 DEF_NOT_cache_stb_first__54_BITS_63_TO_45_68_EQ_ca_ETC___d772;
  tUInt8 DEF_NOT_cache2_working_94_BIT_538_95___d1037;
  tUInt8 DEF_NOT_cache_working_47_BIT_68_48___d690;
 
 /* Local definitions */
 private:
  tUInt8 DEF_x__h47551;
  tUInt32 DEF_v__h357;
  tUInt32 DEF_v__h319;
  tUInt32 DEF_v__h282;
  tUWide DEF_cache2_memReqQ_first____d1114;
  tUWide DEF_cache_memReqQ_first____d1101;
  tUWide DEF_cache2_bram_memory_read____d981;
  tUWide DEF_cache_bram_memory_read____d634;
  tUWide DEF_mainMem_dl_d_39_rv_port1__read____d275;
  tUWide DEF_mainMem_dl_d_38_rv_port1__read____d284;
  tUWide DEF_mainMem_dl_d_38_rv_port0__read____d273;
  tUWide DEF_mainMem_dl_d_37_rv_port1__read____d292;
  tUWide DEF_mainMem_dl_d_37_rv_port0__read____d282;
  tUWide DEF_mainMem_dl_d_36_rv_port1__read____d300;
  tUWide DEF_mainMem_dl_d_36_rv_port0__read____d290;
  tUWide DEF_mainMem_dl_d_35_rv_port1__read____d308;
  tUWide DEF_mainMem_dl_d_35_rv_port0__read____d298;
  tUWide DEF_mainMem_dl_d_34_rv_port1__read____d316;
  tUWide DEF_mainMem_dl_d_34_rv_port0__read____d306;
  tUWide DEF_mainMem_dl_d_33_rv_port1__read____d324;
  tUWide DEF_mainMem_dl_d_33_rv_port0__read____d314;
  tUWide DEF_mainMem_dl_d_32_rv_port1__read____d332;
  tUWide DEF_mainMem_dl_d_32_rv_port0__read____d322;
  tUWide DEF_mainMem_dl_d_31_rv_port1__read____d340;
  tUWide DEF_mainMem_dl_d_31_rv_port0__read____d330;
  tUWide DEF_mainMem_dl_d_30_rv_port1__read____d348;
  tUWide DEF_mainMem_dl_d_30_rv_port0__read____d338;
  tUWide DEF_mainMem_dl_d_29_rv_port1__read____d356;
  tUWide DEF_mainMem_dl_d_29_rv_port0__read____d346;
  tUWide DEF_mainMem_dl_d_28_rv_port1__read____d364;
  tUWide DEF_mainMem_dl_d_28_rv_port0__read____d354;
  tUWide DEF_mainMem_dl_d_27_rv_port1__read____d372;
  tUWide DEF_mainMem_dl_d_27_rv_port0__read____d362;
  tUWide DEF_mainMem_dl_d_26_rv_port1__read____d380;
  tUWide DEF_mainMem_dl_d_26_rv_port0__read____d370;
  tUWide DEF_mainMem_dl_d_25_rv_port1__read____d388;
  tUWide DEF_mainMem_dl_d_25_rv_port0__read____d378;
  tUWide DEF_mainMem_dl_d_24_rv_port1__read____d396;
  tUWide DEF_mainMem_dl_d_24_rv_port0__read____d386;
  tUWide DEF_mainMem_dl_d_23_rv_port1__read____d404;
  tUWide DEF_mainMem_dl_d_23_rv_port0__read____d394;
  tUWide DEF_mainMem_dl_d_22_rv_port1__read____d412;
  tUWide DEF_mainMem_dl_d_22_rv_port0__read____d402;
  tUWide DEF_mainMem_dl_d_21_rv_port1__read____d420;
  tUWide DEF_mainMem_dl_d_21_rv_port0__read____d410;
  tUWide DEF_mainMem_dl_d_20_rv_port1__read____d428;
  tUWide DEF_mainMem_dl_d_20_rv_port0__read____d418;
  tUWide DEF_mainMem_dl_d_19_rv_port1__read____d436;
  tUWide DEF_mainMem_dl_d_19_rv_port0__read____d426;
  tUWide DEF_mainMem_dl_d_18_rv_port1__read____d444;
  tUWide DEF_mainMem_dl_d_18_rv_port0__read____d434;
  tUWide DEF_mainMem_dl_d_17_rv_port1__read____d452;
  tUWide DEF_mainMem_dl_d_17_rv_port0__read____d442;
  tUWide DEF_mainMem_dl_d_16_rv_port1__read____d460;
  tUWide DEF_mainMem_dl_d_16_rv_port0__read____d450;
  tUWide DEF_mainMem_dl_d_15_rv_port1__read____d468;
  tUWide DEF_mainMem_dl_d_15_rv_port0__read____d458;
  tUWide DEF_mainMem_dl_d_14_rv_port1__read____d476;
  tUWide DEF_mainMem_dl_d_14_rv_port0__read____d466;
  tUWide DEF_mainMem_dl_d_13_rv_port1__read____d484;
  tUWide DEF_mainMem_dl_d_13_rv_port0__read____d474;
  tUWide DEF_mainMem_dl_d_12_rv_port1__read____d492;
  tUWide DEF_mainMem_dl_d_12_rv_port0__read____d482;
  tUWide DEF_mainMem_dl_d_11_rv_port1__read____d500;
  tUWide DEF_mainMem_dl_d_11_rv_port0__read____d490;
  tUWide DEF_mainMem_dl_d_10_rv_port1__read____d508;
  tUWide DEF_mainMem_dl_d_10_rv_port0__read____d498;
  tUWide DEF_mainMem_dl_d_9_rv_port1__read____d516;
  tUWide DEF_mainMem_dl_d_9_rv_port0__read____d506;
  tUWide DEF_mainMem_dl_d_8_rv_port1__read____d524;
  tUWide DEF_mainMem_dl_d_8_rv_port0__read____d514;
  tUWide DEF_mainMem_dl_d_7_rv_port1__read____d532;
  tUWide DEF_mainMem_dl_d_7_rv_port0__read____d522;
  tUWide DEF_mainMem_dl_d_6_rv_port1__read____d540;
  tUWide DEF_mainMem_dl_d_6_rv_port0__read____d530;
  tUWide DEF_mainMem_dl_d_5_rv_port1__read____d548;
  tUWide DEF_mainMem_dl_d_5_rv_port0__read____d538;
  tUWide DEF_mainMem_dl_d_4_rv_port1__read____d556;
  tUWide DEF_mainMem_dl_d_4_rv_port0__read____d546;
  tUWide DEF_mainMem_dl_d_3_rv_port1__read____d564;
  tUWide DEF_mainMem_dl_d_3_rv_port0__read____d554;
  tUWide DEF_mainMem_dl_d_2_rv_port1__read____d572;
  tUWide DEF_mainMem_dl_d_2_rv_port0__read____d562;
  tUWide DEF_mainMem_dl_d_1_rv_port1__read____d580;
  tUWide DEF_mainMem_dl_d_1_rv_port0__read____d570;
  tUWide DEF_mainMem_dl_d_0_rv_port0__read____d578;
  tUWide DEF_data__h59515;
  tUWide DEF_v__h60215;
  tUWide DEF_cache_memRespQ_first____d869;
  tUWide DEF_x_wget__h12344;
  tUWide DEF_x_first__h12229;
  tUWide DEF_v__h13407;
  tUWide DEF_x_wget__h217;
  tUInt32 DEF_x_wget__h834;
  tUWide DEF_cache2_working_94_BITS_538_TO_0___d1052;
  tUWide DEF_cache2_working_94_BITS_537_TO_0___d1036;
  tUWide DEF_din_datain_data__h59733;
  tUWide DEF_x3__h60355;
  tUWide DEF_x__h58939;
  tUWide DEF_x_data__h59394;
  tUWide DEF_x_wget_data__h56776;
  tUWide DEF_x_first_data__h58741;
  tUWide DEF_x__h60534;
  tUWide DEF_x__h33258;
  tUWide DEF_x__h33000;
  tUWide DEF_x__h32742;
  tUWide DEF_x__h32484;
  tUWide DEF_x__h32226;
  tUWide DEF_x__h31968;
  tUWide DEF_x__h31710;
  tUWide DEF_x__h31452;
  tUWide DEF_x__h31194;
  tUWide DEF_x__h30936;
  tUWide DEF_x__h30678;
  tUWide DEF_x__h30420;
  tUWide DEF_x__h30162;
  tUWide DEF_x__h29904;
  tUWide DEF_x__h29646;
  tUWide DEF_x__h29388;
  tUWide DEF_x__h29130;
  tUWide DEF_x__h28872;
  tUWide DEF_x__h28614;
  tUWide DEF_x__h28356;
  tUWide DEF_x__h28098;
  tUWide DEF_x__h27840;
  tUWide DEF_x__h27582;
  tUWide DEF_x__h27324;
  tUWide DEF_x__h27066;
  tUWide DEF_x__h26808;
  tUWide DEF_x__h26550;
  tUWide DEF_x__h26292;
  tUWide DEF_x__h26034;
  tUWide DEF_x__h25776;
  tUWide DEF_x__h25518;
  tUWide DEF_x__h25260;
  tUWide DEF_x__h25002;
  tUWide DEF_x__h24744;
  tUWide DEF_x__h24486;
  tUWide DEF_x__h24228;
  tUWide DEF_x__h23970;
  tUWide DEF_x__h23712;
  tUWide DEF_x__h23454;
  tUInt32 DEF_cache_working_line_69_BITS_511_TO_480___d782;
  tUInt32 DEF_cache_working_line_69_BITS_479_TO_448___d785;
  tUInt32 DEF_cache_working_line_69_BITS_447_TO_416___d789;
  tUInt32 DEF_cache_working_line_69_BITS_415_TO_384___d792;
  tUInt32 DEF_cache_working_line_69_BITS_383_TO_352___d796;
  tUInt32 DEF_cache_working_line_69_BITS_351_TO_320___d799;
  tUInt32 DEF_cache_working_line_69_BITS_319_TO_288___d803;
  tUInt32 DEF_cache_working_line_69_BITS_287_TO_256___d806;
  tUInt32 DEF_cache_working_line_69_BITS_255_TO_224___d810;
  tUInt32 DEF_cache_working_line_69_BITS_223_TO_192___d813;
  tUInt32 DEF_cache_working_line_69_BITS_191_TO_160___d817;
  tUInt32 DEF_cache_working_line_69_BITS_159_TO_128___d820;
  tUInt32 DEF_cache_working_line_69_BITS_127_TO_96___d824;
  tUInt32 DEF_cache_working_line_69_BITS_95_TO_64___d827;
  tUInt32 DEF_cache_working_line_69_BITS_63_TO_32___d831;
  tUInt32 DEF_cache_working_line_69_BITS_31_TO_0___d834;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_511_TO_480___d892;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_479_TO_448___d891;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_447_TO_416___d889;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_415_TO_384___d888;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_383_TO_352___d886;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_351_TO_320___d885;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_319_TO_288___d883;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_287_TO_256___d882;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_255_TO_224___d880;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_223_TO_192___d879;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_191_TO_160___d877;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_159_TO_128___d876;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_127_TO_96___d874;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_95_TO_64___d873;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_63_TO_32___d871;
  tUInt32 DEF_cache_memRespQ_first__69_BITS_31_TO_0___d870;
  tUWide DEF_v__h432;
  tUInt32 DEF_x__h47530;
  tUInt8 DEF__read_idx__h58855;
  tUInt8 DEF__read_idx__h47444;
  tUWide DEF_IF_cache2_bram_serverAdapter_outData_ff_i_notE_ETC___d1035;
  tUWide DEF_IF_cache2_bram_serverAdapter_outData_enqw_whas_ETC___d1034;
  tUWide DEF_IF_cache_bram_serverAdapter_outData_ff_i_notEm_ETC___d688;
  tUWide DEF_IF_cache_bram_serverAdapter_outData_enqw_whas__ETC___d687;
  tUWide DEF_v__h60401;
  tUWide DEF_IF_cache2_stb_notEmpty__97_AND_cache2_stb_firs_ETC___d1047;
  tUWide DEF_x__h58954;
  tUWide DEF_IF_cache2_bram_serverAdapter_outData_enqw_whas_ETC___d1045;
  tUWide DEF_IF_mainMem_bram_serverAdapter_outData_ff_i_not_ETC___d593;
  tUWide DEF_x__h12442;
  tUInt32 DEF_x__h932;
  tUInt8 DEF__0_CONCAT_DONTCARE___d37;
  tUWide DEF_cache_memReqQ_first__101_BITS_537_TO_512_103_C_ETC___d1104;
  tUWide DEF__1_CONCAT_cache2_stb_first__001___d1066;
  tUWide DEF__1_CONCAT_cache_working_line_69_BITS_530_TO_512_ETC___d854;
  tUWide DEF_x_data__h49954;
  tUWide DEF__1_CONCAT_cache2_working_line_054_BITS_530_TO_5_ETC___d1076;
  tUWide DEF__0_CONCAT_cache_working_47_CONCAT_DONTCARE___d857;
  tUWide DEF__2_CONCAT_cache2_stb_first__001_BITS_537_TO_519_ETC___d1065;
  tUWide DEF__2_CONCAT_cache_stb_first__54_BITS_63_TO_45_68__ETC___d837;
  tUWide DEF_IF_cache_stb_first__54_BITS_37_TO_34_80_EQ_15__ETC___d836;
  tUWide DEF__2_CONCAT_cache_working_47_BITS_94_TO_76_66_CON_ETC___d941;
  tUWide DEF_IF_cache_working_47_BITS_3_TO_0_61_EQ_15_00_TH_ETC___d940;
  tUWide DEF__1_CONCAT_cache2_working_94_BITS_564_TO_546_013_ETC___d1091;
  tUWide DEF__1_CONCAT_cache2_working_94_BITS_564_TO_546_013_ETC___d1095;
  tUWide DEF__1_CONCAT_cache_working_47_BITS_94_TO_76_66_CON_ETC___d894;
  tUWide DEF_cache_memRespQ_first__69_BITS_31_TO_0_70_CONCA_ETC___d893;
  tUWide DEF__1_CONCAT_IF_mainMem_bram_serverAdapter_outData_ETC___d594;
  tUWide DEF__1_CONCAT_mainMem_dl_d_0_rv_port0__read__78_BIT_ETC___d585;
  tUWide DEF__1_CONCAT_mainMem_dl_d_1_rv_port0__read__70_BIT_ETC___d577;
  tUWide DEF__1_CONCAT_mainMem_dl_d_2_rv_port0__read__62_BIT_ETC___d569;
  tUWide DEF__1_CONCAT_mainMem_dl_d_3_rv_port0__read__54_BIT_ETC___d561;
  tUWide DEF__1_CONCAT_mainMem_dl_d_4_rv_port0__read__46_BIT_ETC___d553;
  tUWide DEF__1_CONCAT_mainMem_dl_d_5_rv_port0__read__38_BIT_ETC___d545;
  tUWide DEF__1_CONCAT_mainMem_dl_d_6_rv_port0__read__30_BIT_ETC___d537;
  tUWide DEF__1_CONCAT_mainMem_dl_d_7_rv_port0__read__22_BIT_ETC___d529;
  tUWide DEF__1_CONCAT_mainMem_dl_d_8_rv_port0__read__14_BIT_ETC___d521;
  tUWide DEF__1_CONCAT_mainMem_dl_d_9_rv_port0__read__06_BIT_ETC___d513;
  tUWide DEF__1_CONCAT_mainMem_dl_d_10_rv_port0__read__98_BI_ETC___d505;
  tUWide DEF__1_CONCAT_mainMem_dl_d_11_rv_port0__read__90_BI_ETC___d497;
  tUWide DEF__1_CONCAT_mainMem_dl_d_12_rv_port0__read__82_BI_ETC___d489;
  tUWide DEF__1_CONCAT_mainMem_dl_d_13_rv_port0__read__74_BI_ETC___d481;
  tUWide DEF__1_CONCAT_mainMem_dl_d_14_rv_port0__read__66_BI_ETC___d473;
  tUWide DEF__1_CONCAT_mainMem_dl_d_15_rv_port0__read__58_BI_ETC___d465;
  tUWide DEF__1_CONCAT_mainMem_dl_d_16_rv_port0__read__50_BI_ETC___d457;
  tUWide DEF__1_CONCAT_mainMem_dl_d_17_rv_port0__read__42_BI_ETC___d449;
  tUWide DEF__1_CONCAT_mainMem_dl_d_18_rv_port0__read__34_BI_ETC___d441;
  tUWide DEF__1_CONCAT_mainMem_dl_d_19_rv_port0__read__26_BI_ETC___d433;
  tUWide DEF__1_CONCAT_mainMem_dl_d_20_rv_port0__read__18_BI_ETC___d425;
  tUWide DEF__1_CONCAT_mainMem_dl_d_21_rv_port0__read__10_BI_ETC___d417;
  tUWide DEF__1_CONCAT_mainMem_dl_d_22_rv_port0__read__02_BI_ETC___d409;
  tUWide DEF__1_CONCAT_mainMem_dl_d_23_rv_port0__read__94_BI_ETC___d401;
  tUWide DEF__1_CONCAT_mainMem_dl_d_24_rv_port0__read__86_BI_ETC___d393;
  tUWide DEF__1_CONCAT_mainMem_dl_d_25_rv_port0__read__78_BI_ETC___d385;
  tUWide DEF__1_CONCAT_mainMem_dl_d_26_rv_port0__read__70_BI_ETC___d377;
  tUWide DEF__1_CONCAT_mainMem_dl_d_27_rv_port0__read__62_BI_ETC___d369;
  tUWide DEF__1_CONCAT_mainMem_dl_d_28_rv_port0__read__54_BI_ETC___d361;
  tUWide DEF__1_CONCAT_mainMem_dl_d_29_rv_port0__read__46_BI_ETC___d353;
  tUWide DEF__1_CONCAT_mainMem_dl_d_30_rv_port0__read__38_BI_ETC___d345;
  tUWide DEF__1_CONCAT_mainMem_dl_d_31_rv_port0__read__30_BI_ETC___d337;
  tUWide DEF__1_CONCAT_mainMem_dl_d_32_rv_port0__read__22_BI_ETC___d329;
  tUWide DEF__1_CONCAT_mainMem_dl_d_33_rv_port0__read__14_BI_ETC___d321;
  tUWide DEF__1_CONCAT_mainMem_dl_d_34_rv_port0__read__06_BI_ETC___d313;
  tUWide DEF__1_CONCAT_mainMem_dl_d_35_rv_port0__read__98_BI_ETC___d305;
  tUWide DEF__1_CONCAT_mainMem_dl_d_36_rv_port0__read__90_BI_ETC___d297;
  tUWide DEF__1_CONCAT_mainMem_dl_d_38_rv_port0__read__73_BI_ETC___d281;
  tUWide DEF__1_CONCAT_mainMem_dl_d_37_rv_port0__read__82_BI_ETC___d289;
  tUWide DEF__0_CONCAT_DONTCARE___d279;
  tUWide DEF_IF_cache_working_47_BITS_3_TO_0_61_EQ_15_00_TH_ETC___d935;
  tUWide DEF_IF_cache_stb_first__54_BITS_37_TO_34_80_EQ_15__ETC___d829;
  tUWide DEF_cache_memRespQ_first__69_BITS_31_TO_0_70_CONCA_ETC___d890;
  tUWide DEF_cache_working_line_69_BITS_127_TO_96_24_CONCAT_ETC___d852;
  tUWide DEF_IF_cache_working_47_BITS_3_TO_0_61_EQ_15_00_TH_ETC___d930;
  tUWide DEF_IF_cache_stb_first__54_BITS_37_TO_34_80_EQ_15__ETC___d822;
  tUWide DEF_cache_memRespQ_first__69_BITS_31_TO_0_70_CONCA_ETC___d887;
  tUWide DEF_cache_working_line_69_BITS_255_TO_224_10_CONCA_ETC___d851;
  tUWide DEF_IF_cache_working_47_BITS_3_TO_0_61_EQ_15_00_TH_ETC___d925;
  tUWide DEF_IF_cache_stb_first__54_BITS_37_TO_34_80_EQ_15__ETC___d815;
  tUWide DEF_cache_memRespQ_first__69_BITS_31_TO_0_70_CONCA_ETC___d884;
  tUWide DEF_IF_cache_working_47_BITS_3_TO_0_61_EQ_15_00_TH_ETC___d920;
  tUWide DEF_IF_cache_stb_first__54_BITS_37_TO_34_80_EQ_15__ETC___d808;
  tUWide DEF_cache_memRespQ_first__69_BITS_31_TO_0_70_CONCA_ETC___d881;
  tUWide DEF_cache_working_line_69_BITS_383_TO_352_96_CONCA_ETC___d850;
  tUWide DEF_IF_cache_working_47_BITS_3_TO_0_61_EQ_15_00_TH_ETC___d915;
  tUWide DEF_IF_cache_stb_first__54_BITS_37_TO_34_80_EQ_15__ETC___d801;
  tUWide DEF_cache_memRespQ_first__69_BITS_31_TO_0_70_CONCA_ETC___d878;
  tUWide DEF_IF_cache_working_47_BITS_3_TO_0_61_EQ_15_00_TH_ETC___d910;
  tUWide DEF_IF_cache_stb_first__54_BITS_37_TO_34_80_EQ_15__ETC___d794;
  tUWide DEF_cache_memRespQ_first__69_BITS_31_TO_0_70_CONCA_ETC___d875;
  tUWide DEF__0_CONCAT_IF_randomMem_zaz_whas_THEN_randomMem__ETC___d1145;
  tUWide DEF_IF_randomMem_zaz_whas_THEN_randomMem_zaz_wget__ETC___d1144;
  tUWide DEF_new_value__h400;
  tUInt64 DEF__0_CONCAT_DONTCARE___d68;
 
 /* Rules */
 public:
  void RL_randomMem_every();
  void RL_randomMem_every_1();
  void RL_mainRef_bram_serverAdapter_outData_enqueue();
  void RL_mainRef_bram_serverAdapter_outData_dequeue();
  void RL_mainRef_bram_serverAdapter_cnt_finalAdd();
  void RL_mainRef_bram_serverAdapter_s1__dreg_update();
  void RL_mainRef_bram_serverAdapter_stageReadResponseAlways();
  void RL_mainRef_bram_serverAdapter_moveToOutFIFO();
  void RL_mainRef_bram_serverAdapter_overRun();
  void RL_mainRef_dl_try_move();
  void RL_mainRef_dl_try_move_1();
  void RL_mainRef_dl_try_move_2();
  void RL_mainRef_dl_try_move_3();
  void RL_mainRef_dl_try_move_4();
  void RL_mainRef_dl_try_move_5();
  void RL_mainRef_dl_try_move_6();
  void RL_mainRef_dl_try_move_7();
  void RL_mainRef_dl_try_move_8();
  void RL_mainRef_dl_try_move_9();
  void RL_mainRef_dl_try_move_10();
  void RL_mainRef_dl_try_move_11();
  void RL_mainRef_dl_try_move_12();
  void RL_mainRef_dl_try_move_13();
  void RL_mainRef_dl_try_move_14();
  void RL_mainRef_dl_try_move_15();
  void RL_mainRef_dl_try_move_16();
  void RL_mainRef_dl_try_move_17();
  void RL_mainRef_dl_try_move_18();
  void RL_mainRef_deq();
  void RL_mainMem_bram_serverAdapter_outData_enqueue();
  void RL_mainMem_bram_serverAdapter_outData_dequeue();
  void RL_mainMem_bram_serverAdapter_cnt_finalAdd();
  void RL_mainMem_bram_serverAdapter_s1__dreg_update();
  void RL_mainMem_bram_serverAdapter_stageReadResponseAlways();
  void RL_mainMem_bram_serverAdapter_moveToOutFIFO();
  void RL_mainMem_bram_serverAdapter_overRun();
  void RL_mainMem_dl_try_move();
  void RL_mainMem_dl_try_move_1();
  void RL_mainMem_dl_try_move_2();
  void RL_mainMem_dl_try_move_3();
  void RL_mainMem_dl_try_move_4();
  void RL_mainMem_dl_try_move_5();
  void RL_mainMem_dl_try_move_6();
  void RL_mainMem_dl_try_move_7();
  void RL_mainMem_dl_try_move_8();
  void RL_mainMem_dl_try_move_9();
  void RL_mainMem_dl_try_move_10();
  void RL_mainMem_dl_try_move_11();
  void RL_mainMem_dl_try_move_12();
  void RL_mainMem_dl_try_move_13();
  void RL_mainMem_dl_try_move_14();
  void RL_mainMem_dl_try_move_15();
  void RL_mainMem_dl_try_move_16();
  void RL_mainMem_dl_try_move_17();
  void RL_mainMem_dl_try_move_18();
  void RL_mainMem_dl_try_move_19();
  void RL_mainMem_dl_try_move_20();
  void RL_mainMem_dl_try_move_21();
  void RL_mainMem_dl_try_move_22();
  void RL_mainMem_dl_try_move_23();
  void RL_mainMem_dl_try_move_24();
  void RL_mainMem_dl_try_move_25();
  void RL_mainMem_dl_try_move_26();
  void RL_mainMem_dl_try_move_27();
  void RL_mainMem_dl_try_move_28();
  void RL_mainMem_dl_try_move_29();
  void RL_mainMem_dl_try_move_30();
  void RL_mainMem_dl_try_move_31();
  void RL_mainMem_dl_try_move_32();
  void RL_mainMem_dl_try_move_33();
  void RL_mainMem_dl_try_move_34();
  void RL_mainMem_dl_try_move_35();
  void RL_mainMem_dl_try_move_36();
  void RL_mainMem_dl_try_move_37();
  void RL_mainMem_dl_try_move_38();
  void RL_mainMem_deq();
  void RL_cache_bram_serverAdapter_outData_enqueue();
  void RL_cache_bram_serverAdapter_outData_dequeue();
  void RL_cache_bram_serverAdapter_cnt_finalAdd();
  void RL_cache_bram_serverAdapter_s1__dreg_update();
  void RL_cache_bram_serverAdapter_stageReadResponseAlways();
  void RL_cache_bram_serverAdapter_moveToOutFIFO();
  void RL_cache_bram_serverAdapter_overRun();
  void RL_cache_count();
  void RL_cache_req_process();
  void RL_cache_mvStbToL1();
  void RL_cache_startMiss();
  void RL_cache_sendFillReq();
  void RL_cache_waitFillResp_Ld();
  void RL_cache_waitFillResp_St();
  void RL_cache2_bram_serverAdapter_outData_enqueue();
  void RL_cache2_bram_serverAdapter_outData_dequeue();
  void RL_cache2_bram_serverAdapter_cnt_finalAdd();
  void RL_cache2_bram_serverAdapter_s1__dreg_update();
  void RL_cache2_bram_serverAdapter_stageReadResponseAlways();
  void RL_cache2_bram_serverAdapter_moveToOutFIFO();
  void RL_cache2_bram_serverAdapter_overRun();
  void RL_cache2_count();
  void RL_cache2_req_process();
  void RL_cache2_mvStbToL1();
  void RL_cache2_startMiss();
  void RL_cache2_sendFillReq();
  void RL_cache2_waitFillResp_Ld();
  void RL_cache2_waitFillResp_St();
  void RL_connectCacheL1L2();
  void RL_connectL2L1Cache();
  void RL_connectCacheDram();
  void RL_connectDramCache();
  void RL_start();
  void RL_reqs();
  void RL_resps();
  void RL_deadlockerC();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkBeveren_nested &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkBeveren_nested &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkBeveren_nested &backing);
};

#endif /* ifndef __mkBeveren_nested_h__ */
