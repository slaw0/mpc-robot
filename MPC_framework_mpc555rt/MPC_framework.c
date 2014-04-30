/*
 * File: MPC_framework.c
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.1070
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Apr 30 19:37:50 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Apr 30 19:37:50 2014
 */

#include "MPC_framework.h"
#include "MPC_framework_private.h"

/* Named constants for block: '<Root>/State Machine' */
#define MPC_framewor_IN_NO_ACTIVE_CHILD (0)
#define MPC_framework_IN_INIT           (1)
#define MPC_framework_IN_INIT_ACK       (2)
#define MPC_framework_IN_OPERATION      (3)
#define MPC_framework_IN_STOPPED        (2)
#define MPC_framework_IN_PRIMITIVE      (4)
#define MPC_framework_IN_CONTROLLER     (3)
#define MPC_framework_IN_MOVING         (1)
#define MPC_framework_IN_POSITIVE_MOV   (2)
#define MPC_framework_IN_NEGATIVE_MOV   (1)
#define MPC_framework_IN_CONFIG         (2)
#define MPC_framework_IN_BLUETOOTH      (1)
#define MPC_framework_IN_TRAJECTORY     (2)
#define MPC_framework_IN_HOLD           (1)
#define MPC_framework_IN_HOLD_main      (1)

uint8_T _sfEvent_MPC_framework_;

/* Block signals (auto storage) */
BlockIO_MPC_framework MPC_framework_B;

/* Block states (auto storage) */
D_Work_MPC_framework MPC_framework_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_MPC_framework MPC_framework_PrevZCSigState;

/* Real-time model */
RT_MODEL_MPC_framework MPC_framework_M_;
RT_MODEL_MPC_framework *MPC_framework_M = &MPC_framework_M_;

static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */

void MPC_framework_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = rtmStepTask(MPC_framework_M, 1);
}

/* This function implements a deterministic rate-monotonic multitasking
 * scheduler for a system with 2 rates.  The function is called by the
 * generated step function, hence the generated code self-manages all
 * its subrates.
 */

static void rate_monotonic_scheduler(void)
{

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++MPC_framework_M->Timing.TaskCounters.TID[1] == 10) { /* Sample time: [0.1s, 0.0s] */
    MPC_framework_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Shared Utility Functions */
real_T lfcbphdbbaaiimgd_sign(real_T eml_X)
{
  real_T eml_S;
  eml_S = 0.0;
  if((boolean_T)rtIsNaN(eml_X)) {
    return rtNaN;
  } else if(eml_X > 0.0) {
    return 1.0;
  } else if(eml_X < 0.0) {
    return -1.0;
  }
  return eml_S;
}

/* Start for function-call system: '<Root>/controller_message sender' */

void controller_messagesen_Start(void)
{

  /*--- S-Function Block: <S11>/controller_message packing ---*/
  MPC_framework_B.controller_messagepacking.ID = 16U;
  MPC_framework_B.controller_messagepacking.type = 0U;
  MPC_framework_B.controller_messagepacking.LENGTH = 1U;
}

/* Output and update for function-call system: '<Root>/controller_message sender' */

void controller_messagesen(void)
{

  /*--- S-Function Block: <S11>/controller_message packing ---*/
  {
    /* final output words that individual signals are |'d into */
    uint32_T output_word0 = 0;
    uint32_T output_word1 = 0;

    /* variable to hold each scaled signal to be packed */
    uint32_T scaledSignal = 0;

    /* --------------- START Packing CANdb signal controller_message ------------------ 
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LittleEndian 
     *  dataType                = UNSIGNED
     *  signalType              = STANDARD
     *  offset                  = 0.0 
     *  factor                  = 1.0 
     * -----------------------------------------------------------------------*/

    /* -- Scaling and Offset --- */

    {

      /* widen the input datatype, uint8_T, 
         to the processor word size, uint32_T,
         for the scaling calculation */

      uint32_T result = (uint32_T) MPC_framework_B.controller_message;

      /* no scaling required */

      scaledSignal = result;
    }

    {
      /* create temporary storage for packing */
      uint32_T working_word0;

      /* -- pack the signal --- */
      scaledSignal &= 0xFF;
      working_word0 = scaledSignal;

      /* The signal is to be packed in little endian format
         No need to reverse the bytes in each word */

      output_word0 |= working_word0;
    }

    /* ------ END Packing CANdb signal controller_message  ----- */

    /* CAN message byte array is not guaranteed to be word aligned,
     * copy bytes individually from the output_words */
    MPC_framework_B.controller_messagepacking.DATA[0] =
      (uint8_T) output_word0;

    MPC_framework_B.controller_messagepacking.DATA[1] =
      (uint8_T) (output_word0 >> 8);

    MPC_framework_B.controller_messagepacking.DATA[2] =
      (uint8_T) (output_word0 >> 16);

    MPC_framework_B.controller_messagepacking.DATA[3] =
      (uint8_T) (output_word0 >> 24);

    MPC_framework_B.controller_messagepacking.DATA[4] =
      (uint8_T) output_word1;

    MPC_framework_B.controller_messagepacking.DATA[5] =
      (uint8_T) (output_word1 >> 8);

    MPC_framework_B.controller_messagepacking.DATA[6] =
      (uint8_T) (output_word1 >> 16);

    MPC_framework_B.controller_messagepacking.DATA[7] =
      (uint8_T) (output_word1 >> 24);
  }

  /* Send message using priority queue and shared TouCAN buffer(s) */
  sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.controller_messagepacking);
}

/* Functions for block: '<Root>/State Machine' */

static void MPC_framework_PRIMITIVE(void );

static void MPC_framework_PRIMITIVE(void )
{
  if(MPC_framework_B.CANMessageUnpackingCANdb_d == 2.0) {
    switch(MPC_framework_DWork.StateMachine.is_PRIMITIVE) {
     case MPC_framework_IN_MOVING:
      MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 0U;
      MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 0U;
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      break;
     case MPC_framework_IN_STOPPED:
      MPC_framework_B.stop_trigger = 0U;
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      break;
    }
    MPC_framework_DWork.StateMachine.is_OPERATION =
      (uint8_T)MPC_framework_IN_CONTROLLER;
    MPC_framework_B.operation_mode = 2U;
    MPC_framework_B.motor1_reference =
      MPC_framework_B.TmpHiddenBufferAtSFunctionInp[0];
    MPC_framework_B.motor2_reference =
      MPC_framework_B.TmpHiddenBufferAtSFunctionInp[1];
    MPC_framework_B.trajectory_enable = 0U;
    MPC_framework_B.controller_enable = 1U;
    MPC_framework_B.da_out_trigger = 1.0;
    MPC_framework_DWork.StateMachine.is_CONTROLLER =
      (uint8_T)MPC_framework_IN_HOLD;
    MPC_framework_B.controller_message = 4U;

    controller_messagesen();

    MPC_framework_DWork.StateMachine.trajectory_ready = 0U;
    MPC_framework_DWork.StateMachine.is_HOLD =
      (uint8_T)MPC_framework_IN_HOLD_main;
  } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 8.0) {
    switch(MPC_framework_DWork.StateMachine.is_PRIMITIVE) {
     case MPC_framework_IN_MOVING:
      MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 0U;
      MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 0U;
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      break;
     case MPC_framework_IN_STOPPED:
      MPC_framework_B.stop_trigger = 0U;
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      break;
    }
    MPC_framework_DWork.StateMachine.is_OPERATION =
      (uint8_T)MPC_framework_IN_BLUETOOTH;
    MPC_framework_B.operation_mode = 4U;
  } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 6.0) {
    switch(MPC_framework_DWork.StateMachine.is_PRIMITIVE) {
     case MPC_framework_IN_MOVING:
      MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 0U;
      MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 0U;
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      break;
     case MPC_framework_IN_STOPPED:
      MPC_framework_B.stop_trigger = 0U;
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
      break;
    }
    MPC_framework_DWork.StateMachine.is_OPERATION =
      (uint8_T)MPC_framework_IN_CONFIG;
    MPC_framework_B.operation_mode = 3U;
  } else {
    MPC_framework_B.controller_enable = 0U;
    switch(MPC_framework_DWork.StateMachine.is_PRIMITIVE) {
     case MPC_framework_IN_MOVING:
      if(MPC_framework_B.CANMessageUnpackingCANdb_l == 5) {
        MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
          (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 0U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
          (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 0U;
        MPC_framework_DWork.StateMachine.is_PRIMITIVE =
          (uint8_T)MPC_framework_IN_STOPPED;
        MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p5;
        MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p5;
        MPC_framework_B.da_out_trigger = 1.0;
      } else {
        switch(MPC_framework_DWork.StateMachine.is_SEGMENT_1) {
         case MPC_framework_IN_NEGATIVE_MOV:
          MPC_framework_B.da_out_trigger = 0.0;
          break;
         case MPC_framework_IN_POSITIVE_MOV:
          MPC_framework_B.da_out_trigger = 0.0;
          break;
         default:
          MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
            (uint8_T)MPC_framework_IN_POSITIVE_MOV;
          MPC_framework_B.motor1_reference =
            (real_T)MPC_framework_P.SFunction_p4;
          MPC_framework_B.da_out_trigger = 1.0;
          break;
        }
        switch(MPC_framework_DWork.StateMachine.is_SEGMENT_2) {
         case MPC_framework_IN_NEGATIVE_MOV:
          MPC_framework_B.da_out_trigger = 0.0;
          break;
         case MPC_framework_IN_POSITIVE_MOV:
          MPC_framework_B.da_out_trigger = 0.0;
          break;
         default:
          MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
            (uint8_T)MPC_framework_IN_POSITIVE_MOV;
          MPC_framework_B.motor2_reference =
            (real_T)MPC_framework_P.SFunction_p4;
          MPC_framework_B.da_out_trigger = 1.0;
          break;
        }
      }
      break;
     case MPC_framework_IN_STOPPED:
      if(MPC_framework_B.CANMessageUnpackingCANdb_l == 4) {
        MPC_framework_B.stop_trigger = 0U;
        MPC_framework_DWork.StateMachine.is_PRIMITIVE =
          (uint8_T)MPC_framework_IN_MOVING;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
          (uint8_T)MPC_framework_IN_POSITIVE_MOV;
        MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p4;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
          (uint8_T)MPC_framework_IN_NEGATIVE_MOV;
        MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p3;
        MPC_framework_B.da_out_trigger = 1.0;
      } else if(MPC_framework_B.CANMessageUnpackingCANdb_l == 3) {
        MPC_framework_B.stop_trigger = 0U;
        MPC_framework_DWork.StateMachine.is_PRIMITIVE =
          (uint8_T)MPC_framework_IN_MOVING;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
          (uint8_T)MPC_framework_IN_NEGATIVE_MOV;
        MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p3;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
          (uint8_T)MPC_framework_IN_POSITIVE_MOV;
        MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p4;
        MPC_framework_B.da_out_trigger = 1.0;
      } else if(MPC_framework_B.CANMessageUnpackingCANdb_l == 2) {
        MPC_framework_B.stop_trigger = 0U;
        MPC_framework_DWork.StateMachine.is_PRIMITIVE =
          (uint8_T)MPC_framework_IN_MOVING;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
          (uint8_T)MPC_framework_IN_POSITIVE_MOV;
        MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p4;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
          (uint8_T)MPC_framework_IN_POSITIVE_MOV;
        MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p4;
        MPC_framework_B.da_out_trigger = 1.0;
      } else if(MPC_framework_B.CANMessageUnpackingCANdb_l == 1) {
        MPC_framework_B.stop_trigger = 0U;
        MPC_framework_DWork.StateMachine.is_PRIMITIVE =
          (uint8_T)MPC_framework_IN_MOVING;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_1 =
          (uint8_T)MPC_framework_IN_POSITIVE_MOV;
        MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p4;
        MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 1U;
        MPC_framework_DWork.StateMachine.is_SEGMENT_2 =
          (uint8_T)MPC_framework_IN_POSITIVE_MOV;
        MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p4;
        MPC_framework_B.da_out_trigger = 1.0;
      } else {
        MPC_framework_B.da_out_trigger = 0.0;
      }
      break;
     default:
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framework_IN_STOPPED;
      MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p5;
      MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p5;
      MPC_framework_B.da_out_trigger = 1.0;
      break;
    }
  }
}

/* Initial conditions for atomic system: '<Root>/State Machine' */

void MPC_frame_StateMachine_Init(void)
{

  /* Initialize code for chart: '<Root>/State Machine' */
  MPC_framework_DWork.StateMachine.is_OPERATION = 0U;
  MPC_framework_DWork.StateMachine.is_CONTROLLER = 0U;
  MPC_framework_DWork.StateMachine.is_HOLD = 0U;
  MPC_framework_DWork.StateMachine.is_PRIMITIVE = 0U;
  MPC_framework_DWork.StateMachine.is_active_SEGMENT_1 = 0U;
  MPC_framework_DWork.StateMachine.is_SEGMENT_1 = 0U;
  MPC_framework_DWork.StateMachine.is_active_SEGMENT_2 = 0U;
  MPC_framework_DWork.StateMachine.is_SEGMENT_2 = 0U;
  MPC_framework_DWork.StateMachine.is_c1_MPC_framework = 0U;
  MPC_framework_DWork.StateMachine.trajectory_ready = 0U;
  MPC_framework_B.init_out_value = 0U;
  MPC_framework_B.init_out_enable = 0U;
  MPC_framework_B.init_out_trigger = 0U;
  MPC_framework_B.stop_trigger = 0U;
  MPC_framework_B.motor1_reference = 32768.0;
  MPC_framework_B.motor2_reference = 32768.0;
  MPC_framework_B.controller_enable = 0U;
  MPC_framework_B.da_out_trigger = 0.0;
  MPC_framework_B.operation_mode = MAX_uint8_T;
  MPC_framework_B.sync_command = 0U;
  MPC_framework_B.controller_message = 0U;
  MPC_framework_B.trajectory_enable = 0U;
  MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
    (uint8_T)MPC_framework_IN_INIT;
  MPC_framework_B.init_out_value = MPC_framework_P.SFunction_p1;
  MPC_framework_B.init_out_enable = 1U;
}

/* Start for atomic system: '<Root>/State Machine' */

void MPC_fram_StateMachine_Start(void)
{

  controller_messagesen_Start();
}

/* Output and update for atomic system: '<Root>/State Machine' */

void MPC_fram_StateMachine(void)
{

  /* SignalConversion: '<S8>/TmpHiddenBufferAt SFunction Inport5' */
  MPC_framework_B.TmpHiddenBufferAtSFunctionInp[0] = MPC_framework_B.Gain;
  MPC_framework_B.TmpHiddenBufferAtSFunctionInp[1] = MPC_framework_B.Gain1;

  /* Stateflow: '<Root>/State Machine' */
  {
    uint8_T sf_previousEvent;
    sf_previousEvent = _sfEvent_MPC_framework_;
    _sfEvent_MPC_framework_ = CALL_EVENT;
    if((_sfEvent_MPC_framework_ == CALL_EVENT) &&
     (MPC_framework_DWork.StateMachine.temporalCounter_i1 < MAX_uint32_T)) {
      MPC_framework_DWork.StateMachine.temporalCounter_i1++;
    }
    switch(MPC_framework_DWork.StateMachine.is_c1_MPC_framework) {
     case MPC_framework_IN_INIT:
      if((MPC_framework_B.Compare_i == 1) && (MPC_framework_B.Compare == 1)) {
        MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
          (uint8_T)MPC_framework_IN_INIT_ACK;
        MPC_framework_B.init_out_enable = 0U;
        MPC_framework_B.init_out_value = MPC_framework_P.SFunction_p2;
        MPC_framework_B.init_out_trigger = 1U;
      }
      goto sf_label_8_1_1;
      break;
     case MPC_framework_IN_INIT_ACK:
      MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
        (uint8_T)MPC_framework_IN_OPERATION;
      MPC_framework_DWork.StateMachine.is_OPERATION =
        (uint8_T)MPC_framework_IN_PRIMITIVE;
      MPC_framework_B.operation_mode = 1U;
      MPC_framework_DWork.StateMachine.is_PRIMITIVE =
        (uint8_T)MPC_framework_IN_STOPPED;
      MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p5;
      MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p5;
      MPC_framework_B.da_out_trigger = 1.0;
      goto sf_label_8_1_1;
      break;
     case MPC_framework_IN_OPERATION:
      switch(MPC_framework_DWork.StateMachine.is_OPERATION) {
       case MPC_framework_IN_BLUETOOTH:
        if(MPC_framework_B.CANMessageUnpackingCANdb_d == 1.0) {
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_PRIMITIVE;
          MPC_framework_B.operation_mode = 1U;
          MPC_framework_DWork.StateMachine.is_PRIMITIVE =
            (uint8_T)MPC_framework_IN_STOPPED;
          MPC_framework_B.motor1_reference =
            (real_T)MPC_framework_P.SFunction_p5;
          MPC_framework_B.motor2_reference =
            (real_T)MPC_framework_P.SFunction_p5;
          MPC_framework_B.da_out_trigger = 1.0;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 2.0) {
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONTROLLER;
          MPC_framework_B.operation_mode = 2U;
          MPC_framework_B.motor1_reference =
            MPC_framework_B.TmpHiddenBufferAtSFunctionInp[0];
          MPC_framework_B.motor2_reference =
            MPC_framework_B.TmpHiddenBufferAtSFunctionInp[1];
          MPC_framework_B.trajectory_enable = 0U;
          MPC_framework_B.controller_enable = 1U;
          MPC_framework_B.da_out_trigger = 1.0;
          MPC_framework_DWork.StateMachine.is_CONTROLLER =
            (uint8_T)MPC_framework_IN_HOLD;
          MPC_framework_B.controller_message = 4U;

          controller_messagesen();

          MPC_framework_DWork.StateMachine.trajectory_ready = 0U;
          MPC_framework_DWork.StateMachine.is_HOLD =
            (uint8_T)MPC_framework_IN_HOLD_main;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 6.0) {
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONFIG;
          MPC_framework_B.operation_mode = 3U;
        } else {
          MPC_framework_B.controller_enable = 0U;
        }
        goto sf_label_8_1_1;
        break;
       case MPC_framework_IN_CONFIG:
        if(MPC_framework_B.CANMessageUnpackingCANdb_d == 1.0) {
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_PRIMITIVE;
          MPC_framework_B.operation_mode = 1U;
          MPC_framework_DWork.StateMachine.is_PRIMITIVE =
            (uint8_T)MPC_framework_IN_STOPPED;
          MPC_framework_B.motor1_reference =
            (real_T)MPC_framework_P.SFunction_p5;
          MPC_framework_B.motor2_reference =
            (real_T)MPC_framework_P.SFunction_p5;
          MPC_framework_B.da_out_trigger = 1.0;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 2.0) {
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONTROLLER;
          MPC_framework_B.operation_mode = 2U;
          MPC_framework_B.motor1_reference =
            MPC_framework_B.TmpHiddenBufferAtSFunctionInp[0];
          MPC_framework_B.motor2_reference =
            MPC_framework_B.TmpHiddenBufferAtSFunctionInp[1];
          MPC_framework_B.trajectory_enable = 0U;
          MPC_framework_B.controller_enable = 1U;
          MPC_framework_B.da_out_trigger = 1.0;
          MPC_framework_DWork.StateMachine.is_CONTROLLER =
            (uint8_T)MPC_framework_IN_HOLD;
          MPC_framework_B.controller_message = 4U;

          controller_messagesen();

          MPC_framework_DWork.StateMachine.trajectory_ready = 0U;
          MPC_framework_DWork.StateMachine.is_HOLD =
            (uint8_T)MPC_framework_IN_HOLD_main;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 8.0) {
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_BLUETOOTH;
          MPC_framework_B.operation_mode = 4U;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 7.0) {
          MPC_framework_B.sync_command = 4U;
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONFIG;
          MPC_framework_B.operation_mode = 3U;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 5.0) {
          MPC_framework_B.sync_command = 3U;
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONFIG;
          MPC_framework_B.operation_mode = 3U;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 4.0) {
          MPC_framework_B.sync_command = 2U;
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONFIG;
          MPC_framework_B.operation_mode = 3U;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 3.0) {
          MPC_framework_B.sync_command = 1U;
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONFIG;
          MPC_framework_B.operation_mode = 3U;
        } else {
          MPC_framework_B.controller_enable = 0U;
          MPC_framework_B.sync_command = 0U;
        }
        goto sf_label_8_1_1;
        break;
       case MPC_framework_IN_CONTROLLER:
        if(MPC_framework_B.CANMessageUnpackingCANdb_d == 1.0) {
          switch(MPC_framework_DWork.StateMachine.is_CONTROLLER) {
           case MPC_framework_IN_HOLD:
            MPC_framework_DWork.StateMachine.is_HOLD =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            MPC_framework_DWork.StateMachine.is_CONTROLLER =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            break;
           case MPC_framework_IN_TRAJECTORY:
            MPC_framework_B.motor1_reference =
              MPC_framework_DWork.invgeo_alpha_1;
            MPC_framework_B.motor2_reference =
              MPC_framework_DWork.invgeo_alpha_2;
            MPC_framework_B.trajectory_enable = 0U;
            MPC_framework_DWork.StateMachine.is_CONTROLLER =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            break;
          }
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_PRIMITIVE;
          MPC_framework_B.operation_mode = 1U;
          MPC_framework_DWork.StateMachine.is_PRIMITIVE =
            (uint8_T)MPC_framework_IN_STOPPED;
          MPC_framework_B.motor1_reference =
            (real_T)MPC_framework_P.SFunction_p5;
          MPC_framework_B.motor2_reference =
            (real_T)MPC_framework_P.SFunction_p5;
          MPC_framework_B.da_out_trigger = 1.0;
          goto sf_label_8_1_1;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 8.0) {
          switch(MPC_framework_DWork.StateMachine.is_CONTROLLER) {
           case MPC_framework_IN_HOLD:
            MPC_framework_DWork.StateMachine.is_HOLD =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            MPC_framework_DWork.StateMachine.is_CONTROLLER =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            break;
           case MPC_framework_IN_TRAJECTORY:
            MPC_framework_B.motor1_reference =
              MPC_framework_DWork.invgeo_alpha_1;
            MPC_framework_B.motor2_reference =
              MPC_framework_DWork.invgeo_alpha_2;
            MPC_framework_B.trajectory_enable = 0U;
            MPC_framework_DWork.StateMachine.is_CONTROLLER =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            break;
          }
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_BLUETOOTH;
          MPC_framework_B.operation_mode = 4U;
          goto sf_label_8_1_1;
        } else if(MPC_framework_B.CANMessageUnpackingCANdb_d == 6.0) {
          switch(MPC_framework_DWork.StateMachine.is_CONTROLLER) {
           case MPC_framework_IN_HOLD:
            MPC_framework_DWork.StateMachine.is_HOLD =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            MPC_framework_DWork.StateMachine.is_CONTROLLER =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            break;
           case MPC_framework_IN_TRAJECTORY:
            MPC_framework_B.motor1_reference =
              MPC_framework_DWork.invgeo_alpha_1;
            MPC_framework_B.motor2_reference =
              MPC_framework_DWork.invgeo_alpha_2;
            MPC_framework_B.trajectory_enable = 0U;
            MPC_framework_DWork.StateMachine.is_CONTROLLER =
              (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
            break;
          }
          MPC_framework_DWork.StateMachine.is_OPERATION =
            (uint8_T)MPC_framework_IN_CONFIG;
          MPC_framework_B.operation_mode = 3U;
          goto sf_label_8_1_1;
        } else {
          switch(MPC_framework_DWork.StateMachine.is_CONTROLLER) {
           case MPC_framework_IN_HOLD:
            if((MPC_framework_B.CANMessageUnpackingCANdb_d == 9.0) &&
             (MPC_framework_DWork.StateMachine.trajectory_ready == 1) &&
             (MPC_framework_DWork.invgeo_error == 0)) {
              MPC_framework_DWork.StateMachine.is_HOLD =
                (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
              MPC_framework_DWork.StateMachine.is_CONTROLLER =
                (uint8_T)MPC_framework_IN_TRAJECTORY;
              MPC_framework_DWork.StateMachine.temporalCounter_i1 = 0U;
              MPC_framework_B.controller_message = 3U;

              controller_messagesen();

              MPC_framework_B.trajectory_enable = 1U;
              goto sf_label_8_1_1;
            } else if(MPC_framework_B.LogicalOperator == 1) {
              if(MPC_framework_DWork.invgeo_error == 0) {
                MPC_framework_B.controller_message = 1U;
              } else if(MPC_framework_DWork.invgeo_error == 1) {
                MPC_framework_B.controller_message = 2U;
              } else {
                goto sf_label_8_1_1;
              }
            } else {
              goto sf_label_8_1_1;
            }
            break;
           case MPC_framework_IN_TRAJECTORY:
            if((_sfEvent_MPC_framework_ == CALL_EVENT) &&
             (MPC_framework_DWork.StateMachine.temporalCounter_i1 ==
              (uint32_T)MPC_framework_P.SFunction_p6)) {
              MPC_framework_B.motor1_reference =
                MPC_framework_DWork.invgeo_alpha_1;
              MPC_framework_B.motor2_reference =
                MPC_framework_DWork.invgeo_alpha_2;
              MPC_framework_B.trajectory_enable = 0U;
              MPC_framework_DWork.StateMachine.is_CONTROLLER =
                (uint8_T)MPC_framework_IN_HOLD;
              MPC_framework_B.controller_message = 4U;

              controller_messagesen();

              MPC_framework_DWork.StateMachine.trajectory_ready = 0U;
              MPC_framework_DWork.StateMachine.is_HOLD =
                (uint8_T)MPC_framework_IN_HOLD_main;
            }
            goto sf_label_8_1_1;
            break;
           default:
            MPC_framework_DWork.StateMachine.is_CONTROLLER =
              (uint8_T)MPC_framework_IN_HOLD;
            MPC_framework_B.controller_message = 4U;

            controller_messagesen();

            MPC_framework_DWork.StateMachine.trajectory_ready = 0U;
            MPC_framework_DWork.StateMachine.is_HOLD =
              (uint8_T)MPC_framework_IN_HOLD_main;
            goto sf_label_8_1_1;
            break;
          }
        }
        break;
       case MPC_framework_IN_PRIMITIVE:
        MPC_framework_PRIMITIVE();
        goto sf_label_8_1_1;
        break;
       default:
        MPC_framework_DWork.StateMachine.is_OPERATION =
          (uint8_T)MPC_framework_IN_PRIMITIVE;
        MPC_framework_B.operation_mode = 1U;
        MPC_framework_DWork.StateMachine.is_PRIMITIVE =
          (uint8_T)MPC_framework_IN_STOPPED;
        MPC_framework_B.motor1_reference = (real_T)MPC_framework_P.SFunction_p5;
        MPC_framework_B.motor2_reference = (real_T)MPC_framework_P.SFunction_p5;
        MPC_framework_B.da_out_trigger = 1.0;
        goto sf_label_8_1_1;
        break;
      }
      break;
     default:
      MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
        (uint8_T)MPC_framework_IN_INIT;
      MPC_framework_B.init_out_value = MPC_framework_P.SFunction_p1;
      MPC_framework_B.init_out_enable = 1U;
      goto sf_label_8_1_1;
      break;
    }
    MPC_framework_DWork.StateMachine.is_HOLD =
      (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;

    controller_messagesen();

    MPC_framework_DWork.StateMachine.trajectory_ready = 1U;
    MPC_framework_DWork.StateMachine.is_HOLD =
      (uint8_T)MPC_framework_IN_HOLD_main;
    sf_label_8_1_1:;
    _sfEvent_MPC_framework_ = sf_previousEvent;
  }
}

/* Output and update for atomic system:
 *   '<S42>/Joint reference singal 1'
 *   '<S42>/Joint reference singal 2'
 */

void Jointreferencesingal(real_T rtu_a0, real_T rtu_a1, real_T rtu_a2, real_T
 rtu_a3, real_T rtu_a4, real_T rtu_a5, real_T rtu_t_sim, real_T rtu_t_end,
 rtB_Jointreferencesingal *localB)
{
  /* local block i/o variables*/
  real_T rtb_qap;
  real_T rtb_qapp;

  /* Embedded MATLAB: '<S42>/Joint reference singal 1' */
  {
    real_T eml_t_sim;
    real_T eml_em_dv0[6];
    real_T eml_em_dv1[6];
    real_T eml_em_dv2[6];
    int32_T eml_em_i0;
    real_T eml_em_dv3[18];
    real_T eml_a0[6];
    real_T eml_Q[3];
    int32_T eml_em_i1;
    eml_t_sim = rtu_t_sim;
    if(rtu_t_sim >= rtu_t_end) {
      /*  This block supports an embeddable subset of the MATLAB language. */
      /*  See the help menu for details.  */
      eml_t_sim = rtu_t_end;
    }
    eml_em_dv0[0] = pow(eml_t_sim, 5.0) / 20.0;
    eml_em_dv0[1] = pow(eml_t_sim, 4.0) / 12.0;
    eml_em_dv0[2] = pow(eml_t_sim, 3.0) / 6.0;
    eml_em_dv0[3] = pow(eml_t_sim, 2.0) / 2.0;
    eml_em_dv0[4] = eml_t_sim;
    eml_em_dv0[5] = 1.0;
    eml_em_dv1[0] = pow(eml_t_sim, 4.0) / 4.0;
    eml_em_dv1[1] = pow(eml_t_sim, 3.0) / 3.0;
    eml_em_dv1[2] = pow(eml_t_sim, 2.0) / 2.0;
    eml_em_dv1[3] = eml_t_sim;
    eml_em_dv1[4] = 1.0;
    eml_em_dv1[5] = 0.0;
    eml_em_dv2[0] = pow(eml_t_sim, 3.0);
    eml_em_dv2[1] = pow(eml_t_sim, 2.0);
    eml_em_dv2[2] = eml_t_sim;
    eml_em_dv2[3] = 1.0;
    eml_em_dv2[4] = 0.0;
    eml_em_dv2[5] = 0.0;
    for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
      eml_em_dv3[3 * eml_em_i0] = eml_em_dv0[eml_em_i0];
      eml_em_dv3[1 + 3 * eml_em_i0] = eml_em_dv1[eml_em_i0];
      eml_em_dv3[2 + 3 * eml_em_i0] = eml_em_dv2[eml_em_i0];
    }
    eml_a0[0] = rtu_a0;
    eml_a0[1] = rtu_a1;
    eml_a0[2] = rtu_a2;
    eml_a0[3] = rtu_a3;
    eml_a0[4] = rtu_a4;
    eml_a0[5] = rtu_a5;
    for(eml_em_i0 = 0; eml_em_i0 < 3; eml_em_i0++) {
      eml_Q[eml_em_i0] = 0.0;
      for(eml_em_i1 = 0; eml_em_i1 < 6; eml_em_i1++) {
        eml_Q[eml_em_i0] += eml_em_dv3[eml_em_i0 + 3 * eml_em_i1] *
          eml_a0[eml_em_i1];
      }
    }
    localB->qa = eml_Q[0];
    rtb_qap = eml_Q[1];
    rtb_qapp = eml_Q[2];
  }
}

/* Output and update for atomic system:
 *   '<S43>/Trajectory design 1'
 *   '<S43>/Trajectory design 2'
 */

void MP_Trajectorydesign1(real_T rtu_A, real_T rtu_B, real_T rtu_t,
 rtB_MP_Trajectorydesign1 *localB)
{

  /* Embedded MATLAB: '<S43>/Trajectory design 1' */
  {
    int32_T eml_em_i0;
    int32_T eml_em_i1;
    real_T eml_y[36];
    real_T eml_em_dv0[6];
    real_T eml_em_dv1[6];
    real_T eml_em_dv2[6];
    real_T eml_A[36];
    static boolean_T eml_em_bv0[6] = { false, false, false, false, false, true };
    static boolean_T eml_em_bv1[6] = { false, false, false, false, true, false };
    static boolean_T eml_em_bv2[6] = { false, false, false, true, false, false };
    int8_T eml_pivot[6];
    real_T eml_temp;
    int32_T eml_k;
    int32_T eml_c;
    int32_T eml_j;
    real_T eml_B[6];
    real_T eml_Ao[6];
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
      for(eml_em_i1 = 0; eml_em_i1 < 6; eml_em_i1++) {
        eml_y[eml_em_i1 + 6 * eml_em_i0] = 0.0;
      }
    }
    eml_em_dv0[0] = pow(rtu_t, 5.0) / 20.0;
    eml_em_dv0[1] = pow(rtu_t, 4.0) / 12.0;
    eml_em_dv0[2] = pow(rtu_t, 3.0) / 6.0;
    eml_em_dv0[3] = pow(rtu_t, 2.0) / 2.0;
    eml_em_dv0[4] = rtu_t;
    eml_em_dv0[5] = 1.0;
    eml_em_dv1[0] = pow(rtu_t, 4.0) / 4.0;
    eml_em_dv1[1] = pow(rtu_t, 3.0) / 3.0;
    eml_em_dv1[2] = pow(rtu_t, 2.0) / 2.0;
    eml_em_dv1[3] = rtu_t;
    eml_em_dv1[4] = 1.0;
    eml_em_dv1[5] = 0.0;
    eml_em_dv2[0] = pow(rtu_t, 3.0);
    eml_em_dv2[1] = pow(rtu_t, 2.0);
    eml_em_dv2[2] = rtu_t;
    eml_em_dv2[3] = 1.0;
    eml_em_dv2[4] = 0.0;
    eml_em_dv2[5] = 0.0;
    for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
      eml_A[6 * eml_em_i0] = eml_em_dv0[eml_em_i0];
      eml_A[1 + 6 * eml_em_i0] = eml_em_dv1[eml_em_i0];
      eml_A[2 + 6 * eml_em_i0] = eml_em_dv2[eml_em_i0];
      eml_A[3 + 6 * eml_em_i0] = (real_T)eml_em_bv0[eml_em_i0];
      eml_A[4 + 6 * eml_em_i0] = (real_T)eml_em_bv1[eml_em_i0];
      eml_A[5 + 6 * eml_em_i0] = (real_T)eml_em_bv2[eml_em_i0];
      eml_pivot[eml_em_i0] = (int8_T)(1 + eml_em_i0);
    }
    for(eml_em_i0 = 0; eml_em_i0 < 5; eml_em_i0++) {
      eml_em_i1 = eml_em_i0 + 1;
      eml_temp = fabs(eml_A[eml_em_i0 + 6 * eml_em_i0]);
      for(eml_k = eml_em_i0 + 2; eml_k <= 6; eml_k++) {
        if(fabs(eml_A[(eml_k - 1) + 6 * eml_em_i0]) > eml_temp) {
          eml_temp = fabs(eml_A[(eml_k - 1) + 6 * eml_em_i0]);
          eml_em_i1 = eml_k;
        }
      }
      if(eml_em_i1 != eml_em_i0 + 1) {
        for(eml_k = 0; eml_k < 6; eml_k++) {
          eml_temp = eml_A[(eml_em_i1 - 1) + 6 * eml_k];
          eml_A[(eml_em_i1 - 1) + 6 * eml_k] = eml_A[eml_em_i0 + 6 * eml_k];
          eml_A[eml_em_i0 + 6 * eml_k] = eml_temp;
        }
        eml_k = (int32_T)eml_pivot[eml_em_i0];
        eml_pivot[eml_em_i0] = eml_pivot[eml_em_i1 - 1];
        eml_pivot[eml_em_i1 - 1] = (int8_T)eml_k;
      }
      if(eml_A[eml_em_i0 + 6 * eml_em_i0] != 0.0) {
        for(eml_k = eml_em_i0 + 2; eml_k <= 6; eml_k++) {
          eml_A[(eml_k - 1) + 6 * eml_em_i0] /= eml_A[eml_em_i0 + 6 * eml_em_i0];
        }
        for(eml_em_i1 = eml_em_i0 + 2; eml_em_i1 <= 6; eml_em_i1++) {
          for(eml_k = eml_em_i0 + 2; eml_k <= 6; eml_k++) {
            eml_A[(eml_k - 1) + 6 * (eml_em_i1 - 1)] -= eml_A[(eml_k - 1) + 6 *
              eml_em_i0] * eml_A[eml_em_i0 + 6 * (eml_em_i1 - 1)];
          }
        }
      }
    }
    eml_k = 1;
    sf_label_11_0_1:;
    if(eml_k <= 6) {
      if((eml_A[(eml_k - 1) + 6 * (eml_k - 1)] == 0.0) ||
       ((boolean_T)rtIsNaN(eml_A[(eml_k - 1) + 6 * (eml_k - 1)]))) {
        for(eml_em_i0 = 0; eml_em_i0 < 36; eml_em_i0++) {
          eml_y[eml_em_i0] = rtInf;
        }
      } else {
        eml_k++;
        goto sf_label_11_0_1;
      }
    } else {
      for(eml_k = 0; eml_k < 6; eml_k++) {
        eml_c = (int32_T)eml_pivot[eml_k];
        eml_y[eml_k + 6 * (eml_c - 1)] = 1.0;
        for(eml_em_i0 = eml_k + 1; eml_em_i0 <= 6; eml_em_i0++) {
          if(eml_y[(eml_em_i0 - 1) + 6 * (eml_c - 1)] != 0.0) {
            for(eml_em_i1 = eml_em_i0 + 1; eml_em_i1 <= 6; eml_em_i1++) {
              eml_y[(eml_em_i1 - 1) + 6 * (eml_c - 1)] -= eml_y[(eml_em_i0 - 1)
                + 6 * (eml_c - 1)] * eml_A[(eml_em_i1 - 1) + 6 * (eml_em_i0 -
                1)];
            }
          }
        }
        for(eml_em_i1 = 6; eml_em_i1 > 0; eml_em_i1 += -1) {
          eml_y[(eml_em_i1 - 1) + 6 * (eml_c - 1)] /= eml_A[(eml_em_i1 - 1) + 6
            * (eml_em_i1 - 1)];
          if(eml_y[(eml_em_i1 - 1) + 6 * (eml_c - 1)] != 0.0) {
            eml_j = eml_em_i1 - 1;
            for(eml_em_i0 = 1; eml_em_i0 <= eml_j; eml_em_i0++) {
              eml_y[(eml_em_i0 - 1) + 6 * (eml_c - 1)] -= eml_y[(eml_em_i1 - 1)
                + 6 * (eml_c - 1)] * eml_A[(eml_em_i0 - 1) + 6 * (eml_em_i1 -
                1)];
            }
          }
        }
      }
    }
    eml_B[0] = rtu_B;
    eml_B[1] = 0.0;
    eml_B[2] = 0.0;
    eml_B[3] = rtu_A;
    eml_B[4] = 0.0;
    eml_B[5] = 0.0;
    for(eml_em_i1 = 0; eml_em_i1 < 6; eml_em_i1++) {
      eml_Ao[eml_em_i1] = 0.0;
      for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
        eml_Ao[eml_em_i1] += eml_y[eml_em_i1 + 6 * eml_em_i0] * eml_B[eml_em_i0];
      }
    }
    localB->a0 = eml_Ao[0];
    localB->a1 = eml_Ao[1];
    localB->a2 = eml_Ao[2];
    localB->a3 = eml_Ao[3];
    localB->a4 = eml_Ao[4];
    localB->a5 = eml_Ao[5];
  }
}

/* Model step function for TID0 */

void MPC_framework_step0(void)          /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_motor1_reference;
  real_T rtb_DataStoreRead;
  real_T rtb_motor2_reference;
  real_T rtb_DataStoreRead1;
  real_T rtb_DiscreteTimeIntegrato;
  real_T rtb_Sum;
  uint8_T rtb_Compare;
  uint8_T rtb_Edge;
  boolean_T rtb_LogicalOperator;

  {                                     /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Memory: '<S41>/Hidden_Mem_for_Latch_at_inp_port_2_of_Init' */
  rtb_motor1_reference = MPC_framework_DWork.Hidden_Mem_for_Latch_at_inp_por;

  /* DataStoreRead: '<S9>/Data Store Read' */
  rtb_DataStoreRead = MPC_framework_DWork.invgeo_alpha_1;

  /* Memory: '<S41>/Hidden_Mem_for_Latch_at_inp_port_4_of_Init' */
  rtb_motor2_reference = MPC_framework_DWork.Hidden_Mem_for_Latch_at_inp_p_l;

  /* DataStoreRead: '<S9>/Data Store Read1' */
  rtb_DataStoreRead1 = MPC_framework_DWork.invgeo_alpha_2;

  /* Block: <S76>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime),&GlobalModuleCAN_A,7) ==
   MSG_RECEIVED ){

    /* Output and update for function-call system: '<S15>/input_coords message unpacking' */

    /*--- S-Function Block: <S77>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime.DATA[0]
        | (MPC_framework_B.Datarealtime.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime.DATA[4]
        | (MPC_framework_B.Datarealtime.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal y ------------------ 
       *  startBit                = 16
       *  length                  = 16
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = SIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0 >> 16;
        unscaledSignal &= 0xFFFF;
      }

      /* -- sign extend the unpacked signal --- */
      unscaledSignal = ( (unscaledSignal >> 15 ) & 0x1 ) ? ((uint32_T)
        0xFFFF0000) | unscaledSignal : unscaledSignal;

      {
        /* map scaledValue back to a real taking care of sign */
        {
          int32_T temp = (int32_T) unscaledSignal;
          MPC_framework_B.CANMessageUnpackingCANdb_o = (real64_T) temp;
        }

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal y  ----- */

      /* --------------- START Unpacking CANdb signal x ------------------ 
       *  startBit                = 0
       *  length                  = 16
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = SIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFFFF;
      }

      /* -- sign extend the unpacked signal --- */
      unscaledSignal = ( (unscaledSignal >> 15 ) & 0x1 ) ? ((uint32_T)
        0xFFFF0000) | unscaledSignal : unscaledSignal;

      {
        /* map scaledValue back to a real taking care of sign */
        {
          int32_T temp = (int32_T) unscaledSignal;
          MPC_framework_B.CANMessageUnpackingCANdb_g = (real64_T) temp;
        }

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal x  ----- */
    }
  }

  /* Block: <S57>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_p),&GlobalModuleCAN_A,4)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S12>/incremental_in_value unpacking' */

    /*--- S-Function Block: <S58>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_p.DATA[0]
        | (MPC_framework_B.Datarealtime_p.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_p.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_p.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_p.DATA[4]
        | (MPC_framework_B.Datarealtime_p.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_p.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_p.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal cntr1 ------------------ 
       *  startBit                = 0
       *  length                  = 24
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFFFFFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_h = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal cntr1  ----- */

      /* --------------- START Unpacking CANdb signal cntr2 ------------------ 
       *  startBit                = 24
       *  length                  = 24
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;
        uint32_T working_word1;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        working_word1 = input_word1;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0 >> 24;
        unscaledSignal |= working_word1 << 8;
        unscaledSignal &= 0xFFFFFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_c = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal cntr2  ----- */
    }
  }

  {
    real_T uDivRound;

    /* Sum: '<S12>/Sum' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rtb_Sum = MPC_framework_B.CANMessageUnpackingCANdb_h -
      MPC_framework_P.Constant_Value;

    /* Math: '<S12>/Math Function' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    if(MPC_framework_P.Constant1_Value == 0.0) {
      MPC_framework_B.MathFunction = rtb_Sum;
    } else if(MPC_framework_P.Constant1_Value <=
     floor(MPC_framework_P.Constant1_Value)) {
      MPC_framework_B.MathFunction = rtb_Sum - floor(rtb_Sum /
        MPC_framework_P.Constant1_Value) * MPC_framework_P.Constant1_Value;
    } else {
      rtb_Sum /= MPC_framework_P.Constant1_Value;
      uDivRound = floor(fabs(rtb_Sum) + 0.5);
      if(rtb_Sum < 0.0) {
        uDivRound = -uDivRound;
      }
      if(fabs(rtb_Sum - uDivRound) <= fabs(rtb_Sum) * DBL_EPSILON) {
        MPC_framework_B.MathFunction = 0.0;
      } else {
        MPC_framework_B.MathFunction = (rtb_Sum - floor(rtb_Sum)) *
          MPC_framework_P.Constant1_Value;
      }
    }

    /* Gain: '<S12>/Gain' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Product: '<S12>/Divide'
     */
    MPC_framework_B.Gain = MPC_framework_B.MathFunction /
      MPC_framework_P.Constant1_Value * MPC_framework_P.Gain_Gain;

    /* Sum: '<S12>/Sum1' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rtb_Sum = MPC_framework_B.CANMessageUnpackingCANdb_c -
      MPC_framework_P.Constant_Value;

    /* Math: '<S12>/Math Function1' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    if(MPC_framework_P.Constant1_Value == 0.0) {
      MPC_framework_B.MathFunction1 = rtb_Sum;
    } else if(MPC_framework_P.Constant1_Value <=
     floor(MPC_framework_P.Constant1_Value)) {
      MPC_framework_B.MathFunction1 = rtb_Sum - floor(rtb_Sum /
        MPC_framework_P.Constant1_Value) * MPC_framework_P.Constant1_Value;
    } else {
      rtb_Sum /= MPC_framework_P.Constant1_Value;
      uDivRound = floor(fabs(rtb_Sum) + 0.5);
      if(rtb_Sum < 0.0) {
        uDivRound = -uDivRound;
      }
      if(fabs(rtb_Sum - uDivRound) <= fabs(rtb_Sum) * DBL_EPSILON) {
        MPC_framework_B.MathFunction1 = 0.0;
      } else {
        MPC_framework_B.MathFunction1 = (rtb_Sum - floor(rtb_Sum)) *
          MPC_framework_P.Constant1_Value;
      }
    }

    /* Gain: '<S12>/Gain1' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Product: '<S12>/Divide1'
     */
    MPC_framework_B.Gain1 = MPC_framework_B.MathFunction1 /
      MPC_framework_P.Constant1_Value * MPC_framework_P.Gain1_Gain;

    /* Outputs for atomic SubSystem: '<Root>/Inverse geometry' */

    /* Logic: '<S6>/Logical Operator' incorporates:
     *  RelationalOperator: '<S37>/FixPt Relational Operator'
     *  RelationalOperator: '<S38>/FixPt Relational Operator'
     *  UnitDelay: '<S37>/Delay Input1'
     *  UnitDelay: '<S38>/Delay Input1'
     */
    MPC_framework_B.LogicalOperator =
      ((MPC_framework_B.CANMessageUnpackingCANdb_o !=
      MPC_framework_DWork.DelayInput1_DSTATE) ||
      (MPC_framework_B.CANMessageUnpackingCANdb_g !=
      MPC_framework_DWork.DelayInput1_DSTATE_i));

    /* Outputs for trigger SubSystem: '<S6>/Subsystem' */
    if((MPC_framework_B.LogicalOperator > 0) &&
     (MPC_framework_PrevZCSigState.Subsystem_ZCE == 0)) {

      /* Embedded MATLAB: '<S39>/invgeo' incorporates:
       *  Constant: '<S6>/a1'
       *  Constant: '<S6>/a2'
       */
      {
        real_T eml_y;
        real_T eml_z;
        uint8_T eml_error;
        real_T eml_b_z;
        real_T eml_c_z;
        real_T eml_r;
        eml_y = sqrt(pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
         pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0));
        if((pow(eml_y, 2.0) > pow(MPC_framework_P.a1_Value, 2.0) +
          pow(MPC_framework_P.a2_Value, 2.0)) || (eml_y <
          MPC_framework_P.a1_Value - MPC_framework_P.a2_Value)) {
          eml_z = MPC_framework_B.Gain;
          eml_y = MPC_framework_B.Gain1;
          eml_error = 1U;
        } else {
          eml_y = MPC_framework_P.a1_Value + MPC_framework_P.a2_Value *
            ((((pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
              pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0)) -
             pow(MPC_framework_P.a1_Value, 2.0)) - pow(MPC_framework_P.a2_Value,
             2.0)) / (2.0 * MPC_framework_P.a1_Value *
            MPC_framework_P.a2_Value));
          eml_z = (eml_y * MPC_framework_B.CANMessageUnpackingCANdb_g +
            MPC_framework_B.CANMessageUnpackingCANdb_o *
            sqrt((pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
             pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0)) - pow(eml_y,
             2.0))) / (pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
           pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0));
          eml_b_z = (eml_y * MPC_framework_B.CANMessageUnpackingCANdb_g -
            MPC_framework_B.CANMessageUnpackingCANdb_o *
            sqrt((pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
             pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0)) - pow(eml_y,
             2.0))) / (pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
           pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0));
          eml_c_z = (eml_y * MPC_framework_B.CANMessageUnpackingCANdb_o +
            MPC_framework_B.CANMessageUnpackingCANdb_g *
            sqrt((pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
             pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0)) - pow(eml_y,
             2.0))) / (pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
           pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0));
          eml_y = (eml_y * MPC_framework_B.CANMessageUnpackingCANdb_o -
            MPC_framework_B.CANMessageUnpackingCANdb_g *
            sqrt((pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
             pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0)) - pow(eml_y,
             2.0))) / (pow(MPC_framework_B.CANMessageUnpackingCANdb_o, 2.0) +
           pow(MPC_framework_B.CANMessageUnpackingCANdb_g, 2.0));
          if(((boolean_T)rtIsNaN(eml_y)) || ((boolean_T)rtIsNaN(eml_z))) {
            eml_r = rtNaN;
          } else if(((boolean_T)rtIsInf(eml_z)) && ((boolean_T)rtIsInf(eml_y))) {
            eml_r = rt_atan2(lfcbphdbbaaiimgd_sign(eml_z),
             lfcbphdbbaaiimgd_sign(eml_y));
          } else if(eml_y == 0.0) {
            if(eml_z > 0.0) {
              eml_r = 1.5707963267948966E+000;
            } else if(eml_z < 0.0) {
              eml_r = -1.5707963267948966E+000;
            } else {
              eml_r = 0.0;
            }
          } else {
            eml_r = rt_atan2(eml_z, eml_y);
          }
          if(((boolean_T)rtIsNaN(eml_c_z)) || ((boolean_T)rtIsNaN(eml_b_z))) {
            eml_c_z = rtNaN;
          } else if(((boolean_T)rtIsInf(eml_b_z)) &&
           ((boolean_T)rtIsInf(eml_c_z))) {
            eml_c_z = rt_atan2(lfcbphdbbaaiimgd_sign(eml_b_z),
             lfcbphdbbaaiimgd_sign(eml_c_z));
          } else if(eml_c_z == 0.0) {
            if(eml_b_z > 0.0) {
              eml_c_z = 1.5707963267948966E+000;
            } else if(eml_b_z < 0.0) {
              eml_c_z = -1.5707963267948966E+000;
            } else {
              eml_c_z = 0.0;
            }
          } else {
            eml_c_z = rt_atan2(eml_b_z, eml_c_z);
          }
          eml_y = (MPC_framework_B.CANMessageUnpackingCANdb_o -
            MPC_framework_P.a1_Value * cos(eml_r)) / MPC_framework_P.a2_Value;
          eml_z = (MPC_framework_B.CANMessageUnpackingCANdb_g -
            MPC_framework_P.a1_Value * sin(eml_r)) / MPC_framework_P.a2_Value;
          if(((boolean_T)rtIsNaN(eml_y)) || ((boolean_T)rtIsNaN(eml_z))) {
            eml_y = rtNaN;
          } else if(((boolean_T)rtIsInf(eml_z)) && ((boolean_T)rtIsInf(eml_y))) {
            eml_y = rt_atan2(lfcbphdbbaaiimgd_sign(eml_z),
             lfcbphdbbaaiimgd_sign(eml_y));
          } else if(eml_y == 0.0) {
            if(eml_z > 0.0) {
              eml_y = 1.5707963267948966E+000;
            } else if(eml_z < 0.0) {
              eml_y = -1.5707963267948966E+000;
            } else {
              eml_y = 0.0;
            }
          } else {
            eml_y = rt_atan2(eml_z, eml_y);
          }
          eml_b_z = eml_y - eml_r;
          eml_z = (MPC_framework_B.CANMessageUnpackingCANdb_o -
            MPC_framework_P.a1_Value * cos(eml_c_z)) / MPC_framework_P.a2_Value;
          eml_y = (MPC_framework_B.CANMessageUnpackingCANdb_g -
            MPC_framework_P.a1_Value * sin(eml_c_z)) / MPC_framework_P.a2_Value;
          if(((boolean_T)rtIsNaN(eml_z)) || ((boolean_T)rtIsNaN(eml_y))) {
            eml_y = rtNaN;
          } else if(((boolean_T)rtIsInf(eml_y)) && ((boolean_T)rtIsInf(eml_z))) {
            eml_y = rt_atan2(lfcbphdbbaaiimgd_sign(eml_y),
             lfcbphdbbaaiimgd_sign(eml_z));
          } else if(eml_z == 0.0) {
            if(eml_y > 0.0) {
              eml_y = 1.5707963267948966E+000;
            } else if(eml_y < 0.0) {
              eml_y = -1.5707963267948966E+000;
            } else {
              eml_y = 0.0;
            }
          } else {
            eml_y = rt_atan2(eml_y, eml_z);
          }
          if(fabs(MPC_framework_B.Gain - eml_r) < fabs(MPC_framework_B.Gain -
            eml_c_z)) {
            eml_z = eml_r;
            eml_y = eml_b_z;
          } else {
            eml_z = eml_c_z;
            eml_y -= eml_c_z;
          }
          eml_error = 0U;
        }
        MPC_framework_B.al1 = eml_z;
        MPC_framework_B.al2 = eml_y;
        MPC_framework_B.error = eml_error;
      }
    }
    MPC_framework_PrevZCSigState.Subsystem_ZCE = MPC_framework_B.LogicalOperator
      > 0 ? POS_ZCSIG : ZERO_ZCSIG;

    /* end of Outputs for SubSystem: '<S6>/Subsystem' */

    /* DataStoreWrite: '<S6>/Data Store Write' */
    MPC_framework_DWork.invgeo_alpha_1 = MPC_framework_B.al1;

    /* DataStoreWrite: '<S6>/Data Store Write1' */
    MPC_framework_DWork.invgeo_alpha_2 = MPC_framework_B.al2;

    /* DataStoreWrite: '<S6>/Data Store Write2' */
    MPC_framework_DWork.invgeo_error = MPC_framework_B.error;

    /* Update for UnitDelay: '<S37>/Delay Input1' */
    MPC_framework_DWork.DelayInput1_DSTATE =
      MPC_framework_B.CANMessageUnpackingCANdb_o;

    /* Update for UnitDelay: '<S38>/Delay Input1' */
    MPC_framework_DWork.DelayInput1_DSTATE_i =
      MPC_framework_B.CANMessageUnpackingCANdb_g;

    /* end of Outputs for SubSystem: '<Root>/Inverse geometry' */

    if((MPC_framework_B.LogicalOperator > 0) &&
     (MPC_framework_PrevZCSigState.Init_ZCE == 0)) {

      /* Output and update for trigger system: '<S41>/Init' */

      /* Stateflow: '<S43>/Trajectory design 1' incorporates:
       *  Constant: '<S41>/trajectory_time'
       */
      MP_Trajectorydesign1(rtb_motor1_reference, rtb_DataStoreRead,
       MPC_framework_P.trajectory_time_Value,
       &MPC_framework_B.sf_Trajectorydesign1);

      /* Stateflow: '<S43>/Trajectory design 2' incorporates:
       *  Constant: '<S41>/trajectory_time'
       */
      MP_Trajectorydesign1(rtb_motor2_reference, rtb_DataStoreRead1,
       MPC_framework_P.trajectory_time_Value,
       &MPC_framework_B.sf_Trajectorydesign2);
    }
    MPC_framework_PrevZCSigState.Init_ZCE = MPC_framework_B.LogicalOperator > 0
      ? POS_ZCSIG : ZERO_ZCSIG;
  }

  /* Block: <S68>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_h),&GlobalModuleCAN_A,5)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S14>/CAN Message Unpacking (CANdb)' */

    /*--- S-Function Block: <S66>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_h.DATA[0]
        | (MPC_framework_B.Datarealtime_h.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_h.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_h.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_h.DATA[4]
        | (MPC_framework_B.Datarealtime_h.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_h.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_h.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal init_ack_sync ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_m = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal init_ack_sync  ----- */
    }

    /* RelationalOperator: '<S70>/Compare' incorporates:
     *  Constant: '<S70>/Constant'
     */
    MPC_framework_B.Compare_i = (MPC_framework_B.CANMessageUnpackingCANdb_m ==
      MPC_framework_P.Constant_Value_g);
  }

  /* Block: <S69>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_pu),&GlobalModuleCAN_A,6)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S14>/CAN Message Unpacking (CANdb)1' */

    /*--- S-Function Block: <S67>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_pu.DATA[0]
        | (MPC_framework_B.Datarealtime_pu.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_pu.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_pu.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_pu.DATA[4]
        | (MPC_framework_B.Datarealtime_pu.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_pu.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_pu.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal init_ack_async ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_e = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal init_ack_async  ----- */
    }

    /* RelationalOperator: '<S71>/Compare' incorporates:
     *  Constant: '<S71>/Constant'
     */
    MPC_framework_B.Compare = (MPC_framework_B.CANMessageUnpackingCANdb_e ==
      MPC_framework_P.Constant_Value_h);
  }

  /* Block: <S87>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_b),&GlobalModuleCAN_A,8)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S17>/primitive_button message unpacking' */

    /*--- S-Function Block: <S88>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_b.DATA[0]
        | (MPC_framework_B.Datarealtime_b.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_b.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_b.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_b.DATA[4]
        | (MPC_framework_B.Datarealtime_b.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_b.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_b.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal primitive_message ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFF;
      }

      {

        /* processor word size, 32 bits, is wide enough 
           to perform the scaling calculation */
        uint32_T workingoutput = (uint32_T) unscaledSignal;

        /* no scaling required */

        /* narrow the working datatype, uint32_T 
           to the output datatype, uint8_T */
        MPC_framework_B.CANMessageUnpackingCANdb_l = (uint8_T) workingoutput;
      }

      /* ------ END Unpacking CANdb signal primitive_message  ----- */
    }
  }

  /* Block: <S48>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_pd),&GlobalModuleCAN_A,3)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S10>/async_request message unpacking' */

    /*--- S-Function Block: <S49>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_pd.DATA[0]
        | (MPC_framework_B.Datarealtime_pd.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_pd.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_pd.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_pd.DATA[4]
        | (MPC_framework_B.Datarealtime_pd.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_pd.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_pd.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal async_request ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_d = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal async_request  ----- */
    }
  }

  /* Stateflow: '<Root>/State Machine' */
  MPC_fram_StateMachine();

  {
    real_T rtb_Switch1_idx;
    real_T rtb_Switch1_idx_a;

    if(MPC_framework_B.trajectory_enable > 0U) {
      if(MPC_framework_DWork.Curvecalculation_MODE == SUBSYS_DISABLED) {

        /* Initial conditions for enable system: '<S41>/Curve calculation' */

        /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
        MPC_framework_DWork.DiscreteTimeIntegrator_DSTATE =
          MPC_framework_P.DiscreteTimeIntegrator_I;
      }
      MPC_framework_DWork.Curvecalculation_MODE = SUBSYS_ENABLED;
    } else if(MPC_framework_DWork.Curvecalculation_MODE == SUBSYS_ENABLED) {

      MPC_framework_DWork.Curvecalculation_MODE = SUBSYS_DISABLED;
    }
    if(MPC_framework_DWork.Curvecalculation_MODE == SUBSYS_ENABLED) {

      /* Output and update for enable system: '<S41>/Curve calculation' */

      /* DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
      rtb_DiscreteTimeIntegrato =
        MPC_framework_DWork.DiscreteTimeIntegrator_DSTATE;

      /* Stateflow: '<S42>/Joint reference singal 1' incorporates:
       *  Constant: '<S41>/trajectory_time'
       */
      Jointreferencesingal(MPC_framework_B.sf_Trajectorydesign1.a0,
       MPC_framework_B.sf_Trajectorydesign1.a1,
       MPC_framework_B.sf_Trajectorydesign1.a2,
       MPC_framework_B.sf_Trajectorydesign1.a3,
       MPC_framework_B.sf_Trajectorydesign1.a4,
       MPC_framework_B.sf_Trajectorydesign1.a5, rtb_DiscreteTimeIntegrato,
       MPC_framework_P.trajectory_time_Value,
       &MPC_framework_B.sf_Jointreferencesing);

      /* Stateflow: '<S42>/Joint reference singal 2' incorporates:
       *  Constant: '<S41>/trajectory_time'
       */
      Jointreferencesingal(MPC_framework_B.sf_Trajectorydesign2.a0,
       MPC_framework_B.sf_Trajectorydesign2.a1,
       MPC_framework_B.sf_Trajectorydesign2.a2,
       MPC_framework_B.sf_Trajectorydesign2.a3,
       MPC_framework_B.sf_Trajectorydesign2.a4,
       MPC_framework_B.sf_Trajectorydesign2.a5, rtb_DiscreteTimeIntegrato,
       MPC_framework_P.trajectory_time_Value,
       &MPC_framework_B.sf_Jointreferencesi_i);

      /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
         Update for *  Constant: '<S42>/time base'
       */
      MPC_framework_DWork.DiscreteTimeIntegrator_DSTATE =
        MPC_framework_P.DiscreteTimeIntegrator_g *
        MPC_framework_P.timebase_Value +
        MPC_framework_DWork.DiscreteTimeIntegrator_DSTATE;
    }

    /* Switch: '<Root>/Switch1' */
    if(MPC_framework_B.trajectory_enable > MPC_framework_P.Switch1_Threshold) {
      rtb_Switch1_idx = MPC_framework_B.sf_Jointreferencesing.qa;
      rtb_Switch1_idx_a = MPC_framework_B.sf_Jointreferencesi_i.qa;
    } else {
      rtb_Switch1_idx = MPC_framework_B.motor1_reference;
      rtb_Switch1_idx_a = MPC_framework_B.motor2_reference;
    }

    /* Outputs for enable SubSystem: '<Root>/Controller' */
    if(MPC_framework_B.controller_enable > 0U) {
      MPC_framework_DWork.Controller_MODE = SUBSYS_ENABLED;
    } else if(MPC_framework_DWork.Controller_MODE == SUBSYS_ENABLED) {

      MPC_framework_DWork.Controller_MODE = SUBSYS_DISABLED;
    }
    if(MPC_framework_DWork.Controller_MODE == SUBSYS_ENABLED) {

      /* Inport: '<S2>/alpha1_ref' */
      MPC_framework_B.alpha1_ref = rtb_Switch1_idx;

      /* Inport: '<S2>/alpha2_ref' */
      MPC_framework_B.alpha2_ref = rtb_Switch1_idx_a;
    }

    /* end of Outputs for SubSystem: '<Root>/Controller' */

    /* Switch: '<Root>/Switch' */
    if(MPC_framework_B.controller_enable > MPC_framework_P.Switch_Threshold) {
      MPC_framework_B.Switch[0] = MPC_framework_B.alpha1_ref;
      MPC_framework_B.Switch[1] = MPC_framework_B.alpha2_ref;
    } else {
      MPC_framework_B.Switch[0] = MPC_framework_B.motor1_reference;
      MPC_framework_B.Switch[1] = MPC_framework_B.motor2_reference;
    }

    if(MPC_framework_B.da_out_trigger > 0.0) {
      if(MPC_framework_DWork.DA_out_valuesender_MODE == SUBSYS_DISABLED) {
      }
      MPC_framework_DWork.DA_out_valuesender_MODE = SUBSYS_ENABLED;
    } else if(MPC_framework_DWork.DA_out_valuesender_MODE == SUBSYS_ENABLED) {

      MPC_framework_DWork.DA_out_valuesender_MODE = SUBSYS_DISABLED;
    }
    if(MPC_framework_DWork.DA_out_valuesender_MODE == SUBSYS_ENABLED) {

      /* Output and update for enable system: '<Root>/DA_out_value sender' */

      /*--- S-Function Block: <S3>/DA_out_value message packing ---*/
      {
        /* final output words that individual signals are |'d into */
        uint32_T output_word0 = 0;
        uint32_T output_word1 = 0;

        /* variable to hold each scaled signal to be packed */
        uint32_T scaledSignal = 0;

        /* --------------- START Packing CANdb signal DA3 ------------------ 
         *  startBit                = 32
         *  length                  = 16
         *  desiredSignalByteLayout = LittleEndian 
         *  dataType                = UNSIGNED
         *  signalType              = STANDARD
         *  offset                  = 0.0 
         *  factor                  = 1.0 
         * -----------------------------------------------------------------------*/

        /* -- Scaling and Offset --- */

        {

          /* widen the input datatype, uint16_T, 
             to the processor word size, uint32_T,
             for the scaling calculation */

          uint32_T result = (uint32_T) MPC_framework_P.Constant_Value_i;

          /* no scaling required */

          scaledSignal = result;
        }

        {
          /* create temporary storage for packing */
          uint32_T working_word0;

          /* -- pack the signal --- */
          scaledSignal &= 0xFFFF;
          working_word0 = scaledSignal;

          /* The signal is to be packed in little endian format
             No need to reverse the bytes in each word */

          output_word1 |= working_word0;
        }

        /* ------ END Packing CANdb signal DA3  ----- */

        /* --------------- START Packing CANdb signal DA2 ------------------ 
         *  startBit                = 16
         *  length                  = 16
         *  desiredSignalByteLayout = LittleEndian 
         *  dataType                = UNSIGNED
         *  signalType              = STANDARD
         *  offset                  = 0.0 
         *  factor                  = 1.0 
         * -----------------------------------------------------------------------*/

        /* -- Scaling and Offset --- */
        {
          /* no scaling required */
          real64_T result = MPC_framework_B.Switch[1];

          /* saturate the result */
          if (result > 65535.0) {
            result = 65535.0;
          }
          else if (result < 0.0) {
            result = 0.0;
          }

          /* Cast to an integer type 
           * rather than round.
           * This will ensure that we stay within the 
           * allowable range.
           */
          scaledSignal = (uint32_T) result;
        }

        {
          /* create temporary storage for packing */
          uint32_T working_word0;

          /* -- pack the signal --- */
          scaledSignal &= 0xFFFF;
          working_word0 = scaledSignal << 16;

          /* The signal is to be packed in little endian format
             No need to reverse the bytes in each word */

          output_word0 |= working_word0;
        }

        /* ------ END Packing CANdb signal DA2  ----- */

        /* --------------- START Packing CANdb signal DA1 ------------------ 
         *  startBit                = 0
         *  length                  = 16
         *  desiredSignalByteLayout = LittleEndian 
         *  dataType                = UNSIGNED
         *  signalType              = STANDARD
         *  offset                  = 0.0 
         *  factor                  = 1.0 
         * -----------------------------------------------------------------------*/

        /* -- Scaling and Offset --- */
        {
          /* no scaling required */
          real64_T result = MPC_framework_B.Switch[0];

          /* saturate the result */
          if (result > 65535.0) {
            result = 65535.0;
          }
          else if (result < 0.0) {
            result = 0.0;
          }

          /* Cast to an integer type 
           * rather than round.
           * This will ensure that we stay within the 
           * allowable range.
           */
          scaledSignal = (uint32_T) result;
        }

        {
          /* create temporary storage for packing */
          uint32_T working_word0;

          /* -- pack the signal --- */
          scaledSignal &= 0xFFFF;
          working_word0 = scaledSignal;

          /* The signal is to be packed in little endian format
             No need to reverse the bytes in each word */

          output_word0 |= working_word0;
        }

        /* ------ END Packing CANdb signal DA1  ----- */

        /* CAN message byte array is not guaranteed to be word aligned,
         * copy bytes individually from the output_words */
        MPC_framework_B.DA_out_valuemessagepacking.DATA[0] =
          (uint8_T) output_word0;

        MPC_framework_B.DA_out_valuemessagepacking.DATA[1] =
          (uint8_T) (output_word0 >> 8);

        MPC_framework_B.DA_out_valuemessagepacking.DATA[2] =
          (uint8_T) (output_word0 >> 16);

        MPC_framework_B.DA_out_valuemessagepacking.DATA[3] =
          (uint8_T) (output_word0 >> 24);

        MPC_framework_B.DA_out_valuemessagepacking.DATA[4] =
          (uint8_T) output_word1;

        MPC_framework_B.DA_out_valuemessagepacking.DATA[5] =
          (uint8_T) (output_word1 >> 8);

        MPC_framework_B.DA_out_valuemessagepacking.DATA[6] =
          (uint8_T) (output_word1 >> 16);

        MPC_framework_B.DA_out_valuemessagepacking.DATA[7] =
          (uint8_T) (output_word1 >> 24);
      }

      /* Send message using priority queue and shared TouCAN buffer(s) */
      sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.DA_out_valuemessagepacking);
    }

    if(MPC_framework_B.init_out_enable > 0U) {
      if(MPC_framework_DWork.Init1messagesender_MODE == SUBSYS_DISABLED) {
      }
      MPC_framework_DWork.Init1messagesender_MODE = SUBSYS_ENABLED;
    } else if(MPC_framework_DWork.Init1messagesender_MODE == SUBSYS_ENABLED) {

      MPC_framework_DWork.Init1messagesender_MODE = SUBSYS_DISABLED;
    }
    if(MPC_framework_DWork.Init1messagesender_MODE == SUBSYS_ENABLED) {

      /* Output and update for enable system: '<Root>/Init 1 message sender' */

      /*--- S-Function Block: <S4>/init message packing ---*/
      {
        /* final output words that individual signals are |'d into */
        uint32_T output_word0 = 0;
        uint32_T output_word1 = 0;

        /* variable to hold each scaled signal to be packed */
        uint32_T scaledSignal = 0;

        /* --------------- START Packing CANdb signal init ------------------ 
         *  startBit                = 0
         *  length                  = 8
         *  desiredSignalByteLayout = LittleEndian 
         *  dataType                = UNSIGNED
         *  signalType              = STANDARD
         *  offset                  = 0.0 
         *  factor                  = 1.0 
         * -----------------------------------------------------------------------*/

        /* -- Scaling and Offset --- */

        {

          /* widen the input datatype, uint8_T, 
             to the processor word size, uint32_T,
             for the scaling calculation */

          uint32_T result = (uint32_T) MPC_framework_B.init_out_value;

          /* no scaling required */

          scaledSignal = result;
        }

        {
          /* create temporary storage for packing */
          uint32_T working_word0;

          /* -- pack the signal --- */
          scaledSignal &= 0xFF;
          working_word0 = scaledSignal;

          /* The signal is to be packed in little endian format
             No need to reverse the bytes in each word */

          output_word0 |= working_word0;
        }

        /* ------ END Packing CANdb signal init  ----- */

        /* CAN message byte array is not guaranteed to be word aligned,
         * copy bytes individually from the output_words */
        MPC_framework_B.initmessagepacking_b.DATA[0] =
          (uint8_T) output_word0;

        MPC_framework_B.initmessagepacking_b.DATA[1] =
          (uint8_T) (output_word0 >> 8);

        MPC_framework_B.initmessagepacking_b.DATA[2] =
          (uint8_T) (output_word0 >> 16);

        MPC_framework_B.initmessagepacking_b.DATA[3] =
          (uint8_T) (output_word0 >> 24);

        MPC_framework_B.initmessagepacking_b.DATA[4] =
          (uint8_T) output_word1;

        MPC_framework_B.initmessagepacking_b.DATA[5] =
          (uint8_T) (output_word1 >> 8);

        MPC_framework_B.initmessagepacking_b.DATA[6] =
          (uint8_T) (output_word1 >> 16);

        MPC_framework_B.initmessagepacking_b.DATA[7] =
          (uint8_T) (output_word1 >> 24);
      }

      /* Send message using priority queue and shared TouCAN buffer(s) */
      sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.initmessagepacking_b);
    }

    if((MPC_framework_B.init_out_trigger > 0) &&
     (MPC_framework_PrevZCSigState.Init2messagesender_ZCE == 0)) {

      /* Output and update for trigger system: '<Root>/Init 2 message sender' */

      /*--- S-Function Block: <S5>/init message packing ---*/
      {
        /* final output words that individual signals are |'d into */
        uint32_T output_word0 = 0;
        uint32_T output_word1 = 0;

        /* variable to hold each scaled signal to be packed */
        uint32_T scaledSignal = 0;

        /* --------------- START Packing CANdb signal init ------------------ 
         *  startBit                = 0
         *  length                  = 8
         *  desiredSignalByteLayout = LittleEndian 
         *  dataType                = UNSIGNED
         *  signalType              = STANDARD
         *  offset                  = 0.0 
         *  factor                  = 1.0 
         * -----------------------------------------------------------------------*/

        /* -- Scaling and Offset --- */

        {

          /* widen the input datatype, uint8_T, 
             to the processor word size, uint32_T,
             for the scaling calculation */

          uint32_T result = (uint32_T) MPC_framework_B.init_out_value;

          /* no scaling required */

          scaledSignal = result;
        }

        {
          /* create temporary storage for packing */
          uint32_T working_word0;

          /* -- pack the signal --- */
          scaledSignal &= 0xFF;
          working_word0 = scaledSignal;

          /* The signal is to be packed in little endian format
             No need to reverse the bytes in each word */

          output_word0 |= working_word0;
        }

        /* ------ END Packing CANdb signal init  ----- */

        /* CAN message byte array is not guaranteed to be word aligned,
         * copy bytes individually from the output_words */
        MPC_framework_B.initmessagepacking.DATA[0] =
          (uint8_T) output_word0;

        MPC_framework_B.initmessagepacking.DATA[1] =
          (uint8_T) (output_word0 >> 8);

        MPC_framework_B.initmessagepacking.DATA[2] =
          (uint8_T) (output_word0 >> 16);

        MPC_framework_B.initmessagepacking.DATA[3] =
          (uint8_T) (output_word0 >> 24);

        MPC_framework_B.initmessagepacking.DATA[4] =
          (uint8_T) output_word1;

        MPC_framework_B.initmessagepacking.DATA[5] =
          (uint8_T) (output_word1 >> 8);

        MPC_framework_B.initmessagepacking.DATA[6] =
          (uint8_T) (output_word1 >> 16);

        MPC_framework_B.initmessagepacking.DATA[7] =
          (uint8_T) (output_word1 >> 24);
      }

      /* Send message using priority queue and shared TouCAN buffer(s) */
      sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.initmessagepacking);
    }
    MPC_framework_PrevZCSigState.Init2messagesender_ZCE =
      MPC_framework_B.init_out_trigger > 0 ? POS_ZCSIG : ZERO_ZCSIG;
  }

  /* RelationalOperator: '<S1>/Compare' */
  rtb_Compare = (MPC_framework_B.operation_mode > ((uint8_T)0U));

  if(rtb_Compare > 0U) {
    if(MPC_framework_DWork.incremental_out_valuesender_MO == SUBSYS_DISABLED) {
    }
    MPC_framework_DWork.incremental_out_valuesender_MO = SUBSYS_ENABLED;
  } else if(MPC_framework_DWork.incremental_out_valuesender_MO ==
   SUBSYS_ENABLED) {

    MPC_framework_DWork.incremental_out_valuesender_MO = SUBSYS_DISABLED;
  }
  if(MPC_framework_DWork.incremental_out_valuesender_MO == SUBSYS_ENABLED) {

    /* Output and update for enable system: '<Root>/incremental_out_value sender' */

    /*--- S-Function Block: <S13>/incremental_out_value message packing ---*/
    {
      /* final output words that individual signals are |'d into */
      uint32_T output_word0 = 0;
      uint32_T output_word1 = 0;

      /* variable to hold each scaled signal to be packed */
      uint32_T scaledSignal = 0;

      /* --------------- START Packing CANdb signal cntr1 ------------------ 
       *  startBit                = 0
       *  length                  = 16
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      /* -- Scaling and Offset --- */
      {
        /* no scaling required */
        real64_T result = MPC_framework_B.MathFunction;

        /* saturate the result */
        if (result > 65535.0) {
          result = 65535.0;
        }
        else if (result < 0.0) {
          result = 0.0;
        }

        /* Cast to an integer type 
         * rather than round.
         * This will ensure that we stay within the 
         * allowable range.
         */
        scaledSignal = (uint32_T) result;
      }

      {
        /* create temporary storage for packing */
        uint32_T working_word0;

        /* -- pack the signal --- */
        scaledSignal &= 0xFFFF;
        working_word0 = scaledSignal;

        /* The signal is to be packed in little endian format
           No need to reverse the bytes in each word */

        output_word0 |= working_word0;
      }

      /* ------ END Packing CANdb signal cntr1  ----- */

      /* --------------- START Packing CANdb signal cntr2 ------------------ 
       *  startBit                = 16
       *  length                  = 16
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      /* -- Scaling and Offset --- */
      {
        /* no scaling required */
        real64_T result = MPC_framework_B.MathFunction1;

        /* saturate the result */
        if (result > 65535.0) {
          result = 65535.0;
        }
        else if (result < 0.0) {
          result = 0.0;
        }

        /* Cast to an integer type 
         * rather than round.
         * This will ensure that we stay within the 
         * allowable range.
         */
        scaledSignal = (uint32_T) result;
      }

      {
        /* create temporary storage for packing */
        uint32_T working_word0;

        /* -- pack the signal --- */
        scaledSignal &= 0xFFFF;
        working_word0 = scaledSignal << 16;

        /* The signal is to be packed in little endian format
           No need to reverse the bytes in each word */

        output_word0 |= working_word0;
      }

      /* ------ END Packing CANdb signal cntr2  ----- */

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually from the output_words */
      MPC_framework_B.incremental_out_valuemessagep.DATA[0] =
        (uint8_T) output_word0;

      MPC_framework_B.incremental_out_valuemessagep.DATA[1] =
        (uint8_T) (output_word0 >> 8);

      MPC_framework_B.incremental_out_valuemessagep.DATA[2] =
        (uint8_T) (output_word0 >> 16);

      MPC_framework_B.incremental_out_valuemessagep.DATA[3] =
        (uint8_T) (output_word0 >> 24);

      MPC_framework_B.incremental_out_valuemessagep.DATA[4] =
        (uint8_T) output_word1;

      MPC_framework_B.incremental_out_valuemessagep.DATA[5] =
        (uint8_T) (output_word1 >> 8);

      MPC_framework_B.incremental_out_valuemessagep.DATA[6] =
        (uint8_T) (output_word1 >> 16);

      MPC_framework_B.incremental_out_valuemessagep.DATA[7] =
        (uint8_T) (output_word1 >> 24);
    }

    /* Send message using priority queue and shared TouCAN buffer(s) */
    sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.incremental_out_valuemessagep);
  }

  /* RelationalOperator: '<S80>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S80>/Delay Input1'
   */
  rtb_Edge = (MPC_framework_B.operation_mode !=
    MPC_framework_DWork.DelayInput1_DSTATE_m);

  if((rtb_Edge > 0) &&
   (MPC_framework_PrevZCSigState.operation_mode_changedsender_ZCE == 0)) {

    /* Output and update for trigger system: '<S16>/operation_mode_changed sender' */

    /*--- S-Function Block: <S81>/operation_mode_changed message packing ---*/
    {
      /* final output words that individual signals are |'d into */
      uint32_T output_word0 = 0;
      uint32_T output_word1 = 0;

      /* variable to hold each scaled signal to be packed */
      uint32_T scaledSignal = 0;

      /* --------------- START Packing CANdb signal operation_mode ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      /* -- Scaling and Offset --- */

      {

        /* widen the input datatype, uint8_T, 
           to the processor word size, uint32_T,
           for the scaling calculation */

        uint32_T result = (uint32_T) MPC_framework_B.operation_mode;

        /* no scaling required */

        scaledSignal = result;
      }

      {
        /* create temporary storage for packing */
        uint32_T working_word0;

        /* -- pack the signal --- */
        scaledSignal &= 0xFF;
        working_word0 = scaledSignal;

        /* The signal is to be packed in little endian format
           No need to reverse the bytes in each word */

        output_word0 |= working_word0;
      }

      /* ------ END Packing CANdb signal operation_mode  ----- */

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually from the output_words */
      MPC_framework_B.operation_mode_changedmessage.DATA[0] =
        (uint8_T) output_word0;

      MPC_framework_B.operation_mode_changedmessage.DATA[1] =
        (uint8_T) (output_word0 >> 8);

      MPC_framework_B.operation_mode_changedmessage.DATA[2] =
        (uint8_T) (output_word0 >> 16);

      MPC_framework_B.operation_mode_changedmessage.DATA[3] =
        (uint8_T) (output_word0 >> 24);

      MPC_framework_B.operation_mode_changedmessage.DATA[4] =
        (uint8_T) output_word1;

      MPC_framework_B.operation_mode_changedmessage.DATA[5] =
        (uint8_T) (output_word1 >> 8);

      MPC_framework_B.operation_mode_changedmessage.DATA[6] =
        (uint8_T) (output_word1 >> 16);

      MPC_framework_B.operation_mode_changedmessage.DATA[7] =
        (uint8_T) (output_word1 >> 24);
    }

    /* Send message using priority queue and shared TouCAN buffer(s) */
    sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.operation_mode_changedmessage);
  }
  MPC_framework_PrevZCSigState.operation_mode_changedsender_ZCE = rtb_Edge > 0 ?
    POS_ZCSIG : ZERO_ZCSIG;

  if(MPC_framework_B.controller_enable > 0U) {
    if(MPC_framework_DWork.request_incremental_valuesende == SUBSYS_DISABLED) {
    }
    MPC_framework_DWork.request_incremental_valuesende = SUBSYS_ENABLED;
  } else if(MPC_framework_DWork.request_incremental_valuesende ==
   SUBSYS_ENABLED) {

    MPC_framework_DWork.request_incremental_valuesende = SUBSYS_DISABLED;
  }
  if(MPC_framework_DWork.request_incremental_valuesende == SUBSYS_ENABLED) {
  }

  if((MPC_framework_B.stop_trigger > 0) &&
   (MPC_framework_PrevZCSigState.stopmessagesender_ZCE == 0)) {

    /* Output and update for trigger system: '<Root>/stop message sender' */

    /*--- S-Function Block: <S19>/stop message packing ---*/
    {
      /* final output words that individual signals are |'d into */
      uint32_T output_word0 = 0;
      uint32_T output_word1 = 0;

      /* variable to hold each scaled signal to be packed */
      uint32_T scaledSignal = 0;

      /* --------------- START Packing CANdb signal stop ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      /* -- Scaling and Offset --- */

      {

        /* widen the input datatype, uint8_T, 
           to the processor word size, uint32_T,
           for the scaling calculation */

        uint32_T result = (uint32_T) MPC_framework_P.Constant_Value_n;

        /* no scaling required */

        scaledSignal = result;
      }

      {
        /* create temporary storage for packing */
        uint32_T working_word0;

        /* -- pack the signal --- */
        scaledSignal &= 0xFF;
        working_word0 = scaledSignal;

        /* The signal is to be packed in little endian format
           No need to reverse the bytes in each word */

        output_word0 |= working_word0;
      }

      /* ------ END Packing CANdb signal stop  ----- */

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually from the output_words */
      MPC_framework_B.stopmessagepacking.DATA[0] =
        (uint8_T) output_word0;

      MPC_framework_B.stopmessagepacking.DATA[1] =
        (uint8_T) (output_word0 >> 8);

      MPC_framework_B.stopmessagepacking.DATA[2] =
        (uint8_T) (output_word0 >> 16);

      MPC_framework_B.stopmessagepacking.DATA[3] =
        (uint8_T) (output_word0 >> 24);

      MPC_framework_B.stopmessagepacking.DATA[4] =
        (uint8_T) output_word1;

      MPC_framework_B.stopmessagepacking.DATA[5] =
        (uint8_T) (output_word1 >> 8);

      MPC_framework_B.stopmessagepacking.DATA[6] =
        (uint8_T) (output_word1 >> 16);

      MPC_framework_B.stopmessagepacking.DATA[7] =
        (uint8_T) (output_word1 >> 24);
    }

    /* Send message using priority queue and shared TouCAN buffer(s) */
    sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.stopmessagepacking);
  }
  MPC_framework_PrevZCSigState.stopmessagesender_ZCE =
    MPC_framework_B.stop_trigger > 0 ? POS_ZCSIG : ZERO_ZCSIG;

  /* Logic: '<S21>/Logical Operator' incorporates:
   *  RelationalOperator: '<S105>/Compare'
   *  RelationalOperator: '<S106>/FixPt Relational Operator'
   *  UnitDelay: '<S106>/Delay Input1'
   */
  rtb_LogicalOperator = ((MPC_framework_B.sync_command !=
    MPC_framework_DWork.DelayInput1_DSTATE_h) && (MPC_framework_B.sync_command >
    ((uint8_T)0U)));

  if(rtb_LogicalOperator &&
   (!(boolean_T)MPC_framework_PrevZCSigState.sync_commandsender_ZCE)) {

    /* Output and update for trigger system: '<S21>/sync_command sender' */

    /*--- S-Function Block: <S107>/sync_command message packing ---*/
    {
      /* final output words that individual signals are |'d into */
      uint32_T output_word0 = 0;
      uint32_T output_word1 = 0;

      /* variable to hold each scaled signal to be packed */
      uint32_T scaledSignal = 0;

      /* --------------- START Packing CANdb signal sync_command ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      /* -- Scaling and Offset --- */

      {

        /* widen the input datatype, uint8_T, 
           to the processor word size, uint32_T,
           for the scaling calculation */

        uint32_T result = (uint32_T) MPC_framework_B.sync_command;

        /* no scaling required */

        scaledSignal = result;
      }

      {
        /* create temporary storage for packing */
        uint32_T working_word0;

        /* -- pack the signal --- */
        scaledSignal &= 0xFF;
        working_word0 = scaledSignal;

        /* The signal is to be packed in little endian format
           No need to reverse the bytes in each word */

        output_word0 |= working_word0;
      }

      /* ------ END Packing CANdb signal sync_command  ----- */

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually from the output_words */
      MPC_framework_B.sync_commandmessagepacking.DATA[0] =
        (uint8_T) output_word0;

      MPC_framework_B.sync_commandmessagepacking.DATA[1] =
        (uint8_T) (output_word0 >> 8);

      MPC_framework_B.sync_commandmessagepacking.DATA[2] =
        (uint8_T) (output_word0 >> 16);

      MPC_framework_B.sync_commandmessagepacking.DATA[3] =
        (uint8_T) (output_word0 >> 24);

      MPC_framework_B.sync_commandmessagepacking.DATA[4] =
        (uint8_T) output_word1;

      MPC_framework_B.sync_commandmessagepacking.DATA[5] =
        (uint8_T) (output_word1 >> 8);

      MPC_framework_B.sync_commandmessagepacking.DATA[6] =
        (uint8_T) (output_word1 >> 16);

      MPC_framework_B.sync_commandmessagepacking.DATA[7] =
        (uint8_T) (output_word1 >> 24);
    }

    /* Send message using priority queue and shared TouCAN buffer(s) */
    sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.sync_commandmessagepacking);
  }
  MPC_framework_PrevZCSigState.sync_commandsender_ZCE =
    (int32_T)rtb_LogicalOperator ? POS_ZCSIG : ZERO_ZCSIG;

  /* Block: <S101>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_k),&GlobalModuleCAN_A,9)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S20>/stop_button message packing' */

    /*--- S-Function Block: <S102>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_k.DATA[0]
        | (MPC_framework_B.Datarealtime_k.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_k.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_k.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_k.DATA[4]
        | (MPC_framework_B.Datarealtime_k.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_k.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_k.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal stop_button ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      {
        /* create temporary storage for unpacking */
        uint32_T working_word0;

        /* -- unpack the signal --- */
        working_word0 = input_word0;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal stop_button  ----- */
    }
  }

  /* Update for Memory: '<S41>/Hidden_Mem_for_Latch_at_inp_port_2_of_Init' */
  MPC_framework_DWork.Hidden_Mem_for_Latch_at_inp_por =
    MPC_framework_B.motor1_reference;

  /* Update for Memory: '<S41>/Hidden_Mem_for_Latch_at_inp_port_4_of_Init' */
  MPC_framework_DWork.Hidden_Mem_for_Latch_at_inp_p_l =
    MPC_framework_B.motor2_reference;

  /* Update for UnitDelay: '<S80>/Delay Input1' */
  MPC_framework_DWork.DelayInput1_DSTATE_m = MPC_framework_B.operation_mode;

  /* Update for UnitDelay: '<S106>/Delay Input1' */
  MPC_framework_DWork.DelayInput1_DSTATE_h = MPC_framework_B.sync_command;
}

/* Model step function for TID1 */

void MPC_framework_step1(void)          /* Sample time: [0.1s, 0.0s] */
{

  if(MPC_framework_DWork.request_incremental_valuesende == SUBSYS_ENABLED) {

    /* Output and update for enable system: '<Root>/request_incremental_value sender' */

    /*--- S-Function Block: <S18>/request_incremental_value message packing ---*/
    {
      /* final output words that individual signals are |'d into */
      uint32_T output_word0 = 0;
      uint32_T output_word1 = 0;

      /* variable to hold each scaled signal to be packed */
      uint32_T scaledSignal = 0;

      /* --------------- START Packing CANdb signal request_incremental_value ------------------ 
       *  startBit                = 0
       *  length                  = 8
       *  desiredSignalByteLayout = LittleEndian 
       *  dataType                = UNSIGNED
       *  signalType              = STANDARD
       *  offset                  = 0.0 
       *  factor                  = 1.0 
       * -----------------------------------------------------------------------*/

      /* -- Scaling and Offset --- */

      {

        /* widen the input datatype, uint8_T, 
           to the processor word size, uint32_T,
           for the scaling calculation */

        uint32_T result = (uint32_T) MPC_framework_P.Constant_Value_f;

        /* no scaling required */

        scaledSignal = result;
      }

      {
        /* create temporary storage for packing */
        uint32_T working_word0;

        /* -- pack the signal --- */
        scaledSignal &= 0xFF;
        working_word0 = scaledSignal;

        /* The signal is to be packed in little endian format
           No need to reverse the bytes in each word */

        output_word0 |= working_word0;
      }

      /* ------ END Packing CANdb signal request_incremental_value  ----- */

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually from the output_words */
      MPC_framework_B.request_incremental_valuemessa.DATA[0] =
        (uint8_T) output_word0;

      MPC_framework_B.request_incremental_valuemessa.DATA[1] =
        (uint8_T) (output_word0 >> 8);

      MPC_framework_B.request_incremental_valuemessa.DATA[2] =
        (uint8_T) (output_word0 >> 16);

      MPC_framework_B.request_incremental_valuemessa.DATA[3] =
        (uint8_T) (output_word0 >> 24);

      MPC_framework_B.request_incremental_valuemessa.DATA[4] =
        (uint8_T) output_word1;

      MPC_framework_B.request_incremental_valuemessa.DATA[5] =
        (uint8_T) (output_word1 >> 8);

      MPC_framework_B.request_incremental_valuemessa.DATA[6] =
        (uint8_T) (output_word1 >> 16);

      MPC_framework_B.request_incremental_valuemessa.DATA[7] =
        (uint8_T) (output_word1 >> 24);
    }

    /* Send message using priority queue and shared TouCAN buffer(s) */
    sendCanMessage(&GlobalModuleCAN_A,&MPC_framework_B.request_incremental_valuemessa);
  }
}

void MPC_framework_step(int_T tid) {

  switch(tid) {
   case 0 :
    MPC_framework_step0();
    break;
   case 1 :
    MPC_framework_step1();
    break;
   default :
    break;
  }
}

/* Model initialize function */

void MPC_framework_initialize(boolean_T firstTime)
{
  if (firstTime) {

    /* Registration code */
    /* initialize real-time model */
    (void) memset((char_T *)MPC_framework_M,0,
     sizeof(RT_MODEL_MPC_framework));

    /* block I/O */

    (void) memset(((void *) &MPC_framework_B),0,
     sizeof(BlockIO_MPC_framework));

    {

      int_T i;
      void *pVoidBlockIORegion;

      pVoidBlockIORegion = (void *)(&MPC_framework_B.Datarealtime);
      for (i = 0; i < 7; i++) {
        ((CAN_FRAME*)pVoidBlockIORegion)[i] = CAN_FRAME_GROUND;
      }

      pVoidBlockIORegion = (void *)(&MPC_framework_B.sync_commandmessagepacking);
      for (i = 0; i < 9; i++) {
        ((CAN_FRAME*)pVoidBlockIORegion)[i] = CAN_FRAME_GROUND;
      }

      pVoidBlockIORegion = (void *)(&MPC_framework_B.MathFunction);
      for (i = 0; i < 6; i++) {
        ((real_T*)pVoidBlockIORegion)[i] = 0.0;
      }

      pVoidBlockIORegion = (void *)(&MPC_framework_B.CANMessageUnpackingCANdb);
      for (i = 0; i < 17; i++) {
        ((real_T*)pVoidBlockIORegion)[i] = 0.0;
      }

      pVoidBlockIORegion = (void *)(&MPC_framework_B.sf_Trajectorydesign2.a0);
      for (i = 0; i < 6; i++) {
        ((real_T*)pVoidBlockIORegion)[i] = 0.0;
      }

      pVoidBlockIORegion = (void *)(&MPC_framework_B.sf_Trajectorydesign1.a0);
      for (i = 0; i < 6; i++) {
        ((real_T*)pVoidBlockIORegion)[i] = 0.0;
      }

      ((real_T*)&MPC_framework_B.sf_Jointreferencesi_i.qa)[0] = 0.0;

      ((real_T*)&MPC_framework_B.sf_Jointreferencesing.qa)[0] = 0.0;
    }

    /* states (dwork) */

    (void) memset((char_T *) &MPC_framework_DWork,0,
     sizeof(D_Work_MPC_framework));
    {
      int_T i;
      real_T *dwork_ptr = (real_T *) &MPC_framework_DWork.DelayInput1_DSTATE;

      for (i = 0; i < 7; i++) {
        dwork_ptr[i] = 0.0;
      }
    }

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));

    /* -- Resource Configuration : MPC555dkConfig::SYSTEM_CLOCKS : [START] --- */

    USIU.PLPRCR.B.MF = 0;

    /* Wait for PLL to Lock */
    while(USIU.PLPRCR.B.SPLS == 0);

    /* Assuming External Oscilator Frequency = 20000000 */

    /* The DIVF bits control the value of the pre-divider in the SPLL circuit. */
    USIU.PLPRCR.B.DIVF = 0;
    /* Division factor high frequency. */
    USIU.SCCR.B.DFNH = 0;
    /* Division factor low frequency. */
    USIU.SCCR.B.DFNL = 0;
    /* RTC (and PIT) clock diver. Divide by 256 */
    USIU.SCCR.B.RTDIV = 1;
    /* External bus division factor. */
    USIU.SCCR.B.EBDF = 0;

    /* -- Resource Configuration : MPC555dkConfig::SYSTEM_CLOCKS : [END] --- */

    /* -- Resource Configuration : MPC555dkConfig::TOUCAN : [START] --- */

    {
      /* ----------------------------------
         Configure the TouCAN Module CAN_A
       *---------------------------------*/
      PCAN_MODULE module;
      module = constructCanModule(&GlobalModuleCAN_A,&CAN_A);
      setCanModuleDefaults(module);
      setCanBitTiming(module,
       5U                               /*propseg*/
       , 6U                             /*pseg1*/
       , 4U                             /*pseg2*/
       , 5U                             /*presdiv*/
       , 1                              /*rjw*/
       , 16                             /* num quanta */
       , 0.75                           /* sample point */
       , 250000                         /* bit rate */
       );

      setCanModuleMasks ( module, CAN_MESSAGE_EXTENDED, // Global Mask Type
       0xffffffff,                      // Global Mask Value
       CAN_MESSAGE_EXTENDED,            // Rx14 Mask type
       0xffffffff,                      // Rx14 Mask value
       CAN_MESSAGE_EXTENDED,            // Rx15 Mask type
       0xffffffff);                     // Rx15 Mask value

      {
        static CAN_FRAME canTxQueueCAN_A[16];
        static uint8_T canTxQueueLinksCAN_A[16];
        canModuleInitTxBuffer(module, 3, canTxQueueCAN_A,
         canTxQueueLinksCAN_A, 16);
      }

      /* Initialize the interrupt level of CAN_A */
      setCanModuleIrqLevel(module,INT_LEVEL1);

      /* -- Start the CAN module CAN_A --- */
      START_CAN_MODULE(&GlobalModuleCAN_A);
    }

    {
      /* ----------------------------------
         Configure the TouCAN Module CAN_B
       *---------------------------------*/
      PCAN_MODULE module;
      module = constructCanModule(&GlobalModuleCAN_B,&CAN_B);
      setCanModuleDefaults(module);
      setCanBitTiming(module,
       7U                               /*propseg*/
       , 8U                             /*pseg1*/
       , 4U                             /*pseg2*/
       , 2U                             /*presdiv*/
       , 4                              /*rjw*/
       , 20                             /* num quanta */
       , 0.81                           /* sample point */
       , 500000                         /* bit rate */
       );

      setCanModuleMasks ( module, CAN_MESSAGE_EXTENDED, // Global Mask Type
       0xffffffff,                      // Global Mask Value
       CAN_MESSAGE_EXTENDED,            // Rx14 Mask type
       0xffffffff,                      // Rx14 Mask value
       CAN_MESSAGE_EXTENDED,            // Rx15 Mask type
       0xffffffff);                     // Rx15 Mask value

      /* Initialize the interrupt level of CAN_B */
      setCanModuleIrqLevel(module,INT_LEVEL2);

      /* -- Start the CAN module CAN_B --- */
      START_CAN_MODULE(&GlobalModuleCAN_B);
    }

    /* -- Resource Configuration : MPC555dkConfig::TOUCAN : [END] --- */

    /* Initialize TouCAN module CAN_A, buffer 7 for operation with polling.
     * Received message identifier 0xf
     */
    initCanRx(&GlobalModuleCAN_A,7,CAN_MESSAGE_STANDARD,15);

    /* Initialize TouCAN module CAN_A, buffer 4 for operation with polling.
     * Received message identifier 0x7
     */
    initCanRx(&GlobalModuleCAN_A,4,CAN_MESSAGE_STANDARD,7);

    /* Start for atomic SubSystem: '<Root>/Inverse geometry' */

    /* Start for trigger SubSystem: '<S6>/Subsystem' */

    /* end of Start for SubSystem: '<S6>/Subsystem' */

    /* end of Start for SubSystem: '<Root>/Inverse geometry' */

    /* Initialize TouCAN module CAN_A, buffer 5 for operation with polling.
     * Received message identifier 0x2
     */
    initCanRx(&GlobalModuleCAN_A,5,CAN_MESSAGE_STANDARD,2);

    /* Initialize TouCAN module CAN_A, buffer 6 for operation with polling.
     * Received message identifier 0x3
     */
    initCanRx(&GlobalModuleCAN_A,6,CAN_MESSAGE_STANDARD,3);

    /* Initialize TouCAN module CAN_A, buffer 8 for operation with polling.
     * Received message identifier 0x8
     */
    initCanRx(&GlobalModuleCAN_A,8,CAN_MESSAGE_STANDARD,8);

    /* Initialize TouCAN module CAN_A, buffer 3 for operation with polling.
     * Received message identifier 0xc
     */
    initCanRx(&GlobalModuleCAN_A,3,CAN_MESSAGE_STANDARD,12);

    /*atomic Subsystem Block: '<Root>/State Machine' */
    MPC_fram_StateMachine_Start();

    /* Start for enable system: '<S41>/Curve calculation' */

    /* Initial conditions for enable system: '<S41>/Curve calculation' */

    /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
    MPC_framework_DWork.DiscreteTimeIntegrator_DSTATE =
      MPC_framework_P.DiscreteTimeIntegrator_I;

    /* Start for enable system: '<Root>/DA_out_value sender' */

    /*--- S-Function Block: <S3>/DA_out_value message packing ---*/
    MPC_framework_B.DA_out_valuemessagepacking.ID = 6U;
    MPC_framework_B.DA_out_valuemessagepacking.type = 0U;
    MPC_framework_B.DA_out_valuemessagepacking.LENGTH = 6U;

    /* Start for enable system: '<Root>/Init 1 message sender' */

    /*--- S-Function Block: <S4>/init message packing ---*/
    MPC_framework_B.initmessagepacking_b.ID = 1U;
    MPC_framework_B.initmessagepacking_b.type = 0U;
    MPC_framework_B.initmessagepacking_b.LENGTH = 1U;

    /* Start for trigger system: '<Root>/Init 2 message sender' */

    /*--- S-Function Block: <S5>/init message packing ---*/
    MPC_framework_B.initmessagepacking.ID = 1U;
    MPC_framework_B.initmessagepacking.type = 0U;
    MPC_framework_B.initmessagepacking.LENGTH = 1U;

    /* Start for enable system: '<Root>/incremental_out_value sender' */

    /*--- S-Function Block: <S13>/incremental_out_value message packing ---*/
    MPC_framework_B.incremental_out_valuemessagep.ID = 10U;
    MPC_framework_B.incremental_out_valuemessagep.type = 0U;
    MPC_framework_B.incremental_out_valuemessagep.LENGTH = 4U;

    /* Start for trigger system: '<S16>/operation_mode_changed sender' */

    /*--- S-Function Block: <S81>/operation_mode_changed message packing ---*/
    MPC_framework_B.operation_mode_changedmessage.ID = 13U;
    MPC_framework_B.operation_mode_changedmessage.type = 0U;
    MPC_framework_B.operation_mode_changedmessage.LENGTH = 1U;

    /* Start for enable system: '<Root>/request_incremental_value sender' */

    /*--- S-Function Block: <S18>/request_incremental_value message packing ---*/
    MPC_framework_B.request_incremental_valuemessa.ID = 0U;
    MPC_framework_B.request_incremental_valuemessa.type = 0U;
    MPC_framework_B.request_incremental_valuemessa.LENGTH = 1U;

    /* Start for trigger system: '<Root>/stop message sender' */

    /*--- S-Function Block: <S19>/stop message packing ---*/
    MPC_framework_B.stopmessagepacking.ID = 5U;
    MPC_framework_B.stopmessagepacking.type = 0U;
    MPC_framework_B.stopmessagepacking.LENGTH = 1U;

    /* Start for trigger system: '<S21>/sync_command sender' */

    /*--- S-Function Block: <S107>/sync_command message packing ---*/
    MPC_framework_B.sync_commandmessagepacking.ID = 14U;
    MPC_framework_B.sync_commandmessagepacking.type = 0U;
    MPC_framework_B.sync_commandmessagepacking.LENGTH = 1U;

    /* Initialize TouCAN module CAN_A, buffer 9 for operation with polling.
     * Received message identifier 0x4
     */
    initCanRx(&GlobalModuleCAN_A,9,CAN_MESSAGE_STANDARD,4);

    /* Start for DataStoreMemory: '<Root>/invgeo_alpha_1' */
    MPC_framework_DWork.invgeo_alpha_1 =
      MPC_framework_P.invgeo_alpha_1_InitialValu;

    /* Start for DataStoreMemory: '<Root>/invgeo_alpha_2' */
    MPC_framework_DWork.invgeo_alpha_2 =
      MPC_framework_P.invgeo_alpha_2_InitialValu;

    /* Start for DataStoreMemory: '<Root>/invgeo_error' */
    MPC_framework_DWork.invgeo_error = MPC_framework_P.invgeo_error_InitialValue;
  }

  MPC_framework_PrevZCSigState.sync_commandsender_ZCE = POS_ZCSIG;

  MPC_framework_PrevZCSigState.stopmessagesender_ZCE = POS_ZCSIG;

  MPC_framework_PrevZCSigState.operation_mode_changedsender_ZCE = POS_ZCSIG;

  MPC_framework_PrevZCSigState.Init_ZCE = POS_ZCSIG;

  MPC_framework_PrevZCSigState.Subsystem_ZCE = POS_ZCSIG;

  MPC_framework_PrevZCSigState.Init2messagesender_ZCE = POS_ZCSIG;

  /* InitializeConditions for Memory: '<S41>/Hidden_Mem_for_Latch_at_inp_port_2_of_Init' */
  MPC_framework_DWork.Hidden_Mem_for_Latch_at_inp_por =
    MPC_framework_P.Hidden_Mem_for_Latch_at_in;

  /* InitializeConditions for Memory: '<S41>/Hidden_Mem_for_Latch_at_inp_port_4_of_Init' */
  MPC_framework_DWork.Hidden_Mem_for_Latch_at_inp_p_l =
    MPC_framework_P.Hidden_Mem_for_Latch_at_ij;

  /* InitializeConditions for atomic SubSystem: '<Root>/Inverse geometry' */

  /* InitializeConditions for UnitDelay: '<S37>/Delay Input1' */
  MPC_framework_DWork.DelayInput1_DSTATE = MPC_framework_P.DelayInput1_X0;

  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1' */
  MPC_framework_DWork.DelayInput1_DSTATE_i = MPC_framework_P.DelayInput1_X0_b;

  /* end of InitializeConditions for SubSystem: '<Root>/Inverse geometry' */

  /*atomic Subsystem Block: '<Root>/State Machine' */
  MPC_frame_StateMachine_Init();

  /* InitializeConditions for UnitDelay: '<S80>/Delay Input1' */
  MPC_framework_DWork.DelayInput1_DSTATE_m = MPC_framework_P.DelayInput1_X0_f;

  /* InitializeConditions for UnitDelay: '<S106>/Delay Input1' */
  MPC_framework_DWork.DelayInput1_DSTATE_h = MPC_framework_P.DelayInput1_X0_k;

  /* Machine initializer */
  _sfEvent_MPC_framework_ = CALL_EVENT;
}

/* Model terminate function */

void MPC_framework_terminate(void)
{

  /* Terminate for atomic SubSystem: '<Root>/Inverse geometry' */

  /* end of Terminate for SubSystem: '<Root>/Inverse geometry' */
}

/* user code (bottom of registration file) */
// A pointer to a CAN module that
// all transmit and receive blocks
// will reference.
CAN_MODULE GlobalModuleCAN_A;
// A pointer to a CAN module that
// all transmit and receive blocks
// will reference.
CAN_MODULE GlobalModuleCAN_B;

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
