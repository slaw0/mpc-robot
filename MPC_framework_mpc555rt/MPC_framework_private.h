/*
 * File: MPC_framework_private.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.698
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Tue Apr 29 11:48:54 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Tue Apr 29 11:48:55 2014
 */

#ifndef _RTW_HEADER_MPC_framework_private_h_
#define _RTW_HEADER_MPC_framework_private_h_

#include "rtwtypes.h"

#include "can_rx.h"
#include <string.h>

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

extern CAN_FRAME CAN_FRAME_GROUND;      // A pointer to a CAN module that
// all transmit and receive blocks
// will reference.
extern CAN_MODULE GlobalModuleCAN_A;
// A pointer to a CAN module that
// all transmit and receive blocks
// will reference.
extern CAN_MODULE GlobalModuleCAN_B;

real_T lfcbphdbbaaiimgd_sign(real_T eml_X);

void MPC_f_Inversegeometry(real_T rtu_X, real_T rtu_Y, real_T rtu_2, real_T
 rtu_3, real_T rtu_a1, real_T rtu_a2, rtB_MPC_f_Inversegeometry *localB);
void controller_messagesen_Start(void);
void controller_messagesen(void);
void MPC_frame_StateMachine_Init(void);
void MPC_fram_StateMachine_Start(void);
void MPC_fram_StateMachine(void);

#endif                                  /* _RTW_HEADER_MPC_framework_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
