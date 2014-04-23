#ifndef __c2_MPC_framework_h__
#define __c2_MPC_framework_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c2_is_active_c2_MPC_framework;
  ChartInfoStruct chartInfo;
} SFc2_MPC_frameworkInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c2_MPC_framework_get_check_sum(mxArray *plhs[]);
extern void c2_MPC_framework_method_dispatcher(SimStruct *S, int_T method, void
 *data);

#endif

