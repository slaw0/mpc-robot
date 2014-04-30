/* Include files */
#include "trajectory_test_sfun.h"
#include "c1_trajectory_test.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "trajectory_test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_trajectory_testInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_trajectory_test(void);
static void initialize_params_c1_trajectory_test(void);
static void enable_c1_trajectory_test(void);
static void disable_c1_trajectory_test(void);
static void finalize_c1_trajectory_test(void);
static void sf_c1_trajectory_test(void);
static real_T c1_mpower(real_T c1_a);
static real_T c1_b_mpower(real_T c1_a);
static real_T c1_c_mpower(real_T c1_a);
static real_T *c1_a0(void);
static real_T *c1_a1(void);
static real_T *c1_a2(void);
static real_T *c1_a3(void);
static real_T *c1_a4(void);
static real_T *c1_a5(void);
static real_T *c1_t_sim(void);
static real_T *c1_qa(void);
static real_T *c1_qap(void);
static real_T *c1_qapp(void);
static real_T *c1_t_end(void);
static real_T *c1_finished(void);
static void init_dsm_address_info(void);
static void sf_save_state_c1_trajectory_test(FILE *c1_file);
static void sf_load_state_c1_trajectory_test(FILE *c1_file);

/* Function Definitions */
static void initialize_c1_trajectory_test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_is_active_c1_trajectory_test = 0U;
}

static void initialize_params_c1_trajectory_test(void)
{
}

static void enable_c1_trajectory_test(void)
{
}

static void disable_c1_trajectory_test(void)
{
}

static void finalize_c1_trajectory_test(void)
{
}

static void sf_c1_trajectory_test(void)
{
  uint8_T c1_previousEvent;
  real_T c1_b_a0;
  real_T c1_b_a1;
  real_T c1_b_a2;
  real_T c1_b_a3;
  real_T c1_b_a4;
  real_T c1_b_a5;
  real_T c1_b_t_sim;
  real_T c1_b_t_end;
  real_T c1_Q[3];
  real_T c1_T[6][3];
  real_T c1_b_finished;
  real_T c1_b_qapp;
  real_T c1_b_qap;
  real_T c1_b_qa;
  real_T c1_a;
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_x;
  real_T c1_xk;
  real_T c1_ak;
  real_T c1_b_x;
  real_T c1_b_xk;
  real_T c1_bk;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_b_y;
  real_T c1_c;
  real_T c1_A;
  real_T c1_B;
  real_T c1_d_x;
  real_T c1_c_y;
  real_T c1_z;
  real_T c1_d_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_b_z;
  real_T c1_f_y;
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_f_x;
  real_T c1_g_y;
  real_T c1_c_z;
  real_T c1_h_y;
  real_T c1_d_A;
  real_T c1_d_B;
  real_T c1_g_x;
  real_T c1_i_y;
  real_T c1_d_z;
  real_T c1_j_y;
  real_T c1_e_A;
  real_T c1_e_B;
  real_T c1_h_x;
  real_T c1_k_y;
  real_T c1_e_z;
  real_T c1_l_y;
  real_T c1_f_A;
  real_T c1_f_B;
  real_T c1_i_x;
  real_T c1_m_y;
  real_T c1_f_z;
  real_T c1_n_y;
  real_T c1_g_A;
  real_T c1_g_B;
  real_T c1_j_x;
  real_T c1_o_y;
  real_T c1_g_z;
  real_T c1_p_y;
  real_T c1_q_y[6][1];
  real_T c1_r_y[6][1];
  real_T c1_em_dv0[6][1];
  int32_T c1_em_i0;
  int32_T c1_em_i1;
  int32_T c1_em_i2;
  real_T c1_c_a0[6];
  int32_T c1_em_i3;
  int32_T c1_em_i4;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c1_a0(), 8U);
  _SFD_DATA_RANGE_CHECK(*c1_a1(), 7U);
  _SFD_DATA_RANGE_CHECK(*c1_a2(), 3U);
  _SFD_DATA_RANGE_CHECK(*c1_a3(), 11U);
  _SFD_DATA_RANGE_CHECK(*c1_a4(), 9U);
  _SFD_DATA_RANGE_CHECK(*c1_a5(), 1U);
  _SFD_DATA_RANGE_CHECK(*c1_t_sim(), 5U);
  _SFD_DATA_RANGE_CHECK(*c1_qa(), 10U);
  _SFD_DATA_RANGE_CHECK(*c1_qap(), 4U);
  _SFD_DATA_RANGE_CHECK(*c1_qapp(), 0U);
  _SFD_DATA_RANGE_CHECK(*c1_t_end(), 6U);
  _SFD_DATA_RANGE_CHECK(*c1_finished(), 2U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_b_a0 = *c1_a0();
  c1_b_a1 = *c1_a1();
  c1_b_a2 = *c1_a2();
  c1_b_a3 = *c1_a3();
  c1_b_a4 = *c1_a4();
  c1_b_a5 = *c1_a5();
  c1_b_t_sim = *c1_t_sim();
  c1_b_t_end = *c1_t_end();
  sf_debug_push_symbol_scope(14U, 0U);
  sf_debug_symbol_scope_add_symbol("Q", 0, 1U, 3U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c1_Q, 0);
  sf_debug_symbol_scope_add_symbol("T", 0, 2U, 3U, 6U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c1_T, 0);
  sf_debug_symbol_scope_add_symbol("finished", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c1_b_finished, 0);
  sf_debug_symbol_scope_add_symbol("qapp", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c1_b_qapp, 0);
  sf_debug_symbol_scope_add_symbol("qap", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_qap, 0);
  sf_debug_symbol_scope_add_symbol("qa", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_qa, 0);
  sf_debug_symbol_scope_add_symbol("t_end", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c1_b_t_end, 0);
  sf_debug_symbol_scope_add_symbol("t_sim", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c1_b_t_sim, 0);
  sf_debug_symbol_scope_add_symbol("a5", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_a5, 0);
  sf_debug_symbol_scope_add_symbol("a4", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_a4, 0);
  sf_debug_symbol_scope_add_symbol("a3", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_a3, 0);
  sf_debug_symbol_scope_add_symbol("a2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_a2, 0);
  sf_debug_symbol_scope_add_symbol("a1", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_a1, 0);
  sf_debug_symbol_scope_add_symbol("a0", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c1_b_a0, 0);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  if(CV_EML_IF(0, 0, c1_b_t_sim >= c1_b_t_end)) {
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
    c1_b_t_sim = c1_b_t_end;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
    c1_b_finished = 1.0;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
    c1_b_finished = 0.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  c1_a = c1_b_t_sim;
  c1_b_a = c1_a;
  c1_b = 5.0;
  c1_k = 1.0;
  c1_b_k = c1_k;
  c1_x = c1_b_a;
  c1_xk = c1_x;
  c1_ak = c1_xk;
  c1_b_x = c1_b;
  c1_b_xk = c1_b_x;
  c1_bk = c1_b_xk;
  if(c1_ak < 0.0) {
    c1_c_x = c1_bk;
    c1_y = floor(c1_c_x);
    if(c1_y != c1_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c1_b_k), 1,
   1, 1);
  c1_b_y = pow(c1_ak, c1_bk);
  c1_c = c1_b_y;
  c1_A = c1_c;
  c1_B = 20.0;
  c1_d_x = c1_A;
  c1_c_y = c1_B;
  c1_z = c1_d_x / c1_c_y;
  c1_d_y = c1_z;
  c1_b_A = c1_mpower(c1_b_t_sim);
  c1_b_B = 12.0;
  c1_e_x = c1_b_A;
  c1_e_y = c1_b_B;
  c1_b_z = c1_e_x / c1_e_y;
  c1_f_y = c1_b_z;
  c1_c_A = c1_b_mpower(c1_b_t_sim);
  c1_c_B = 6.0;
  c1_f_x = c1_c_A;
  c1_g_y = c1_c_B;
  c1_c_z = c1_f_x / c1_g_y;
  c1_h_y = c1_c_z;
  c1_d_A = c1_c_mpower(c1_b_t_sim);
  c1_d_B = 2.0;
  c1_g_x = c1_d_A;
  c1_i_y = c1_d_B;
  c1_d_z = c1_g_x / c1_i_y;
  c1_j_y = c1_d_z;
  c1_e_A = c1_mpower(c1_b_t_sim);
  c1_e_B = 4.0;
  c1_h_x = c1_e_A;
  c1_k_y = c1_e_B;
  c1_e_z = c1_h_x / c1_k_y;
  c1_l_y = c1_e_z;
  c1_f_A = c1_b_mpower(c1_b_t_sim);
  c1_f_B = 3.0;
  c1_i_x = c1_f_A;
  c1_m_y = c1_f_B;
  c1_f_z = c1_i_x / c1_m_y;
  c1_n_y = c1_f_z;
  c1_g_A = c1_c_mpower(c1_b_t_sim);
  c1_g_B = 2.0;
  c1_j_x = c1_g_A;
  c1_o_y = c1_g_B;
  c1_g_z = c1_j_x / c1_o_y;
  c1_p_y = c1_g_z;
  c1_q_y[0][0] = c1_d_y;
  c1_q_y[1][0] = c1_f_y;
  c1_q_y[2][0] = c1_h_y;
  c1_q_y[3][0] = c1_j_y;
  c1_q_y[4][0] = c1_b_t_sim;
  c1_q_y[5][0] = 1.0;
  c1_r_y[0][0] = c1_l_y;
  c1_r_y[1][0] = c1_n_y;
  c1_r_y[2][0] = c1_p_y;
  c1_r_y[3][0] = c1_b_t_sim;
  c1_r_y[4][0] = 1.0;
  c1_r_y[5][0] = 0.0;
  c1_em_dv0[0][0] = c1_b_mpower(c1_b_t_sim);
  c1_em_dv0[1][0] = c1_c_mpower(c1_b_t_sim);
  c1_em_dv0[2][0] = c1_b_t_sim;
  c1_em_dv0[3][0] = 1.0;
  c1_em_dv0[4][0] = 0.0;
  c1_em_dv0[5][0] = 0.0;
  for(c1_em_i0 = 0; c1_em_i0 < 6; c1_em_i0 = c1_em_i0 + 1) {
    c1_T[c1_em_i0][0] = c1_q_y[c1_em_i0][0];
  }
  for(c1_em_i1 = 0; c1_em_i1 < 6; c1_em_i1 = c1_em_i1 + 1) {
    c1_T[c1_em_i1][1] = c1_r_y[c1_em_i1][0];
  }
  for(c1_em_i2 = 0; c1_em_i2 < 6; c1_em_i2 = c1_em_i2 + 1) {
    c1_T[c1_em_i2][2] = c1_em_dv0[c1_em_i2][0];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
  c1_c_a0[0] = c1_b_a0;
  c1_c_a0[1] = c1_b_a1;
  c1_c_a0[2] = c1_b_a2;
  c1_c_a0[3] = c1_b_a3;
  c1_c_a0[4] = c1_b_a4;
  c1_c_a0[5] = c1_b_a5;
  for(c1_em_i3 = 0; c1_em_i3 < 3; c1_em_i3 = c1_em_i3 + 1) {
    c1_Q[c1_em_i3] = 0.0;
    for(c1_em_i4 = 0; c1_em_i4 < 6; c1_em_i4 = c1_em_i4 + 1) {
      c1_Q[c1_em_i3] = c1_Q[c1_em_i3] + c1_T[c1_em_i4][c1_em_i3] *
        c1_c_a0[c1_em_i4];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
  c1_b_qa = c1_Q[0];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,16);
  c1_b_qap = c1_Q[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
  c1_b_qapp = c1_Q[2];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-17);
  sf_debug_pop_symbol_scope();
  *c1_qa() = c1_b_qa;
  *c1_qap() = c1_b_qap;
  *c1_qapp() = c1_b_qapp;
  *c1_finished() = c1_b_finished;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_trajectory_testMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static real_T c1_mpower(real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_x;
  real_T c1_xk;
  real_T c1_ak;
  real_T c1_b_x;
  real_T c1_b_xk;
  real_T c1_bk;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_b_y;
  c1_b_a = c1_a;
  c1_b = 4.0;
  c1_k = 1.0;
  c1_b_k = c1_k;
  c1_x = c1_b_a;
  c1_xk = c1_x;
  c1_ak = c1_xk;
  c1_b_x = c1_b;
  c1_b_xk = c1_b_x;
  c1_bk = c1_b_xk;
  if(c1_ak < 0.0) {
    c1_c_x = c1_bk;
    c1_y = floor(c1_c_x);
    if(c1_y != c1_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c1_b_k), 1,
   1, 1);
  c1_b_y = pow(c1_ak, c1_bk);
  return c1_b_y;
}

static real_T c1_b_mpower(real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_x;
  real_T c1_xk;
  real_T c1_ak;
  real_T c1_b_x;
  real_T c1_b_xk;
  real_T c1_bk;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_b_y;
  c1_b_a = c1_a;
  c1_b = 3.0;
  c1_k = 1.0;
  c1_b_k = c1_k;
  c1_x = c1_b_a;
  c1_xk = c1_x;
  c1_ak = c1_xk;
  c1_b_x = c1_b;
  c1_b_xk = c1_b_x;
  c1_bk = c1_b_xk;
  if(c1_ak < 0.0) {
    c1_c_x = c1_bk;
    c1_y = floor(c1_c_x);
    if(c1_y != c1_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c1_b_k), 1,
   1, 1);
  c1_b_y = pow(c1_ak, c1_bk);
  return c1_b_y;
}

static real_T c1_c_mpower(real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_k;
  real_T c1_b_k;
  real_T c1_x;
  real_T c1_xk;
  real_T c1_ak;
  real_T c1_b_x;
  real_T c1_b_xk;
  real_T c1_bk;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_b_y;
  c1_b_a = c1_a;
  c1_b = 2.0;
  c1_k = 1.0;
  c1_b_k = c1_k;
  c1_x = c1_b_a;
  c1_xk = c1_x;
  c1_ak = c1_xk;
  c1_b_x = c1_b;
  c1_b_xk = c1_b_x;
  c1_bk = c1_b_xk;
  if(c1_ak < 0.0) {
    c1_c_x = c1_bk;
    c1_y = floor(c1_c_x);
    if(c1_y != c1_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c1_b_k), 1,
   1, 1);
  c1_b_y = pow(c1_ak, c1_bk);
  return c1_b_y;
}

static real_T *c1_a0(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real_T *c1_a1(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real_T *c1_a2(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static real_T *c1_a3(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
}

static real_T *c1_a4(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
}

static real_T *c1_a5(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
}

static real_T *c1_t_sim(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
}

static real_T *c1_qa(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real_T *c1_qap(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static real_T *c1_qapp(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static real_T *c1_t_end(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 7);
}

static real_T *c1_finished(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c1_trajectory_test(FILE *c1_file)
{
  fwrite(&chartInstance.c1_is_active_c1_trajectory_test, 1,
   sizeof(chartInstance.c1_is_active_c1_trajectory_test), c1_file);
}

static void sf_load_state_c1_trajectory_test(FILE *c1_file)
{
  fread(&chartInstance.c1_is_active_c1_trajectory_test, 1,
   sizeof(chartInstance.c1_is_active_c1_trajectory_test), c1_file);
}

/* SFunction Glue Code */
void sf_c1_trajectory_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(664972447U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(497676082U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3170834504U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(822000949U);
}

mxArray *sf_c1_trajectory_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(110420898U);
    pr[1] = (double)(232629384U);
    pr[2] = (double)(2085574770U);
    pr[3] = (double)(931828140U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }
    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }
    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }
    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }
    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S)
{
  if(ssIsFirstInitCond(S)) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_trajectory_testMachineNumber_,
         1,
         1,
         1,
         12,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting(_trajectory_testMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_trajectory_testMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a0",0);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a1",0);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a2",0);
          _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a3",0);
          _SFD_SET_DATA_PROPS(9,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a4",0);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a5",0);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t_sim",0);
          _SFD_SET_DATA_PROPS(10,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"qa",0);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"qap",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"qapp",0);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t_end",0);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"finished",0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,462);
        _SFD_CV_INIT_EML_IF(0,0,170,187,226,252);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(8U, c1_a0());
        _SFD_SET_DATA_VALUE_PTR(7U, c1_a1());
        _SFD_SET_DATA_VALUE_PTR(3U, c1_a2());
        _SFD_SET_DATA_VALUE_PTR(11U, c1_a3());
        _SFD_SET_DATA_VALUE_PTR(9U, c1_a4());
        _SFD_SET_DATA_VALUE_PTR(1U, c1_a5());
        _SFD_SET_DATA_VALUE_PTR(5U, c1_t_sim());
        _SFD_SET_DATA_VALUE_PTR(10U, c1_qa());
        _SFD_SET_DATA_VALUE_PTR(4U, c1_qap());
        _SFD_SET_DATA_VALUE_PTR(0U, c1_qapp());
        _SFD_SET_DATA_VALUE_PTR(6U, c1_t_end());
        _SFD_SET_DATA_VALUE_PTR(2U, c1_finished());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_trajectory_testMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c1_trajectory_test(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c1_trajectory_test();
  initialize_c1_trajectory_test();
}

static void sf_opaque_enable_c1_trajectory_test(void *chartInstanceVar)
{
  enable_c1_trajectory_test();
}

static void sf_opaque_disable_c1_trajectory_test(void *chartInstanceVar)
{
  disable_c1_trajectory_test();
}

static void sf_opaque_gateway_c1_trajectory_test(void *chartInstanceVar)
{
  sf_c1_trajectory_test();
}

static void sf_opaque_terminate_c1_trajectory_test(void *chartInstanceVar)
{
  finalize_c1_trajectory_test();
}

static void mdlProcessParameters_c1_trajectory_test(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c1_trajectory_test();
}

static void mdlSetWorkWidths_c1_trajectory_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("trajectory_test",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("trajectory_test",1,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"trajectory_test",1,8);
      sf_mark_chart_reusable_outputs(S,"trajectory_test",1,4);
    }
    if (!sf_is_chart_instance_optimized_out("trajectory_test",1)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("trajectory_test",1);
      dtId = ssRegisterDataType(S, chartInstanceTypedefName);
      if (dtId == INVALID_DTYPE_ID ) return;
      /* Register the size of the udt */
      if (!ssSetDataTypeSize(S, dtId, 8)) return;
      if(!ssSetNumDWork(S,1)) return;
      ssSetDWorkDataType(S, 0, dtId);
      ssSetDWorkWidth(S, 0, 1);
      ssSetDWorkName(S, 0, "ChartInstance"); /*optional name, less than 16 chars*/
      sf_set_rtw_identifier(S);
    }
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1099381907U));
  ssSetChecksum1(S,(1683811193U));
  ssSetChecksum2(S,(664397944U));
  ssSetChecksum3(S,(2382707694U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_trajectory_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "trajectory_test", 1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void sf_save_debug_c1_trajectory_test(SFc1_trajectory_testInstanceStruct*
 chartInstance, FILE* file)
{
  int machineNumber = _trajectory_testMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = sf_debug_get_state_vectors_data_size(machineNumber,
   chartNumber, instanceNumber);
  unsigned char* buffer = (unsigned char*) malloc(bufferSize);
  unsigned int chartActive = sf_debug_get_chart_active(machineNumber,
   chartNumber, instanceNumber);
  fwrite(&chartActive, sizeof(chartActive),1,file);
  sf_debug_get_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  fwrite(&bufferSize, sizeof(bufferSize), 1, file); /* Write number of bytes */
  fwrite(buffer, 1, bufferSize,file);   /* Write buffer */
  free(buffer);
}
static void sf_load_debug_c1_trajectory_test(SFc1_trajectory_testInstanceStruct*
 chartInstance,FILE* file)
{
  int machineNumber = _trajectory_testMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = 0;
  unsigned char* buffer = NULL;
  unsigned int chartActive = 0;
  fread(&chartActive, sizeof(chartActive),1,file);
  sf_debug_set_chart_active(machineNumber, chartNumber, instanceNumber,
   chartActive);
  fread(&bufferSize, sizeof(bufferSize), 1, file);
  buffer = (unsigned char*) malloc(bufferSize);
  fread(buffer, 1, bufferSize, file);
  sf_debug_set_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  free(buffer);
}
static void sf_c1_trajectory_test_sim_ctx_io(SimStruct* S, const char io, FILE*
 file)
{
  if(io == 'r') {
    sf_load_state_c1_trajectory_test(file);
    sf_load_debug_c1_trajectory_test(&chartInstance, file);
  } else {
    sf_save_state_c1_trajectory_test(file);
    sf_save_debug_c1_trajectory_test(&chartInstance, file);
  }
}
static void mdlStart_c1_trajectory_test(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_trajectory_test;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_trajectory_test;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c1_trajectory_test;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_trajectory_test;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_trajectory_test;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_trajectory_test;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_trajectory_test;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_trajectory_test;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c1_trajectory_test_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c1_trajectory_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_trajectory_test(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_trajectory_test(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_trajectory_test(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c1_trajectory_test_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

