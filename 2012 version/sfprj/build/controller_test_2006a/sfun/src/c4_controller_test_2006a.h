#ifndef __c4_controller_test_2006a_h__
#define __c4_controller_test_2006a_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c4_is_active_c4_controller_test_2006a;
  ChartInfoStruct chartInfo;
} SFc4_controller_test_2006aInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c4_controller_test_2006a_get_check_sum(mxArray *plhs[]);
extern void c4_controller_test_2006a_method_dispatcher(SimStruct *S, int_T
 method, void *data);

#endif

