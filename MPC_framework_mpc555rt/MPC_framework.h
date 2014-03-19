/*
 * File: MPC_framework.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.282
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Mar 19 14:11:59 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Mar 19 14:11:59 2014
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
  CAN_FRAME Datarealtime;               /* '<S40>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_p;             /* '<S41>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_d;             /* '<S50>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_a;             /* '<S48>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_pr;            /* '<S29>/CAN Receive (S-Function)' */
  CAN_FRAME Datarealtime_k;             /* '<S66>/CAN Receive (S-Function)' */
  CAN_FRAME stopmessagepacking;         /* '<S12>/stop message packing' */
  CAN_FRAME request_incremental_valuemessa; /* '<S11>/request_incremental_value message packing' */
  CAN_FRAME incremental_out_valuemessagep; /* '<S8>/incremental_out_value message packing' */
  CAN_FRAME initmessagepacking;         /* '<S4>/init message packing' */
  CAN_FRAME initmessagepacking_b;       /* '<S3>/init message packing' */
  CAN_FRAME DA_out_valuemessagepacking; /* '<S2>/DA_out_value message packing' */
  real_T CANMessageUnpackingCANdb;      /* '<S67>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_e;    /* '<S39>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_m;    /* '<S38>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_o;    /* '<S30>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_c;    /* '<S30>/CAN Message Unpacking (CANdb)' */
  real_T CANMessageUnpackingCANdb_n;    /* '<S30>/CAN Message Unpacking (CANdb)' */
  uint16_T motor1_reference;            /* '<Root>/State Machine' */
  uint16_T motor2_reference;            /* '<Root>/State Machine' */
  uint16_T motor1_reference_j;          /* '<S1>/motor1_reference' */
  uint16_T motor2_reference_l;          /* '<S1>/motor2_reference' */
  uint8_T CANMessageUnpackingCANdb_ee; /* '<S51>/CAN Message Unpacking (CANdb)' */
  uint8_T CANMessageUnpackingCANdb_g;   /* '<S49>/CAN Message Unpacking (CANdb)' */
  uint8_T Compare;                      /* '<S43>/Compare' */
  uint8_T Compare_i;                    /* '<S42>/Compare' */
  uint8_T init_out_value;               /* '<Root>/State Machine' */
  uint8_T init_out_enable;              /* '<Root>/State Machine' */
  uint8_T init_out_trigger;             /* '<Root>/State Machine' */
  uint8_T stop_trigger;                 /* '<Root>/State Machine' */
  uint8_T controller_enable;            /* '<Root>/State Machine' */
} BlockIO_MPC_framework;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  CSc1_MPC_framework_ChartStruct StateMachine; /* '<Root>/State Machine' */
  int_T Controller_MODE;                /* '<Root>/Controller' */
  int_T DA_out_valuesender_MODE;        /* '<Root>/DA_out_value sender' */
  int_T Init1messagesender_MODE;        /* '<Root>/Init 1 message sender' */
  int_T incremental_out_valuesender_MO; /* '<Root>/incremental_out_value sender' */
  int_T request_incremental_valuesende; /* '<Root>/request_incremental_value sender' */
} D_Work_MPC_framework;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState stopmessagesender_ZCE;     /* '<Root>/stop message sender' */
  ZCSigState Init2messagesender_ZCE;    /* '<Root>/Init 2 message sender' */
} PrevZCSigStates_MPC_framework;

/* Parameters (auto storage) */
struct _Parameters_MPC_framework {
  real_T Constant_Value;                /* Expression: hex2dec('8000')
                                         * '<S2>/Constant'
                                         */
  real_T Constant_Value_g;              /* Computed Parameter: Value
                                         * '<S42>/Constant'
                                         */
  real_T Constant_Value_h;              /* Computed Parameter: Value
                                         * '<S43>/Constant'
                                         */
  uint8_T SFunction_p1;                 /* Expression: init_1_message
                                         * '<Root>/State Machine'
                                         */
  uint8_T SFunction_p2;                 /* Expression: init_2_message
                                         * '<Root>/State Machine'
                                         */
  uint8_T Constant_Value_f;             /* Computed Parameter: Value
                                         * '<S11>/Constant'
                                         */
  uint8_T Constant_Value_n;             /* Computed Parameter: Value
                                         * '<S12>/Constant'
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
 * '<S1>'   : MPC_framework/Controller
 * '<S2>'   : MPC_framework/DA_out_value sender
 * '<S3>'   : MPC_framework/Init 1 message sender
 * '<S4>'   : MPC_framework/Init 2 message sender
 * '<S5>'   : MPC_framework/MPC555 Resource Configuration
 * '<S6>'   : MPC_framework/State Machine
 * '<S7>'   : MPC_framework/incremental_in_value receiver
 * '<S8>'   : MPC_framework/incremental_out_value sender
 * '<S9>'   : MPC_framework/init_ack_messages receiver
 * '<S10>'  : MPC_framework/positive//negative buttons receiver
 * '<S11>'  : MPC_framework/request_incremental_value sender
 * '<S12>'  : MPC_framework/stop message sender
 * '<S13>'  : MPC_framework/stop_button receiver
 * '<S14>'  : MPC_framework/DA_out_value sender/TouCAN Transmit
 * '<S15>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S16>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S17>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output
 * '<S18>'  : MPC_framework/DA_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S19>'  : MPC_framework/Init 1 message sender/TouCAN Transmit
 * '<S20>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S21>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S22>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output
 * '<S23>'  : MPC_framework/Init 1 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S24>'  : MPC_framework/Init 2 message sender/TouCAN Transmit
 * '<S25>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Configurable Outport Control
 * '<S26>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S27>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output
 * '<S28>'  : MPC_framework/Init 2 message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S29>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive
 * '<S30>'  : MPC_framework/incremental_in_value receiver/incremental_in_value unpacking
 * '<S31>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Configurable Outport Control
 * '<S32>'  : MPC_framework/incremental_in_value receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S33>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit
 * '<S34>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S35>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S36>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output
 * '<S37>'  : MPC_framework/incremental_out_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S38>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)
 * '<S39>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1
 * '<S40>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive
 * '<S41>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1
 * '<S42>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)/Compare To Constant
 * '<S43>'  : MPC_framework/init_ack_messages receiver/CAN Message Unpacking (CANdb)1/Compare To Constant
 * '<S44>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Configurable Outport Control
 * '<S45>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive/Non-Configurable Outport Control1
 * '<S46>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Configurable Outport Control
 * '<S47>'  : MPC_framework/init_ack_messages receiver/TouCAN Receive1/Non-Configurable Outport Control1
 * '<S48>'  : MPC_framework/positive//negative buttons receiver/negative_button message receive
 * '<S49>'  : MPC_framework/positive//negative buttons receiver/negative_button message unpacking
 * '<S50>'  : MPC_framework/positive//negative buttons receiver/positive_button message receive
 * '<S51>'  : MPC_framework/positive//negative buttons receiver/positive_button message unpacking
 * '<S52>'  : MPC_framework/positive//negative buttons receiver/negative_button message receive/Configurable Outport Control
 * '<S53>'  : MPC_framework/positive//negative buttons receiver/negative_button message receive/Non-Configurable Outport Control1
 * '<S54>'  : MPC_framework/positive//negative buttons receiver/positive_button message receive/Configurable Outport Control
 * '<S55>'  : MPC_framework/positive//negative buttons receiver/positive_button message receive/Non-Configurable Outport Control1
 * '<S56>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit
 * '<S57>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Configurable Outport Control
 * '<S58>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S59>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output
 * '<S60>'  : MPC_framework/request_incremental_value sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S61>'  : MPC_framework/stop message sender/TouCAN Transmit
 * '<S62>'  : MPC_framework/stop message sender/TouCAN Transmit/Configurable Outport Control
 * '<S63>'  : MPC_framework/stop message sender/TouCAN Transmit/Non-Configurable Inport Control
 * '<S64>'  : MPC_framework/stop message sender/TouCAN Transmit/Pass through output
 * '<S65>'  : MPC_framework/stop message sender/TouCAN Transmit/Pass through output/Pass through input
 * '<S66>'  : MPC_framework/stop_button receiver/TouCAN Receive
 * '<S67>'  : MPC_framework/stop_button receiver/stop_button message packing
 * '<S68>'  : MPC_framework/stop_button receiver/TouCAN Receive/Configurable Outport Control
 * '<S69>'  : MPC_framework/stop_button receiver/TouCAN Receive/Non-Configurable Outport Control1
 */

#endif                                  /* _RTW_HEADER_MPC_framework_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
