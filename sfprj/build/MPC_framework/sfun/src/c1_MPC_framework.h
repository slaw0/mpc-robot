#ifndef __c1_MPC_framework_h__
#define __c1_MPC_framework_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  void *c1_testPointAddrMap[13];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint16_T c1_motor_negative_value;
  uint16_T c1_motor_positive_value;
  uint16_T c1_motor_stopped_value;
  uint8_T c1_b_tp_NEGATIVE_MOV;
  uint8_T c1_b_tp_POSITIVE_MOV;
  uint8_T c1_init_1_message;
  uint8_T c1_init_2_message;
  uint8_T c1_is_OPERATION;
  uint8_T c1_is_PRIMITIVE;
  uint8_T c1_is_SEGMENT_1;
  uint8_T c1_is_SEGMENT_2;
  uint8_T c1_is_active_SEGMENT_1;
  uint8_T c1_is_active_SEGMENT_2;
  uint8_T c1_is_active_c1_MPC_framework;
  uint8_T c1_is_c1_MPC_framework;
  uint8_T c1_tp_CONTROLLER;
  uint8_T c1_tp_INIT;
  uint8_T c1_tp_INIT_ACK;
  uint8_T c1_tp_MOVING;
  uint8_T c1_tp_NEGATIVE_MOV;
  uint8_T c1_tp_OPERATION;
  uint8_T c1_tp_POSITIVE_MOV;
  uint8_T c1_tp_PRIMITIVE;
  uint8_T c1_tp_SEGMENT_1;
  uint8_T c1_tp_SEGMENT_2;
  uint8_T c1_tp_STOPPED;
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
  ChartInfoStruct chartInfo;
} SFc1_MPC_frameworkInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c1_MPC_framework_get_check_sum(mxArray *plhs[]);
extern void c1_MPC_framework_method_dispatcher(SimStruct *S, int_T method, void
 *data);

#endif

