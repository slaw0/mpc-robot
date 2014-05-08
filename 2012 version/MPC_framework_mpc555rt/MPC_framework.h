/*
 * File: MPC_framework.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.1102
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Tue May 06 12:21:42 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Tue May 06 12:21:42 2014
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

/* Block signals for system '<S48>/Joint reference singal 1' */
typedef struct {
  real_T qa;                            /* '<S48>/Joint reference singal 1' */
} rtB_Jointreferencesingal;

/* Block signals for system '<S49>/Trajectory design 1' */
typedef struct {
  real_T a0;                            /* '<S49>/Trajectory design 1' */
  real_T a1;                            /* '<S49>/Trajectory design 1' */
  real_T a2;                            /* '<S49>/Trajectory design 1' */
  real_T a3;                            /* '<S49>/Trajectory design 1' */
  real_T a4;                            /* '<S49>/Trajectory design 1' */
  real_T a5;                            /* '<S49>/Trajectory design 1' */
} rtB_MP_Trajectorydesign1;

/* Block signals (auto storage) */
typedef struct {
  CAN_FRAME Datarealtime;               /* '<S82>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_p;             /* '<S63>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_h;             /* '<S74>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pu;            /* '<S75>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_b;             /* '<S93>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pd;            /* '<S54>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_k;             /* '<S107>/CAN Receive (S-Function)' */
  CAN_FRAME sync_commandmessagepacking; /* '<S113>/sync_command message packing' */
  CAN_FRAME stopmessagepacking;         /* '<S19>/stop message packing' */
  CAN_FRAME request_incremental_valuemessa; /* '<S18>/request_incremental_value message packing' */
  CAN_FRAME operation_mode_changedmessage; /* '<S87>/operation_mode_changed message packing' */
  CAN_FRAME incremental_out_valuemessagep; /* '<S13>/incremental_out_value message packing' */
  CAN_FRAME controller_messagepacking; /* '<S11>/controller_message packing' */
  CAN_FRAME initmessagepacking;         /* '<S5>/init message packing' */
  CAN_FRAME initmessagepacking_b;       /* '<S4>/init message packing' */
  CAN_FRAME DA_out_valuemessagepacking; /* '<S3>/DA_out_value message packing' */
  real_T Gain;                          /* '<S12>/Gain' */
  real_T Gain1;                         /* '<S12>/Gain1' */
  real_T Switch[2];                     /* '<Root>/Switch' */
  real_T CANMessageUnpackingCANdb;      /* '<S108>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_o;    /* '<S83>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_g;    /* '<S83>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_e;    /* '<S73>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_m;    /* '<S72>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_h;    /* '<S64>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_c;    /* '<S64>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_d;    /* '<S55>/CAN Message Unpacking (CANdb)' */
  real_T TmpHiddenBufferAtSFunctionInp[2]; /* '<Root>/State Machine' */
  real_T motor1_reference;              /* '<Root>/State Machine' */
  real_T motor2_reference;              /* '<Root>/State Machine' */
  real_T da_out_trigger;                /* '<Root>/State Machine' */
  real_T al1;                           /* '<S45>/invgeo' */
  real_T al2;                           /* '<S45>/invgeo' */
  real_T Gain_n;                        /* '<S2>/Gain' */
  real_T Gain1_i;                       /* '<S2>/Gain1' */
  uint16_T DataTypeConversion;          /* '<S13>/Data Type Conversion' */
  uint16_T DataTypeConversion1;         /* '<S13>/Data Type Conversion1' */
  uint8_T CANMessageUnpackingCANdb_l;   /* '<S94>/CAN Message Unpacking (CANdb)' */
  uint8_T Compare;                      /* '<S77>/Compare' */
  uint8_T Compare_i;                    /* '<S76>/Compare' */
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
  uint8_T error;                        /* '<S45>/invgeo' */
  rtB_MP_Trajectorydesign1 sf_Trajectorydesign2; /* '<S49>/Trajectory design 2' */
  rtB_MP_Trajectorydesign1 sf_Trajectorydesign1; /* '<S49>/Trajectory design 1' */
  rtB_Jointreferencesingal sf_Jointreferencesi_i; /* '<S48>/Joint reference singal 2' */
  rtB_Jointreferencesingal sf_Jointreferencesing; /* '<S48>/Joint reference singal 1' */
} BlockIO_MPC_framework;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;              /* '<S25>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;            /* '<S24>/Unit Delay' */
  real_T UnitDelay_DSTATE_o;            /* '<S27>/Unit Delay' */
  real_T UnitDelay_DSTATE_i;            /* '<S26>/Unit Delay' */
  real_T DelayInput1_DSTATE;            /* '<S43>/Delay Input1' */
  real_T DelayInput1_DSTATE_i;          /* '<S44>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE; /* '<S48>/Discrete-Time Integrator' */
  real_T Hidden_Mem_for_Latch_at_inp_por; /* 'synthesized block' */
  real_T Hidden_Mem_for_Latch_at_inp_p_l; /* 'synthesized block' */
  real_T invgeo_alpha_1;                /* '<Root>/invgeo_alpha_1' */
  real_T invgeo_alpha_2;                /* '<Root>/invgeo_alpha_2' */
  CSc1_MPC_framework_ChartStruct StateMachine; /* '<Root>/State Machine' */
  int_T Curvecalculation_MODE;          /* '<S47>/Curve calculation' */
  int_T Controller_MODE;                /* '<Root>/Controller' */
  int_T DA_out_valuesender_MODE;        /* '<Root>/DA_out_value sender' */
  int_T Init1messagesender_MODE;        /* '<Root>/Init 1 message sender' */
  int_T incremental_out_valuesender_MO; /* '<Root>/incremental_out_value sender' */
  int_T request_incremental_valuesende; /* '<Root>/request_incremental_value sender' */
  uint8_T DelayInput1_DSTATE_m;         /* '<S86>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_h;         /* '<S112>/Delay Input1' */
  uint8_T invgeo_error;                 /* '<Root>/invgeo_error' */
} D_Work_MPC_framework;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState sync_commandsender_ZCE;    /* '<S21>/sync_command sender' */
  ZCSigState stopmessagesender_ZCE;     /* '<Root>/stop message sender' */
  ZCSigState operation_mode_changedsender_ZCE; /* '<S16>/operation_mode_changed sender' */
  ZCSigState Init_ZCE;                  /* '<S47>/Init' */
  ZCSigState Subsystem_ZCE;             /* '<S6>/Subsystem' */
  ZCSigState Init2messagesender_ZCE;    /* '<Root>/Init 2 message sender' */
} PrevZCSigStates_MPC_framework;

/* Parameters (auto storage) */
struct _Parameters_MPC_framework {
  real_T trajectory_time_Value;         /* Expression: trajectory_time
                                         * '<S47>/trajectory_time'
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
  real_T Ap1_Value;                     /* Expression: 1/8
                                         * '<S2>/Ap1'
                                         */
  real_T Ap2_Value;                     /* Expression: 1/15
                                         * '<S2>/Ap2'
                                         */
  real_T T_Value;                       /* Expression: fundamental_sample_time
                                         * '<S2>/T'
                                         */
  real_T UnitDelay_X0;                  /* Expression: 0
                                         * '<S25>/Unit Delay'
                                         */
  real_T Tc1_Value;                     /* Expression: 0.2
                                         * '<S2>/Tc1'
                                         */
  real_T UnitDelay_X0_b;                /* Expression: 0
                                         * '<S24>/Unit Delay'
                                         */
  real_T Td1_Value;                     /* Expression: 0.1
                                         * '<S2>/Td1'
                                         */
  real_T Saturation_UpperSat;           /* Expression: 0.5
                                         * '<S22>/Saturation'
                                         */
  real_T Saturation_LowerSat;           /* Expression: -0.5
                                         * '<S22>/Saturation'
                                         */
  real_T Saturation1_UpperSat;          /* Expression: 0.5
                                         * '<S22>/Saturation1'
                                         */
  real_T Saturation1_LowerSat;          /* Expression: -0.5
                                         * '<S22>/Saturation1'
                                         */
  real_T UnitDelay_X0_a;                /* Expression: 0
                                         * '<S27>/Unit Delay'
                                         */
  real_T Tc2_Value;                     /* Expression: 0.2
                                         * '<S2>/Tc2'
                                         */
  real_T UnitDelay_X0_o;                /* Expression: 0
                                         * '<S26>/Unit Delay'
                                         */
  real_T Td2_Value;                     /* Expression: 0.1
                                         * '<S2>/Td2'
                                         */
  real_T Saturation_UpperSat_i;         /* Expression: 0.5
                                         * '<S23>/Saturation'
                                         */
  real_T Saturation_LowerSat_b;         /* Expression: -0.5
                                         * '<S23>/Saturation'
                                         */
  real_T Saturation1_UpperSat_i;        /* Expression: 0.5
                                         * '<S23>/Saturation1'
                                         */
  real_T Saturation1_LowerSat_j;        /* Expression: -0.5
                                         * '<S23>/Saturation1'
                                         */
  real_T c1_Value;                      /* Expression: 1
                                         * '<S2>/c1'
                                         */
  real_T Gain_Gain_b;                   /* Computed Parameter: Gain
                                         * '<S2>/Gain'
                                         */
  real_T Gain2_Gain;                    /* Expression: -1
                                         * '<S2>/Gain2'
                                         */
  real_T c2_Value;                      /* Expression: 1
                                         * '<S2>/c2'
                                         */
  real_T Gain1_Gain_k;                  /* Computed Parameter: Gain
                                         * '<S2>/Gain1'
                                         */
  real_T a1_Value;                      /* Expression: a1
                                         * '<S6>/a1'
                                         */
  real_T a2_Value;                      /* Expression: a2
                                         * '<S6>/a2'
                                         */
  real_T DelayInput1_X0;                /* Expression: vinit
                                         * '<S43>/Delay Input1'
                                         */
  real_T DelayInput1_X0_b;              /* Expression: vinit
                                         * '<S44>/Delay Input1'
                                         */
  real_T SFunction_p8;                  /* Expression: ticks_per_trajectory_time
                                         * '<Root>/State Machine'
                                         */
  real_T SFunction_p9;                  /* Expression: trajectory_time
                                         * '<Root>/State Machine'
                                         */
  real_T DiscreteTimeIntegrator_g;      /* Computed Parameter: gainval
                                         * '<S48>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_I;      /* Expression: 0
                                         * '<S48>/Discrete-Time Integrator'
                                         */
  real_T timebase_Value;                /* Expression: 1
                                         * '<S48>/time base'
                                         */
  real_T Constant_Value_g;              /* Computed Parameter: Value
                                         * '<S76>/Constant'
                                         */
  real_T Constant_Value_h;              /* Computed Parameter: Value
                                         * '<S77>/Constant'
                                         */
  uint16_T Constant_Value_i;            /* Expression: motor_stopped_value
                                         * '<S3>/Constant'
                                         */
  uint16_T SFunction_p3;                /* Expression: motor_negative_value_seg_1
                                         * '<Root>/State Machine'
                                         */
  uint16_T SFunction_p4;                /* Expression: motor_negative_value_seg_2
                                         * '<Root>/State Machine'
                                         */
  uint16_T SFunction_p5;                /* Expression: motor_positive_value_seg_1
                                         * '<Root>/State Machine'
                                         */
  uint16_T SFunction_p6;                /* Expression: motor_positive_value_seg_2
                                         * '<Root>/State Machine'
                                         */
  uint16_T SFunction_p7;                /* Expression: motor_stopped_value
                                         * '<Root>/State Machine'
                                         */
  uint8_T Switch1_Threshold;            /* Computed Parameter: Threshold
                                         * '<Root>/Switch1'
                                         */
  uint8_T Switch_Threshold;             /* Computed Parameter: Threshold
                                         * '<Root>/Switch'
                                         */
  uint8_T DelayInput1_X0_f;             /* Computed Parameter: X0
                                         * '<S86>/Delay Input1'
                                         */
  uint8_T DelayInput1_X0_k;             /* Computed Parameter: X0
                                         * '<S112>/Delay Input1'
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
 * '<S22>'  : MPC_framework/Controller/Discrete PD
 * '<S23>'  : MPC_framework/Controller/Discrete PD1
 * '<S24>'  : MPC_framework/Controller/Discrete PD/Discrete derivative
 * '<S25>'  : MPC_framework/Controller/Discrete PD/Discrete low pass filter
 * '<S26>'  : MPC_framework/Controller/Discrete PD1/Discrete derivative
 * '<S27>'  : MPC_framework/Controller/Discrete PD1/Discrete low pass filter
 * '<S28>'  : MPC_framework/DA_out_value sender/TouCAN Transmit
 * '<S29>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S30>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S31>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output
 * '<S32>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S33>'  : MPC_framework/Init 1 message sender/TouCAN Transmit
 * '<S34>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S35>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S36>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output
 * '<S37>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S38>'  : MPC_framework/Init 2 message sender/TouCAN Transmit
 * '<S39>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S40>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S41>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output
 * '<S42>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S43>'  : MPC_framework/Inverse geometry/Detect Change
 * '<S44>'  : MPC_framework/Inverse geometry/Detect Change1
 * '<S45>'  : MPC_framework/Inverse geometry/Subsystem
 * '<S46>'  : MPC_framework/Inverse geometry/Subsystem/invgeo
 * '<S47>'  : MPC_framework/Trajectory design/Trajectory design1
 * '<S48>'  : MPC_framework/Trajectory design/Trajectory design1/Curve calculation
 * '<S49>'  : MPC_framework/Trajectory design/Trajectory design1/Init
 * '<S50>'  : MPC_framework/Trajectory design/Trajectory design1/Curve calculation/Joint reference singal 1
 * '<S51>'  : MPC_framework/Trajectory design/Trajectory design1/Curve calculation/Joint reference singal 2
 * '<S52>'  : MPC_framework/Trajectory design/Trajectory design1/Init/Trajectory design 1
 * '<S53>'  : MPC_framework/Trajectory design/Trajectory design1/Init/Trajectory design 2
 * '<S54>'  : MPC_framework/async_request receiver1/async_request message receive
 * '<S55>'  : MPC_framework/async_request receiver1/async_request message unpacking
 * '<S56>'  : MPC_framework/async_request receiver1/async_request message receive/Configurable Outport Control
 * '<S57>'  : MPC_framework/async_request receiver1/async_request message receive/Non-Configurable Outport Control1
 * '<S58>'  : MPC_framework/controller_message sender/TouCAN Transmit
 * '<S59>'  : MPC_framework/controller_message sender/TouCAN Transmit/Configurable Outport Control
 * '<S60>'  : MPC_framework/controller_message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S61>'  : MPC_framework/controller_message sender/TouCAN Transmit/Pass through output
 * '<S62>'  : MPC_framework/controller_message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S63>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive
 * '<S64>'  : MPC_framework/incremental_in_value receiver/incremental_in_value unpacking
 * '<S65>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Configurable Outport Control
 * '<S66>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S67>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit
 * '<S68>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S69>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S70>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output
 * '<S71>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S72>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)
 * '<S73>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1
 * '<S74>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive
 * '<S75>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1
 * '<S76>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)/Compare To Constant
 * '<S77>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1/Compare To Constant
 * '<S78>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Configurable Outport Control
 * '<S79>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S80>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Configurable Outport Control
 * '<S81>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Non-Configurable Outport Control1
 * '<S82>'  : MPC_framework/input_coords receiver/input_coords message receive
 * '<S83>'  : MPC_framework/input_coords receiver/input_coords message unpacking
 * '<S84>'  : MPC_framework/input_coords receiver/input_coords message receive/Configurable Outport Control
 * '<S85>'  : MPC_framework/input_coords receiver/input_coords message receive/Non-Configurable Outport Control1
 * '<S86>'  : MPC_framework/operation_mode handler/Detect Change
 * '<S87>'  : MPC_framework/operation_mode handler/operation_mode_changed sender
 * '<S88>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit
 * '<S89>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Configurable Outport Control
 * '<S90>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S91>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Pass through output
 * '<S92>'  : MPC_framework/operation_mode handler/operation_mode_changed sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S93>'  : MPC_framework/primitive_button receiver/primitive_button message receive
 * '<S94>'  : MPC_framework/primitive_button receiver/primitive_button message unpacking
 * '<S95>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Configurable Outport Control
 * '<S96>'  : MPC_framework/primitive_button receiver/primitive_button message receive/Non-Configurable Outport Control1
 * '<S97>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit
 * '<S98>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S99>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S100>' : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output
 * '<S101>' : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S102>' : MPC_framework/stop message sender/TouCAN Transmit
 * '<S103>' : MPC_framework/stop message sender/TouCAN Transmit/Configurable Outport Control
 * '<S104>' : MPC_framework/stop message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S105>' : MPC_framework/stop message sender/TouCAN Transmit/Pass through output
 * '<S106>' : MPC_framework/stop message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S107>' : MPC_framework/stop_button receiver/TouCAN Receive
 * '<S108>' : MPC_framework/stop_button receiver/stop_button message packing
 * '<S109>' : MPC_framework/stop_button receiver/TouCAN Receive/Configurable Outport Control
 * '<S110>' : MPC_framework/stop_button receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S111>' : MPC_framework/sync_command handler/Compare To Zero1
 * '<S112>' : MPC_framework/sync_command handler/Detect Change2
 * '<S113>' : MPC_framework/sync_command handler/sync_command sender
 * '<S114>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit
 * '<S115>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Configurable Outport Control
 * '<S116>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S117>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Pass through output
 * '<S118>' : MPC_framework/sync_command handler/sync_command sender/TouCAN Transmit/Pass through output/Pass through input
 */

#endif                                  /* _RTW_HEADER_MPC_framework_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
