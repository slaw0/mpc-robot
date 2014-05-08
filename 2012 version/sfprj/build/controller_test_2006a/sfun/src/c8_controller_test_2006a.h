#ifndef __c8_controller_test_2006a_h__
#define __c8_controller_test_2006a_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c8_is_active_c8_controller_test_2006a;
  ChartInfoStruct chartInfo;
} SFc8_controller_test_2006aInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c8_controller_test_2006a_get_check_sum(mxArray *plhs[]);
extern void c8_controller_test_2006a_method_dispatcher(SimStruct *S, int_T
 method, void *data);

#endif

