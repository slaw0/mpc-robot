/*
 * File: serial_test.c
 *
 * Real-Time Workshop code generated for Simulink model serial_test.
 *
 * Model version                        : 1.22
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Mar 26 18:24:19 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Mar 26 18:24:19 2014
 */

#include "serial_test.h"
#include "serial_test_private.h"

/* Block signals (auto storage) */
BlockIO_serial_test serial_test_B;

/* Real-time model */
RT_MODEL_serial_test serial_test_M_;
RT_MODEL_serial_test *serial_test_M = &serial_test_M_;

static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */

void serial_test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = rtmStepTask(serial_test_M, 1);
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
  if (++serial_test_M->Timing.TaskCounters.TID[1] == 10) { /* Sample time: [0.1s, 0.0s] */
    serial_test_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */

void serial_test_step0(void)            /* Sample time: [0.01s, 0.0s] */
{

  {                                     /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */

void serial_test_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  /* local block i/o variables */
  uint16_T rtb_Switch;
  uint16_T rtb_BitwiseOperator1;
  uint16_T rtb_BitwiseOperator;
  uint16_T rtb_Switch_b;
  uint16_T rtb_BitwiseOperator1_f;
  uint16_T rtb_BitwiseOperator_n;
  uint8_T rtb_SerialReceive1_o1;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_c;

  {
    uint32_T tmpVar = (1 <= 1U) ? 1 : 1U;
    serial_test_B.SerialReceive_o2 = general_get_string_sci1(
      &rtb_SerialReceive1_o1,tmpVar);
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Compare = (serial_test_B.SerialReceive_o2 > serial_test_P.Constant_Value);

  /* Output and update for atomic system: '<S3>/Subsystem' */
  {

    /* user code (Output function Header) */
    /* System : <S3>/Subsystem */
    EID();

    /* Output and update for atomic system: '<S9>/fd' */

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/masks'
     */
    if(rtb_Compare) {
      rtb_Switch_b = serial_test_P.masks_Value;
    } else {
      rtb_Switch_b = serial_test_P.Constant_Value_l;
    }

    /* S-Function (sfix_bitop): '<S12>/Bitwise Operator1' incorporates:
     *  S-Function (sfun_get_expr): '<S12>/RTW memory get'
     */
    /* Bitwise Block: '<S12>/Bitwise Operator1'
     * AND
     */
    rtb_BitwiseOperator1_f = (((uint16_T)(MIOS1.MPIOSM32DR.R ))) &
      (serial_test_P.BitwiseOperator1_BitMask);

    /* S-Function (sfix_bitop): '<S12>/Bitwise Operator' */
    /* Bitwise Block: '<S12>/Bitwise Operator'
     * OR
     */
    rtb_BitwiseOperator_n = (rtb_Switch_b) | (rtb_BitwiseOperator1_f);

    /* S-Function (sfun_set_expr): '<S12>/RTW memory set' */

    MIOS1.MPIOSM32DR.R = (VUINT16) rtb_BitwiseOperator_n;

    /* user code (Output function Trailer) */
    /* System : <S3>/Subsystem */
    EIE();
  }

  general_send_string_sci1(&rtb_SerialReceive1_o1,serial_test_B.SerialReceive_o2);

  {
    uint32_T tmpVar = (1 <= 1U) ? 1 : 1U;
    serial_test_B.SerialReceive1_o2 = general_get_string_sci2(
      &rtb_SerialReceive1_o1,tmpVar);
  }

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Compare_c = (serial_test_B.SerialReceive1_o2 >
    serial_test_P.Constant_Value_a);

  /* Output and update for atomic system: '<S4>/Subsystem' */
  {

    /* user code (Output function Header) */
    /* System : <S4>/Subsystem */
    EID();

    /* Output and update for atomic system: '<S16>/fd' */

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S19>/masks'
     */
    if(rtb_Compare_c) {
      rtb_Switch = serial_test_P.masks_Value_i;
    } else {
      rtb_Switch = serial_test_P.Constant_Value_f;
    }

    /* S-Function (sfix_bitop): '<S19>/Bitwise Operator1' incorporates:
     *  S-Function (sfun_get_expr): '<S19>/RTW memory get'
     */
    /* Bitwise Block: '<S19>/Bitwise Operator1'
     * AND
     */
    rtb_BitwiseOperator1 = (((uint16_T)(MIOS1.MPIOSM32DR.R ))) &
      (serial_test_P.BitwiseOperator1_BitMas_d);

    /* S-Function (sfix_bitop): '<S19>/Bitwise Operator' */
    /* Bitwise Block: '<S19>/Bitwise Operator'
     * OR
     */
    rtb_BitwiseOperator = (rtb_Switch) | (rtb_BitwiseOperator1);

    /* S-Function (sfun_set_expr): '<S19>/RTW memory set' */

    MIOS1.MPIOSM32DR.R = (VUINT16) rtb_BitwiseOperator;

    /* user code (Output function Trailer) */
    /* System : <S4>/Subsystem */
    EIE();
  }

  general_send_string_sci2(&rtb_SerialReceive1_o1,serial_test_B.SerialReceive1_o2);
}

void serial_test_step(int_T tid) {

  switch(tid) {
   case 0 :
    serial_test_step0();
    break;
   case 1 :
    serial_test_step1();
    break;
   default :
    break;
  }
}

/* Model initialize function */

void serial_test_initialize(boolean_T firstTime)
{
  if (firstTime) {

    /* Registration code */
    /* initialize real-time model */
    (void) memset((char_T *)serial_test_M,0,
     sizeof(RT_MODEL_serial_test));

    /* block I/O */

    (void) memset(((void *) &serial_test_B),0,
     sizeof(BlockIO_serial_test));

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

    /* -- Resource Configuration : MPC555dkConfig::MIOS1 : [START] --- */

    /* -- Main MIOS Configuration --- */

    MIOS1.MCPSMSCR.B.FREN = 1;
    MIOS1.MCPSMSCR.B.PREN = 1;
    MIOS1.MCPSMSCR.B.PSL = 0;

    /* -- Modulus Counter --- 6 */

    /* Freeze Enable */
    MIOS1.MMCSM6SCRD.B.FREN = 1;

    /* Clock Prescaler */
    MIOS1.MMCSM6SCRD.B.CP = 0;

    /* Modulus Latch Register */
    MIOS1.MMCSM6MLR.R = 0;

    /* Clock Select = MMCSM Clock Prescaler */
    MIOS1.MMCSM6SCRD.B.CLS = 3;

    /* Modulus Load Sensitivity = Disabled */
    MIOS1.MMCSM6SCRD.B.EDGN = 0;
    MIOS1.MMCSM6SCRD.B.EDGP = 0;

    /*-- Modulus Counter 22 ---*/

    /* Freeze Enable */
    MIOS1.MMCSM22SCRD.B.FREN = 1;

    /* Clock Prescaler */
    MIOS1.MMCSM22SCRD.B.CP = 0;

    /* Clock Select = MMCSM Clock Prescaler */
    MIOS1.MMCSM22SCRD.B.CLS = 3;

    /* Modulus Latch Register */
    MIOS1.MMCSM22MLR.R = 0;

    /* Modulus Load Sensitivity = Disabled : EDGN + EDGP */
    MIOS1.MMCSM22SCRD.B.EDGN = 0;
    MIOS1.MMCSM22SCRD.B.EDGP = 0;

    /* -- Resource Configuration : MPC555dkConfig::MIOS1 : [END] --- */

    /* -- Resource Configuration : MPC555dkConfig::QSMCM : [START] --- */

    {
      /* SCI1 control register 0 
       * Ideal bit rate = 9600
       * Achieved bit rate = 9.6153846153846152E+003
       * Calculation based on system clock = 20000000
       * Loop mode = Standard transmit/receive
       */
      const uint16_T sc1br = 0x41U;
      /* SCI1 control register 1 
       * Using 8-bit data
       * Parity = N/A
       */
      const uint16_T scc1r1 = 0xcU;

      qsmcm_sci1_init(sc1br, scc1r1);
    }

    {
      /* SCI2 control register 0 
       * Ideal bit rate = 9600
       * Achieved bit rate = 9.6153846153846152E+003
       * Calculation based on system clock = 20000000
       * Loop mode = Standard transmit/receive
       */
      const uint16_T sc2br = 0x41U;
      /* SCI2 control register 1 
       * Using 8-bit data
       * Parity = N/A
       */
      const uint16_T scc2r1 = 0xcU;

      qsmcm_sci2_init(sc2br, scc2r1);
    }

    /* -- Resource Configuration : MPC555dkConfig::QSMCM : [END] --- */

    /* Initialize MIOS Digital Out                                                 
       Bits          [ 0 ]                                                        
       Initial Value [ 0 ]                                                        
     */
    MIOS1.MPIOSM32DDR.R |= (VUINT16) 0x1;
    MIOS1.MPIOSM32DR.R = ( MIOS1.MPIOSM32DR.R & (VUINT16) 0xFFFE ) | (VUINT16)
      0x0;

    /* Initialize MIOS Digital Out                                                 
       Bits          [ 1 ]                                                        
       Initial Value [ 0 ]                                                        
     */
    MIOS1.MPIOSM32DDR.R |= (VUINT16) 0x2;
    MIOS1.MPIOSM32DR.R = ( MIOS1.MPIOSM32DR.R & (VUINT16) 0xFFFD ) | (VUINT16)
      0x0;
  }
}

/* Model terminate function */

void serial_test_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
