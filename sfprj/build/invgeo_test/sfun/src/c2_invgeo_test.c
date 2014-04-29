/* Include files */
#include "invgeo_test_sfun.h"
#include "c2_invgeo_test.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "invgeo_test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_invgeo_testInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_invgeo_test(void);
static void initialize_params_c2_invgeo_test(void);
static void enable_c2_invgeo_test(void);
static void disable_c2_invgeo_test(void);
static void finalize_c2_invgeo_test(void);
static void sf_c2_invgeo_test(void);
static real_T c2_mpower(real_T c2_a);
static real_T c2_atan2(real_T c2_Y, real_T c2_X);
static real_T c2_sign(real_T c2_X);
static real_T *c2_x(void);
static real_T *c2_y(void);
static real_T *c2_al1_c(void);
static real_T *c2_al2_c(void);
static real_T *c2_a1(void);
static real_T *c2_a2(void);
static real_T *c2_al1(void);
static real_T *c2_al2(void);
static uint8_T *c2_error(void);
static void init_dsm_address_info(void);
static void sf_save_state_c2_invgeo_test(FILE *c2_file);
static void sf_load_state_c2_invgeo_test(FILE *c2_file);

/* Function Definitions */
static void initialize_c2_invgeo_test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_invgeo_test = 0U;
}

static void initialize_params_c2_invgeo_test(void)
{
}

static void enable_c2_invgeo_test(void)
{
}

static void disable_c2_invgeo_test(void)
{
}

static void finalize_c2_invgeo_test(void)
{
}

static void sf_c2_invgeo_test(void)
{
  uint8_T c2_previousEvent;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_b_al1_c;
  real_T c2_b_al2_c;
  real_T c2_b_a1;
  real_T c2_b_a2;
  real_T c2_al2_2;
  real_T c2_al2_1;
  real_T c2_al2_n;
  real_T c2_al2_p;
  real_T c2_al1_2;
  real_T c2_al1_1;
  real_T c2_cos_al1_n;
  real_T c2_cos_al1_p;
  real_T c2_sin_al1_n;
  real_T c2_sin_al1_p;
  real_T c2_D;
  real_T c2_cos_al2;
  real_T c2_d;
  uint8_T c2_b_error;
  real_T c2_b_al2;
  real_T c2_b_al1;
  real_T c2_c_x;
  real_T c2_c_y;
  boolean_T c2_em_b0;
  boolean_T c2_em_b1;
  real_T c2_A;
  real_T c2_B;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_z;
  real_T c2_e_y;
  real_T c2_e_x;
  real_T c2_f_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_f_x;
  real_T c2_g_y;
  real_T c2_b_z;
  real_T c2_h_y;
  real_T c2_g_x;
  real_T c2_i_y;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_h_x;
  real_T c2_j_y;
  real_T c2_c_z;
  real_T c2_k_y;
  real_T c2_i_x;
  real_T c2_l_y;
  real_T c2_d_A;
  real_T c2_d_B;
  real_T c2_j_x;
  real_T c2_m_y;
  real_T c2_d_z;
  real_T c2_n_y;
  real_T c2_k_x;
  real_T c2_o_y;
  real_T c2_e_A;
  real_T c2_e_B;
  real_T c2_l_x;
  real_T c2_p_y;
  real_T c2_e_z;
  real_T c2_q_y;
  real_T c2_m_x;
  real_T c2_k;
  real_T c2_b_k;
  real_T c2_r_y;
  real_T c2_n_x;
  real_T c2_s_y;
  real_T c2_o_x;
  real_T c2_t_y;
  real_T c2_p_x;
  real_T c2_u_y;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_x(), 1U);
  _SFD_DATA_RANGE_CHECK(*c2_y(), 8U);
  _SFD_DATA_RANGE_CHECK(*c2_al1_c(), 3U);
  _SFD_DATA_RANGE_CHECK(*c2_al2_c(), 4U);
  _SFD_DATA_RANGE_CHECK(*c2_a1(), 5U);
  _SFD_DATA_RANGE_CHECK(*c2_a2(), 2U);
  _SFD_DATA_RANGE_CHECK(*c2_al1(), 0U);
  _SFD_DATA_RANGE_CHECK(*c2_al2(), 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_error(), 6U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_b_x = *c2_x();
  c2_b_y = *c2_y();
  c2_b_al1_c = *c2_al1_c();
  c2_b_al2_c = *c2_al2_c();
  c2_b_a1 = *c2_a1();
  c2_b_a2 = *c2_a2();
  sf_debug_push_symbol_scope(22U, 0U);
  sf_debug_symbol_scope_add_symbol("al2_2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_2, 0);
  sf_debug_symbol_scope_add_symbol("al2_1", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_1, 0);
  sf_debug_symbol_scope_add_symbol("al2_n", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_n, 0);
  sf_debug_symbol_scope_add_symbol("al2_p", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_p, 0);
  sf_debug_symbol_scope_add_symbol("al1_2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al1_2, 0);
  sf_debug_symbol_scope_add_symbol("al1_1", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al1_1, 0);
  sf_debug_symbol_scope_add_symbol("cos_al1_n", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_cos_al1_n, 0);
  sf_debug_symbol_scope_add_symbol("cos_al1_p", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_cos_al1_p, 0);
  sf_debug_symbol_scope_add_symbol("sin_al1_n", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_sin_al1_n, 0);
  sf_debug_symbol_scope_add_symbol("sin_al1_p", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_sin_al1_p, 0);
  sf_debug_symbol_scope_add_symbol("D", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_D, 0);
  sf_debug_symbol_scope_add_symbol("cos_al2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_cos_al2, 0);
  sf_debug_symbol_scope_add_symbol("d", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_d, 0);
  sf_debug_symbol_scope_add_symbol("error", 3, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_b_error, 0);
  sf_debug_symbol_scope_add_symbol("al2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_al2, 0);
  sf_debug_symbol_scope_add_symbol("al1", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_al1, 0);
  sf_debug_symbol_scope_add_symbol("a2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_a2, 0);
  sf_debug_symbol_scope_add_symbol("a1", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_a1, 0);
  sf_debug_symbol_scope_add_symbol("al2_c", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_b_al2_c, 0);
  sf_debug_symbol_scope_add_symbol("al1_c", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_b_al1_c, 0);
  sf_debug_symbol_scope_add_symbol("y", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_y, 0);
  sf_debug_symbol_scope_add_symbol("x", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_x, 0);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,3);
  c2_c_x = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
  c2_c_y = sqrt(c2_c_x);
  c2_d = c2_c_y;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c2_em_b0 = (c2_mpower(c2_d) > c2_mpower(c2_b_a1) + c2_mpower(c2_b_a2));
  c2_em_b1 = (c2_d < c2_b_a1 - c2_b_a2);
  if(CV_EML_IF(0, 0, c2_em_b0 || c2_em_b1)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
    c2_b_al1 = c2_b_al1_c;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
    c2_b_al2 = c2_b_al2_c;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
    c2_b_error = 1U;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
    c2_A = ((c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_b_a1)) -
      c2_mpower(c2_b_a2);
    c2_B = 2.0 * c2_b_a1 * c2_b_a2;
    c2_d_x = c2_A;
    c2_d_y = c2_B;
    c2_z = c2_d_x / c2_d_y;
    c2_e_y = c2_z;
    c2_cos_al2 = c2_e_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
    c2_D = c2_b_a1 + c2_b_a2 * c2_cos_al2;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,14);
    c2_e_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_f_y = sqrt(c2_e_x);
    c2_b_A = c2_D * c2_b_y + c2_b_x * c2_f_y;
    c2_b_B = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
    c2_f_x = c2_b_A;
    c2_g_y = c2_b_B;
    c2_b_z = c2_f_x / c2_g_y;
    c2_h_y = c2_b_z;
    c2_sin_al1_p = c2_h_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
    c2_g_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_i_y = sqrt(c2_g_x);
    c2_c_A = c2_D * c2_b_y - c2_b_x * c2_i_y;
    c2_c_B = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
    c2_h_x = c2_c_A;
    c2_j_y = c2_c_B;
    c2_c_z = c2_h_x / c2_j_y;
    c2_k_y = c2_c_z;
    c2_sin_al1_n = c2_k_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
    c2_i_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_l_y = sqrt(c2_i_x);
    c2_d_A = c2_D * c2_b_x + c2_b_y * c2_l_y;
    c2_d_B = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
    c2_j_x = c2_d_A;
    c2_m_y = c2_d_B;
    c2_d_z = c2_j_x / c2_m_y;
    c2_n_y = c2_d_z;
    c2_cos_al1_p = c2_n_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
    c2_k_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_o_y = sqrt(c2_k_x);
    c2_e_A = c2_D * c2_b_x - c2_b_y * c2_o_y;
    c2_e_B = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
    c2_l_x = c2_e_A;
    c2_p_y = c2_e_B;
    c2_e_z = c2_l_x / c2_p_y;
    c2_q_y = c2_e_z;
    c2_cos_al1_n = c2_q_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,20);
    c2_al1_1 = c2_atan2(c2_sin_al1_p, c2_cos_al1_n);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,22);
    c2_al1_2 = c2_atan2(c2_sin_al1_n, c2_cos_al1_p);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,24);
    c2_m_x = c2_cos_al2;
    c2_k = 1.0;
    c2_b_k = c2_k;
    _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
     1, 1, 1);
    if(c2_m_x < -1.0) {
    } else {
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
       1, 1, 1);
      if(c2_m_x > 1.0) {
      } else {
        goto label_1;
      }
    }
    sf_mex_call("error", 0U, 1U, 15,
     "Domain error. To compute complex results from real x, use \'acos(complex(x))\'.");
    label_1:;
    c2_r_y = acos(c2_m_x);
    c2_al2_p = c2_r_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,25);
    c2_al2_n = -c2_al2_p;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,27);
    c2_n_x = c2_al1_1 + c2_al2_p;
    c2_s_y = cos(c2_n_x);
    if(CV_EML_IF(0, 1, c2_b_x == c2_b_a1 * c2_cos_al1_n + c2_b_a2 * c2_s_y)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,28);
      c2_al2_1 = c2_al2_p;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
      c2_al2_2 = c2_al2_n;
    } else {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,31);
      c2_al2_1 = c2_al2_n;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,32);
      c2_al2_2 = c2_al2_p;
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
    c2_o_x = c2_b_al1_c - c2_al1_1;
    c2_t_y = fabs(c2_o_x);
    c2_p_x = c2_b_al1_c - c2_al1_2;
    c2_u_y = fabs(c2_p_x);
    if(CV_EML_IF(0, 2, c2_t_y < c2_u_y)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,36);
      c2_b_al1 = c2_al1_1;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,37);
      c2_b_al2 = c2_al2_1;
    } else {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,39);
      c2_b_al1 = c2_al1_2;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,40);
      c2_b_al2 = c2_al2_2;
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,43);
    c2_b_error = 0U;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-43);
  sf_debug_pop_symbol_scope();
  *c2_al1() = c2_b_al1;
  *c2_al2() = c2_b_al2;
  *c2_error() = c2_b_error;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_invgeo_testMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static real_T c2_mpower(real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_b;
  real_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_xk;
  real_T c2_ak;
  real_T c2_c_x;
  real_T c2_b_xk;
  real_T c2_bk;
  real_T c2_d_x;
  real_T c2_b_y;
  real_T c2_c_y;
  c2_b_a = c2_a;
  c2_b = 2.0;
  c2_k = 1.0;
  c2_b_k = c2_k;
  c2_b_x = c2_b_a;
  c2_xk = c2_b_x;
  c2_ak = c2_xk;
  c2_c_x = c2_b;
  c2_b_xk = c2_c_x;
  c2_bk = c2_b_xk;
  if(c2_ak < 0.0) {
    c2_d_x = c2_bk;
    c2_b_y = floor(c2_d_x);
    if(c2_b_y != c2_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k), 1,
   1, 1);
  c2_c_y = pow(c2_ak, c2_bk);
  return c2_c_y;
}

static real_T c2_atan2(real_T c2_Y, real_T c2_X)
{
  real_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_xk;
  real_T c2_yk;
  real_T c2_c_x;
  real_T c2_b_xk;
  real_T c2_c_xk;
  real_T c2_b_y;
  real_T c2_d_x;
  real_T c2_e_x;
  boolean_T c2_b;
  real_T c2_f_x;
  boolean_T c2_b_b;
  real_T c2_g_x;
  real_T c2_r;
  real_T c2_c_y;
  real_T c2_b_r;
  real_T c2_h_x;
  boolean_T c2_c_b;
  real_T c2_i_x;
  boolean_T c2_d_b;
  real_T c2_j_x;
  real_T c2_c_r;
  real_T c2_k_x;
  real_T c2_d_r;
  real_T c2_l_x;
  real_T c2_e_r;
  real_T c2_m_x;
  real_T c2_f_r;
  c2_k = 1.0;
  c2_b_k = c2_k;
  c2_b_x = c2_Y;
  c2_xk = c2_b_x;
  c2_yk = c2_xk;
  c2_c_x = c2_X;
  c2_b_xk = c2_c_x;
  c2_c_xk = c2_b_xk;
  _SFD_EML_ARRAY_BOUNDS_CHECK("R", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k), 1,
   1, 1);
  c2_b_y = c2_yk;
  c2_d_x = c2_c_xk;
  c2_e_x = c2_d_x;
  c2_b = rtIsNaN(c2_e_x);
  if(c2_b) {
    goto label_1;
  } else {
    c2_f_x = c2_b_y;
    c2_b_b = rtIsNaN(c2_f_x);
    if(c2_b_b) {
      goto label_1;
    } else {
      c2_h_x = c2_b_y;
      c2_c_b = rtIsInf(c2_h_x);
      if(c2_c_b) {
        c2_i_x = c2_d_x;
        c2_d_b = rtIsInf(c2_i_x);
        if(c2_d_b) {
          c2_j_x = atan2(c2_sign(c2_b_y), c2_sign(c2_d_x));
          c2_c_r = c2_j_x;
          c2_b_r = c2_c_r;
          goto label_2;
        }
      }
    }
  }
  if(c2_d_x == 0.0) {
    if(c2_b_y > 0.0) {
      c2_k_x = 1.5707963267948966E+000;
      c2_d_r = c2_k_x;
      c2_b_r = c2_d_r;
    } else if(c2_b_y < 0.0) {
      c2_l_x = -1.5707963267948966E+000;
      c2_e_r = c2_l_x;
      c2_b_r = c2_e_r;
    } else {
      c2_b_r = 0.0;
    }
  } else {
    c2_m_x = atan2(c2_b_y, c2_d_x);
    c2_f_r = c2_m_x;
    c2_b_r = c2_f_r;
  }
  goto label_2;
  label_1:;
  c2_g_x = rtNaN;
  c2_r = c2_g_x;
  c2_c_y = c2_r;
  c2_b_r = c2_c_y;
  label_2:;
  return c2_b_r;
}

static real_T c2_sign(real_T c2_X)
{
  real_T c2_S;
  real_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  boolean_T c2_b;
  real_T c2_b_y;
  c2_S = 0.0;
  c2_k = 1.0;
  c2_b_k = c2_k;
  _SFD_EML_ARRAY_BOUNDS_CHECK("X", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k), 1,
   1, 1);
  c2_b_x = c2_X;
  c2_c_x = c2_b_x;
  c2_b = rtIsNaN(c2_c_x);
  if(c2_b) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
     1, 1, 1);
    c2_b_y = rtNaN;
    return c2_b_y;
  } else if(c2_b_x > 0.0) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
     1, 1, 1);
    return 1.0;
  } else if(c2_b_x < 0.0) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
     1, 1, 1);
    return -1.0;
  }
  return c2_S;
}

static real_T *c2_x(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real_T *c2_y(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real_T *c2_al1_c(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static real_T *c2_al2_c(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
}

static real_T *c2_a1(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
}

static real_T *c2_a2(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
}

static real_T *c2_al1(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real_T *c2_al2(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static uint8_T *c2_error(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c2_invgeo_test(FILE *c2_file)
{
  fwrite(&chartInstance.c2_is_active_c2_invgeo_test, 1,
   sizeof(chartInstance.c2_is_active_c2_invgeo_test), c2_file);
}

static void sf_load_state_c2_invgeo_test(FILE *c2_file)
{
  fread(&chartInstance.c2_is_active_c2_invgeo_test, 1,
   sizeof(chartInstance.c2_is_active_c2_invgeo_test), c2_file);
}

/* SFunction Glue Code */
void sf_c2_invgeo_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1809520955U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4012761217U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(78359670U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1759277369U);
}

mxArray *sf_c2_invgeo_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4177632627U);
    pr[1] = (double)(3369926759U);
    pr[2] = (double)(2211162526U);
    pr[3] = (double)(4053111967U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(3));
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
          sf_debug_initialize_chart(_invgeo_testMachineNumber_,
         2,
         1,
         1,
         9,
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
          sf_debug_set_chart_disable_implicit_casting(_invgeo_testMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_invgeo_testMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x",0);
          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"al1_c",0);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"al2_c",0);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a1",0);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a2",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"al1",0);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"al2",0);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"error",0);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1105);
        _SFD_CV_INIT_EML_IF(0,0,98,140,756,917);
        _SFD_CV_INIT_EML_IF(0,1,756,808,860,917);
        _SFD_CV_INIT_EML_IF(0,2,927,971,1018,1072);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(1U, c2_x());
        _SFD_SET_DATA_VALUE_PTR(8U, c2_y());
        _SFD_SET_DATA_VALUE_PTR(3U, c2_al1_c());
        _SFD_SET_DATA_VALUE_PTR(4U, c2_al2_c());
        _SFD_SET_DATA_VALUE_PTR(5U, c2_a1());
        _SFD_SET_DATA_VALUE_PTR(2U, c2_a2());
        _SFD_SET_DATA_VALUE_PTR(0U, c2_al1());
        _SFD_SET_DATA_VALUE_PTR(7U, c2_al2());
        _SFD_SET_DATA_VALUE_PTR(6U, c2_error());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_invgeo_testMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_invgeo_test(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c2_invgeo_test();
  initialize_c2_invgeo_test();
}

static void sf_opaque_enable_c2_invgeo_test(void *chartInstanceVar)
{
  enable_c2_invgeo_test();
}

static void sf_opaque_disable_c2_invgeo_test(void *chartInstanceVar)
{
  disable_c2_invgeo_test();
}

static void sf_opaque_gateway_c2_invgeo_test(void *chartInstanceVar)
{
  sf_c2_invgeo_test();
}

static void sf_opaque_terminate_c2_invgeo_test(void *chartInstanceVar)
{
  finalize_c2_invgeo_test();
}

static void mdlProcessParameters_c2_invgeo_test(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c2_invgeo_test();
}

static void mdlSetWorkWidths_c2_invgeo_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("invgeo_test",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("invgeo_test",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"invgeo_test",2,6);
      sf_mark_chart_reusable_outputs(S,"invgeo_test",2,3);
    }
    if (!sf_is_chart_instance_optimized_out("invgeo_test",2)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("invgeo_test",2);
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

  ssSetChecksum0(S,(1702540849U));
  ssSetChecksum1(S,(1166673137U));
  ssSetChecksum2(S,(2209122499U));
  ssSetChecksum3(S,(1272556604U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_invgeo_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "invgeo_test", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void sf_save_debug_c2_invgeo_test(SFc2_invgeo_testInstanceStruct*
 chartInstance, FILE* file)
{
  int machineNumber = _invgeo_testMachineNumber_;
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
static void sf_load_debug_c2_invgeo_test(SFc2_invgeo_testInstanceStruct*
 chartInstance,FILE* file)
{
  int machineNumber = _invgeo_testMachineNumber_;
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
static void sf_c2_invgeo_test_sim_ctx_io(SimStruct* S, const char io, FILE* file)
{
  if(io == 'r') {
    sf_load_state_c2_invgeo_test(file);
    sf_load_debug_c2_invgeo_test(&chartInstance, file);
  } else {
    sf_save_state_c2_invgeo_test(file);
    sf_save_debug_c2_invgeo_test(&chartInstance, file);
  }
}
static void mdlStart_c2_invgeo_test(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_invgeo_test;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_invgeo_test;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_invgeo_test;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_invgeo_test;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_invgeo_test;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_invgeo_test;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_invgeo_test;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_invgeo_test;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c2_invgeo_test_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c2_invgeo_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_invgeo_test(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_invgeo_test(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_invgeo_test(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_invgeo_test_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

