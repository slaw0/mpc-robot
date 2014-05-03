/*
 * trajectory_test_private.h
 *
 * Real-Time Workshop code generation for Simulink model "trajectory_test.mdl".
 *
 * Model Version              : 1.29
 * Real-Time Workshop version : 6.4  (R2006a)  03-Feb-2006
 * C source code generated on : Wed Apr 30 13:11:18 2014
 */
#ifndef _RTW_HEADER_trajectory_test_private_h_
#define _RTW_HEADER_trajectory_test_private_h_

#include "rtwtypes.h"

# include "rtlibsrc.h"
#define CALL_EVENT                      (MAX_uint8_T)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else
/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                  /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                  /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                  /* __RTWTYPES_H__ */

void tJointreferencesingal1(real_T rtu_a0, real_T rtu_a1, real_T rtu_a2, real_T
 rtu_a3, real_T rtu_a4, real_T rtu_a5, real_T rtu_t_sim, real_T rtu_t_end,
 rtB_tJointreferencesingal1 *localB);
void traje_Trajectorydesign1(real_T rtu_A, real_T rtu_B, real_T rtu_t,
 rtB_traje_Trajectorydesign1 *localB);

#endif                                  /* _RTW_HEADER_trajectory_test_private_h_ */
