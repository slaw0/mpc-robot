/*
 * File: can_test.h
 *
 * Real-Time Workshop code generated for Simulink model can_test.
 *
 * Model version                        : 1.1
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Mar 19 13:49:57 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Mar 19 13:49:57 2014
 */

#ifndef _RTW_HEADER_can_test_h_
#define _RTW_HEADER_can_test_h_

#ifndef _can_test_COMMON_INCLUDES_
# define _can_test_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpc5xx.h"
#include "can_msg.h"
#include "can_driver.h"
#include "isr.h"
#include "can_tx_queue.h"
#include "can_callback.h"
#endif                                  /* _can_test_COMMON_INCLUDES_ */

#include "can_test_types.h"

/* Macros for accessing real-time model data structure  */

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

/* user code (top of export header file) */

/* The interrupt level for rtOnestep function */
#define RT_ONE_STEP_IRQ                 INT_LEVEL0

/* The oscillator frequency of the processor  */
#define OSCILLATOR_FREQ                 20000000                 /* hz */
#include "can_msg.h"

/* Block signals (auto storage) */
typedef struct {
  CAN_FRAME initmessagepacking;         /* '<Root>/init message packing' */
} BlockIO_can_test;

/* Parameters (auto storage) */
struct _Parameters_can_test {
  uint8_T Constant_Value;               /* Computed Parameter: Value
                                         * '<Root>/Constant'
                                         */
};

/* Real-time Model Data Structure */
struct RT_MODEL_can_test {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_can_test can_test_P;

/* Block signals (auto storage) */
extern BlockIO_can_test can_test_B;

/* Model entry point functions */
extern void can_test_initialize(boolean_T firstTime);
extern void can_test_step(void);
extern void can_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_can_test *can_test_M;

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
 * '<Root>' : can_test
 * '<S1>'   : can_test/MPC555 Resource Configuration
 * '<S2>'   : can_test/TouCAN Transmit
 * '<S3>'   : can_test/TouCAN Transmit/Configurable Outport Control
 * '<S4>'   : can_test/TouCAN Transmit/Non-Configurable Inport Control
 * '<S5>'   : can_test/TouCAN Transmit/Pass through output
 * '<S6>'   : can_test/TouCAN Transmit/Pass through output/Pass through input
 */

#endif                                  /* _RTW_HEADER_can_test_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
