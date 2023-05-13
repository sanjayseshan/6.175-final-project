/*
 * Generated by Bluespec Compiler, version 2023.01-6-g034050db (build 034050db)
 * 
 * On Sat May 13 00:02:49 EDT 2023
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
  MOD_BRAM<tUInt8,tUInt32,tUInt8> INST_cache_bram1_memory;
  MOD_Reg<tUInt8> INST_cache_bram1_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_cache_bram1_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_cache_bram1_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_cache_bram1_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_cache_bram1_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_cache_bram1_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_cache_bram1_serverAdapter_outData_dequeueing;
  MOD_Wire<tUInt32> INST_cache_bram1_serverAdapter_outData_enqw;
  MOD_Fifo<tUInt32> INST_cache_bram1_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_cache_bram1_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_cache_bram1_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_cache_bram1_serverAdapter_writeWithResp;
  MOD_BRAM<tUInt8,tUWide,tUInt64> INST_cache_bram2_memory;
  MOD_Reg<tUInt8> INST_cache_bram2_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_cache_bram2_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_cache_bram2_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_cache_bram2_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_cache_bram2_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_cache_bram2_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_cache_bram2_serverAdapter_outData_dequeueing;
  MOD_Wire<tUWide> INST_cache_bram2_serverAdapter_outData_enqw;
  MOD_Fifo<tUWide> INST_cache_bram2_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_cache_bram2_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_cache_bram2_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_cache_bram2_serverAdapter_writeWithResp;
  MOD_Fifo<tUInt32> INST_cache_hitQ;
  MOD_Reg<tUInt8> INST_cache_is_downgrade;
  MOD_Reg<tUInt8> INST_cache_lockL1;
  MOD_Fifo<tUWide> INST_cache_memReqQ;
  MOD_Fifo<tUWide> INST_cache_memRespQ;
  MOD_Reg<tUInt8> INST_cache_mshr;
  MOD_Reg<tUInt8> INST_cache_start_fill;
  MOD_Fifo<tUWide> INST_cache_stb;
  MOD_Fifo<tUWide> INST_cache_upgrades;
  MOD_Reg<tUWide> INST_cache_working;
  MOD_Reg<tUWide> INST_cache_working_data;
  MOD_Reg<tUInt32> INST_cache_working_line;
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
  MOD_CReg<tUWide> INST_mainMem_dl_d_2_rv;
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
  tUInt8 DEF_cache2_stb_first__60_BITS_537_TO_512_61_EQ_cac_ETC___d963;
  tUInt8 DEF_NOT_IF_cache2_bram_serverAdapter_outData_ff_i__ETC___d980;
  tUInt8 DEF_cache2_stb_notEmpty____d956;
  tUInt8 DEF_NOT_cache2_stb_notEmpty__56___d957;
  tUInt8 DEF_cache2_stb_notEmpty__56_AND_cache2_stb_first___ETC___d964;
  tUInt8 DEF_x__h54048;
  tUInt8 DEF__read_memReq_word_byte__h34225;
  tUInt8 DEF_NOT_cache_working_55_BITS_67_TO_49_74_EQ_IF_ca_ETC___d477;
  tUWide DEF_cache2_working___d953;
  tUWide DEF_cache2_stb_first____d960;
  tUWide DEF_cache2_working_line___d1013;
  tUWide DEF_cache2_bram_serverAdapter_outData_enqw_wget____d909;
  tUWide DEF_cache2_bram_serverAdapter_outData_ff_first____d967;
  tUWide DEF_mainMem_dl_d_19_rv_port0__read____d1063;
  tUWide DEF_mainMem_dl_d_0_rv_port1__read____d348;
  tUWide DEF_cache_working___d455;
  tUWide DEF_cache_stb_first____d655;
  tUWide DEF_x_wget__h217;
  tUInt64 DEF_mainRef_dl_d_9_rv_port0__read____d1099;
  tUInt32 DEF_x__h55705;
  tUInt32 DEF_cache_working_line___d657;
  tUInt32 DEF_cache_bram1_serverAdapter_outData_enqw_wget____d361;
  tUInt32 DEF_cache_bram1_serverAdapter_outData_ff_first____d458;
  tUInt8 DEF_b__h52433;
  tUInt8 DEF_b__h24705;
  tUInt8 DEF_b__h19518;
  tUInt8 DEF_b__h7898;
  tUInt8 DEF_b__h1350;
  tUInt8 DEF_cache2_bram_serverAdapter_s1___d935;
  tUInt8 DEF_x__h47801;
  tUInt8 DEF_cache_bram2_serverAdapter_s1___d435;
  tUInt8 DEF_cache_bram1_serverAdapter_s1___d387;
  tUInt8 DEF_mainMem_bram_serverAdapter_s1___d177;
  tUInt8 DEF_mainRef_bram_serverAdapter_s1___d46;
  tUInt8 DEF_cache2_memRespQ_notEmpty____d1038;
  tUInt8 DEF_cache2_bram_serverAdapter_cnt_3_whas____d914;
  tUInt8 DEF_cache2_bram_serverAdapter_cnt_2_whas____d912;
  tUInt8 DEF_cache2_bram_serverAdapter_cnt_1_whas____d911;
  tUInt8 DEF_cache2_bram_serverAdapter_outData_ff_i_notEmpty____d906;
  tUInt8 DEF_cache_memRespQ_notEmpty____d714;
  tUInt8 DEF_cache_bram2_serverAdapter_cnt_3_whas____d414;
  tUInt8 DEF_cache_bram2_serverAdapter_cnt_2_whas____d412;
  tUInt8 DEF_cache_bram2_serverAdapter_cnt_1_whas____d411;
  tUInt8 DEF_cache_bram2_serverAdapter_outData_ff_i_notEmpty____d406;
  tUInt8 DEF_cache_bram1_serverAdapter_cnt_3_whas____d366;
  tUInt8 DEF_cache_bram1_serverAdapter_cnt_2_whas____d364;
  tUInt8 DEF_cache_bram1_serverAdapter_cnt_1_whas____d363;
  tUInt8 DEF_cache_bram1_serverAdapter_outData_ff_i_notEmpty____d358;
  tUInt8 DEF_mainMem_bram_serverAdapter_cnt_3_whas____d156;
  tUInt8 DEF_mainMem_bram_serverAdapter_cnt_2_whas____d154;
  tUInt8 DEF_mainMem_bram_serverAdapter_cnt_1_whas____d153;
  tUInt8 DEF_mainMem_bram_serverAdapter_outData_ff_i_notEmpty____d147;
  tUInt8 DEF_mainRef_bram_serverAdapter_cnt_3_whas____d24;
  tUInt8 DEF_mainRef_bram_serverAdapter_cnt_2_whas____d22;
  tUInt8 DEF_mainRef_bram_serverAdapter_cnt_1_whas____d21;
  tUInt8 DEF_mainRef_bram_serverAdapter_outData_ff_i_notEmpty____d15;
  tUWide DEF_v__h432;
  tUInt32 DEF__read_memReq_addr__h54005;
  tUInt32 DEF_value__h34278;
  tUInt32 DEF_value__h34326;
  tUInt32 DEF_din_datain_tag__h41010;
  tUInt32 DEF__read_tag__h38884;
  tUInt32 DEF_x_first_tag__h30149;
  tUInt32 DEF_x_wget_tag__h19076;
  tUInt32 DEF_y__h54044;
  tUInt32 DEF_x__h54229;
  tUInt32 DEF__read_tag__h54258;
  tUInt32 DEF_x_first_tag__h53884;
  tUInt32 DEF_x_wget_tag__h51965;
  tUInt8 DEF_newreq_word_byte__h55652;
  tUInt8 DEF_x__h54501;
  tUInt8 DEF_x_first_valid__h53883;
  tUInt8 DEF_x_wget_valid__h51964;
  tUInt8 DEF_x__h41220;
  tUInt8 DEF_x_first_valid__h30148;
  tUInt8 DEF_x_wget_valid__h19075;
  tUInt8 DEF_cache2_working_53_BIT_538___d954;
  tUInt8 DEF_cache2_bram_serverAdapter_s1_35_BIT_0___d936;
  tUInt8 DEF_cache_bram2_serverAdapter_s1_35_BIT_0___d436;
  tUInt8 DEF_cache_bram1_serverAdapter_s1_87_BIT_0___d388;
  tUInt8 DEF_mainMem_bram_serverAdapter_s1_77_BIT_0___d178;
  tUInt8 DEF_mainRef_bram_serverAdapter_s1_6_BIT_0___d47;
  tUInt32 DEF_value__h34280;
  tUInt32 DEF_x__h54043;
  tUInt8 DEF_value__h34283;
  tUInt8 DEF_cache_working_55_BITS_71_TO_68_56_EQ_0___d457;
  tUInt8 DEF_cache_stb_first__55_BITS_67_TO_49_56_EQ_cache__ETC___d659;
  tUInt8 DEF_cache_working_55_BITS_67_TO_49_74_EQ_IF_cache__ETC___d475;
  tUInt8 DEF_IF_cache_bram1_serverAdapter_outData_ff_i_notE_ETC___d464;
  tUInt8 DEF_cache2_stb_first__60_BITS_537_TO_520_012_EQ_ca_ETC___d1015;
  tUInt8 DEF_IF_cache2_bram_serverAdapter_outData_ff_i_notE_ETC___d973;
  tUInt8 DEF_IF_randomMem_zaz_whas_THEN_randomMem_zaz_wget__ETC___d1074;
  tUInt8 DEF_cache2_working_line_013_BITS_531_TO_530_026_EQ_2___d1027;
  tUInt8 DEF_IF_cache2_bram_serverAdapter_outData_ff_i_notE_ETC___d979;
  tUInt8 DEF_cache_working_line_57_BITS_20_TO_19_00_EQ_2___d701;
  tUInt8 DEF_IF_cache_bram1_serverAdapter_outData_ff_i_notE_ETC___d470;
  tUInt8 DEF_NOT_cache2_stb_first__60_BITS_537_TO_520_012_E_ETC___d1016;
  tUInt8 DEF_NOT_cache_stb_first__55_BITS_67_TO_49_56_EQ_ca_ETC___d660;
  tUInt8 DEF_NOT_IF_cache_bram1_serverAdapter_outData_ff_i__ETC___d471;
  tUInt8 DEF_NOT_cache2_working_53_BIT_538_54___d996;
  tUInt8 DEF_NOT_cache_working_55_BITS_71_TO_68_56_EQ_0_57___d500;
 
 /* Local definitions */
 private:
  tUInt8 DEF__read_offset__h34221;
  tUInt32 DEF_v__h357;
  tUInt32 DEF_v__h319;
  tUInt32 DEF_v__h282;
  tUWide DEF_cache_memReqQ_first____d1058;
  tUWide DEF_cache2_bram_memory_read____d942;
  tUWide DEF_mainMem_dl_d_19_rv_port1__read____d195;
  tUWide DEF_mainMem_dl_d_18_rv_port1__read____d204;
  tUWide DEF_mainMem_dl_d_18_rv_port0__read____d193;
  tUWide DEF_mainMem_dl_d_17_rv_port1__read____d212;
  tUWide DEF_mainMem_dl_d_17_rv_port0__read____d202;
  tUWide DEF_mainMem_dl_d_16_rv_port1__read____d220;
  tUWide DEF_mainMem_dl_d_16_rv_port0__read____d210;
  tUWide DEF_mainMem_dl_d_15_rv_port1__read____d228;
  tUWide DEF_mainMem_dl_d_15_rv_port0__read____d218;
  tUWide DEF_mainMem_dl_d_14_rv_port1__read____d236;
  tUWide DEF_mainMem_dl_d_14_rv_port0__read____d226;
  tUWide DEF_mainMem_dl_d_13_rv_port1__read____d244;
  tUWide DEF_mainMem_dl_d_13_rv_port0__read____d234;
  tUWide DEF_mainMem_dl_d_12_rv_port1__read____d252;
  tUWide DEF_mainMem_dl_d_12_rv_port0__read____d242;
  tUWide DEF_mainMem_dl_d_11_rv_port1__read____d260;
  tUWide DEF_mainMem_dl_d_11_rv_port0__read____d250;
  tUWide DEF_mainMem_dl_d_10_rv_port1__read____d268;
  tUWide DEF_mainMem_dl_d_10_rv_port0__read____d258;
  tUWide DEF_mainMem_dl_d_9_rv_port1__read____d276;
  tUWide DEF_mainMem_dl_d_9_rv_port0__read____d266;
  tUWide DEF_mainMem_dl_d_8_rv_port1__read____d284;
  tUWide DEF_mainMem_dl_d_8_rv_port0__read____d274;
  tUWide DEF_mainMem_dl_d_7_rv_port1__read____d292;
  tUWide DEF_mainMem_dl_d_7_rv_port0__read____d282;
  tUWide DEF_mainMem_dl_d_6_rv_port1__read____d300;
  tUWide DEF_mainMem_dl_d_6_rv_port0__read____d290;
  tUWide DEF_mainMem_dl_d_5_rv_port1__read____d308;
  tUWide DEF_mainMem_dl_d_5_rv_port0__read____d298;
  tUWide DEF_mainMem_dl_d_4_rv_port1__read____d316;
  tUWide DEF_mainMem_dl_d_4_rv_port0__read____d306;
  tUWide DEF_mainMem_dl_d_3_rv_port1__read____d324;
  tUWide DEF_mainMem_dl_d_3_rv_port0__read____d314;
  tUWide DEF_mainMem_dl_d_2_rv_port1__read____d332;
  tUWide DEF_mainMem_dl_d_2_rv_port0__read____d322;
  tUWide DEF_mainMem_dl_d_1_rv_port1__read____d340;
  tUWide DEF_mainMem_dl_d_1_rv_port0__read____d330;
  tUWide DEF_mainMem_dl_d_0_rv_port0__read____d338;
  tUWide DEF_data__h54659;
  tUWide DEF_cache_memRespQ_first____d727;
  tUWide DEF_cache_working_data__h43231;
  tUWide DEF_cache_bram2_serverAdapter_outData_enqw_wget____d409;
  tUWide DEF_cache_bram2_serverAdapter_outData_ff_first____d494;
  tUWide DEF_cache_bram2_memory_read____d442;
  tUWide DEF_x_wget__h7405;
  tUWide DEF_x_first__h7290;
  tUWide DEF_v__h8468;
  tUInt32 DEF_x_wget__h857;
  tUInt8 DEF_cache_is_downgrade__h34287;
  tUWide DEF_cache2_working_53_BITS_538_TO_0___d1011;
  tUWide DEF_cache2_working_53_BITS_537_TO_0___d995;
  tUWide DEF_din_datain_data__h54877;
  tUWide DEF_cache_memReqQ_first__058_BITS_511_TO_0___d1061;
  tUWide DEF_x__h54083;
  tUWide DEF_x_data__h54538;
  tUWide DEF_x_first_data__h53885;
  tUWide DEF_x_wget_data__h51966;
  tUWide DEF_x__h55421;
  tUWide DEF_x__h18339;
  tUWide DEF_x__h18081;
  tUWide DEF_x__h17823;
  tUWide DEF_x__h17565;
  tUWide DEF_x__h17307;
  tUWide DEF_x__h17049;
  tUWide DEF_x__h16791;
  tUWide DEF_x__h16533;
  tUWide DEF_x__h16275;
  tUWide DEF_x__h16017;
  tUWide DEF_x__h15759;
  tUWide DEF_x__h15501;
  tUWide DEF_x__h15243;
  tUWide DEF_x__h14985;
  tUWide DEF_x__h14727;
  tUWide DEF_x__h14469;
  tUWide DEF_x__h14211;
  tUWide DEF_x__h13953;
  tUWide DEF_x__h13695;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_511_TO_480___d743;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_479_TO_448___d742;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_447_TO_416___d741;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_415_TO_384___d740;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_383_TO_352___d739;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_351_TO_320___d738;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_319_TO_288___d737;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_287_TO_256___d736;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_255_TO_224___d735;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_223_TO_192___d734;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_191_TO_160___d733;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_159_TO_128___d732;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_127_TO_96___d731;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_95_TO_64___d730;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_63_TO_32___d729;
  tUInt32 DEF_cache_memRespQ_first__27_BITS_31_TO_0___d728;
  tUInt32 DEF_n__h37244;
  tUInt32 DEF_x__h46973;
  tUInt8 DEF__read_idx__h53999;
  tUInt8 DEF__read_idx__h34219;
  tUWide DEF_IF_cache2_bram_serverAdapter_outData_ff_i_notE_ETC___d994;
  tUWide DEF_IF_cache2_bram_serverAdapter_outData_enqw_whas_ETC___d993;
  tUWide DEF_v__h55288;
  tUWide DEF_IF_cache2_stb_notEmpty__56_AND_cache2_stb_firs_ETC___d1006;
  tUWide DEF_x__h54098;
  tUWide DEF_IF_cache2_bram_serverAdapter_outData_enqw_whas_ETC___d1004;
  tUWide DEF_IF_cache_working_55_BIT_71_50_THEN_IF_cache_wo_ETC___d902;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d858;
  tUWide DEF_IF_cache_working_55_BIT_70_52_THEN_IF_cache_wo_ETC___d901;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d882;
  tUWide DEF_IF_cache_working_55_BIT_69_53_THEN_IF_cache_wo_ETC___d900;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d890;
  tUWide DEF_IF_cache_working_55_BIT_68_54_THEN_IF_cache_wo_ETC___d899;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d898;
  tUWide DEF_IF_cache_bram2_serverAdapter_outData_ff_i_notE_ETC___d496;
  tUWide DEF_IF_cache_bram2_serverAdapter_outData_enqw_whas_ETC___d495;
  tUWide DEF_v__h18377;
  tUWide DEF_x__h7503;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_0___d621;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_1___d619;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_2___d616;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_3___d614;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_4___d611;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_5___d609;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_6___d606;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_7___d604;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_8___d601;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_9___d599;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_10___d596;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_11___d594;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_12___d591;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_13___d589;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_15___d584;
  tUInt8 DEF_cache_working_55_BITS_3_TO_0_13_EQ_14___d586;
  tUInt32 DEF_x__h955;
  tUInt8 DEF__0_CONCAT_DONTCARE___d37;
  tUInt8 DEF_NOT_cache_is_downgrade_02___d507;
  tUWide DEF__1_CONCAT_cache2_stb_first__60___d1025;
  tUWide DEF__1_CONCAT_cache_working_line_57_BITS_18_TO_0_58_ETC___d709;
  tUWide DEF__1_CONCAT_cache2_working_line_013_BITS_529_TO_5_ETC___d1035;
  tUWide DEF__0_CONCAT_cache_working_55_BITS_97_TO_72_12_CON_ETC___d713;
  tUWide DEF__2_CONCAT_cache2_stb_first__60_BITS_537_TO_520__ETC___d1024;
  tUWide DEF__1_CONCAT_cache2_working_53_BITS_564_TO_547_72__ETC___d1050;
  tUWide DEF__1_CONCAT_cache2_working_53_BITS_564_TO_547_72__ETC___d1054;
  tUWide DEF__1_CONCAT_IF_mainMem_bram_serverAdapter_outData_ETC___d354;
  tUWide DEF__1_CONCAT_mainMem_dl_d_0_rv_port0__read__38_BIT_ETC___d345;
  tUWide DEF__1_CONCAT_mainMem_dl_d_1_rv_port0__read__30_BIT_ETC___d337;
  tUWide DEF__1_CONCAT_mainMem_dl_d_2_rv_port0__read__22_BIT_ETC___d329;
  tUWide DEF__1_CONCAT_mainMem_dl_d_3_rv_port0__read__14_BIT_ETC___d321;
  tUWide DEF__1_CONCAT_mainMem_dl_d_4_rv_port0__read__06_BIT_ETC___d313;
  tUWide DEF__1_CONCAT_mainMem_dl_d_5_rv_port0__read__98_BIT_ETC___d305;
  tUWide DEF__1_CONCAT_mainMem_dl_d_6_rv_port0__read__90_BIT_ETC___d297;
  tUWide DEF__1_CONCAT_mainMem_dl_d_7_rv_port0__read__82_BIT_ETC___d289;
  tUWide DEF__1_CONCAT_mainMem_dl_d_8_rv_port0__read__74_BIT_ETC___d281;
  tUWide DEF__1_CONCAT_mainMem_dl_d_9_rv_port0__read__66_BIT_ETC___d273;
  tUWide DEF__1_CONCAT_mainMem_dl_d_10_rv_port0__read__58_BI_ETC___d265;
  tUWide DEF__1_CONCAT_mainMem_dl_d_11_rv_port0__read__50_BI_ETC___d257;
  tUWide DEF__1_CONCAT_mainMem_dl_d_12_rv_port0__read__42_BI_ETC___d249;
  tUWide DEF__1_CONCAT_mainMem_dl_d_13_rv_port0__read__34_BI_ETC___d241;
  tUWide DEF__1_CONCAT_mainMem_dl_d_14_rv_port0__read__26_BI_ETC___d233;
  tUWide DEF__1_CONCAT_mainMem_dl_d_15_rv_port0__read__18_BI_ETC___d225;
  tUWide DEF__1_CONCAT_mainMem_dl_d_16_rv_port0__read__10_BI_ETC___d217;
  tUWide DEF__1_CONCAT_mainMem_dl_d_18_rv_port0__read__93_BI_ETC___d201;
  tUWide DEF__1_CONCAT_mainMem_dl_d_17_rv_port0__read__02_BI_ETC___d209;
  tUWide DEF__0_CONCAT_DONTCARE___d199;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d897;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d889;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d879;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d847;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d649;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d646;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d694;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d691;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d896;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d888;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d876;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d836;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d643;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d688;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d895;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d887;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d873;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d825;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d640;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d685;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d894;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d886;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d870;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d814;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d637;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d682;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d893;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d885;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d867;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d803;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d634;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d679;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d892;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d884;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d864;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d792;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d631;
  tUWide DEF_IF_cache_working_55_BITS_3_TO_0_13_EQ_15_84_TH_ETC___d676;
  tUWide DEF__0_CONCAT_IF_randomMem_zaz_whas_THEN_randomMem__ETC___d1098;
  tUWide DEF_IF_randomMem_zaz_whas_THEN_randomMem_zaz_wget__ETC___d1097;
  tUWide DEF_IF_randomMem_zaz_whas_THEN_randomMem_zaz_wget__ETC___d1092;
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
  void RL_mainMem_deq();
  void RL_cache_bram1_serverAdapter_outData_enqueue();
  void RL_cache_bram1_serverAdapter_outData_dequeue();
  void RL_cache_bram1_serverAdapter_cnt_finalAdd();
  void RL_cache_bram1_serverAdapter_s1__dreg_update();
  void RL_cache_bram1_serverAdapter_stageReadResponseAlways();
  void RL_cache_bram1_serverAdapter_moveToOutFIFO();
  void RL_cache_bram1_serverAdapter_overRun();
  void RL_cache_bram2_serverAdapter_outData_enqueue();
  void RL_cache_bram2_serverAdapter_outData_dequeue();
  void RL_cache_bram2_serverAdapter_cnt_finalAdd();
  void RL_cache_bram2_serverAdapter_s1__dreg_update();
  void RL_cache_bram2_serverAdapter_stageReadResponseAlways();
  void RL_cache_bram2_serverAdapter_moveToOutFIFO();
  void RL_cache_bram2_serverAdapter_overRun();
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
  void RL_cache2_req_process();
  void RL_cache2_mvStbToL1();
  void RL_cache2_startMiss();
  void RL_cache2_sendFillReq();
  void RL_cache2_waitFillResp_Ld();
  void RL_cache2_waitFillResp_St();
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
