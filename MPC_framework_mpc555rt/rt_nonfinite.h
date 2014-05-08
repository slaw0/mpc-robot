/*
 * File: rt_nonfinite.h
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.1466
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Thu May 08 18:43:44 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Thu May 08 18:43:45 2014
 */

#ifndef _RTW_HEADER_rt_nonfinite_h_
#define _RTW_HEADER_rt_nonfinite_h_

#include <stddef.h>
#include "rtwtypes.h"

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;

extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);

#endif                                  /* _RTW_HEADER_rt_nonfinite_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
