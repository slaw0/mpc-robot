/*
 * File: serial_test_private.h
 *
 * Real-Time Workshop code generated for Simulink model serial_test.
 *
 * Model version                        : 1.22
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Wed Mar 26 18:24:19 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Wed Mar 26 18:24:19 2014
 */

#ifndef _RTW_HEADER_serial_test_private_h_
#define _RTW_HEADER_serial_test_private_h_

#include "rtwtypes.h"

#ifndef MPC555_VARIANT
/* For processors other than mpc555 such as the mpc565 the MIOS is now known as
   the MIOS14 which is backward compatible with the MPC555 */
#define MIOS1                           MIOS14
#endif
#ifndef MPC555_VARIANT
/* For processors other than mpc555 such as the mpc565 the QSMCM is known as
   the QSMCM_A, QSMCM_B. Currently, we support only a single QSMCM */
#define QSMCM                           QSMCM_A
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else
/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                  /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                  /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                  /* __RTWTYPES_H__ */

#endif                                  /* _RTW_HEADER_serial_test_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
