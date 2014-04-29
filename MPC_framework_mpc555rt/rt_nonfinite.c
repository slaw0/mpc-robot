/*
 * File: rt_nonfinite.c
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.907
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Tue Apr 29 19:27:31 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Tue Apr 29 19:27:32 2014
 */

/*
 * Abstract:
 *      Real-Time Workshop function to intialize non-finites,
 *      (Inf, NaN and -Inf).
 */
#include "rt_nonfinite.h"

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;

real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/* Function: rt_InitInfAndNaN ==================================================
 * Abstract:
 *	Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 *	generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize) {
  typedef struct {
    uint32_T sign : 1;
    uint32_T exponent : 8;
    uint32_T fraction : 23;
  } BigEndianIEEESingle;

  typedef struct {
    struct {
      uint32_T sign : 1;
      uint32_T exponent : 11;
      uint32_T fraction1 : 20;
    } wordL;
    struct {
      uint32_T fraction2;
    } wordH;
  } BigEndianIEEEDouble;

  (*(BigEndianIEEESingle*)&rtInfF).sign = 0;
  (*(BigEndianIEEESingle*)&rtInfF).exponent = 0xFF;
  (*(BigEndianIEEESingle*)&rtInfF).fraction = 0;
  rtMinusInfF = rtInfF;
  rtNaNF = rtInfF;
  (*(BigEndianIEEESingle*)&rtMinusInfF).sign = 1;
  (*(BigEndianIEEESingle*)&rtNaNF).fraction = 0x7FFFFF;

  if (realSize == 4) {
    (*(BigEndianIEEESingle*)&rtInf).sign = 0;
    (*(BigEndianIEEESingle*)&rtInf).exponent = 0xFF;
    (*(BigEndianIEEESingle*)&rtInf).fraction = 0;
    rtMinusInf = rtInf;
    rtNaN = rtInf;
    (*(BigEndianIEEESingle*)&rtMinusInf).sign = 1;
    (*(BigEndianIEEESingle*)&rtNaN).fraction = 0x7FFFFF;
  } else {
    (*(BigEndianIEEEDouble*)&rtInf).wordL.sign = 0;
    (*(BigEndianIEEEDouble*)&rtInf).wordL.exponent = 0x7FF;
    (*(BigEndianIEEEDouble*)&rtInf).wordL.fraction1 = 0;
    (*(BigEndianIEEEDouble*)&rtInf).wordH.fraction2 = 0;

    rtMinusInf = rtInf;
    (*(BigEndianIEEEDouble*)&rtMinusInf).wordL.sign = 1;
    (*(BigEndianIEEEDouble*)&rtNaN).wordL.sign = 0;
    (*(BigEndianIEEEDouble*)&rtNaN).wordL.exponent = 0x7FF;
    (*(BigEndianIEEEDouble*)&rtNaN).wordL.fraction1 = 0xFFFFF;
    (*(BigEndianIEEEDouble*)&rtNaN).wordH.fraction2 = 0xFFFFFFFF;
  }
}

/* Function: rtIsInf ==================================================
 * Abstract:
 *	Test if value is infinite
 */
boolean_T rtIsInf(real_T value) {
  return ((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Function: rtIsInfF =================================================
 * Abstract:
 *	Test if single-precision value is infinite
 */
boolean_T rtIsInfF(real32_T value) {
  return(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Function: rtIsNaN ==================================================
 * Abstract:
 *	Test if value is not a number
 */
boolean_T rtIsNaN(real_T value) {
  return((value!=value) ? 1U : 0U);
}

/* Function: rtIsNaNF =================================================
 * Abstract:
 *	Test if single-precision value is not a number
 */
boolean_T rtIsNaNF(real32_T value) {
  return((value!=value) ? 1U : 0U);
}

/* end rt_nonfinite.c */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
