/*
 * File: serial_test.h
 *
 * Real-Time Workshop code generated for Simulink model serial_test.
 *
 * Model version                        : 1.35
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Thu Apr 03 16:38:13 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Thu Apr 03 16:38:14 2014
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
  uint32_T SerialReceive2_o2;           /* '<Root>/Serial Receive2' */
} BlockIO_serial_test;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T Output_DSTATE;                /* '<S2>/Output' */
} D_Work_serial_test;

/* Parameters (auto storage) */
struct _Parameters_serial_test {
  uint32_T Constant_Value;              /* Computed Parameter: Value
                                         * '<S1>/Constant'
                                         */
  uint16_T Constant_Value_i;            /* Computed Parameter: Value
                                         * '<S13>/Constant'
                                         */
  uint16_T masks_Value;                 /* Expression: masks
                                         * '<S13>/masks'
                                         */
  uint16_T BitwiseOperator1_BitMask;    /* Expression: BitMask
                                         * '<S13>/Bitwise Operator1'
                                         */
  uint8_T Output_X0;                    /* Computed Parameter: X0
                                         * '<S2>/Output'
                                         */
  uint8_T FixPtConstant_Value;          /* Computed Parameter: Value
                                         * '<S5>/FixPt Constant'
                                         */
  uint8_T FixPtSwitch_Threshold;        /* Computed Parameter: Threshold
                                         * '<S6>/FixPt Switch'
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

/* Block states (auto storage) */
extern D_Work_serial_test serial_test_DWork;

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
 * '<S1>'   : serial_test/Compare To Constant2
 * '<S2>'   : serial_test/Counter Free-Running
 * '<S3>'   : serial_test/MIOS Digital Out2
 * '<S4>'   : serial_test/MPC555 Resource Configuration
 * '<S5>'   : serial_test/Counter Free-Running/Increment Real World
 * '<S6>'   : serial_test/Counter Free-Running/Wrap To Zero
 * '<S7>'   : serial_test/MIOS Digital Out2/Configurable Outport Control
 * '<S8>'   : serial_test/MIOS Digital Out2/Non-Configurable Inport Control
 * '<S9>'   : serial_test/MIOS Digital Out2/Pass through output
 * '<S10>'  : serial_test/MIOS Digital Out2/Subsystem
 * '<S11>'  : serial_test/MIOS Digital Out2/Pass through output/Pass through input
 * '<S12>'  : serial_test/MIOS Digital Out2/Subsystem/Disable MPC555 Interrupts
 * '<S13>'  : serial_test/MIOS Digital Out2/Subsystem/fd
 */

#endif                                  /* _RTW_HEADER_serial_test_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
