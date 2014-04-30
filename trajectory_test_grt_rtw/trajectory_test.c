/*
 * trajectory_test.c
 * 
 * Real-Time Workshop code generation for Simulink model "trajectory_test.mdl".
 *
 * Model Version              : 1.29
 * Real-Time Workshop version : 6.4  (R2006a)  03-Feb-2006
 * C source code generated on : Wed Apr 30 13:11:18 2014
 */

#include "trajectory_test.h"
#include "trajectory_test_private.h"

/* Block signals (auto storage) */
BlockIO_trajectory_test trajectory_test_B;

/* Block states (auto storage) */
D_Work_trajectory_test trajectory_test_DWork;

/* Real-time model */
RT_MODEL_trajectory_test trajectory_test_M_;
RT_MODEL_trajectory_test *trajectory_test_M = &trajectory_test_M_;

/* Output and update for atomic system:
 *   '<S1>/Joint reference singal 1'
 *   '<S1>/Joint reference singal 2'
 */

void tJointreferencesingal1(real_T rtu_a0, real_T rtu_a1, real_T rtu_a2, real_T
 rtu_a3, real_T rtu_a4, real_T rtu_a5, real_T rtu_t_sim, real_T rtu_t_end,
 rtB_tJointreferencesingal1 *localB)
{
  /* local block i/o variables*/
  real_T rtb_qap;
  real_T rtb_qapp;

  /* Embedded MATLAB: '<S1>/Joint reference singal 1' */
  {
    real_T eml_t_sim;
    real_T eml_em_dv0[6];
    real_T eml_em_dv1[6];
    real_T eml_em_dv2[6];
    int32_T eml_em_i0;
    real_T eml_em_dv3[18];
    real_T eml_a0[6];
    real_T eml_Q[3];
    int32_T eml_em_i1;
    eml_t_sim = rtu_t_sim;
    if(rtu_t_sim > rtu_t_end) {
      /*  This block supports an embeddable subset of the MATLAB language. */
      /*  See the help menu for details.  */
      eml_t_sim = rtu_t_end;
    }
    eml_em_dv0[0] = pow(eml_t_sim, 5.0) / 20.0;
    eml_em_dv0[1] = pow(eml_t_sim, 4.0) / 12.0;
    eml_em_dv0[2] = pow(eml_t_sim, 3.0) / 6.0;
    eml_em_dv0[3] = pow(eml_t_sim, 2.0) / 2.0;
    eml_em_dv0[4] = eml_t_sim;
    eml_em_dv0[5] = 1.0;
    eml_em_dv1[0] = pow(eml_t_sim, 4.0) / 4.0;
    eml_em_dv1[1] = pow(eml_t_sim, 3.0) / 3.0;
    eml_em_dv1[2] = pow(eml_t_sim, 2.0) / 2.0;
    eml_em_dv1[3] = eml_t_sim;
    eml_em_dv1[4] = 1.0;
    eml_em_dv1[5] = 0.0;
    eml_em_dv2[0] = pow(eml_t_sim, 3.0);
    eml_em_dv2[1] = pow(eml_t_sim, 2.0);
    eml_em_dv2[2] = eml_t_sim;
    eml_em_dv2[3] = 1.0;
    eml_em_dv2[4] = 0.0;
    eml_em_dv2[5] = 0.0;
    for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
      eml_em_dv3[3 * eml_em_i0] = eml_em_dv0[eml_em_i0];
      eml_em_dv3[1 + 3 * eml_em_i0] = eml_em_dv1[eml_em_i0];
      eml_em_dv3[2 + 3 * eml_em_i0] = eml_em_dv2[eml_em_i0];
    }
    eml_a0[0] = rtu_a0;
    eml_a0[1] = rtu_a1;
    eml_a0[2] = rtu_a2;
    eml_a0[3] = rtu_a3;
    eml_a0[4] = rtu_a4;
    eml_a0[5] = rtu_a5;
    for(eml_em_i0 = 0; eml_em_i0 < 3; eml_em_i0++) {
      eml_Q[eml_em_i0] = 0.0;
      for(eml_em_i1 = 0; eml_em_i1 < 6; eml_em_i1++) {
        eml_Q[eml_em_i0] += eml_em_dv3[eml_em_i0 + 3 * eml_em_i1] *
          eml_a0[eml_em_i1];
      }
    }
    localB->qa = eml_Q[0];
    rtb_qap = eml_Q[1];
    rtb_qapp = eml_Q[2];
  }
}

/* Output and update for atomic system:
 *   '<S1>/Trajectory design 1'
 *   '<S1>/Trajectory design 2'
 */

void traje_Trajectorydesign1(real_T rtu_A, real_T rtu_B, real_T rtu_t,
 rtB_traje_Trajectorydesign1 *localB)
{

  /* Embedded MATLAB: '<S1>/Trajectory design 1' */
  {
    int32_T eml_em_i0;
    int32_T eml_em_i1;
    real_T eml_y[36];
    real_T eml_em_dv0[6];
    real_T eml_em_dv1[6];
    real_T eml_em_dv2[6];
    real_T eml_A[36];
    static boolean_T eml_em_bv0[6] = { false, false, false, false, false, true };
    static boolean_T eml_em_bv1[6] = { false, false, false, false, true, false };
    static boolean_T eml_em_bv2[6] = { false, false, false, true, false, false };
    int8_T eml_pivot[6];
    real_T eml_temp;
    int32_T eml_k;
    int32_T eml_c;
    int32_T eml_j;
    real_T eml_B[6];
    real_T eml_Ao[6];
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
      for(eml_em_i1 = 0; eml_em_i1 < 6; eml_em_i1++) {
        eml_y[eml_em_i1 + 6 * eml_em_i0] = 0.0;
      }
    }
    eml_em_dv0[0] = pow(rtu_t, 5.0) / 20.0;
    eml_em_dv0[1] = pow(rtu_t, 4.0) / 12.0;
    eml_em_dv0[2] = pow(rtu_t, 3.0) / 6.0;
    eml_em_dv0[3] = pow(rtu_t, 2.0) / 2.0;
    eml_em_dv0[4] = rtu_t;
    eml_em_dv0[5] = 1.0;
    eml_em_dv1[0] = pow(rtu_t, 4.0) / 4.0;
    eml_em_dv1[1] = pow(rtu_t, 3.0) / 3.0;
    eml_em_dv1[2] = pow(rtu_t, 2.0) / 2.0;
    eml_em_dv1[3] = rtu_t;
    eml_em_dv1[4] = 1.0;
    eml_em_dv1[5] = 0.0;
    eml_em_dv2[0] = pow(rtu_t, 3.0);
    eml_em_dv2[1] = pow(rtu_t, 2.0);
    eml_em_dv2[2] = rtu_t;
    eml_em_dv2[3] = 1.0;
    eml_em_dv2[4] = 0.0;
    eml_em_dv2[5] = 0.0;
    for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
      eml_A[6 * eml_em_i0] = eml_em_dv0[eml_em_i0];
      eml_A[1 + 6 * eml_em_i0] = eml_em_dv1[eml_em_i0];
      eml_A[2 + 6 * eml_em_i0] = eml_em_dv2[eml_em_i0];
      eml_A[3 + 6 * eml_em_i0] = (real_T)eml_em_bv0[eml_em_i0];
      eml_A[4 + 6 * eml_em_i0] = (real_T)eml_em_bv1[eml_em_i0];
      eml_A[5 + 6 * eml_em_i0] = (real_T)eml_em_bv2[eml_em_i0];
      eml_pivot[eml_em_i0] = (int8_T)(1 + eml_em_i0);
    }
    for(eml_em_i0 = 0; eml_em_i0 < 5; eml_em_i0++) {
      eml_em_i1 = eml_em_i0 + 1;
      eml_temp = fabs(eml_A[eml_em_i0 + 6 * eml_em_i0]);
      for(eml_k = eml_em_i0 + 2; eml_k <= 6; eml_k++) {
        if(fabs(eml_A[(eml_k - 1) + 6 * eml_em_i0]) > eml_temp) {
          eml_temp = fabs(eml_A[(eml_k - 1) + 6 * eml_em_i0]);
          eml_em_i1 = eml_k;
        }
      }
      if(eml_em_i1 != eml_em_i0 + 1) {
        for(eml_k = 0; eml_k < 6; eml_k++) {
          eml_temp = eml_A[(eml_em_i1 - 1) + 6 * eml_k];
          eml_A[(eml_em_i1 - 1) + 6 * eml_k] = eml_A[eml_em_i0 + 6 * eml_k];
          eml_A[eml_em_i0 + 6 * eml_k] = eml_temp;
        }
        eml_k = (int32_T)eml_pivot[eml_em_i0];
        eml_pivot[eml_em_i0] = eml_pivot[eml_em_i1 - 1];
        eml_pivot[eml_em_i1 - 1] = (int8_T)eml_k;
      }
      if(eml_A[eml_em_i0 + 6 * eml_em_i0] != 0.0) {
        for(eml_k = eml_em_i0 + 2; eml_k <= 6; eml_k++) {
          eml_A[(eml_k - 1) + 6 * eml_em_i0] /= eml_A[eml_em_i0 + 6 * eml_em_i0];
        }
        for(eml_em_i1 = eml_em_i0 + 2; eml_em_i1 <= 6; eml_em_i1++) {
          for(eml_k = eml_em_i0 + 2; eml_k <= 6; eml_k++) {
            eml_A[(eml_k - 1) + 6 * (eml_em_i1 - 1)] -= eml_A[(eml_k - 1) + 6 *
              eml_em_i0] * eml_A[eml_em_i0 + 6 * (eml_em_i1 - 1)];
          }
        }
      }
    }
    eml_k = 1;
    sf_label_3_0_1:;
    if(eml_k <= 6) {
      if((eml_A[(eml_k - 1) + 6 * (eml_k - 1)] == 0.0) ||
       ((boolean_T)rtIsNaN(eml_A[(eml_k - 1) + 6 * (eml_k - 1)]))) {
        for(eml_em_i0 = 0; eml_em_i0 < 36; eml_em_i0++) {
          eml_y[eml_em_i0] = rtInf;
        }
      } else {
        eml_k++;
        goto sf_label_3_0_1;
      }
    } else {
      for(eml_k = 0; eml_k < 6; eml_k++) {
        eml_c = (int32_T)eml_pivot[eml_k];
        eml_y[eml_k + 6 * (eml_c - 1)] = 1.0;
        for(eml_em_i0 = eml_k + 1; eml_em_i0 <= 6; eml_em_i0++) {
          if(eml_y[(eml_em_i0 - 1) + 6 * (eml_c - 1)] != 0.0) {
            for(eml_em_i1 = eml_em_i0 + 1; eml_em_i1 <= 6; eml_em_i1++) {
              eml_y[(eml_em_i1 - 1) + 6 * (eml_c - 1)] -= eml_y[(eml_em_i0 - 1)
                + 6 * (eml_c - 1)] * eml_A[(eml_em_i1 - 1) + 6 * (eml_em_i0 -
                1)];
            }
          }
        }
        for(eml_em_i1 = 6; eml_em_i1 > 0; eml_em_i1 += -1) {
          eml_y[(eml_em_i1 - 1) + 6 * (eml_c - 1)] /= eml_A[(eml_em_i1 - 1) + 6
            * (eml_em_i1 - 1)];
          if(eml_y[(eml_em_i1 - 1) + 6 * (eml_c - 1)] != 0.0) {
            eml_j = eml_em_i1 - 1;
            for(eml_em_i0 = 1; eml_em_i0 <= eml_j; eml_em_i0++) {
              eml_y[(eml_em_i0 - 1) + 6 * (eml_c - 1)] -= eml_y[(eml_em_i1 - 1)
                + 6 * (eml_c - 1)] * eml_A[(eml_em_i0 - 1) + 6 * (eml_em_i1 -
                1)];
            }
          }
        }
      }
    }
    eml_B[0] = rtu_B;
    eml_B[1] = 0.0;
    eml_B[2] = 0.0;
    eml_B[3] = rtu_A;
    eml_B[4] = 0.0;
    eml_B[5] = 0.0;
    for(eml_em_i1 = 0; eml_em_i1 < 6; eml_em_i1++) {
      eml_Ao[eml_em_i1] = 0.0;
      for(eml_em_i0 = 0; eml_em_i0 < 6; eml_em_i0++) {
        eml_Ao[eml_em_i1] += eml_y[eml_em_i1 + 6 * eml_em_i0] * eml_B[eml_em_i0];
      }
    }
    localB->a0 = eml_Ao[0];
    localB->a1 = eml_Ao[1];
    localB->a2 = eml_Ao[2];
    localB->a3 = eml_Ao[3];
    localB->a4 = eml_Ao[4];
    localB->a5 = eml_Ao[5];
  }
}

/* Model output function */

static void trajectory_test_output(int_T tid)
{

  /* local block i/o variables*/
  real_T rtb_Switch;
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator =
    (trajectory_test_DWork.clockTickCounter <
    trajectory_test_P.PulseGenerator_Duty &&
    trajectory_test_DWork.clockTickCounter >= 0) ?
   trajectory_test_P.PulseGenerator_Amp :
    0.0;
  if (trajectory_test_DWork.clockTickCounter >=
   trajectory_test_P.PulseGenerator_Period-1) {
    trajectory_test_DWork.clockTickCounter = 0;
  } else {
    (trajectory_test_DWork.clockTickCounter)++;
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if(rtb_PulseGenerator != 0.0) {
    rtb_Switch = trajectory_test_P.Constant_Value;
  } else {
    rtb_Switch = trajectory_test_P.Constant1_Value;
  }

  if(rtb_Switch > 0.0) {
    if(trajectory_test_DWork.Subsystem_MODE == SUBSYS_DISABLED) {
    }
    trajectory_test_DWork.Subsystem_MODE = SUBSYS_ENABLED;
  } else if(trajectory_test_DWork.Subsystem_MODE == SUBSYS_ENABLED) {

    trajectory_test_DWork.Subsystem_MODE = SUBSYS_DISABLED;
  }
  if(trajectory_test_DWork.Subsystem_MODE == SUBSYS_ENABLED) {

    /* Output and update for enable system: '<Root>/Subsystem' */

    /* Stateflow: '<S1>/Trajectory design 1' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/Constant'
     */
    traje_Trajectorydesign1(trajectory_test_P.Constant1_Value_n,
     trajectory_test_P.Constant2_Value, trajectory_test_P.Constant_Value_j,
     &trajectory_test_B.sf_Trajectorydesign1);

    /* Stateflow: '<S1>/Joint reference singal 1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    tJointreferencesingal1(trajectory_test_B.sf_Trajectorydesign1.a0,
     trajectory_test_B.sf_Trajectorydesign1.a1,
     trajectory_test_B.sf_Trajectorydesign1.a2,
     trajectory_test_B.sf_Trajectorydesign1.a3,
     trajectory_test_B.sf_Trajectorydesign1.a4,
     trajectory_test_B.sf_Trajectorydesign1.a5, 0.0,
     trajectory_test_P.Constant_Value_j,
     &trajectory_test_B.sf_Jointreferencesing);

    /* Stateflow: '<S1>/Trajectory design 2' incorporates:
     *  Constant: '<S1>/Constant3'
     *  Constant: '<S1>/Constant4'
     *  Constant: '<S1>/Constant'
     */
    traje_Trajectorydesign1(trajectory_test_P.Constant3_Value,
     trajectory_test_P.Constant4_Value, trajectory_test_P.Constant_Value_j,
     &trajectory_test_B.sf_Trajectorydesign2);

    /* Stateflow: '<S1>/Joint reference singal 2' incorporates:
     *  Constant: '<S1>/Constant'
     */
    tJointreferencesingal1(trajectory_test_B.sf_Trajectorydesign2.a0,
     trajectory_test_B.sf_Trajectorydesign2.a1,
     trajectory_test_B.sf_Trajectorydesign2.a2,
     trajectory_test_B.sf_Trajectorydesign2.a3,
     trajectory_test_B.sf_Trajectorydesign2.a4,
     trajectory_test_B.sf_Trajectorydesign2.a5, 0.0,
     trajectory_test_P.Constant_Value_j,
     &trajectory_test_B.sf_Jointreferencesi_m);
  }
}

/* Model update function */

static void trajectory_test_update(int_T tid)
{

  /* Update absolute time for base rate */
  if(!(++trajectory_test_M->Timing.clockTick0))
  ++trajectory_test_M->Timing.clockTickH0;
  trajectory_test_M->Timing.t[0] = trajectory_test_M->Timing.clockTick0 *
    trajectory_test_M->Timing.stepSize0 + trajectory_test_M->Timing.clockTickH0
    * trajectory_test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */

void trajectory_test_initialize(boolean_T firstTime)
{
  if (firstTime) {

    /* Registration code */
    /* initialize real-time model */
    (void) memset((char_T *)trajectory_test_M,0,
     sizeof(RT_MODEL_trajectory_test));

    /* Initialize timing info */
    {
      int_T *mdlTsMap = trajectory_test_M->Timing.sampleTimeTaskIDArray;
      mdlTsMap[0] = 0;
      trajectory_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
      trajectory_test_M->Timing.sampleTimes =
        (&trajectory_test_M->Timing.sampleTimesArray[0]);
      trajectory_test_M->Timing.offsetTimes =
        (&trajectory_test_M->Timing.offsetTimesArray[0]);
      /* task periods */
      trajectory_test_M->Timing.sampleTimes[0] = (0.01);

      /* task offsets */
      trajectory_test_M->Timing.offsetTimes[0] = (0.0);
    }

    rtmSetTPtr(trajectory_test_M, &trajectory_test_M->Timing.tArray[0]);

    {
      int_T *mdlSampleHits = trajectory_test_M->Timing.sampleHitArray;
      mdlSampleHits[0] = 1;
      trajectory_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
    }

    rtmSetTFinal(trajectory_test_M, 20.0);
    trajectory_test_M->Timing.stepSize0 = 0.01;

    /* Setup for data logging */
    {
      static RTWLogInfo rt_DataLoggingInfo;

      trajectory_test_M->rtwLogInfo = &rt_DataLoggingInfo;

      rtliSetLogFormat(trajectory_test_M->rtwLogInfo, 0);

      rtliSetLogMaxRows(trajectory_test_M->rtwLogInfo, 1000);

      rtliSetLogDecimation(trajectory_test_M->rtwLogInfo, 1);

      rtliSetLogVarNameModifier(trajectory_test_M->rtwLogInfo, "rt_");

      rtliSetLogT(trajectory_test_M->rtwLogInfo, "tout");

      rtliSetLogX(trajectory_test_M->rtwLogInfo, "");

      rtliSetLogXFinal(trajectory_test_M->rtwLogInfo, "");

      rtliSetSigLog(trajectory_test_M->rtwLogInfo, "");

      rtliSetLogXSignalInfo(trajectory_test_M->rtwLogInfo, NULL);

      rtliSetLogXSignalPtrs(trajectory_test_M->rtwLogInfo, NULL);

      rtliSetLogY(trajectory_test_M->rtwLogInfo, "");

      rtliSetLogYSignalInfo(trajectory_test_M->rtwLogInfo, NULL);

      rtliSetLogYSignalPtrs(trajectory_test_M->rtwLogInfo, NULL);
    }

    trajectory_test_M->solverInfoPtr = (&trajectory_test_M->solverInfo);
    trajectory_test_M->Timing.stepSize = (0.01);
    rtsiSetFixedStepSize(&trajectory_test_M->solverInfo, 0.01);
    rtsiSetSolverMode(&trajectory_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

    /* block I/O */
    trajectory_test_M->ModelData.blockIO = ((void *) &trajectory_test_B);

    {

      int_T i;
      void *pVoidBlockIORegion;

      pVoidBlockIORegion = (void *)(&trajectory_test_B.sf_Trajectorydesign2.a0);
      for (i = 0; i < 6; i++) {
        ((real_T*)pVoidBlockIORegion)[i] = 0.0;
      }

      pVoidBlockIORegion = (void *)(&trajectory_test_B.sf_Trajectorydesign1.a0);
      for (i = 0; i < 6; i++) {
        ((real_T*)pVoidBlockIORegion)[i] = 0.0;
      }

      ((real_T*)&trajectory_test_B.sf_Jointreferencesi_m.qa)[0] = 0.0;

      ((real_T*)&trajectory_test_B.sf_Jointreferencesing.qa)[0] = 0.0;
    }

    /* parameters */
    trajectory_test_M->ModelData.defaultParam = ((real_T *) &trajectory_test_P);

    /* states (dwork) */

    trajectory_test_M->Work.dwork = ((void *) &trajectory_test_DWork);

    (void) memset((char_T *) &trajectory_test_DWork,0,
     sizeof(D_Work_trajectory_test));

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
  }
}

/* Model terminate function */

void trajectory_test_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/

void MdlOutputs(int_T tid) {

  trajectory_test_output(tid);
}

void MdlUpdate(int_T tid) {

  trajectory_test_update(tid);
}

void MdlInitializeSizes(void) {
  trajectory_test_M->Sizes.numContStates = (0); /* Number of continuous states */
  trajectory_test_M->Sizes.numY = (0); /* Number of model outputs */
  trajectory_test_M->Sizes.numU = (0); /* Number of model inputs */
  trajectory_test_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  trajectory_test_M->Sizes.numSampTimes = (1); /* Number of sample times */
  trajectory_test_M->Sizes.numBlocks = (23); /* Number of blocks */
  trajectory_test_M->Sizes.numBlockIO = (14); /* Number of block outputs */
  trajectory_test_M->Sizes.numBlockPrms = (10); /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void) {
}

void MdlInitialize(void) {
}

void MdlStart(void) {

  /* DiscretePulseGenerator Block: '<Root>/Pulse Generator' */
  {
    int_T Ns;

    Ns = 0;

    if (Ns <= 0) {
      trajectory_test_DWork.clockTickCounter = Ns;
    } else {
      trajectory_test_DWork.clockTickCounter = Ns -
        (int_T)(trajectory_test_P.PulseGenerator_Period*floor((real_T)Ns /
        trajectory_test_P.PulseGenerator_Period));
    }
  }

  MdlInitialize();
}

RT_MODEL_trajectory_test *trajectory_test(void) {
  trajectory_test_initialize(1);
  return trajectory_test_M;
}

void MdlTerminate(void) {
  trajectory_test_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/

