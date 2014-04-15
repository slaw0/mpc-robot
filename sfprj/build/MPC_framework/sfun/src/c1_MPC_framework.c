/* Include files */
#include "MPC_framework_sfun.h"
#include "c1_MPC_framework.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "MPC_framework_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD           (0)
#define c1_IN_INIT                      (1)
#define c1_IN_INIT_ACK                  (2)
#define c1_IN_OPERATION                 (3)
#define c1_IN_STOPPED                   (2)
#define c1_IN_PRIMITIVE                 (3)
#define c1_IN_CONTROLLER                (2)
#define c1_IN_MOVING                    (1)
#define c1_IN_POSITIVE_MOV              (2)
#define c1_IN_NEGATIVE_MOV              (1)
#define c1_IN_CONFIG                    (1)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_MPC_frameworkInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_MPC_framework(void);
static void initialize_params_c1_MPC_framework(void);
static void enable_c1_MPC_framework(void);
static void disable_c1_MPC_framework(void);
static void finalize_c1_MPC_framework(void);
static void sf_c1_MPC_framework(void);
static void c1_INIT(void);
static void c1_STOPPED(void);
static void c1_exit_internal_PRIMITIVE(void);
static void c1_exit_internal_MOVING(void);
static void c1_CONFIG(void);
static boolean_T c1__bool_s32_(int32_T c1_b);
static uint8_T *c1_init_out_value(void);
static uint8_T *c1_init_out_enable(void);
static uint8_T *c1_init_ack_sync(void);
static uint8_T *c1_init_ack_async(void);
static uint8_T *c1_init_out_trigger(void);
static uint8_T *c1_stop_trigger(void);
static uint8_T *c1_primitive_button(void);
static uint16_T *c1_motor1_reference(void);
static uint16_T *c1_motor2_reference(void);
static uint8_T *c1_controller_enable(void);
static real_T *c1_da_out_trigger(void);
static real_T *c1_async_request(void);
static uint8_T *c1_operation_mode(void);
static uint8_T *c1_sync_command(void);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static void init_dsm_address_info(void);
static void sf_save_state_c1_MPC_framework(FILE *c1_file);
static void sf_load_state_c1_MPC_framework(FILE *c1_file);

/* Function Definitions */
static void initialize_c1_MPC_framework(void)
{
  uint8_T c1_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_tp_INIT = 0U;
  chartInstance.c1_tp_INIT_ACK = 0U;
  chartInstance.c1_is_OPERATION = 0U;
  chartInstance.c1_tp_OPERATION = 0U;
  chartInstance.c1_tp_CONFIG = 0U;
  chartInstance.c1_tp_CONTROLLER = 0U;
  chartInstance.c1_is_PRIMITIVE = 0U;
  chartInstance.c1_tp_PRIMITIVE = 0U;
  chartInstance.c1_tp_MOVING = 0U;
  chartInstance.c1_is_active_SEGMENT_1 = 0U;
  chartInstance.c1_is_SEGMENT_1 = 0U;
  chartInstance.c1_tp_SEGMENT_1 = 0U;
  chartInstance.c1_tp_NEGATIVE_MOV = 0U;
  chartInstance.c1_tp_POSITIVE_MOV = 0U;
  chartInstance.c1_is_active_SEGMENT_2 = 0U;
  chartInstance.c1_is_SEGMENT_2 = 0U;
  chartInstance.c1_tp_SEGMENT_2 = 0U;
  chartInstance.c1_b_tp_NEGATIVE_MOV = 0U;
  chartInstance.c1_b_tp_POSITIVE_MOV = 0U;
  chartInstance.c1_tp_STOPPED = 0U;
  chartInstance.c1_is_active_c1_MPC_framework = 0U;
  chartInstance.c1_is_c1_MPC_framework = 0U;
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c1_init_out_value() = 0U;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 2) != 0)) {
    *c1_init_out_enable() = 0U;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 3) != 0)) {
    *c1_init_out_trigger() = 0U;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 4) != 0)) {
    *c1_stop_trigger() = 0U;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 5) != 0)) {
    *c1_motor1_reference() = 32768U;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 6) != 0)) {
    *c1_motor2_reference() = 32768U;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 7) != 0)) {
    *c1_controller_enable() = 0U;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 8) != 0)) {
    *c1_da_out_trigger() = 0.0;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 9) != 0)) {
    *c1_operation_mode() = MAX_uint8_T;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 10) != 0)) {
    *c1_sync_command() = 0U;
  }
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
  chartInstance.c1_is_active_c1_MPC_framework = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
  chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_INIT;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
  chartInstance.c1_tp_INIT = 1U;
  *c1_init_out_value() = chartInstance.c1_init_1_message;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 18U);
  *c1_init_out_enable() = 1U;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 2U);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
}

static void initialize_params_c1_MPC_framework(void)
{
  real_T c1_sf_d0;
  real_T c1_sf_d1;
  real_T c1_sf_d2;
  real_T c1_sf_d3;
  real_T c1_sf_d4;
  real_T c1_sf_d5;
  real_T c1_sf_d6;

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): Error evaluating chart workspace data 'motor_stopped_value' in the chart's parent workspace.\n");
  sf_mex_import(sf_mex_get_sfun_param(chartInstance.S, 4),
   "sf_mex_get_sfun_param", &c1_sf_d0, 0, 0U, 0, 0);
  chartInstance.c1_motor_stopped_value = (uint16_T)c1_sf_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): Error evaluating chart workspace data 'init_1_message' in the chart's parent workspace.\n");
  sf_mex_import(sf_mex_get_sfun_param(chartInstance.S, 0),
   "sf_mex_get_sfun_param", &c1_sf_d1, 0, 0U, 0, 0);
  c1_sf_d2 = floor(c1_sf_d1 + 0.5);
  chartInstance.c1_init_1_message = (uint8_T)(c1_sf_d2 <= 255.0 ? c1_sf_d2 >=
    0.0 ? c1_sf_d2 : 0.0 : 255.0);
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): Error evaluating chart workspace data 'init_2_message' in the chart's parent workspace.\n");
  sf_mex_import(sf_mex_get_sfun_param(chartInstance.S, 1),
   "sf_mex_get_sfun_param", &c1_sf_d3, 0, 0U, 0, 0);
  c1_sf_d4 = floor(c1_sf_d3 + 0.5);
  chartInstance.c1_init_2_message = (uint8_T)(c1_sf_d4 <= 255.0 ? c1_sf_d4 >=
    0.0 ? c1_sf_d4 : 0.0 : 255.0);
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): Error evaluating chart workspace data 'motor_positive_value' in the chart's parent workspace.\n");
  sf_mex_import(sf_mex_get_sfun_param(chartInstance.S, 3),
   "sf_mex_get_sfun_param", &c1_sf_d5, 0, 0U, 0, 0);
  chartInstance.c1_motor_positive_value = (uint16_T)c1_sf_d5;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): Error evaluating chart workspace data 'motor_negative_value' in the chart's parent workspace.\n");
  sf_mex_import(sf_mex_get_sfun_param(chartInstance.S, 2),
   "sf_mex_get_sfun_param", &c1_sf_d6, 0, 0U, 0, 0);
  chartInstance.c1_motor_negative_value = (uint16_T)c1_sf_d6;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_MPC_framework(void)
{
}

static void disable_c1_MPC_framework(void)
{
}

static void finalize_c1_MPC_framework(void)
{
}

static void sf_c1_MPC_framework(void)
{
  uint8_T c1_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 18U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_ack_sync(), 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_ack_async(), 13U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_trigger(), 17U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 12U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_primitive_button(), 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_motor_stopped_value, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 0U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_init_1_message, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_init_2_message, 11U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_motor_positive_value, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_motor_negative_value, 10U);
  _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
  _SFD_DATA_RANGE_CHECK(*c1_async_request(), 16U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 8U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  switch(chartInstance.c1_is_c1_MPC_framework) {
   case c1_IN_INIT:
    CV_CHART_EVAL(0,0,1);
    c1_INIT();
    break;
   case c1_IN_INIT_ACK:
    CV_CHART_EVAL(0,0,2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
    chartInstance.c1_tp_INIT_ACK = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_OPERATION;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c1_tp_OPERATION = 1U;
    *c1_operation_mode() = MAX_uint8_T;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_PRIMITIVE;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
    chartInstance.c1_tp_PRIMITIVE = 1U;
    *c1_operation_mode() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
    chartInstance.c1_tp_STOPPED = 1U;
    *c1_motor1_reference() = chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
    *c1_motor2_reference() = chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    break;
   case c1_IN_OPERATION:
    CV_CHART_EVAL(0,0,3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
    switch(chartInstance.c1_is_OPERATION) {
     case c1_IN_CONFIG:
      CV_STATE_EVAL(0,0,1);
      c1_CONFIG();
      break;
     case c1_IN_CONTROLLER:
      CV_STATE_EVAL(0,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,13);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(8U,
         (int32_T)_SFD_CCP_CALL(8,0,((*c1_async_request() == 1.0)!=0)))) != 0) {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions=1;
          transitionList[0] = 8;
          sf_debug_transition_conflict_check_begin();
          if(*c1_async_request() == 6.0) {
            transitionList[numTransitions] = 16;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,13);
        chartInstance.c1_tp_CONTROLLER = 0U;
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_PRIMITIVE;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
        chartInstance.c1_tp_PRIMITIVE = 1U;
        *c1_operation_mode() = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
        chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
        chartInstance.c1_tp_STOPPED = 1U;
        *c1_motor1_reference() = chartInstance.c1_motor_stopped_value;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
        *c1_motor2_reference() = chartInstance.c1_motor_stopped_value;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
        *c1_da_out_trigger() = 1.0;
        _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(16U,
         (int32_T)_SFD_CCP_CALL(16,0,((*c1_async_request() == 6.0)!=0)))) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,16);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,13);
        chartInstance.c1_tp_CONTROLLER = 0U;
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
        chartInstance.c1_tp_CONFIG = 1U;
        *c1_operation_mode() = 3U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
      } else {
        *c1_controller_enable() = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 0U);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
      break;
     case c1_IN_PRIMITIVE:
      CV_STATE_EVAL(0,0,3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,9);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(12U,
         (int32_T)_SFD_CCP_CALL(12,0,((*c1_async_request() == 2.0)!=0)))) != 0) {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions=1;
          transitionList[0] = 12;
          sf_debug_transition_conflict_check_begin();
          if(*c1_async_request() == 6.0) {
            transitionList[numTransitions] = 13;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,12);
        c1_exit_internal_PRIMITIVE();
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,9);
        chartInstance.c1_tp_PRIMITIVE = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,9);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONTROLLER;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
        chartInstance.c1_tp_CONTROLLER = 1U;
        *c1_operation_mode() = 2U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(13U,
         (int32_T)_SFD_CCP_CALL(13,0,((*c1_async_request() == 6.0)!=0)))) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,13);
        c1_exit_internal_PRIMITIVE();
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,9);
        chartInstance.c1_tp_PRIMITIVE = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,9);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
        chartInstance.c1_tp_CONFIG = 1U;
        *c1_operation_mode() = 3U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
      } else {
        *c1_controller_enable() = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 0U);
        switch(chartInstance.c1_is_PRIMITIVE) {
         case c1_IN_MOVING:
          CV_STATE_EVAL(9,0,1);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
          if(c1__bool_s32_(CV_TRANSITION_EVAL(4U,
             (int32_T)_SFD_CCP_CALL(4,0,((*c1_primitive_button() == 5)!=0)))) !=
           0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
            c1_exit_internal_MOVING();
            _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
            chartInstance.c1_tp_MOVING = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
            chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
            chartInstance.c1_tp_STOPPED = 1U;
            *c1_motor1_reference() = chartInstance.c1_motor_stopped_value;
            _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
            *c1_motor2_reference() = chartInstance.c1_motor_stopped_value;
            _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
            *c1_da_out_trigger() = 1.0;
            _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,6);
            switch(chartInstance.c1_is_SEGMENT_1) {
             case c1_IN_NEGATIVE_MOV:
              CV_STATE_EVAL(6,0,1);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
              *c1_da_out_trigger() = 0.0;
              _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
              break;
             case c1_IN_POSITIVE_MOV:
              CV_STATE_EVAL(6,0,2);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
              *c1_da_out_trigger() = 0.0;
              _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
              break;
             default:
              CV_STATE_EVAL(6,0,0);
              break;
            }
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,10);
            switch(chartInstance.c1_is_SEGMENT_2) {
             case c1_IN_NEGATIVE_MOV:
              CV_STATE_EVAL(10,0,1);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
              *c1_da_out_trigger() = 0.0;
              _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
              break;
             case c1_IN_POSITIVE_MOV:
              CV_STATE_EVAL(10,0,2);
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,8);
              *c1_da_out_trigger() = 0.0;
              _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
              break;
             default:
              CV_STATE_EVAL(10,0,0);
              break;
            }
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
          break;
         case c1_IN_STOPPED:
          CV_STATE_EVAL(9,0,2);
          c1_STOPPED();
          break;
         default:
          CV_STATE_EVAL(9,0,0);
          break;
        }
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
      break;
     default:
      CV_STATE_EVAL(0,0,0);
      break;
    }
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    break;
   default:
    CV_CHART_EVAL(0,0,0);
    break;
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_frameworkMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c1_INIT(void)
{
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,7);
  if(c1__bool_s32_(CV_TRANSITION_EVAL(14U,
     (_SFD_CCP_CALL(14,0,((*c1_init_ack_sync() == 1)!=0)) != 0) &&
     (_SFD_CCP_CALL(14,1,((*
         c1_init_ack_async() == 1)!=0)) != 0))) != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,14);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
    chartInstance.c1_tp_INIT = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
    chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_INIT_ACK;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
    chartInstance.c1_tp_INIT_ACK = 1U;
    *c1_init_out_enable() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 2U);
    *c1_init_out_value() = chartInstance.c1_init_2_message;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 18U);
    *c1_init_out_trigger() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_trigger(), 17U);
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
}

static void c1_STOPPED(void)
{
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,11);
  if(c1__bool_s32_(CV_TRANSITION_EVAL(10U,
     (int32_T)_SFD_CCP_CALL(10,0,((*c1_primitive_button() == 4)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[4];
      unsigned int numTransitions=1;
      transitionList[0] = 10;
      sf_debug_transition_conflict_check_begin();
      if(*c1_primitive_button() == 3) {
        transitionList[numTransitions] = 7;
        numTransitions++;
      }
      if(*c1_primitive_button() == 2) {
        transitionList[numTransitions] = 20;
        numTransitions++;
      }
      if(*c1_primitive_button() == 1) {
        transitionList[numTransitions] = 18;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,10);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 12U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,15);
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
    chartInstance.c1_tp_POSITIVE_MOV = 1U;
    *c1_motor1_reference() = chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_NEGATIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
    chartInstance.c1_b_tp_NEGATIVE_MOV = 1U;
    *c1_motor2_reference() = chartInstance.c1_motor_negative_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(7U,
     (int32_T)_SFD_CCP_CALL(7,0,((*c1_primitive_button() == 3)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[3];
      unsigned int numTransitions=1;
      transitionList[0] = 7;
      sf_debug_transition_conflict_check_begin();
      if(*c1_primitive_button() == 2) {
        transitionList[numTransitions] = 20;
        numTransitions++;
      }
      if(*c1_primitive_button() == 1) {
        transitionList[numTransitions] = 18;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 12U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_NEGATIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
    chartInstance.c1_tp_NEGATIVE_MOV = 1U;
    *c1_motor1_reference() = chartInstance.c1_motor_negative_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c1_b_tp_POSITIVE_MOV = 1U;
    *c1_motor2_reference() = chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(20U,
     (int32_T)_SFD_CCP_CALL(20,0,((*c1_primitive_button() == 2)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions=1;
      transitionList[0] = 20;
      sf_debug_transition_conflict_check_begin();
      if(*c1_primitive_button() == 1) {
        transitionList[numTransitions] = 18;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,20);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 12U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,15);
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
    chartInstance.c1_tp_POSITIVE_MOV = 1U;
    *c1_motor1_reference() = chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c1_b_tp_POSITIVE_MOV = 1U;
    *c1_motor2_reference() = chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(18U,
     (int32_T)_SFD_CCP_CALL(18,0,((*c1_primitive_button() == 1)!=0)))) != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,18);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 12U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
    chartInstance.c1_tp_POSITIVE_MOV = 1U;
    *c1_motor1_reference() = chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c1_b_tp_POSITIVE_MOV = 1U;
    *c1_motor2_reference() = chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
  } else {
    *c1_da_out_trigger() = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
}

static void c1_exit_internal_PRIMITIVE(void)
{
  switch(chartInstance.c1_is_PRIMITIVE) {
   case c1_IN_MOVING:
    CV_STATE_EVAL(9,1,1);
    c1_exit_internal_MOVING();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
    chartInstance.c1_tp_MOVING = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
    break;
   case c1_IN_STOPPED:
    CV_STATE_EVAL(9,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 12U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
    break;
   default:
    CV_STATE_EVAL(9,1,0);
    break;
  }
}

static void c1_exit_internal_MOVING(void)
{
  switch(chartInstance.c1_is_SEGMENT_2) {
   case c1_IN_NEGATIVE_MOV:
    CV_STATE_EVAL(10,1,1);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
    chartInstance.c1_b_tp_NEGATIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
    break;
   case c1_IN_POSITIVE_MOV:
    CV_STATE_EVAL(10,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,8);
    chartInstance.c1_b_tp_POSITIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
    break;
   default:
    CV_STATE_EVAL(10,1,0);
    break;
  }
  _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,10);
  chartInstance.c1_tp_SEGMENT_2 = 0U;
  chartInstance.c1_is_active_SEGMENT_2 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
  switch(chartInstance.c1_is_SEGMENT_1) {
   case c1_IN_NEGATIVE_MOV:
    CV_STATE_EVAL(6,1,1);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
    chartInstance.c1_tp_NEGATIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
    break;
   case c1_IN_POSITIVE_MOV:
    CV_STATE_EVAL(6,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
    chartInstance.c1_tp_POSITIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
    break;
   default:
    CV_STATE_EVAL(6,1,0);
    break;
  }
  _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
  chartInstance.c1_tp_SEGMENT_1 = 0U;
  chartInstance.c1_is_active_SEGMENT_1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
}

static void c1_CONFIG(void)
{
  uint8_T c1_b_sync_command;
  uint8_T c1_c_sync_command;
  uint8_T c1_d_sync_command;
  uint8_T c1_e_sync_command;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,12);
  if(c1__bool_s32_(CV_TRANSITION_EVAL(5U,
     (int32_T)_SFD_CCP_CALL(5,0,((*c1_async_request() == 2.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[6];
      unsigned int numTransitions=1;
      transitionList[0] = 5;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 7.0) {
        transitionList[numTransitions] = 17;
        numTransitions++;
      }
      if(*c1_async_request() == 5.0) {
        transitionList[numTransitions] = 21;
        numTransitions++;
      }
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 11;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 9;
        numTransitions++;
      }
      if(*c1_async_request() == 1.0) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONTROLLER;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
    chartInstance.c1_tp_CONTROLLER = 1U;
    *c1_operation_mode() = 2U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(17U,
     (int32_T)_SFD_CCP_CALL(17,0,((*c1_async_request() == 7.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[5];
      unsigned int numTransitions=1;
      transitionList[0] = 17;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 5.0) {
        transitionList[numTransitions] = 21;
        numTransitions++;
      }
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 11;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 9;
        numTransitions++;
      }
      if(*c1_async_request() == 1.0) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
    *c1_sync_command() = 4U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 8U);
    c1_b_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_b_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(21U,
     (int32_T)_SFD_CCP_CALL(21,0,((*c1_async_request() == 5.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[4];
      unsigned int numTransitions=1;
      transitionList[0] = 21;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 11;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 9;
        numTransitions++;
      }
      if(*c1_async_request() == 1.0) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,21);
    *c1_sync_command() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 8U);
    c1_c_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_c_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(11U,
     (int32_T)_SFD_CCP_CALL(11,0,((*c1_async_request() == 4.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[3];
      unsigned int numTransitions=1;
      transitionList[0] = 11;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 9;
        numTransitions++;
      }
      if(*c1_async_request() == 1.0) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,11);
    *c1_sync_command() = 2U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 8U);
    c1_d_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_d_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(9U,
     (int32_T)_SFD_CCP_CALL(9,0,((*c1_async_request() == 3.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions=1;
      transitionList[0] = 9;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 1.0) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,9);
    *c1_sync_command() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 8U);
    c1_e_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_e_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(19U,
     (int32_T)_SFD_CCP_CALL(19,0,((*c1_async_request() == 1.0)!=0)))) != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,19);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_PRIMITIVE;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
    chartInstance.c1_tp_PRIMITIVE = 1U;
    *c1_operation_mode() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 9U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
    chartInstance.c1_tp_STOPPED = 1U;
    *c1_motor1_reference() = chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 14U);
    *c1_motor2_reference() = chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 15U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 4U);
  } else {
    *c1_controller_enable() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 0U);
    *c1_sync_command() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 8U);
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
}

static boolean_T c1__bool_s32_(int32_T c1_b)
{
  boolean_T c1_a;
  c1_a = (boolean_T)c1_b;
  if(c1_a != c1_b) {
    sf_debug_overflow_detection(0);
  }
  return c1_a;
}

static uint8_T *c1_init_out_value(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static uint8_T *c1_init_out_enable(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static uint8_T *c1_init_ack_sync(void)
{
  return (uint8_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static uint8_T *c1_init_ack_async(void)
{
  return (uint8_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static uint8_T *c1_init_out_trigger(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static uint8_T *c1_stop_trigger(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 4);
}

static uint8_T *c1_primitive_button(void)
{
  return (uint8_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static uint16_T *c1_motor1_reference(void)
{
  return (uint16_T *)ssGetOutputPortSignal(chartInstance.S, 5);
}

static uint16_T *c1_motor2_reference(void)
{
  return (uint16_T *)ssGetOutputPortSignal(chartInstance.S, 6);
}

static uint8_T *c1_controller_enable(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 7);
}

static real_T *c1_da_out_trigger(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
}

static real_T *c1_async_request(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
}

static uint8_T *c1_operation_mode(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
}

static uint8_T *c1_sync_command(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 10);
}

static void init_test_point_addr_map(void)
{
  chartInstance.c1_testPointAddrMap[0] = &chartInstance.c1_tp_INIT;
  chartInstance.c1_testPointAddrMap[1] = &chartInstance.c1_tp_INIT_ACK;
  chartInstance.c1_testPointAddrMap[2] = &chartInstance.c1_tp_OPERATION;
  chartInstance.c1_testPointAddrMap[3] = &chartInstance.c1_tp_CONFIG;
  chartInstance.c1_testPointAddrMap[4] = &chartInstance.c1_tp_CONTROLLER;
  chartInstance.c1_testPointAddrMap[5] = &chartInstance.c1_tp_PRIMITIVE;
  chartInstance.c1_testPointAddrMap[6] = &chartInstance.c1_tp_MOVING;
  chartInstance.c1_testPointAddrMap[7] = &chartInstance.c1_tp_SEGMENT_1;
  chartInstance.c1_testPointAddrMap[8] = &chartInstance.c1_tp_NEGATIVE_MOV;
  chartInstance.c1_testPointAddrMap[9] = &chartInstance.c1_tp_POSITIVE_MOV;
  chartInstance.c1_testPointAddrMap[10] = &chartInstance.c1_tp_SEGMENT_2;
  chartInstance.c1_testPointAddrMap[11] = &chartInstance.c1_b_tp_NEGATIVE_MOV;
  chartInstance.c1_testPointAddrMap[12] = &chartInstance.c1_b_tp_POSITIVE_MOV;
  chartInstance.c1_testPointAddrMap[13] = &chartInstance.c1_tp_STOPPED;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c1_testPointMappingInfo;
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c1_MPC_framework(FILE *c1_file)
{
  fwrite(&chartInstance.c1_tp_INIT, 1, sizeof(chartInstance.c1_tp_INIT),
   c1_file);
  fwrite(&chartInstance.c1_tp_INIT_ACK, 1, sizeof(chartInstance.c1_tp_INIT_ACK),
   c1_file);
  fwrite(&chartInstance.c1_tp_OPERATION, 1,
   sizeof(chartInstance.c1_tp_OPERATION), c1_file);
  fwrite(&chartInstance.c1_tp_STOPPED, 1, sizeof(chartInstance.c1_tp_STOPPED),
   c1_file);
  fwrite(&chartInstance.c1_tp_PRIMITIVE, 1,
   sizeof(chartInstance.c1_tp_PRIMITIVE), c1_file);
  fwrite(&chartInstance.c1_tp_CONTROLLER, 1,
   sizeof(chartInstance.c1_tp_CONTROLLER), c1_file);
  fwrite(&chartInstance.c1_tp_MOVING, 1, sizeof(chartInstance.c1_tp_MOVING),
   c1_file);
  fwrite(&chartInstance.c1_tp_SEGMENT_1, 1,
   sizeof(chartInstance.c1_tp_SEGMENT_1), c1_file);
  fwrite(&chartInstance.c1_tp_SEGMENT_2, 1,
   sizeof(chartInstance.c1_tp_SEGMENT_2), c1_file);
  fwrite(&chartInstance.c1_tp_POSITIVE_MOV, 1,
   sizeof(chartInstance.c1_tp_POSITIVE_MOV), c1_file);
  fwrite(&chartInstance.c1_tp_NEGATIVE_MOV, 1,
   sizeof(chartInstance.c1_tp_NEGATIVE_MOV), c1_file);
  fwrite(&chartInstance.c1_b_tp_POSITIVE_MOV, 1,
   sizeof(chartInstance.c1_b_tp_POSITIVE_MOV), c1_file);
  fwrite(&chartInstance.c1_b_tp_NEGATIVE_MOV, 1,
   sizeof(chartInstance.c1_b_tp_NEGATIVE_MOV), c1_file);
  fwrite(&chartInstance.c1_tp_CONFIG, 1, sizeof(chartInstance.c1_tp_CONFIG),
   c1_file);
  fwrite(&chartInstance.c1_is_active_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_active_c1_MPC_framework), c1_file);
  fwrite(&chartInstance.c1_is_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_c1_MPC_framework), c1_file);
  fwrite(&chartInstance.c1_is_OPERATION, 1,
   sizeof(chartInstance.c1_is_OPERATION), c1_file);
  fwrite(&chartInstance.c1_is_PRIMITIVE, 1,
   sizeof(chartInstance.c1_is_PRIMITIVE), c1_file);
  fwrite(&chartInstance.c1_is_active_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_1), c1_file);
  fwrite(&chartInstance.c1_is_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_SEGMENT_1), c1_file);
  fwrite(&chartInstance.c1_is_active_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_2), c1_file);
  fwrite(&chartInstance.c1_is_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_SEGMENT_2), c1_file);
}

static void sf_load_state_c1_MPC_framework(FILE *c1_file)
{
  fread(&chartInstance.c1_tp_INIT, 1, sizeof(chartInstance.c1_tp_INIT), c1_file);
  fread(&chartInstance.c1_tp_INIT_ACK, 1, sizeof(chartInstance.c1_tp_INIT_ACK),
   c1_file);
  fread(&chartInstance.c1_tp_OPERATION, 1,
   sizeof(chartInstance.c1_tp_OPERATION), c1_file);
  fread(&chartInstance.c1_tp_STOPPED, 1, sizeof(chartInstance.c1_tp_STOPPED),
   c1_file);
  fread(&chartInstance.c1_tp_PRIMITIVE, 1,
   sizeof(chartInstance.c1_tp_PRIMITIVE), c1_file);
  fread(&chartInstance.c1_tp_CONTROLLER, 1,
   sizeof(chartInstance.c1_tp_CONTROLLER), c1_file);
  fread(&chartInstance.c1_tp_MOVING, 1, sizeof(chartInstance.c1_tp_MOVING),
   c1_file);
  fread(&chartInstance.c1_tp_SEGMENT_1, 1,
   sizeof(chartInstance.c1_tp_SEGMENT_1), c1_file);
  fread(&chartInstance.c1_tp_SEGMENT_2, 1,
   sizeof(chartInstance.c1_tp_SEGMENT_2), c1_file);
  fread(&chartInstance.c1_tp_POSITIVE_MOV, 1,
   sizeof(chartInstance.c1_tp_POSITIVE_MOV), c1_file);
  fread(&chartInstance.c1_tp_NEGATIVE_MOV, 1,
   sizeof(chartInstance.c1_tp_NEGATIVE_MOV), c1_file);
  fread(&chartInstance.c1_b_tp_POSITIVE_MOV, 1,
   sizeof(chartInstance.c1_b_tp_POSITIVE_MOV), c1_file);
  fread(&chartInstance.c1_b_tp_NEGATIVE_MOV, 1,
   sizeof(chartInstance.c1_b_tp_NEGATIVE_MOV), c1_file);
  fread(&chartInstance.c1_tp_CONFIG, 1, sizeof(chartInstance.c1_tp_CONFIG),
   c1_file);
  fread(&chartInstance.c1_is_active_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_active_c1_MPC_framework), c1_file);
  fread(&chartInstance.c1_is_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_c1_MPC_framework), c1_file);
  fread(&chartInstance.c1_is_OPERATION, 1,
   sizeof(chartInstance.c1_is_OPERATION), c1_file);
  fread(&chartInstance.c1_is_PRIMITIVE, 1,
   sizeof(chartInstance.c1_is_PRIMITIVE), c1_file);
  fread(&chartInstance.c1_is_active_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_1), c1_file);
  fread(&chartInstance.c1_is_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_SEGMENT_1), c1_file);
  fread(&chartInstance.c1_is_active_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_2), c1_file);
  fread(&chartInstance.c1_is_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_SEGMENT_2), c1_file);
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_MPC_framework_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3267587501U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1890348072U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1227287551U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3448373587U);
}

mxArray *sf_c1_MPC_framework_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4231690705U);
    pr[1] = (double)(3524684450U);
    pr[2] = (double)(3513600504U);
    pr[3] = (double)(2860524929U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      {
        const char *fixptFields[] =
        {"isSigned","wordLength","bias","slope","exponent"};
        mxArray *mxFixpt = mxCreateStructMatrix(1,1,5,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(8));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      {
        const char *fixptFields[] =
        {"isSigned","wordLength","bias","slope","exponent"};
        mxArray *mxFixpt = mxCreateStructMatrix(1,1,5,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(8));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }
    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }
    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }
    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }
    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }
    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }
    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }
    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S)
{
  if(ssIsFirstInitCond(S)) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_MPC_frameworkMachineNumber_,
         1,
         14,
         22,
         19,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting(_MPC_frameworkMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_MPC_frameworkMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(18,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_value",0);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_enable",0);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_ack_sync",0);
          _SFD_SET_DATA_PROPS(13,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_ack_async",0);
          _SFD_SET_DATA_PROPS(17,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_trigger",0);
          _SFD_SET_DATA_PROPS(12,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"stop_trigger",0);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"primitive_button",0);
          _SFD_SET_DATA_PROPS(14,2,0,1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor1_reference",0);
          _SFD_SET_DATA_PROPS(15,2,0,1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor2_reference",0);
          _SFD_SET_DATA_PROPS(3,10,0,0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor_stopped_value",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"controller_enable",0);
          _SFD_SET_DATA_PROPS(1,10,0,0,SF_UINT8,0,NULL,1,0,8,0,1,0,"init_1_message",0);
          _SFD_SET_DATA_PROPS(11,10,0,0,SF_UINT8,0,NULL,1,0,8,0,1,0,"init_2_message",0);
          _SFD_SET_DATA_PROPS(6,10,0,0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor_positive_value",0);
          _SFD_SET_DATA_PROPS(10,10,0,0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor_negative_value",0);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"da_out_trigger",0);
          _SFD_SET_DATA_PROPS(16,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"async_request",0);
          _SFD_SET_DATA_PROPS(9,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"operation_mode",0);
          _SFD_SET_DATA_PROPS(8,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"sync_command",0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(5,1,0);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(10,0,1);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,7);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_CH_SUBSTATE_INDEX(2,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,12);
          _SFD_ST_SUBSTATE_INDEX(0,1,13);
          _SFD_ST_SUBSTATE_INDEX(0,2,9);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(9,2);
          _SFD_ST_SUBSTATE_INDEX(9,0,5);
          _SFD_ST_SUBSTATE_INDEX(9,1,11);
          _SFD_ST_SUBSTATE_COUNT(5,2);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,10);
          _SFD_ST_SUBSTATE_COUNT(6,2);
          _SFD_ST_SUBSTATE_INDEX(6,0,1);
          _SFD_ST_SUBSTATE_INDEX(6,1,4);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(10,2);
          _SFD_ST_SUBSTATE_INDEX(10,0,3);
          _SFD_ST_SUBSTATE_INDEX(10,1,8);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
        }
        _SFD_CV_INIT_CHART(3,1,0,0);
        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(0,3,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(9,2,1,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(5,2,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(6,2,1,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(10,2,1,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1,21};
          static unsigned int sEndGuardMap[] = {17,38};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(14,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(18,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(20,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(13,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(19,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(21,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_TRANS_COV_WTS(3,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(3,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(14,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1,21};
          static unsigned int sEndGuardMap[] = {17,38};
          _SFD_TRANS_COV_MAPS(14,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(6,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(6,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(2,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(2,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(4,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(4,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(18,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(18,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(7,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(7,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(20,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(20,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(10,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(10,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(12,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(12,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(8,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(13,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(13,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(16,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(16,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(19,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(19,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(5,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(5,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(15,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(15,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(1,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(1,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(9,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(9,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(11,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(11,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(21,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(21,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(17,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(17,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(18U, c1_init_out_value());
        _SFD_SET_DATA_VALUE_PTR(2U, c1_init_out_enable());
        _SFD_SET_DATA_VALUE_PTR(5U, c1_init_ack_sync());
        _SFD_SET_DATA_VALUE_PTR(13U, c1_init_ack_async());
        _SFD_SET_DATA_VALUE_PTR(17U, c1_init_out_trigger());
        _SFD_SET_DATA_VALUE_PTR(12U, c1_stop_trigger());
        _SFD_SET_DATA_VALUE_PTR(7U, c1_primitive_button());
        _SFD_SET_DATA_VALUE_PTR(14U, c1_motor1_reference());
        _SFD_SET_DATA_VALUE_PTR(15U, c1_motor2_reference());
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance.c1_motor_stopped_value);
        _SFD_SET_DATA_VALUE_PTR(0U, c1_controller_enable());
        _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance.c1_init_1_message);
        _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance.c1_init_2_message);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance.c1_motor_positive_value);
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance.c1_motor_negative_value);
        _SFD_SET_DATA_VALUE_PTR(4U, c1_da_out_trigger());
        _SFD_SET_DATA_VALUE_PTR(16U, c1_async_request());
        _SFD_SET_DATA_VALUE_PTR(9U, c1_operation_mode());
        _SFD_SET_DATA_VALUE_PTR(8U, c1_sync_command());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_MPC_frameworkMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c1_MPC_framework(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c1_MPC_framework();
  initialize_c1_MPC_framework();
}

static void sf_opaque_enable_c1_MPC_framework(void *chartInstanceVar)
{
  enable_c1_MPC_framework();
}

static void sf_opaque_disable_c1_MPC_framework(void *chartInstanceVar)
{
  disable_c1_MPC_framework();
}

static void sf_opaque_gateway_c1_MPC_framework(void *chartInstanceVar)
{
  sf_c1_MPC_framework();
}

static void sf_opaque_terminate_c1_MPC_framework(void *chartInstanceVar)
{
  finalize_c1_MPC_framework();
}

static void mdlProcessParameters_c1_MPC_framework(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c1_MPC_framework();
}

static void mdlSetWorkWidths_c1_MPC_framework(SimStruct *S)
{
  /* Actual parameters from chart:
     init_1_message init_2_message motor_negative_value motor_positive_value motor_stopped_value 
   */
  const char_T *rtParamNames[] = {"p1","p2","p3","p4","p5"};

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  /* registration for init_1_message*/
  {
    DTypeId dataTypeId = sf_get_fixpt_data_type_id(S,
     (unsigned int)8,
     (bool)0,
     (int)0,
     (double)1,
     (double)0);
    ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], dataTypeId);
  }
  /* registration for init_2_message*/
  {
    DTypeId dataTypeId = sf_get_fixpt_data_type_id(S,
     (unsigned int)8,
     (bool)0,
     (int)0,
     (double)1,
     (double)0);
    ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], dataTypeId);
  }
  /* registration for motor_negative_value*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_UINT16);
  /* registration for motor_positive_value*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_UINT16);
  /* registration for motor_stopped_value*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_UINT16);

  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("MPC_framework",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("MPC_framework",1,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_framework",1,4);
      sf_mark_chart_reusable_outputs(S,"MPC_framework",1,10);
    }
    if (!sf_is_chart_instance_optimized_out("MPC_framework",1)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("MPC_framework",1);
      dtId = ssRegisterDataType(S, chartInstanceTypedefName);
      if (dtId == INVALID_DTYPE_ID ) return;
      /* Register the size of the udt */
      if (!ssSetDataTypeSize(S, dtId, 8)) return;
      if(!ssSetNumDWork(S,1)) return;
      ssSetDWorkDataType(S, 0, dtId);
      ssSetDWorkWidth(S, 0, 1);
      ssSetDWorkName(S, 0, "ChartInstance"); /*optional name, less than 16 chars*/
      sf_set_rtw_identifier(S);
    }
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
    ssSetCallsOutputInInitFcn(S,1);
  }

  ssSetChecksum0(S,(3171898987U));
  ssSetChecksum1(S,(3011734879U));
  ssSetChecksum2(S,(259295982U));
  ssSetChecksum3(S,(3027932798U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_MPC_framework(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MPC_framework", 1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void sf_save_debug_c1_MPC_framework(SFc1_MPC_frameworkInstanceStruct*
 chartInstance, FILE* file)
{
  int machineNumber = _MPC_frameworkMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = sf_debug_get_state_vectors_data_size(machineNumber,
   chartNumber, instanceNumber);
  unsigned char* buffer = (unsigned char*) malloc(bufferSize);
  unsigned int chartActive = sf_debug_get_chart_active(machineNumber,
   chartNumber, instanceNumber);
  fwrite(&chartActive, sizeof(chartActive),1,file);
  sf_debug_get_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  fwrite(&bufferSize, sizeof(bufferSize), 1, file); /* Write number of bytes */
  fwrite(buffer, 1, bufferSize,file);   /* Write buffer */
  free(buffer);
}
static void sf_load_debug_c1_MPC_framework(SFc1_MPC_frameworkInstanceStruct*
 chartInstance,FILE* file)
{
  int machineNumber = _MPC_frameworkMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = 0;
  unsigned char* buffer = NULL;
  unsigned int chartActive = 0;
  fread(&chartActive, sizeof(chartActive),1,file);
  sf_debug_set_chart_active(machineNumber, chartNumber, instanceNumber,
   chartActive);
  fread(&bufferSize, sizeof(bufferSize), 1, file);
  buffer = (unsigned char*) malloc(bufferSize);
  fread(buffer, 1, bufferSize, file);
  sf_debug_set_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  free(buffer);
}
static void sf_c1_MPC_framework_sim_ctx_io(SimStruct* S, const char io, FILE*
 file)
{
  if(io == 'r') {
    sf_load_state_c1_MPC_framework(file);
    sf_load_debug_c1_MPC_framework(&chartInstance, file);
  } else {
    sf_save_state_c1_MPC_framework(file);
    sf_save_debug_c1_MPC_framework(&chartInstance, file);
  }
}
static void mdlStart_c1_MPC_framework(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c1_MPC_framework;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_MPC_framework;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c1_MPC_framework;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_MPC_framework;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_MPC_framework;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_MPC_framework;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_MPC_framework;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_MPC_framework;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c1_MPC_framework_sim_ctx_io);

  if(!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c1_MPC_framework_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_MPC_framework(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_MPC_framework(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_MPC_framework(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c1_MPC_framework_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  {"uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0}
};

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  {NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0}
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  {rtwCAPI_SCALAR, 0, 2}
};

static const uint_T dimensionArray[] = {
  1, 1
};

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  {&sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0}
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  {0, 0, "StateflowChart/INIT", "INIT", 0, 0, 0, 0, 0},
  {1, 0, "StateflowChart/INIT_ACK", "INIT_ACK", 0, 0, 0, 0, 0},
  {2, 0, "StateflowChart/OPERATION", "OPERATION", 0, 0, 0, 0, 0},
  {3, 0, "StateflowChart/OPERATION.CONFIG", "CONFIG", 0, 0, 0, 0, 0},
  {4, 0, "StateflowChart/OPERATION.CONTROLLER", "CONTROLLER", 0, 0, 0, 0, 0},
  {5, 0, "StateflowChart/OPERATION.PRIMITIVE", "PRIMITIVE", 0, 0, 0, 0, 0},
  {6, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING", "MOVING", 0, 0, 0, 0, 0},
  {7, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_1", "SEGMENT_1", 0,
    0, 0, 0, 0},
  {8, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_1.NEGATIVE_MOV",
    "NEGATIVE_MOV", 0, 0, 0, 0, 0},
  {9, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_1.POSITIVE_MOV",
    "POSITIVE_MOV", 0, 0, 0, 0, 0},
  {10, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_2", "SEGMENT_2", 0,
    0, 0, 0, 0},
  {11, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_2.NEGATIVE_MOV",
    "NEGATIVE_MOV", 0, 0, 0, 0, 0},
  {12, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_2.POSITIVE_MOV",
    "POSITIVE_MOV", 0, 0, 0, 0, 0},
  {13, 0, "StateflowChart/OPERATION.PRIMITIVE.STOPPED", "STOPPED", 0, 0, 0, 0, 0}
};

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                   /* Block signals Array  */
    14                                  /* Num Block IO signals */
  },

  /* parameter tuning */
  {
    NULL,                               /* Block parameters Array    */
    0,                                  /* Num block parameters      */
    NULL,                               /* Variable parameters Array */
    0                                   /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                               /* Block States array        */
    0                                   /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                        /* Data Type Map            */
    dimensionMap,                       /* Data Dimension Map       */
    fixedPointMap,                      /* Fixed Point Map          */
    NULL,                               /* Structure Element map    */
    sampleTimeMap,                      /* Sample Times Map         */
    dimensionArray                      /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S) {
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;

  init_test_point_addr_map();
  testPointMappingInfo = get_test_point_mapping_info();
  testPointAddrMap = get_test_point_address_map();

  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);

  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}

