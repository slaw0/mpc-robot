/* Include files */

#include "blascompat32.h"
#include "controller_test_sfun.h"
#include "c8_controller_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[13] = { "T", "Ao", "nargin", "nargout",
  "A", "B", "t", "a0", "a1", "a2", "a3", "a4", "a5" };

/* Function Declarations */
static void initialize_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance);
static void initialize_params_c8_controller_test
  (SFc8_controller_testInstanceStruct *chartInstance);
static void enable_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance);
static void disable_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_controller_test
  (SFc8_controller_testInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_controller_test
  (SFc8_controller_testInstanceStruct *chartInstance);
static void set_sim_state_c8_controller_test(SFc8_controller_testInstanceStruct *
  chartInstance, const mxArray *c8_st);
static void finalize_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance);
static void sf_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance);
static void c8_chartstep_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance);
static void initSimStructsc8_controller_test(SFc8_controller_testInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_a5, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_c_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6]);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_d_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[36]);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[127]);
static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[127]);
static void c8_eml_scalar_eg(SFc8_controller_testInstanceStruct *chartInstance);
static real_T c8_mpower(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_a);
static real_T c8_b_mpower(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_a);
static real_T c8_c_mpower(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_a);
static void c8_invNxN(SFc8_controller_testInstanceStruct *chartInstance, real_T
                      c8_x[36], real_T c8_y[36]);
static void c8_realmin(SFc8_controller_testInstanceStruct *chartInstance);
static void c8_eps(SFc8_controller_testInstanceStruct *chartInstance);
static void c8_eml_matlab_zgetrf(SFc8_controller_testInstanceStruct
  *chartInstance, real_T c8_A[36], real_T c8_b_A[36], int32_T c8_ipiv[6],
  int32_T *c8_info);
static void c8_eml_int_forloop_overflow_check(SFc8_controller_testInstanceStruct
  *chartInstance);
static void c8_b_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance, int32_T c8_b);
static void c8_c_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance);
static void c8_d_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance, int32_T c8_a, int32_T c8_b);
static void c8_eml_xgeru(SFc8_controller_testInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, int32_T c8_ix0, int32_T c8_iy0,
  real_T c8_A[36], int32_T c8_ia0, real_T c8_b_A[36]);
static void c8_eml_xtrsm(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_A[36], real_T c8_B[36], real_T c8_b_B[36]);
static void c8_e_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance);
static real_T c8_norm(SFc8_controller_testInstanceStruct *chartInstance, real_T
                      c8_x[36]);
static void c8_eml_warning(SFc8_controller_testInstanceStruct *chartInstance);
static void c8_b_eml_warning(SFc8_controller_testInstanceStruct *chartInstance,
  char_T c8_varargin_2[14]);
static void c8_b_eml_scalar_eg(SFc8_controller_testInstanceStruct *chartInstance);
static void c8_e_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_sprintf, const char_T *c8_identifier, char_T
  c8_y[14]);
static void c8_f_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  char_T c8_y[14]);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_g_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_h_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_controller_test, const char_T
  *c8_identifier);
static uint8_T c8_i_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_eml_matlab_zgetrf(SFc8_controller_testInstanceStruct
  *chartInstance, real_T c8_A[36], int32_T c8_ipiv[6], int32_T *c8_info);
static void c8_b_eml_xgeru(SFc8_controller_testInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, int32_T c8_ix0, int32_T c8_iy0,
  real_T c8_A[36], int32_T c8_ia0);
static void c8_b_eml_xtrsm(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_A[36], real_T c8_B[36]);
static void init_dsm_address_info(SFc8_controller_testInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_controller_test = 0U;
}

static void initialize_params_c8_controller_test
  (SFc8_controller_testInstanceStruct *chartInstance)
{
}

static void enable_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_controller_test
  (SFc8_controller_testInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_controller_test
  (SFc8_controller_testInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_hoistedGlobal;
  real_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real_T c8_d_hoistedGlobal;
  real_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  real_T c8_e_hoistedGlobal;
  real_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  real_T c8_f_hoistedGlobal;
  real_T c8_f_u;
  const mxArray *c8_g_y = NULL;
  uint8_T c8_g_hoistedGlobal;
  uint8_T c8_g_u;
  const mxArray *c8_h_y = NULL;
  real_T *c8_a0;
  real_T *c8_a1;
  real_T *c8_a2;
  real_T *c8_a3;
  real_T *c8_a4;
  real_T *c8_a5;
  c8_a5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_a4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_a3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_a1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_a0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(7), FALSE);
  c8_hoistedGlobal = *c8_a0;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_a1;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = *c8_a2;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = *c8_a3;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_e_hoistedGlobal = *c8_a4;
  c8_e_u = c8_e_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  c8_f_hoistedGlobal = *c8_a5;
  c8_f_u = c8_f_hoistedGlobal;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 5, c8_g_y);
  c8_g_hoistedGlobal = chartInstance->c8_is_active_c8_controller_test;
  c8_g_u = c8_g_hoistedGlobal;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 6, c8_h_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_controller_test(SFc8_controller_testInstanceStruct *
  chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_a0;
  real_T *c8_a1;
  real_T *c8_a2;
  real_T *c8_a3;
  real_T *c8_a4;
  real_T *c8_a5;
  c8_a5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_a4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_a3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_a1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_a0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_a0 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
    "a0");
  *c8_a1 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
    "a1");
  *c8_a2 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 2)),
    "a2");
  *c8_a3 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 3)),
    "a3");
  *c8_a4 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 4)),
    "a4");
  *c8_a5 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 5)),
    "a5");
  chartInstance->c8_is_active_c8_controller_test = c8_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 6)),
     "is_active_c8_controller_test");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_controller_test(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance)
{
}

static void sf_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance)
{
  real_T *c8_A;
  real_T *c8_B;
  real_T *c8_t;
  real_T *c8_a0;
  real_T *c8_a1;
  real_T *c8_a2;
  real_T *c8_a3;
  real_T *c8_a4;
  real_T *c8_a5;
  c8_a5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_a4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_a3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_a1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_a0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c8_A, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_B, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_t, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_a0, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_a1, 4U);
  _SFD_DATA_RANGE_CHECK(*c8_a2, 5U);
  _SFD_DATA_RANGE_CHECK(*c8_a3, 6U);
  _SFD_DATA_RANGE_CHECK(*c8_a4, 7U);
  _SFD_DATA_RANGE_CHECK(*c8_a5, 8U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_controller_test(chartInstance);
  sf_debug_check_for_state_inconsistency(_controller_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_chartstep_c8_controller_test(SFc8_controller_testInstanceStruct
  *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  real_T c8_A;
  real_T c8_B;
  real_T c8_t;
  uint32_T c8_debug_family_var_map[13];
  real_T c8_T[36];
  real_T c8_Ao[6];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 6.0;
  real_T c8_a0;
  real_T c8_a1;
  real_T c8_a2;
  real_T c8_a3;
  real_T c8_a4;
  real_T c8_a5;
  real_T c8_a;
  real_T c8_b_a;
  real_T c8_ak;
  real_T c8_c;
  real_T c8_b_A;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_y;
  real_T c8_c_A;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_b_y;
  real_T c8_d_A;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_c_y;
  real_T c8_e_A;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_d_y;
  real_T c8_f_A;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_e_y;
  real_T c8_g_A;
  real_T c8_k_x;
  real_T c8_l_x;
  real_T c8_f_y;
  real_T c8_h_A;
  real_T c8_m_x;
  real_T c8_n_x;
  real_T c8_g_y;
  real_T c8_d0;
  real_T c8_d1;
  int32_T c8_i0;
  int32_T c8_i1;
  static real_T c8_dv0[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c8_i2;
  int32_T c8_i3;
  static real_T c8_dv1[6] = { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 };

  int32_T c8_i4;
  int32_T c8_i5;
  static real_T c8_dv2[6] = { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };

  int32_T c8_i6;
  real_T c8_o_x[36];
  int32_T c8_i7;
  real_T c8_p_x[36];
  real_T c8_h_y[36];
  int32_T c8_i8;
  real_T c8_q_x[36];
  real_T c8_n1x;
  int32_T c8_i9;
  real_T c8_i_y[36];
  real_T c8_n1xinv;
  real_T c8_c_a;
  real_T c8_b;
  real_T c8_j_y;
  real_T c8_rc;
  real_T c8_r_x;
  boolean_T c8_b_b;
  real_T c8_s_x;
  int32_T c8_i10;
  static char_T c8_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c8_u[8];
  const mxArray *c8_k_y = NULL;
  real_T c8_b_u;
  const mxArray *c8_l_y = NULL;
  real_T c8_c_u;
  const mxArray *c8_m_y = NULL;
  real_T c8_d_u;
  const mxArray *c8_n_y = NULL;
  char_T c8_str[14];
  int32_T c8_i11;
  char_T c8_b_str[14];
  real_T c8_c_b[6];
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  real_T c8_C[6];
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i20;
  real_T *c8_b_a5;
  real_T *c8_b_a4;
  real_T *c8_b_a3;
  real_T *c8_b_a2;
  real_T *c8_b_a1;
  real_T *c8_b_a0;
  real_T *c8_b_t;
  real_T *c8_b_B;
  real_T *c8_i_A;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c8_b_a5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_b_a4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_b_a3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_b_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_b_a1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_b_a0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_i_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_i_A;
  c8_b_hoistedGlobal = *c8_b_B;
  c8_c_hoistedGlobal = *c8_b_t;
  c8_A = c8_hoistedGlobal;
  c8_B = c8_b_hoistedGlobal;
  c8_t = c8_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c8_T, 0U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c8_Ao, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 2U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_A, 4U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_B, 5U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_t, 6U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_a0, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a1, 8U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a2, 9U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a3, 10U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a4, 11U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a5, 12U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_a = c8_t;
  c8_b_a = c8_a;
  c8_eml_scalar_eg(chartInstance);
  c8_ak = c8_b_a;
  c8_c = muDoubleScalarPower(c8_ak, 5.0);
  c8_b_A = c8_c;
  c8_x = c8_b_A;
  c8_b_x = c8_x;
  c8_y = c8_b_x / 20.0;
  c8_c_A = c8_mpower(chartInstance, c8_t);
  c8_c_x = c8_c_A;
  c8_d_x = c8_c_x;
  c8_b_y = c8_d_x / 12.0;
  c8_d_A = c8_b_mpower(chartInstance, c8_t);
  c8_e_x = c8_d_A;
  c8_f_x = c8_e_x;
  c8_c_y = c8_f_x / 6.0;
  c8_e_A = c8_c_mpower(chartInstance, c8_t);
  c8_g_x = c8_e_A;
  c8_h_x = c8_g_x;
  c8_d_y = c8_h_x / 2.0;
  c8_f_A = c8_mpower(chartInstance, c8_t);
  c8_i_x = c8_f_A;
  c8_j_x = c8_i_x;
  c8_e_y = c8_j_x / 4.0;
  c8_g_A = c8_b_mpower(chartInstance, c8_t);
  c8_k_x = c8_g_A;
  c8_l_x = c8_k_x;
  c8_f_y = c8_l_x / 3.0;
  c8_h_A = c8_c_mpower(chartInstance, c8_t);
  c8_m_x = c8_h_A;
  c8_n_x = c8_m_x;
  c8_g_y = c8_n_x / 2.0;
  c8_d0 = c8_b_mpower(chartInstance, c8_t);
  c8_d1 = c8_c_mpower(chartInstance, c8_t);
  c8_T[0] = c8_y;
  c8_T[6] = c8_b_y;
  c8_T[12] = c8_c_y;
  c8_T[18] = c8_d_y;
  c8_T[24] = c8_t;
  c8_T[30] = 1.0;
  c8_T[1] = c8_e_y;
  c8_T[7] = c8_f_y;
  c8_T[13] = c8_g_y;
  c8_T[19] = c8_t;
  c8_T[25] = 1.0;
  c8_T[31] = 0.0;
  c8_T[2] = c8_d0;
  c8_T[8] = c8_d1;
  c8_T[14] = c8_t;
  c8_T[20] = 1.0;
  c8_T[26] = 0.0;
  c8_T[32] = 0.0;
  c8_i0 = 0;
  for (c8_i1 = 0; c8_i1 < 6; c8_i1++) {
    c8_T[c8_i0 + 3] = c8_dv0[c8_i1];
    c8_i0 += 6;
  }

  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 6; c8_i3++) {
    c8_T[c8_i2 + 4] = c8_dv1[c8_i3];
    c8_i2 += 6;
  }

  c8_i4 = 0;
  for (c8_i5 = 0; c8_i5 < 6; c8_i5++) {
    c8_T[c8_i4 + 5] = c8_dv2[c8_i5];
    c8_i4 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  for (c8_i6 = 0; c8_i6 < 36; c8_i6++) {
    c8_o_x[c8_i6] = c8_T[c8_i6];
  }

  for (c8_i7 = 0; c8_i7 < 36; c8_i7++) {
    c8_p_x[c8_i7] = c8_o_x[c8_i7];
  }

  c8_invNxN(chartInstance, c8_p_x, c8_h_y);
  for (c8_i8 = 0; c8_i8 < 36; c8_i8++) {
    c8_q_x[c8_i8] = c8_o_x[c8_i8];
  }

  c8_n1x = c8_norm(chartInstance, c8_q_x);
  for (c8_i9 = 0; c8_i9 < 36; c8_i9++) {
    c8_i_y[c8_i9] = c8_h_y[c8_i9];
  }

  c8_n1xinv = c8_norm(chartInstance, c8_i_y);
  c8_c_a = c8_n1x;
  c8_b = c8_n1xinv;
  c8_j_y = c8_c_a * c8_b;
  c8_rc = 1.0 / c8_j_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c8_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c8_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c8_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c8_r_x = c8_rc;
    c8_b_b = muDoubleScalarIsNaN(c8_r_x);
    guard3 = FALSE;
    if (c8_b_b) {
      guard3 = TRUE;
    } else {
      c8_eps(chartInstance);
      if (c8_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c8_s_x = c8_rc;
      for (c8_i10 = 0; c8_i10 < 8; c8_i10++) {
        c8_u[c8_i10] = c8_cv0[c8_i10];
      }

      c8_k_y = NULL;
      sf_mex_assign(&c8_k_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c8_b_u = 14.0;
      c8_l_y = NULL;
      sf_mex_assign(&c8_l_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c8_c_u = 6.0;
      c8_m_y = NULL;
      sf_mex_assign(&c8_m_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c8_d_u = c8_s_x;
      c8_n_y = NULL;
      sf_mex_assign(&c8_n_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c8_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c8_k_y, 14, c8_l_y, 14,
        c8_m_y), 14, c8_n_y), "sprintf", c8_str);
      for (c8_i11 = 0; c8_i11 < 14; c8_i11++) {
        c8_b_str[c8_i11] = c8_str[c8_i11];
      }

      c8_b_eml_warning(chartInstance, c8_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c8_eml_warning(chartInstance);
  }

  c8_c_b[0] = c8_B;
  c8_c_b[1] = 0.0;
  c8_c_b[2] = 0.0;
  c8_c_b[3] = c8_A;
  c8_c_b[4] = 0.0;
  c8_c_b[5] = 0.0;
  c8_b_eml_scalar_eg(chartInstance);
  c8_b_eml_scalar_eg(chartInstance);
  for (c8_i12 = 0; c8_i12 < 6; c8_i12++) {
    c8_Ao[c8_i12] = 0.0;
  }

  for (c8_i13 = 0; c8_i13 < 6; c8_i13++) {
    c8_Ao[c8_i13] = 0.0;
  }

  for (c8_i14 = 0; c8_i14 < 6; c8_i14++) {
    c8_C[c8_i14] = c8_Ao[c8_i14];
  }

  for (c8_i15 = 0; c8_i15 < 6; c8_i15++) {
    c8_Ao[c8_i15] = c8_C[c8_i15];
  }

  for (c8_i16 = 0; c8_i16 < 6; c8_i16++) {
    c8_C[c8_i16] = c8_Ao[c8_i16];
  }

  for (c8_i17 = 0; c8_i17 < 6; c8_i17++) {
    c8_Ao[c8_i17] = c8_C[c8_i17];
  }

  for (c8_i18 = 0; c8_i18 < 6; c8_i18++) {
    c8_Ao[c8_i18] = 0.0;
    c8_i19 = 0;
    for (c8_i20 = 0; c8_i20 < 6; c8_i20++) {
      c8_Ao[c8_i18] += c8_h_y[c8_i19 + c8_i18] * c8_c_b[c8_i20];
      c8_i19 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  c8_a0 = c8_Ao[0];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_a1 = c8_Ao[1];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_a2 = c8_Ao[2];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 9);
  c8_a3 = c8_Ao[3];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
  c8_a4 = c8_Ao[4];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
  c8_a5 = c8_Ao[5];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  *c8_b_a0 = c8_a0;
  *c8_b_a1 = c8_a1;
  *c8_b_a2 = c8_a2;
  *c8_b_a3 = c8_a3;
  *c8_b_a4 = c8_a4;
  *c8_b_a5 = c8_a5;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_controller_test(SFc8_controller_testInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_a5, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_a5), &c8_thisId);
  sf_mex_destroy(&c8_a5);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d2;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d2, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d2;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_a5;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_a5 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_a5), &c8_thisId);
  sf_mex_destroy(&c8_a5);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i21;
  real_T c8_b_inData[6];
  int32_T c8_i22;
  real_T c8_u[6];
  const mxArray *c8_y = NULL;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i21 = 0; c8_i21 < 6; c8_i21++) {
    c8_b_inData[c8_i21] = (*(real_T (*)[6])c8_inData)[c8_i21];
  }

  for (c8_i22 = 0; c8_i22 < 6; c8_i22++) {
    c8_u[c8_i22] = c8_b_inData[c8_i22];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_c_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6])
{
  real_T c8_dv3[6];
  int32_T c8_i23;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv3, 1, 0, 0U, 1, 0U, 1, 6);
  for (c8_i23 = 0; c8_i23 < 6; c8_i23++) {
    c8_y[c8_i23] = c8_dv3[c8_i23];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_Ao;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[6];
  int32_T c8_i24;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_Ao = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Ao), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_Ao);
  for (c8_i24 = 0; c8_i24 < 6; c8_i24++) {
    (*(real_T (*)[6])c8_outData)[c8_i24] = c8_y[c8_i24];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i27;
  real_T c8_b_inData[36];
  int32_T c8_i28;
  int32_T c8_i29;
  int32_T c8_i30;
  real_T c8_u[36];
  const mxArray *c8_y = NULL;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i25 = 0;
  for (c8_i26 = 0; c8_i26 < 6; c8_i26++) {
    for (c8_i27 = 0; c8_i27 < 6; c8_i27++) {
      c8_b_inData[c8_i27 + c8_i25] = (*(real_T (*)[36])c8_inData)[c8_i27 +
        c8_i25];
    }

    c8_i25 += 6;
  }

  c8_i28 = 0;
  for (c8_i29 = 0; c8_i29 < 6; c8_i29++) {
    for (c8_i30 = 0; c8_i30 < 6; c8_i30++) {
      c8_u[c8_i30 + c8_i28] = c8_b_inData[c8_i30 + c8_i28];
    }

    c8_i28 += 6;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_d_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[36])
{
  real_T c8_dv4[36];
  int32_T c8_i31;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv4, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c8_i31 = 0; c8_i31 < 36; c8_i31++) {
    c8_y[c8_i31] = c8_dv4[c8_i31];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_T;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[36];
  int32_T c8_i32;
  int32_T c8_i33;
  int32_T c8_i34;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_T = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_T), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_T);
  c8_i32 = 0;
  for (c8_i33 = 0; c8_i33 < 6; c8_i33++) {
    for (c8_i34 = 0; c8_i34 < 6; c8_i34++) {
      (*(real_T (*)[36])c8_outData)[c8_i34 + c8_i32] = c8_y[c8_i34 + c8_i32];
    }

    c8_i32 += 6;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_controller_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[127];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i35;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  c8_b_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 127), FALSE);
  for (c8_i35 = 0; c8_i35 < 127; c8_i35++) {
    c8_r0 = &c8_info[c8_i35];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i35);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i35);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i35);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i35);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i35);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i35);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i35);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i35);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[127])
{
  c8_info[0].context = "";
  c8_info[0].name = "mpower";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[0].fileTimeLo = 1286818842U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[1].name = "power";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[1].fileTimeLo = 1307651240U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[2].name = "eml_scalar_eg";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[2].fileTimeLo = 1286818796U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[3].name = "eml_scalexp_alloc";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[3].fileTimeLo = 1286818796U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[4].name = "eml_scalar_floor";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[4].fileTimeLo = 1286818726U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context = "";
  c8_info[5].name = "mrdivide";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[5].fileTimeLo = 1325124138U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 1319729966U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[6].name = "rdivide";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[6].fileTimeLo = 1286818844U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[7].name = "eml_div";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[7].fileTimeLo = 1313347810U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context = "";
  c8_info[8].name = "inv";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m";
  c8_info[8].fileTimeLo = 1305318000U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[9].name = "eml_index_class";
  c8_info[9].dominantType = "";
  c8_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[9].fileTimeLo = 1286818778U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[10].name = "eml_xgetrf";
  c8_info[10].dominantType = "int32";
  c8_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c8_info[10].fileTimeLo = 1286818806U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c8_info[11].name = "eml_lapack_xgetrf";
  c8_info[11].dominantType = "int32";
  c8_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c8_info[11].fileTimeLo = 1286818810U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c8_info[12].name = "eml_matlab_zgetrf";
  c8_info[12].dominantType = "int32";
  c8_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[12].fileTimeLo = 1302688994U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[13].name = "realmin";
  c8_info[13].dominantType = "char";
  c8_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[13].fileTimeLo = 1307651242U;
  c8_info[13].fileTimeHi = 0U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
  c8_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[14].name = "eml_realmin";
  c8_info[14].dominantType = "char";
  c8_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c8_info[14].fileTimeLo = 1307651244U;
  c8_info[14].fileTimeHi = 0U;
  c8_info[14].mFileTimeLo = 0U;
  c8_info[14].mFileTimeHi = 0U;
  c8_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c8_info[15].name = "eml_float_model";
  c8_info[15].dominantType = "char";
  c8_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[15].fileTimeLo = 1307651242U;
  c8_info[15].fileTimeHi = 0U;
  c8_info[15].mFileTimeLo = 0U;
  c8_info[15].mFileTimeHi = 0U;
  c8_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[16].name = "eps";
  c8_info[16].dominantType = "char";
  c8_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[16].fileTimeLo = 1307651240U;
  c8_info[16].fileTimeHi = 0U;
  c8_info[16].mFileTimeLo = 0U;
  c8_info[16].mFileTimeHi = 0U;
  c8_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[17].name = "eml_is_float_class";
  c8_info[17].dominantType = "char";
  c8_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[17].fileTimeLo = 1286818782U;
  c8_info[17].fileTimeHi = 0U;
  c8_info[17].mFileTimeLo = 0U;
  c8_info[17].mFileTimeHi = 0U;
  c8_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[18].name = "eml_eps";
  c8_info[18].dominantType = "char";
  c8_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[18].fileTimeLo = 1307651240U;
  c8_info[18].fileTimeHi = 0U;
  c8_info[18].mFileTimeLo = 0U;
  c8_info[18].mFileTimeHi = 0U;
  c8_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[19].name = "eml_float_model";
  c8_info[19].dominantType = "char";
  c8_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[19].fileTimeLo = 1307651242U;
  c8_info[19].fileTimeHi = 0U;
  c8_info[19].mFileTimeLo = 0U;
  c8_info[19].mFileTimeHi = 0U;
  c8_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[20].name = "min";
  c8_info[20].dominantType = "int32";
  c8_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[20].fileTimeLo = 1311255318U;
  c8_info[20].fileTimeHi = 0U;
  c8_info[20].mFileTimeLo = 0U;
  c8_info[20].mFileTimeHi = 0U;
  c8_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[21].name = "eml_min_or_max";
  c8_info[21].dominantType = "int32";
  c8_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[21].fileTimeLo = 1303146212U;
  c8_info[21].fileTimeHi = 0U;
  c8_info[21].mFileTimeLo = 0U;
  c8_info[21].mFileTimeHi = 0U;
  c8_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[22].name = "eml_scalar_eg";
  c8_info[22].dominantType = "int32";
  c8_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[22].fileTimeLo = 1286818796U;
  c8_info[22].fileTimeHi = 0U;
  c8_info[22].mFileTimeLo = 0U;
  c8_info[22].mFileTimeHi = 0U;
  c8_info[23].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[23].name = "eml_scalexp_alloc";
  c8_info[23].dominantType = "int32";
  c8_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[23].fileTimeLo = 1286818796U;
  c8_info[23].fileTimeHi = 0U;
  c8_info[23].mFileTimeLo = 0U;
  c8_info[23].mFileTimeHi = 0U;
  c8_info[24].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[24].name = "eml_index_class";
  c8_info[24].dominantType = "";
  c8_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[24].fileTimeLo = 1286818778U;
  c8_info[24].fileTimeHi = 0U;
  c8_info[24].mFileTimeLo = 0U;
  c8_info[24].mFileTimeHi = 0U;
  c8_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[25].name = "eml_scalar_eg";
  c8_info[25].dominantType = "int32";
  c8_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[25].fileTimeLo = 1286818796U;
  c8_info[25].fileTimeHi = 0U;
  c8_info[25].mFileTimeLo = 0U;
  c8_info[25].mFileTimeHi = 0U;
  c8_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[26].name = "colon";
  c8_info[26].dominantType = "int32";
  c8_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[26].fileTimeLo = 1311255318U;
  c8_info[26].fileTimeHi = 0U;
  c8_info[26].mFileTimeLo = 0U;
  c8_info[26].mFileTimeHi = 0U;
  c8_info[27].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[27].name = "colon";
  c8_info[27].dominantType = "int32";
  c8_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[27].fileTimeLo = 1311255318U;
  c8_info[27].fileTimeHi = 0U;
  c8_info[27].mFileTimeLo = 0U;
  c8_info[27].mFileTimeHi = 0U;
  c8_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[28].name = "floor";
  c8_info[28].dominantType = "double";
  c8_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[28].fileTimeLo = 1286818742U;
  c8_info[28].fileTimeHi = 0U;
  c8_info[28].mFileTimeLo = 0U;
  c8_info[28].mFileTimeHi = 0U;
  c8_info[29].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[29].name = "eml_scalar_floor";
  c8_info[29].dominantType = "double";
  c8_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[29].fileTimeLo = 1286818726U;
  c8_info[29].fileTimeHi = 0U;
  c8_info[29].mFileTimeLo = 0U;
  c8_info[29].mFileTimeHi = 0U;
  c8_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c8_info[30].name = "intmin";
  c8_info[30].dominantType = "char";
  c8_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[30].fileTimeLo = 1311255318U;
  c8_info[30].fileTimeHi = 0U;
  c8_info[30].mFileTimeLo = 0U;
  c8_info[30].mFileTimeHi = 0U;
  c8_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c8_info[31].name = "intmax";
  c8_info[31].dominantType = "char";
  c8_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[31].fileTimeLo = 1311255316U;
  c8_info[31].fileTimeHi = 0U;
  c8_info[31].mFileTimeLo = 0U;
  c8_info[31].mFileTimeHi = 0U;
  c8_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c8_info[32].name = "intmin";
  c8_info[32].dominantType = "char";
  c8_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[32].fileTimeLo = 1311255318U;
  c8_info[32].fileTimeHi = 0U;
  c8_info[32].mFileTimeLo = 0U;
  c8_info[32].mFileTimeHi = 0U;
  c8_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c8_info[33].name = "intmax";
  c8_info[33].dominantType = "char";
  c8_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[33].fileTimeLo = 1311255316U;
  c8_info[33].fileTimeHi = 0U;
  c8_info[33].mFileTimeLo = 0U;
  c8_info[33].mFileTimeHi = 0U;
  c8_info[34].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c8_info[34].name = "eml_isa_uint";
  c8_info[34].dominantType = "int32";
  c8_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c8_info[34].fileTimeLo = 1286818784U;
  c8_info[34].fileTimeHi = 0U;
  c8_info[34].mFileTimeLo = 0U;
  c8_info[34].mFileTimeHi = 0U;
  c8_info[35].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[35].name = "eml_unsigned_class";
  c8_info[35].dominantType = "char";
  c8_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c8_info[35].fileTimeLo = 1286818800U;
  c8_info[35].fileTimeHi = 0U;
  c8_info[35].mFileTimeLo = 0U;
  c8_info[35].mFileTimeHi = 0U;
  c8_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[36].name = "eml_index_class";
  c8_info[36].dominantType = "";
  c8_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[36].fileTimeLo = 1286818778U;
  c8_info[36].fileTimeHi = 0U;
  c8_info[36].mFileTimeLo = 0U;
  c8_info[36].mFileTimeHi = 0U;
  c8_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[37].name = "intmax";
  c8_info[37].dominantType = "char";
  c8_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[37].fileTimeLo = 1311255316U;
  c8_info[37].fileTimeHi = 0U;
  c8_info[37].mFileTimeLo = 0U;
  c8_info[37].mFileTimeHi = 0U;
  c8_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[38].name = "eml_isa_uint";
  c8_info[38].dominantType = "int32";
  c8_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c8_info[38].fileTimeLo = 1286818784U;
  c8_info[38].fileTimeHi = 0U;
  c8_info[38].mFileTimeLo = 0U;
  c8_info[38].mFileTimeHi = 0U;
  c8_info[39].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[39].name = "eml_index_plus";
  c8_info[39].dominantType = "int32";
  c8_info[39].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[39].fileTimeLo = 1286818778U;
  c8_info[39].fileTimeHi = 0U;
  c8_info[39].mFileTimeLo = 0U;
  c8_info[39].mFileTimeHi = 0U;
  c8_info[40].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[40].name = "eml_index_class";
  c8_info[40].dominantType = "";
  c8_info[40].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[40].fileTimeLo = 1286818778U;
  c8_info[40].fileTimeHi = 0U;
  c8_info[40].mFileTimeLo = 0U;
  c8_info[40].mFileTimeHi = 0U;
  c8_info[41].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c8_info[41].name = "eml_int_forloop_overflow_check";
  c8_info[41].dominantType = "";
  c8_info[41].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[41].fileTimeLo = 1311255316U;
  c8_info[41].fileTimeHi = 0U;
  c8_info[41].mFileTimeLo = 0U;
  c8_info[41].mFileTimeHi = 0U;
  c8_info[42].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c8_info[42].name = "intmax";
  c8_info[42].dominantType = "char";
  c8_info[42].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[42].fileTimeLo = 1311255316U;
  c8_info[42].fileTimeHi = 0U;
  c8_info[42].mFileTimeLo = 0U;
  c8_info[42].mFileTimeHi = 0U;
  c8_info[43].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[43].name = "eml_index_class";
  c8_info[43].dominantType = "";
  c8_info[43].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[43].fileTimeLo = 1286818778U;
  c8_info[43].fileTimeHi = 0U;
  c8_info[43].mFileTimeLo = 0U;
  c8_info[43].mFileTimeHi = 0U;
  c8_info[44].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[44].name = "eml_index_plus";
  c8_info[44].dominantType = "int32";
  c8_info[44].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[44].fileTimeLo = 1286818778U;
  c8_info[44].fileTimeHi = 0U;
  c8_info[44].mFileTimeLo = 0U;
  c8_info[44].mFileTimeHi = 0U;
  c8_info[45].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[45].name = "eml_int_forloop_overflow_check";
  c8_info[45].dominantType = "";
  c8_info[45].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[45].fileTimeLo = 1311255316U;
  c8_info[45].fileTimeHi = 0U;
  c8_info[45].mFileTimeLo = 0U;
  c8_info[45].mFileTimeHi = 0U;
  c8_info[46].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[46].name = "eml_index_minus";
  c8_info[46].dominantType = "int32";
  c8_info[46].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[46].fileTimeLo = 1286818778U;
  c8_info[46].fileTimeHi = 0U;
  c8_info[46].mFileTimeLo = 0U;
  c8_info[46].mFileTimeHi = 0U;
  c8_info[47].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[47].name = "eml_index_class";
  c8_info[47].dominantType = "";
  c8_info[47].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[47].fileTimeLo = 1286818778U;
  c8_info[47].fileTimeHi = 0U;
  c8_info[47].mFileTimeLo = 0U;
  c8_info[47].mFileTimeHi = 0U;
  c8_info[48].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[48].name = "eml_index_times";
  c8_info[48].dominantType = "int32";
  c8_info[48].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[48].fileTimeLo = 1286818780U;
  c8_info[48].fileTimeHi = 0U;
  c8_info[48].mFileTimeLo = 0U;
  c8_info[48].mFileTimeHi = 0U;
  c8_info[49].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[49].name = "eml_index_class";
  c8_info[49].dominantType = "";
  c8_info[49].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[49].fileTimeLo = 1286818778U;
  c8_info[49].fileTimeHi = 0U;
  c8_info[49].mFileTimeLo = 0U;
  c8_info[49].mFileTimeHi = 0U;
  c8_info[50].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[50].name = "eml_ixamax";
  c8_info[50].dominantType = "int32";
  c8_info[50].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c8_info[50].fileTimeLo = 1299076770U;
  c8_info[50].fileTimeHi = 0U;
  c8_info[50].mFileTimeLo = 0U;
  c8_info[50].mFileTimeHi = 0U;
  c8_info[51].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c8_info[51].name = "eml_blas_inline";
  c8_info[51].dominantType = "";
  c8_info[51].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[51].fileTimeLo = 1299076768U;
  c8_info[51].fileTimeHi = 0U;
  c8_info[51].mFileTimeLo = 0U;
  c8_info[51].mFileTimeHi = 0U;
  c8_info[52].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c8_info[52].name = "length";
  c8_info[52].dominantType = "double";
  c8_info[52].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[52].fileTimeLo = 1303146206U;
  c8_info[52].fileTimeHi = 0U;
  c8_info[52].mFileTimeLo = 0U;
  c8_info[52].mFileTimeHi = 0U;
  c8_info[53].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c8_info[53].name = "eml_index_class";
  c8_info[53].dominantType = "";
  c8_info[53].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[53].fileTimeLo = 1286818778U;
  c8_info[53].fileTimeHi = 0U;
  c8_info[53].mFileTimeLo = 0U;
  c8_info[53].mFileTimeHi = 0U;
  c8_info[54].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c8_info[54].name = "eml_refblas_ixamax";
  c8_info[54].dominantType = "int32";
  c8_info[54].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[54].fileTimeLo = 1299076770U;
  c8_info[54].fileTimeHi = 0U;
  c8_info[54].mFileTimeLo = 0U;
  c8_info[54].mFileTimeHi = 0U;
  c8_info[55].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[55].name = "eml_index_class";
  c8_info[55].dominantType = "";
  c8_info[55].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[55].fileTimeLo = 1286818778U;
  c8_info[55].fileTimeHi = 0U;
  c8_info[55].mFileTimeLo = 0U;
  c8_info[55].mFileTimeHi = 0U;
  c8_info[56].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[56].name = "eml_xcabs1";
  c8_info[56].dominantType = "double";
  c8_info[56].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[56].fileTimeLo = 1286818706U;
  c8_info[56].fileTimeHi = 0U;
  c8_info[56].mFileTimeLo = 0U;
  c8_info[56].mFileTimeHi = 0U;
  c8_info[57].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[57].name = "abs";
  c8_info[57].dominantType = "double";
  c8_info[57].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[57].fileTimeLo = 1286818694U;
  c8_info[57].fileTimeHi = 0U;
  c8_info[57].mFileTimeLo = 0U;
  c8_info[57].mFileTimeHi = 0U;
  c8_info[58].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[58].name = "eml_scalar_abs";
  c8_info[58].dominantType = "double";
  c8_info[58].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[58].fileTimeLo = 1286818712U;
  c8_info[58].fileTimeHi = 0U;
  c8_info[58].mFileTimeLo = 0U;
  c8_info[58].mFileTimeHi = 0U;
  c8_info[59].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[59].name = "eml_int_forloop_overflow_check";
  c8_info[59].dominantType = "";
  c8_info[59].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[59].fileTimeLo = 1311255316U;
  c8_info[59].fileTimeHi = 0U;
  c8_info[59].mFileTimeLo = 0U;
  c8_info[59].mFileTimeHi = 0U;
  c8_info[60].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[60].name = "eml_index_plus";
  c8_info[60].dominantType = "int32";
  c8_info[60].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[60].fileTimeLo = 1286818778U;
  c8_info[60].fileTimeHi = 0U;
  c8_info[60].mFileTimeLo = 0U;
  c8_info[60].mFileTimeHi = 0U;
  c8_info[61].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[61].name = "eml_xswap";
  c8_info[61].dominantType = "int32";
  c8_info[61].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c8_info[61].fileTimeLo = 1299076778U;
  c8_info[61].fileTimeHi = 0U;
  c8_info[61].mFileTimeLo = 0U;
  c8_info[61].mFileTimeHi = 0U;
  c8_info[62].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c8_info[62].name = "eml_blas_inline";
  c8_info[62].dominantType = "";
  c8_info[62].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[62].fileTimeLo = 1299076768U;
  c8_info[62].fileTimeHi = 0U;
  c8_info[62].mFileTimeLo = 0U;
  c8_info[62].mFileTimeHi = 0U;
  c8_info[63].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c8_info[63].name = "eml_refblas_xswap";
  c8_info[63].dominantType = "int32";
  c8_info[63].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[63].fileTimeLo = 1299076786U;
  c8_info[63].fileTimeHi = 0U;
  c8_info[63].mFileTimeLo = 0U;
  c8_info[63].mFileTimeHi = 0U;
}

static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[127])
{
  c8_info[64].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[64].name = "eml_index_class";
  c8_info[64].dominantType = "";
  c8_info[64].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[64].fileTimeLo = 1286818778U;
  c8_info[64].fileTimeHi = 0U;
  c8_info[64].mFileTimeLo = 0U;
  c8_info[64].mFileTimeHi = 0U;
  c8_info[65].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[65].name = "abs";
  c8_info[65].dominantType = "int32";
  c8_info[65].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[65].fileTimeLo = 1286818694U;
  c8_info[65].fileTimeHi = 0U;
  c8_info[65].mFileTimeLo = 0U;
  c8_info[65].mFileTimeHi = 0U;
  c8_info[66].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[66].name = "eml_scalar_abs";
  c8_info[66].dominantType = "int32";
  c8_info[66].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[66].fileTimeLo = 1286818712U;
  c8_info[66].fileTimeHi = 0U;
  c8_info[66].mFileTimeLo = 0U;
  c8_info[66].mFileTimeHi = 0U;
  c8_info[67].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[67].name = "eml_int_forloop_overflow_check";
  c8_info[67].dominantType = "";
  c8_info[67].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[67].fileTimeLo = 1311255316U;
  c8_info[67].fileTimeHi = 0U;
  c8_info[67].mFileTimeLo = 0U;
  c8_info[67].mFileTimeHi = 0U;
  c8_info[68].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[68].name = "eml_index_plus";
  c8_info[68].dominantType = "int32";
  c8_info[68].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[68].fileTimeLo = 1286818778U;
  c8_info[68].fileTimeHi = 0U;
  c8_info[68].mFileTimeLo = 0U;
  c8_info[68].mFileTimeHi = 0U;
  c8_info[69].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[69].name = "eml_div";
  c8_info[69].dominantType = "double";
  c8_info[69].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[69].fileTimeLo = 1313347810U;
  c8_info[69].fileTimeHi = 0U;
  c8_info[69].mFileTimeLo = 0U;
  c8_info[69].mFileTimeHi = 0U;
  c8_info[70].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[70].name = "eml_xgeru";
  c8_info[70].dominantType = "int32";
  c8_info[70].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[70].fileTimeLo = 1299076774U;
  c8_info[70].fileTimeHi = 0U;
  c8_info[70].mFileTimeLo = 0U;
  c8_info[70].mFileTimeHi = 0U;
  c8_info[71].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[71].name = "eml_blas_inline";
  c8_info[71].dominantType = "";
  c8_info[71].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[71].fileTimeLo = 1299076768U;
  c8_info[71].fileTimeHi = 0U;
  c8_info[71].mFileTimeLo = 0U;
  c8_info[71].mFileTimeHi = 0U;
  c8_info[72].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[72].name = "eml_xger";
  c8_info[72].dominantType = "int32";
  c8_info[72].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c8_info[72].fileTimeLo = 1299076774U;
  c8_info[72].fileTimeHi = 0U;
  c8_info[72].mFileTimeLo = 0U;
  c8_info[72].mFileTimeHi = 0U;
  c8_info[73].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c8_info[73].name = "eml_blas_inline";
  c8_info[73].dominantType = "";
  c8_info[73].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[73].fileTimeLo = 1299076768U;
  c8_info[73].fileTimeHi = 0U;
  c8_info[73].mFileTimeLo = 0U;
  c8_info[73].mFileTimeHi = 0U;
  c8_info[74].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c8_info[74].name = "intmax";
  c8_info[74].dominantType = "char";
  c8_info[74].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[74].fileTimeLo = 1311255316U;
  c8_info[74].fileTimeHi = 0U;
  c8_info[74].mFileTimeLo = 0U;
  c8_info[74].mFileTimeHi = 0U;
  c8_info[75].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c8_info[75].name = "min";
  c8_info[75].dominantType = "double";
  c8_info[75].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[75].fileTimeLo = 1311255318U;
  c8_info[75].fileTimeHi = 0U;
  c8_info[75].mFileTimeLo = 0U;
  c8_info[75].mFileTimeHi = 0U;
  c8_info[76].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[76].name = "eml_min_or_max";
  c8_info[76].dominantType = "char";
  c8_info[76].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[76].fileTimeLo = 1303146212U;
  c8_info[76].fileTimeHi = 0U;
  c8_info[76].mFileTimeLo = 0U;
  c8_info[76].mFileTimeHi = 0U;
  c8_info[77].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[77].name = "eml_scalar_eg";
  c8_info[77].dominantType = "double";
  c8_info[77].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[77].fileTimeLo = 1286818796U;
  c8_info[77].fileTimeHi = 0U;
  c8_info[77].mFileTimeLo = 0U;
  c8_info[77].mFileTimeHi = 0U;
  c8_info[78].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[78].name = "eml_scalexp_alloc";
  c8_info[78].dominantType = "double";
  c8_info[78].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[78].fileTimeLo = 1286818796U;
  c8_info[78].fileTimeHi = 0U;
  c8_info[78].mFileTimeLo = 0U;
  c8_info[78].mFileTimeHi = 0U;
  c8_info[79].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[79].name = "eml_scalar_eg";
  c8_info[79].dominantType = "double";
  c8_info[79].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[79].fileTimeLo = 1286818796U;
  c8_info[79].fileTimeHi = 0U;
  c8_info[79].mFileTimeLo = 0U;
  c8_info[79].mFileTimeHi = 0U;
  c8_info[80].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c8_info[80].name = "mtimes";
  c8_info[80].dominantType = "double";
  c8_info[80].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[80].fileTimeLo = 1289519692U;
  c8_info[80].fileTimeHi = 0U;
  c8_info[80].mFileTimeLo = 0U;
  c8_info[80].mFileTimeHi = 0U;
  c8_info[81].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c8_info[81].name = "eml_refblas_xger";
  c8_info[81].dominantType = "int32";
  c8_info[81].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c8_info[81].fileTimeLo = 1299076776U;
  c8_info[81].fileTimeHi = 0U;
  c8_info[81].mFileTimeLo = 0U;
  c8_info[81].mFileTimeHi = 0U;
  c8_info[82].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c8_info[82].name = "eml_refblas_xgerx";
  c8_info[82].dominantType = "int32";
  c8_info[82].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[82].fileTimeLo = 1299076778U;
  c8_info[82].fileTimeHi = 0U;
  c8_info[82].mFileTimeLo = 0U;
  c8_info[82].mFileTimeHi = 0U;
  c8_info[83].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[83].name = "eml_index_class";
  c8_info[83].dominantType = "";
  c8_info[83].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[83].fileTimeLo = 1286818778U;
  c8_info[83].fileTimeHi = 0U;
  c8_info[83].mFileTimeLo = 0U;
  c8_info[83].mFileTimeHi = 0U;
  c8_info[84].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[84].name = "abs";
  c8_info[84].dominantType = "int32";
  c8_info[84].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[84].fileTimeLo = 1286818694U;
  c8_info[84].fileTimeHi = 0U;
  c8_info[84].mFileTimeLo = 0U;
  c8_info[84].mFileTimeHi = 0U;
  c8_info[85].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[85].name = "eml_index_minus";
  c8_info[85].dominantType = "int32";
  c8_info[85].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[85].fileTimeLo = 1286818778U;
  c8_info[85].fileTimeHi = 0U;
  c8_info[85].mFileTimeLo = 0U;
  c8_info[85].mFileTimeHi = 0U;
  c8_info[86].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[86].name = "eml_int_forloop_overflow_check";
  c8_info[86].dominantType = "";
  c8_info[86].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[86].fileTimeLo = 1311255316U;
  c8_info[86].fileTimeHi = 0U;
  c8_info[86].mFileTimeLo = 0U;
  c8_info[86].mFileTimeHi = 0U;
  c8_info[87].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[87].name = "eml_index_plus";
  c8_info[87].dominantType = "int32";
  c8_info[87].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[87].fileTimeLo = 1286818778U;
  c8_info[87].fileTimeHi = 0U;
  c8_info[87].mFileTimeLo = 0U;
  c8_info[87].mFileTimeHi = 0U;
  c8_info[88].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[88].name = "eml_ipiv2perm";
  c8_info[88].dominantType = "int32";
  c8_info[88].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c8_info[88].fileTimeLo = 1286818782U;
  c8_info[88].fileTimeHi = 0U;
  c8_info[88].mFileTimeLo = 0U;
  c8_info[88].mFileTimeHi = 0U;
  c8_info[89].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c8_info[89].name = "colon";
  c8_info[89].dominantType = "int32";
  c8_info[89].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[89].fileTimeLo = 1311255318U;
  c8_info[89].fileTimeHi = 0U;
  c8_info[89].mFileTimeLo = 0U;
  c8_info[89].mFileTimeHi = 0U;
  c8_info[90].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c8_info[90].name = "eml_index_class";
  c8_info[90].dominantType = "";
  c8_info[90].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[90].fileTimeLo = 1286818778U;
  c8_info[90].fileTimeHi = 0U;
  c8_info[90].mFileTimeLo = 0U;
  c8_info[90].mFileTimeHi = 0U;
  c8_info[91].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[91].name = "eml_int_forloop_overflow_check";
  c8_info[91].dominantType = "";
  c8_info[91].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[91].fileTimeLo = 1311255316U;
  c8_info[91].fileTimeHi = 0U;
  c8_info[91].mFileTimeLo = 0U;
  c8_info[91].mFileTimeHi = 0U;
  c8_info[92].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[92].name = "eml_index_plus";
  c8_info[92].dominantType = "int32";
  c8_info[92].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[92].fileTimeLo = 1286818778U;
  c8_info[92].fileTimeHi = 0U;
  c8_info[92].mFileTimeLo = 0U;
  c8_info[92].mFileTimeHi = 0U;
  c8_info[93].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[93].name = "mtimes";
  c8_info[93].dominantType = "double";
  c8_info[93].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[93].fileTimeLo = 1289519692U;
  c8_info[93].fileTimeHi = 0U;
  c8_info[93].mFileTimeLo = 0U;
  c8_info[93].mFileTimeHi = 0U;
  c8_info[94].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[94].name = "eml_scalar_eg";
  c8_info[94].dominantType = "double";
  c8_info[94].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[94].fileTimeLo = 1286818796U;
  c8_info[94].fileTimeHi = 0U;
  c8_info[94].mFileTimeLo = 0U;
  c8_info[94].mFileTimeHi = 0U;
  c8_info[95].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c8_info[95].name = "eml_xtrsm";
  c8_info[95].dominantType = "int32";
  c8_info[95].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c8_info[95].fileTimeLo = 1299076778U;
  c8_info[95].fileTimeHi = 0U;
  c8_info[95].mFileTimeLo = 0U;
  c8_info[95].mFileTimeHi = 0U;
  c8_info[96].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c8_info[96].name = "eml_blas_inline";
  c8_info[96].dominantType = "";
  c8_info[96].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[96].fileTimeLo = 1299076768U;
  c8_info[96].fileTimeHi = 0U;
  c8_info[96].mFileTimeLo = 0U;
  c8_info[96].mFileTimeHi = 0U;
  c8_info[97].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c8_info[97].name = "mtimes";
  c8_info[97].dominantType = "double";
  c8_info[97].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[97].fileTimeLo = 1289519692U;
  c8_info[97].fileTimeHi = 0U;
  c8_info[97].mFileTimeLo = 0U;
  c8_info[97].mFileTimeHi = 0U;
  c8_info[98].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c8_info[98].name = "eml_scalar_eg";
  c8_info[98].dominantType = "double";
  c8_info[98].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[98].fileTimeLo = 1286818796U;
  c8_info[98].fileTimeHi = 0U;
  c8_info[98].mFileTimeLo = 0U;
  c8_info[98].mFileTimeHi = 0U;
  c8_info[99].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c8_info[99].name = "eml_refblas_xtrsm";
  c8_info[99].dominantType = "int32";
  c8_info[99].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[99].fileTimeLo = 1299076786U;
  c8_info[99].fileTimeHi = 0U;
  c8_info[99].mFileTimeLo = 0U;
  c8_info[99].mFileTimeHi = 0U;
  c8_info[100].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[100].name = "eml_scalar_eg";
  c8_info[100].dominantType = "double";
  c8_info[100].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[100].fileTimeLo = 1286818796U;
  c8_info[100].fileTimeHi = 0U;
  c8_info[100].mFileTimeLo = 0U;
  c8_info[100].mFileTimeHi = 0U;
  c8_info[101].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[101].name = "eml_index_minus";
  c8_info[101].dominantType = "int32";
  c8_info[101].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[101].fileTimeLo = 1286818778U;
  c8_info[101].fileTimeHi = 0U;
  c8_info[101].mFileTimeLo = 0U;
  c8_info[101].mFileTimeHi = 0U;
  c8_info[102].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[102].name = "eml_index_class";
  c8_info[102].dominantType = "";
  c8_info[102].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[102].fileTimeLo = 1286818778U;
  c8_info[102].fileTimeHi = 0U;
  c8_info[102].mFileTimeLo = 0U;
  c8_info[102].mFileTimeHi = 0U;
  c8_info[103].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[103].name = "eml_int_forloop_overflow_check";
  c8_info[103].dominantType = "";
  c8_info[103].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[103].fileTimeLo = 1311255316U;
  c8_info[103].fileTimeHi = 0U;
  c8_info[103].mFileTimeLo = 0U;
  c8_info[103].mFileTimeHi = 0U;
  c8_info[104].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[104].name = "eml_index_times";
  c8_info[104].dominantType = "int32";
  c8_info[104].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[104].fileTimeLo = 1286818780U;
  c8_info[104].fileTimeHi = 0U;
  c8_info[104].mFileTimeLo = 0U;
  c8_info[104].mFileTimeHi = 0U;
  c8_info[105].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[105].name = "eml_index_plus";
  c8_info[105].dominantType = "int32";
  c8_info[105].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[105].fileTimeLo = 1286818778U;
  c8_info[105].fileTimeHi = 0U;
  c8_info[105].mFileTimeLo = 0U;
  c8_info[105].mFileTimeHi = 0U;
  c8_info[106].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c8_info[106].name = "intmin";
  c8_info[106].dominantType = "char";
  c8_info[106].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[106].fileTimeLo = 1311255318U;
  c8_info[106].fileTimeHi = 0U;
  c8_info[106].mFileTimeLo = 0U;
  c8_info[106].mFileTimeHi = 0U;
  c8_info[107].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[107].name = "eml_div";
  c8_info[107].dominantType = "double";
  c8_info[107].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[107].fileTimeLo = 1313347810U;
  c8_info[107].fileTimeHi = 0U;
  c8_info[107].mFileTimeLo = 0U;
  c8_info[107].mFileTimeHi = 0U;
  c8_info[108].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[108].name = "norm";
  c8_info[108].dominantType = "double";
  c8_info[108].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[108].fileTimeLo = 1286818826U;
  c8_info[108].fileTimeHi = 0U;
  c8_info[108].mFileTimeLo = 0U;
  c8_info[108].mFileTimeHi = 0U;
  c8_info[109].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c8_info[109].name = "abs";
  c8_info[109].dominantType = "double";
  c8_info[109].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[109].fileTimeLo = 1286818694U;
  c8_info[109].fileTimeHi = 0U;
  c8_info[109].mFileTimeLo = 0U;
  c8_info[109].mFileTimeHi = 0U;
  c8_info[110].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c8_info[110].name = "isnan";
  c8_info[110].dominantType = "double";
  c8_info[110].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[110].fileTimeLo = 1286818760U;
  c8_info[110].fileTimeHi = 0U;
  c8_info[110].mFileTimeLo = 0U;
  c8_info[110].mFileTimeHi = 0U;
  c8_info[111].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c8_info[111].name = "eml_guarded_nan";
  c8_info[111].dominantType = "char";
  c8_info[111].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c8_info[111].fileTimeLo = 1286818776U;
  c8_info[111].fileTimeHi = 0U;
  c8_info[111].mFileTimeLo = 0U;
  c8_info[111].mFileTimeHi = 0U;
  c8_info[112].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c8_info[112].name = "eml_is_float_class";
  c8_info[112].dominantType = "char";
  c8_info[112].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[112].fileTimeLo = 1286818782U;
  c8_info[112].fileTimeHi = 0U;
  c8_info[112].mFileTimeLo = 0U;
  c8_info[112].mFileTimeHi = 0U;
  c8_info[113].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[113].name = "mtimes";
  c8_info[113].dominantType = "double";
  c8_info[113].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[113].fileTimeLo = 1289519692U;
  c8_info[113].fileTimeHi = 0U;
  c8_info[113].mFileTimeLo = 0U;
  c8_info[113].mFileTimeHi = 0U;
  c8_info[114].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[114].name = "eml_warning";
  c8_info[114].dominantType = "char";
  c8_info[114].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c8_info[114].fileTimeLo = 1286818802U;
  c8_info[114].fileTimeHi = 0U;
  c8_info[114].mFileTimeLo = 0U;
  c8_info[114].mFileTimeHi = 0U;
  c8_info[115].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[115].name = "isnan";
  c8_info[115].dominantType = "double";
  c8_info[115].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[115].fileTimeLo = 1286818760U;
  c8_info[115].fileTimeHi = 0U;
  c8_info[115].mFileTimeLo = 0U;
  c8_info[115].mFileTimeHi = 0U;
  c8_info[116].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[116].name = "eps";
  c8_info[116].dominantType = "char";
  c8_info[116].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[116].fileTimeLo = 1307651240U;
  c8_info[116].fileTimeHi = 0U;
  c8_info[116].mFileTimeLo = 0U;
  c8_info[116].mFileTimeHi = 0U;
  c8_info[117].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c8_info[117].name = "eml_flt2str";
  c8_info[117].dominantType = "double";
  c8_info[117].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c8_info[117].fileTimeLo = 1309451196U;
  c8_info[117].fileTimeHi = 0U;
  c8_info[117].mFileTimeLo = 0U;
  c8_info[117].mFileTimeHi = 0U;
  c8_info[118].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c8_info[118].name = "char";
  c8_info[118].dominantType = "double";
  c8_info[118].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/strfun/char.m";
  c8_info[118].fileTimeLo = 1319729968U;
  c8_info[118].fileTimeHi = 0U;
  c8_info[118].mFileTimeLo = 0U;
  c8_info[118].mFileTimeHi = 0U;
  c8_info[119].context = "";
  c8_info[119].name = "mtimes";
  c8_info[119].dominantType = "double";
  c8_info[119].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[119].fileTimeLo = 1289519692U;
  c8_info[119].fileTimeHi = 0U;
  c8_info[119].mFileTimeLo = 0U;
  c8_info[119].mFileTimeHi = 0U;
  c8_info[120].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[120].name = "eml_index_class";
  c8_info[120].dominantType = "";
  c8_info[120].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[120].fileTimeLo = 1286818778U;
  c8_info[120].fileTimeHi = 0U;
  c8_info[120].mFileTimeLo = 0U;
  c8_info[120].mFileTimeHi = 0U;
  c8_info[121].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[121].name = "eml_scalar_eg";
  c8_info[121].dominantType = "double";
  c8_info[121].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[121].fileTimeLo = 1286818796U;
  c8_info[121].fileTimeHi = 0U;
  c8_info[121].mFileTimeLo = 0U;
  c8_info[121].mFileTimeHi = 0U;
  c8_info[122].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[122].name = "eml_xgemm";
  c8_info[122].dominantType = "int32";
  c8_info[122].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[122].fileTimeLo = 1299076772U;
  c8_info[122].fileTimeHi = 0U;
  c8_info[122].mFileTimeLo = 0U;
  c8_info[122].mFileTimeHi = 0U;
  c8_info[123].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[123].name = "eml_blas_inline";
  c8_info[123].dominantType = "";
  c8_info[123].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[123].fileTimeLo = 1299076768U;
  c8_info[123].fileTimeHi = 0U;
  c8_info[123].mFileTimeLo = 0U;
  c8_info[123].mFileTimeHi = 0U;
  c8_info[124].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c8_info[124].name = "mtimes";
  c8_info[124].dominantType = "double";
  c8_info[124].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[124].fileTimeLo = 1289519692U;
  c8_info[124].fileTimeHi = 0U;
  c8_info[124].mFileTimeLo = 0U;
  c8_info[124].mFileTimeHi = 0U;
  c8_info[125].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[125].name = "eml_scalar_eg";
  c8_info[125].dominantType = "double";
  c8_info[125].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[125].fileTimeLo = 1286818796U;
  c8_info[125].fileTimeHi = 0U;
  c8_info[125].mFileTimeLo = 0U;
  c8_info[125].mFileTimeHi = 0U;
  c8_info[126].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[126].name = "eml_refblas_xgemm";
  c8_info[126].dominantType = "int32";
  c8_info[126].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[126].fileTimeLo = 1299076774U;
  c8_info[126].fileTimeHi = 0U;
  c8_info[126].mFileTimeLo = 0U;
  c8_info[126].mFileTimeHi = 0U;
}

static void c8_eml_scalar_eg(SFc8_controller_testInstanceStruct *chartInstance)
{
}

static real_T c8_mpower(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_ak;
  c8_b_a = c8_a;
  c8_eml_scalar_eg(chartInstance);
  c8_ak = c8_b_a;
  return muDoubleScalarPower(c8_ak, 4.0);
}

static real_T c8_b_mpower(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_ak;
  c8_b_a = c8_a;
  c8_eml_scalar_eg(chartInstance);
  c8_ak = c8_b_a;
  return muDoubleScalarPower(c8_ak, 3.0);
}

static real_T c8_c_mpower(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_ak;
  c8_b_a = c8_a;
  c8_eml_scalar_eg(chartInstance);
  c8_ak = c8_b_a;
  return muDoubleScalarPower(c8_ak, 2.0);
}

static void c8_invNxN(SFc8_controller_testInstanceStruct *chartInstance, real_T
                      c8_x[36], real_T c8_y[36])
{
  int32_T c8_i36;
  int32_T c8_info;
  int32_T c8_ipiv[6];
  int32_T c8_i37;
  int32_T c8_p[6];
  int32_T c8_k;
  real_T c8_b_k;
  int32_T c8_ipk;
  int32_T c8_pipk;
  int32_T c8_c_k;
  int32_T c8_d_k;
  int32_T c8_c;
  int32_T c8_e_k;
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_a;
  int32_T c8_i38;
  int32_T c8_i;
  int32_T c8_b_i;
  real_T c8_b_a;
  real_T c8_b;
  real_T c8_b_y;
  int32_T c8_i39;
  real_T c8_b_x[36];
  for (c8_i36 = 0; c8_i36 < 36; c8_i36++) {
    c8_y[c8_i36] = 0.0;
  }

  c8_b_eml_matlab_zgetrf(chartInstance, c8_x, c8_ipiv, &c8_info);
  for (c8_i37 = 0; c8_i37 < 6; c8_i37++) {
    c8_p[c8_i37] = 1 + c8_i37;
  }

  for (c8_k = 0; c8_k < 5; c8_k++) {
    c8_b_k = 1.0 + (real_T)c8_k;
    c8_ipk = c8_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", c8_b_k), 1, 6, 1, 0) - 1];
    if ((real_T)c8_ipk > c8_b_k) {
      c8_pipk = c8_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c8_ipk), 1, 6, 1, 0) - 1];
      c8_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_ipk), 1, 6, 1, 0) - 1] = c8_p[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", c8_b_k), 1, 6, 1, 0) - 1];
      c8_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c8_b_k), 1, 6, 1, 0) - 1] = c8_pipk;
    }
  }

  c8_c_eml_int_forloop_overflow_check(chartInstance);
  for (c8_c_k = 1; c8_c_k < 7; c8_c_k++) {
    c8_d_k = c8_c_k;
    c8_c = c8_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_d_k), 1, 6, 1, 0) - 1];
    c8_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_d_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_c), 1, 6, 2, 0) - 1)) - 1]
      = 1.0;
    c8_e_k = c8_d_k;
    c8_d_eml_int_forloop_overflow_check(chartInstance, c8_e_k, 6);
    for (c8_j = c8_e_k; c8_j < 7; c8_j++) {
      c8_b_j = c8_j;
      if (c8_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c8_b_j), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_c), 1, 6, 2, 0) - 1)) -
          1] != 0.0) {
        c8_a = c8_b_j + 1;
        c8_i38 = c8_a;
        c8_d_eml_int_forloop_overflow_check(chartInstance, c8_i38, 6);
        for (c8_i = c8_i38; c8_i < 7; c8_i++) {
          c8_b_i = c8_i;
          c8_b_a = c8_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_j), 1, 6, 1, 0) + 6 *
                         (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_c), 1, 6, 2, 0) - 1)) - 1];
          c8_b = c8_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_i), 1, 6, 1, 0) + 6 *
                       (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_j), 1, 6, 2, 0) - 1)) - 1];
          c8_b_y = c8_b_a * c8_b;
          c8_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c8_b_i), 1, 6, 1, 0) + 6 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c8_c), 1, 6, 2, 0) - 1)) - 1] = c8_y
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_c), 1, 6, 2, 0) -
               1)) - 1] - c8_b_y;
        }
      }
    }
  }

  for (c8_i39 = 0; c8_i39 < 36; c8_i39++) {
    c8_b_x[c8_i39] = c8_x[c8_i39];
  }

  c8_b_eml_xtrsm(chartInstance, c8_b_x, c8_y);
}

static void c8_realmin(SFc8_controller_testInstanceStruct *chartInstance)
{
}

static void c8_eps(SFc8_controller_testInstanceStruct *chartInstance)
{
}

static void c8_eml_matlab_zgetrf(SFc8_controller_testInstanceStruct
  *chartInstance, real_T c8_A[36], real_T c8_b_A[36], int32_T c8_ipiv[6],
  int32_T *c8_info)
{
  int32_T c8_i40;
  for (c8_i40 = 0; c8_i40 < 36; c8_i40++) {
    c8_b_A[c8_i40] = c8_A[c8_i40];
  }

  c8_b_eml_matlab_zgetrf(chartInstance, c8_b_A, c8_ipiv, c8_info);
}

static void c8_eml_int_forloop_overflow_check(SFc8_controller_testInstanceStruct
  *chartInstance)
{
}

static void c8_b_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance, int32_T c8_b)
{
  int32_T c8_b_b;
  boolean_T c8_overflow;
  boolean_T c8_safe;
  int32_T c8_i41;
  static char_T c8_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c8_u[34];
  const mxArray *c8_y = NULL;
  int32_T c8_i42;
  static char_T c8_cv2[5] = { 'i', 'n', 't', '3', '2' };

  char_T c8_b_u[5];
  const mxArray *c8_b_y = NULL;
  c8_b_b = c8_b;
  if (2 > c8_b_b) {
    c8_overflow = FALSE;
  } else {
    c8_overflow = (c8_b_b > 2147483646);
  }

  c8_safe = !c8_overflow;
  if (c8_safe) {
  } else {
    for (c8_i41 = 0; c8_i41 < 34; c8_i41++) {
      c8_u[c8_i41] = c8_cv1[c8_i41];
    }

    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c8_i42 = 0; c8_i42 < 5; c8_i42++) {
      c8_b_u[c8_i42] = c8_cv2[c8_i42];
    }

    c8_b_y = NULL;
    sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c8_y, 14, c8_b_y));
  }
}

static void c8_c_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance)
{
}

static void c8_d_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance, int32_T c8_a, int32_T c8_b)
{
  int32_T c8_b_a;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  boolean_T c8_safe;
  int32_T c8_i43;
  static char_T c8_cv3[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c8_u[34];
  const mxArray *c8_y = NULL;
  int32_T c8_i44;
  static char_T c8_cv4[5] = { 'i', 'n', 't', '3', '2' };

  char_T c8_b_u[5];
  const mxArray *c8_b_y = NULL;
  c8_b_a = c8_a;
  c8_b_b = c8_b;
  if (c8_b_a > c8_b_b) {
    c8_overflow = FALSE;
  } else {
    c8_overflow = (c8_b_b > 2147483646);
  }

  c8_safe = !c8_overflow;
  if (c8_safe) {
  } else {
    for (c8_i43 = 0; c8_i43 < 34; c8_i43++) {
      c8_u[c8_i43] = c8_cv3[c8_i43];
    }

    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c8_i44 = 0; c8_i44 < 5; c8_i44++) {
      c8_b_u[c8_i44] = c8_cv4[c8_i44];
    }

    c8_b_y = NULL;
    sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c8_y, 14, c8_b_y));
  }
}

static void c8_eml_xgeru(SFc8_controller_testInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, int32_T c8_ix0, int32_T c8_iy0,
  real_T c8_A[36], int32_T c8_ia0, real_T c8_b_A[36])
{
  int32_T c8_i45;
  for (c8_i45 = 0; c8_i45 < 36; c8_i45++) {
    c8_b_A[c8_i45] = c8_A[c8_i45];
  }

  c8_b_eml_xgeru(chartInstance, c8_m, c8_n, c8_alpha1, c8_ix0, c8_iy0, c8_b_A,
                 c8_ia0);
}

static void c8_eml_xtrsm(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_A[36], real_T c8_B[36], real_T c8_b_B[36])
{
  int32_T c8_i46;
  int32_T c8_i47;
  real_T c8_b_A[36];
  for (c8_i46 = 0; c8_i46 < 36; c8_i46++) {
    c8_b_B[c8_i46] = c8_B[c8_i46];
  }

  for (c8_i47 = 0; c8_i47 < 36; c8_i47++) {
    c8_b_A[c8_i47] = c8_A[c8_i47];
  }

  c8_b_eml_xtrsm(chartInstance, c8_b_A, c8_b_B);
}

static void c8_e_eml_int_forloop_overflow_check
  (SFc8_controller_testInstanceStruct *chartInstance)
{
}

static real_T c8_norm(SFc8_controller_testInstanceStruct *chartInstance, real_T
                      c8_x[36])
{
  real_T c8_y;
  int32_T c8_j;
  real_T c8_b_j;
  real_T c8_s;
  int32_T c8_i;
  real_T c8_b_i;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_b_y;
  real_T c8_d_x;
  boolean_T c8_b;
  boolean_T exitg1;
  c8_y = 0.0;
  c8_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (c8_j < 6)) {
    c8_b_j = 1.0 + (real_T)c8_j;
    c8_s = 0.0;
    for (c8_i = 0; c8_i < 6; c8_i++) {
      c8_b_i = 1.0 + (real_T)c8_i;
      c8_b_x = c8_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c8_b_i), 1, 6, 1, 0) + 6 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c8_b_j), 1, 6, 2, 0) - 1)) - 1];
      c8_c_x = c8_b_x;
      c8_b_y = muDoubleScalarAbs(c8_c_x);
      c8_s += c8_b_y;
    }

    c8_d_x = c8_s;
    c8_b = muDoubleScalarIsNaN(c8_d_x);
    if (c8_b) {
      c8_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c8_s > c8_y) {
        c8_y = c8_s;
      }

      c8_j++;
    }
  }

  return c8_y;
}

static void c8_eml_warning(SFc8_controller_testInstanceStruct *chartInstance)
{
  int32_T c8_i48;
  static char_T c8_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c8_u[27];
  const mxArray *c8_y = NULL;
  for (c8_i48 = 0; c8_i48 < 27; c8_i48++) {
    c8_u[c8_i48] = c8_varargin_1[c8_i48];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c8_y));
}

static void c8_b_eml_warning(SFc8_controller_testInstanceStruct *chartInstance,
  char_T c8_varargin_2[14])
{
  int32_T c8_i49;
  static char_T c8_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c8_u[33];
  const mxArray *c8_y = NULL;
  int32_T c8_i50;
  char_T c8_b_u[14];
  const mxArray *c8_b_y = NULL;
  for (c8_i49 = 0; c8_i49 < 33; c8_i49++) {
    c8_u[c8_i49] = c8_varargin_1[c8_i49];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c8_i50 = 0; c8_i50 < 14; c8_i50++) {
    c8_b_u[c8_i50] = c8_varargin_2[c8_i50];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c8_y, 14, c8_b_y));
}

static void c8_b_eml_scalar_eg(SFc8_controller_testInstanceStruct *chartInstance)
{
}

static void c8_e_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_sprintf, const char_T *c8_identifier, char_T
  c8_y[14])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_sprintf), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_sprintf);
}

static void c8_f_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  char_T c8_y[14])
{
  char_T c8_cv5[14];
  int32_T c8_i51;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_cv5, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c8_i51 = 0; c8_i51 < 14; c8_i51++) {
    c8_y[c8_i51] = c8_cv5[c8_i51];
  }

  sf_mex_destroy(&c8_u);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_g_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i52;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i52, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i52;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_h_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_controller_test, const char_T
  *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_controller_test), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_controller_test);
  return c8_y;
}

static uint8_T c8_i_emlrt_marshallIn(SFc8_controller_testInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_eml_matlab_zgetrf(SFc8_controller_testInstanceStruct
  *chartInstance, real_T c8_A[36], int32_T c8_ipiv[6], int32_T *c8_info)
{
  int32_T c8_i53;
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_a;
  int32_T c8_jm1;
  int32_T c8_b;
  int32_T c8_mmj;
  int32_T c8_b_a;
  int32_T c8_c;
  int32_T c8_b_b;
  int32_T c8_jj;
  int32_T c8_c_a;
  int32_T c8_jp1j;
  int32_T c8_d_a;
  int32_T c8_b_c;
  int32_T c8_n;
  int32_T c8_ix0;
  int32_T c8_b_n;
  int32_T c8_b_ix0;
  int32_T c8_c_n;
  int32_T c8_c_ix0;
  int32_T c8_idxmax;
  int32_T c8_ix;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_b_y;
  real_T c8_smax;
  int32_T c8_loop_ub;
  int32_T c8_k;
  int32_T c8_b_k;
  int32_T c8_e_a;
  real_T c8_f_x;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_c_y;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_d_y;
  real_T c8_s;
  int32_T c8_f_a;
  int32_T c8_jpiv_offset;
  int32_T c8_g_a;
  int32_T c8_c_b;
  int32_T c8_jpiv;
  int32_T c8_h_a;
  int32_T c8_d_b;
  int32_T c8_c_c;
  int32_T c8_e_b;
  int32_T c8_jrow;
  int32_T c8_i_a;
  int32_T c8_f_b;
  int32_T c8_jprow;
  int32_T c8_d_ix0;
  int32_T c8_iy0;
  int32_T c8_e_ix0;
  int32_T c8_b_iy0;
  int32_T c8_f_ix0;
  int32_T c8_c_iy0;
  int32_T c8_b_ix;
  int32_T c8_iy;
  int32_T c8_c_k;
  real_T c8_temp;
  int32_T c8_j_a;
  int32_T c8_k_a;
  int32_T c8_b_jp1j;
  int32_T c8_l_a;
  int32_T c8_d_c;
  int32_T c8_m_a;
  int32_T c8_g_b;
  int32_T c8_i54;
  int32_T c8_i;
  int32_T c8_b_i;
  real_T c8_k_x;
  real_T c8_e_y;
  real_T c8_z;
  int32_T c8_h_b;
  int32_T c8_e_c;
  int32_T c8_n_a;
  int32_T c8_f_c;
  int32_T c8_o_a;
  int32_T c8_g_c;
  real_T c8_d3;
  c8_realmin(chartInstance);
  c8_eps(chartInstance);
  for (c8_i53 = 0; c8_i53 < 6; c8_i53++) {
    c8_ipiv[c8_i53] = 1 + c8_i53;
  }

  *c8_info = 0;
  c8_eml_int_forloop_overflow_check(chartInstance);
  for (c8_j = 1; c8_j < 6; c8_j++) {
    c8_b_j = c8_j;
    c8_a = c8_b_j - 1;
    c8_jm1 = c8_a;
    c8_b = c8_b_j;
    c8_mmj = 6 - c8_b;
    c8_b_a = c8_jm1;
    c8_c = c8_b_a * 7;
    c8_b_b = c8_c + 1;
    c8_jj = c8_b_b;
    c8_c_a = c8_jj + 1;
    c8_jp1j = c8_c_a;
    c8_d_a = c8_mmj;
    c8_b_c = c8_d_a;
    c8_n = c8_b_c + 1;
    c8_ix0 = c8_jj;
    c8_b_n = c8_n;
    c8_b_ix0 = c8_ix0;
    c8_c_n = c8_b_n;
    c8_c_ix0 = c8_b_ix0;
    if ((real_T)c8_c_n < 1.0) {
      c8_idxmax = 0;
    } else {
      c8_idxmax = 1;
      if ((real_T)c8_c_n > 1.0) {
        c8_ix = c8_c_ix0;
        c8_x = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c8_ix), 1, 36, 1, 0) - 1];
        c8_b_x = c8_x;
        c8_c_x = c8_b_x;
        c8_y = muDoubleScalarAbs(c8_c_x);
        c8_d_x = 0.0;
        c8_e_x = c8_d_x;
        c8_b_y = muDoubleScalarAbs(c8_e_x);
        c8_smax = c8_y + c8_b_y;
        c8_b_eml_int_forloop_overflow_check(chartInstance, c8_c_n);
        c8_loop_ub = c8_c_n;
        for (c8_k = 2; c8_k <= c8_loop_ub; c8_k++) {
          c8_b_k = c8_k;
          c8_e_a = c8_ix + 1;
          c8_ix = c8_e_a;
          c8_f_x = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_ix), 1, 36, 1, 0) - 1];
          c8_g_x = c8_f_x;
          c8_h_x = c8_g_x;
          c8_c_y = muDoubleScalarAbs(c8_h_x);
          c8_i_x = 0.0;
          c8_j_x = c8_i_x;
          c8_d_y = muDoubleScalarAbs(c8_j_x);
          c8_s = c8_c_y + c8_d_y;
          if (c8_s > c8_smax) {
            c8_idxmax = c8_b_k;
            c8_smax = c8_s;
          }
        }
      }
    }

    c8_f_a = c8_idxmax - 1;
    c8_jpiv_offset = c8_f_a;
    c8_g_a = c8_jj;
    c8_c_b = c8_jpiv_offset;
    c8_jpiv = c8_g_a + c8_c_b;
    if (c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c8_jpiv_offset != 0.0) {
        c8_h_a = c8_b_j;
        c8_d_b = c8_jpiv_offset;
        c8_c_c = c8_h_a + c8_d_b;
        c8_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_j), 1, 6, 1, 0) - 1] = c8_c_c;
        c8_e_b = c8_jm1 + 1;
        c8_jrow = c8_e_b;
        c8_i_a = c8_jrow;
        c8_f_b = c8_jpiv_offset;
        c8_jprow = c8_i_a + c8_f_b;
        c8_d_ix0 = c8_jrow;
        c8_iy0 = c8_jprow;
        c8_e_ix0 = c8_d_ix0;
        c8_b_iy0 = c8_iy0;
        c8_f_ix0 = c8_e_ix0;
        c8_c_iy0 = c8_b_iy0;
        c8_b_ix = c8_f_ix0;
        c8_iy = c8_c_iy0;
        c8_c_eml_int_forloop_overflow_check(chartInstance);
        for (c8_c_k = 1; c8_c_k < 7; c8_c_k++) {
          c8_temp = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 36, 1, 0) - 1];
          c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ix), 1, 36, 1, 0) - 1] =
            c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_iy), 1, 36, 1, 0) - 1];
          c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_iy), 1, 36, 1, 0) - 1] = c8_temp;
          c8_j_a = c8_b_ix + 6;
          c8_b_ix = c8_j_a;
          c8_k_a = c8_iy + 6;
          c8_iy = c8_k_a;
        }
      }

      c8_b_jp1j = c8_jp1j;
      c8_l_a = c8_mmj;
      c8_d_c = c8_l_a;
      c8_m_a = c8_jp1j;
      c8_g_b = c8_d_c - 1;
      c8_i54 = c8_m_a + c8_g_b;
      c8_d_eml_int_forloop_overflow_check(chartInstance, c8_b_jp1j, c8_i54);
      for (c8_i = c8_b_jp1j; c8_i <= c8_i54; c8_i++) {
        c8_b_i = c8_i;
        c8_k_x = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_b_i), 1, 36, 1, 0) - 1];
        c8_e_y = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_jj), 1, 36, 1, 0) - 1];
        c8_z = c8_k_x / c8_e_y;
        c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_i), 1, 36, 1, 0) - 1] = c8_z;
      }
    } else {
      *c8_info = c8_b_j;
    }

    c8_h_b = c8_b_j;
    c8_e_c = 6 - c8_h_b;
    c8_n_a = c8_jj;
    c8_f_c = c8_n_a;
    c8_o_a = c8_jj;
    c8_g_c = c8_o_a;
    c8_d3 = -1.0;
    c8_b_eml_xgeru(chartInstance, c8_mmj, c8_e_c, c8_d3, c8_jp1j, c8_f_c + 6,
                   c8_A, c8_g_c + 7);
  }

  if ((real_T)*c8_info == 0.0) {
    if (!(c8_A[35] != 0.0)) {
      *c8_info = 6;
    }
  }
}

static void c8_b_eml_xgeru(SFc8_controller_testInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, int32_T c8_ix0, int32_T c8_iy0,
  real_T c8_A[36], int32_T c8_ia0)
{
  int32_T c8_b_m;
  int32_T c8_b_n;
  real_T c8_b_alpha1;
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_b_ia0;
  int32_T c8_c_m;
  int32_T c8_c_n;
  real_T c8_c_alpha1;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_c_ia0;
  int32_T c8_d_m;
  int32_T c8_d_n;
  real_T c8_d_alpha1;
  int32_T c8_d_ix0;
  int32_T c8_d_iy0;
  int32_T c8_d_ia0;
  int32_T c8_e_m;
  int32_T c8_e_n;
  real_T c8_e_alpha1;
  int32_T c8_e_ix0;
  int32_T c8_e_iy0;
  int32_T c8_e_ia0;
  int32_T c8_ixstart;
  int32_T c8_a;
  int32_T c8_jA;
  int32_T c8_jy;
  int32_T c8_loop_ub;
  int32_T c8_j;
  real_T c8_yjy;
  real_T c8_temp;
  int32_T c8_ix;
  int32_T c8_b;
  int32_T c8_i55;
  int32_T c8_b_a;
  int32_T c8_b_b;
  int32_T c8_i56;
  int32_T c8_ijA;
  int32_T c8_b_ijA;
  int32_T c8_c_a;
  int32_T c8_d_a;
  int32_T c8_e_a;
  c8_b_m = c8_m;
  c8_b_n = c8_n;
  c8_b_alpha1 = c8_alpha1;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_b_ia0 = c8_ia0;
  c8_c_m = c8_b_m;
  c8_c_n = c8_b_n;
  c8_c_alpha1 = c8_b_alpha1;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  c8_c_ia0 = c8_b_ia0;
  c8_d_m = c8_c_m;
  c8_d_n = c8_c_n;
  c8_d_alpha1 = c8_c_alpha1;
  c8_d_ix0 = c8_c_ix0;
  c8_d_iy0 = c8_c_iy0;
  c8_d_ia0 = c8_c_ia0;
  c8_e_m = c8_d_m;
  c8_e_n = c8_d_n;
  c8_e_alpha1 = c8_d_alpha1;
  c8_e_ix0 = c8_d_ix0;
  c8_e_iy0 = c8_d_iy0;
  c8_e_ia0 = c8_d_ia0;
  if (c8_e_alpha1 == 0.0) {
  } else {
    c8_ixstart = c8_e_ix0;
    c8_a = c8_e_ia0 - 1;
    c8_jA = c8_a;
    c8_jy = c8_e_iy0;
    c8_d_eml_int_forloop_overflow_check(chartInstance, 1, c8_e_n);
    c8_loop_ub = c8_e_n;
    for (c8_j = 1; c8_j <= c8_loop_ub; c8_j++) {
      c8_yjy = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c8_jy), 1, 36, 1, 0) - 1];
      if (c8_yjy != 0.0) {
        c8_temp = c8_yjy * c8_e_alpha1;
        c8_ix = c8_ixstart;
        c8_b = c8_jA + 1;
        c8_i55 = c8_b;
        c8_b_a = c8_e_m;
        c8_b_b = c8_jA;
        c8_i56 = c8_b_a + c8_b_b;
        c8_d_eml_int_forloop_overflow_check(chartInstance, c8_i55, c8_i56);
        for (c8_ijA = c8_i55; c8_ijA <= c8_i56; c8_ijA++) {
          c8_b_ijA = c8_ijA;
          c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ijA), 1, 36, 1, 0) - 1] =
            c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ijA), 1, 36, 1, 0) - 1] +
            c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_ix), 1, 36, 1, 0) - 1] * c8_temp;
          c8_c_a = c8_ix + 1;
          c8_ix = c8_c_a;
        }
      }

      c8_d_a = c8_jy + 6;
      c8_jy = c8_d_a;
      c8_e_a = c8_jA + 6;
      c8_jA = c8_e_a;
    }
  }
}

static void c8_b_eml_xtrsm(SFc8_controller_testInstanceStruct *chartInstance,
  real_T c8_A[36], real_T c8_B[36])
{
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_a;
  int32_T c8_c;
  int32_T c8_b;
  int32_T c8_b_c;
  int32_T c8_b_b;
  int32_T c8_jBcol;
  int32_T c8_k;
  int32_T c8_b_k;
  int32_T c8_b_a;
  int32_T c8_c_c;
  int32_T c8_c_b;
  int32_T c8_d_c;
  int32_T c8_d_b;
  int32_T c8_kAcol;
  int32_T c8_c_a;
  int32_T c8_e_b;
  int32_T c8_e_c;
  int32_T c8_d_a;
  int32_T c8_f_b;
  int32_T c8_f_c;
  int32_T c8_e_a;
  int32_T c8_g_b;
  int32_T c8_g_c;
  int32_T c8_f_a;
  int32_T c8_h_b;
  int32_T c8_h_c;
  real_T c8_x;
  real_T c8_y;
  real_T c8_z;
  int32_T c8_g_a;
  int32_T c8_i57;
  int32_T c8_i;
  int32_T c8_b_i;
  int32_T c8_h_a;
  int32_T c8_i_b;
  int32_T c8_i_c;
  int32_T c8_i_a;
  int32_T c8_j_b;
  int32_T c8_j_c;
  int32_T c8_j_a;
  int32_T c8_k_b;
  int32_T c8_k_c;
  int32_T c8_k_a;
  int32_T c8_l_b;
  int32_T c8_l_c;
  c8_c_eml_int_forloop_overflow_check(chartInstance);
  for (c8_j = 1; c8_j < 7; c8_j++) {
    c8_b_j = c8_j;
    c8_a = c8_b_j;
    c8_c = c8_a;
    c8_b = c8_c - 1;
    c8_b_c = 6 * c8_b;
    c8_b_b = c8_b_c;
    c8_jBcol = c8_b_b;
    c8_e_eml_int_forloop_overflow_check(chartInstance);
    for (c8_k = 6; c8_k > 0; c8_k--) {
      c8_b_k = c8_k;
      c8_b_a = c8_b_k;
      c8_c_c = c8_b_a;
      c8_c_b = c8_c_c - 1;
      c8_d_c = 6 * c8_c_b;
      c8_d_b = c8_d_c;
      c8_kAcol = c8_d_b;
      c8_c_a = c8_b_k;
      c8_e_b = c8_jBcol;
      c8_e_c = c8_c_a + c8_e_b;
      if (c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_e_c), 1, 36, 1, 0) - 1] != 0.0) {
        c8_d_a = c8_b_k;
        c8_f_b = c8_jBcol;
        c8_f_c = c8_d_a + c8_f_b;
        c8_e_a = c8_b_k;
        c8_g_b = c8_jBcol;
        c8_g_c = c8_e_a + c8_g_b;
        c8_f_a = c8_b_k;
        c8_h_b = c8_kAcol;
        c8_h_c = c8_f_a + c8_h_b;
        c8_x = c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c8_g_c), 1, 36, 1, 0) - 1];
        c8_y = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c8_h_c), 1, 36, 1, 0) - 1];
        c8_z = c8_x / c8_y;
        c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_f_c), 1, 36, 1, 0) - 1] = c8_z;
        c8_g_a = c8_b_k - 1;
        c8_i57 = c8_g_a;
        c8_d_eml_int_forloop_overflow_check(chartInstance, 1, c8_i57);
        for (c8_i = 1; c8_i <= c8_i57; c8_i++) {
          c8_b_i = c8_i;
          c8_h_a = c8_b_i;
          c8_i_b = c8_jBcol;
          c8_i_c = c8_h_a + c8_i_b;
          c8_i_a = c8_b_i;
          c8_j_b = c8_jBcol;
          c8_j_c = c8_i_a + c8_j_b;
          c8_j_a = c8_b_k;
          c8_k_b = c8_jBcol;
          c8_k_c = c8_j_a + c8_k_b;
          c8_k_a = c8_b_i;
          c8_l_b = c8_kAcol;
          c8_l_c = c8_k_a + c8_l_b;
          c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_i_c), 1, 36, 1, 0) - 1] =
            c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_j_c), 1, 36, 1, 0) - 1] -
            c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_k_c), 1, 36, 1, 0) - 1] *
            c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_l_c), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc8_controller_testInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_controller_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1898154334U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(913337293U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1265913711U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2313934870U);
}

mxArray *sf_c8_controller_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BTKub5MyomifJr6TsKm7H");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c8_controller_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[7],T\"a0\",},{M[1],M[8],T\"a1\",},{M[1],M[9],T\"a2\",},{M[1],M[10],T\"a3\",},{M[1],M[11],T\"a4\",},{M[1],M[12],T\"a5\",},{M[8],M[0],T\"is_active_c8_controller_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_controller_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_controller_testInstanceStruct *chartInstance;
    chartInstance = (SFc8_controller_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_testMachineNumber_,
           8,
           1,
           1,
           9,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_controller_testMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_testMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_controller_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"A");
          _SFD_SET_DATA_PROPS(1,1,1,0,"B");
          _SFD_SET_DATA_PROPS(2,1,1,0,"t");
          _SFD_SET_DATA_PROPS(3,2,0,1,"a0");
          _SFD_SET_DATA_PROPS(4,2,0,1,"a1");
          _SFD_SET_DATA_PROPS(5,2,0,1,"a2");
          _SFD_SET_DATA_PROPS(6,2,0,1,"a3");
          _SFD_SET_DATA_PROPS(7,2,0,1,"a4");
          _SFD_SET_DATA_PROPS(8,2,0,1,"a5");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,342);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);

        {
          real_T *c8_A;
          real_T *c8_B;
          real_T *c8_t;
          real_T *c8_a0;
          real_T *c8_a1;
          real_T *c8_a2;
          real_T *c8_a3;
          real_T *c8_a4;
          real_T *c8_a5;
          c8_a5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c8_a4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c8_a3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c8_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c8_a1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c8_a0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c8_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_A);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_B);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_t);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_a0);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_a1);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_a2);
          _SFD_SET_DATA_VALUE_PTR(6U, c8_a3);
          _SFD_SET_DATA_VALUE_PTR(7U, c8_a4);
          _SFD_SET_DATA_VALUE_PTR(8U, c8_a5);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_controller_testMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "9kkjZFSVFGWa75hdeyiQkG";
}

static void sf_opaque_initialize_c8_controller_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_controller_testInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_controller_test((SFc8_controller_testInstanceStruct*)
    chartInstanceVar);
  initialize_c8_controller_test((SFc8_controller_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_controller_test(void *chartInstanceVar)
{
  enable_c8_controller_test((SFc8_controller_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_controller_test(void *chartInstanceVar)
{
  disable_c8_controller_test((SFc8_controller_testInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_controller_test(void *chartInstanceVar)
{
  sf_c8_controller_test((SFc8_controller_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_controller_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_controller_test
    ((SFc8_controller_testInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_controller_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c8_controller_test(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_controller_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_controller_test((SFc8_controller_testInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_controller_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_controller_test(S);
}

static void sf_opaque_set_sim_state_c8_controller_test(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c8_controller_test(S, st);
}

static void sf_opaque_terminate_c8_controller_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_controller_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_controller_test((SFc8_controller_testInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_controller_test((SFc8_controller_testInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_controller_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_controller_test((SFc8_controller_testInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_controller_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,6);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2295830646U));
  ssSetChecksum1(S,(1883329399U));
  ssSetChecksum2(S,(1311001084U));
  ssSetChecksum3(S,(2604405802U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_controller_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_controller_test(SimStruct *S)
{
  SFc8_controller_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_controller_testInstanceStruct *)malloc(sizeof
    (SFc8_controller_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_controller_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_controller_test;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_controller_test;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_controller_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_controller_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_controller_test;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_controller_test;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_controller_test;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_controller_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_controller_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_controller_test;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_controller_test;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c8_controller_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_controller_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_controller_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_controller_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_controller_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
