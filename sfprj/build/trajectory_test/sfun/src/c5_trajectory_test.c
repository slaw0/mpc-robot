/* Include files */
#include "trajectory_test_sfun.h"
#include "c5_trajectory_test.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "trajectory_test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc5_trajectory_testInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c5_trajectory_test(void);
static void initialize_params_c5_trajectory_test(void);
static void enable_c5_trajectory_test(void);
static void disable_c5_trajectory_test(void);
static void finalize_c5_trajectory_test(void);
static void sf_c5_trajectory_test(void);
static real_T c5_mpower(real_T c5_a);
static real_T c5_b_mpower(real_T c5_a);
static real_T c5_c_mpower(real_T c5_a);
static real_T *c5_a0(void);
static real_T *c5_a1(void);
static real_T *c5_a2(void);
static real_T *c5_a3(void);
static real_T *c5_a4(void);
static real_T *c5_a5(void);
static real_T *c5_t_sim(void);
static real_T *c5_qa(void);
static real_T *c5_qap(void);
static real_T *c5_qapp(void);
static real_T *c5_t_end(void);
static void init_dsm_address_info(void);
static void sf_save_state_c5_trajectory_test(FILE *c5_file);
static void sf_load_state_c5_trajectory_test(FILE *c5_file);

/* Function Definitions */
static void initialize_c5_trajectory_test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c5_is_active_c5_trajectory_test = 0U;
}

static void initialize_params_c5_trajectory_test(void)
{
}

static void enable_c5_trajectory_test(void)
{
}

static void disable_c5_trajectory_test(void)
{
}

static void finalize_c5_trajectory_test(void)
{
}

static void sf_c5_trajectory_test(void)
{
  uint8_T c5_previousEvent;
  real_T c5_b_a0;
  real_T c5_b_a1;
  real_T c5_b_a2;
  real_T c5_b_a3;
  real_T c5_b_a4;
  real_T c5_b_a5;
  real_T c5_b_t_sim;
  real_T c5_b_t_end;
  real_T c5_Q[3];
  real_T c5_T[6][3];
  real_T c5_b_qapp;
  real_T c5_b_qap;
  real_T c5_b_qa;
  real_T c5_a;
  real_T c5_b_a;
  real_T c5_b;
  real_T c5_k;
  real_T c5_b_k;
  real_T c5_x;
  real_T c5_xk;
  real_T c5_ak;
  real_T c5_b_x;
  real_T c5_b_xk;
  real_T c5_bk;
  real_T c5_c_x;
  real_T c5_y;
  real_T c5_b_y;
  real_T c5_c;
  real_T c5_A;
  real_T c5_B;
  real_T c5_d_x;
  real_T c5_c_y;
  real_T c5_z;
  real_T c5_d_y;
  real_T c5_b_A;
  real_T c5_b_B;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_b_z;
  real_T c5_f_y;
  real_T c5_c_A;
  real_T c5_c_B;
  real_T c5_f_x;
  real_T c5_g_y;
  real_T c5_c_z;
  real_T c5_h_y;
  real_T c5_d_A;
  real_T c5_d_B;
  real_T c5_g_x;
  real_T c5_i_y;
  real_T c5_d_z;
  real_T c5_j_y;
  real_T c5_e_A;
  real_T c5_e_B;
  real_T c5_h_x;
  real_T c5_k_y;
  real_T c5_e_z;
  real_T c5_l_y;
  real_T c5_f_A;
  real_T c5_f_B;
  real_T c5_i_x;
  real_T c5_m_y;
  real_T c5_f_z;
  real_T c5_n_y;
  real_T c5_g_A;
  real_T c5_g_B;
  real_T c5_j_x;
  real_T c5_o_y;
  real_T c5_g_z;
  real_T c5_p_y;
  real_T c5_q_y[6][1];
  real_T c5_r_y[6][1];
  real_T c5_em_dv0[6][1];
  int32_T c5_em_i0;
  int32_T c5_em_i1;
  int32_T c5_em_i2;
  real_T c5_c_a0[6];
  int32_T c5_em_i3;
  int32_T c5_em_i4;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c5_a0(), 7U);
  _SFD_DATA_RANGE_CHECK(*c5_a1(), 6U);
  _SFD_DATA_RANGE_CHECK(*c5_a2(), 2U);
  _SFD_DATA_RANGE_CHECK(*c5_a3(), 10U);
  _SFD_DATA_RANGE_CHECK(*c5_a4(), 8U);
  _SFD_DATA_RANGE_CHECK(*c5_a5(), 1U);
  _SFD_DATA_RANGE_CHECK(*c5_t_sim(), 4U);
  _SFD_DATA_RANGE_CHECK(*c5_qa(), 9U);
  _SFD_DATA_RANGE_CHECK(*c5_qap(), 3U);
  _SFD_DATA_RANGE_CHECK(*c5_qapp(), 0U);
  _SFD_DATA_RANGE_CHECK(*c5_t_end(), 5U);
  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  c5_b_a0 = *c5_a0();
  c5_b_a1 = *c5_a1();
  c5_b_a2 = *c5_a2();
  c5_b_a3 = *c5_a3();
  c5_b_a4 = *c5_a4();
  c5_b_a5 = *c5_a5();
  c5_b_t_sim = *c5_t_sim();
  c5_b_t_end = *c5_t_end();
  sf_debug_push_symbol_scope(13U, 0U);
  sf_debug_symbol_scope_add_symbol("Q", 0, 1U, 3U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c5_Q, 0);
  sf_debug_symbol_scope_add_symbol("T", 0, 2U, 3U, 6U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c5_T, 0);
  sf_debug_symbol_scope_add_symbol("qapp", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c5_b_qapp, 0);
  sf_debug_symbol_scope_add_symbol("qap", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_qap, 0);
  sf_debug_symbol_scope_add_symbol("qa", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_qa, 0);
  sf_debug_symbol_scope_add_symbol("t_end", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c5_b_t_end, 0);
  sf_debug_symbol_scope_add_symbol("t_sim", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c5_b_t_sim, 0);
  sf_debug_symbol_scope_add_symbol("a5", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_a5, 0);
  sf_debug_symbol_scope_add_symbol("a4", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_a4, 0);
  sf_debug_symbol_scope_add_symbol("a3", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_a3, 0);
  sf_debug_symbol_scope_add_symbol("a2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_a2, 0);
  sf_debug_symbol_scope_add_symbol("a1", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_a1, 0);
  sf_debug_symbol_scope_add_symbol("a0", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c5_b_a0, 0);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  if(CV_EML_IF(0, 0, c5_b_t_sim > c5_b_t_end)) {
    /*  This block supports an embeddable subset of the MATLAB language. */
    /*  See the help menu for details.  */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
    c5_b_t_sim = c5_b_t_end;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c5_a = c5_b_t_sim;
  c5_b_a = c5_a;
  c5_b = 5.0;
  c5_k = 1.0;
  c5_b_k = c5_k;
  c5_x = c5_b_a;
  c5_xk = c5_x;
  c5_ak = c5_xk;
  c5_b_x = c5_b;
  c5_b_xk = c5_b_x;
  c5_bk = c5_b_xk;
  if(c5_ak < 0.0) {
    c5_c_x = c5_bk;
    c5_y = floor(c5_c_x);
    if(c5_y != c5_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c5_b_k), 1,
   1, 1);
  c5_b_y = pow(c5_ak, c5_bk);
  c5_c = c5_b_y;
  c5_A = c5_c;
  c5_B = 20.0;
  c5_d_x = c5_A;
  c5_c_y = c5_B;
  c5_z = c5_d_x / c5_c_y;
  c5_d_y = c5_z;
  c5_b_A = c5_mpower(c5_b_t_sim);
  c5_b_B = 12.0;
  c5_e_x = c5_b_A;
  c5_e_y = c5_b_B;
  c5_b_z = c5_e_x / c5_e_y;
  c5_f_y = c5_b_z;
  c5_c_A = c5_b_mpower(c5_b_t_sim);
  c5_c_B = 6.0;
  c5_f_x = c5_c_A;
  c5_g_y = c5_c_B;
  c5_c_z = c5_f_x / c5_g_y;
  c5_h_y = c5_c_z;
  c5_d_A = c5_c_mpower(c5_b_t_sim);
  c5_d_B = 2.0;
  c5_g_x = c5_d_A;
  c5_i_y = c5_d_B;
  c5_d_z = c5_g_x / c5_i_y;
  c5_j_y = c5_d_z;
  c5_e_A = c5_mpower(c5_b_t_sim);
  c5_e_B = 4.0;
  c5_h_x = c5_e_A;
  c5_k_y = c5_e_B;
  c5_e_z = c5_h_x / c5_k_y;
  c5_l_y = c5_e_z;
  c5_f_A = c5_b_mpower(c5_b_t_sim);
  c5_f_B = 3.0;
  c5_i_x = c5_f_A;
  c5_m_y = c5_f_B;
  c5_f_z = c5_i_x / c5_m_y;
  c5_n_y = c5_f_z;
  c5_g_A = c5_c_mpower(c5_b_t_sim);
  c5_g_B = 2.0;
  c5_j_x = c5_g_A;
  c5_o_y = c5_g_B;
  c5_g_z = c5_j_x / c5_o_y;
  c5_p_y = c5_g_z;
  c5_q_y[0][0] = c5_d_y;
  c5_q_y[1][0] = c5_f_y;
  c5_q_y[2][0] = c5_h_y;
  c5_q_y[3][0] = c5_j_y;
  c5_q_y[4][0] = c5_b_t_sim;
  c5_q_y[5][0] = 1.0;
  c5_r_y[0][0] = c5_l_y;
  c5_r_y[1][0] = c5_n_y;
  c5_r_y[2][0] = c5_p_y;
  c5_r_y[3][0] = c5_b_t_sim;
  c5_r_y[4][0] = 1.0;
  c5_r_y[5][0] = 0.0;
  c5_em_dv0[0][0] = c5_b_mpower(c5_b_t_sim);
  c5_em_dv0[1][0] = c5_c_mpower(c5_b_t_sim);
  c5_em_dv0[2][0] = c5_b_t_sim;
  c5_em_dv0[3][0] = 1.0;
  c5_em_dv0[4][0] = 0.0;
  c5_em_dv0[5][0] = 0.0;
  for(c5_em_i0 = 0; c5_em_i0 < 6; c5_em_i0 = c5_em_i0 + 1) {
    c5_T[c5_em_i0][0] = c5_q_y[c5_em_i0][0];
  }
  for(c5_em_i1 = 0; c5_em_i1 < 6; c5_em_i1 = c5_em_i1 + 1) {
    c5_T[c5_em_i1][1] = c5_r_y[c5_em_i1][0];
  }
  for(c5_em_i2 = 0; c5_em_i2 < 6; c5_em_i2 = c5_em_i2 + 1) {
    c5_T[c5_em_i2][2] = c5_em_dv0[c5_em_i2][0];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
  c5_c_a0[0] = c5_b_a0;
  c5_c_a0[1] = c5_b_a1;
  c5_c_a0[2] = c5_b_a2;
  c5_c_a0[3] = c5_b_a3;
  c5_c_a0[4] = c5_b_a4;
  c5_c_a0[5] = c5_b_a5;
  for(c5_em_i3 = 0; c5_em_i3 < 3; c5_em_i3 = c5_em_i3 + 1) {
    c5_Q[c5_em_i3] = 0.0;
    for(c5_em_i4 = 0; c5_em_i4 < 6; c5_em_i4 = c5_em_i4 + 1) {
      c5_Q[c5_em_i3] = c5_Q[c5_em_i3] + c5_T[c5_em_i4][c5_em_i3] *
        c5_c_a0[c5_em_i4];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  c5_b_qa = c5_Q[0];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
  c5_b_qap = c5_Q[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
  c5_b_qapp = c5_Q[2];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-13);
  sf_debug_pop_symbol_scope();
  *c5_qa() = c5_b_qa;
  *c5_qap() = c5_b_qap;
  *c5_qapp() = c5_b_qapp;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_trajectory_testMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static real_T c5_mpower(real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_b;
  real_T c5_k;
  real_T c5_b_k;
  real_T c5_x;
  real_T c5_xk;
  real_T c5_ak;
  real_T c5_b_x;
  real_T c5_b_xk;
  real_T c5_bk;
  real_T c5_c_x;
  real_T c5_y;
  real_T c5_b_y;
  c5_b_a = c5_a;
  c5_b = 4.0;
  c5_k = 1.0;
  c5_b_k = c5_k;
  c5_x = c5_b_a;
  c5_xk = c5_x;
  c5_ak = c5_xk;
  c5_b_x = c5_b;
  c5_b_xk = c5_b_x;
  c5_bk = c5_b_xk;
  if(c5_ak < 0.0) {
    c5_c_x = c5_bk;
    c5_y = floor(c5_c_x);
    if(c5_y != c5_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c5_b_k), 1,
   1, 1);
  c5_b_y = pow(c5_ak, c5_bk);
  return c5_b_y;
}

static real_T c5_b_mpower(real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_b;
  real_T c5_k;
  real_T c5_b_k;
  real_T c5_x;
  real_T c5_xk;
  real_T c5_ak;
  real_T c5_b_x;
  real_T c5_b_xk;
  real_T c5_bk;
  real_T c5_c_x;
  real_T c5_y;
  real_T c5_b_y;
  c5_b_a = c5_a;
  c5_b = 3.0;
  c5_k = 1.0;
  c5_b_k = c5_k;
  c5_x = c5_b_a;
  c5_xk = c5_x;
  c5_ak = c5_xk;
  c5_b_x = c5_b;
  c5_b_xk = c5_b_x;
  c5_bk = c5_b_xk;
  if(c5_ak < 0.0) {
    c5_c_x = c5_bk;
    c5_y = floor(c5_c_x);
    if(c5_y != c5_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c5_b_k), 1,
   1, 1);
  c5_b_y = pow(c5_ak, c5_bk);
  return c5_b_y;
}

static real_T c5_c_mpower(real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_b;
  real_T c5_k;
  real_T c5_b_k;
  real_T c5_x;
  real_T c5_xk;
  real_T c5_ak;
  real_T c5_b_x;
  real_T c5_b_xk;
  real_T c5_bk;
  real_T c5_c_x;
  real_T c5_y;
  real_T c5_b_y;
  c5_b_a = c5_a;
  c5_b = 2.0;
  c5_k = 1.0;
  c5_b_k = c5_k;
  c5_x = c5_b_a;
  c5_xk = c5_x;
  c5_ak = c5_xk;
  c5_b_x = c5_b;
  c5_b_xk = c5_b_x;
  c5_bk = c5_b_xk;
  if(c5_ak < 0.0) {
    c5_c_x = c5_bk;
    c5_y = floor(c5_c_x);
    if(c5_y != c5_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c5_b_k), 1,
   1, 1);
  c5_b_y = pow(c5_ak, c5_bk);
  return c5_b_y;
}

static real_T *c5_a0(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real_T *c5_a1(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real_T *c5_a2(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static real_T *c5_a3(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
}

static real_T *c5_a4(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
}

static real_T *c5_a5(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
}

static real_T *c5_t_sim(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
}

static real_T *c5_qa(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real_T *c5_qap(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static real_T *c5_qapp(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static real_T *c5_t_end(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 7);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c5_trajectory_test(FILE *c5_file)
{
  fwrite(&chartInstance.c5_is_active_c5_trajectory_test, 1,
   sizeof(chartInstance.c5_is_active_c5_trajectory_test), c5_file);
}

static void sf_load_state_c5_trajectory_test(FILE *c5_file)
{
  fread(&chartInstance.c5_is_active_c5_trajectory_test, 1,
   sizeof(chartInstance.c5_is_active_c5_trajectory_test), c5_file);
}

/* SFunction Glue Code */
void sf_c5_trajectory_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1930596012U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(565699577U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1492007599U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2046849703U);
}

mxArray *sf_c5_trajectory_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4238009582U);
    pr[1] = (double)(915673266U);
    pr[2] = (double)(2617678768U);
    pr[3] = (double)(2372055474U);
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
    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);
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
         5,
         1,
         1,
         11,
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

          _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a0",0);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a1",0);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a2",0);
          _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a3",0);
          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a4",0);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a5",0);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t_sim",0);
          _SFD_SET_DATA_PROPS(9,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"qa",0);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"qap",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"qapp",0);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t_end",0);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,406);
        _SFD_CV_INIT_EML_IF(0,0,161,177,-1,196);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(7U, c5_a0());
        _SFD_SET_DATA_VALUE_PTR(6U, c5_a1());
        _SFD_SET_DATA_VALUE_PTR(2U, c5_a2());
        _SFD_SET_DATA_VALUE_PTR(10U, c5_a3());
        _SFD_SET_DATA_VALUE_PTR(8U, c5_a4());
        _SFD_SET_DATA_VALUE_PTR(1U, c5_a5());
        _SFD_SET_DATA_VALUE_PTR(4U, c5_t_sim());
        _SFD_SET_DATA_VALUE_PTR(9U, c5_qa());
        _SFD_SET_DATA_VALUE_PTR(3U, c5_qap());
        _SFD_SET_DATA_VALUE_PTR(0U, c5_qapp());
        _SFD_SET_DATA_VALUE_PTR(5U, c5_t_end());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_trajectory_testMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c5_trajectory_test(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c5_trajectory_test();
  initialize_c5_trajectory_test();
}

static void sf_opaque_enable_c5_trajectory_test(void *chartInstanceVar)
{
  enable_c5_trajectory_test();
}

static void sf_opaque_disable_c5_trajectory_test(void *chartInstanceVar)
{
  disable_c5_trajectory_test();
}

static void sf_opaque_gateway_c5_trajectory_test(void *chartInstanceVar)
{
  sf_c5_trajectory_test();
}

static void sf_opaque_terminate_c5_trajectory_test(void *chartInstanceVar)
{
  finalize_c5_trajectory_test();
}

static void mdlProcessParameters_c5_trajectory_test(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c5_trajectory_test();
}

static void mdlSetWorkWidths_c5_trajectory_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("trajectory_test",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("trajectory_test",5,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"trajectory_test",5,8);
      sf_mark_chart_reusable_outputs(S,"trajectory_test",5,3);
    }
    if (!sf_is_chart_instance_optimized_out("trajectory_test",5)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("trajectory_test",5);
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

  ssSetChecksum0(S,(1777646960U));
  ssSetChecksum1(S,(693501155U));
  ssSetChecksum2(S,(2456349526U));
  ssSetChecksum3(S,(3451640452U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_trajectory_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "trajectory_test", 5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void sf_save_debug_c5_trajectory_test(SFc5_trajectory_testInstanceStruct*
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
static void sf_load_debug_c5_trajectory_test(SFc5_trajectory_testInstanceStruct*
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
static void sf_c5_trajectory_test_sim_ctx_io(SimStruct* S, const char io, FILE*
 file)
{
  if(io == 'r') {
    sf_load_state_c5_trajectory_test(file);
    sf_load_debug_c5_trajectory_test(&chartInstance, file);
  } else {
    sf_save_state_c5_trajectory_test(file);
    sf_save_debug_c5_trajectory_test(&chartInstance, file);
  }
}
static void mdlStart_c5_trajectory_test(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_trajectory_test;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c5_trajectory_test;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c5_trajectory_test;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c5_trajectory_test;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c5_trajectory_test;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c5_trajectory_test;
  chartInstance.chartInfo.mdlStart = mdlStart_c5_trajectory_test;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_trajectory_test;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c5_trajectory_test_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c5_trajectory_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_trajectory_test(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_trajectory_test(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_trajectory_test(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c5_trajectory_test_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

