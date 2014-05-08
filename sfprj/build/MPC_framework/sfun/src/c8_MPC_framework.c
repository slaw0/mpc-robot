/* Include files */
#include "MPC_framework_sfun.h"
#include "c8_MPC_framework.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "MPC_framework_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c8_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc8_MPC_frameworkInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c8_MPC_framework(void);
static void initialize_params_c8_MPC_framework(void);
static void enable_c8_MPC_framework(void);
static void disable_c8_MPC_framework(void);
static void finalize_c8_MPC_framework(void);
static void sf_c8_MPC_framework(void);
static real_T c8_mpower(real_T c8_a);
static real_T c8_b_mpower(real_T c8_a);
static real_T c8_c_mpower(real_T c8_a);
static void c8_invNxN(real_T *c8_x, real_T *c8_y);
static real_T c8_norm(real_T *c8_x);
static real32_T *c8_A(void);
static real32_T *c8_B(void);
static real_T *c8_t(void);
static real32_T *c8_a0(void);
static real32_T *c8_a1(void);
static real32_T *c8_a2(void);
static real32_T *c8_a3(void);
static real32_T *c8_a4(void);
static real32_T *c8_a5(void);
static void init_dsm_address_info(void);
static void sf_save_state_c8_MPC_framework(FILE *c8_file);
static void sf_load_state_c8_MPC_framework(FILE *c8_file);

/* Function Definitions */
static void initialize_c8_MPC_framework(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c8_is_active_c8_MPC_framework = 0U;
}

static void initialize_params_c8_MPC_framework(void)
{
}

static void enable_c8_MPC_framework(void)
{
}

static void disable_c8_MPC_framework(void)
{
}

static void finalize_c8_MPC_framework(void)
{
}

static void sf_c8_MPC_framework(void)
{
  uint8_T c8_previousEvent;
  real32_T c8_b_A;
  real32_T c8_b_B;
  real_T c8_b_t;
  real32_T c8_Ao[6];
  real_T c8_T[6][6];
  real32_T c8_b_a5;
  real32_T c8_b_a4;
  real32_T c8_b_a3;
  real32_T c8_b_a2;
  real32_T c8_b_a1;
  real32_T c8_b_a0;
  real_T c8_a;
  real_T c8_b_a;
  real_T c8_b;
  real_T c8_k;
  real_T c8_b_k;
  real_T c8_x;
  real_T c8_xk;
  real_T c8_ak;
  real_T c8_b_x;
  real_T c8_b_xk;
  real_T c8_bk;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_b_y;
  real_T c8_c;
  real_T c8_c_A;
  real_T c8_c_B;
  real_T c8_d_x;
  real_T c8_c_y;
  real_T c8_z;
  real_T c8_d_y;
  real_T c8_d_A;
  real_T c8_d_B;
  real_T c8_e_x;
  real_T c8_e_y;
  real_T c8_b_z;
  real_T c8_f_y;
  real_T c8_e_A;
  real_T c8_e_B;
  real_T c8_f_x;
  real_T c8_g_y;
  real_T c8_c_z;
  real_T c8_h_y;
  real_T c8_f_A;
  real_T c8_f_B;
  real_T c8_g_x;
  real_T c8_i_y;
  real_T c8_d_z;
  real_T c8_j_y;
  real_T c8_g_A;
  real_T c8_g_B;
  real_T c8_h_x;
  real_T c8_k_y;
  real_T c8_e_z;
  real_T c8_l_y;
  real_T c8_h_A;
  real_T c8_h_B;
  real_T c8_i_x;
  real_T c8_m_y;
  real_T c8_f_z;
  real_T c8_n_y;
  real_T c8_i_A;
  real_T c8_i_B;
  real_T c8_j_x;
  real_T c8_o_y;
  real_T c8_g_z;
  real_T c8_p_y;
  real_T c8_q_y[6][1];
  real_T c8_r_y[6][1];
  real_T c8_em_dv0[6][1];
  int32_T c8_em_i0;
  int32_T c8_em_i1;
  int32_T c8_em_i2;
  int32_T c8_em_i3;
  static real_T c8_em_dv1[6][1] = { { 0.0 }, { 0.0 }, { 0.0 }, { 0.0 }, { 0.0 },
    { 1.0 } };
  int32_T c8_em_i4;
  static real_T c8_em_dv2[6][1] = { { 0.0 }, { 0.0 }, { 0.0 }, { 0.0 }, { 1.0 },
    { 0.0 } };
  int32_T c8_em_i5;
  static real_T c8_em_dv3[6][1] = { { 0.0 }, { 0.0 }, { 0.0 }, { 1.0 }, { 0.0 },
    { 0.0 } };
  int32_T c8_em_i6;
  int32_T c8_em_i7;
  real_T c8_k_x[6][6];
  real_T c8_l_x[6][6];
  real_T c8_s_y[6][6];
  int32_T c8_em_i8;
  int32_T c8_em_i9;
  real_T c8_m_x[6][6];
  real_T c8_xinv[6][6];
  real_T c8_j_A;
  int32_T c8_em_i10;
  int32_T c8_em_i11;
  real_T c8_n_x[6][6];
  real_T c8_b_xinv[6][6];
  real_T c8_j_B;
  real_T c8_o_x;
  real_T c8_t_y;
  real_T c8_h_z;
  real_T c8_u_y;
  real_T c8_rcond;
  real_T c8_p_x;
  boolean_T c8_b_b;
  real_T c8_r;
  int32_T c8_em_i12;
  static char c8_em_cv0[103][1] = { { 'M' }, { 'a' }, { 't' }, { 'r' }, { 'i' },
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
  char c8_em_cv1[103][1];
  int32_T c8_em_i13;
  int32_T c8_em_i14;
  real32_T c8_v_y[6][6];
  real32_T c8_k_B[6];
  int32_T c8_em_i15;
  int32_T c8_em_i16;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_A(), 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_B(), 1U);
  _SFD_DATA_RANGE_CHECK(*c8_t(), 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a0(), 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a1(), 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a2(), 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a3(), 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a4(), 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a5(), 3U);
  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,5);
  c8_b_A = *c8_A();
  c8_b_B = *c8_B();
  c8_b_t = *c8_t();
  sf_debug_push_symbol_scope(11U, 0U);
  sf_debug_symbol_scope_add_symbol("Ao", 1, 1U, 6U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c8_Ao, 0);
  sf_debug_symbol_scope_add_symbol("T", 0, 2U, 6U, 6U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c8_T, 0);
  sf_debug_symbol_scope_add_symbol("a5", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_a5, 0);
  sf_debug_symbol_scope_add_symbol("a4", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_a4, 0);
  sf_debug_symbol_scope_add_symbol("a3", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_a3, 0);
  sf_debug_symbol_scope_add_symbol("a2", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_a2, 0);
  sf_debug_symbol_scope_add_symbol("a1", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_a1, 0);
  sf_debug_symbol_scope_add_symbol("a0", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_a0, 0);
  sf_debug_symbol_scope_add_symbol("t", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_t, 0);
  sf_debug_symbol_scope_add_symbol("B", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_B, 0);
  sf_debug_symbol_scope_add_symbol("A", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c8_b_A, 0);
  CV_EML_FCN(0, 0);
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c8_a = c8_b_t;
  c8_b_a = c8_a;
  c8_b = 5.0;
  c8_k = 1.0;
  c8_b_k = c8_k;
  c8_x = c8_b_a;
  c8_xk = c8_x;
  c8_ak = c8_xk;
  c8_b_x = c8_b;
  c8_b_xk = c8_b_x;
  c8_bk = c8_b_xk;
  if(c8_ak < 0.0) {
    c8_c_x = c8_bk;
    c8_y = floor(c8_c_x);
    if(c8_y != c8_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1,
   1, 1);
  c8_b_y = pow(c8_ak, c8_bk);
  c8_c = c8_b_y;
  c8_c_A = c8_c;
  c8_c_B = 20.0;
  c8_d_x = c8_c_A;
  c8_c_y = c8_c_B;
  c8_z = c8_d_x / c8_c_y;
  c8_d_y = c8_z;
  c8_d_A = c8_mpower(c8_b_t);
  c8_d_B = 12.0;
  c8_e_x = c8_d_A;
  c8_e_y = c8_d_B;
  c8_b_z = c8_e_x / c8_e_y;
  c8_f_y = c8_b_z;
  c8_e_A = c8_b_mpower(c8_b_t);
  c8_e_B = 6.0;
  c8_f_x = c8_e_A;
  c8_g_y = c8_e_B;
  c8_c_z = c8_f_x / c8_g_y;
  c8_h_y = c8_c_z;
  c8_f_A = c8_c_mpower(c8_b_t);
  c8_f_B = 2.0;
  c8_g_x = c8_f_A;
  c8_i_y = c8_f_B;
  c8_d_z = c8_g_x / c8_i_y;
  c8_j_y = c8_d_z;
  c8_g_A = c8_mpower(c8_b_t);
  c8_g_B = 4.0;
  c8_h_x = c8_g_A;
  c8_k_y = c8_g_B;
  c8_e_z = c8_h_x / c8_k_y;
  c8_l_y = c8_e_z;
  c8_h_A = c8_b_mpower(c8_b_t);
  c8_h_B = 3.0;
  c8_i_x = c8_h_A;
  c8_m_y = c8_h_B;
  c8_f_z = c8_i_x / c8_m_y;
  c8_n_y = c8_f_z;
  c8_i_A = c8_c_mpower(c8_b_t);
  c8_i_B = 2.0;
  c8_j_x = c8_i_A;
  c8_o_y = c8_i_B;
  c8_g_z = c8_j_x / c8_o_y;
  c8_p_y = c8_g_z;
  c8_q_y[0][0] = c8_d_y;
  c8_q_y[1][0] = c8_f_y;
  c8_q_y[2][0] = c8_h_y;
  c8_q_y[3][0] = c8_j_y;
  c8_q_y[4][0] = c8_b_t;
  c8_q_y[5][0] = 1.0;
  c8_r_y[0][0] = c8_l_y;
  c8_r_y[1][0] = c8_n_y;
  c8_r_y[2][0] = c8_p_y;
  c8_r_y[3][0] = c8_b_t;
  c8_r_y[4][0] = 1.0;
  c8_r_y[5][0] = 0.0;
  c8_em_dv0[0][0] = c8_b_mpower(c8_b_t);
  c8_em_dv0[1][0] = c8_c_mpower(c8_b_t);
  c8_em_dv0[2][0] = c8_b_t;
  c8_em_dv0[3][0] = 1.0;
  c8_em_dv0[4][0] = 0.0;
  c8_em_dv0[5][0] = 0.0;
  for(c8_em_i0 = 0; c8_em_i0 < 6; c8_em_i0 = c8_em_i0 + 1) {
    c8_T[c8_em_i0][0] = c8_q_y[c8_em_i0][0];
  }
  for(c8_em_i1 = 0; c8_em_i1 < 6; c8_em_i1 = c8_em_i1 + 1) {
    c8_T[c8_em_i1][1] = c8_r_y[c8_em_i1][0];
  }
  for(c8_em_i2 = 0; c8_em_i2 < 6; c8_em_i2 = c8_em_i2 + 1) {
    c8_T[c8_em_i2][2] = c8_em_dv0[c8_em_i2][0];
  }
  for(c8_em_i3 = 0; c8_em_i3 < 6; c8_em_i3 = c8_em_i3 + 1) {
    c8_T[c8_em_i3][3] = c8_em_dv1[c8_em_i3][0];
  }
  for(c8_em_i4 = 0; c8_em_i4 < 6; c8_em_i4 = c8_em_i4 + 1) {
    c8_T[c8_em_i4][4] = c8_em_dv2[c8_em_i4][0];
  }
  for(c8_em_i5 = 0; c8_em_i5 < 6; c8_em_i5 = c8_em_i5 + 1) {
    c8_T[c8_em_i5][5] = c8_em_dv3[c8_em_i5][0];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  for(c8_em_i6 = 0; c8_em_i6 < 6; c8_em_i6 = c8_em_i6 + 1) {
    for(c8_em_i7 = 0; c8_em_i7 < 6; c8_em_i7 = c8_em_i7 + 1) {
      c8_k_x[c8_em_i6][c8_em_i7] = c8_T[c8_em_i6][c8_em_i7];
      c8_l_x[c8_em_i6][c8_em_i7] = c8_k_x[c8_em_i6][c8_em_i7];
    }
  }
  c8_invNxN((real_T *)c8_l_x, (real_T *)c8_s_y);
  for(c8_em_i8 = 0; c8_em_i8 < 6; c8_em_i8 = c8_em_i8 + 1) {
    for(c8_em_i9 = 0; c8_em_i9 < 6; c8_em_i9 = c8_em_i9 + 1) {
      c8_m_x[c8_em_i8][c8_em_i9] = c8_k_x[c8_em_i8][c8_em_i9];
      c8_xinv[c8_em_i8][c8_em_i9] = c8_s_y[c8_em_i8][c8_em_i9];
    }
  }
  c8_j_A = 1.0;
  for(c8_em_i10 = 0; c8_em_i10 < 6; c8_em_i10 = c8_em_i10 + 1) {
    for(c8_em_i11 = 0; c8_em_i11 < 6; c8_em_i11 = c8_em_i11 + 1) {
      c8_n_x[c8_em_i10][c8_em_i11] = c8_m_x[c8_em_i10][c8_em_i11];
      c8_b_xinv[c8_em_i10][c8_em_i11] = c8_xinv[c8_em_i10][c8_em_i11];
    }
  }
  c8_j_B = c8_norm((real_T *)c8_n_x) * c8_norm((real_T *)c8_b_xinv);
  c8_o_x = c8_j_A;
  c8_t_y = c8_j_B;
  c8_h_z = c8_o_x / c8_t_y;
  c8_u_y = c8_h_z;
  c8_rcond = c8_u_y;
  if(c8_rcond == 0.0) {
    sf_mex_call("warning", 0U, 1U, 15,
     "Matrix is singular to working precision.");
  } else {
    c8_p_x = c8_rcond;
    c8_b_b = rtIsNaN(c8_p_x);
    if(c8_b_b) {
    } else {
      c8_r = 2.2204460492503131E-016;
      if(c8_rcond < c8_r) {
      } else {
        goto label_1;
      }
    }
    for(c8_em_i12 = 0; c8_em_i12 < 103; c8_em_i12 = c8_em_i12 + 1) {
      c8_em_cv1[c8_em_i12][0] = c8_em_cv0[c8_em_i12][0];
    }
    sf_mex_call("warning", 0U, 2U, 14, sf_mex_create(&c8_em_cv1, "warning", 8,
      0U, 1U, 2, 1, 103), 6, c8_rcond);
    label_1:;
  }
  for(c8_em_i13 = 0; c8_em_i13 < 6; c8_em_i13 = c8_em_i13 + 1) {
    for(c8_em_i14 = 0; c8_em_i14 < 6; c8_em_i14 = c8_em_i14 + 1) {
      c8_v_y[c8_em_i13][c8_em_i14] = (real32_T)c8_s_y[c8_em_i13][c8_em_i14];
    }
  }
  c8_k_B[0] = c8_b_B;
  c8_k_B[1] = 0.0F;
  c8_k_B[2] = 0.0F;
  c8_k_B[3] = c8_b_A;
  c8_k_B[4] = 0.0F;
  c8_k_B[5] = 0.0F;
  for(c8_em_i15 = 0; c8_em_i15 < 6; c8_em_i15 = c8_em_i15 + 1) {
    c8_Ao[c8_em_i15] = 0.0F;
    for(c8_em_i16 = 0; c8_em_i16 < 6; c8_em_i16 = c8_em_i16 + 1) {
      c8_Ao[c8_em_i15] = c8_Ao[c8_em_i15] + c8_v_y[c8_em_i16][c8_em_i15] *
        c8_k_B[c8_em_i16];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c8_b_a0 = c8_Ao[0];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  c8_b_a1 = c8_Ao[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
  c8_b_a2 = c8_Ao[2];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
  c8_b_a3 = c8_Ao[3];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  c8_b_a4 = c8_Ao[4];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  c8_b_a5 = c8_Ao[5];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-11);
  sf_debug_pop_symbol_scope();
  *c8_a0() = c8_b_a0;
  *c8_a1() = c8_b_a1;
  *c8_a2() = c8_b_a2;
  *c8_a3() = c8_b_a3;
  *c8_a4() = c8_b_a4;
  *c8_a5() = c8_b_a5;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
  _sfEvent_ = c8_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_frameworkMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static real_T c8_mpower(real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_b;
  real_T c8_k;
  real_T c8_b_k;
  real_T c8_x;
  real_T c8_xk;
  real_T c8_ak;
  real_T c8_b_x;
  real_T c8_b_xk;
  real_T c8_bk;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_b_y;
  c8_b_a = c8_a;
  c8_b = 4.0;
  c8_k = 1.0;
  c8_b_k = c8_k;
  c8_x = c8_b_a;
  c8_xk = c8_x;
  c8_ak = c8_xk;
  c8_b_x = c8_b;
  c8_b_xk = c8_b_x;
  c8_bk = c8_b_xk;
  if(c8_ak < 0.0) {
    c8_c_x = c8_bk;
    c8_y = floor(c8_c_x);
    if(c8_y != c8_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1,
   1, 1);
  c8_b_y = pow(c8_ak, c8_bk);
  return c8_b_y;
}

static real_T c8_b_mpower(real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_b;
  real_T c8_k;
  real_T c8_b_k;
  real_T c8_x;
  real_T c8_xk;
  real_T c8_ak;
  real_T c8_b_x;
  real_T c8_b_xk;
  real_T c8_bk;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_b_y;
  c8_b_a = c8_a;
  c8_b = 3.0;
  c8_k = 1.0;
  c8_b_k = c8_k;
  c8_x = c8_b_a;
  c8_xk = c8_x;
  c8_ak = c8_xk;
  c8_b_x = c8_b;
  c8_b_xk = c8_b_x;
  c8_bk = c8_b_xk;
  if(c8_ak < 0.0) {
    c8_c_x = c8_bk;
    c8_y = floor(c8_c_x);
    if(c8_y != c8_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1,
   1, 1);
  c8_b_y = pow(c8_ak, c8_bk);
  return c8_b_y;
}

static real_T c8_c_mpower(real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_b;
  real_T c8_k;
  real_T c8_b_k;
  real_T c8_x;
  real_T c8_xk;
  real_T c8_ak;
  real_T c8_b_x;
  real_T c8_b_xk;
  real_T c8_bk;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_b_y;
  c8_b_a = c8_a;
  c8_b = 2.0;
  c8_k = 1.0;
  c8_b_k = c8_k;
  c8_x = c8_b_a;
  c8_xk = c8_x;
  c8_ak = c8_xk;
  c8_b_x = c8_b;
  c8_b_xk = c8_b_x;
  c8_bk = c8_b_xk;
  if(c8_ak < 0.0) {
    c8_c_x = c8_bk;
    c8_y = floor(c8_c_x);
    if(c8_y != c8_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1,
   1, 1);
  c8_b_y = pow(c8_ak, c8_bk);
  return c8_b_y;
}

static void c8_invNxN(real_T *c8_x, real_T *c8_y)
{
  int32_T c8_em_i17;
  int32_T c8_em_i18;
  real_T c8_b_A[6][6];
  real_T c8_c_A[6][6];
  int32_T c8_em_i19;
  real_T c8_pivot[6][1];
  real_T c8_k;
  real_T c8_b_k;
  real_T c8_p;
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_maxval;
  real_T c8_em_d0;
  real_T c8_i;
  real_T c8_b_i;
  real_T c8_c_x;
  real_T c8_c_y;
  real_T c8_d_x;
  real_T c8_d_y;
  real_T c8_a;
  real_T c8_b_a;
  real_T c8_temp;
  real_T c8_ptemp;
  real_T c8_em_d1;
  real_T c8_c_i;
  real_T c8_d_A;
  real_T c8_b_B;
  real_T c8_e_x;
  real_T c8_e_y;
  real_T c8_z;
  real_T c8_f_y;
  real_T c8_em_d2;
  real_T c8_j;
  real_T c8_b_j;
  real_T c8_em_d3;
  real_T c8_d_i;
  int32_T c8_em_i20;
  int32_T c8_em_i21;
  real_T c8_f_x[6][6];
  int32_T c8_em_i22;
  real_T c8_b_p[6][1];
  int32_T c8_em_i23;
  int32_T c8_em_i24;
  real_T c8_c_k;
  real_T c8_d_k;
  real_T c8_g_x;
  boolean_T c8_b;
  real_T c8_g_y;
  int32_T c8_em_i25;
  real_T c8_e_k;
  real_T c8_c;
  real_T c8_em_d4;
  real_T c8_c_j;
  real_T c8_d_j;
  real_T c8_em_d5;
  real_T c8_e_i;
  real_T c8_f_i;
  real_T c8_e_j;
  real_T c8_e_A;
  real_T c8_c_B;
  real_T c8_h_x;
  real_T c8_h_y;
  real_T c8_b_z;
  real_T c8_i_y;
  real_T c8_f_j;
  real_T c8_g_i;
  for(c8_em_i17 = 0; c8_em_i17 < 6; c8_em_i17 = c8_em_i17 + 1) {
    for(c8_em_i18 = 0; c8_em_i18 < 6; c8_em_i18 = c8_em_i18 + 1) {
      c8_y[6 * c8_em_i17 + c8_em_i18] = 0.0;
      c8_b_A[c8_em_i17][c8_em_i18] = c8_x[6 * c8_em_i17 + c8_em_i18];
      c8_c_A[c8_em_i17][c8_em_i18] = c8_b_A[c8_em_i17][c8_em_i18];
    }
  }
  for(c8_em_i19 = 0; c8_em_i19 < 6; c8_em_i19 = c8_em_i19 + 1) {
    c8_pivot[c8_em_i19][0] = 1.0 + (real_T)c8_em_i19;
  }
  for(c8_k = 1.0; c8_k <= 5.0; c8_k = c8_k + 1.0) {
    c8_b_k = c8_k;
    c8_p = c8_b_k;
    c8_b_x = c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
     (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) - 1][(int32_T)
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k),
     1, 6, 1) - 1];
    c8_b_y = fabs(c8_b_x);
    c8_maxval = c8_b_y;
    c8_em_d0 = c8_b_k + 1.0;
    for(c8_i = c8_em_d0; c8_i <= 6.0; c8_i = c8_i + 1.0) {
      c8_b_i = c8_i;
      c8_c_x = c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
       (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) - 1][(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i", c8_b_i),
       1, 6, 1) - 1];
      c8_c_y = fabs(c8_c_x);
      if(c8_c_y > c8_maxval) {
        c8_d_x = c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
          c8_b_i), 1, 6, 1) - 1];
        c8_d_y = fabs(c8_d_x);
        c8_maxval = c8_d_y;
        c8_p = c8_b_i;
      }
    }
    if(c8_p != c8_b_k) {
      for(c8_a = 1.0; c8_a <= 6.0; c8_a = c8_a + 1.0) {
        c8_b_a = c8_a;
        c8_temp = c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("a", c8_b_a), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("p", c8_p),
         1, 6, 1) - 1];
        c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("a", c8_b_a), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("p", c8_p),
         1, 6, 1) - 1] = c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK
          ("A", (int32_T)_SFD_INTEGER_CHECK("a", c8_b_a), 1, 6, 2) -
        1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
          "k", c8_b_k), 1, 6, 1) - 1];
        c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("a", c8_b_a), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k",
          c8_b_k), 1, 6, 1) - 1] = c8_temp;
      }
      c8_ptemp = (*(real_T
        (*)[6])&c8_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6
       , 1) - 1];
      (*(real_T (*)[6])&c8_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 1) - 1] =
        (*(real_T
        (*)[6])&c8_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("p", c8_p), 1, 6, 1) - 1];
      (*(real_T (*)[6])&c8_pivot)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("pivot",
       (int32_T)_SFD_INTEGER_CHECK("p", c8_p), 1, 6, 1) - 1] =
        c8_ptemp;
    }
    if(c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
      (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) - 1][(int32_T)
     _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k),
      1, 6, 1) - 1] != 0.0) {
      c8_em_d1 = c8_b_k + 1.0;
      for(c8_c_i = c8_em_d1; c8_c_i <= 6.0; c8_c_i = c8_c_i + 1.0) {
        c8_b_i = c8_c_i;
        c8_d_A = c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
          c8_b_i), 1, 6, 1) - 1];
        c8_b_B = c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k",
          c8_b_k), 1, 6, 1) - 1];
        c8_e_x = c8_d_A;
        c8_e_y = c8_b_B;
        c8_z = c8_e_x / c8_e_y;
        c8_f_y = c8_z;
        c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) - 1][(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
          c8_b_i), 1, 6, 1) - 1] = c8_f_y;
      }
      c8_em_d2 = c8_b_k + 1.0;
      for(c8_j = c8_em_d2; c8_j <= 6.0; c8_j = c8_j + 1.0) {
        c8_b_j = c8_j;
        c8_em_d3 = c8_b_k + 1.0;
        for(c8_d_i = c8_em_d3; c8_d_i <= 6.0; c8_d_i = c8_d_i + 1.0) {
          c8_b_i = c8_d_i;
          c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
           (int32_T)_SFD_INTEGER_CHECK("j", c8_b_j), 1, 6, 2) - 1][(int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
            c8_b_i), 1, 6, 1) - 1] = c8_c_A[(int32_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("j",
            c8_b_j), 1, 6, 2) - 1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (
            int32_T)_SFD_INTEGER_CHECK("i", c8_b_i), 1, 6, 1) - 1] -
          c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
           _SFD_INTEGER_CHECK("k", c8_b_k), 1, 6, 2) -
          1][(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
           (int32_T)_SFD_INTEGER_CHECK("i", c8_b_i), 1
           , 6, 1) - 1] * c8_c_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
           (int32_T)_SFD_INTEGER_CHECK("j", c8_b_j), 1, 6, 2) - 1][(int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("k",
            c8_b_k), 1, 6, 1) - 1];
        }
      }
    }
  }
  for(c8_em_i20 = 0; c8_em_i20 < 6; c8_em_i20 = c8_em_i20 + 1) {
    for(c8_em_i21 = 0; c8_em_i21 < 6; c8_em_i21 = c8_em_i21 + 1) {
      c8_f_x[c8_em_i20][c8_em_i21] = c8_c_A[c8_em_i20][c8_em_i21];
    }
  }
  for(c8_em_i22 = 0; c8_em_i22 < 6; c8_em_i22 = c8_em_i22 + 1) {
    c8_b_p[c8_em_i22][0] = c8_pivot[c8_em_i22][0];
  }
  for(c8_em_i23 = 0; c8_em_i23 < 6; c8_em_i23 = c8_em_i23 + 1) {
    for(c8_em_i24 = 0; c8_em_i24 < 6; c8_em_i24 = c8_em_i24 + 1) {
      c8_x[6 * c8_em_i23 + c8_em_i24] = c8_f_x[c8_em_i23][c8_em_i24];
    }
  }
  c8_c_k = 1.0;
  label_1:;
  if(c8_c_k <= 6.0) {
    c8_d_k = c8_c_k;
    if(c8_x[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
       (int32_T)_SFD_INTEGER_CHECK("k", c8_d_k), 1, 6, 2) - 1) + ((int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k", c8_d_k),
       1, 6, 1) - 1)] == 0.0) {
    } else {
      c8_g_x = c8_x[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
        (int32_T)_SFD_INTEGER_CHECK("k", c8_d_k), 1, 6, 2) - 1) + ((int32_T)
       _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k",
         c8_d_k), 1, 6, 1) - 1)];
      c8_b = rtIsNaN(c8_g_x);
      if(c8_b) {
      } else {
        c8_c_k = c8_c_k + 1.0;
        goto label_1;
      }
    }
  } else {
    for(c8_e_k = 1.0; c8_e_k <= 6.0; c8_e_k = c8_e_k + 1.0) {
      c8_d_k = c8_e_k;
      c8_c = (*(real_T (*)[6])&c8_b_p)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("p",
       (int32_T)_SFD_INTEGER_CHECK("k", c8_d_k), 1, 6, 1) - 1];
      c8_y[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
        (int32_T)_SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) + ((int32_T)
       _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k",
         c8_d_k), 1, 6, 1) - 1)] = 1.0;
      c8_em_d4 = c8_d_k;
      for(c8_c_j = c8_em_d4; c8_c_j <= 6.0; c8_c_j = c8_c_j + 1.0) {
        c8_d_j = c8_c_j;
        if(c8_y[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
           (int32_T)_SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) + ((int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
            c8_d_j), 1, 6, 1) - 1)] != 0.0) {
          c8_em_d5 = c8_d_j + 1.0;
          for(c8_e_i = c8_em_d5; c8_e_i <= 6.0; c8_e_i = c8_e_i + 1.0) {
            c8_f_i = c8_e_i;
            c8_y[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
              (int32_T)_SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) + ((int32_T)
             _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("i",
               c8_f_i), 1, 6, 1) - 1)] = c8_y[6 * ((int32_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
               c8_c), 1, 6, 2) - 1) + ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",

              (int32_T)_SFD_INTEGER_CHECK("i", c8_f_i), 1, 6, 1) - 1)] - c8_y[6
            * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
              _SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) +
            ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
              (int32_T)_SFD_INTEGER_CHECK("j", c8_d_j),
              1, 6, 1) - 1)] * c8_x[6 *
            ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
              (int32_T)_SFD_INTEGER_CHECK("j", c8_d_j), 1, 6, 2) - 1) + ((
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
              (int32_T)_SFD_INTEGER_CHECK("i", c8_f_i), 1, 6, 1) - 1)];
          }
        }
      }
      for(c8_e_j = 6.0; c8_e_j >= 1.0; c8_e_j = c8_e_j + -1.0) {
        c8_d_j = c8_e_j;
        c8_e_A = c8_y[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
          (int32_T)_SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) + ((int32_T)
         _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
           c8_d_j), 1, 6, 1) - 1)];
        c8_c_B = c8_x[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
          (int32_T)_SFD_INTEGER_CHECK("j", c8_d_j), 1, 6, 2) - 1) + ((int32_T)
         _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("j",
           c8_d_j), 1, 6, 1) - 1)];
        c8_h_x = c8_e_A;
        c8_h_y = c8_c_B;
        c8_b_z = c8_h_x / c8_h_y;
        c8_i_y = c8_b_z;
        c8_y[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
          (int32_T)_SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) + ((int32_T)
         _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
           c8_d_j), 1, 6, 1) - 1)] = c8_i_y;
        if(c8_y[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
           (int32_T)_SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) + ((int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
            c8_d_j), 1, 6, 1) - 1)] != 0.0) {
          c8_f_j = c8_d_j - 1.0;
          for(c8_g_i = 1.0; c8_g_i <= c8_f_j; c8_g_i = c8_g_i + 1.0) {
            c8_f_i = c8_g_i;
            c8_y[6 * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
              (int32_T)_SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) + ((int32_T)
             _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("i",
               c8_f_i), 1, 6, 1) - 1)] = c8_y[6 * ((int32_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
               c8_c), 1, 6, 2) - 1) + ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",

              (int32_T)_SFD_INTEGER_CHECK("i", c8_f_i), 1, 6, 1) - 1)] - c8_y[6
            * ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
              _SFD_INTEGER_CHECK("c", c8_c), 1, 6, 2) - 1) +
            ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
              (int32_T)_SFD_INTEGER_CHECK("j", c8_d_j),
              1, 6, 1) - 1)] * c8_x[6 *
            ((int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
              (int32_T)_SFD_INTEGER_CHECK("j", c8_d_j), 1, 6, 2) - 1) + ((
              int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
              (int32_T)_SFD_INTEGER_CHECK("i", c8_f_i), 1, 6, 1) - 1)];
          }
        }
      }
    }
    return;
  }
  c8_g_y = rtInf;
  for(c8_em_i25 = 0; c8_em_i25 < 36; c8_em_i25 = c8_em_i25 + 1) {
    (*(real_T (*)[36])c8_y)[c8_em_i25] = c8_g_y;
  }
}

static real_T c8_norm(real_T *c8_x)
{
  int32_T c8_em_i26;
  int32_T c8_em_i27;
  real_T c8_b_x[6][6];
  real_T c8_zero;
  real_T c8_b_y;
  real_T c8_j;
  real_T c8_b_j;
  real_T c8_s;
  real_T c8_i;
  real_T c8_b_i;
  real_T c8_c_x;
  real_T c8_c_y;
  real_T c8_d_x;
  boolean_T c8_b;
  for(c8_em_i26 = 0; c8_em_i26 < 6; c8_em_i26 = c8_em_i26 + 1) {
    for(c8_em_i27 = 0; c8_em_i27 < 6; c8_em_i27 = c8_em_i27 + 1) {
      c8_b_x[c8_em_i26][c8_em_i27] = c8_x[6 * c8_em_i26 + c8_em_i27];
    }
  }
  c8_zero = 0.0;
  c8_b_y = c8_zero;
  c8_j = 1.0;
  label_1:;
  if(c8_j <= 6.0) {
    c8_b_j = c8_j;
    c8_s = c8_zero;
    for(c8_i = 1.0; c8_i <= 6.0; c8_i = c8_i + 1.0) {
      c8_b_i = c8_i;
      c8_c_x = c8_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
       (int32_T)_SFD_INTEGER_CHECK("j", c8_b_j), 1, 6, 2) - 1][(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("i", c8_b_i),
       1, 6, 1) - 1];
      c8_c_y = fabs(c8_c_x);
      c8_s = c8_s + c8_c_y;
    }
    c8_d_x = c8_s;
    c8_b = rtIsNaN(c8_d_x);
    if(c8_b) {
      c8_b_y = c8_s;
    } else {
      if(c8_s > c8_b_y) {
        c8_b_y = c8_s;
      }
      c8_j = c8_j + 1.0;
      goto label_1;
    }
  }
  return c8_b_y;
}

static real32_T *c8_A(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real32_T *c8_B(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real_T *c8_t(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static real32_T *c8_a0(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real32_T *c8_a1(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static real32_T *c8_a2(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static real32_T *c8_a3(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 4);
}

static real32_T *c8_a4(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 5);
}

static real32_T *c8_a5(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 6);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c8_MPC_framework(FILE *c8_file)
{
  fwrite(&chartInstance.c8_is_active_c8_MPC_framework, 1,
   sizeof(chartInstance.c8_is_active_c8_MPC_framework), c8_file);
}

static void sf_load_state_c8_MPC_framework(FILE *c8_file)
{
  fread(&chartInstance.c8_is_active_c8_MPC_framework, 1,
   sizeof(chartInstance.c8_is_active_c8_MPC_framework), c8_file);
}

/* SFunction Glue Code */
void sf_c8_MPC_framework_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1927746154U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2851622619U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1769187543U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3893179994U);
}

mxArray *sf_c8_MPC_framework_get_autoinheritance_info(void)
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
          sf_debug_initialize_chart(_MPC_frameworkMachineNumber_,
         8,
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
          sf_debug_set_chart_disable_implicit_casting(_MPC_frameworkMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_MPC_frameworkMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"A",0);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"B",0);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"t",0);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a0",0);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a1",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a2",0);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a3",0);
          _SFD_SET_DATA_PROPS(8,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a4",0);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a5",0);
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
        _SFD_SET_DATA_VALUE_PTR(2U, c8_A());
        _SFD_SET_DATA_VALUE_PTR(1U, c8_B());
        _SFD_SET_DATA_VALUE_PTR(5U, c8_t());
        _SFD_SET_DATA_VALUE_PTR(7U, c8_a0());
        _SFD_SET_DATA_VALUE_PTR(6U, c8_a1());
        _SFD_SET_DATA_VALUE_PTR(0U, c8_a2());
        _SFD_SET_DATA_VALUE_PTR(4U, c8_a3());
        _SFD_SET_DATA_VALUE_PTR(8U, c8_a4());
        _SFD_SET_DATA_VALUE_PTR(3U, c8_a5());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_MPC_frameworkMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c8_MPC_framework(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c8_MPC_framework();
  initialize_c8_MPC_framework();
}

static void sf_opaque_enable_c8_MPC_framework(void *chartInstanceVar)
{
  enable_c8_MPC_framework();
}

static void sf_opaque_disable_c8_MPC_framework(void *chartInstanceVar)
{
  disable_c8_MPC_framework();
}

static void sf_opaque_gateway_c8_MPC_framework(void *chartInstanceVar)
{
  sf_c8_MPC_framework();
}

static void sf_opaque_terminate_c8_MPC_framework(void *chartInstanceVar)
{
  finalize_c8_MPC_framework();
}

static void mdlProcessParameters_c8_MPC_framework(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c8_MPC_framework();
}

static void mdlSetWorkWidths_c8_MPC_framework(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("MPC_framework",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("MPC_framework",8,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_framework",8,3);
      sf_mark_chart_reusable_outputs(S,"MPC_framework",8,6);
    }
    if (!sf_is_chart_instance_optimized_out("MPC_framework",8)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("MPC_framework",8);
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

  ssSetChecksum0(S,(1250168077U));
  ssSetChecksum1(S,(3637738057U));
  ssSetChecksum2(S,(4174540004U));
  ssSetChecksum3(S,(3132531198U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_MPC_framework(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MPC_framework", 8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void sf_save_debug_c8_MPC_framework(SFc8_MPC_frameworkInstanceStruct*
 chartInstance, FILE* file)
{
  int machineNumber = _MPC_frameworkMachineNumber_;
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
static void sf_load_debug_c8_MPC_framework(SFc8_MPC_frameworkInstanceStruct*
 chartInstance,FILE* file)
{
  int machineNumber = _MPC_frameworkMachineNumber_;
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
static void sf_c8_MPC_framework_sim_ctx_io(SimStruct* S, const char io, FILE*
 file)
{
  if(io == 'r') {
    sf_load_state_c8_MPC_framework(file);
    sf_load_debug_c8_MPC_framework(&chartInstance, file);
  } else {
    sf_save_state_c8_MPC_framework(file);
    sf_save_debug_c8_MPC_framework(&chartInstance, file);
  }
}
static void mdlStart_c8_MPC_framework(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c8_MPC_framework;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c8_MPC_framework;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c8_MPC_framework;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c8_MPC_framework;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c8_MPC_framework;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c8_MPC_framework;
  chartInstance.chartInfo.mdlStart = mdlStart_c8_MPC_framework;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_MPC_framework;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c8_MPC_framework_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c8_MPC_framework_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_MPC_framework(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_MPC_framework(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_MPC_framework(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c8_MPC_framework_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

