#ifndef __c7_trajectory_test_h__
#define __c7_trajectory_test_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c7_is_active_c7_trajectory_test;
  ChartInfoStruct chartInfo;
} SFc7_trajectory_testInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c7_trajectory_test_get_check_sum(mxArray *plhs[]);
extern void c7_trajectory_test_method_dispatcher(SimStruct *S, int_T method,
 void *data);

#endif

