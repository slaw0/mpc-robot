/* Include files */
#include "trajectory_test_sfun.h"
#include "c6_trajectory_test.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "trajectory_test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c6_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc6_trajectory_testInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c6_trajectory_test(void);
static void initialize_params_c6_trajectory_test(void);
static void enable_c6_trajectory_test(void);
static void disable_c6_trajectory_test(void);
static void finalize_c6_trajectory_test(void);
static void sf_c6_trajectory_test(void);
static real_T c6_mpower(real_T c6_a);
static real_T c6_b_mpower(real_T c6_a);
static real_T c6_c_mpower(real_T c6_a);
static void c6_inv(real_T *c6_x, real_T *c6_y);
static real_T c6_norm(real_T *c6_x);
static real_T *c6_A(void);
static real_T *c6_B(void);
static real_T *c6_t(void);
static real_T *c6_a0(void);
static real_T *c6_a1(void);
static real_T *c6_a2(void);
static real_T *c6_a3(void);
static real_T *c6_a4(void);
static real_T *c6_a5(void);
static void init_dsm_address_info(void);
static void sf_save_state_c6_trajectory_test(FILE *c6_file);
static void sf_load_state_c6_trajectory_test(FILE *c6_file);

/* Function Definitions */
static void initialize_c6_trajectory_test(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c6_is_active_c6_trajectory_test = 0U;
}

static void initialize_params_c6_trajectory_test(void)
{
}

static void enable_c6_trajectory_test(void)
{
}

static void disable_c6_trajectory_test(void)
{
}

static void finalize_c6_trajectory_test(void)
{
}

static void sf_c6_trajectory_test(void)
{
  uint8_T c6_previousEvent;
  real_T c6_b_A;
  real_T c6_b_B;
  real_T c6_b_t;
  real_T c6_Ao[6];
  real_T c6_T[6][6];
  real_T c6_b_a5;
  real_T c6_b_a4;
  real_T c6_b_a3;
  real_T c6_b_a2;
  real_T c6_b_a1;
  real_T c6_b_a0;
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_b;
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_x;
  real_T c6_xk;
  real_T c6_ak;
  real_T c6_b_x;
  real_T c6_b_xk;
  real_T c6_bk;
  real_T c6_c_x;
  real_T c6_y;
  real_T c6_b_y;
  real_T c6_c;
  real_T c6_c_A;
  real_T c6_c_B;
  real_T c6_d_x;
  real_T c6_c_y;
  real_T c6_z;
  real_T c6_d_y;
  real_T c6_d_A;
  real_T c6_d_B;
  real_T c6_e_x;
  real_T c6_e_y;
  real_T c6_b_z;
  real_T c6_f_y;
  real_T c6_e_A;
  real_T c6_e_B;
  real_T c6_f_x;
  real_T c6_g_y;
  real_T c6_c_z;
  real_T c6_h_y;
  real_T c6_f_A;
  real_T c6_f_B;
  real_T c6_g_x;
  real_T c6_i_y;
  real_T c6_d_z;
  real_T c6_j_y;
  real_T c6_g_A;
  real_T c6_g_B;
  real_T c6_h_x;
  real_T c6_k_y;
  real_T c6_e_z;
  real_T c6_l_y;
  real_T c6_h_A;
  real_T c6_h_B;
  real_T c6_i_x;
  real_T c6_m_y;
  real_T c6_f_z;
  real_T c6_n_y;
  real_T c6_i_A;
  real_T c6_i_B;
  real_T c6_j_x;
  real_T c6_o_y;
  real_T c6_g_z;
  real_T c6_p_y;
  real_T c6_q_y[6][1];
  real_T c6_r_y[6][1];
  real_T c6_em_dv0[6][1];
  int32_T c6_em_i0;
  int32_T c6_em_i1;
  int32_T c6_em_i2;
  int32_T c6_em_i3;
  static real_T c6_em_dv1[6][1] = { { 0.0 }, { 0.0 }, { 0.0 }, { 0.0 }, { 0.0 },
    { 1.0 } };
  int32_T c6_em_i4;
  static real_T c6_em_dv2[6][1] = { { 0.0 }, { 0.0 }, { 0.0 }, { 0.0 }, { 1.0 },
    { 0.0 } };
  int32_T c6_em_i5;
  static real_T c6_em_dv3[6][1] = { { 0.0 }, { 0.0 }, { 0.0 }, { 1.0 }, { 0.0 },
    { 0.0 } };
  int32_T c6_em_i6;
  int32_T c6_em_i7;
  real_T c6_b_T[6][6];
  real_T c6_em_dv4[6][6];
  real_T c6_j_B[6];
  int32_T c6_em_i8;
  int32_T c6_em_i9;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c6_A(), 8U);
  _SFD_DATA_RANGE_CHECK(*c6_B(), 1U);
  _SFD_DATA_RANGE_CHECK(*c6_t(), 4U);
  _SFD_DATA_RANGE_CHECK(*c6_a0(), 2U);
  _SFD_DATA_RANGE_CHECK(*c6_a1(), 7U);
  _SFD_DATA_RANGE_CHECK(*c6_a2(), 5U);
  _SFD_DATA_RANGE_CHECK(*c6_a3(), 3U);
  _SFD_DATA_RANGE_CHECK(*c6_a4(), 6U);
  _SFD_DATA_RANGE_CHECK(*c6_a5(), 0U);
  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  c6_b_A = *c6_A();
  c6_b_B = *c6_B();
  c6_b_t = *c6_t();
  sf_debug_push_symbol_scope(11U, 0U);
  sf_debug_symbol_scope_add_symbol("Ao", 0, 1U, 6U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c6_Ao, 0);
  sf_debug_symbol_scope_add_symbol("T", 0, 2U, 6U, 6U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c6_T, 0);
  sf_debug_symbol_scope_add_symbol("a5", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_a5, 0);
  sf_debug_symbol_scope_add_symbol("a4", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_a4, 0);
  sf_debug_symbol_scope_add_symbol("a3", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_a3, 0);
  sf_debug_symbol_scope_add_symbol("a2", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_a2, 0);
  sf_debug_symbol_scope_add_symbol("a1", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_a1, 0);
  sf_debug_symbol_scope_add_symbol("a0", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_a0, 0);
  sf_debug_symbol_scope_add_symbol("t", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_t, 0);
  sf_debug_symbol_scope_add_symbol("B", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_B, 0);
  sf_debug_symbol_scope_add_symbol("A", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c6_b_A, 0);
  CV_EML_FCN(0, 0);
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c6_a = c6_b_t;
  c6_b_a = c6_a;
  c6_b = 5.0;
  c6_k = 1.0;
  c6_b_k = c6_k;
  c6_x = c6_b_a;
  c6_xk = c6_x;
  c6_ak = c6_xk;
  c6_b_x = c6_b;
  c6_b_xk = c6_b_x;
  c6_bk = c6_b_xk;
  if(c6_ak < 0.0) {
    c6_c_x = c6_bk;
    c6_y = floor(c6_c_x);
    if(c6_y != c6_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1,
   1, 1);
  c6_b_y = pow(c6_ak, c6_bk);
  c6_c = c6_b_y;
  c6_c_A = c6_c;
  c6_c_B = 20.0;
  c6_d_x = c6_c_A;
  c6_c_y = c6_c_B;
  c6_z = c6_d_x / c6_c_y;
  c6_d_y = c6_z;
  c6_d_A = c6_mpower(c6_b_t);
  c6_d_B = 12.0;
  c6_e_x = c6_d_A;
  c6_e_y = c6_d_B;
  c6_b_z = c6_e_x / c6_e_y;
  c6_f_y = c6_b_z;
  c6_e_A = c6_b_mpower(c6_b_t);
  c6_e_B = 6.0;
  c6_f_x = c6_e_A;
  c6_g_y = c6_e_B;
  c6_c_z = c6_f_x / c6_g_y;
  c6_h_y = c6_c_z;
  c6_f_A = c6_c_mpower(c6_b_t);
  c6_f_B = 2.0;
  c6_g_x = c6_f_A;
  c6_i_y = c6_f_B;
  c6_d_z = c6_g_x / c6_i_y;
  c6_j_y = c6_d_z;
  c6_g_A = c6_mpower(c6_b_t);
  c6_g_B = 4.0;
  c6_h_x = c6_g_A;
  c6_k_y = c6_g_B;
  c6_e_z = c6_h_x / c6_k_y;
  c6_l_y = c6_e_z;
  c6_h_A = c6_b_mpower(c6_b_t);
  c6_h_B = 3.0;
  c6_i_x = c6_h_A;
  c6_m_y = c6_h_B;
  c6_f_z = c6_i_x / c6_m_y;
  c6_n_y = c6_f_z;
  c6_i_A = c6_c_mpower(c6_b_t);
  c6_i_B = 2.0;
  c6_j_x = c6_i_A;
  c6_o_y = c6_i_B;
  c6_g_z = c6_j_x / c6_o_y;
  c6_p_y = c6_g_z;
  c6_q_y[0][0] = c6_d_y;
  c6_q_y[1][0] = c6_f_y;
  c6_q_y[2][0] = c6_h_y;
  c6_q_y[3][0] = c6_j_y;
  c6_q_y[4][0] = c6_b_t;
  c6_q_y[5][0] = 1.0;
  c6_r_y[0][0] = c6_l_y;
  c6_r_y[1][0] = c6_n_y;
  c6_r_y[2][0] = c6_p_y;
  c6_r_y[3][0] = c6_b_t;
  c6_r_y[4][0] = 1.0;
  c6_r_y[5][0] = 0.0;
  c6_em_dv0[0][0] = c6_b_mpower(c6_b_t);
  c6_em_dv0[1][0] = c6_c_mpower(c6_b_t);
  c6_em_dv0[2][0] = c6_b_t;
  c6_em_dv0[3][0] = 1.0;
  c6_em_dv0[4][0] = 0.0;
  c6_em_dv0[5][0] = 0.0;
  for(c6_em_i0 = 0; c6_em_i0 < 6; c6_em_i0 = c6_em_i0 + 1) {
    c6_T[c6_em_i0][0] = c6_q_y[c6_em_i0][0];
  }
  for(c6_em_i1 = 0; c6_em_i1 < 6; c6_em_i1 = c6_em_i1 + 1) {
    c6_T[c6_em_i1][1] = c6_r_y[c6_em_i1][0];
  }
  for(c6_em_i2 = 0; c6_em_i2 < 6; c6_em_i2 = c6_em_i2 + 1) {
    c6_T[c6_em_i2][2] = c6_em_dv0[c6_em_i2][0];
  }
  for(c6_em_i3 = 0; c6_em_i3 < 6; c6_em_i3 = c6_em_i3 + 1) {
    c6_T[c6_em_i3][3] = c6_em_dv1[c6_em_i3][0];
  }
  for(c6_em_i4 = 0; c6_em_i4 < 6; c6_em_i4 = c6_em_i4 + 1) {
    c6_T[c6_em_i4][4] = c6_em_dv2[c6_em_i4][0];
  }
  for(c6_em_i5 = 0; c6_em_i5 < 6; c6_em_i5 = c6_em_i5 + 1) {
    c6_T[c6_em_i5][5] = c6_em_dv3[c6_em_i5][0];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  for(c6_em_i6 = 0; c6_em_i6 < 6; c6_em_i6 = c6_em_i6 + 1) {
    for(c6_em_i7 = 0; c6_em_i7 < 6; c6_em_i7 = c6_em_i7 + 1) {
      c6_b_T[c6_em_i6][c6_em_i7] = c6_T[c6_em_i6][c6_em_i7];
    }
  }
  c6_inv((real_T *)c6_b_T, (real_T *)c6_em_dv4);
  c6_j_B[0] = c6_b_B;
  c6_j_B[1] = 0.0;
  c6_j_B[2] = 0.0;
  c6_j_B[3] = c6_b_A;
  c6_j_B[4] = 0.0;
  c6_j_B[5] = 0.0;
  for(c6_em_i8 = 0; c6_em_i8 < 6; c6_em_i8 = c6_em_i8 + 1) {
    c6_Ao[c6_em_i8] = 0.0;
    for(c6_em_i9 = 0; c6_em_i9 < 6; c6_em_i9 = c6_em_i9 + 1) {
      c6_Ao[c6_em_i8] = c6_Ao[c6_em_i8] + c6_em_dv4[c6_em_i9][c6_em_i8] *
        c6_j_B[c6_em_i9];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c6_b_a0 = c6_Ao[0];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  c6_b_a1 = c6_Ao[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
  c6_b_a2 = c6_Ao[2];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
  c6_b_a3 = c6_Ao[3];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  c6_b_a4 = c6_Ao[4];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  c6_b_a5 = c6_Ao[5];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-11);
  sf_debug_pop_symbol_scope();
  *c6_a0() = c6_b_a0;
  *c6_a1() = c6_b_a1;
  *c6_a2() = c6_b_a2;
  *c6_a3() = c6_b_a3;
  *c6_a4() = c6_b_a4;
  *c6_a5() = c6_b_a5;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency(_trajectory_testMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static real_T c6_mpower(real_T c6_a)
{
  real_T c6_b_a;
  real_T c6_b;
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_x;
  real_T c6_xk;
  real_T c6_ak;
  real_T c6_b_x;
  real_T c6_b_xk;
  real_T c6_bk;
  real_T c6_c_x;
  real_T c6_y;
  real_T c6_b_y;
  c6_b_a = c6_a;
  c6_b = 4.0;
  c6_k = 1.0;
  c6_b_k = c6_k;
  c6_x = c6_b_a;
  c6_xk = c6_x;
  c6_ak = c6_xk;
  c6_b_x = c6_b;
  c6_b_xk = c6_b_x;
  c6_bk = c6_b_xk;
  if(c6_ak < 0.0) {
    c6_c_x = c6_bk;
    c6_y = floor(c6_c_x);
    if(c6_y != c6_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1,
   1, 1);
  c6_b_y = pow(c6_ak, c6_bk);
  return c6_b_y;
}

static real_T c6_b_mpower(real_T c6_a)
{
  real_T c6_b_a;
  real_T c6_b;
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_x;
  real_T c6_xk;
  real_T c6_ak;
  real_T c6_b_x;
  real_T c6_b_xk;
  real_T c6_bk;
  real_T c6_c_x;
  real_T c6_y;
  real_T c6_b_y;
  c6_b_a = c6_a;
  c6_b = 3.0;
  c6_k = 1.0;
  c6_b_k = c6_k;
  c6_x = c6_b_a;
  c6_xk = c6_x;
  c6_ak = c6_xk;
  c6_b_x = c6_b;
  c6_b_xk = c6_b_x;
  c6_bk = c6_b_xk;
  if(c6_ak < 0.0) {
    c6_c_x = c6_bk;
    c6_y = floor(c6_c_x);
    if(c6_y != c6_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1,
   1, 1);
  c6_b_y = pow(c6_ak, c6_bk);
  return c6_b_y;
}

static real_T c6_c_mpower(real_T c6_a)
{
  real_T c6_b_a;
  real_T c6_b;
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_x;
  real_T c6_xk;
  real_T c6_ak;
  real_T c6_b_x;
  real_T c6_b_xk;
  real_T c6_bk;
  real_T c6_c_x;
  real_T c6_y;
  real_T c6_b_y;
  c6_b_a = c6_a;
  c6_b = 2.0;
  c6_k = 1.0;
  c6_b_k = c6_k;
  c6_x = c6_b_a;
  c6_xk = c6_x;
  c6_ak = c6_xk;
  c6_b_x = c6_b;
  c6_b_xk = c6_b_x;
  c6_bk = c6_b_xk;
  if(c6_ak < 0.0) {
    c6_c_x = c6_bk;
    c6_y = floor(c6_c_x);
    if(c6_y != c6_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1,
   1, 1);
  c6_b_y = pow(c6_ak, c6_bk);
  return c6_b_y;
}

static void c6_inv(real_T *c6_x, real_T *c6_y)
{
  int32_T c6_em_i10;
  int32_T c6_em_i11;
  real_T c6_b_x[6][6];
  real_T c6_b_y[6][6];
  real_T c6_b_A[6][6];
  real_T c6_c_A[6][6];
  int32_T c6_em_i12;
  real_T c6_pivot[6][1];
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_p;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_maxval;
  real_T c6_em_d0;
  real_T c6_i;
  real_T c6_b_i;
  real_T c6_d_x;
  real_T c6_d_y;
  real_T c6_e_x;
  real_T c6_e_y;
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_temp;
  real_T c6_ptemp;
  real_T c6_em_d1;
  real_T c6_c_i;
  real_T c6_d_A;
  real_T c6_b_B;
  real_T c6_f_x;
  real_T c6_f_y;
  real_T c6_z;
  real_T c6_g_y;
  real_T c6_em_d2;
  real_T c6_j;
  real_T c6_b_j;
  real_T c6_em_d3;
  real_T c6_d_i;
  int32_T c6_em_i13;
  int32_T c6_em_i14;
  real_T c6_g_x[6][6];
  int32_T c6_em_i15;
  real_T c6_b_p[6][1];
  int32_T c6_em_i16;
  int32_T c6_em_i17;
  real_T c6_c_k;
  real_T c6_d_k;
  real_T c6_h_x;
  boolean_T c6_b;
  real_T c6_h_y;
  int32_T c6_em_i18;
  real_T c6_e_k;
  real_T c6_c;
  real_T c6_em_d4;
  real_T c6_c_j;
  real_T c6_d_j;
  real_T c6_em_d5;
  real_T c6_e_i;
  real_T c6_f_i;
  real_T c6_e_j;
  real_T c6_e_A;
  real_T c6_c_B;
  real_T c6_i_x;
  real_T c6_i_y;
  real_T c6_b_z;
  real_T c6_j_y;
  real_T c6_f_j;
  real_T c6_g_i;
  int32_T c6_em_i19;
  int32_T c6_em_i20;
  real_T c6_j_x[6][6];
  real_T c6_xinv[6][6];
  real_T c6_f_A;
  int32_T c6_em_i21;
  int32_T c6_em_i22;
  real_T c6_k_x[6][6];
  real_T c6_b_xinv[6][6];
  real_T c6_d_B;
  real_T c6_l_x;
  real_T c6_k_y;
  real_T c6_c_z;
  real_T c6_l_y;
  real_T c6_rcond;
  real_T c6_m_x;
  boolean_T c6_b_b;
  real_T c6_r;
  int32_T c6_em_i23;
  static char c6_em_cv0[103][1] = { { 'M' }, { 'a' }, { 't' }, { 'r' }, { 'i' },
    { 'x' }, { ' ' }, { 'i' }, { 's' }, { ' ' }, { 's' }
    , { 'i' }, { 'n' }, { 'g' }, { 'u' }, { 'l' }, { 'a' }, { 'r' }, { ',' }, {
      ' ' }, { 'c' }, { 'l'
    }, { 'o' }, { 's' }, { 'e' }, { ' ' }, { 't' }, { 'o' }, { ' ' }, { 's' }, {
      'i' }, { 'n' }, {
      'g'
    }, { 'u' }, { 'l' }, { 'a' }, { 'r' }, { ' ' }, { 'o' }, { 'r' }, { ' ' }, {
      'b' }, { 'a' }, {
      'd'
    }, { 'l' }, { 'y' }, { ' ' }, { 's' }, { 'c' }, { 'a' }, { 'l' }, { 'e' }, {
      'd' }, { '.' }, {
      '\\'
    }, { 'n' }, { ' ' }, { ' ' }, { ' ' }, { ' ' }, { ' ' }, { ' ' }, { ' ' }, {
      ' ' }, { ' ' }, {
      'R'
    }, { 'e' }, { 's' }, { 'u' }, { 'l' }, { 't' }, { 's' }, { ' ' }, { 'm' }, {
      'a' }, { 'y' }, {
      ' '
    }, { 'b' }, { 'e' }, { ' ' }, { 'i' }, { 'n' }, { 'a' }, { 'c' }, { 'c' }, {
      'u' }, { 'r' }, {
      'a'
    }, { 't' }, { 'e' }, { '.' }, { ' ' }, { 'R' }, { 'C' }, { 'O' }, { 'N' }, {
      'D' }, { ' ' }, {
      '='
    }, { ' ' }, { '%' }, { 'e' }, { '.' } };
  char c6_em_cv1[103][1];
  for(c6_em_i10 = 0; c6_em_i10 < 6; c6_em_i10 = c6_em_i10 + 1) {
    for(c6_em_i11 = 0; c6_em_i11 < 6; c6_em_i11 = c6_em_i11 + 1) {
      c6_b_x[c6_em_i10][c6_em_i11] = c6_x[6 * c6_em_i10 + c6_em_i11];
      c6_b_y[c6_em_i10][c6_em_i11] = 0.0;
      c6_b_A[c6_em_i10][c6_em_i11] = c6_b_x[c6_em_i10][c6_em_i11];
      c6_c_A[c6_em_i10][c6_em_i11] = c6_b_A[c6_em_i10][c6_em_i11];
    }
  }
  for(c6_em_i12 = 0; c6_em_i12 < 6; c6_em_i12 = c6_em_i12 + 1) {
    c6_pivot[c6_em_i12][0] = 1.0 + (real_T)c6_em_i12;
  }
  for(c6_k = 1.0; c6_k <= 5.0; c6_k = c6_k + 1.0) {
    c6_b_k = c6_k;
    c6_p = c6_b_k;
    c6_c_x = c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
     (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) - 1][(int32_T)
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k),
     1, 6, 1) - 1];
    c6_c_y = fabs(c6_c_x);
    c6_maxval = c6_c_y;
    c6_em_d0 = c6_b_k + 1.0;
    for(c6_i = c6_em_d0; c6_i <= 6.0; c6_i = c6_i + 1.0) {
      c6_b_i = c6_i;
      c6_d_x = c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
       (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) - 1][(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i", c6_b_i),
       1, 6, 1) - 1];
      c6_d_y = fabs(c6_d_x);
      if(c6_d_y > c6_maxval) {
        c6_e_x = c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
          c6_b_i), 1, 6, 1) - 1];
        c6_e_y = fabs(c6_e_x);
        c6_maxval = c6_e_y;
        c6_p = c6_b_i;
      }
    }
    if(c6_p != c6_b_k) {
      for(c6_a = 1.0; c6_a <= 6.0; c6_a = c6_a + 1.0) {
        c6_b_a = c6_a;
        c6_temp = c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("a", c6_b_a), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("p", c6_p),
         1, 6, 1) - 1];
        c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("a", c6_b_a), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("p", c6_p),
         1, 6, 1) - 1] = c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK
          ("A", (int32_T)_SFD_INTEGER_CHECK("a", c6_b_a), 1, 6, 2) -
        1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
          "k", c6_b_k), 1, 6, 1) - 1];
        c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("a", c6_b_a), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k",
          c6_b_k), 1, 6, 1) - 1] = c6_temp;
      }
      c6_ptemp = (*(real_T
        (*)[6])&c6_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6
       , 1) - 1];
      (*(real_T (*)[6])&c6_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 1) - 1] =
        (*(real_T
        (*)[6])&c6_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("p", c6_p), 1, 6, 1) - 1];
      (*(real_T (*)[6])&c6_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("p", c6_p), 1, 6, 1) - 1] =
        c6_ptemp;
    }
    if(c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
      (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) - 1][(int32_T)
     _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k),
      1, 6, 1) - 1] != 0.0) {
      c6_em_d1 = c6_b_k + 1.0;
      for(c6_c_i = c6_em_d1; c6_c_i <= 6.0; c6_c_i = c6_c_i + 1.0) {
        c6_b_i = c6_c_i;
        c6_d_A = c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
          c6_b_i), 1, 6, 1) - 1];
        c6_b_B = c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k",
          c6_b_k), 1, 6, 1) - 1];
        c6_f_x = c6_d_A;
        c6_f_y = c6_b_B;
        c6_z = c6_f_x / c6_f_y;
        c6_g_y = c6_z;
        c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
          c6_b_i), 1, 6, 1) - 1] = c6_g_y;
      }
      c6_em_d2 = c6_b_k + 1.0;
      for(c6_j = c6_em_d2; c6_j <= 6.0; c6_j = c6_j + 1.0) {
        c6_b_j = c6_j;
        c6_em_d3 = c6_b_k + 1.0;
        for(c6_d_i = c6_em_d3; c6_d_i <= 6.0; c6_d_i = c6_d_i + 1.0) {
          c6_b_i = c6_d_i;
          c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
           (int32_T)_SFD_INTEGER_CHECK("j", c6_b_j), 1, 6, 2) - 1][(int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
            c6_b_i), 1, 6, 1) - 1] = c6_c_A[(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("j",
            c6_b_j), 1, 6, 2) - 1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (
            int32_T)_SFD_INTEGER_CHECK("i", c6_b_i), 1, 6, 1) - 1] -
          c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
           _SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 2) -
          1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
           (int32_T)_SFD_INTEGER_CHECK("i", c6_b_i), 1
           , 6, 1) - 1] * c6_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
           (int32_T)_SFD_INTEGER_CHECK("j", c6_b_j), 1, 6, 2) - 1][(int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k",
            c6_b_k), 1, 6, 1) - 1];
        }
      }
    }
  }
  for(c6_em_i13 = 0; c6_em_i13 < 6; c6_em_i13 = c6_em_i13 + 1) {
    for(c6_em_i14 = 0; c6_em_i14 < 6; c6_em_i14 = c6_em_i14 + 1) {
      c6_g_x[c6_em_i13][c6_em_i14] = c6_c_A[c6_em_i13][c6_em_i14];
    }
  }
  for(c6_em_i15 = 0; c6_em_i15 < 6; c6_em_i15 = c6_em_i15 + 1) {
    c6_b_p[c6_em_i15][0] = c6_pivot[c6_em_i15][0];
  }
  for(c6_em_i16 = 0; c6_em_i16 < 6; c6_em_i16 = c6_em_i16 + 1) {
    for(c6_em_i17 = 0; c6_em_i17 < 6; c6_em_i17 = c6_em_i17 + 1) {
      c6_b_x[c6_em_i16][c6_em_i17] = c6_g_x[c6_em_i16][c6_em_i17];
    }
  }
  c6_c_k = 1.0;
  label_1:;
  if(c6_c_k <= 6.0) {
    c6_d_k = c6_c_k;
    if(c6_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
      (int32_T)_SFD_INTEGER_CHECK("k", c6_d_k), 1, 6, 2) - 1][(int32_T)
     _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k", c6_d_k),
      1, 6, 1) - 1] == 0.0) {
    } else {
      c6_h_x = c6_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
       (int32_T)_SFD_INTEGER_CHECK("k", c6_d_k), 1, 6, 2) - 1][(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k", c6_d_k),
       1, 6, 1) - 1];
      c6_b = rtIsNaN(c6_h_x);
      if(c6_b) {
      } else {
        c6_c_k = c6_c_k + 1.0;
        goto label_1;
      }
    }
  } else {
    for(c6_e_k = 1.0; c6_e_k <= 6.0; c6_e_k = c6_e_k + 1.0) {
      c6_d_k = c6_e_k;
      c6_c = (*(real_T (*)[6])&c6_b_p)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("p",
       (int32_T)_SFD_INTEGER_CHECK("k", c6_d_k), 1, 6, 1) - 1];
      c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
       (int32_T)_SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) - 1][(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c6_d_k),
       1, 6, 1) - 1] = 1.0;
      c6_em_d4 = c6_d_k;
      for(c6_c_j = c6_em_d4; c6_c_j <= 6.0; c6_c_j = c6_c_j + 1.0) {
        c6_d_j = c6_c_j;
        if(c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
          (int32_T)_SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) - 1][(int32_T)
         _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
           c6_d_j), 1, 6, 1) - 1] != 0.0) {
          c6_em_d5 = c6_d_j + 1.0;
          for(c6_e_i = c6_em_d5; c6_e_i <= 6.0; c6_e_i = c6_e_i + 1.0) {
            c6_f_i = c6_e_i;
            c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
             (int32_T)_SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) - 1][(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("i",
              c6_f_i), 1, 6, 1) - 1] = c6_b_y[(int32_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
              c6_c), 1, 6, 2) - 1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", (
              int32_T)_SFD_INTEGER_CHECK("i", c6_f_i), 1, 6, 1) - 1] -
            c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
             _SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) -
            1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
             (int32_T)_SFD_INTEGER_CHECK("j", c6_d_j), 1,
             6, 1) - 1] * c6_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
             (int32_T)_SFD_INTEGER_CHECK("j", c6_d_j), 1, 6, 2) - 1][(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("i",
              c6_f_i), 1, 6, 1) - 1];
          }
        }
      }
      for(c6_e_j = 6.0; c6_e_j >= 1.0; c6_e_j = c6_e_j + -1.0) {
        c6_d_j = c6_e_j;
        c6_e_A = c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
         (int32_T)_SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
          c6_d_j), 1, 6, 1) - 1];
        c6_c_B = c6_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
         (int32_T)_SFD_INTEGER_CHECK("j", c6_d_j), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("j",
          c6_d_j), 1, 6, 1) - 1];
        c6_i_x = c6_e_A;
        c6_i_y = c6_c_B;
        c6_b_z = c6_i_x / c6_i_y;
        c6_j_y = c6_b_z;
        c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
         (int32_T)_SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
          c6_d_j), 1, 6, 1) - 1] = c6_j_y;
        if(c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
          (int32_T)_SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) - 1][(int32_T)
         _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
           c6_d_j), 1, 6, 1) - 1] != 0.0) {
          c6_f_j = c6_d_j - 1.0;
          for(c6_g_i = 1.0; c6_g_i <= c6_f_j; c6_g_i = c6_g_i + 1.0) {
            c6_f_i = c6_g_i;
            c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
             (int32_T)_SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) - 1][(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("i",
              c6_f_i), 1, 6, 1) - 1] = c6_b_y[(int32_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
              c6_c), 1, 6, 2) - 1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", (
              int32_T)_SFD_INTEGER_CHECK("i", c6_f_i), 1, 6, 1) - 1] -
            c6_b_y[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
             _SFD_INTEGER_CHECK("c", c6_c), 1, 6, 2) -
            1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
             (int32_T)_SFD_INTEGER_CHECK("j", c6_d_j), 1,
             6, 1) - 1] * c6_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
             (int32_T)_SFD_INTEGER_CHECK("j", c6_d_j), 1, 6, 2) - 1][(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("i",
              c6_f_i), 1, 6, 1) - 1];
          }
        }
      }
    }
    goto label_2;
  }
  c6_h_y = rtInf;
  for(c6_em_i18 = 0; c6_em_i18 < 36; c6_em_i18 = c6_em_i18 + 1) {
    (*(real_T (*)[36])&c6_b_y)[c6_em_i18] = c6_h_y;
  }
  label_2:;
  for(c6_em_i19 = 0; c6_em_i19 < 6; c6_em_i19 = c6_em_i19 + 1) {
    for(c6_em_i20 = 0; c6_em_i20 < 6; c6_em_i20 = c6_em_i20 + 1) {
      c6_y[6 * c6_em_i19 + c6_em_i20] = c6_b_y[c6_em_i19][c6_em_i20];
      c6_j_x[c6_em_i19][c6_em_i20] = c6_x[6 * c6_em_i19 + c6_em_i20];
      c6_xinv[c6_em_i19][c6_em_i20] = c6_y[6 * c6_em_i19 + c6_em_i20];
    }
  }
  c6_f_A = 1.0;
  for(c6_em_i21 = 0; c6_em_i21 < 6; c6_em_i21 = c6_em_i21 + 1) {
    for(c6_em_i22 = 0; c6_em_i22 < 6; c6_em_i22 = c6_em_i22 + 1) {
      c6_k_x[c6_em_i21][c6_em_i22] = c6_j_x[c6_em_i21][c6_em_i22];
      c6_b_xinv[c6_em_i21][c6_em_i22] = c6_xinv[c6_em_i21][c6_em_i22];
    }
  }
  c6_d_B = c6_norm((real_T *)c6_k_x) * c6_norm((real_T *)c6_b_xinv);
  c6_l_x = c6_f_A;
  c6_k_y = c6_d_B;
  c6_c_z = c6_l_x / c6_k_y;
  c6_l_y = c6_c_z;
  c6_rcond = c6_l_y;
  if(c6_rcond == 0.0) {
    sf_mex_call("warning", 0U, 1U, 15,
     "Matrix is singular to working precision.");
  } else {
    c6_m_x = c6_rcond;
    c6_b_b = rtIsNaN(c6_m_x);
    if(c6_b_b) {
    } else {
      c6_r = 2.2204460492503131E-016;
      if(c6_rcond < c6_r) {
      } else {
        return;
      }
    }
    for(c6_em_i23 = 0; c6_em_i23 < 103; c6_em_i23 = c6_em_i23 + 1) {
      c6_em_cv1[c6_em_i23][0] = c6_em_cv0[c6_em_i23][0];
    }
    sf_mex_call("warning", 0U, 2U, 14, sf_mex_create(&c6_em_cv1, "warning", 8,
      0U, 1U, 2, 1, 103), 6, c6_rcond);
  }
}

static real_T c6_norm(real_T *c6_x)
{
  int32_T c6_em_i24;
  int32_T c6_em_i25;
  real_T c6_b_x[6][6];
  real_T c6_zero;
  real_T c6_b_y;
  real_T c6_j;
  real_T c6_b_j;
  real_T c6_s;
  real_T c6_i;
  real_T c6_b_i;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_d_x;
  boolean_T c6_b;
  for(c6_em_i24 = 0; c6_em_i24 < 6; c6_em_i24 = c6_em_i24 + 1) {
    for(c6_em_i25 = 0; c6_em_i25 < 6; c6_em_i25 = c6_em_i25 + 1) {
      c6_b_x[c6_em_i24][c6_em_i25] = c6_x[6 * c6_em_i24 + c6_em_i25];
    }
  }
  c6_zero = 0.0;
  c6_b_y = c6_zero;
  c6_j = 1.0;
  label_1:;
  if(c6_j <= 6.0) {
    c6_b_j = c6_j;
    c6_s = c6_zero;
    for(c6_i = 1.0; c6_i <= 6.0; c6_i = c6_i + 1.0) {
      c6_b_i = c6_i;
      c6_c_x = c6_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
       (int32_T)_SFD_INTEGER_CHECK("j", c6_b_j), 1, 6, 2) - 1][(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("i", c6_b_i),
       1, 6, 1) - 1];
      c6_c_y = fabs(c6_c_x);
      c6_s = c6_s + c6_c_y;
    }
    c6_d_x = c6_s;
    c6_b = rtIsNaN(c6_d_x);
    if(c6_b) {
      c6_b_y = c6_s;
    } else {
      if(c6_s > c6_b_y) {
        c6_b_y = c6_s;
      }
      c6_j = c6_j + 1.0;
      goto label_1;
    }
  }
  return c6_b_y;
}

static real_T *c6_A(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real_T *c6_B(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real_T *c6_t(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static real_T *c6_a0(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real_T *c6_a1(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static real_T *c6_a2(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static real_T *c6_a3(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
}

static real_T *c6_a4(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
}

static real_T *c6_a5(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c6_trajectory_test(FILE *c6_file)
{
  fwrite(&chartInstance.c6_is_active_c6_trajectory_test, 1,
   sizeof(chartInstance.c6_is_active_c6_trajectory_test), c6_file);
}

static void sf_load_state_c6_trajectory_test(FILE *c6_file)
{
  fread(&chartInstance.c6_is_active_c6_trajectory_test, 1,
   sizeof(chartInstance.c6_is_active_c6_trajectory_test), c6_file);
}

/* SFunction Glue Code */
void sf_c6_trajectory_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3852960485U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1492775270U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2779657836U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3052545220U);
}

mxArray *sf_c6_trajectory_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1398833622U);
    pr[1] = (double)(2869068939U);
    pr[2] = (double)(242064090U);
    pr[3] = (double)(4021710387U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
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
         6,
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
          sf_debug_set_chart_disable_implicit_casting(_trajectory_testMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_trajectory_testMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"A",0);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"B",0);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t",0);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a0",0);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a1",0);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a2",0);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a3",0);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a4",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a5",0);
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,342);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(8U, c6_A());
        _SFD_SET_DATA_VALUE_PTR(1U, c6_B());
        _SFD_SET_DATA_VALUE_PTR(4U, c6_t());
        _SFD_SET_DATA_VALUE_PTR(2U, c6_a0());
        _SFD_SET_DATA_VALUE_PTR(7U, c6_a1());
        _SFD_SET_DATA_VALUE_PTR(5U, c6_a2());
        _SFD_SET_DATA_VALUE_PTR(3U, c6_a3());
        _SFD_SET_DATA_VALUE_PTR(6U, c6_a4());
        _SFD_SET_DATA_VALUE_PTR(0U, c6_a5());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_trajectory_testMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c6_trajectory_test(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c6_trajectory_test();
  initialize_c6_trajectory_test();
}

static void sf_opaque_enable_c6_trajectory_test(void *chartInstanceVar)
{
  enable_c6_trajectory_test();
}

static void sf_opaque_disable_c6_trajectory_test(void *chartInstanceVar)
{
  disable_c6_trajectory_test();
}

static void sf_opaque_gateway_c6_trajectory_test(void *chartInstanceVar)
{
  sf_c6_trajectory_test();
}

static void sf_opaque_terminate_c6_trajectory_test(void *chartInstanceVar)
{
  finalize_c6_trajectory_test();
}

static void mdlProcessParameters_c6_trajectory_test(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c6_trajectory_test();
}

static void mdlSetWorkWidths_c6_trajectory_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("trajectory_test",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("trajectory_test",6,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"trajectory_test",6,3);
      sf_mark_chart_reusable_outputs(S,"trajectory_test",6,6);
    }
    if (!sf_is_chart_instance_optimized_out("trajectory_test",6)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("trajectory_test",6);
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

  ssSetChecksum0(S,(3377461026U));
  ssSetChecksum1(S,(150108156U));
  ssSetChecksum2(S,(1753973591U));
  ssSetChecksum3(S,(1089863391U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_trajectory_test(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "trajectory_test", 6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void sf_save_debug_c6_trajectory_test(SFc6_trajectory_testInstanceStruct*
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
static void sf_load_debug_c6_trajectory_test(SFc6_trajectory_testInstanceStruct*
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
static void sf_c6_trajectory_test_sim_ctx_io(SimStruct* S, const char io, FILE*
 file)
{
  if(io == 'r') {
    sf_load_state_c6_trajectory_test(file);
    sf_load_debug_c6_trajectory_test(&chartInstance, file);
  } else {
    sf_save_state_c6_trajectory_test(file);
    sf_save_debug_c6_trajectory_test(&chartInstance, file);
  }
}
static void mdlStart_c6_trajectory_test(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_trajectory_test;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c6_trajectory_test;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c6_trajectory_test;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c6_trajectory_test;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c6_trajectory_test;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c6_trajectory_test;
  chartInstance.chartInfo.mdlStart = mdlStart_c6_trajectory_test;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_trajectory_test;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c6_trajectory_test_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c6_trajectory_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_trajectory_test(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_trajectory_test(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_trajectory_test(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c6_trajectory_test_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

