/*
 * File: MPC_framework.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.1070
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Apr 30 19:37:50 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Apr 30 19:37:50 2014
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

/* Block signals for system '<S42>/Joint reference singal 1' */
typedef struct {
  real_T qa;                            /* '<S42>/Joint reference singal 1' */
} rtB_Jointreferencesingal;

/* Block signals for system '<S43>/Trajectory design 1' */
typedef struct {
  real_T a0;                            /* '<S43>/Trajectory design 1' */
  real_T a1;                            /* '<S43>/Trajectory design 1' */
  real_T a2;                            /* '<S43>/Trajectory design 1' */
  real_T a3;                            /* '<S43>/Trajectory design 1' */
  real_T a4;                            /* '<S43>/Trajectory design 1' */
  real_T a5;                            /* '<S43>/Trajectory design 1' */
} rtB_MP_Trajectorydesign1;

/* Block signals (auto storage) */
typedef struct {
  CAN_FRAME Datarealtime;               /* '<S76>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_p;             /* '<S57>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_h;             /* '<S68>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pu;            /* '<S69>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_b;             /* '<S87>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pd;            /* '<S48>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_k;             /* '<S101>/CAN Receive (S-Function)' */
  CAN_FRAME sync_commandmessagepacking; /* '<S107>/sync_command message packing' */
  CAN_FRAME stopmessagepacking;         /* '<S19>/stop message packing' */
  CAN_FRAME request_incremental_valuemessa; /* '<S18>/request_incremental_value message packing' */
  CAN_FRAME operation_mode_changedmessage; /* '<S81>/operation_mode_changed message packing' */
  CAN_FRAME incremental_out_valuemessagep; /* '<S13>/incremental_out_value message packing' */
  CAN_FRAME controller_messagepacking; /* '<S11>/controller_message packing' */
  CAN_FRAME initmessagepacking;         /* '<S5>/init message packing' */
  CAN_FRAME initmessagepacking_b;       /* '<S4>/init message packing' */
  CAN_FRAME DA_out_valuemessagepacking; /* '<S3>/DA_out_value message packing' */
  real_T MathFunction;                  /* '<S12>/Math Function' */
  real_T Gain;                          /* '<S12>/Gain' */
  real_T MathFunction1;                 /* '<S12>/Math Function1' */
  real_T Gain1;                         /* '<S12>/Gain1' */
  real_T Switch[2];                     /* '<Root>/Switch' */
  real_T CANMessageUnpackingCANdb;      /* '<S102>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_o;    /* '<S77>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_g;    /* '<S77>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_e;    /* '<S67>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_m;    /* '<S66>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_h;    /* '<S58>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_c;    /* '<S58>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_d;    /* '<S49>/CAN Message Unpacking (CANdb)' */
  real_T TmpHiddenBufferAtSFunctionInp[2]; /* '<Root>/State Machine' */
  real_T motor1_reference;              /* '<Root>/State Machine' */
  real_T motor2_reference;              /* '<Root>/State Machine' */
  real_T da_out_trigger;                /* '<Root>/State Machine' */
  real_T al1;                           /* '<S39>/invgeo' */
  real_T al2;                           /* '<S39>/invgeo' */
  real_T alpha1_ref;                    /* '<S2>/alpha1_ref' */
  real_T alpha2_ref;                    /* '<S2>/alpha2_ref' */
  uint8_T CANMessageUnpackingCANdb_l;   /* '<S88>/CAN Message Unpacking (CANdb)' */
  uint8_T Compare;                      /* '<S71>/Compare' */
  uint8_T Compare_i;                    /* '<S70>/Compare' */
  uint8_T init_out_value;               /* '<Root>/State Machine' */
  uint8_T init_out_enable;              /* '<Root>/State Machine' */
  uint8_T init_out_trigger;             /* '<Root>/State Machine' */
  uint8_T stop_trigger;                 /* '<Root>/State Machine' */
  uint8_T controller_enable;            /* '<Root>/State Machine' */
  uint8_T operation_mode;               /* '<Root>/State Machine' */
  uint8_T sync_command;                 /* '<Root>/State Machine' */
  uint8_T controller_message;           /* '<Root>/State Machine' */
  uint8_T trajectory_enable;            /* '<Root>/State Machine' */
  uint8_T LogicalOperator;              /* '<S6>/Logical Operator' */
  uint8_T error;                        /* '<S39>/invgeo' */
  rtB_MP_Trajectorydesign1 sf_Trajectorydesign2; /* '<S43>/Trajectory design 2' */
  rtB_MP_Trajectorydesign1 sf_Trajectorydesign1; /* '<S43>/Trajectory design 1' */
  rtB_Jointreferencesingal sf_Jointreferencesi_i; /* '<S42>/Joint reference singal 2' */
  rtB_Jointreferencesingal sf_Jointreferencesing; /* '<S42>/Joint reference singal 1' */
} BlockIO_MPC_framework;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;            /* '<S37>/Delay Input1' */
  real_T DelayInput1_DSTATE_i;          /* '<S38>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE; /* '<S42>/Discrete-Time Integrator' */
  real_T Hidden_Mem_for_Latch_at_inp_por; /* 'synthesized block' */
  real_T Hidden_Mem_for_Latch_at_inp_p_l; /* 'synthesized block' */
  real_T invgeo_alpha_1;                /* '<Root>/invgeo_alpha_1' */
  real_T invgeo_alpha_2;                /* '<Root>/invgeo_alpha_2' */
  CSc1_MPC_framework_ChartStruct StateMachine; /* '<Root>/State Machine' */
  int_T Curvecalculation_MODE;          /* '<S41>/Curve calculation' */
  int_T Controller_MODE;                /* '<Root>/Controller' */
  int_T DA_out_valuesender_MODE;        /* '<Root>/DA_out_value sender' */
  int_T Init1messagesender_MODE;        /* '<Root>/Init 1 message sender' */
  int_T incremental_out_valuesender_MO; /* '<Root>/incremental_out_value sender' */
  int_T request_incremental_valuesende; /* '<Root>/request_incremental_value sender' */
  uint8_T DelayInput1_DSTATE_m;         /* '<S80>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_h;         /* '<S106>/Delay Input1' */
  uint8_T invgeo_error;                 /* '<Root>/invgeo_error' */
} D_Work_MPC_framework;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState sync_commandsender_ZCE;    /* '<S21>/sync_command sender' */
  ZCSigState stopmessagesender_ZCE;     /* '<Root>/stop message sender' */
  ZCSigState operation_mode_changedsender_ZCE; /* '<S16>/operation_mode_changed sender' */
  ZCSigState Init_ZCE;                  /* '<S41>/Init' */
  ZCSigState Subsystem_ZCE;             /* '<S6>/Subsystem' */
  ZCSigState Init2messagesender_ZCE;    /* '<Root>/Init 2 message sender' */
} PrevZCSigStates_MPC_framework;

/* Parameters (auto storage) */
struct _Parameters_MPC_framework {
  real_T trajectory_time_Value;         /* Expression: trajectory_time
                                         * '<S41>/trajectory_time'
                                         */
  real_T Hidden_Mem_for_Latch_at_in;    /* Expression: 0
                                         * 'synthesized block'
                                         */
  real_T Hidden_Mem_for_Latch_at_ij;    /* Expression: 0
                                         * 'synthesized block'
                                         */
  real_T Constant_Value;                /* Computed Parameter: Value
                                         * '<S12>/Constant'
                                         */
  real_T Constant1_Value;               /* Expression: increments_per_half_turn
                                         * '<S12>/Constant1'
                                         */
  real_T Gain_Gain;                     /* Expression: pi
                                         * '<S12>/Gain'
                                         */
  real_T Gain1_Gain;                    /* Expression: pi
                                         * '<S12>/Gain1'
                                         */
  real_T invgeo_alpha_1_InitialValu;    /* Expression: 0
                                         * '<Root>/invgeo_alpha_1'
                                         */
  real_T invgeo_alpha_2_InitialValu;    /* Expression: 0
                                         * '<Root>/invgeo_alpha_2'
                                         */
  real_T a1_Value;                      /* Expression: a1
                                         * '<S6>/a1'
                                         */
  real_T a2_Value;                      /* Expression: a2
                                         * '<S6>/a2'
                                         */
  real_T DelayInput1_X0;                /* Expression: vinit
                                         * '<S37>/Delay Input1'
                                         */
  real_T DelayInput1_X0_b;              /* Expression: vinit
                                         * '<S38>/Delay Input1'
                                         */
  real_T SFunction_p6;                  /* Expression: ticks_per_trajectory_time
                                         * '<Root>/State Machine'
                                         */
  real_T SFunction_p7;                  /* Expression: trajectory_time
                                         * '<Root>/State Machine'
                                         */
  real_T DiscreteTimeIntegrator_g;      /* Computed Parameter: gainval
                                         * '<S42>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_I;      /* Expression: 0
                                         * '<S42>/Discrete-Time Integrator'
                                         */
  real_T timebase_Value;                /* Expression: 1
                                         * '<S42>/time base'
                                         */
  real_T Constant_Value_g;              /* Computed Parameter: Value
                                         * '<S70>/Constant'
                                         */
  real_T Constant_Value_h;              /* Computed Parameter: Value
                                         * '<S71>/Constant'
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
  uint8_T Switch1_Threshold;            /* Computed Parameter: Threshold
                                         * '<Root>/Switch1'
                                         */
  uint8_T Switch_Threshold;             /* Computed Parameter: Threshold
                                         * '<Root>/Switch'
                                         */
  uint8_T DelayInput1_X0_f;             /* Computed Parameter: X0
                                         * '<S80>/Delay Input1'
                                         */
  uint8_T DelayInput1_X0_k;             /* Computed Parameter: X0
                                         * '<S106>/Delay Input1'
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
                                         * '<S18>/Constant'
                                         */
  uint8_T Constant_Value_n;             /* Computed Parameter: Value
                                         * '<S19>/Constant'
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
 * '<S9>'   : MPC_framework/Trajectory design
 * '<S10>'  : MPC_framework/async_request receiver1
 * '<S11>'  : MPC_framework/controller_message sender
 * '<S12>'  : MPC_framework/incremental_in_value receiver
 * '<S13>'  : MPC_framework/incremental_out_value sender
 * '<S14>'  : MPC_framework/init_ack_messages receiver
 * '<S15>'  : MPC_framework/input_coords receiver
 * '<S16>'  : MPC_framework/operation_mode handler
 * '<S17>'  : MPC_framework/primitive_button receiver
 * '<S18>'  : MPC_framework/request_incremental_value sender
 * '<S19>'  : MPC_framework/stop message sender
 * '<S20>'  : MPC_framework/stop_button receiver
 * '<S21>'  : MPC_framework/sync_command handler
 * '<S22>'  : MPC_framework/DA_out_value sender/TouCAN Transmit
 * '<S23>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S24>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S25>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output
 * '<S26>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S27>'  : MPC_framework/Init 1 message sender/TouCAN Transmit
 * '<S28>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S29>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S30>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output
 * '<S31>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S32>'  : MPC_framework/Init 2 message sender/TouCAN Transmit
 * '<S33>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S34>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S35>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output
 * '<S36>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S37>'  : MPC_framework/Inverse geometry/Detect Change
 * '<S38>'  : MPC_framework/Inverse geometry/Detect Change1
 * '<S39>'  : MPC_framework/Inverse geometry/Subsystem
 * '<S40>'  : MPC_framework/Inverse geometry/Subsystem/invgeo
 * '<S41>'  : MPC_framework/Trajectory design/Trajectory design1
 * '<S42>'  : MPC_framework/Trajectory design/Trajectory design1/Curve calculation
 * '<S43>'  : MPC_framework/Trajectory design/Trajectory design1/Init
 * '<S44>'  : MPC_framework/Trajectory design/Trajectory design1/Curve calculation/Joint reference singal 1
 * '<S45>'  : MPC_framework/Trajectory design/Trajectory design1/Curve calculation/Joint reference singal 2
 * '<S46>'  : MPC_framework/Trajectory design/Trajectory design1/Init/Trajectory design 1
 * '<S47>'  : MPC_framework/Trajectory design/Trajectory design1/Init/Trajectory design 2
 * '<S48>'  : MPC_framework/async_request receiver1/async_request message receive
 * '<S49>'  : MPC_framework/async_request receiver1/async_request message unpacking
 * '<S50>'  : MPC_framework/async_request receiver1/async_request message receive/Configurable Outport Control
 * '<S51>'  : MPC_framework/async_request receiver1/async_request message receive/Non-Configurable Outport Control1
 * '<S52>'  : MPC_framework/controller_message sender/TouCAN Transmit
 * '<S53>'  : MPC_framework/controller_message sender/TouCAN Transmit/Configurable Outport Control
 * '<S54>'  : MPC_framework/controller_message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S55>'  : MPC_framework/controller_message sender/TouCAN Transmit/Pass through output
 * '<S56>'  : MPC_framework/controller_message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S57>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive
 * '<S58>'  : MPC_framework/incremental_in_value receiver/incremental_in_value unpacking
 * '<S59>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Configurable Outport Control
 * '<S60>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S61>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit
 * '<S62>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S63>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S64>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output
 * '<S65>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S66>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)
 * '<S67>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1
 * '<S68>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive
 * '<S69>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1
 * '<S70>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)/Compare To Constant
 * '<S71>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1/Compare To Constant
 * '<S72>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Configurable Outport Control
 * '<S73>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S74>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Configurable Outport Control
 * '<S75>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Non-Configurable Outport Control1
 * '<S76>'  : MPC_framework/input_coords receiver/input_coords message receive
 * '<S77>'  : MPC_framework/input_coords receiver/input_coords message unpacking
 * '<S78>'  : MPC_framework/input_coords receiver/input_coords message receive/Configurable Outport Control
 * '<S79>'  : MPC_framework/input_coords receiver/input_coords message receive/Non-Configurable Outport Control1
 * '<S80>'  : MPC_framework/operation_mode handler/Detect Change
 * '<S81>'  : MPC_framework/operation_mode handler/operation_mode_changed sender
 * '<S82>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit
 * '<S83>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Configurable Outport Control
 * '<S84>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S85>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Pass through output
 * '<S86>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S87>'  : MPC_framework/primitive_button receiver/primitive_button message receive
 * '<S88>'  : MPC_framework/primitive_button receiver/primitive_button message unpacking
 * '<S89>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Configurable Outport Control
 * '<S90>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Non-Configurable Outport Control1
 * '<S91>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit
 * '<S92>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S93>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S94>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output
 * '<S95>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S96>'  : MPC_framework/stop message sender/TouCAN Transmit
 * '<S97>'  : MPC_framework/stop message sender/TouCAN Transmit/Configurable Outport Control
 * '<S98>'  : MPC_framework/stop message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S99>'  : MPC_framework/stop message sender/TouCAN Transmit/Pass through output
 * '<S100>' : MPC_framework/stop message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S101>' : MPC_framework/stop_button receiver/TouCAN Receive
 * '<S102>' : MPC_framework/stop_button receiver/stop_button message packing
 * '<S103>' : MPC_framework/stop_button receiver/TouCAN Receive/Configurable Outport Control
 * '<S104>' : MPC_framework/stop_button receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S105>' : MPC_framework/sync_command handler/Compare To Zero1
 * '<S106>' : MPC_framework/sync_command handler/Detect Change2
 * '<S107>' : MPC_framework/sync_command handler/sync_command sender
 * '<S108>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit
 * '<S109>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Configurable Outport Control
 * '<S110>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S111>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Pass through output
 * '<S112>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Pass through output/Pass through input
 */

#endif                                  /* _RTW_HEADER_MPC_framework_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
