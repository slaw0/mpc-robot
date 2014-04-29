/*
 * File: MPC_framework.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.907
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Tue Apr 29 19:27:31 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Tue Apr 29 19:27:32 2014
 */

#ifndef _RTW_HEADER_MPC_framework_h_
#define _RTW_HEADER_MPC_framework_h_

#ifndef _MPC_framework_COMMON_INCLUDES_
# define _MPC_framework_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "rtwtypes.h"
#include "rtlibsrc.h"
#include "can_msg.h"
#include "mpc5xx.h"
#include "can_driver.h"
#include "isr.h"
#include "can_tx_queue.h"
#include "can_callback.h"
#include "rt_nonfinite.h"
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

/* Block signals for system '<Root>/Inverse geometry' */
typedef struct {
  real_T al1;                           /* '<S38>/invgeo' */
  real_T al2;                           /* '<S38>/invgeo' */
  uint8_T LogicalOperator;              /* '<S6>/Logical Operator' */
  uint8_T error;                        /* '<S38>/invgeo' */
} rtB_MPC_f_Inversegeometry;

/* Block states (auto storage) for system '<Root>/Inverse geometry' */
typedef struct {
  real_T DelayInput1_DSTATE;            /* '<S36>/Delay Input1' */
  real_T DelayInput1_DSTATE_i;          /* '<S37>/Delay Input1' */
} rtDW_MPC_f_Inversegeometry;

/* Zero-crossing (trigger) state for system '<Root>/Inverse geometry' */
typedef struct {
  ZCSigState Subsystem_ZCE;             /* '<S6>/Subsystem' */
} rtZCE_MPC_f_Inversegeometry;

/* Block signals (auto storage) */
typedef struct {
  CAN_FRAME Datarealtime;               /* '<S60>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_p;             /* '<S61>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_b;             /* '<S79>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pd;            /* '<S40>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pr;            /* '<S49>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_l;             /* '<S68>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_k;             /* '<S93>/CAN Receive (S-Function)' */
  CAN_FRAME sync_commandmessagepacking; /* '<S99>/sync_command message packing' */
  CAN_FRAME stopmessagepacking;         /* '<S18>/stop message packing' */
  CAN_FRAME request_incremental_valuemessa; /* '<S17>/request_incremental_value message packing' */
  CAN_FRAME operation_mode_changedmessage; /* '<S73>/operation_mode_changed message packing' */
  CAN_FRAME incremental_out_valuemessagep; /* '<S12>/incremental_out_value message packing' */
  CAN_FRAME controller_messagepacking; /* '<S10>/controller_message packing' */
  CAN_FRAME initmessagepacking;         /* '<S5>/init message packing' */
  CAN_FRAME initmessagepacking_b;       /* '<S4>/init message packing' */
  CAN_FRAME DA_out_valuemessagepacking; /* '<S3>/DA_out_value message packing' */
  real_T MathFunction;                  /* '<S11>/Math Function' */
  real_T MathFunction1;                 /* '<S11>/Math Function1' */
  real_T Switch[2];                     /* '<Root>/Switch' */
  real_T CANMessageUnpackingCANdb;      /* '<S94>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_o;    /* '<S69>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_g;    /* '<S69>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_e;    /* '<S59>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_m;    /* '<S58>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_h;    /* '<S50>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_c;    /* '<S50>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_d;    /* '<S41>/CAN Message Unpacking (CANdb)' */
  real_T TmpHiddenBufferAtSFunctionInp[2]; /* '<Root>/State Machine' */
  real_T motor1_reference;              /* '<Root>/State Machine' */
  real_T motor2_reference;              /* '<Root>/State Machine' */
  real_T da_out_trigger;                /* '<Root>/State Machine' */
  real_T alpha1_ref;                    /* '<S2>/alpha1_ref' */
  real_T alpha2_ref;                    /* '<S2>/alpha2_ref' */
  uint8_T CANMessageUnpackingCANdb_l;   /* '<S80>/CAN Message Unpacking (CANdb)' */
  uint8_T Compare;                      /* '<S63>/Compare' */
  uint8_T Compare_i;                    /* '<S62>/Compare' */
  uint8_T init_out_value;               /* '<Root>/State Machine' */
  uint8_T init_out_enable;              /* '<Root>/State Machine' */
  uint8_T init_out_trigger;             /* '<Root>/State Machine' */
  uint8_T stop_trigger;                 /* '<Root>/State Machine' */
  uint8_T controller_enable;            /* '<Root>/State Machine' */
  uint8_T operation_mode;               /* '<Root>/State Machine' */
  uint8_T sync_command;                 /* '<Root>/State Machine' */
  uint8_T controller_message;           /* '<Root>/State Machine' */
  rtB_MPC_f_Inversegeometry Inversegeometry; /* '<Root>/Inverse geometry' */
} BlockIO_MPC_framework;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T invgeo_alpha_2;                /* '<Root>/ingeo_alpha_2' */
  real_T invgeo_alpha_1;                /* '<Root>/invgeo_alpha_1' */
  CSc1_MPC_framework_ChartStruct StateMachine; /* '<Root>/State Machine' */
  int_T Controller_MODE;                /* '<Root>/Controller' */
  int_T DA_out_valuesender_MODE;        /* '<Root>/DA_out_value sender' */
  int_T Init1messagesender_MODE;        /* '<Root>/Init 1 message sender' */
  int_T incremental_out_valuesender_MO; /* '<Root>/incremental_out_value sender' */
  int_T request_incremental_valuesende; /* '<Root>/request_incremental_value sender' */
  uint8_T DelayInput1_DSTATE_m;         /* '<S72>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_h;         /* '<S98>/Delay Input1' */
  uint8_T invgeo_error;                 /* '<Root>/invgeo_error' */
  rtDW_MPC_f_Inversegeometry Inversegeometry; /* '<Root>/Inverse geometry' */
} D_Work_MPC_framework;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState sync_commandsender_ZCE;    /* '<S20>/sync_command sender' */
  ZCSigState stopmessagesender_ZCE;     /* '<Root>/stop message sender' */
  ZCSigState operation_mode_changedsender_ZCE; /* '<S15>/operation_mode_changed sender' */
  rtZCE_MPC_f_Inversegeometry Inversegeometry; /* '<Root>/Inverse geometry' */
  ZCSigState Init2messagesender_ZCE;    /* '<Root>/Init 2 message sender' */
} PrevZCSigStates_MPC_framework;

/* Parameters for system: '<Root>/Inverse geometry' */
struct _rtP_MPC_f_Inversegeometry {
  real_T a1_Value;                      /* Expression: a1
                                         * '<S6>/a1'
                                         */
  real_T a2_Value;                      /* Expression: a2
                                         * '<S6>/a2'
                                         */
  real_T DelayInput1_X0;                /* Expression: vinit
                                         * '<S36>/Delay Input1'
                                         */
  real_T DelayInput1_X0_b;              /* Expression: vinit
                                         * '<S37>/Delay Input1'
                                         */
};

/* Parameters (auto storage) */
struct _Parameters_MPC_framework {
  real_T increments_per_half_turn_V;    /* Computed Parameter: Value
                                         * '<S11>/increments_per_half_turn'
                                         */
  real_T ingeo_alpha_2_InitialValue;    /* Expression: 0
                                         * '<Root>/ingeo_alpha_2'
                                         */
  real_T invgeo_alpha_1_InitialValu;    /* Expression: 0
                                         * '<Root>/invgeo_alpha_1'
                                         */
  real_T Constant_Value;                /* Computed Parameter: Value
                                         * '<S62>/Constant'
                                         */
  real_T Constant_Value_h;              /* Computed Parameter: Value
                                         * '<S63>/Constant'
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
                                         * '<S72>/Delay Input1'
                                         */
  uint8_T DelayInput1_X0_k;             /* Computed Parameter: X0
                                         * '<S98>/Delay Input1'
                                         */
  uint8_T invgeo_error_InitialValue;    /* Computed Parameter: InitialValue
                                         * '<Root>/invgeo_error'
                                         */
  uint8_T SFunction_p1;                 /* Expression: init_1_message
                                         * '<Root>/State Machine'
                                         */
  uint8_T SFunction_p2;                 /* Expression: init_2_message
                                         * '<Root>/State Machine'
                                         */
  uint8_T Constant_Value_f;             /* Computed Parameter: Value
                                         * '<S17>/Constant'
                                         */
  uint8_T Constant_Value_n;             /* Computed Parameter: Value
                                         * '<S18>/Constant'
                                         */
  rtP_MPC_f_Inversegeometry Inversegeometry; /* '<Root>/Inverse geometry' */
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

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_MPC_framework MPC_framework_PrevZCSigState;

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
 * '<S4>'   : MPC_framework/Init 1 message sender
 * '<S5>'   : MPC_framework/Init 2 message sender
 * '<S6>'   : MPC_framework/Inverse geometry
 * '<S7>'   : MPC_framework/MPC555 Resource Configuration
 * '<S8>'   : MPC_framework/State Machine
 * '<S9>'   : MPC_framework/async_request receiver1
 * '<S10>'  : MPC_framework/controller_message sender
 * '<S11>'  : MPC_framework/incremental_in_value receiver
 * '<S12>'  : MPC_framework/incremental_out_value sender
 * '<S13>'  : MPC_framework/init_ack_messages receiver
 * '<S14>'  : MPC_framework/input_coords receiver
 * '<S15>'  : MPC_framework/operation_mode handler
 * '<S16>'  : MPC_framework/primitive_button receiver
 * '<S17>'  : MPC_framework/request_incremental_value sender
 * '<S18>'  : MPC_framework/stop message sender
 * '<S19>'  : MPC_framework/stop_button receiver
 * '<S20>'  : MPC_framework/sync_command handler
 * '<S21>'  : MPC_framework/DA_out_value sender/TouCAN Transmit
 * '<S22>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S23>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S24>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output
 * '<S25>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S26>'  : MPC_framework/Init 1 message sender/TouCAN Transmit
 * '<S27>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S28>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S29>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output
 * '<S30>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S31>'  : MPC_framework/Init 2 message sender/TouCAN Transmit
 * '<S32>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S33>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S34>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output
 * '<S35>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S36>'  : MPC_framework/Inverse geometry/Detect Change
 * '<S37>'  : MPC_framework/Inverse geometry/Detect Change1
 * '<S38>'  : MPC_framework/Inverse geometry/Subsystem
 * '<S39>'  : MPC_framework/Inverse geometry/Subsystem/invgeo
 * '<S40>'  : MPC_framework/async_request receiver1/async_request message receive
 * '<S41>'  : MPC_framework/async_request receiver1/async_request message unpacking
 * '<S42>'  : MPC_framework/async_request receiver1/async_request message receive/Configurable Outport Control
 * '<S43>'  : MPC_framework/async_request receiver1/async_request message receive/Non-Configurable Outport Control1
 * '<S44>'  : MPC_framework/controller_message sender/TouCAN Transmit
 * '<S45>'  : MPC_framework/controller_message sender/TouCAN Transmit/Configurable Outport Control
 * '<S46>'  : MPC_framework/controller_message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S47>'  : MPC_framework/controller_message sender/TouCAN Transmit/Pass through output
 * '<S48>'  : MPC_framework/controller_message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S49>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive
 * '<S50>'  : MPC_framework/incremental_in_value receiver/incremental_in_value unpacking
 * '<S51>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Configurable Outport Control
 * '<S52>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S53>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit
 * '<S54>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S55>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S56>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output
 * '<S57>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S58>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)
 * '<S59>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1
 * '<S60>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive
 * '<S61>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1
 * '<S62>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)/Compare To Constant
 * '<S63>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1/Compare To Constant
 * '<S64>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Configurable Outport Control
 * '<S65>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S66>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Configurable Outport Control
 * '<S67>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Non-Configurable Outport Control1
 * '<S68>'  : MPC_framework/input_coords receiver/input_coords message receive
 * '<S69>'  : MPC_framework/input_coords receiver/input_coords message unpacking
 * '<S70>'  : MPC_framework/input_coords receiver/input_coords message receive/Configurable Outport Control
 * '<S71>'  : MPC_framework/input_coords receiver/input_coords message receive/Non-Configurable Outport Control1
 * '<S72>'  : MPC_framework/operation_mode handler/Detect Change
 * '<S73>'  : MPC_framework/operation_mode handler/operation_mode_changed sender
 * '<S74>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit
 * '<S75>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Configurable Outport Control
 * '<S76>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S77>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Pass through output
 * '<S78>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S79>'  : MPC_framework/primitive_button receiver/primitive_button message receive
 * '<S80>'  : MPC_framework/primitive_button receiver/primitive_button message unpacking
 * '<S81>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Configurable Outport Control
 * '<S82>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Non-Configurable Outport Control1
 * '<S83>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit
 * '<S84>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S85>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S86>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output
 * '<S87>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S88>'  : MPC_framework/stop message sender/TouCAN Transmit
 * '<S89>'  : MPC_framework/stop message sender/TouCAN Transmit/Configurable Outport Control
 * '<S90>'  : MPC_framework/stop message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S91>'  : MPC_framework/stop message sender/TouCAN Transmit/Pass through output
 * '<S92>'  : MPC_framework/stop message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S93>'  : MPC_framework/stop_button receiver/TouCAN Receive
 * '<S94>'  : MPC_framework/stop_button receiver/stop_button message packing
 * '<S95>'  : MPC_framework/stop_button receiver/TouCAN Receive/Configurable Outport Control
 * '<S96>'  : MPC_framework/stop_button receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S97>'  : MPC_framework/sync_command handler/Compare To Zero1
 * '<S98>'  : MPC_framework/sync_command handler/Detect Change2
 * '<S99>'  : MPC_framework/sync_command handler/sync_command sender
 * '<S100>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit
 * '<S101>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Configurable Outport Control
 * '<S102>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S103>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Pass through output
 * '<S104>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Pass through output/Pass through input
 */

#endif                                  /* _RTW_HEADER_MPC_framework_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
