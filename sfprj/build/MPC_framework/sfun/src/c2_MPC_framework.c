/* Include files */
#include "MPC_framework_sfun.h"
#include "c2_MPC_framework.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "MPC_framework_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_MPC_frameworkInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_MPC_framework(void);
static void initialize_params_c2_MPC_framework(void);
static void enable_c2_MPC_framework(void);
static void disable_c2_MPC_framework(void);
static void finalize_c2_MPC_framework(void);
static void sf_c2_MPC_framework(void);
static void c2_c2_MPC_framework(void);
static real32_T c2_mpower(real32_T c2_a);
static real32_T c2_atan2(real32_T c2_Y, real32_T c2_X);
static real32_T c2_sign(real32_T c2_X);
static real32_T *c2_x(void);
static real32_T *c2_y(void);
static real32_T *c2_al1_c(void);
static real32_T *c2_al2_c(void);
static real32_T *c2_a1(void);
static real32_T *c2_a2(void);
static real32_T *c2_al1(void);
static real32_T *c2_al2(void);
static uint8_T *c2_error(void);
static void init_dsm_address_info(void);
static void sf_save_state_c2_MPC_framework(FILE *c2_file);
static void sf_load_state_c2_MPC_framework(FILE *c2_file);

/* Function Definitions */
static void initialize_c2_MPC_framework(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_MPC_framework = 0U;
}

static void initialize_params_c2_MPC_framework(void)
{
}

static void enable_c2_MPC_framework(void)
{
}

static void disable_c2_MPC_framework(void)
{
}

static void finalize_c2_MPC_framework(void)
{
}

static void sf_c2_MPC_framework(void)
{
  uint8_T c2_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_x(), 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_y(), 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_al1_c(), 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_al2_c(), 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_a1(), 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_a2(), 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_al1(), 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_al2(), 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_error(), 7U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_MPC_framework();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_MPC_frameworkMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c2_c2_MPC_framework(void)
{
  real32_T c2_b_x;
  real32_T c2_b_y;
  real32_T c2_b_al1_c;
  real32_T c2_b_al2_c;
  real32_T c2_b_a1;
  real32_T c2_b_a2;
  real32_T c2_al2_2;
  real32_T c2_al1_al2_2;
  real32_T c2_sin_al1_al2_2;
  real32_T c2_cos_al1_al2_2;
  real32_T c2_al2_1;
  real32_T c2_al1_al2_1;
  real32_T c2_sin_al1_al2_1;
  real32_T c2_cos_al1_al2_1;
  real32_T c2_al2_n;
  real32_T c2_al2_p;
  real32_T c2_al1_2;
  real32_T c2_al1_1;
  real32_T c2_cos_al1_n;
  real32_T c2_cos_al1_p;
  real32_T c2_sin_al1_n;
  real32_T c2_sin_al1_p;
  real32_T c2_D;
  real32_T c2_cos_al2;
  real32_T c2_d;
  uint8_T c2_b_error;
  real32_T c2_b_al2;
  real32_T c2_b_al1;
  real32_T c2_c_x;
  real32_T c2_c_y;
  boolean_T c2_em_b0;
  boolean_T c2_em_b1;
  real32_T c2_A;
  real32_T c2_B;
  real32_T c2_d_x;
  real32_T c2_d_y;
  real32_T c2_z;
  real32_T c2_e_y;
  real32_T c2_e_x;
  real32_T c2_f_y;
  real32_T c2_b_A;
  real32_T c2_b_B;
  real32_T c2_f_x;
  real32_T c2_g_y;
  real32_T c2_b_z;
  real32_T c2_h_y;
  real32_T c2_g_x;
  real32_T c2_i_y;
  real32_T c2_c_A;
  real32_T c2_c_B;
  real32_T c2_h_x;
  real32_T c2_j_y;
  real32_T c2_c_z;
  real32_T c2_k_y;
  real32_T c2_i_x;
  real32_T c2_l_y;
  real32_T c2_d_A;
  real32_T c2_d_B;
  real32_T c2_j_x;
  real32_T c2_m_y;
  real32_T c2_d_z;
  real32_T c2_n_y;
  real32_T c2_k_x;
  real32_T c2_o_y;
  real32_T c2_e_A;
  real32_T c2_e_B;
  real32_T c2_l_x;
  real32_T c2_p_y;
  real32_T c2_e_z;
  real32_T c2_q_y;
  real32_T c2_m_x;
  real_T c2_k;
  real_T c2_b_k;
  real32_T c2_r_y;
  real32_T c2_n_x;
  real32_T c2_s_y;
  real32_T c2_f_A;
  real32_T c2_f_B;
  real32_T c2_o_x;
  real32_T c2_t_y;
  real32_T c2_f_z;
  real32_T c2_u_y;
  real32_T c2_p_x;
  real32_T c2_v_y;
  real32_T c2_g_A;
  real32_T c2_g_B;
  real32_T c2_q_x;
  real32_T c2_w_y;
  real32_T c2_g_z;
  real32_T c2_x_y;
  real32_T c2_r_x;
  real32_T c2_y_y;
  real32_T c2_h_A;
  real32_T c2_h_B;
  real32_T c2_s_x;
  real32_T c2_ab_y;
  real32_T c2_h_z;
  real32_T c2_bb_y;
  real32_T c2_t_x;
  real32_T c2_cb_y;
  real32_T c2_i_A;
  real32_T c2_i_B;
  real32_T c2_u_x;
  real32_T c2_db_y;
  real32_T c2_i_z;
  real32_T c2_eb_y;
  real32_T c2_v_x;
  real32_T c2_fb_y;
  real32_T c2_w_x;
  real32_T c2_gb_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  c2_b_x = *c2_x();
  c2_b_y = *c2_y();
  c2_b_al1_c = *c2_al1_c();
  c2_b_al2_c = *c2_al2_c();
  c2_b_a1 = *c2_a1();
  c2_b_a2 = *c2_a2();
  sf_debug_push_symbol_scope(28U, 0U);
  sf_debug_symbol_scope_add_symbol("al2_2", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_2, 0);
  sf_debug_symbol_scope_add_symbol("al1_al2_2", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_al1_al2_2, 0);
  sf_debug_symbol_scope_add_symbol("sin_al1_al2_2", 1, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c2_sin_al1_al2_2, 0);
  sf_debug_symbol_scope_add_symbol("cos_al1_al2_2", 1, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c2_cos_al1_al2_2, 0);
  sf_debug_symbol_scope_add_symbol("al2_1", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_1, 0);
  sf_debug_symbol_scope_add_symbol("al1_al2_1", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_al1_al2_1, 0);
  sf_debug_symbol_scope_add_symbol("sin_al1_al2_1", 1, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c2_sin_al1_al2_1, 0);
  sf_debug_symbol_scope_add_symbol("cos_al1_al2_1", 1, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c2_cos_al1_al2_1, 0);
  sf_debug_symbol_scope_add_symbol("al2_n", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_n, 0);
  sf_debug_symbol_scope_add_symbol("al2_p", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al2_p, 0);
  sf_debug_symbol_scope_add_symbol("al1_2", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al1_2, 0);
  sf_debug_symbol_scope_add_symbol("al1_1", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_al1_1, 0);
  sf_debug_symbol_scope_add_symbol("cos_al1_n", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_cos_al1_n, 0);
  sf_debug_symbol_scope_add_symbol("cos_al1_p", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_cos_al1_p, 0);
  sf_debug_symbol_scope_add_symbol("sin_al1_n", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_sin_al1_n, 0);
  sf_debug_symbol_scope_add_symbol("sin_al1_p", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_sin_al1_p, 0);
  sf_debug_symbol_scope_add_symbol("D", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_D, 0);
  sf_debug_symbol_scope_add_symbol("cos_al2", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_cos_al2, 0);
  sf_debug_symbol_scope_add_symbol("d", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_d, 0);
  sf_debug_symbol_scope_add_symbol("error", 3, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_b_error, 0);
  sf_debug_symbol_scope_add_symbol("al2", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_al2, 0);
  sf_debug_symbol_scope_add_symbol("al1", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_al1, 0);
  sf_debug_symbol_scope_add_symbol("a2", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_a2, 0);
  sf_debug_symbol_scope_add_symbol("a1", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_a1, 0);
  sf_debug_symbol_scope_add_symbol("al2_c", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_b_al2_c, 0);
  sf_debug_symbol_scope_add_symbol("al1_c", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c2_b_al1_c, 0);
  sf_debug_symbol_scope_add_symbol("y", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_y, 0);
  sf_debug_symbol_scope_add_symbol("x", 1, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_b_x, 0);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,3);
  c2_c_x = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
  c2_c_y = (real32_T)sqrt((real_T)c2_c_x);
  c2_d = c2_c_y;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c2_em_b0 = (c2_d > c2_b_a1 + c2_b_a2);
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
    c2_B = 2.0F * c2_b_a1 * c2_b_a2;
    c2_d_x = c2_A;
    c2_d_y = c2_B;
    c2_z = c2_d_x / c2_d_y;
    c2_e_y = c2_z;
    c2_cos_al2 = c2_e_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
    c2_D = c2_b_a1 + c2_b_a2 * c2_cos_al2;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,14);
    c2_e_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_f_y = (real32_T)sqrt((real_T)c2_e_x);
    c2_b_A = c2_D * c2_b_y + c2_b_x * c2_f_y;
    c2_b_B = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
    c2_f_x = c2_b_A;
    c2_g_y = c2_b_B;
    c2_b_z = c2_f_x / c2_g_y;
    c2_h_y = c2_b_z;
    c2_sin_al1_p = c2_h_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
    c2_g_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_i_y = (real32_T)sqrt((real_T)c2_g_x);
    c2_c_A = c2_D * c2_b_y - c2_b_x * c2_i_y;
    c2_c_B = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
    c2_h_x = c2_c_A;
    c2_j_y = c2_c_B;
    c2_c_z = c2_h_x / c2_j_y;
    c2_k_y = c2_c_z;
    c2_sin_al1_n = c2_k_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
    c2_i_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_l_y = (real32_T)sqrt((real_T)c2_i_x);
    c2_d_A = c2_D * c2_b_x + c2_b_y * c2_l_y;
    c2_d_B = c2_mpower(c2_b_x) + c2_mpower(c2_b_y);
    c2_j_x = c2_d_A;
    c2_m_y = c2_d_B;
    c2_d_z = c2_j_x / c2_m_y;
    c2_n_y = c2_d_z;
    c2_cos_al1_p = c2_n_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
    c2_k_x = (c2_mpower(c2_b_x) + c2_mpower(c2_b_y)) - c2_mpower(c2_D);
    c2_o_y = (real32_T)sqrt((real_T)c2_k_x);
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
    if((real_T)c2_m_x < -1.0) {
    } else {
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
       1, 1, 1);
      if((real_T)c2_m_x > 1.0) {
      } else {
        goto label_1;
      }
    }
    sf_mex_call("error", 0U, 1U, 15,
     "Domain error. To compute complex results from real x, use \'acos(complex(x))\'.");
    label_1:;
    c2_r_y = (real32_T)acos((real_T)c2_m_x);
    c2_al2_p = c2_r_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,25);
    c2_al2_n = -c2_al2_p;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,27);
    c2_n_x = c2_al1_1;
    c2_s_y = (real32_T)cos((real_T)c2_n_x);
    c2_f_A = c2_b_x - c2_b_a1 * c2_s_y;
    c2_f_B = c2_b_a2;
    c2_o_x = c2_f_A;
    c2_t_y = c2_f_B;
    c2_f_z = c2_o_x / c2_t_y;
    c2_u_y = c2_f_z;
    c2_cos_al1_al2_1 = c2_u_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,28);
    c2_p_x = c2_al1_1;
    c2_v_y = (real32_T)sin((real_T)c2_p_x);
    c2_g_A = c2_b_y - c2_b_a1 * c2_v_y;
    c2_g_B = c2_b_a2;
    c2_q_x = c2_g_A;
    c2_w_y = c2_g_B;
    c2_g_z = c2_q_x / c2_w_y;
    c2_x_y = c2_g_z;
    c2_sin_al1_al2_1 = c2_x_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
    c2_al1_al2_1 = c2_atan2(c2_sin_al1_al2_1, c2_cos_al1_al2_1);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,30);
    c2_al2_1 = c2_al1_al2_1 - c2_al1_1;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,32);
    c2_r_x = c2_al1_2;
    c2_y_y = (real32_T)cos((real_T)c2_r_x);
    c2_h_A = c2_b_x - c2_b_a1 * c2_y_y;
    c2_h_B = c2_b_a2;
    c2_s_x = c2_h_A;
    c2_ab_y = c2_h_B;
    c2_h_z = c2_s_x / c2_ab_y;
    c2_bb_y = c2_h_z;
    c2_cos_al1_al2_2 = c2_bb_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,33);
    c2_t_x = c2_al1_2;
    c2_cb_y = (real32_T)sin((real_T)c2_t_x);
    c2_i_A = c2_b_y - c2_b_a1 * c2_cb_y;
    c2_i_B = c2_b_a2;
    c2_u_x = c2_i_A;
    c2_db_y = c2_i_B;
    c2_i_z = c2_u_x / c2_db_y;
    c2_eb_y = c2_i_z;
    c2_sin_al1_al2_2 = c2_eb_y;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,34);
    c2_al1_al2_2 = c2_atan2(c2_sin_al1_al2_2, c2_cos_al1_al2_2);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
    c2_al2_2 = c2_al1_al2_2 - c2_al1_2;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,37);
    c2_v_x = c2_b_al1_c - c2_al1_1;
    c2_fb_y = (real32_T)fabs((real_T)c2_v_x);
    c2_w_x = c2_b_al1_c - c2_al1_2;
    c2_gb_y = (real32_T)fabs((real_T)c2_w_x);
    if(CV_EML_IF(0, 1, c2_fb_y < c2_gb_y)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,38);
      c2_b_al1 = c2_al1_1;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,39);
      c2_b_al2 = c2_al2_1;
    } else {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,41);
      c2_b_al1 = c2_al1_2;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,42);
      c2_b_al2 = c2_al2_2;
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,45);
    c2_b_error = 0U;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-45);
  sf_debug_pop_symbol_scope();
  *c2_al1() = c2_b_al1;
  *c2_al2() = c2_b_al2;
  *c2_error() = c2_b_error;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static real32_T c2_mpower(real32_T c2_a)
{
  real32_T c2_b_a;
  real_T c2_b;
  real_T c2_k;
  real_T c2_b_k;
  real32_T c2_b_x;
  real32_T c2_xk;
  real32_T c2_ak;
  real_T c2_c_x;
  real_T c2_b_xk;
  real_T c2_bk;
  real_T c2_d_x;
  real_T c2_b_y;
  real32_T c2_c_y;
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
  if((real_T)c2_ak < 0.0) {
    c2_d_x = c2_bk;
    c2_b_y = floor(c2_d_x);
    if(c2_b_y != c2_bk) {
      sf_mex_call("error", 0U, 1U, 15,
       "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
    }
  }
  _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k), 1,
   1, 1);
  c2_c_y = (real32_T)pow((real_T)c2_ak, c2_bk);
  return c2_c_y;
}

static real32_T c2_atan2(real32_T c2_Y, real32_T c2_X)
{
  real_T c2_k;
  real_T c2_b_k;
  real32_T c2_b_x;
  real32_T c2_xk;
  real32_T c2_yk;
  real32_T c2_c_x;
  real32_T c2_b_xk;
  real32_T c2_c_xk;
  real32_T c2_b_y;
  real32_T c2_d_x;
  real32_T c2_e_x;
  boolean_T c2_b;
  real32_T c2_f_x;
  boolean_T c2_b_b;
  real_T c2_g_x;
  real32_T c2_r;
  real32_T c2_c_y;
  real32_T c2_b_r;
  real32_T c2_h_x;
  boolean_T c2_c_b;
  real32_T c2_i_x;
  boolean_T c2_d_b;
  real32_T c2_j_x;
  real32_T c2_c_r;
  real_T c2_k_x;
  real32_T c2_d_r;
  real_T c2_l_x;
  real32_T c2_e_r;
  real32_T c2_m_x;
  real32_T c2_f_r;
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
  c2_b = rtIsNaN((real_T)c2_e_x);
  if(c2_b) {
    goto label_1;
  } else {
    c2_f_x = c2_b_y;
    c2_b_b = rtIsNaN((real_T)c2_f_x);
    if(c2_b_b) {
      goto label_1;
    } else {
      c2_h_x = c2_b_y;
      c2_c_b = rtIsInf((real_T)c2_h_x);
      if(c2_c_b) {
        c2_i_x = c2_d_x;
        c2_d_b = rtIsInf((real_T)c2_i_x);
        if(c2_d_b) {
          c2_j_x = (real32_T)atan2((real_T)c2_sign(c2_b_y),
           (real_T)c2_sign(c2_d_x));
          c2_c_r = c2_j_x;
          c2_b_r = c2_c_r;
          goto label_2;
        }
      }
    }
  }
  if((real_T)c2_d_x == 0.0) {
    if((real_T)c2_b_y > 0.0) {
      c2_k_x = 1.5707963267948966E+000;
      c2_d_r = (real32_T)c2_k_x;
      c2_b_r = c2_d_r;
    } else if((real_T)c2_b_y < 0.0) {
      c2_l_x = -1.5707963267948966E+000;
      c2_e_r = (real32_T)c2_l_x;
      c2_b_r = c2_e_r;
    } else {
      c2_b_r = 0.0F;
    }
  } else {
    c2_m_x = (real32_T)atan2((real_T)c2_b_y, (real_T)c2_d_x);
    c2_f_r = c2_m_x;
    c2_b_r = c2_f_r;
  }
  goto label_2;
  label_1:;
  c2_g_x = rtNaN;
  c2_r = (real32_T)c2_g_x;
  c2_c_y = c2_r;
  c2_b_r = c2_c_y;
  label_2:;
  return c2_b_r;
}

static real32_T c2_sign(real32_T c2_X)
{
  real32_T c2_S;
  real_T c2_k;
  real_T c2_b_k;
  real32_T c2_b_x;
  real32_T c2_c_x;
  boolean_T c2_b;
  real_T c2_b_y;
  c2_S = 0.0F;
  c2_k = 1.0;
  c2_b_k = c2_k;
  _SFD_EML_ARRAY_BOUNDS_CHECK("X", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k), 1,
   1, 1);
  c2_b_x = c2_X;
  c2_c_x = c2_b_x;
  c2_b = rtIsNaN((real_T)c2_c_x);
  if(c2_b) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
     1, 1, 1);
    c2_b_y = rtNaN;
    return (real32_T)c2_b_y;
  } else if((real_T)c2_b_x > 0.0) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
     1, 1, 1);
    return 1.0F;
  } else if((real_T)c2_b_x < 0.0) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("S", (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k),
     1, 1, 1);
    return -1.0F;
  }
  return c2_S;
}

static real32_T *c2_x(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real32_T *c2_y(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real32_T *c2_al1_c(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static real32_T *c2_al2_c(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 3);
}

static real32_T *c2_a1(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 4);
}

static real32_T *c2_a2(void)
{
  return (real32_T *)ssGetInputPortSignal(chartInstance.S, 5);
}

static real32_T *c2_al1(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real32_T *c2_al2(void)
{
  return (real32_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static uint8_T *c2_error(void)
{
  return (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c2_MPC_framework(FILE *c2_file)
{
  fwrite(&chartInstance.c2_is_active_c2_MPC_framework, 1,
   sizeof(chartInstance.c2_is_active_c2_MPC_framework), c2_file);
}

static void sf_load_state_c2_MPC_framework(FILE *c2_file)
{
  fread(&chartInstance.c2_is_active_c2_MPC_framework, 1,
   sizeof(chartInstance.c2_is_active_c2_MPC_framework), c2_file);
}

/* SFunction Glue Code */
void sf_c2_MPC_framework_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(976754495U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2450187096U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3761924733U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1321091409U);
}

mxArray *sf_c2_MPC_framework_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(376277256U);
    pr[1] = (double)(2338174529U);
    pr[2] = (double)(4164341131U);
    pr[3] = (double)(1132625652U);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
          sf_debug_initialize_chart(_MPC_frameworkMachineNumber_,
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
          sf_debug_set_chart_disable_implicit_casting(_MPC_frameworkMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_MPC_frameworkMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(6,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"x",0);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"y",0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"al1_c",0);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"al2_c",0);
          _SFD_SET_DATA_PROPS(8,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a1",0);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"a2",0);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"al1",0);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"al2",0);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"error",0);
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
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1296);
        _SFD_CV_INIT_EML_IF(0,0,98,133,1118,1263);
        _SFD_CV_INIT_EML_IF(0,1,1118,1162,1209,1263);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(6U, c2_x());
        _SFD_SET_DATA_VALUE_PTR(5U, c2_y());
        _SFD_SET_DATA_VALUE_PTR(0U, c2_al1_c());
        _SFD_SET_DATA_VALUE_PTR(1U, c2_al2_c());
        _SFD_SET_DATA_VALUE_PTR(8U, c2_a1());
        _SFD_SET_DATA_VALUE_PTR(3U, c2_a2());
        _SFD_SET_DATA_VALUE_PTR(2U, c2_al1());
        _SFD_SET_DATA_VALUE_PTR(4U, c2_al2());
        _SFD_SET_DATA_VALUE_PTR(7U, c2_error());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_MPC_frameworkMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_MPC_framework(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c2_MPC_framework();
  initialize_c2_MPC_framework();
}

static void sf_opaque_enable_c2_MPC_framework(void *chartInstanceVar)
{
  enable_c2_MPC_framework();
}

static void sf_opaque_disable_c2_MPC_framework(void *chartInstanceVar)
{
  disable_c2_MPC_framework();
}

static void sf_opaque_gateway_c2_MPC_framework(void *chartInstanceVar)
{
  sf_c2_MPC_framework();
}

static void sf_opaque_terminate_c2_MPC_framework(void *chartInstanceVar)
{
  finalize_c2_MPC_framework();
}

static void mdlProcessParameters_c2_MPC_framework(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c2_MPC_framework();
}

static void mdlSetWorkWidths_c2_MPC_framework(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("MPC_framework",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("MPC_framework",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"MPC_framework",2,6);
      sf_mark_chart_reusable_outputs(S,"MPC_framework",2,3);
    }
    if (!sf_is_chart_instance_optimized_out("MPC_framework",2)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("MPC_framework",2);
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

  ssSetChecksum0(S,(2390408860U));
  ssSetChecksum1(S,(1084335824U));
  ssSetChecksum2(S,(1294869783U));
  ssSetChecksum3(S,(1829175565U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_MPC_framework(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "MPC_framework", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void sf_save_debug_c2_MPC_framework(SFc2_MPC_frameworkInstanceStruct*
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
static void sf_load_debug_c2_MPC_framework(SFc2_MPC_frameworkInstanceStruct*
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
static void sf_c2_MPC_framework_sim_ctx_io(SimStruct* S, const char io, FILE*
 file)
{
  if(io == 'r') {
    sf_load_state_c2_MPC_framework(file);
    sf_load_debug_c2_MPC_framework(&chartInstance, file);
  } else {
    sf_save_state_c2_MPC_framework(file);
    sf_save_debug_c2_MPC_framework(&chartInstance, file);
  }
}
static void mdlStart_c2_MPC_framework(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_MPC_framework;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_MPC_framework;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_MPC_framework;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_MPC_framework;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_MPC_framework;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_MPC_framework;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_MPC_framework;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_MPC_framework;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c2_MPC_framework_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c2_MPC_framework_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_MPC_framework(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_MPC_framework(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_MPC_framework(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_MPC_framework_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

