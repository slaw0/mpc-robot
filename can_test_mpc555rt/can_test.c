/*
 * File: can_test.c
 *
 * Real-Time Workshop code generated for Simulink model can_test.
 *
 * Model version                        : 1.1
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Mar 19 13:49:57 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Mar 19 13:49:57 2014
 */

#include "can_test.h"
#include "can_test_private.h"

/* Block signals (auto storage) */
BlockIO_can_test can_test_B;

/* Real-time model */
RT_MODEL_can_test can_test_M_;
RT_MODEL_can_test *can_test_M = &can_test_M_;

/* Model step function */

void can_test_step(void)
{

  /*--- S-Function Block: <Root>/init message packing ---*/
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

      uint32_T result = (uint32_T) can_test_P.Constant_Value;

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
    can_test_B.initmessagepacking.DATA[0] =
      (uint8_T) output_word0;

    can_test_B.initmessagepacking.DATA[1] =
      (uint8_T) (output_word0 >> 8);

    can_test_B.initmessagepacking.DATA[2] =
      (uint8_T) (output_word0 >> 16);

    can_test_B.initmessagepacking.DATA[3] =
      (uint8_T) (output_word0 >> 24);

    can_test_B.initmessagepacking.DATA[4] =
      (uint8_T) output_word1;

    can_test_B.initmessagepacking.DATA[5] =
      (uint8_T) (output_word1 >> 8);

    can_test_B.initmessagepacking.DATA[6] =
      (uint8_T) (output_word1 >> 16);

    can_test_B.initmessagepacking.DATA[7] =
      (uint8_T) (output_word1 >> 24);
  }

  /* Send message using priority queue and shared TouCAN buffer(s) */
  sendCanMessage(&GlobalModuleCAN_A,&can_test_B.initmessagepacking);
}

/* Model initialize function */

void can_test_initialize(boolean_T firstTime)
{
  if (firstTime) {

    /* Registration code */

    /* initialize error status */
    rtmSetErrorStatus(can_test_M, (const char_T *)0);

    /* block I/O */

    {

      ((CAN_FRAME*)&can_test_B.initmessagepacking)[0] = CAN_FRAME_GROUND;
    }

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

    /*--- S-Function Block: <Root>/init message packing ---*/
    can_test_B.initmessagepacking.ID = 1U;
    can_test_B.initmessagepacking.type = 0U;
    can_test_B.initmessagepacking.LENGTH = 1U;
  }
}

/* Model terminate function */

void can_test_terminate(void)
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
