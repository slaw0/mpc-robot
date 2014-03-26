/*
 * realtime_vars.h
 *
 * Real-Time Workshop code generation for Simulink model "MPC_framework.mdl".
 *
 * Model Version              : 1.340
 * Real-Time Workshop version : 6.4  (R2006a)  03-Feb-2006
 * C source code generated on : Wed Mar 26 19:04:35 2014
 *
 * Description  : Header file to define model dependent variables required
 *                by the build process. This file is included by
 *                mpc555dk_main.c
 */

/* Model sample period */
#define TIMER_TICK_PERIOD               0.01

/* 
 * Macro used by CCP block to determine which DAQ Lists to 
 * process after a Single-Tasking model step.
 *
 * Note: this macro should be called prior to calling MODEL_STEP
 * since MODEL_STEP will update the timing information.
 *
 * Note: Only call this macro for Single Tasking models
 *
 */
#ifndef DISC_NUMST
#error DISC_NUMST must be defined
#endif

#ifndef CCP_MT_PROCESSED
#error CCP_MT_PROCESSED must be defined
#endif

#ifndef CCP_AUTOBUILD_PROCESSED
#error CCP_AUTOBUILD_PROCESSED must be defined
#endif

#if (DISC_NUMST > 1) && !defined(MULTITASKING) && defined(CCP_DAQ_LIST_ENABLED)
#ifndef NCSTATES
#error NCSTATES must be defined
#else
#if NCSTATES > 0
#error CCP DAQ lists are not supported with multi-rate, singleTasking models, that also contain continuous states
#else
#define MPC555_IS_SINGLE_TASKING_SAMPLE_HIT(TID_NUM) (tid == TID_NUM)
#endif
#endif
#else
/* MPC555_IS_SINGLE_TASKING_SAMPLE_HIT macro not required */
#endif

