/*
 * File: MPC_framework_data.c
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.1466
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Thu May 08 18:43:44 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Thu May 08 18:43:45 2014
 */

#include "MPC_framework.h"
#include "MPC_framework_private.h"

/* Block parameters (auto storage) */
Parameters_MPC_framework MPC_framework_P = {
  5.0 ,                                 /* trajectory_time_Value : '<S47>/trajectory_time'
                                         */
  0.01 ,                                /* DiscreteTimeIntegrator_g : '<S48>/Discrete-Time Integrator'
                                         */
  0.0 ,                                 /* DiscreteTimeIntegrator_I : '<S48>/Discrete-Time Integrator'
                                         */
  1.0 ,                                 /* timebase_Value : '<S48>/time base'
                                         */
  20.0 ,                                /* Constant_Value : '<S76>/Constant'
                                         */
  21.0 ,                                /* Constant_Value_h : '<S77>/Constant'
                                         */
  8.928571333E-006F ,                   /* Gain_Gain : '<S12>/Gain'
                                         */
  6.283185482F ,                        /* Gain4_Gain : '<S12>/Gain4'
                                         */
  8.928571333E-006F ,                   /* Gain1_Gain : '<S12>/Gain1'
                                         */
  6.283185482F ,                        /* Gain5_Gain : '<S12>/Gain5'
                                         */
  0.0F ,                                /* Switch_Threshold : '<Root>/Switch'
                                         */
  360.0F ,                              /* Gain2_Gain : '<S12>/Gain2'
                                         */
  360.0F ,                              /* Gain3_Gain : '<S12>/Gain3'
                                         */
  0.0F ,                                /* invgeo_alpha_1_InitialValu : '<Root>/invgeo_alpha_1'
                                         */
  0.0F ,                                /* invgeo_alpha_2_InitialValu : '<Root>/invgeo_alpha_2'
                                         */
  3.0F ,                                /* Ap1_Value : '<S2>/Ap1'
                                         */
  0.06666667014F ,                      /* Ap2_Value : '<S2>/Ap2'
                                         */
  0.009999999776F ,                     /* T_Value : '<S2>/T'
                                         */
  0.0F ,                                /* UnitDelay_X0 : '<S25>/Unit Delay'
                                         */
  0.200000003F ,                        /* Tc1_Value : '<S2>/Tc1'
                                         */
  0.0F ,                                /* UnitDelay_X0_b : '<S24>/Unit Delay'
                                         */
  2.0F ,                                /* Td1_Value : '<S2>/Td1'
                                         */
  0.5F ,                                /* Saturation_UpperSat : '<S22>/Saturation'
                                         */
  -0.5F ,                               /* Saturation_LowerSat : '<S22>/Saturation'
                                         */
  0.5F ,                                /* Saturation1_UpperSat : '<S22>/Saturation1'
                                         */
  -0.5F ,                               /* Saturation1_LowerSat : '<S22>/Saturation1'
                                         */
  0.0F ,                                /* UnitDelay_X0_a : '<S27>/Unit Delay'
                                         */
  0.200000003F ,                        /* Tc2_Value : '<S2>/Tc2'
                                         */
  0.0F ,                                /* UnitDelay_X0_o : '<S26>/Unit Delay'
                                         */
  0.0F ,                                /* Td2_Value : '<S2>/Td2'
                                         */
  0.5F ,                                /* Saturation_UpperSat_i : '<S23>/Saturation'
                                         */
  -0.5F ,                               /* Saturation_LowerSat_b : '<S23>/Saturation'
                                         */
  0.5F ,                                /* Saturation1_UpperSat_i : '<S23>/Saturation1'
                                         */
  -0.5F ,                               /* Saturation1_LowerSat_j : '<S23>/Saturation1'
                                         */
  6554.0F ,                             /* Gain_Gain_b : '<S2>/Gain'
                                         */
  -1.0F ,                               /* Gain2_Gain_p : '<S2>/Gain2'
                                         */
  6554.0F ,                             /* Gain1_Gain_k : '<S2>/Gain1'
                                         */
  32768.0F ,                            /* c1_Value : '<S2>/c1'
                                         */
  32768.0F ,                            /* c2_Value : '<S2>/c2'
                                         */
  42598.0F ,                            /* Saturation1_UpperSat_a : '<S3>/Saturation1'
                                         */
  22937.0F ,                            /* Saturation1_LowerSat_m : '<S3>/Saturation1'
                                         */
  42598.0F ,                            /* Saturation2_UpperSat : '<S3>/Saturation2'
                                         */
  22937.0F ,                            /* Saturation2_LowerSat : '<S3>/Saturation2'
                                         */
  600.0F ,                              /* a1_Value : '<S6>/a1'
                                         */
  400.0F ,                              /* a2_Value : '<S6>/a2'
                                         */
  0.0F ,                                /* DelayInput1_X0 : '<S43>/Delay Input1'
                                         */
  0.0F ,                                /* DelayInput1_X0_b : '<S44>/Delay Input1'
                                         */
  500.0F ,                              /* SFunction_p8 : '<Root>/State Machine'
                                         */
  5.0F ,                                /* SFunction_p9 : '<Root>/State Machine'
                                         */
  8388608 ,                             /* Constant_Value_g : '<S12>/Constant'
                                         */
  -1 ,                                  /* Gain12_Gain : '<S12>/Gain12'
                                         */
  32768U ,                              /* Constant_Value_i : '<S3>/Constant'
                                         */
  42598U ,                              /* Saturation_UpperSat_n : '<S3>/Saturation'
                                         */
  22937U ,                              /* Saturation_LowerSat_i : '<S3>/Saturation'
                                         */
  31457U ,                              /* SFunction_p3 : '<Root>/State Machine'
                                         */
  34078U ,                              /* SFunction_p4 : '<Root>/State Machine'
                                         */
  34078U ,                              /* SFunction_p5 : '<Root>/State Machine'
                                         */
  31457U ,                              /* SFunction_p6 : '<Root>/State Machine'
                                         */
  32768U ,                              /* SFunction_p7 : '<Root>/State Machine'
                                         */
  0U ,                                  /* UnitDelay_X0_ov : '<S47>/Unit Delay'
                                         */
  0U ,                                  /* UnitDelay1_X0 : '<S47>/Unit Delay1'
                                         */
  0U ,                                  /* Switch1_Threshold : '<Root>/Switch1'
                                         */
  0U ,                                  /* DelayInput1_X0_f : '<S86>/Delay Input1'
                                         */
  0U ,                                  /* DelayInput1_X0_k : '<S112>/Delay Input1'
                                         */
  255U ,                                /* invgeo_error_InitialValue : '<Root>/invgeo_error'
                                         */
  1U ,                                  /* SFunction_p1 : '<Root>/State Machine'
                                         */
  2U ,                                  /* SFunction_p2 : '<Root>/State Machine'
                                         */
  1U ,                                  /* Constant_Value_f : '<S18>/Constant'
                                         */
  1U                                    /* Constant_Value_n : '<S19>/Constant'
                                         */
};

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
