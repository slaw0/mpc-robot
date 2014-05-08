/*
 * File: MPC_framework_data.c
 *
 * Real-Time Workshop code generated for Simulink model MPC_framework.
 *
 * Model version                        : 1.1102
 * Real-Time Workshop file version      : 6.4  (R2006a)  03-Feb-2006
 * Real-Time Workshop file generated on : Tue May 06 12:21:42 2014
 * TLC version                          : 6.4 (Jan 31 2006)
 * C source code generated on           : Tue May 06 12:21:42 2014
 */

#include "MPC_framework.h"
#include "MPC_framework_private.h"

/* Block parameters (auto storage) */
Parameters_MPC_framework MPC_framework_P = {
  5.0 ,                                 /* trajectory_time_Value : '<S47>/trajectory_time'
                                         */
  0.0 ,                                 /* Hidden_Mem_for_Latch_at_in : 'synthesized block'
                                         */
  0.0 ,                                 /* Hidden_Mem_for_Latch_at_ij : 'synthesized block'
                                         */
  8.388608E+006 ,                       /* Constant_Value : '<S12>/Constant'
                                         */
  57674.0 ,                             /* Constant1_Value : '<S12>/Constant1'
                                         */
  3.1415926535897931E+000 ,             /* Gain_Gain : '<S12>/Gain'
                                         */
  3.1415926535897931E+000 ,             /* Gain1_Gain : '<S12>/Gain1'
                                         */
  0.0 ,                                 /* invgeo_alpha_1_InitialValu : '<Root>/invgeo_alpha_1'
                                         */
  0.0 ,                                 /* invgeo_alpha_2_InitialValu : '<Root>/invgeo_alpha_2'
                                         */
  0.125 ,                               /* Ap1_Value : '<S2>/Ap1'
                                         */
  6.6666666666666666E-002 ,             /* Ap2_Value : '<S2>/Ap2'
                                         */
  0.01 ,                                /* T_Value : '<S2>/T'
                                         */
  0.0 ,                                 /* UnitDelay_X0 : '<S25>/Unit Delay'
                                         */
  0.2 ,                                 /* Tc1_Value : '<S2>/Tc1'
                                         */
  0.0 ,                                 /* UnitDelay_X0_b : '<S24>/Unit Delay'
                                         */
  0.1 ,                                 /* Td1_Value : '<S2>/Td1'
                                         */
  0.5 ,                                 /* Saturation_UpperSat : '<S22>/Saturation'
                                         */
  -0.5 ,                                /* Saturation_LowerSat : '<S22>/Saturation'
                                         */
  0.5 ,                                 /* Saturation1_UpperSat : '<S22>/Saturation1'
                                         */
  -0.5 ,                                /* Saturation1_LowerSat : '<S22>/Saturation1'
                                         */
  0.0 ,                                 /* UnitDelay_X0_a : '<S27>/Unit Delay'
                                         */
  0.2 ,                                 /* Tc2_Value : '<S2>/Tc2'
                                         */
  0.0 ,                                 /* UnitDelay_X0_o : '<S26>/Unit Delay'
                                         */
  0.1 ,                                 /* Td2_Value : '<S2>/Td2'
                                         */
  0.5 ,                                 /* Saturation_UpperSat_i : '<S23>/Saturation'
                                         */
  -0.5 ,                                /* Saturation_LowerSat_b : '<S23>/Saturation'
                                         */
  0.5 ,                                 /* Saturation1_UpperSat_i : '<S23>/Saturation1'
                                         */
  -0.5 ,                                /* Saturation1_LowerSat_j : '<S23>/Saturation1'
                                         */
  1.0 ,                                 /* c1_Value : '<S2>/c1'
                                         */
  32768.0 ,                             /* Gain_Gain_b : '<S2>/Gain'
                                         */
  -1.0 ,                                /* Gain2_Gain : '<S2>/Gain2'
                                         */
  1.0 ,                                 /* c2_Value : '<S2>/c2'
                                         */
  32768.0 ,                             /* Gain1_Gain_k : '<S2>/Gain1'
                                         */
  600.0 ,                               /* a1_Value : '<S6>/a1'
                                         */
  400.0 ,                               /* a2_Value : '<S6>/a2'
                                         */
  0.0 ,                                 /* DelayInput1_X0 : '<S43>/Delay Input1'
                                         */
  0.0 ,                                 /* DelayInput1_X0_b : '<S44>/Delay Input1'
                                         */
  500.0 ,                               /* SFunction_p8 : '<Root>/State Machine'
                                         */
  5.0 ,                                 /* SFunction_p9 : '<Root>/State Machine'
                                         */
  0.01 ,                                /* DiscreteTimeIntegrator_g : '<S48>/Discrete-Time Integrator'
                                         */
  0.0 ,                                 /* DiscreteTimeIntegrator_I : '<S48>/Discrete-Time Integrator'
                                         */
  1.0 ,                                 /* timebase_Value : '<S48>/time base'
                                         */
  20.0 ,                                /* Constant_Value_g : '<S76>/Constant'
                                         */
  21.0 ,                                /* Constant_Value_h : '<S77>/Constant'
                                         */
  32768U ,                              /* Constant_Value_i : '<S3>/Constant'
                                         */
  32112U ,                              /* SFunction_p3 : '<Root>/State Machine'
                                         */
  33423U ,                              /* SFunction_p4 : '<Root>/State Machine'
                                         */
  33423U ,                              /* SFunction_p5 : '<Root>/State Machine'
                                         */
  32112U ,                              /* SFunction_p6 : '<Root>/State Machine'
                                         */
  32768U ,                              /* SFunction_p7 : '<Root>/State Machine'
                                         */
  0U ,                                  /* Switch1_Threshold : '<Root>/Switch1'
                                         */
  0U ,                                  /* Switch_Threshold : '<Root>/Switch'
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
