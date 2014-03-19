/*
 * File: MPC_framework.c
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.282
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Mar 19 14:11:59 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Mar 19 14:11:59 2014
 */

#include "MPC_framework.h"
#include "MPC_framework_private.h"

/* Named constants for block: '<Root>/State Machine' */
#define MPC_framewor_IN_NO_ACTIVE_CHILD (0)
#define MPC_framework_IN_INIT           (1)
#define MPC_framework_IN_INIT_ACK       (2)
#define MPC_framework_IN_OPERATION      (3)
#define MPC_framework_IN_MOVING         (1)
#define MPC_framework_IN_STOPPED        (2)
#define MPC_framew_IN_POSITIVE_MOVEMENT (2)
#define MPC_framew_IN_NEGATIVE_MOVEMENT (1)
#define MPC_framewo_motor_stopped_value (32768.0)
#define MPC_framew_motor_positive_value (40960.0)
#define MPC_framew_motor_negative_value (24576.0)

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

/* Initial conditions for atomic system: '<Root>/State Machine' */

void MPC_frame_StateMachine_Init(void)
{

  /* Initialize code for chart: '<Root>/State Machine' */
  MPC_framework_DWork.StateMachine.is_OPERATION = 0U;
  MPC_framework_DWork.StateMachine.is_MOVING = 0U;
  MPC_framework_DWork.StateMachine.is_c1_MPC_framework = 0U;
  MPC_framework_B.init_out_value = 0U;
  MPC_framework_B.init_out_enable = 0U;
  MPC_framework_B.init_out_trigger = 0U;
  MPC_framework_B.stop_trigger = 0U;
  MPC_framework_B.motor1_reference = 32768U;
  MPC_framework_B.motor2_reference = 32768U;
  MPC_framework_B.controller_enable = 0U;
  MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
    (uint8_T)MPC_framework_IN_INIT;
  MPC_framework_B.init_out_value = MPC_framework_P.SFunction_p1;
  MPC_framework_B.init_out_enable = 1U;
}

/* Output and update for atomic system: '<Root>/State Machine' */

void MPC_fram_StateMachine(void)
{

  /* Stateflow: '<Root>/State Machine' */
  switch(MPC_framework_DWork.StateMachine.is_c1_MPC_framework) {
   case MPC_framework_IN_INIT:
    if((MPC_framework_B.Compare_i == 1) && (MPC_framework_B.Compare == 1)) {
      MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
        (uint8_T)MPC_framework_IN_INIT_ACK;
      MPC_framework_B.init_out_enable = 0U;
      MPC_framework_B.init_out_value = MPC_framework_P.SFunction_p2;
      MPC_framework_B.init_out_trigger = 1U;
    }
    break;
   case MPC_framework_IN_INIT_ACK:
    MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
      (uint8_T)MPC_framework_IN_OPERATION;
    MPC_framework_DWork.StateMachine.is_OPERATION =
      (uint8_T)MPC_framework_IN_STOPPED;
    MPC_framework_B.motor1_reference = (uint16_T)MPC_framewo_motor_stopped_value;
    MPC_framework_B.motor2_reference = (uint16_T)MPC_framewo_motor_stopped_value;
    break;
   case MPC_framework_IN_OPERATION:
    MPC_framework_B.controller_enable = 1U;
    switch(MPC_framework_DWork.StateMachine.is_OPERATION) {
     case MPC_framework_IN_MOVING:
      if(MPC_framework_B.CANMessageUnpackingCANdb_g == 2) {
        MPC_framework_DWork.StateMachine.is_MOVING =
          (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
        MPC_framework_DWork.StateMachine.is_OPERATION =
          (uint8_T)MPC_framework_IN_STOPPED;
        MPC_framework_B.motor1_reference =
          (uint16_T)MPC_framewo_motor_stopped_value;
        MPC_framework_B.motor2_reference =
          (uint16_T)MPC_framewo_motor_stopped_value;
      } else if(MPC_framework_B.CANMessageUnpackingCANdb_ee == 2) {
        MPC_framework_DWork.StateMachine.is_MOVING =
          (uint8_T)MPC_framewor_IN_NO_ACTIVE_CHILD;
        MPC_framework_DWork.StateMachine.is_OPERATION =
          (uint8_T)MPC_framework_IN_STOPPED;
        MPC_framework_B.motor1_reference =
          (uint16_T)MPC_framewo_motor_stopped_value;
        MPC_framework_B.motor2_reference =
          (uint16_T)MPC_framewo_motor_stopped_value;
      }
      break;
     case MPC_framework_IN_STOPPED:
      if(MPC_framework_B.CANMessageUnpackingCANdb_ee == 1) {
        MPC_framework_B.stop_trigger = 0U;
        MPC_framework_DWork.StateMachine.is_OPERATION =
          (uint8_T)MPC_framework_IN_MOVING;
        MPC_framework_DWork.StateMachine.is_MOVING =
          (uint8_T)MPC_framew_IN_POSITIVE_MOVEMENT;
        MPC_framework_B.motor1_reference =
          (uint16_T)MPC_framew_motor_positive_value;
      } else if(MPC_framework_B.CANMessageUnpackingCANdb_g == 1) {
        MPC_framework_B.stop_trigger = 0U;
        MPC_framework_DWork.StateMachine.is_OPERATION =
          (uint8_T)MPC_framework_IN_MOVING;
        MPC_framework_DWork.StateMachine.is_MOVING =
          (uint8_T)MPC_framew_IN_NEGATIVE_MOVEMENT;
        MPC_framework_B.motor1_reference =
          (uint16_T)MPC_framew_motor_negative_value;
      }
      break;
     default:
      MPC_framework_DWork.StateMachine.is_OPERATION =
        (uint8_T)MPC_framework_IN_STOPPED;
      MPC_framework_B.motor1_reference =
        (uint16_T)MPC_framewo_motor_stopped_value;
      MPC_framework_B.motor2_reference =
        (uint16_T)MPC_framewo_motor_stopped_value;
      break;
    }
    break;
   default:
    MPC_framework_DWork.StateMachine.is_c1_MPC_framework =
      (uint8_T)MPC_framework_IN_INIT;
    MPC_framework_B.init_out_value = MPC_framework_P.SFunction_p1;
    MPC_framework_B.init_out_enable = 1U;
    break;
  }
}

/* Model step function for TID0 */

void MPC_framework_step0(void)          /* Sample time: [0.01s, 0.0s] */
{

  {                                     /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Block: <S40>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime),&GlobalModuleCAN_A,4) ==
   MSG_RECEIVED ){

    /* Output and update for function-call system: '<S9>/CAN Message Unpacking (CANdb)' */

    /*--- S-Function Block: <S38>/CAN Message Unpacking (CANdb) ---*/
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

    /* RelationalOperator: '<S42>/Compare' incorporates:
     *  Constant: '<S42>/Constant'
     */
    MPC_framework_B.Compare_i = (MPC_framework_B.CANMessageUnpackingCANdb_m ==
      MPC_framework_P.Constant_Value_g);
  }

  /* Block: <S41>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_p),&GlobalModuleCAN_A,5)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S9>/CAN Message Unpacking (CANdb)1' */

    /*--- S-Function Block: <S39>/CAN Message Unpacking (CANdb) ---*/
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

    /* RelationalOperator: '<S43>/Compare' incorporates:
     *  Constant: '<S43>/Constant'
     */
    MPC_framework_B.Compare = (MPC_framework_B.CANMessageUnpackingCANdb_e ==
      MPC_framework_P.Constant_Value_h);
  }

  /* Block: <S50>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_d),&GlobalModuleCAN_A,7)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S10>/positive_button message unpacking' */

    /*--- S-Function Block: <S51>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_d.DATA[0]
        | (MPC_framework_B.Datarealtime_d.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_d.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_d.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_d.DATA[4]
        | (MPC_framework_B.Datarealtime_d.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_d.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_d.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal positive_button ------------------ 
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
        MPC_framework_B.CANMessageUnpackingCANdb_ee = (uint8_T) workingoutput;
      }

      /* ------ END Unpacking CANdb signal positive_button  ----- */
    }
  }

  /* Block: <S48>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_a),&GlobalModuleCAN_A,6)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S10>/negative_button message unpacking' */

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
        MPC_framework_B.Datarealtime_a.DATA[0]
        | (MPC_framework_B.Datarealtime_a.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_a.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_a.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_a.DATA[4]
        | (MPC_framework_B.Datarealtime_a.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_a.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_a.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal negative_button ------------------ 
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
        MPC_framework_B.CANMessageUnpackingCANdb_g = (uint8_T) workingoutput;
      }

      /* ------ END Unpacking CANdb signal negative_button  ----- */
    }
  }

  /* Stateflow: '<Root>/State Machine' */
  MPC_fram_StateMachine();

  /* Outputs for enable SubSystem: '<Root>/Controller' */
  if(MPC_framework_B.controller_enable > 0U) {
    MPC_framework_DWork.Controller_MODE = SUBSYS_ENABLED;
  } else if(MPC_framework_DWork.Controller_MODE == SUBSYS_ENABLED) {

    MPC_framework_DWork.Controller_MODE = SUBSYS_DISABLED;
  }
  if(MPC_framework_DWork.Controller_MODE == SUBSYS_ENABLED) {

    /* Inport: '<S1>/motor1_reference' */
    MPC_framework_B.motor1_reference_j = MPC_framework_B.motor1_reference;

    /* Inport: '<S1>/motor2_reference' */
    MPC_framework_B.motor2_reference_l = MPC_framework_B.motor2_reference;
  }

  /* end of Outputs for SubSystem: '<Root>/Controller' */

  if(MPC_framework_B.controller_enable > 0U) {
    if(MPC_framework_DWork.DA_out_valuesender_MODE == SUBSYS_DISABLED) {
    }
    MPC_framework_DWork.DA_out_valuesender_MODE = SUBSYS_ENABLED;
  } else if(MPC_framework_DWork.DA_out_valuesender_MODE == SUBSYS_ENABLED) {

    MPC_framework_DWork.DA_out_valuesender_MODE = SUBSYS_DISABLED;
  }
  if(MPC_framework_DWork.DA_out_valuesender_MODE == SUBSYS_ENABLED) {

    /* Output and update for enable system: '<Root>/DA_out_value sender' */

    /*--- S-Function Block: <S2>/DA_out_value message packing ---*/
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
        /* no scaling required */
        real64_T result = MPC_framework_P.Constant_Value;

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

        /* widen the input datatype, uint16_T, 
           to the processor word size, uint32_T,
           for the scaling calculation */

        uint32_T result = (uint32_T) MPC_framework_B.motor2_reference_l;

        /* no scaling required */

        scaledSignal = result;
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

        /* widen the input datatype, uint16_T, 
           to the processor word size, uint32_T,
           for the scaling calculation */

        uint32_T result = (uint32_T) MPC_framework_B.motor1_reference_j;

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

    /*--- S-Function Block: <S3>/init message packing ---*/
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

  /* Block: <S29>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_pr),&GlobalModuleCAN_A,3)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S7>/incremental_in_value unpacking' */

    /*--- S-Function Block: <S30>/CAN Message Unpacking (CANdb) ---*/
    {
      /* final input words that contain all signals as read from the message */
      uint32_T input_word0 = 0;
      uint32_T input_word1 = 0;

      /* variable to hold each unscaled unpacked signal */
      uint32_T unscaledSignal = 0;

      /* CAN message byte array is not guaranteed to be word aligned,
       * copy bytes individually to the input_words */

      input_word0 |=
        MPC_framework_B.Datarealtime_pr.DATA[0]
        | (MPC_framework_B.Datarealtime_pr.DATA[1] << 8)
        | (MPC_framework_B.Datarealtime_pr.DATA[2] << 16)
        | (MPC_framework_B.Datarealtime_pr.DATA[3] << 24);

      input_word1 |=
        MPC_framework_B.Datarealtime_pr.DATA[4]
        | (MPC_framework_B.Datarealtime_pr.DATA[5] << 8)
        | (MPC_framework_B.Datarealtime_pr.DATA[6] << 16)
        | (MPC_framework_B.Datarealtime_pr.DATA[7] << 24);

      /* --------------- START Unpacking CANdb signal cntr1 ------------------ 
       *  startBit                = 32
       *  length                  = 16
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
        working_word0 = input_word1;

        /* The signal is to be unpacked in little endian format
           No need to reverse the bytes in each word */

        unscaledSignal = working_word0;
        unscaledSignal &= 0xFFFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_o = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal cntr1  ----- */

      /* --------------- START Unpacking CANdb signal cntr2 ------------------ 
       *  startBit                = 16
       *  length                  = 16
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

        unscaledSignal = working_word0 >> 16;
        unscaledSignal &= 0xFFFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_c = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal cntr2  ----- */

      /* --------------- START Unpacking CANdb signal cntr3 ------------------ 
       *  startBit                = 0
       *  length                  = 16
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
        unscaledSignal &= 0xFFFF;
      }

      {
        /* map scaledValue back to a real taking care of sign */
        MPC_framework_B.CANMessageUnpackingCANdb_n = (real64_T) unscaledSignal;

        /* no scaling required */
      }

      /* ------ END Unpacking CANdb signal cntr3  ----- */
    }
  }

  if(MPC_framework_B.controller_enable > 0U) {
    if(MPC_framework_DWork.incremental_out_valuesender_MO == SUBSYS_DISABLED) {
    }
    MPC_framework_DWork.incremental_out_valuesender_MO = SUBSYS_ENABLED;
  } else if(MPC_framework_DWork.incremental_out_valuesender_MO ==
   SUBSYS_ENABLED) {

    MPC_framework_DWork.incremental_out_valuesender_MO = SUBSYS_DISABLED;
  }
  if(MPC_framework_DWork.incremental_out_valuesender_MO == SUBSYS_ENABLED) {

    /* Output and update for enable system: '<Root>/incremental_out_value sender' */

    /*--- S-Function Block: <S8>/incremental_out_value message packing ---*/
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
        real64_T result = MPC_framework_B.CANMessageUnpackingCANdb_o;

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
        real64_T result = MPC_framework_B.CANMessageUnpackingCANdb_c;

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

    /*--- S-Function Block: <S12>/stop message packing ---*/
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

  /* Block: <S66>/CAN Receive (S-Function)
   * Receive CAN message 
   */
  if( receiveCanMessage(&(MPC_framework_B.Datarealtime_k),&GlobalModuleCAN_A,8)
   == MSG_RECEIVED ){

    /* Output and update for function-call system: '<S13>/stop_button message packing' */

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
}

/* Model step function for TID1 */

void MPC_framework_step1(void)          /* Sample time: [0.1s, 0.0s] */
{

  if(MPC_framework_DWork.request_incremental_valuesende == SUBSYS_ENABLED) {

    /* Output and update for enable system: '<Root>/request_incremental_value sender' */

    /*--- S-Function Block: <S11>/request_incremental_value message packing ---*/
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
      for (i = 0; i < 6; i++) {
        ((CAN_FRAME*)pVoidBlockIORegion)[i] = CAN_FRAME_GROUND;
      }

      pVoidBlockIORegion = (void *)(&MPC_framework_B.stopmessagepacking);
      for (i = 0; i < 6; i++) {
        ((CAN_FRAME*)pVoidBlockIORegion)[i] = CAN_FRAME_GROUND;
      }

      pVoidBlockIORegion = (void *)(&MPC_framework_B.CANMessageUnpackingCANdb);
      for (i = 0; i < 6; i++) {
        ((real_T*)pVoidBlockIORegion)[i] = 0.0;
      }
    }

    /* states (dwork) */

    (void) memset((char_T *) &MPC_framework_DWork,0,
     sizeof(D_Work_MPC_framework));

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
       2U                               /*propseg*/
       , 3U                             /*pseg1*/
       , 2U                             /*pseg2*/
       , 25U                            /*presdiv*/
       , 1                              /*rjw*/
       , 8                              /* num quanta */
       , 0.75                           /* sample point */
       , 100000                         /* bit rate */
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

    /* Initialize TouCAN module CAN_A, buffer 4 for operation with polling.
     * Received message identifier 0x2
     */
    initCanRx(&GlobalModuleCAN_A,4,CAN_MESSAGE_STANDARD,2);

    /* Initialize TouCAN module CAN_A, buffer 5 for operation with polling.
     * Received message identifier 0x3
     */
    initCanRx(&GlobalModuleCAN_A,5,CAN_MESSAGE_STANDARD,3);

    /* Initialize TouCAN module CAN_A, buffer 7 for operation with polling.
     * Received message identifier 0x8
     */
    initCanRx(&GlobalModuleCAN_A,7,CAN_MESSAGE_STANDARD,8);

    /* Initialize TouCAN module CAN_A, buffer 6 for operation with polling.
     * Received message identifier 0x9
     */
    initCanRx(&GlobalModuleCAN_A,6,CAN_MESSAGE_STANDARD,9);

    /* Start for enable system: '<Root>/DA_out_value sender' */

    /*--- S-Function Block: <S2>/DA_out_value message packing ---*/
    MPC_framework_B.DA_out_valuemessagepacking.ID = 6U;
    MPC_framework_B.DA_out_valuemessagepacking.type = 0U;
    MPC_framework_B.DA_out_valuemessagepacking.LENGTH = 6U;

    /* Start for enable system: '<Root>/Init 1 message sender' */

    /*--- S-Function Block: <S3>/init message packing ---*/
    MPC_framework_B.initmessagepacking_b.ID = 1U;
    MPC_framework_B.initmessagepacking_b.type = 0U;
    MPC_framework_B.initmessagepacking_b.LENGTH = 1U;

    /* Start for trigger system: '<Root>/Init 2 message sender' */

    /*--- S-Function Block: <S4>/init message packing ---*/
    MPC_framework_B.initmessagepacking.ID = 1U;
    MPC_framework_B.initmessagepacking.type = 0U;
    MPC_framework_B.initmessagepacking.LENGTH = 1U;

    /* Initialize TouCAN module CAN_A, buffer 3 for operation with polling.
     * Received message identifier 0x7
     */
    initCanRx(&GlobalModuleCAN_A,3,CAN_MESSAGE_STANDARD,7);

    /* Start for enable system: '<Root>/incremental_out_value sender' */

    /*--- S-Function Block: <S8>/incremental_out_value message packing ---*/
    MPC_framework_B.incremental_out_valuemessagep.ID = 6U;
    MPC_framework_B.incremental_out_valuemessagep.type = 0U;
    MPC_framework_B.incremental_out_valuemessagep.LENGTH = 4U;

    /* Start for enable system: '<Root>/request_incremental_value sender' */

    /*--- S-Function Block: <S11>/request_incremental_value message packing ---*/
    MPC_framework_B.request_incremental_valuemessa.ID = 0U;
    MPC_framework_B.request_incremental_valuemessa.type = 0U;
    MPC_framework_B.request_incremental_valuemessa.LENGTH = 1U;

    /* Start for trigger system: '<Root>/stop message sender' */

    /*--- S-Function Block: <S12>/stop message packing ---*/
    MPC_framework_B.stopmessagepacking.ID = 5U;
    MPC_framework_B.stopmessagepacking.type = 0U;
    MPC_framework_B.stopmessagepacking.LENGTH = 1U;

    /* Initialize TouCAN module CAN_A, buffer 8 for operation with polling.
     * Received message identifier 0x4
     */
    initCanRx(&GlobalModuleCAN_A,8,CAN_MESSAGE_STANDARD,4);
  }

  MPC_framework_PrevZCSigState.stopmessagesender_ZCE = POS_ZCSIG;

  MPC_framework_PrevZCSigState.Init2messagesender_ZCE = POS_ZCSIG;

  /*atomic Subsystem Block: '<Root>/State Machine' */
  MPC_frame_StateMachine_Init();
}

/* Model terminate function */

void MPC_framework_terminate(void)
{
  /* (no terminate code required) */
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
