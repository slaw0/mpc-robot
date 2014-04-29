/*
 * File: MPC_framework_types.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.907
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Tue Apr 29 19:27:31 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Tue Apr 29 19:27:32 2014
 */

#ifndef _RTW_HEADER_MPC_framework_types_h_
#define _RTW_HEADER_MPC_framework_types_h_

#ifndef _CSC1_MPC_FRAMEWORK_CHARTSTRUCT_
#define _CSC1_MPC_FRAMEWORK_CHARTSTRUCT_

typedef struct {
  real_T alpha1_ref;
  real_T alpha2_ref;
  uint8_T is_CONTROLLER;
  uint8_T is_HOLD;
  uint8_T is_OPERATION;
  uint8_T is_PRIMITIVE;
  uint8_T is_SEGMENT_1;
  uint8_T is_SEGMENT_2;
  uint8_T is_active_SEGMENT_1;
  uint8_T is_active_SEGMENT_2;
  uint8_T is_c1_MPC_framework;
} CSc1_MPC_framework_ChartStruct;

#endif                                  /* _CSC1_MPC_FRAMEWORK_CHARTSTRUCT_ */

/* Parameters for system: '<Root>/Inverse geometry' */
typedef struct _rtP_MPC_f_Inversegeometry rtP_MPC_f_Inversegeometry;

/* Parameters (auto storage) */
typedef struct _Parameters_MPC_framework Parameters_MPC_framework;

/* Forward declaration for rtModel */
typedef struct RT_MODEL_MPC_framework RT_MODEL_MPC_framework;

#endif                                  /* _RTW_HEADER_MPC_framework_types_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
