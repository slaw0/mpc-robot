/*
 * File: serial_test.h
 *
 * Real-Time Workshop code generated for Simulink model serial_test.
 *
 * Model version                        : 1.22
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Mar 26 18:24:19 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Mar 26 18:24:19 2014
 */

#ifndef _RTW_HEADER_serial_test_h_
#define _RTW_HEADER_serial_test_h_

#ifndef _serial_test_COMMON_INCLUDES_
# define _serial_test_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpc5xx.h"
#include "qsmcm_sci.h"
#endif                                  /* _serial_test_COMMON_INCLUDES_ */

#include "serial_test_types.h"

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

/* user code (top of header file) */
/* System : <Root> */
/* MIOS Digital Out Required Header Files*/
#include "isr.h"

/* user code (top of export header file) */

/* The interrupt level for rtOnestep function */
#define RT_ONE_STEP_IRQ                 INT_LEVEL0

/* The oscillator frequency of the processor  */
#define OSCILLATOR_FREQ                 20000000                 /* hz */

/* Block signals (auto storage) */
typedef struct {
  uint32_T SerialReceive_o2;            /* '<Root>/Serial Receive' */
  uint32_T SerialReceive1_o2;           /* '<Root>/Serial Receive1' */
} BlockIO_serial_test;

/* Parameters (auto storage) */
struct _Parameters_serial_test {
  uint32_T Constant_Value;              /* Computed Parameter: Value
                                         * '<S1>/Constant'
                                         */
  uint32_T Constant_Value_a;            /* Computed Parameter: Value
                                         * '<S2>/Constant'
                                         */
  uint16_T Constant_Value_l;            /* Computed Parameter: Value
                                         * '<S12>/Constant'
                                         */
  uint16_T masks_Value;                 /* Expression: masks
                                         * '<S12>/masks'
                                         */
  uint16_T BitwiseOperator1_BitMask;    /* Expression: BitMask
                                         * '<S12>/Bitwise Operator1'
                                         */
  uint16_T Constant_Value_f;            /* Computed Parameter: Value
                                         * '<S19>/Constant'
                                         */
  uint16_T masks_Value_i;               /* Expression: masks
                                         * '<S19>/masks'
                                         */
  uint16_T BitwiseOperator1_BitMas_d;   /* Expression: BitMask
                                         * '<S19>/Bitwise Operator1'
                                         */
};

/* Real-time Model Data Structure */
struct RT_MODEL_serial_test {
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
extern Parameters_serial_test serial_test_P;

/* Block signals (auto storage) */
extern BlockIO_serial_test serial_test_B;

/* Model entry point functions */
extern void serial_test_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void serial_test_initialize(boolean_T firstTime);
extern void serial_test_step(int_T tid);
extern void serial_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_serial_test *serial_test_M;

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
 * '<Root>' : serial_test
 * '<S1>'   : serial_test/Compare To Constant
 * '<S2>'   : serial_test/Compare To Constant1
 * '<S3>'   : serial_test/MIOS Digital Out
 * '<S4>'   : serial_test/MIOS Digital Out1
 * '<S5>'   : serial_test/MPC555 Resource Configuration
 * '<S6>'   : serial_test/MIOS Digital Out/Configurable Outport Control
 * '<S7>'   : serial_test/MIOS Digital Out/Non-Configurable Inport Control
 * '<S8>'   : serial_test/MIOS Digital Out/Pass through output
 * '<S9>'   : serial_test/MIOS Digital Out/Subsystem
 * '<S10>'  : serial_test/MIOS Digital Out/Pass through output/Pass through input
 * '<S11>'  : serial_test/MIOS Digital Out/Subsystem/Disable MPC555 Interrupts
 * '<S12>'  : serial_test/MIOS Digital Out/Subsystem/fd
 * '<S13>'  : serial_test/MIOS Digital Out1/Configurable Outport Control
 * '<S14>'  : serial_test/MIOS Digital Out1/Non-Configurable Inport Control
 * '<S15>'  : serial_test/MIOS Digital Out1/Pass through output
 * '<S16>'  : serial_test/MIOS Digital Out1/Subsystem
 * '<S17>'  : serial_test/MIOS Digital Out1/Pass through output/Pass through input
 * '<S18>'  : serial_test/MIOS Digital Out1/Subsystem/Disable MPC555 Interrupts
 * '<S19>'  : serial_test/MIOS Digital Out1/Subsystem/fd
 */

#endif                                  /* _RTW_HEADER_serial_test_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
