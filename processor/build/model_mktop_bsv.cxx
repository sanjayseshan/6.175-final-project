/*
 * Generated by Bluespec Compiler, version 2023.01-6-g034050db (build 034050db)
 * 
 * On Sun Apr 30 20:54:18 EDT 2023
 * 
 */
#include "bluesim_primitives.h"
#include "model_mktop_bsv.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mktop_bsv::MODEL_mktop_bsv()
{
  mktop_bsv_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mktop_bsv()
{
  MODEL_mktop_bsv *model = new MODEL_mktop_bsv();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mktop_bsv &INST_top = *((MOD_mktop_bsv *)(instance_ptr));
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_NOT_starting___d9;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_NOT_toMMIO_rv_port0__read__46_BIT_68_47___d348;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_IF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dI_ETC___d352;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BIT_0_98_THEN_fromMMIO_rv_p_ETC___d503;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BITS_5_TO_3_90_EQ_0b0_91_OR_ETC___d507;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_state__h4472;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_do_tic_logging;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_do_tic_logging;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_fetch;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_fetch;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_decode;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_decode;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_execute;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_execute;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_writeback;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_writeback;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_administrative_konata_commit;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_administrative_konata_commit;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_administrative_konata_flush;
	 tUInt8 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_administrative_konata_flush;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterA_s1_5_BIT_1___d40;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterB_s1_4_BIT_1___d89;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterA_outData_ff_i_notFull____d38;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterA_outData_beforeDeq_read____d45;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterA_outData_enqw_whas____d1;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterA_outData_dequeueing_whas____d2;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterB_outData_ff_i_notFull____d87;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterB_outData_beforeDeq_read____d94;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterB_outData_enqw_whas____d51;
	 tUInt8 DEF_INST_top_DEF_bram_serverAdapterB_outData_dequeueing_whas____d52;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_outData_enqueue;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_outData_enqueue;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_outData_dequeue;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_outData_dequeue;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_cnt_finalAdd;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_cnt_finalAdd;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_s1__dreg_update;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_s1__dreg_update;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_stageReadResponseAlways;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_stageReadResponseAlways;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_moveToOutFIFO;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_moveToOutFIFO;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_overRun;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_overRun;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_outData_enqueue;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_outData_enqueue;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_outData_dequeue;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_outData_dequeue;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_cnt_finalAdd;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_cnt_finalAdd;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_s1__dreg_update;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_s1__dreg_update;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_stageReadResponseAlways;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_stageReadResponseAlways;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_moveToOutFIFO;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_moveToOutFIFO;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_overRun;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_overRun;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_tic;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_tic;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_requestI;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_requestI;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_responseI;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_responseI;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_requestD;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_requestD;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_responseD;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_responseD;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_requestMMIO;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_requestMMIO;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_responseMMIO;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_responseMMIO;
	 INST_top.DEF_bram_serverAdapterA_s1___d35 = INST_top.INST_bram_serverAdapterA_s1.METH_read();
	 DEF_INST_top_DEF_bram_serverAdapterA_outData_ff_i_notFull____d38 = INST_top.INST_bram_serverAdapterA_outData_ff.METH_i_notFull();
	 DEF_INST_top_DEF_bram_serverAdapterA_s1_5_BIT_1___d40 = (tUInt8)((INST_top.DEF_bram_serverAdapterA_s1___d35) >> 1u);
	 INST_top.DEF_bram_serverAdapterA_s1_5_BIT_0___d36 = (tUInt8)((tUInt8)1u & (INST_top.DEF_bram_serverAdapterA_s1___d35));
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_moveToOutFIFO = (!(INST_top.DEF_bram_serverAdapterA_s1_5_BIT_0___d36) || DEF_INST_top_DEF_bram_serverAdapterA_outData_ff_i_notFull____d38) && DEF_INST_top_DEF_bram_serverAdapterA_s1_5_BIT_1___d40;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_moveToOutFIFO = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_moveToOutFIFO;
	 DEF_INST_top_DEF_bram_serverAdapterA_outData_beforeDeq_read____d45 = INST_top.INST_bram_serverAdapterA_outData_beforeDeq.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_overRun = DEF_INST_top_DEF_bram_serverAdapterA_s1_5_BIT_1___d40 && ((!INST_top.INST_bram_serverAdapterA_outData_beforeEnq.METH_read() || !DEF_INST_top_DEF_bram_serverAdapterA_outData_beforeDeq_read____d45) || !DEF_INST_top_DEF_bram_serverAdapterA_outData_ff_i_notFull____d38);
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_overRun = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_overRun;
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_s1__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_s1__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_s1__dreg_update;
	 INST_top.DEF_bram_serverAdapterB_s1___d84 = INST_top.INST_bram_serverAdapterB_s1.METH_read();
	 DEF_INST_top_DEF_bram_serverAdapterB_outData_ff_i_notFull____d87 = INST_top.INST_bram_serverAdapterB_outData_ff.METH_i_notFull();
	 DEF_INST_top_DEF_bram_serverAdapterB_s1_4_BIT_1___d89 = (tUInt8)((INST_top.DEF_bram_serverAdapterB_s1___d84) >> 1u);
	 INST_top.DEF_bram_serverAdapterB_s1_4_BIT_0___d85 = (tUInt8)((tUInt8)1u & (INST_top.DEF_bram_serverAdapterB_s1___d84));
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_moveToOutFIFO = (!(INST_top.DEF_bram_serverAdapterB_s1_4_BIT_0___d85) || DEF_INST_top_DEF_bram_serverAdapterB_outData_ff_i_notFull____d87) && DEF_INST_top_DEF_bram_serverAdapterB_s1_4_BIT_1___d89;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_moveToOutFIFO = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_moveToOutFIFO;
	 DEF_INST_top_DEF_bram_serverAdapterB_outData_beforeDeq_read____d94 = INST_top.INST_bram_serverAdapterB_outData_beforeDeq.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_overRun = DEF_INST_top_DEF_bram_serverAdapterB_s1_4_BIT_1___d89 && ((!INST_top.INST_bram_serverAdapterB_outData_beforeEnq.METH_read() || !DEF_INST_top_DEF_bram_serverAdapterB_outData_beforeDeq_read____d94) || !DEF_INST_top_DEF_bram_serverAdapterB_outData_ff_i_notFull____d87);
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_overRun = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_overRun;
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_s1__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_s1__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_s1__dreg_update;
	 DEF_INST_top_DEF_CAN_FIRE_RL_responseMMIO = INST_top.INST_rv_core.METH_RDY_getMMIOResp() && INST_top.INST_mmioreq.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_responseMMIO = DEF_INST_top_DEF_CAN_FIRE_RL_responseMMIO;
	 DEF_INST_top_DEF_CAN_FIRE_RL_tic = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_tic = DEF_INST_top_DEF_CAN_FIRE_RL_tic;
	 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_administrative_konata_commit = INST_top.INST_rv_core.INST_retired.METH_i_notEmpty();
	 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_administrative_konata_commit = DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_administrative_konata_commit;
	 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_administrative_konata_flush = INST_top.INST_rv_core.INST_squashed.METH_i_notEmpty();
	 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_administrative_konata_flush = DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_administrative_konata_flush;
	 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_do_tic_logging = (tUInt8)1u;
	 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_do_tic_logging = DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_do_tic_logging;
	 INST_top.INST_rv_core.DEF_toMMIO_rv_port0__read____d346 = INST_top.INST_rv_core.INST_toMMIO_rv.METH_port0__read();
	 INST_top.INST_rv_core.DEF_toDmem_rv_port0__read____d349 = INST_top.INST_rv_core.INST_toDmem_rv.METH_port0__read();
	 INST_top.INST_rv_core.DEF_dInst___d293 = INST_top.INST_rv_core.INST_dInst.METH_read();
	 INST_top.INST_rv_core.DEF_dInst_93_BIT_6___d294 = (tUInt8)((tUInt8)1u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 6u));
	 INST_top.INST_rv_core.DEF_rs1_val__h10449 = INST_top.INST_rv_core.INST_rv1.METH_read();
	 DEF_INST_top_INST_rv_core_DEF_state__h4472 = INST_top.INST_rv_core.INST_state.METH_read();
	 INST_top.INST_rv_core.DEF_starting__h4015 = INST_top.INST_rv_core.INST_starting.METH_read();
	 INST_top.INST_rv_core.DEF_x__h8705 = (tUInt32)(4095u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 20u));
	 INST_top.INST_rv_core.DEF_dInst_93_BITS_11_TO_7___d310 = (tUInt8)((tUInt8)31u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 7u));
	 INST_top.INST_rv_core.DEF_dInst_93_BITS_34_TO_32___d301 = (tUInt8)((tUInt8)7u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 32u));
	 INST_top.INST_rv_core.DEF_dInst_93_BIT_35___d300 = (tUInt8)((tUInt8)1u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 35u));
	 INST_top.INST_rv_core.DEF_dInst_93_BIT_31___d315 = (tUInt8)((tUInt8)1u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 31u));
	 INST_top.INST_rv_core.DEF_IF_dInst_93_BIT_35_00_THEN_dInst_93_BITS_34_TO_ETC___d302 = INST_top.INST_rv_core.DEF_dInst_93_BITS_34_TO_32___d301;
	 DEF_INST_top_INST_rv_core_DEF_NOT_toMMIO_rv_port0__read__46_BIT_68_47___d348 = !INST_top.INST_rv_core.DEF_toMMIO_rv_port0__read____d346.get_bits_in_word8(2u,
																				   4u,
																				   1u);
	 INST_top.INST_rv_core.DEF_dInst_93_BITS_4_TO_3_95_EQ_0b0___d296 = ((tUInt8)((tUInt8)3u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 3u))) == (tUInt8)0u;
	 INST_top.INST_rv_core.DEF_dInst_93_BIT_6_94_OR_NOT_dInst_93_BITS_4_TO_3__ETC___d298 = INST_top.INST_rv_core.DEF_dInst_93_BIT_6___d294 || !(INST_top.INST_rv_core.DEF_dInst_93_BITS_4_TO_3_95_EQ_0b0___d296);
	 DEF_INST_top_INST_rv_core_DEF_NOT_starting___d9 = !(INST_top.INST_rv_core.DEF_starting__h4015);
	 INST_top.INST_rv_core.DEF_x__h8821 = 8191u & (((((((tUInt32)(INST_top.INST_rv_core.DEF_dInst_93_BIT_31___d315)) << 12u) | (((tUInt32)((tUInt8)((tUInt8)1u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 7u)))) << 11u)) | (((tUInt32)((tUInt8)((tUInt8)63u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 25u)))) << 5u)) | (((tUInt32)((tUInt8)((tUInt8)15u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 8u)))) << 1u)) | (tUInt32)((tUInt8)0u));
	 INST_top.INST_rv_core.DEF_x__h8982 = 2097151u & (((((((tUInt32)(INST_top.INST_rv_core.DEF_dInst_93_BIT_31___d315)) << 20u) | (((tUInt32)((tUInt8)((tUInt8)255u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 12u)))) << 12u)) | (((tUInt32)((tUInt8)((tUInt8)1u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 20u)))) << 11u)) | (((tUInt32)(1023u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 21u))) << 1u)) | (tUInt32)((tUInt8)0u));
	 INST_top.INST_rv_core.DEF_x__h8752 = 4095u & ((((tUInt32)((tUInt8)((tUInt8)127u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 25u)))) << 5u) | (tUInt32)(INST_top.INST_rv_core.DEF_dInst_93_BITS_11_TO_7___d310));
	 INST_top.INST_rv_core.DEF_imm__h8562 = INST_top.INST_rv_core.DEF_dInst_93_BIT_35___d300 && (INST_top.INST_rv_core.DEF_IF_dInst_93_BIT_35_00_THEN_dInst_93_BITS_34_TO_ETC___d302) == (tUInt8)0u ? primSignExt32(32u,
																											12u,
																											(tUInt32)(INST_top.INST_rv_core.DEF_x__h8705)) : (INST_top.INST_rv_core.DEF_dInst_93_BIT_35___d300 && (INST_top.INST_rv_core.DEF_IF_dInst_93_BIT_35_00_THEN_dInst_93_BITS_34_TO_ETC___d302) == (tUInt8)1u ? primSignExt32(32u,
																																																						  12u,
																																																						  (tUInt32)(INST_top.INST_rv_core.DEF_x__h8752)) : (INST_top.INST_rv_core.DEF_dInst_93_BIT_35___d300 && (INST_top.INST_rv_core.DEF_IF_dInst_93_BIT_35_00_THEN_dInst_93_BITS_34_TO_ETC___d302) == (tUInt8)2u ? primSignExt32(32u,
																																																																																	    13u,
																																																																																	    (tUInt32)(INST_top.INST_rv_core.DEF_x__h8821)) : (INST_top.INST_rv_core.DEF_dInst_93_BIT_35___d300 && (INST_top.INST_rv_core.DEF_IF_dInst_93_BIT_35_00_THEN_dInst_93_BITS_34_TO_ETC___d302) == (tUInt8)3u ? ((tUInt32)(1048575u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 12u))) << 12u : (INST_top.INST_rv_core.DEF_dInst_93_BIT_35___d300 && (INST_top.INST_rv_core.DEF_IF_dInst_93_BIT_35_00_THEN_dInst_93_BITS_34_TO_ETC___d302) == (tUInt8)4u ? primSignExt32(32u,
																																																																																																																																										    21u,
																																																																																																																																										    (tUInt32)(INST_top.INST_rv_core.DEF_x__h8982)) : 0u))));
	 INST_top.INST_rv_core.DEF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dInst_ETC___d339 = (INST_top.INST_rv_core.DEF_rs1_val__h10449) + (INST_top.INST_rv_core.DEF_imm__h8562);
	 INST_top.INST_rv_core.DEF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dInst_ETC___d340 = (tUInt32)((INST_top.INST_rv_core.DEF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dInst_ETC___d339) >> 2u);
	 switch (INST_top.INST_rv_core.DEF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dInst_ETC___d340) {
	 case 1006649340u:
	 case 1006649341u:
	 case 1006649342u:
	   DEF_INST_top_INST_rv_core_DEF_IF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dI_ETC___d352 = DEF_INST_top_INST_rv_core_DEF_NOT_toMMIO_rv_port0__read__46_BIT_68_47___d348;
	   break;
	 default:
	   DEF_INST_top_INST_rv_core_DEF_IF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dI_ETC___d352 = !INST_top.INST_rv_core.DEF_toDmem_rv_port0__read____d349.get_bits_in_word8(2u,
																						4u,
																						1u);
	 }
	 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_execute = (INST_top.INST_rv_core.DEF_dInst_93_BIT_6_94_OR_NOT_dInst_93_BITS_4_TO_3__ETC___d298 || DEF_INST_top_INST_rv_core_DEF_IF_rv1_99_PLUS_IF_dInst_93_BIT_35_00_AND_IF_dI_ETC___d352) && (DEF_INST_top_INST_rv_core_DEF_state__h4472 == (tUInt8)2u && DEF_INST_top_INST_rv_core_DEF_NOT_starting___d9);
	 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_execute = DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_execute;
	 INST_top.INST_rv_core.DEF_toImem_rv_port0__read____d4 = INST_top.INST_rv_core.INST_toImem_rv.METH_port0__read();
	 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_fetch = !INST_top.INST_rv_core.DEF_toImem_rv_port0__read____d4.get_bits_in_word8(2u,
																    4u,
																    1u) && (DEF_INST_top_INST_rv_core_DEF_state__h4472 == (tUInt8)0u && DEF_INST_top_INST_rv_core_DEF_NOT_starting___d9);
	 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_fetch = DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_fetch;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_responseMMIO)
	   INST_top.RL_responseMMIO();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_tic)
	   INST_top.RL_tic();
	 if (DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_execute)
	   INST_top.INST_rv_core.RL_execute();
	 INST_top.DEF_b__h910 = INST_top.INST_bram_serverAdapterA_cnt.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_requestD = INST_top.INST_rv_core.METH_RDY_getDReq() && primSLT8(1u,
												      3u,
												      (tUInt8)(INST_top.DEF_b__h910),
												      3u,
												      (tUInt8)3u);
	 DEF_INST_top_DEF_WILL_FIRE_RL_requestD = DEF_INST_top_DEF_CAN_FIRE_RL_requestD;
	 DEF_INST_top_DEF_CAN_FIRE_RL_requestMMIO = INST_top.INST_rv_core.METH_RDY_getMMIOReq() && INST_top.INST_mmioreq.METH_i_notFull();
	 DEF_INST_top_DEF_WILL_FIRE_RL_requestMMIO = DEF_INST_top_DEF_CAN_FIRE_RL_requestMMIO;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_requestMMIO)
	   INST_top.RL_requestMMIO();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_overRun)
	   INST_top.RL_bram_serverAdapterA_overRun();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_moveToOutFIFO)
	   INST_top.RL_bram_serverAdapterA_moveToOutFIFO();
	 DEF_INST_top_DEF_bram_serverAdapterA_outData_enqw_whas____d1 = INST_top.INST_bram_serverAdapterA_outData_enqw.METH_whas();
	 INST_top.DEF_bram_serverAdapterA_outData_ff_i_notEmpty____d4 = INST_top.INST_bram_serverAdapterA_outData_ff.METH_i_notEmpty();
	 DEF_INST_top_DEF_CAN_FIRE_RL_responseD = (DEF_INST_top_DEF_bram_serverAdapterA_outData_beforeDeq_read____d45 && (INST_top.DEF_bram_serverAdapterA_outData_ff_i_notEmpty____d4 || DEF_INST_top_DEF_bram_serverAdapterA_outData_enqw_whas____d1)) && INST_top.INST_rv_core.METH_RDY_getDResp();
	 DEF_INST_top_DEF_WILL_FIRE_RL_responseD = DEF_INST_top_DEF_CAN_FIRE_RL_responseD;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_overRun)
	   INST_top.RL_bram_serverAdapterB_overRun();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_moveToOutFIFO)
	   INST_top.RL_bram_serverAdapterB_moveToOutFIFO();
	 DEF_INST_top_DEF_bram_serverAdapterB_outData_enqw_whas____d51 = INST_top.INST_bram_serverAdapterB_outData_enqw.METH_whas();
	 INST_top.DEF_bram_serverAdapterB_outData_ff_i_notEmpty____d54 = INST_top.INST_bram_serverAdapterB_outData_ff.METH_i_notEmpty();
	 DEF_INST_top_DEF_CAN_FIRE_RL_responseI = (DEF_INST_top_DEF_bram_serverAdapterB_outData_beforeDeq_read____d94 && (INST_top.DEF_bram_serverAdapterB_outData_ff_i_notEmpty____d54 || DEF_INST_top_DEF_bram_serverAdapterB_outData_enqw_whas____d51)) && INST_top.INST_rv_core.METH_RDY_getIResp();
	 DEF_INST_top_DEF_WILL_FIRE_RL_responseI = DEF_INST_top_DEF_CAN_FIRE_RL_responseI;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_responseD)
	   INST_top.RL_responseD();
	 DEF_INST_top_DEF_bram_serverAdapterA_outData_dequeueing_whas____d2 = INST_top.INST_bram_serverAdapterA_outData_dequeueing.METH_whas();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_outData_dequeue = DEF_INST_top_DEF_bram_serverAdapterA_outData_dequeueing_whas____d2 && INST_top.DEF_bram_serverAdapterA_outData_ff_i_notEmpty____d4;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_outData_dequeue = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_outData_dequeue;
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_outData_enqueue = DEF_INST_top_DEF_bram_serverAdapterA_outData_enqw_whas____d1 && (!DEF_INST_top_DEF_bram_serverAdapterA_outData_dequeueing_whas____d2 || INST_top.DEF_bram_serverAdapterA_outData_ff_i_notEmpty____d4);
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_outData_enqueue = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_outData_enqueue;
	 INST_top.INST_rv_core.DEF_fromMMIO_rv_port1__read____d499 = INST_top.INST_rv_core.INST_fromMMIO_rv.METH_port1__read();
	 INST_top.INST_rv_core.DEF_fromDmem_rv_port1__read____d501 = INST_top.INST_rv_core.INST_fromDmem_rv.METH_port1__read();
	 INST_top.INST_rv_core.DEF_mem_business___d489 = INST_top.INST_rv_core.INST_mem_business.METH_read();
	 INST_top.INST_rv_core.DEF_mem_business_89_BIT_0___d498 = (tUInt8)((tUInt8)1u & (INST_top.INST_rv_core.DEF_mem_business___d489));
	 INST_top.INST_rv_core.DEF_mem_business_89_BITS_5_TO_3___d490 = (tUInt8)((INST_top.INST_rv_core.DEF_mem_business___d489) >> 3u);
	 INST_top.INST_rv_core.DEF_dInst_93_BIT_36___d363 = (tUInt8)((tUInt8)1u & ((INST_top.INST_rv_core.DEF_dInst___d293) >> 36u));
	 DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BIT_0_98_THEN_fromMMIO_rv_p_ETC___d503 = INST_top.INST_rv_core.DEF_mem_business_89_BIT_0___d498 ? INST_top.INST_rv_core.DEF_fromMMIO_rv_port1__read____d499.get_bits_in_word8(2u,
																													4u,
																													1u) : INST_top.INST_rv_core.DEF_fromDmem_rv_port1__read____d501.get_bits_in_word8(2u,
																																							  4u,
																																							  1u);
	 switch (INST_top.INST_rv_core.DEF_mem_business_89_BITS_5_TO_3___d490) {
	 case (tUInt8)0u:
	 case (tUInt8)1u:
	 case (tUInt8)4u:
	 case (tUInt8)5u:
	   DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BITS_5_TO_3_90_EQ_0b0_91_OR_ETC___d507 = DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BIT_0_98_THEN_fromMMIO_rv_p_ETC___d503;
	   break;
	 default:
	   DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BITS_5_TO_3_90_EQ_0b0_91_OR_ETC___d507 = !((INST_top.INST_rv_core.DEF_mem_business_89_BITS_5_TO_3___d490) == (tUInt8)2u) || DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BIT_0_98_THEN_fromMMIO_rv_p_ETC___d503;
	 }
	 INST_top.INST_rv_core.DEF_NOT_dInst_93_BIT_36_63___d364 = !(INST_top.INST_rv_core.DEF_dInst_93_BIT_36___d363);
	 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_writeback = ((INST_top.INST_rv_core.INST_retired.METH_i_notFull() && ((INST_top.INST_rv_core.DEF_NOT_dInst_93_BIT_36_63___d364 || (INST_top.INST_rv_core.DEF_dInst_93_BIT_6_94_OR_NOT_dInst_93_BITS_4_TO_3__ETC___d298 || DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BITS_5_TO_3_90_EQ_0b0_91_OR_ETC___d507)) && (INST_top.INST_rv_core.DEF_dInst_93_BIT_6_94_OR_NOT_dInst_93_BITS_4_TO_3__ETC___d298 || DEF_INST_top_INST_rv_core_DEF_IF_mem_business_89_BIT_0_98_THEN_fromMMIO_rv_p_ETC___d503))) && (DEF_INST_top_INST_rv_core_DEF_state__h4472 == (tUInt8)3u && DEF_INST_top_INST_rv_core_DEF_NOT_starting___d9)) && !DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_execute;
	 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_writeback = DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_writeback;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_outData_dequeue)
	   INST_top.RL_bram_serverAdapterA_outData_dequeue();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_outData_enqueue)
	   INST_top.RL_bram_serverAdapterA_outData_enqueue();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_requestD)
	   INST_top.RL_requestD();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_stageReadResponseAlways = INST_top.INST_bram_serverAdapterA_writeWithResp.METH_whas();
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_stageReadResponseAlways = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_stageReadResponseAlways;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_stageReadResponseAlways)
	   INST_top.RL_bram_serverAdapterA_stageReadResponseAlways();
	 INST_top.DEF_bram_serverAdapterA_cnt_3_whas____d13 = INST_top.INST_bram_serverAdapterA_cnt_3.METH_whas();
	 INST_top.DEF_bram_serverAdapterA_cnt_2_whas____d11 = INST_top.INST_bram_serverAdapterA_cnt_2.METH_whas();
	 INST_top.DEF_bram_serverAdapterA_cnt_1_whas____d10 = INST_top.INST_bram_serverAdapterA_cnt_1.METH_whas();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_cnt_finalAdd = (INST_top.DEF_bram_serverAdapterA_cnt_1_whas____d10 || INST_top.DEF_bram_serverAdapterA_cnt_2_whas____d11) || INST_top.DEF_bram_serverAdapterA_cnt_3_whas____d13;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_cnt_finalAdd = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterA_cnt_finalAdd;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_cnt_finalAdd)
	   INST_top.RL_bram_serverAdapterA_cnt_finalAdd();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterA_s1__dreg_update)
	   INST_top.RL_bram_serverAdapterA_s1__dreg_update();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_responseI)
	   INST_top.RL_responseI();
	 DEF_INST_top_DEF_bram_serverAdapterB_outData_dequeueing_whas____d52 = INST_top.INST_bram_serverAdapterB_outData_dequeueing.METH_whas();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_outData_dequeue = DEF_INST_top_DEF_bram_serverAdapterB_outData_dequeueing_whas____d52 && INST_top.DEF_bram_serverAdapterB_outData_ff_i_notEmpty____d54;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_outData_dequeue = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_outData_dequeue;
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_outData_enqueue = DEF_INST_top_DEF_bram_serverAdapterB_outData_enqw_whas____d51 && (!DEF_INST_top_DEF_bram_serverAdapterB_outData_dequeueing_whas____d52 || INST_top.DEF_bram_serverAdapterB_outData_ff_i_notEmpty____d54);
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_outData_enqueue = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_outData_enqueue;
	 INST_top.INST_rv_core.DEF_fromImem_rv_port1__read____d17 = INST_top.INST_rv_core.INST_fromImem_rv.METH_port1__read();
	 DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_decode = (INST_top.INST_rv_core.DEF_fromImem_rv_port1__read____d17.get_bits_in_word8(2u,
																	4u,
																	1u) && (DEF_INST_top_INST_rv_core_DEF_state__h4472 == (tUInt8)1u && DEF_INST_top_INST_rv_core_DEF_NOT_starting___d9)) && !DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_execute;
	 DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_decode = DEF_INST_top_INST_rv_core_DEF_CAN_FIRE_RL_decode;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_outData_dequeue)
	   INST_top.RL_bram_serverAdapterB_outData_dequeue();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_outData_enqueue)
	   INST_top.RL_bram_serverAdapterB_outData_enqueue();
	 if (DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_decode)
	   INST_top.INST_rv_core.RL_decode();
	 if (DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_fetch)
	   INST_top.INST_rv_core.RL_fetch();
	 INST_top.DEF_b__h2255 = INST_top.INST_bram_serverAdapterB_cnt.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_requestI = INST_top.INST_rv_core.METH_RDY_getIReq() && primSLT8(1u,
												      3u,
												      (tUInt8)(INST_top.DEF_b__h2255),
												      3u,
												      (tUInt8)3u);
	 DEF_INST_top_DEF_WILL_FIRE_RL_requestI = DEF_INST_top_DEF_CAN_FIRE_RL_requestI;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_requestI)
	   INST_top.RL_requestI();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_stageReadResponseAlways = INST_top.INST_bram_serverAdapterB_writeWithResp.METH_whas();
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_stageReadResponseAlways = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_stageReadResponseAlways;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_stageReadResponseAlways)
	   INST_top.RL_bram_serverAdapterB_stageReadResponseAlways();
	 INST_top.DEF_bram_serverAdapterB_cnt_3_whas____d63 = INST_top.INST_bram_serverAdapterB_cnt_3.METH_whas();
	 INST_top.DEF_bram_serverAdapterB_cnt_2_whas____d61 = INST_top.INST_bram_serverAdapterB_cnt_2.METH_whas();
	 INST_top.DEF_bram_serverAdapterB_cnt_1_whas____d60 = INST_top.INST_bram_serverAdapterB_cnt_1.METH_whas();
	 DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_cnt_finalAdd = (INST_top.DEF_bram_serverAdapterB_cnt_1_whas____d60 || INST_top.DEF_bram_serverAdapterB_cnt_2_whas____d61) || INST_top.DEF_bram_serverAdapterB_cnt_3_whas____d63;
	 DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_cnt_finalAdd = DEF_INST_top_DEF_CAN_FIRE_RL_bram_serverAdapterB_cnt_finalAdd;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_cnt_finalAdd)
	   INST_top.RL_bram_serverAdapterB_cnt_finalAdd();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_bram_serverAdapterB_s1__dreg_update)
	   INST_top.RL_bram_serverAdapterB_s1__dreg_update();
	 if (DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_writeback)
	   INST_top.INST_rv_core.RL_writeback();
	 if (DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_administrative_konata_commit)
	   INST_top.INST_rv_core.RL_administrative_konata_commit();
	 if (DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_administrative_konata_flush)
	   INST_top.INST_rv_core.RL_administrative_konata_flush();
	 if (DEF_INST_top_INST_rv_core_DEF_WILL_FIRE_RL_do_tic_logging)
	   INST_top.INST_rv_core.RL_do_tic_logging();
	 INST_top.INST_bram_serverAdapterB_s1_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterB_writeWithResp.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterB_cnt_3.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterB_cnt_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterB_cnt_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterB_outData_dequeueing.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterB_outData_enqw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterA_s1_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterA_writeWithResp.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterA_cnt_3.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterA_cnt_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterA_cnt_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterA_outData_dequeueing.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_serverAdapterA_outData_enqw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_memory.clkA((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_bram_memory.clkB((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_rv_core.INST_fromMMIO_rv.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_rv_core.INST_toMMIO_rv.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_rv_core.INST_fromDmem_rv.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_rv_core.INST_toDmem_rv.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_rv_core.INST_fromImem_rv.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_rv_core.INST_toImem_rv.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_rv_core.INST_toImem_rv.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_fromImem_rv.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_toDmem_rv.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_fromDmem_rv.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_toMMIO_rv.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_fromMMIO_rv.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_pc.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_0.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_2.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_3.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_4.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_5.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_6.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_7.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_8.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_9.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_10.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_11.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_12.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_13.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_14.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_15.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_16.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_17.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_18.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_19.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_20.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_21.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_22.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_23.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_24.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_25.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_26.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_27.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_28.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_29.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_30.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rf_31.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_state.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rv1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rv2.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_rvd.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_dInst.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_mem_business.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_lfh.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_current_id.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_fresh_id.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_commit_id.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_rv_core.INST_retired.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_squashed.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_rv_core.INST_starting.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_bram_serverAdapterA_outData_ff.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_bram_serverAdapterA_cnt.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_bram_serverAdapterA_s1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_bram_serverAdapterB_outData_ff.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_bram_serverAdapterB_cnt.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_bram_serverAdapterB_s1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_mmioreq.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_cycle_count.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mktop_bsv::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mktop_bsv_instance = new MOD_mktop_bsv(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mktop_bsv_instance->INST_bram_memory.set_clk_1)("CLK");
  (mktop_bsv_instance->INST_bram_memory.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_outData_ff.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_outData_enqw.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_outData_dequeueing.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_cnt_1.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_cnt_2.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_cnt_3.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_writeWithResp.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterA_s1_1.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_outData_ff.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_outData_enqw.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_outData_dequeueing.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_cnt_1.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_cnt_2.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_cnt_3.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_writeWithResp.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_bram_serverAdapterB_s1_1.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_toImem_rv.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_fromImem_rv.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_toDmem_rv.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_fromDmem_rv.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_toMMIO_rv.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_fromMMIO_rv.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_retired.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.INST_squashed.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_rv_core.set_clk_0)("CLK");
  (mktop_bsv_instance->INST_mmioreq.set_clk_0)("CLK");
  (mktop_bsv_instance->set_clk_0)("CLK");
}
void MODEL_mktop_bsv::destroy_model()
{
  delete mktop_bsv_instance;
  mktop_bsv_instance = NULL;
}
void MODEL_mktop_bsv::reset_model(bool asserted)
{
  (mktop_bsv_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mktop_bsv::get_instance()
{
  return mktop_bsv_instance;
}

/* Fill in version numbers */
void MODEL_mktop_bsv::get_version(char const **name, char const **build)
{
  *name = "2023.01-6-g034050db";
  *build = "034050db";
}

/* Get the model creation time */
time_t MODEL_mktop_bsv::get_creation_time()
{
  
  /* Mon May  1 00:54:18 UTC 2023 */
  return 1682902458llu;
}

/* State dumping function */
void MODEL_mktop_bsv::dump_state()
{
  (mktop_bsv_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mktop_bsv & mktop_bsv_backing(tSimStateHdl simHdl)
{
  static MOD_mktop_bsv *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mktop_bsv(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mktop_bsv::dump_VCD_defs()
{
  (mktop_bsv_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mktop_bsv::dump_VCD(tVCDDumpType dt)
{
  (mktop_bsv_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mktop_bsv_backing(sim_hdl));
}
