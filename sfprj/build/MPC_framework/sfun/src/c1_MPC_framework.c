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
#define c1_IN_PRIMITIVE                 (4)
#define c1_IN_CONTROLLER                (3)
#define c1_IN_MOVING                    (1)
#define c1_IN_POSITIVE_MOV              (2)
#define c1_IN_NEGATIVE_MOV              (1)
#define c1_IN_CONFIG                    (2)
#define c1_IN_BLUETOOTH                 (1)
#define c1_IN_HOLD                      (1)
#define c1_IN_TRAJECTORY                (2)
#define c1_IN_HOLD_main                 (1)

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
static void c1_c1_MPC_framework(void);
static void c1_STOPPED(void);
static void c1_PRIMITIVE(void);
static void c1_exit_internal_PRIMITIVE(void);
static void c1_enter_atomic_CONTROLLER(void);
static void c1_enter_internal_CONTROLLER(void);
static void c1_CONTROLLER(void);
static void c1_exit_internal_CONTROLLER(void);
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
static real_T *c1_motor1_reference(void);
static real_T *c1_motor2_reference(void);
static uint8_T *c1_controller_enable(void);
static real_T *c1_da_out_trigger(void);
static real_T *c1_async_request(void);
static uint8_T *c1_operation_mode(void);
static uint8_T *c1_sync_command(void);
static real_T *c1_alpha_in(void);
static uint8_T *c1_controller_message(void);
static boolean_T *c1_coords_changed(void);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static uint8_T c1_get_invgeo_error(int32_T c1_b);
static void c1_set_invgeo_error(int32_T c1_b, uint8_T c1_c);
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
  chartInstance.c1_tp_BLUETOOTH = 0U;
  chartInstance.c1_tp_CONFIG = 0U;
  chartInstance.c1_is_CONTROLLER = 0U;
  chartInstance.c1_tp_CONTROLLER = 0U;
  chartInstance.c1_is_HOLD = 0U;
  chartInstance.c1_tp_HOLD = 0U;
  chartInstance.c1_tp_HOLD_main = 0U;
  chartInstance.c1_tp_TRAJECTORY = 0U;
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
  chartInstance.c1_alpha1_ref = 0.0;
  chartInstance.c1_alpha2_ref = 0.0;
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
    *c1_motor1_reference() = 32768.0;
  }
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 6) != 0)) {
    *c1_motor2_reference() = 32768.0;
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
  if(!((boolean_T)cdrGetOutputPortReusable(chartInstance.S, 11) != 0)) {
    *c1_controller_message() = 0U;
  }
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
  chartInstance.c1_is_active_c1_MPC_framework = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,20);
  chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_INIT;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
  chartInstance.c1_tp_INIT = 1U;
  *c1_init_out_value() = chartInstance.c1_init_1_message;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 24U);
  *c1_init_out_enable() = 1U;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 3U);
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
  sf_call_output_fcn_enable(chartInstance.S, 0, "invgeo_start", 1);
  sf_call_output_fcn_enable(chartInstance.S, 1, "send_controller_message", 1);
}

static void disable_c1_MPC_framework(void)
{
  sf_call_output_fcn_disable(chartInstance.S, 0, "invgeo_start", 1);
  sf_call_output_fcn_disable(chartInstance.S, 1, "send_controller_message", 1);
}

static void finalize_c1_MPC_framework(void)
{
}

static void sf_c1_MPC_framework(void)
{
  int32_T c1_sf_i0;
  uint8_T c1_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 24U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_ack_sync(), 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_ack_async(), 20U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_trigger(), 23U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 19U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_primitive_button(), 10U);
  _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
  _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_motor_stopped_value, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 1U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_init_1_message, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_init_2_message, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_motor_positive_value, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_motor_negative_value, 14U);
  _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  _SFD_DATA_RANGE_CHECK(*c1_async_request(), 21U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_alpha1_ref, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_alpha2_ref, 13U);
  for(c1_sf_i0 = 0; c1_sf_i0 < 2; c1_sf_i0 = c1_sf_i0 + 1) {
    _SFD_DATA_RANGE_CHECK(c1_alpha_in()[c1_sf_i0], 15U);
  }
  _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_message(), 16U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_coords_changed(), 18U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_MPC_framework();
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_frameworkMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c1_c1_MPC_framework(void)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  switch(chartInstance.c1_is_c1_MPC_framework) {
   case c1_IN_INIT:
    CV_CHART_EVAL(0,0,1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
    if(c1__bool_s32_(CV_TRANSITION_EVAL(22U,
       (_SFD_CCP_CALL(22,0,((*c1_init_ack_sync() == 1)!=0)) != 0) &&
       (_SFD_CCP_CALL(22,1,((*
           c1_init_ack_async() == 1)!=0)) != 0))) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,22);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
      chartInstance.c1_tp_INIT = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
      chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_INIT_ACK;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
      chartInstance.c1_tp_INIT_ACK = 1U;
      *c1_init_out_enable() = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 3U);
      *c1_init_out_value() = chartInstance.c1_init_2_message;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 24U);
      *c1_init_out_trigger() = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_trigger(), 23U);
    }
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
    break;
   case c1_IN_INIT_ACK:
    CV_CHART_EVAL(0,0,2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,32);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
    chartInstance.c1_tp_INIT_ACK = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_OPERATION;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
    chartInstance.c1_tp_OPERATION = 1U;
    *c1_operation_mode() = MAX_uint8_T;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,9);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_PRIMITIVE;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c1_tp_PRIMITIVE = 1U;
    *c1_operation_mode() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
    chartInstance.c1_tp_STOPPED = 1U;
    *c1_motor1_reference() = (real_T)chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
    *c1_motor2_reference() = (real_T)chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    break;
   case c1_IN_OPERATION:
    CV_CHART_EVAL(0,0,3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,7);
    switch(chartInstance.c1_is_OPERATION) {
     case c1_IN_BLUETOOTH:
      CV_STATE_EVAL(7,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(21U,
         (int32_T)_SFD_CCP_CALL(21,0,((*c1_async_request() == 1.0)!=0)))) != 0) {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[3];
          unsigned int numTransitions=1;
          transitionList[0] = 21;
          sf_debug_transition_conflict_check_begin();
          if(*c1_async_request() == 2.0) {
            transitionList[numTransitions] = 6;
            numTransitions++;
          }
          if(*c1_async_request() == 6.0) {
            transitionList[numTransitions] = 35;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,21);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
        chartInstance.c1_tp_BLUETOOTH = 0U;
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_PRIMITIVE;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
        chartInstance.c1_tp_PRIMITIVE = 1U;
        *c1_operation_mode() = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
        chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
        chartInstance.c1_tp_STOPPED = 1U;
        *c1_motor1_reference() = (real_T)chartInstance.c1_motor_stopped_value;
        _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
        *c1_motor2_reference() = (real_T)chartInstance.c1_motor_stopped_value;
        _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
        *c1_da_out_trigger() = 1.0;
        _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(6U,
         (int32_T)_SFD_CCP_CALL(6,0,((*c1_async_request() == 2.0)!=0)))) != 0) {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions=1;
          transitionList[0] = 6;
          sf_debug_transition_conflict_check_begin();
          if(*c1_async_request() == 6.0) {
            transitionList[numTransitions] = 35;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
        chartInstance.c1_tp_BLUETOOTH = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONTROLLER;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,14);
        chartInstance.c1_tp_CONTROLLER = 1U;
        *c1_operation_mode() = 2U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
        chartInstance.c1_alpha1_ref = c1_alpha_in()[0];
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_alpha1_ref, 9U);
        chartInstance.c1_alpha2_ref = c1_alpha_in()[1];
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_alpha2_ref, 13U);
        c1_set_invgeo_error(0, MAX_uint8_T);
        *c1_controller_message() = MAX_uint8_T;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_message(), 16U);
        c1_enter_internal_CONTROLLER();
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(35U,
         (int32_T)_SFD_CCP_CALL(35,0,((*c1_async_request() == 6.0)!=0)))) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,35);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
        chartInstance.c1_tp_BLUETOOTH = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
        chartInstance.c1_tp_CONFIG = 1U;
        *c1_operation_mode() = 3U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
      } else {
        *c1_controller_enable() = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 1U);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      break;
     case c1_IN_CONFIG:
      CV_STATE_EVAL(7,0,2);
      c1_CONFIG();
      break;
     case c1_IN_CONTROLLER:
      CV_STATE_EVAL(7,0,3);
      c1_CONTROLLER();
      break;
     case c1_IN_PRIMITIVE:
      CV_STATE_EVAL(7,0,4);
      c1_PRIMITIVE();
      break;
     default:
      CV_STATE_EVAL(7,0,0);
      break;
    }
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
    break;
   default:
    CV_CHART_EVAL(0,0,0);
    break;
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void c1_STOPPED(void)
{
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,10);
  if(c1__bool_s32_(CV_TRANSITION_EVAL(34U,
     (int32_T)_SFD_CCP_CALL(34,0,((*c1_primitive_button() == 4)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[4];
      unsigned int numTransitions=1;
      transitionList[0] = 34;
      sf_debug_transition_conflict_check_begin();
      if(*c1_primitive_button() == 3) {
        transitionList[numTransitions] = 10;
        numTransitions++;
      }
      if(*c1_primitive_button() == 2) {
        transitionList[numTransitions] = 12;
        numTransitions++;
      }
      if(*c1_primitive_button() == 1) {
        transitionList[numTransitions] = 30;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,34);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,10);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 19U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,15);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,17);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,28);
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
    chartInstance.c1_tp_POSITIVE_MOV = 1U;
    *c1_motor1_reference() = (real_T)chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_NEGATIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c1_b_tp_NEGATIVE_MOV = 1U;
    *c1_motor2_reference() = (real_T)chartInstance.c1_motor_negative_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(10U,
     (int32_T)_SFD_CCP_CALL(10,0,((*c1_primitive_button() == 3)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[3];
      unsigned int numTransitions=1;
      transitionList[0] = 10;
      sf_debug_transition_conflict_check_begin();
      if(*c1_primitive_button() == 2) {
        transitionList[numTransitions] = 12;
        numTransitions++;
      }
      if(*c1_primitive_button() == 1) {
        transitionList[numTransitions] = 30;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,10);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,10);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 19U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,15);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,17);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_NEGATIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,16);
    chartInstance.c1_tp_NEGATIVE_MOV = 1U;
    *c1_motor1_reference() = (real_T)chartInstance.c1_motor_negative_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,18);
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c1_b_tp_POSITIVE_MOV = 1U;
    *c1_motor2_reference() = (real_T)chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(12U,
     (int32_T)_SFD_CCP_CALL(12,0,((*c1_primitive_button() == 2)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions=1;
      transitionList[0] = 12;
      sf_debug_transition_conflict_check_begin();
      if(*c1_primitive_button() == 1) {
        transitionList[numTransitions] = 30;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,12);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,10);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 19U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,15);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,17);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,28);
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
    chartInstance.c1_tp_POSITIVE_MOV = 1U;
    *c1_motor1_reference() = (real_T)chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c1_b_tp_POSITIVE_MOV = 1U;
    *c1_motor2_reference() = (real_T)chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(30U,
     (int32_T)_SFD_CCP_CALL(30,0,((*c1_primitive_button() == 1)!=0)))) != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,30);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,10);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 19U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_MOVING;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,15);
    chartInstance.c1_tp_MOVING = 1U;
    chartInstance.c1_is_active_SEGMENT_1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,17);
    chartInstance.c1_tp_SEGMENT_1 = 1U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
    chartInstance.c1_tp_POSITIVE_MOV = 1U;
    *c1_motor1_reference() = (real_T)chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
    chartInstance.c1_is_active_SEGMENT_2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
    chartInstance.c1_tp_SEGMENT_2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,18);
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_POSITIVE_MOV;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
    chartInstance.c1_b_tp_POSITIVE_MOV = 1U;
    *c1_motor2_reference() = (real_T)chartInstance.c1_motor_positive_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  } else {
    *c1_da_out_trigger() = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
}

static void c1_PRIMITIVE(void)
{
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,8);
  if(c1__bool_s32_(CV_TRANSITION_EVAL(8U,
     (int32_T)_SFD_CCP_CALL(8,0,((*c1_async_request() == 2.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[3];
      unsigned int numTransitions=1;
      transitionList[0] = 8;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 8.0) {
        transitionList[numTransitions] = 17;
        numTransitions++;
      }
      if(*c1_async_request() == 6.0) {
        transitionList[numTransitions] = 7;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
    c1_exit_internal_PRIMITIVE();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,8);
    chartInstance.c1_tp_PRIMITIVE = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
    c1_enter_atomic_CONTROLLER();
    c1_enter_internal_CONTROLLER();
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(17U,
     (int32_T)_SFD_CCP_CALL(17,0,((*c1_async_request() == 8.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions=1;
      transitionList[0] = 17;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 6.0) {
        transitionList[numTransitions] = 7;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
    c1_exit_internal_PRIMITIVE();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,8);
    chartInstance.c1_tp_PRIMITIVE = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_BLUETOOTH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
    chartInstance.c1_tp_BLUETOOTH = 1U;
    *c1_operation_mode() = 4U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(7U,
     (int32_T)_SFD_CCP_CALL(7,0,((*c1_async_request() == 6.0)!=0)))) != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
    c1_exit_internal_PRIMITIVE();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,8);
    chartInstance.c1_tp_PRIMITIVE = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else {
    *c1_controller_enable() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 1U);
    switch(chartInstance.c1_is_PRIMITIVE) {
     case c1_IN_MOVING:
      CV_STATE_EVAL(8,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,15);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(33U,
         (int32_T)_SFD_CCP_CALL(33,0,((*c1_primitive_button() == 5)!=0)))) != 0)
      {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,33);
        c1_exit_internal_MOVING();
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,15);
        chartInstance.c1_tp_MOVING = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,15);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
        chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
        chartInstance.c1_tp_STOPPED = 1U;
        *c1_motor1_reference() = (real_T)chartInstance.c1_motor_stopped_value;
        _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
        *c1_motor2_reference() = (real_T)chartInstance.c1_motor_stopped_value;
        _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
        *c1_da_out_trigger() = 1.0;
        _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,17);
        switch(chartInstance.c1_is_SEGMENT_1) {
         case c1_IN_NEGATIVE_MOV:
          CV_STATE_EVAL(17,0,1);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,16);
          *c1_da_out_trigger() = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
          break;
         case c1_IN_POSITIVE_MOV:
          CV_STATE_EVAL(17,0,2);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
          *c1_da_out_trigger() = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
          break;
         default:
          CV_STATE_EVAL(17,0,0);
          break;
        }
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,17);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,9);
        switch(chartInstance.c1_is_SEGMENT_2) {
         case c1_IN_NEGATIVE_MOV:
          CV_STATE_EVAL(9,0,1);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
          *c1_da_out_trigger() = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
          break;
         case c1_IN_POSITIVE_MOV:
          CV_STATE_EVAL(9,0,2);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
          *c1_da_out_trigger() = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
          break;
         default:
          CV_STATE_EVAL(9,0,0);
          break;
        }
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
      break;
     case c1_IN_STOPPED:
      CV_STATE_EVAL(8,0,2);
      c1_STOPPED();
      break;
     default:
      CV_STATE_EVAL(8,0,0);
      break;
    }
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
}

static void c1_exit_internal_PRIMITIVE(void)
{
  switch(chartInstance.c1_is_PRIMITIVE) {
   case c1_IN_MOVING:
    CV_STATE_EVAL(8,1,1);
    c1_exit_internal_MOVING();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,15);
    chartInstance.c1_tp_MOVING = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,15);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
    break;
   case c1_IN_STOPPED:
    CV_STATE_EVAL(8,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,10);
    *c1_stop_trigger() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 19U);
    chartInstance.c1_tp_STOPPED = 0U;
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
    break;
   default:
    CV_STATE_EVAL(8,1,0);
    break;
  }
}

static void c1_enter_atomic_CONTROLLER(void)
{
  chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONTROLLER;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,14);
  chartInstance.c1_tp_CONTROLLER = 1U;
  *c1_operation_mode() = 2U;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  chartInstance.c1_alpha1_ref = c1_alpha_in()[0];
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_alpha1_ref, 9U);
  chartInstance.c1_alpha2_ref = c1_alpha_in()[1];
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_alpha2_ref, 13U);
  c1_set_invgeo_error(0, MAX_uint8_T);
  *c1_controller_message() = MAX_uint8_T;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_message(), 16U);
}

static void c1_enter_internal_CONTROLLER(void)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,31);
  chartInstance.c1_is_CONTROLLER = (uint8_T)c1_IN_HOLD;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
  chartInstance.c1_tp_HOLD = 1U;
  *c1_controller_message() = 4U;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_message(), 16U);
  sf_call_output_fcn_call(chartInstance.S, 1, "send_controller_message", 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,29);
  chartInstance.c1_is_HOLD = (uint8_T)c1_IN_HOLD_main;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
  chartInstance.c1_tp_HOLD_main = 1U;
}

static void c1_CONTROLLER(void)
{
  uint8_T c1_b_controller_message;
  uint8_T c1_c_controller_message;
  uint8_T c1_invgeo_error;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,14);
  if(c1__bool_s32_(CV_TRANSITION_EVAL(11U,
     (int32_T)_SFD_CCP_CALL(11,0,((*c1_async_request() == 1.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[3];
      unsigned int numTransitions=1;
      transitionList[0] = 11;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 8.0) {
        transitionList[numTransitions] = 15;
        numTransitions++;
      }
      if(*c1_async_request() == 6.0) {
        transitionList[numTransitions] = 14;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,11);
    c1_exit_internal_CONTROLLER();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,14);
    chartInstance.c1_tp_CONTROLLER = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,14);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_PRIMITIVE;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c1_tp_PRIMITIVE = 1U;
    *c1_operation_mode() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
    chartInstance.c1_tp_STOPPED = 1U;
    *c1_motor1_reference() = (real_T)chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
    *c1_motor2_reference() = (real_T)chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(15U,
     (int32_T)_SFD_CCP_CALL(15,0,((*c1_async_request() == 8.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions=1;
      transitionList[0] = 15;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 6.0) {
        transitionList[numTransitions] = 14;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,15);
    c1_exit_internal_CONTROLLER();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,14);
    chartInstance.c1_tp_CONTROLLER = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,14);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_BLUETOOTH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
    chartInstance.c1_tp_BLUETOOTH = 1U;
    *c1_operation_mode() = 4U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(14U,
     (int32_T)_SFD_CCP_CALL(14,0,((*c1_async_request() == 6.0)!=0)))) != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,14);
    c1_exit_internal_CONTROLLER();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,14);
    chartInstance.c1_tp_CONTROLLER = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,14);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else {
    switch(chartInstance.c1_is_CONTROLLER) {
     case c1_IN_HOLD:
      CV_STATE_EVAL(14,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,12);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(26U,
         (int32_T)_SFD_CCP_CALL(26,0,((*c1_async_request() == 9.0)!=0)))) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,26);
        if(c1__bool_s32_(CV_TRANSITION_EVAL(24U,
           (int32_T)_SFD_CCP_CALL(24,0,((*c1_controller_message() == 1)!=0))))
         != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,24);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
          chartInstance.c1_tp_HOLD_main = 0U;
          chartInstance.c1_is_HOLD = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
          chartInstance.c1_tp_HOLD = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
          chartInstance.c1_is_CONTROLLER = (uint8_T)c1_IN_TRAJECTORY;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
          chartInstance.c1_tp_TRAJECTORY = 1U;
          goto label_1;
        }
      }
      *c1_controller_enable() = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 1U);
      *c1_motor1_reference() = chartInstance.c1_alpha1_ref;
      _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
      *c1_motor2_reference() = chartInstance.c1_alpha2_ref;
      _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,11);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(27U,
         (int32_T)_SFD_CCP_CALL(27,0,((c1_get_invgeo_error(0) == 1)!=0)))) != 0)
      {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[3];
          unsigned int numTransitions=1;
          transitionList[0] = 27;
          sf_debug_transition_conflict_check_begin();
          if(c1_get_invgeo_error(0) == 0) {
            transitionList[numTransitions] = 16;
            numTransitions++;
          }
          if(*c1_coords_changed() != 0 == 1) {
            transitionList[numTransitions] = 25;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,27);
        *c1_controller_message() = 2U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_message(), 16U);
        c1_b_controller_message = *c1_controller_message();
        sf_mex_printf("%s =\\n", "controller_message");
        sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_b_controller_message);
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(16U,
         (int32_T)_SFD_CCP_CALL(16,0,((c1_get_invgeo_error(0) == 0)!=0)))) != 0)
      {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions=1;
          transitionList[0] = 16;
          sf_debug_transition_conflict_check_begin();
          if(*c1_coords_changed() != 0 == 1) {
            transitionList[numTransitions] = 25;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,16);
        *c1_controller_message() = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_message(), 16U);
        c1_c_controller_message = *c1_controller_message();
        sf_mex_printf("%s =\\n", "controller_message");
        sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_c_controller_message);
      } else {
        if(c1__bool_s32_(CV_TRANSITION_EVAL(25U,
           (int32_T)_SFD_CCP_CALL(25,0,((*c1_coords_changed() != 0 == 1)!=0))))
         != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,25);
          sf_mex_printf("%s\\n", "invgeo_start");
          sf_call_output_fcn_call(chartInstance.S, 0, "invgeo_start", 1);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
          chartInstance.c1_tp_HOLD_main = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
          chartInstance.c1_is_HOLD = (uint8_T)c1_IN_HOLD_main;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
          chartInstance.c1_tp_HOLD_main = 1U;
        }
        goto label_2;
      }
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,36);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
      chartInstance.c1_tp_HOLD_main = 0U;
      chartInstance.c1_is_HOLD = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
      sf_mex_printf("%s\\n", "send_controller_message");
      sf_call_output_fcn_call(chartInstance.S, 1, "send_controller_message", 1);
      c1_set_invgeo_error(0, MAX_uint8_T);
      c1_invgeo_error = c1_get_invgeo_error(0);
      sf_mex_printf("%s =\\n", "invgeo_error");
      sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_invgeo_error);
      chartInstance.c1_is_HOLD = (uint8_T)c1_IN_HOLD_main;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
      chartInstance.c1_tp_HOLD_main = 1U;
      label_2:;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
      label_1:;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
      break;
     case c1_IN_TRAJECTORY:
      CV_STATE_EVAL(14,0,2);
      break;
     default:
      CV_STATE_EVAL(14,0,0);
      break;
    }
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
}

static void c1_exit_internal_CONTROLLER(void)
{
  switch(chartInstance.c1_is_CONTROLLER) {
   case c1_IN_HOLD:
    CV_STATE_EVAL(14,1,1);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
    chartInstance.c1_tp_HOLD_main = 0U;
    chartInstance.c1_is_HOLD = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_HOLD = 0U;
    chartInstance.c1_is_CONTROLLER = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    break;
   case c1_IN_TRAJECTORY:
    CV_STATE_EVAL(14,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,13);
    chartInstance.c1_tp_TRAJECTORY = 0U;
    chartInstance.c1_is_CONTROLLER = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
    break;
   default:
    CV_STATE_EVAL(14,1,0);
    break;
  }
}

static void c1_exit_internal_MOVING(void)
{
  switch(chartInstance.c1_is_SEGMENT_2) {
   case c1_IN_NEGATIVE_MOV:
    CV_STATE_EVAL(9,1,1);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
    chartInstance.c1_b_tp_NEGATIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    break;
   case c1_IN_POSITIVE_MOV:
    CV_STATE_EVAL(9,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
    chartInstance.c1_b_tp_POSITIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
    break;
   default:
    CV_STATE_EVAL(9,1,0);
    break;
  }
  _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,9);
  chartInstance.c1_tp_SEGMENT_2 = 0U;
  chartInstance.c1_is_active_SEGMENT_2 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG,9);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
  switch(chartInstance.c1_is_SEGMENT_1) {
   case c1_IN_NEGATIVE_MOV:
    CV_STATE_EVAL(17,1,1);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,16);
    chartInstance.c1_tp_NEGATIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,16);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
    break;
   case c1_IN_POSITIVE_MOV:
    CV_STATE_EVAL(17,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
    chartInstance.c1_tp_POSITIVE_MOV = 0U;
    chartInstance.c1_is_SEGMENT_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
    break;
   default:
    CV_STATE_EVAL(17,1,0);
    break;
  }
  _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,17);
  chartInstance.c1_tp_SEGMENT_1 = 0U;
  chartInstance.c1_is_active_SEGMENT_1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG,17);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,17);
}

static void c1_CONFIG(void)
{
  uint8_T c1_b_sync_command;
  uint8_T c1_c_sync_command;
  uint8_T c1_d_sync_command;
  uint8_T c1_e_sync_command;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,6);
  if(c1__bool_s32_(CV_TRANSITION_EVAL(0U,
     (int32_T)_SFD_CCP_CALL(0,0,((*c1_async_request() == 1.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[7];
      unsigned int numTransitions=1;
      transitionList[0] = 0;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 2.0) {
        transitionList[numTransitions] = 2;
        numTransitions++;
      }
      if(*c1_async_request() == 8.0) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }
      if(*c1_async_request() == 7.0) {
        transitionList[numTransitions] = 13;
        numTransitions++;
      }
      if(*c1_async_request() == 5.0) {
        transitionList[numTransitions] = 5;
        numTransitions++;
      }
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 1;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 23;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_PRIMITIVE;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
    chartInstance.c1_tp_PRIMITIVE = 1U;
    *c1_operation_mode() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
    chartInstance.c1_is_PRIMITIVE = (uint8_T)c1_IN_STOPPED;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
    chartInstance.c1_tp_STOPPED = 1U;
    *c1_motor1_reference() = (real_T)chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor1_reference(), 22U);
    *c1_motor2_reference() = (real_T)chartInstance.c1_motor_stopped_value;
    _SFD_DATA_RANGE_CHECK(*c1_motor2_reference(), 17U);
    *c1_da_out_trigger() = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_da_out_trigger(), 6U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(2U,
     (int32_T)_SFD_CCP_CALL(2,0,((*c1_async_request() == 2.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[6];
      unsigned int numTransitions=1;
      transitionList[0] = 2;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 8.0) {
        transitionList[numTransitions] = 19;
        numTransitions++;
      }
      if(*c1_async_request() == 7.0) {
        transitionList[numTransitions] = 13;
        numTransitions++;
      }
      if(*c1_async_request() == 5.0) {
        transitionList[numTransitions] = 5;
        numTransitions++;
      }
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 1;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 23;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    c1_enter_atomic_CONTROLLER();
    c1_enter_internal_CONTROLLER();
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(19U,
     (int32_T)_SFD_CCP_CALL(19,0,((*c1_async_request() == 8.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[5];
      unsigned int numTransitions=1;
      transitionList[0] = 19;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 7.0) {
        transitionList[numTransitions] = 13;
        numTransitions++;
      }
      if(*c1_async_request() == 5.0) {
        transitionList[numTransitions] = 5;
        numTransitions++;
      }
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 1;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 23;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,19);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_BLUETOOTH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
    chartInstance.c1_tp_BLUETOOTH = 1U;
    *c1_operation_mode() = 4U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(13U,
     (int32_T)_SFD_CCP_CALL(13,0,((*c1_async_request() == 7.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[4];
      unsigned int numTransitions=1;
      transitionList[0] = 13;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 5.0) {
        transitionList[numTransitions] = 5;
        numTransitions++;
      }
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 1;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 23;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,13);
    *c1_sync_command() = 4U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 11U);
    c1_b_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_b_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(5U,
     (int32_T)_SFD_CCP_CALL(5,0,((*c1_async_request() == 5.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[3];
      unsigned int numTransitions=1;
      transitionList[0] = 5;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 4.0) {
        transitionList[numTransitions] = 1;
        numTransitions++;
      }
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 23;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
    *c1_sync_command() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 11U);
    c1_c_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_c_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(1U,
     (int32_T)_SFD_CCP_CALL(1,0,((*c1_async_request() == 4.0)!=0)))) != 0) {
    if(sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions=1;
      transitionList[0] = 1;
      sf_debug_transition_conflict_check_begin();
      if(*c1_async_request() == 3.0) {
        transitionList[numTransitions] = 23;
        numTransitions++;
      }
      sf_debug_transition_conflict_check_end();
      if(numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
    *c1_sync_command() = 2U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 11U);
    c1_d_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_d_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else if(c1__bool_s32_(CV_TRANSITION_EVAL(23U,
     (int32_T)_SFD_CCP_CALL(23,0,((*c1_async_request() == 3.0)!=0)))) != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,23);
    *c1_sync_command() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 11U);
    c1_e_sync_command = *c1_sync_command();
    sf_mex_printf("%s =\\n", "sync_command");
    sf_mex_call("disp", 0U, 1U, 6, (real_T)c1_e_sync_command);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_CONFIG = 0U;
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_CONFIG;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
    chartInstance.c1_tp_CONFIG = 1U;
    *c1_operation_mode() = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_operation_mode(), 12U);
  } else {
    *c1_controller_enable() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 1U);
    *c1_sync_command() = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_sync_command(), 11U);
  }
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
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

static real_T *c1_motor1_reference(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
}

static real_T *c1_motor2_reference(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
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

static real_T *c1_alpha_in(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
}

static uint8_T *c1_controller_message(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 11);
}

static boolean_T *c1_coords_changed(void)
{
  return (boolean_T *)ssGetInputPortSignal(chartInstance.S, 5);
}

static void init_test_point_addr_map(void)
{
  chartInstance.c1_testPointAddrMap[0] = &chartInstance.c1_alpha1_ref;
  chartInstance.c1_testPointAddrMap[1] = &chartInstance.c1_alpha2_ref;
  chartInstance.c1_testPointAddrMap[2] = &chartInstance.c1_tp_INIT;
  chartInstance.c1_testPointAddrMap[3] = &chartInstance.c1_tp_INIT_ACK;
  chartInstance.c1_testPointAddrMap[4] = &chartInstance.c1_tp_OPERATION;
  chartInstance.c1_testPointAddrMap[5] = &chartInstance.c1_tp_BLUETOOTH;
  chartInstance.c1_testPointAddrMap[6] = &chartInstance.c1_tp_CONFIG;
  chartInstance.c1_testPointAddrMap[7] = &chartInstance.c1_tp_CONTROLLER;
  chartInstance.c1_testPointAddrMap[8] = &chartInstance.c1_tp_HOLD;
  chartInstance.c1_testPointAddrMap[9] = &chartInstance.c1_tp_HOLD_main;
  chartInstance.c1_testPointAddrMap[10] = &chartInstance.c1_tp_TRAJECTORY;
  chartInstance.c1_testPointAddrMap[11] = &chartInstance.c1_tp_PRIMITIVE;
  chartInstance.c1_testPointAddrMap[12] = &chartInstance.c1_tp_MOVING;
  chartInstance.c1_testPointAddrMap[13] = &chartInstance.c1_tp_SEGMENT_1;
  chartInstance.c1_testPointAddrMap[14] = &chartInstance.c1_tp_NEGATIVE_MOV;
  chartInstance.c1_testPointAddrMap[15] = &chartInstance.c1_tp_POSITIVE_MOV;
  chartInstance.c1_testPointAddrMap[16] = &chartInstance.c1_tp_SEGMENT_2;
  chartInstance.c1_testPointAddrMap[17] = &chartInstance.c1_b_tp_NEGATIVE_MOV;
  chartInstance.c1_testPointAddrMap[18] = &chartInstance.c1_b_tp_POSITIVE_MOV;
  chartInstance.c1_testPointAddrMap[19] = &chartInstance.c1_tp_STOPPED;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c1_testPointMappingInfo;
}

static uint8_T c1_get_invgeo_error(int32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance.S, 0, NULL, c1_b);
  return chartInstance.c1_invgeo_error_address[c1_b];
}

static void c1_set_invgeo_error(int32_T c1_b, uint8_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance.S, 0, NULL, c1_b);
  chartInstance.c1_invgeo_error_address[c1_b] = c1_c;
}

static void init_dsm_address_info(void)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance.S, "invgeo_error", (void
    **)&chartInstance.c1_invgeo_error_address, &chartInstance.
   c1_invgeo_error_index);
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
  fwrite(&chartInstance.c1_tp_BLUETOOTH, 1,
   sizeof(chartInstance.c1_tp_BLUETOOTH), c1_file);
  fwrite(&chartInstance.c1_tp_HOLD, 1, sizeof(chartInstance.c1_tp_HOLD),
   c1_file);
  fwrite(&chartInstance.c1_tp_TRAJECTORY, 1,
   sizeof(chartInstance.c1_tp_TRAJECTORY), c1_file);
  fwrite(&chartInstance.c1_tp_HOLD_main, 1,
   sizeof(chartInstance.c1_tp_HOLD_main), c1_file);
  fwrite(&chartInstance.c1_is_active_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_active_c1_MPC_framework), c1_file);
  fwrite(&chartInstance.c1_is_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_c1_MPC_framework), c1_file);
  fwrite(&chartInstance.c1_is_OPERATION, 1,
   sizeof(chartInstance.c1_is_OPERATION), c1_file);
  fwrite(&chartInstance.c1_is_PRIMITIVE, 1,
   sizeof(chartInstance.c1_is_PRIMITIVE), c1_file);
  fwrite(&chartInstance.c1_is_CONTROLLER, 1,
   sizeof(chartInstance.c1_is_CONTROLLER), c1_file);
  fwrite(&chartInstance.c1_is_active_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_1), c1_file);
  fwrite(&chartInstance.c1_is_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_SEGMENT_1), c1_file);
  fwrite(&chartInstance.c1_is_active_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_2), c1_file);
  fwrite(&chartInstance.c1_is_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_SEGMENT_2), c1_file);
  fwrite(&chartInstance.c1_is_HOLD, 1, sizeof(chartInstance.c1_is_HOLD),
   c1_file);
  fwrite(&chartInstance.c1_alpha1_ref, 1, sizeof(chartInstance.c1_alpha1_ref),
   c1_file);
  fwrite(&chartInstance.c1_alpha2_ref, 1, sizeof(chartInstance.c1_alpha2_ref),
   c1_file);
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
  fread(&chartInstance.c1_tp_BLUETOOTH, 1,
   sizeof(chartInstance.c1_tp_BLUETOOTH), c1_file);
  fread(&chartInstance.c1_tp_HOLD, 1, sizeof(chartInstance.c1_tp_HOLD), c1_file);
  fread(&chartInstance.c1_tp_TRAJECTORY, 1,
   sizeof(chartInstance.c1_tp_TRAJECTORY), c1_file);
  fread(&chartInstance.c1_tp_HOLD_main, 1,
   sizeof(chartInstance.c1_tp_HOLD_main), c1_file);
  fread(&chartInstance.c1_is_active_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_active_c1_MPC_framework), c1_file);
  fread(&chartInstance.c1_is_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_c1_MPC_framework), c1_file);
  fread(&chartInstance.c1_is_OPERATION, 1,
   sizeof(chartInstance.c1_is_OPERATION), c1_file);
  fread(&chartInstance.c1_is_PRIMITIVE, 1,
   sizeof(chartInstance.c1_is_PRIMITIVE), c1_file);
  fread(&chartInstance.c1_is_CONTROLLER, 1,
   sizeof(chartInstance.c1_is_CONTROLLER), c1_file);
  fread(&chartInstance.c1_is_active_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_1), c1_file);
  fread(&chartInstance.c1_is_SEGMENT_1, 1,
   sizeof(chartInstance.c1_is_SEGMENT_1), c1_file);
  fread(&chartInstance.c1_is_active_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_active_SEGMENT_2), c1_file);
  fread(&chartInstance.c1_is_SEGMENT_2, 1,
   sizeof(chartInstance.c1_is_SEGMENT_2), c1_file);
  fread(&chartInstance.c1_is_HOLD, 1, sizeof(chartInstance.c1_is_HOLD), c1_file);
  fread(&chartInstance.c1_alpha1_ref, 1, sizeof(chartInstance.c1_alpha1_ref),
   c1_file);
  fread(&chartInstance.c1_alpha2_ref, 1, sizeof(chartInstance.c1_alpha2_ref),
   c1_file);
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_MPC_framework_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3209927377U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3204942018U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(781710472U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(857934662U);
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
    pr[0] = (double)(2632017680U);
    pr[1] = (double)(3692854582U);
    pr[2] = (double)(530783830U);
    pr[3] = (double)(2251246721U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);
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
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
      mxSetField(mxData,4,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }
    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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
    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }
    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
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
         18,
         37,
         25,
         2,
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
           2,
           2,
           2);

          _SFD_SET_DATA_PROPS(24,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_value",0);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_enable",0);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_ack_sync",0);
          _SFD_SET_DATA_PROPS(20,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_ack_async",0);
          _SFD_SET_DATA_PROPS(23,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_trigger",0);
          _SFD_SET_DATA_PROPS(19,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"stop_trigger",0);
          _SFD_SET_DATA_PROPS(10,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"primitive_button",0);
          _SFD_SET_DATA_PROPS(22,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"motor1_reference",0);
          _SFD_SET_DATA_PROPS(17,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"motor2_reference",0);
          _SFD_SET_DATA_PROPS(5,10,0,0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor_stopped_value",0);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"controller_enable",0);
          _SFD_SET_DATA_PROPS(0,10,0,0,SF_UINT8,0,NULL,1,0,8,0,1,0,"init_1_message",0);
          _SFD_SET_DATA_PROPS(2,10,0,0,SF_UINT8,0,NULL,1,0,8,0,1,0,"init_2_message",0);
          _SFD_SET_DATA_PROPS(8,10,0,0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor_positive_value",0);
          _SFD_SET_DATA_PROPS(14,10,0,0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor_negative_value",0);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"da_out_trigger",0);
          _SFD_SET_DATA_PROPS(21,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"async_request",0);
          _SFD_SET_DATA_PROPS(12,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"operation_mode",0);
          _SFD_SET_DATA_PROPS(11,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"sync_command",0);
          _SFD_SET_DATA_PROPS(9,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"alpha1_ref",0);
          _SFD_SET_DATA_PROPS(13,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"alpha2_ref",0);
          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 2;
            _SFD_SET_DATA_PROPS(15,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,1.0,0,"alpha_in",0);
          }
          _SFD_SET_DATA_PROPS(16,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"controller_message",0);
          _SFD_SET_DATA_PROPS(4,11,0,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"invgeo_error",0);
          _SFD_SET_DATA_PROPS(18,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"coords_changed",0);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(0,2);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(15,1,0);
          _SFD_STATE_INFO(17,0,1);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(9,0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,4);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_CH_SUBSTATE_INDEX(2,7);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(7,4);
          _SFD_ST_SUBSTATE_INDEX(7,0,1);
          _SFD_ST_SUBSTATE_INDEX(7,1,6);
          _SFD_ST_SUBSTATE_INDEX(7,2,14);
          _SFD_ST_SUBSTATE_INDEX(7,3,8);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(14,2);
          _SFD_ST_SUBSTATE_INDEX(14,0,12);
          _SFD_ST_SUBSTATE_INDEX(14,1,13);
          _SFD_ST_SUBSTATE_COUNT(12,1);
          _SFD_ST_SUBSTATE_INDEX(12,0,11);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(8,2);
          _SFD_ST_SUBSTATE_INDEX(8,0,15);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_COUNT(15,2);
          _SFD_ST_SUBSTATE_INDEX(15,0,17);
          _SFD_ST_SUBSTATE_INDEX(15,1,9);
          _SFD_ST_SUBSTATE_COUNT(17,2);
          _SFD_ST_SUBSTATE_INDEX(17,0,16);
          _SFD_ST_SUBSTATE_INDEX(17,1,3);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(9,2);
          _SFD_ST_SUBSTATE_INDEX(9,0,0);
          _SFD_ST_SUBSTATE_INDEX(9,1,5);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
        }
        _SFD_CV_INIT_CHART(3,1,0,0);
        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(7,4,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(14,2,1,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(12,1,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(8,2,1,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(15,2,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(17,2,1,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(9,2,1,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1,21};
          static unsigned int sEndGuardMap[] = {17,38};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(22,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(33,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(30,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(34,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
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
          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(14,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(23,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
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
          _SFD_CV_INIT_TRANS(15,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
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
          _SFD_CV_INIT_TRANS(35,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(21,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {18};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(25,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(27,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(26,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {22};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(24,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);

        _SFD_TRANS_COV_WTS(20,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(20,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(22,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1,21};
          static unsigned int sEndGuardMap[] = {17,38};
          _SFD_TRANS_COV_MAPS(22,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
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
        _SFD_TRANS_COV_WTS(32,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(32,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(9,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(9,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(33,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(33,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(30,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(30,
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
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(12,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(34,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {20};
          _SFD_TRANS_COV_MAPS(34,
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
        _SFD_TRANS_COV_WTS(11,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(11,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(7,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(7,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(14,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(14,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(0,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(2,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(28,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(28,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(18,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(18,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(23,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(23,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(1,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(1,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(5,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(5,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(13,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(13,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(15,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(15,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(17,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(17,
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
        _SFD_TRANS_COV_WTS(35,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(35,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(6,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(6,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(21,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(21,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(31,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(31,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(25,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {18};
          _SFD_TRANS_COV_MAPS(25,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(27,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          _SFD_TRANS_COV_MAPS(27,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(16,0,1,1,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {16};
          _SFD_TRANS_COV_MAPS(16,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(4,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(4,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(36,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(36,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(26,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {17};
          _SFD_TRANS_COV_MAPS(26,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(24,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {22};
          _SFD_TRANS_COV_MAPS(24,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(29,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(29,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(24U, c1_init_out_value());
        _SFD_SET_DATA_VALUE_PTR(3U, c1_init_out_enable());
        _SFD_SET_DATA_VALUE_PTR(7U, c1_init_ack_sync());
        _SFD_SET_DATA_VALUE_PTR(20U, c1_init_ack_async());
        _SFD_SET_DATA_VALUE_PTR(23U, c1_init_out_trigger());
        _SFD_SET_DATA_VALUE_PTR(19U, c1_stop_trigger());
        _SFD_SET_DATA_VALUE_PTR(10U, c1_primitive_button());
        _SFD_SET_DATA_VALUE_PTR(22U, c1_motor1_reference());
        _SFD_SET_DATA_VALUE_PTR(17U, c1_motor2_reference());
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance.c1_motor_stopped_value);
        _SFD_SET_DATA_VALUE_PTR(1U, c1_controller_enable());
        _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance.c1_init_1_message);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance.c1_init_2_message);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance.c1_motor_positive_value);
        _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance.c1_motor_negative_value);
        _SFD_SET_DATA_VALUE_PTR(6U, c1_da_out_trigger());
        _SFD_SET_DATA_VALUE_PTR(21U, c1_async_request());
        _SFD_SET_DATA_VALUE_PTR(12U, c1_operation_mode());
        _SFD_SET_DATA_VALUE_PTR(11U, c1_sync_command());
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance.c1_alpha1_ref);
        _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance.c1_alpha2_ref);
        _SFD_SET_DATA_VALUE_PTR(15U, c1_alpha_in());
        _SFD_SET_DATA_VALUE_PTR(16U, c1_controller_message());
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance.c1_invgeo_error_address);
        _SFD_SET_DATA_VALUE_PTR(18U, c1_coords_changed());
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
    sf_mark_output_events_with_multiple_callers(S,"MPC_framework",1,2);
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_framework",1,6);
      sf_mark_chart_reusable_outputs(S,"MPC_framework",1,11);
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

  ssSetChecksum0(S,(2926322338U));
  ssSetChecksum1(S,(1950450077U));
  ssSetChecksum2(S,(374480065U));
  ssSetChecksum3(S,(3481261410U));

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
  {"real_T", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0},
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
  {0, 0,"StateflowChart/alpha1_ref", "alpha1_ref", 0, 0, 0, 0, 0},
  {1, 0,"StateflowChart/alpha2_ref", "alpha2_ref", 0, 0, 0, 0, 0},
  {2, 0, "StateflowChart/INIT", "INIT", 0, 1, 0, 0, 0},
  {3, 0, "StateflowChart/INIT_ACK", "INIT_ACK", 0, 1, 0, 0, 0},
  {4, 0, "StateflowChart/OPERATION", "OPERATION", 0, 1, 0, 0, 0},
  {5, 0, "StateflowChart/OPERATION.BLUETOOTH", "BLUETOOTH", 0, 1, 0, 0, 0},
  {6, 0, "StateflowChart/OPERATION.CONFIG", "CONFIG", 0, 1, 0, 0, 0},
  {7, 0, "StateflowChart/OPERATION.CONTROLLER", "CONTROLLER", 0, 1, 0, 0, 0},
  {8, 0, "StateflowChart/OPERATION.CONTROLLER.HOLD", "HOLD", 0, 1, 0, 0, 0},
  {9, 0, "StateflowChart/OPERATION.CONTROLLER.HOLD.HOLD_main", "HOLD_main", 0,
    1, 0, 0, 0},
  {10, 0, "StateflowChart/OPERATION.CONTROLLER.TRAJECTORY", "TRAJECTORY", 0, 1,
    0, 0, 0},
  {11, 0, "StateflowChart/OPERATION.PRIMITIVE", "PRIMITIVE", 0, 1, 0, 0, 0},
  {12, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING", "MOVING", 0, 1, 0, 0, 0},
  {13, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_1", "SEGMENT_1", 0,
    1, 0, 0, 0},
  {14, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_1.NEGATIVE_MOV",
    "NEGATIVE_MOV", 0, 1, 0, 0, 0},
  {15, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_1.POSITIVE_MOV",
    "POSITIVE_MOV", 0, 1, 0, 0, 0},
  {16, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_2", "SEGMENT_2", 0,
    1, 0, 0, 0},
  {17, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_2.NEGATIVE_MOV",
    "NEGATIVE_MOV", 0, 1, 0, 0, 0},
  {18, 0, "StateflowChart/OPERATION.PRIMITIVE.MOVING.SEGMENT_2.POSITIVE_MOV",
    "POSITIVE_MOV", 0, 1, 0, 0, 0},
  {19, 0, "StateflowChart/OPERATION.PRIMITIVE.STOPPED", "STOPPED", 0, 1, 0, 0, 0}
};

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                   /* Block signals Array  */
    20                                  /* Num Block IO signals */
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

