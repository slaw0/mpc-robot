/*
 * File: MPC_framework_types.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.1466
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Thu May 08 18:43:44 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Thu May 08 18:43:45 2014
 */

#ifndef _RTW_HEADER_MPC_framework_types_h_
#define _RTW_HEADER_MPC_framework_types_h_

#ifndef _CSC1_MPC_FRAMEWORK_CHARTSTRUCT_
#define _CSC1_MPC_FRAMEWORK_CHARTSTRUCT_

typedef struct {
  uint16_T temporalCounter_i1;
  uint8_T is_CONTROLLER;
  uint8_T is_HOLD;
  uint8_T is_MOVING;
  uint8_T is_OPERATION;
  uint8_T is_PRIMITIVE;
  uint8_T is_c1_MPC_framework;
  uint8_T trajectory_ready;
} CSc1_MPC_framework_ChartStruct;

#endif                                  /* _CSC1_MPC_FRAMEWORK_CHARTSTRUCT_ */

/* Parameters (auto storage) */
typedef struct _Parameters_MPC_framework Parameters_MPC_framework;

/* Forward declaration for rtModel */
typedef struct RT_MODEL_MPC_framework RT_MODEL_MPC_framework;

#endif                                  /* _RTW_HEADER_MPC_framework_types_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
