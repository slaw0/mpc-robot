/* Include files */
#include "MPC_framework_sfun.h"
#include "c1_MPC_framework.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "MPC_framework_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_event_stop_button            (0U)
#define c1_IN_NO_ACTIVE_CHILD           (0)
#define c1_IN_INIT                      (1)
#define c1_IN_INIT_ACK                  (2)
#define c1_IN_OPERATION                 (3)
#define c1_IN_MOVING                    (1)
#define c1_IN_STOPPED                   (2)
#define c1_IN_POSITIVE_MOVEMENT         (2)
#define c1_IN_NEGATIVE_MOVEMENT         (1)

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
static void c1_exit_internal_MOVING(void);
static void c1_broadcast_stop_button(void);
static boolean_T c1__bool_s32_(int32_T c1_b);
static uint16_T c1__u16_d_(real_T c1_b);
static uint8_T *c1_init_out_value(void);
static uint8_T *c1_init_out_enable(void);
static uint8_T *c1_init_ack_sync(void);
static uint8_T *c1_init_ack_async(void);
static uint8_T *c1_init_out_trigger(void);
static uint8_T *c1_stop_trigger(void);
static uint8_T *c1_positive_button(void);
static uint8_T *c1_negative_button(void);
static uint16_T *c1_motor1_reference(void);
static uint16_T *c1_motor2_reference(void);
static uint8_T *c1_controller_enable(void);
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
  chartInstance.c1_is_MOVING = 0U;
  chartInstance.c1_tp_MOVING = 0U;
  chartInstance.c1_tp_NEGATIVE_MOVEMENT = 0U;
  chartInstance.c1_tp_POSITIVE_MOVEMENT = 0U;
  chartInstance.c1_tp_STOPPED = 0U;
  chartInstance.c1_is_active_c1_MPC_framework = 0U;
  chartInstance.c1_is_c1_MPC_framework = 0U;
  chartInstance.c1_motor_stopped_value = 32768.0;
  chartInstance.c1_init_1_message = 0U;
  chartInstance.c1_init_2_message = 0U;
  chartInstance.c1_motor_positive_value = 40960.0;
  chartInstance.c1_motor_negative_value = 24576.0;
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
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
  chartInstance.c1_is_active_c1_MPC_framework = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
  chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_INIT;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
  chartInstance.c1_tp_INIT = 1U;
  *c1_init_out_value() = chartInstance.c1_init_1_message;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 14U);
  *c1_init_out_enable() = 1U;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 2U);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
}

static void initialize_params_c1_MPC_framework(void)
{
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
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 14U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_ack_sync(), 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_ack_async(), 10U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_trigger(), 13U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_positive_button(), 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_negative_button(), 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 11U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_motor_stopped_value, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 1U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_init_1_message, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance.c1_init_2_message, 9U);
  c1_broadcast_stop_button();
  sf_debug_check_for_state_inconsistency(_MPC_frameworkMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c1_exit_internal_MOVING(void)
{
  switch(chartInstance.c1_is_MOVING) {
   case c1_IN_NEGATIVE_MOVEMENT:
    CV_STATE_EVAL(4,0,1);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
    chartInstance.c1_tp_NEGATIVE_MOVEMENT = 0U;
    chartInstance.c1_is_MOVING = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
    break;
   case c1_IN_POSITIVE_MOVEMENT:
    CV_STATE_EVAL(4,0,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_POSITIVE_MOVEMENT = 0U;
    chartInstance.c1_is_MOVING = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    break;
   default:
    CV_STATE_EVAL(4,0,0);
    break;
  }
}

static void c1_broadcast_stop_button(void)
{
  uint8_T c1_previousEvent;
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = c1_event_stop_button;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG,c1_event_stop_button);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  switch(chartInstance.c1_is_c1_MPC_framework) {
   case c1_IN_INIT:
    CV_CHART_EVAL(0,0,1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
    if(c1__bool_s32_(CV_TRANSITION_EVAL(2U,
       (_SFD_CCP_CALL(2,0,((*c1_init_ack_sync() == 1)!=0)) != 0) &&
       (_SFD_CCP_CALL(2,1,((*
           c1_init_ack_async() == 1)!=0)) != 0))) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,5);
      chartInstance.c1_tp_INIT = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
      chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_INIT_ACK;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
      chartInstance.c1_tp_INIT_ACK = 1U;
      *c1_init_out_enable() = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_enable(), 2U);
      *c1_init_out_value() = chartInstance.c1_init_2_message;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_value(), 14U);
      *c1_init_out_trigger() = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_init_out_trigger(), 13U);
    }
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
    break;
   case c1_IN_INIT_ACK:
    CV_CHART_EVAL(0,0,2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
    chartInstance.c1_tp_INIT_ACK = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    chartInstance.c1_is_c1_MPC_framework = (uint8_T)c1_IN_OPERATION;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
    chartInstance.c1_tp_OPERATION = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_STOPPED;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
    chartInstance.c1_tp_STOPPED = 1U;
    *c1_motor1_reference() = c1__u16_d_(chartInstance.c1_motor_stopped_value);
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 11U);
    *c1_motor2_reference() = c1__u16_d_(chartInstance.c1_motor_stopped_value);
    _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 12U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    break;
   case c1_IN_OPERATION:
    CV_CHART_EVAL(0,0,3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
    *c1_controller_enable() = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_controller_enable(), 1U);
    switch(chartInstance.c1_is_OPERATION) {
     case c1_IN_MOVING:
      CV_STATE_EVAL(2,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(3U,
         (int32_T)_SFD_CCP_CALL(3,0,((_sfEvent_ == c1_event_stop_button)!=0))))
       != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
        c1_exit_internal_MOVING();
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
        chartInstance.c1_tp_MOVING = 0U;
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
        *c1_stop_trigger() = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 8U);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_STOPPED;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
        chartInstance.c1_tp_STOPPED = 1U;
        *c1_motor1_reference() =
          c1__u16_d_(chartInstance.c1_motor_stopped_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 11U);
        *c1_motor2_reference() =
          c1__u16_d_(chartInstance.c1_motor_stopped_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 12U);
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(8U,
         (int32_T)_SFD_CCP_CALL(8,0,((*c1_negative_button() == 2)!=0)))) != 0) {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions=1;
          transitionList[0] = 8;
          sf_debug_transition_conflict_check_begin();
          if(*c1_positive_button() == 2) {
            transitionList[numTransitions] = 4;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
        c1_exit_internal_MOVING();
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
        chartInstance.c1_tp_MOVING = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_STOPPED;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
        chartInstance.c1_tp_STOPPED = 1U;
        *c1_motor1_reference() =
          c1__u16_d_(chartInstance.c1_motor_stopped_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 11U);
        *c1_motor2_reference() =
          c1__u16_d_(chartInstance.c1_motor_stopped_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 12U);
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(4U,
         (int32_T)_SFD_CCP_CALL(4,0,((*c1_positive_button() == 2)!=0)))) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
        switch(chartInstance.c1_is_MOVING) {
         case c1_IN_NEGATIVE_MOVEMENT:
          CV_STATE_EVAL(4,0,1);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
          chartInstance.c1_tp_NEGATIVE_MOVEMENT = 0U;
          chartInstance.c1_is_MOVING = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
          break;
         case c1_IN_POSITIVE_MOVEMENT:
          CV_STATE_EVAL(4,0,2);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
          chartInstance.c1_tp_POSITIVE_MOVEMENT = 0U;
          chartInstance.c1_is_MOVING = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
          break;
         default:
          CV_STATE_EVAL(4,0,0);
          break;
        }
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,4);
        chartInstance.c1_tp_MOVING = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_STOPPED;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
        chartInstance.c1_tp_STOPPED = 1U;
        *c1_motor1_reference() =
          c1__u16_d_(chartInstance.c1_motor_stopped_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 11U);
        *c1_motor2_reference() =
          c1__u16_d_(chartInstance.c1_motor_stopped_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor2_reference(), 12U);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
      break;
     case c1_IN_STOPPED:
      CV_STATE_EVAL(2,0,2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
      if(c1__bool_s32_(CV_TRANSITION_EVAL(1U,
         (int32_T)_SFD_CCP_CALL(1,0,((*c1_positive_button() == 1)!=0)))) != 0) {
        if(sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions=1;
          transitionList[0] = 1;
          sf_debug_transition_conflict_check_begin();
          if(*c1_negative_button() == 1) {
            transitionList[numTransitions] = 6;
            numTransitions++;
          }
          sf_debug_transition_conflict_check_end();
          if(numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
        *c1_stop_trigger() = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 8U);
        chartInstance.c1_tp_STOPPED = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_MOVING;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
        chartInstance.c1_tp_MOVING = 1U;
        chartInstance.c1_is_MOVING = (uint8_T)c1_IN_POSITIVE_MOVEMENT;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
        chartInstance.c1_tp_POSITIVE_MOVEMENT = 1U;
        *c1_motor1_reference() =
          c1__u16_d_(chartInstance.c1_motor_positive_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 11U);
      } else if(c1__bool_s32_(CV_TRANSITION_EVAL(6U,
         (int32_T)_SFD_CCP_CALL(6,0,((*c1_negative_button() == 1)!=0)))) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,3);
        *c1_stop_trigger() = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_stop_trigger(), 8U);
        chartInstance.c1_tp_STOPPED = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,3);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
        chartInstance.c1_is_OPERATION = (uint8_T)c1_IN_MOVING;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
        chartInstance.c1_tp_MOVING = 1U;
        chartInstance.c1_is_MOVING = (uint8_T)c1_IN_NEGATIVE_MOVEMENT;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
        chartInstance.c1_tp_NEGATIVE_MOVEMENT = 1U;
        *c1_motor1_reference() =
          c1__u16_d_(chartInstance.c1_motor_negative_value);
        _SFD_DATA_RANGE_CHECK((real_T)*c1_motor1_reference(), 11U);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
      break;
     default:
      CV_STATE_EVAL(2,0,0);
      break;
    }
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    break;
   default:
    CV_CHART_EVAL(0,0,0);
    break;
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG,c1_event_stop_button);
  _sfEvent_ = c1_previousEvent;
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

static uint16_T c1__u16_d_(real_T c1_b)
{
  uint16_T c1_a;
  c1_a = (uint16_T)c1_b;
  if((real_T)c1_a != (c1_b < 0.0 ? ceil(c1_b) : floor(c1_b))) {
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

static uint8_T *c1_positive_button(void)
{
  return (uint8_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static uint8_T *c1_negative_button(void)
{
  return (uint8_T *)ssGetInputPortSignal(chartInstance.S, 3);
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

static void init_test_point_addr_map(void)
{
  chartInstance.c1_testPointAddrMap[0] = &chartInstance.c1_tp_INIT;
  chartInstance.c1_testPointAddrMap[1] = &chartInstance.c1_tp_INIT_ACK;
  chartInstance.c1_testPointAddrMap[2] = &chartInstance.c1_tp_OPERATION;
  chartInstance.c1_testPointAddrMap[3] = &chartInstance.c1_tp_MOVING;
  chartInstance.c1_testPointAddrMap[4] = &chartInstance.c1_tp_NEGATIVE_MOVEMENT;
  chartInstance.c1_testPointAddrMap[5] = &chartInstance.c1_tp_POSITIVE_MOVEMENT;
  chartInstance.c1_testPointAddrMap[6] = &chartInstance.c1_tp_STOPPED;
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
  fwrite(&chartInstance.c1_tp_MOVING, 1, sizeof(chartInstance.c1_tp_MOVING),
   c1_file);
  fwrite(&chartInstance.c1_tp_STOPPED, 1, sizeof(chartInstance.c1_tp_STOPPED),
   c1_file);
  fwrite(&chartInstance.c1_tp_POSITIVE_MOVEMENT, 1,
   sizeof(chartInstance.c1_tp_POSITIVE_MOVEMENT), c1_file);
  fwrite(&chartInstance.c1_tp_NEGATIVE_MOVEMENT, 1,
   sizeof(chartInstance.c1_tp_NEGATIVE_MOVEMENT), c1_file);
  fwrite(&chartInstance.c1_is_active_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_active_c1_MPC_framework), c1_file);
  fwrite(&chartInstance.c1_is_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_c1_MPC_framework), c1_file);
  fwrite(&chartInstance.c1_is_OPERATION, 1,
   sizeof(chartInstance.c1_is_OPERATION), c1_file);
  fwrite(&chartInstance.c1_is_MOVING, 1, sizeof(chartInstance.c1_is_MOVING),
   c1_file);
}

static void sf_load_state_c1_MPC_framework(FILE *c1_file)
{
  fread(&chartInstance.c1_tp_INIT, 1, sizeof(chartInstance.c1_tp_INIT), c1_file);
  fread(&chartInstance.c1_tp_INIT_ACK, 1, sizeof(chartInstance.c1_tp_INIT_ACK),
   c1_file);
  fread(&chartInstance.c1_tp_OPERATION, 1,
   sizeof(chartInstance.c1_tp_OPERATION), c1_file);
  fread(&chartInstance.c1_tp_MOVING, 1, sizeof(chartInstance.c1_tp_MOVING),
   c1_file);
  fread(&chartInstance.c1_tp_STOPPED, 1, sizeof(chartInstance.c1_tp_STOPPED),
   c1_file);
  fread(&chartInstance.c1_tp_POSITIVE_MOVEMENT, 1,
   sizeof(chartInstance.c1_tp_POSITIVE_MOVEMENT), c1_file);
  fread(&chartInstance.c1_tp_NEGATIVE_MOVEMENT, 1,
   sizeof(chartInstance.c1_tp_NEGATIVE_MOVEMENT), c1_file);
  fread(&chartInstance.c1_is_active_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_active_c1_MPC_framework), c1_file);
  fread(&chartInstance.c1_is_c1_MPC_framework, 1,
   sizeof(chartInstance.c1_is_c1_MPC_framework), c1_file);
  fread(&chartInstance.c1_is_OPERATION, 1,
   sizeof(chartInstance.c1_is_OPERATION), c1_file);
  fread(&chartInstance.c1_is_MOVING, 1, sizeof(chartInstance.c1_is_MOVING),
   c1_file);
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_MPC_framework_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(551821747U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1782427759U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(247696008U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2878041026U);
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
    pr[0] = (double)(869972484U);
    pr[1] = (double)(1612770957U);
    pr[2] = (double)(2348277248U);
    pr[3] = (double)(2563020838U);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);
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
         7,
         9,
         16,
         1,
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
           1,
           1,
           1);

          _SFD_SET_DATA_PROPS(14,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_value",0);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_enable",0);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_ack_sync",0);
          _SFD_SET_DATA_PROPS(10,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_ack_async",0);
          _SFD_SET_DATA_PROPS(13,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"init_out_trigger",0);
          _SFD_SET_DATA_PROPS(8,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"stop_trigger",0);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"positive_button",0);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"negative_button",0);
          _SFD_SET_DATA_PROPS(11,2,0,1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor1_reference",0);
          _SFD_SET_DATA_PROPS(12,2,0,1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,"motor2_reference",0);
          _SFD_SET_DATA_PROPS(6,7,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"motor_stopped_value",0);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"controller_enable",0);
          _SFD_SET_DATA_PROPS(0,7,0,0,SF_UINT8,0,NULL,1,0,8,0,1,0,"init_1_message",0);
          _SFD_SET_DATA_PROPS(9,7,0,0,SF_UINT8,0,NULL,1,0,8,0,1,0,"init_2_message",0);
          _SFD_SET_DATA_PROPS(15,7,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"motor_positive_value",0);
          _SFD_SET_DATA_PROPS(5,7,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"motor_negative_value",0);
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,5);
          _SFD_CH_SUBSTATE_INDEX(1,0);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(2,2);
          _SFD_ST_SUBSTATE_INDEX(2,0,4);
          _SFD_ST_SUBSTATE_INDEX(2,1,3);
          _SFD_ST_SUBSTATE_COUNT(4,2);
          _SFD_ST_SUBSTATE_INDEX(4,0,1);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }
        _SFD_CV_INIT_CHART(3,1,0,0);
        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(2,2,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(4,2,0,1,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1,21};
          static unsigned int sEndGuardMap[] = {17,38};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {11};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_TRANS_COV_WTS(5,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(5,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(2,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1,21};
          static unsigned int sEndGuardMap[] = {17,38};
          _SFD_TRANS_COV_MAPS(2,
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
        _SFD_TRANS_COV_WTS(7,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(7,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(3,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {0};
          static unsigned int sEndGuardMap[] = {11};
          _SFD_TRANS_COV_MAPS(3,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          _SFD_TRANS_COV_MAPS(1,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(6,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          _SFD_TRANS_COV_MAPS(6,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(4,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          _SFD_TRANS_COV_MAPS(4,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {19};
          _SFD_TRANS_COV_MAPS(8,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(14U, c1_init_out_value());
        _SFD_SET_DATA_VALUE_PTR(2U, c1_init_out_enable());
        _SFD_SET_DATA_VALUE_PTR(3U, c1_init_ack_sync());
        _SFD_SET_DATA_VALUE_PTR(10U, c1_init_ack_async());
        _SFD_SET_DATA_VALUE_PTR(13U, c1_init_out_trigger());
        _SFD_SET_DATA_VALUE_PTR(8U, c1_stop_trigger());
        _SFD_SET_DATA_VALUE_PTR(4U, c1_positive_button());
        _SFD_SET_DATA_VALUE_PTR(7U, c1_negative_button());
        _SFD_SET_DATA_VALUE_PTR(11U, c1_motor1_reference());
        _SFD_SET_DATA_VALUE_PTR(12U, c1_motor2_reference());
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance.c1_motor_stopped_value);
        _SFD_SET_DATA_VALUE_PTR(1U, c1_controller_enable());
        _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance.c1_init_1_message);
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance.c1_init_2_message);
        _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance.c1_motor_positive_value);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance.c1_motor_negative_value);
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
      sf_mark_chart_reusable_outputs(S,"MPC_framework",1,7);
    }
    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
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

  ssSetChecksum0(S,(3620345513U));
  ssSetChecksum1(S,(1455857276U));
  ssSetChecksum2(S,(1848736988U));
  ssSetChecksum3(S,(3127066014U));

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
  {3, 0, "StateflowChart/OPERATION.MOVING", "MOVING", 0, 0, 0, 0, 0},
  {4, 0, "StateflowChart/OPERATION.MOVING.NEGATIVE_MOVEMENT",
    "NEGATIVE_MOVEMENT", 0, 0, 0, 0, 0},
  {5, 0, "StateflowChart/OPERATION.MOVING.POSITIVE_MOVEMENT",
    "POSITIVE_MOVEMENT", 0, 0, 0, 0, 0},
  {6, 0, "StateflowChart/OPERATION.STOPPED", "STOPPED", 0, 0, 0, 0, 0}
};

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                   /* Block signals Array  */
    7                                   /* Num Block IO signals */
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

