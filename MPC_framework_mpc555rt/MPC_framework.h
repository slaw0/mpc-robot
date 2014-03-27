/*
 * File: MPC_framework.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.386
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Thu Mar 27 19:08:21 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Thu Mar 27 19:08:22 2014
 */

#ifndef _RTW_HEADER_MPC_framework_h_
#define _RTW_HEADER_MPC_framework_h_

#ifndef _MPC_framework_COMMON_INCLUDES_
# define _MPC_framework_COMMON_INCLUDES_
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtlibsrc.h"
#include "can_msg.h"
#include "mpc5xx.h"
#include "can_driver.h"
#include "isr.h"
#include "can_tx_queue.h"
#include "can_callback.h"
#endif                                  /* _MPC_framework_COMMON_INCLUDES_ */

#include "MPC_framework_types.h"

/* Macros for accessing real-time model data structure  */

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx) ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

/* user code (top of export header file) */
#include "can_msg.h"

/* The interrupt level for rtOnestep function */
#define RT_ONE_STEP_IRQ                 INT_LEVEL0

/* The oscillator frequency of the processor  */
#define OSCILLATOR_FREQ                 20000000                 /* hz */

/* Block signals (auto storage) */
typedef struct {
  CAN_FRAME Datarealtime;               /* '<S48>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_p;             /* '<S49>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_b;             /* '<S61>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pd;            /* '<S33>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pr;            /* '<S37>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_k;             /* '<S75>/CAN Receive (S-Function)' */
  CAN_FRAME stopmessagepacking;         /* '<S16>/stop message packing' */
  CAN_FRAME request_incremental_valuemessa; /* '<S15>/request_incremental_value message packing' */
  CAN_FRAME operation_mode_changedmessage; /* '<S13>/operation_mode_changed message packing' */
  CAN_FRAME incremental_out_valuemessagep; /* '<S11>/incremental_out_value message packing' */
  CAN_FRAME initmessagepacking;         /* '<S6>/init message packing' */
  CAN_FRAME initmessagepacking_b;       /* '<S5>/init message packing' */
  CAN_FRAME DA_out_valuemessagepacking; /* '<S3>/DA_out_value message packing' */
  real_T CANMessageUnpackingCANdb;      /* '<S76>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_e;    /* '<S47>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_m;    /* '<S46>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_o;    /* '<S38>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_c;    /* '<S38>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_d;    /* '<S34>/CAN Message Unpacking (CANdb)' */
  real_T da_out_trigger;                /* '<Root>/State Machine' */
  uint16_T Switch[2];                   /* '<Root>/Switch' */
  uint16_T Gain;                        /* '<S11>/Gain' */
  uint16_T Gain1;                       /* '<S11>/Gain1' */
  uint16_T motor1_reference;            /* '<Root>/State Machine' */
  uint16_T motor2_reference;            /* '<Root>/State Machine' */
  uint16_T motor1_reference_j;          /* '<S2>/motor1_reference' */
  uint16_T motor2_reference_l;          /* '<S2>/motor2_reference' */
  uint8_T CANMessageUnpackingCANdb_l;   /* '<S62>/CAN Message Unpacking (CANdb)' */
  uint8_T Compare;                      /* '<S51>/Compare' */
  uint8_T Compare_i;                    /* '<S50>/Compare' */
  uint8_T init_out_value;               /* '<Root>/State Machine' */
  uint8_T init_out_enable;              /* '<Root>/State Machine' */
  uint8_T init_out_trigger;             /* '<Root>/State Machine' */
  uint8_T stop_trigger;                 /* '<Root>/State Machine' */
  uint8_T controller_enable;            /* '<Root>/State Machine' */
  uint8_T operation_mode;               /* '<Root>/State Machine' */
} BlockIO_MPC_framework;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  CSc1_MPC_framework_ChartStruct StateMachine; /* '<Root>/State Machine' */
  int_T Controller_MODE;                /* '<Root>/Controller' */
  int_T Init1messagesender_MODE;        /* '<Root>/Init 1 message sender' */
  int_T incremental_out_valuesender_MO; /* '<Root>/incremental_out_value sender' */
  int_T request_incremental_valuesende; /* '<Root>/request_incremental_value sender' */
  uint8_T DelayInput1_DSTATE;           /* '<S4>/Delay Input1' */
} D_Work_MPC_framework;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState stopmessagesender_ZCE;     /* '<Root>/stop message sender' */
  ZCSigState operation_mode_changedsender_ZCE; /* '<Root>/operation_mode_changed sender' */
  ZCSigState Init2messagesender_ZCE;    /* '<Root>/Init 2 message sender' */
  ZCSigState DA_out_valuesender_ZCE;    /* '<Root>/DA_out_value sender' */
} PrevZCSigStates_MPC_framework;

/* Parameters (auto storage) */
struct _Parameters_MPC_framework {
  real_T Gain_Gain;                     /* Computed Parameter: Gain
                                         * '<S11>/Gain'
                                         */
  real_T Gain1_Gain;                    /* Computed Parameter: Gain
                                         * '<S11>/Gain1'
                                         */
  real_T Constant_Value;                /* Computed Parameter: Value
                                         * '<S50>/Constant'
                                         */
  real_T Constant_Value_h;              /* Computed Parameter: Value
                                         * '<S51>/Constant'
                                         */
  uint16_T Constant_Value_i;            /* Expression: motor_stopped_value
                                         * '<S3>/Constant'
                                         */
  uint16_T SFunction_p3;                /* Expression: motor_negative_value
                                         * '<Root>/State Machine'
                                         */
  uint16_T SFunction_p4;                /* Expression: motor_positive_value
                                         * '<Root>/State Machine'
                                         */
  uint16_T SFunction_p5;                /* Expression: motor_stopped_value
                                         * '<Root>/State Machine'
                                         */
  uint8_T Switch_Threshold;             /* Computed Parameter: Threshold
                                         * '<Root>/Switch'
                                         */
  uint8_T DelayInput1_X0;               /* Computed Parameter: X0
                                         * '<S4>/Delay Input1'
                                         */
  uint8_T SFunction_p1;                 /* Expression: init_1_message
                                         * '<Root>/State Machine'
                                         */
  uint8_T SFunction_p2;                 /* Expression: init_2_message
                                         * '<Root>/State Machine'
                                         */
  uint8_T Constant_Value_f;             /* Computed Parameter: Value
                                         * '<S15>/Constant'
                                         */
  uint8_T Constant_Value_n;             /* Computed Parameter: Value
                                         * '<S16>/Constant'
                                         */
};

/* Real-time Model Data Structure */
struct RT_MODEL_MPC_framework {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_MPC_framework MPC_framework_P;

/* Block signals (auto storage) */
extern BlockIO_MPC_framework MPC_framework_B;

/* Block states (auto storage) */
extern D_Work_MPC_framework MPC_framework_DWork;

/* Model entry point functions */
extern void MPC_framework_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void MPC_framework_initialize(boolean_T firstTime);
extern void MPC_framework_step(int_T tid);
extern void MPC_framework_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MPC_framework *MPC_framework_M;

/* 
 * The generated code includes comments that allow you to trace directly 
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : MPC_framework
 * '<S1>'   : MPC_framework/Compare To Zero
 * '<S2>'   : MPC_framework/Controller
 * '<S3>'   : MPC_framework/DA_out_value sender
 * '<S4>'   : MPC_framework/Detect Change
 * '<S5>'   : MPC_framework/Init 1 message sender
 * '<S6>'   : MPC_framework/Init 2 message sender
 * '<S7>'   : MPC_framework/MPC555 Resource Configuration
 * '<S8>'   : MPC_framework/State Machine
 * '<S9>'   : MPC_framework/async_request receiver1
 * '<S10>'  : MPC_framework/incremental_in_value receiver
 * '<S11>'  : MPC_framework/incremental_out_value sender
 * '<S12>'  : MPC_framework/init_ack_messages receiver
 * '<S13>'  : MPC_framework/operation_mode_changed sender
 * '<S14>'  : MPC_framework/primitive_button receiver
 * '<S15>'  : MPC_framework/request_incremental_value sender
 * '<S16>'  : MPC_framework/stop message sender
 * '<S17>'  : MPC_framework/stop_button receiver
 * '<S18>'  : MPC_framework/DA_out_value sender/TouCAN Transmit
 * '<S19>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S20>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S21>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output
 * '<S22>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S23>'  : MPC_framework/Init 1 message sender/TouCAN Transmit
 * '<S24>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S25>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S26>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output
 * '<S27>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S28>'  : MPC_framework/Init 2 message sender/TouCAN Transmit
 * '<S29>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S30>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S31>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output
 * '<S32>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S33>'  : MPC_framework/async_request receiver1/async_request message receive
 * '<S34>'  : MPC_framework/async_request receiver1/async_request message unpacking
 * '<S35>'  : MPC_framework/async_request receiver1/async_request message receive/Configurable Outport Control
 * '<S36>'  : MPC_framework/async_request receiver1/async_request message receive/Non-Configurable Outport Control1
 * '<S37>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive
 * '<S38>'  : MPC_framework/incremental_in_value receiver/incremental_in_value unpacking
 * '<S39>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Configurable Outport Control
 * '<S40>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S41>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit
 * '<S42>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S43>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S44>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output
 * '<S45>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S46>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)
 * '<S47>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1
 * '<S48>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive
 * '<S49>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1
 * '<S50>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)/Compare To Constant
 * '<S51>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1/Compare To Constant
 * '<S52>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Configurable Outport Control
 * '<S53>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S54>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Configurable Outport Control
 * '<S55>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Non-Configurable Outport Control1
 * '<S56>'  : MPC_framework/operation_mode_changed sender/TouCAN Transmit
 * '<S57>'  : MPC_framework/operation_mode_changed sender/TouCAN Transmit/Configurable Outport Control
 * '<S58>'  : MPC_framework/operation_mode_changed sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S59>'  : MPC_framework/operation_mode_changed sender/TouCAN Transmit/Pass through output
 * '<S60>'  : MPC_framework/operation_mode_changed sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S61>'  : MPC_framework/primitive_button receiver/primitive_button message receive
 * '<S62>'  : MPC_framework/primitive_button receiver/primitive_button message unpacking
 * '<S63>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Configurable Outport Control
 * '<S64>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Non-Configurable Outport Control1
 * '<S65>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit
 * '<S66>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S67>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S68>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output
 * '<S69>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S70>'  : MPC_framework/stop message sender/TouCAN Transmit
 * '<S71>'  : MPC_framework/stop message sender/TouCAN Transmit/Configurable Outport Control
 * '<S72>'  : MPC_framework/stop message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S73>'  : MPC_framework/stop message sender/TouCAN Transmit/Pass through output
 * '<S74>'  : MPC_framework/stop message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S75>'  : MPC_framework/stop_button receiver/TouCAN Receive
 * '<S76>'  : MPC_framework/stop_button receiver/stop_button message packing
 * '<S77>'  : MPC_framework/stop_button receiver/TouCAN Receive/Configurable Outport Control
 * '<S78>'  : MPC_framework/stop_button receiver/TouCAN Receive/Non-Configurable Outport Control1
 */

#endif                                  /* _RTW_HEADER_MPC_framework_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
