/* Include files */
#include "controller_test_2006a_sfun.h"
#include "c3_controller_test_2006a.h"
#include "c4_controller_test_2006a.h"
#include "c7_controller_test_2006a.h"
#include "c8_controller_test_2006a.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _controller_test_2006aMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void controller_test_2006a_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void controller_test_2006a_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_controller_test_2006a_method_dispatcher(SimStruct *simstructPtr,
 const char *chartName, int_T method, void *data)
{
  if(!strcmp_ignore_ws(chartName,"controller_test_2006a/Trajectory design1/Curve calculation/Joint reference singal 1/ SFunction "))
  {
    c3_controller_test_2006a_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"controller_test_2006a/Trajectory design1/Curve calculation/Joint reference singal 2/ SFunction "))
  {
    c4_controller_test_2006a_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"controller_test_2006a/Trajectory design1/Init/Trajectory design 1/ SFunction "))
  {
    c7_controller_test_2006a_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"controller_test_2006a/Trajectory design1/Init/Trajectory design 2/ SFunction "))
  {
    c8_controller_test_2006a_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_controller_test_2006a_process_check_sum_call( int nlhs, mxArray
 * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(901932305U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1004691407U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2827364091U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2595383857U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3873636311U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2698341060U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1049816125U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(985010704U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 3:
        {
          extern void sf_c3_controller_test_2006a_get_check_sum(mxArray *plhs[]);
          sf_c3_controller_test_2006a_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_controller_test_2006a_get_check_sum(mxArray *plhs[]);
          sf_c4_controller_test_2006a_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_controller_test_2006a_get_check_sum(mxArray *plhs[]);
          sf_c7_controller_test_2006a_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_controller_test_2006a_get_check_sum(mxArray *plhs[]);
          sf_c8_controller_test_2006a_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2734356174U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3347896126U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2233157383U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(525562952U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3708759055U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2001559031U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1653980818U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2423269908U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_controller_test_2006a_autoinheritance_info( int nlhs, mxArray *
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
        extern mxArray
        *sf_c3_controller_test_2006a_get_autoinheritance_info(void);
        plhs[0] = sf_c3_controller_test_2006a_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray
        *sf_c4_controller_test_2006a_get_autoinheritance_info(void);
        plhs[0] = sf_c4_controller_test_2006a_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray
        *sf_c7_controller_test_2006a_get_autoinheritance_info(void);
        plhs[0] = sf_c7_controller_test_2006a_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray
        *sf_c8_controller_test_2006a_get_autoinheritance_info(void);
        plhs[0] = sf_c8_controller_test_2006a_get_autoinheritance_info();
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
void controller_test_2006a_debug_initialize(void)
{
  _controller_test_2006aMachineNumber_ =
    sf_debug_initialize_machine("controller_test_2006a","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(_controller_test_2006aMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_controller_test_2006aMachineNumber_,0);
}

void controller_test_2006a_register_exported_symbols(SimStruct* S)
{
}
