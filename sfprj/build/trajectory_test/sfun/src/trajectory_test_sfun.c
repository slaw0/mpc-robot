/* Include files */
#include "trajectory_test_sfun.h"
#include "c3_trajectory_test.h"
#include "c4_trajectory_test.h"
#include "c7_trajectory_test.h"
#include "c8_trajectory_test.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _trajectory_testMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void trajectory_test_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void trajectory_test_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_trajectory_test_method_dispatcher(SimStruct *simstructPtr, const
 char *chartName, int_T method, void *data)
{
  if(!strcmp_ignore_ws(chartName,"trajectory_test/Trajectory design1/Curve calculation/Joint reference singal 1/ SFunction "))
  {
    c3_trajectory_test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"trajectory_test/Trajectory design1/Curve calculation/Joint reference singal 2/ SFunction "))
  {
    c4_trajectory_test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"trajectory_test/Trajectory design1/Init/Trajectory design 1/ SFunction "))
  {
    c7_trajectory_test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"trajectory_test/Trajectory design1/Init/Trajectory design 2/ SFunction "))
  {
    c8_trajectory_test_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_trajectory_test_process_check_sum_call( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"sf_get_check_sum")) return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if(nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(505215296U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(577739690U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2222618968U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1957428758U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2349917130U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3732336188U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2531680547U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3061598361U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 3:
        {
          extern void sf_c3_trajectory_test_get_check_sum(mxArray *plhs[]);
          sf_c3_trajectory_test_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_trajectory_test_get_check_sum(mxArray *plhs[]);
          sf_c4_trajectory_test_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_trajectory_test_get_check_sum(mxArray *plhs[]);
          sf_c7_trajectory_test_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_trajectory_test_get_check_sum(mxArray *plhs[]);
          sf_c8_trajectory_test_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1754806362U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1973214305U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1659388014U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2148097642U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2242048874U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(289544939U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3269081762U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1474773730U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_trajectory_test_autoinheritance_info( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_autoinheritance_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 3:
      {
        extern mxArray *sf_c3_trajectory_test_get_autoinheritance_info(void);
        plhs[0] = sf_c3_trajectory_test_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_trajectory_test_get_autoinheritance_info(void);
        plhs[0] = sf_c4_trajectory_test_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_trajectory_test_get_autoinheritance_info(void);
        plhs[0] = sf_c7_trajectory_test_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_trajectory_test_get_autoinheritance_info(void);
        plhs[0] = sf_c8_trajectory_test_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void trajectory_test_debug_initialize(void)
{
  _trajectory_testMachineNumber_ =
  sf_debug_initialize_machine("trajectory_test","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(_trajectory_testMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_trajectory_testMachineNumber_,0);
}

void trajectory_test_register_exported_symbols(SimStruct* S)
{
}
