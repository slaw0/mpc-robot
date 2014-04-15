/* Include files */

#include "blascompat32.h"
#include "dof2_test_sfun.h"
#include "c1_dof2_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dof2_test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[15] = { "T", "Q", "nargin", "nargout",
  "a0", "a1", "a2", "a3", "a4", "a5", "t_sim", "t", "qa", "qap", "qapp" };

/* Function Declarations */
static void initialize_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance);
static void initialize_params_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance);
static void enable_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance);
static void disable_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance);
static void set_sim_state_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance);
static void sf_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance);
static void c1_chartstep_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance);
static void initSimStructsc1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_qapp, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[18]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[16]);
static void c1_eml_scalar_eg(SFc1_dof2_testInstanceStruct *chartInstance);
static real_T c1_mpower(SFc1_dof2_testInstanceStruct *chartInstance, real_T c1_a);
static real_T c1_b_mpower(SFc1_dof2_testInstanceStruct *chartInstance, real_T
  c1_a);
static real_T c1_c_mpower(SFc1_dof2_testInstanceStruct *chartInstance, real_T
  c1_a);
static void c1_b_eml_scalar_eg(SFc1_dof2_testInstanceStruct *chartInstance);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_dof2_test, const char_T *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_dof2_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_dof2_test = 0U;
}

static void initialize_params_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance)
{
}

static void enable_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T *c1_qa;
  real_T *c1_qap;
  real_T *c1_qapp;
  c1_qapp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_qap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_qa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_qa;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_qap;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_qapp;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_dof2_test;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_qa;
  real_T *c1_qap;
  real_T *c1_qapp;
  c1_qapp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_qap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_qa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_qa = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "qa");
  *c1_qap = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "qap");
  *c1_qapp = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    2)), "qapp");
  chartInstance->c1_is_active_c1_dof2_test = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 3)), "is_active_c1_dof2_test");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_dof2_test(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance)
{
}

static void sf_c1_dof2_test(SFc1_dof2_testInstanceStruct *chartInstance)
{
  real_T *c1_a0;
  real_T *c1_a1;
  real_T *c1_a2;
  real_T *c1_a3;
  real_T *c1_a4;
  real_T *c1_a5;
  real_T *c1_t_sim;
  real_T *c1_qa;
  real_T *c1_qap;
  real_T *c1_qapp;
  real_T *c1_t;
  c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_qapp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_qap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_qa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_t_sim = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_a5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_a4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_a2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_a1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_a0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_a0, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_a1, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_a2, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_a3, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_a4, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_a5, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_t_sim, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_qa, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_qap, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_qapp, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_t, 10U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_dof2_test(chartInstance);
  sf_debug_check_for_state_inconsistency(_dof2_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_a0;
  real_T c1_a1;
  real_T c1_a2;
  real_T c1_a3;
  real_T c1_a4;
  real_T c1_a5;
  real_T c1_t_sim;
  real_T c1_t;
  uint32_T c1_debug_family_var_map[15];
  real_T c1_T[18];
  real_T c1_Q[3];
  real_T c1_nargin = 8.0;
  real_T c1_nargout = 3.0;
  real_T c1_qa;
  real_T c1_qap;
  real_T c1_qapp;
  real_T c1_a;
  real_T c1_b_a;
  real_T c1_ak;
  real_T c1_c;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_y;
  real_T c1_b_A;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_y;
  real_T c1_c_A;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_y;
  real_T c1_d_A;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_d_y;
  real_T c1_e_A;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_e_y;
  real_T c1_f_A;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_f_y;
  real_T c1_g_A;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_g_y;
  real_T c1_d0;
  real_T c1_d1;
  int32_T c1_i0;
  real_T c1_c_a[18];
  real_T c1_b[6];
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  real_T c1_C[3];
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  real_T *c1_b_a0;
  real_T *c1_b_a1;
  real_T *c1_b_a2;
  real_T *c1_b_a3;
  real_T *c1_b_a4;
  real_T *c1_b_a5;
  real_T *c1_b_t_sim;
  real_T *c1_b_t;
  real_T *c1_b_qa;
  real_T *c1_b_qap;
  real_T *c1_b_qapp;
  c1_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_qapp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_qap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_qa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_t_sim = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_a5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_a4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_a2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_a1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_a0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_a0;
  c1_b_hoistedGlobal = *c1_b_a1;
  c1_c_hoistedGlobal = *c1_b_a2;
  c1_d_hoistedGlobal = *c1_b_a3;
  c1_e_hoistedGlobal = *c1_b_a4;
  c1_f_hoistedGlobal = *c1_b_a5;
  c1_g_hoistedGlobal = *c1_b_t_sim;
  c1_h_hoistedGlobal = *c1_b_t;
  c1_a0 = c1_hoistedGlobal;
  c1_a1 = c1_b_hoistedGlobal;
  c1_a2 = c1_c_hoistedGlobal;
  c1_a3 = c1_d_hoistedGlobal;
  c1_a4 = c1_e_hoistedGlobal;
  c1_a5 = c1_f_hoistedGlobal;
  c1_t_sim = c1_g_hoistedGlobal;
  c1_t = c1_h_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_T, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Q, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_a0, 4U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a1, 5U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a2, 6U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a3, 7U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a4, 8U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a5, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t_sim, 10U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_t, 11U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_qa, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_qap, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_qapp, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c1_t_sim > c1_t)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
    c1_t_sim = c1_t;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_a = c1_t_sim;
  c1_b_a = c1_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_b_a;
  c1_c = muDoubleScalarPower(c1_ak, 5.0);
  c1_A = c1_c;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_y = c1_b_x / 20.0;
  c1_b_A = c1_mpower(chartInstance, c1_t_sim);
  c1_c_x = c1_b_A;
  c1_d_x = c1_c_x;
  c1_b_y = c1_d_x / 12.0;
  c1_c_A = c1_b_mpower(chartInstance, c1_t_sim);
  c1_e_x = c1_c_A;
  c1_f_x = c1_e_x;
  c1_c_y = c1_f_x / 6.0;
  c1_d_A = c1_c_mpower(chartInstance, c1_t_sim);
  c1_g_x = c1_d_A;
  c1_h_x = c1_g_x;
  c1_d_y = c1_h_x / 2.0;
  c1_e_A = c1_mpower(chartInstance, c1_t_sim);
  c1_i_x = c1_e_A;
  c1_j_x = c1_i_x;
  c1_e_y = c1_j_x / 4.0;
  c1_f_A = c1_b_mpower(chartInstance, c1_t_sim);
  c1_k_x = c1_f_A;
  c1_l_x = c1_k_x;
  c1_f_y = c1_l_x / 3.0;
  c1_g_A = c1_c_mpower(chartInstance, c1_t_sim);
  c1_m_x = c1_g_A;
  c1_n_x = c1_m_x;
  c1_g_y = c1_n_x / 2.0;
  c1_d0 = c1_b_mpower(chartInstance, c1_t_sim);
  c1_d1 = c1_c_mpower(chartInstance, c1_t_sim);
  c1_T[0] = c1_y;
  c1_T[3] = c1_b_y;
  c1_T[6] = c1_c_y;
  c1_T[9] = c1_d_y;
  c1_T[12] = c1_t_sim;
  c1_T[15] = 1.0;
  c1_T[1] = c1_e_y;
  c1_T[4] = c1_f_y;
  c1_T[7] = c1_g_y;
  c1_T[10] = c1_t_sim;
  c1_T[13] = 1.0;
  c1_T[16] = 0.0;
  c1_T[2] = c1_d0;
  c1_T[5] = c1_d1;
  c1_T[8] = c1_t_sim;
  c1_T[11] = 1.0;
  c1_T[14] = 0.0;
  c1_T[17] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i0 = 0; c1_i0 < 18; c1_i0++) {
    c1_c_a[c1_i0] = c1_T[c1_i0];
  }

  c1_b[0] = c1_a0;
  c1_b[1] = c1_a1;
  c1_b[2] = c1_a2;
  c1_b[3] = c1_a3;
  c1_b[4] = c1_a4;
  c1_b[5] = c1_a5;
  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_Q[c1_i1] = 0.0;
  }

  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    c1_Q[c1_i2] = 0.0;
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_C[c1_i3] = c1_Q[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_Q[c1_i4] = c1_C[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_C[c1_i5] = c1_Q[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_Q[c1_i6] = c1_C[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_Q[c1_i7] = 0.0;
    c1_i8 = 0;
    for (c1_i9 = 0; c1_i9 < 6; c1_i9++) {
      c1_Q[c1_i7] += c1_c_a[c1_i8 + c1_i7] * c1_b[c1_i9];
      c1_i8 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_qa = c1_Q[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_qap = c1_Q[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_qapp = c1_Q[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -13);
  sf_debug_symbol_scope_pop();
  *c1_b_qa = c1_qa;
  *c1_b_qap = c1_qap;
  *c1_b_qapp = c1_qapp;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_dof2_test(SFc1_dof2_testInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_qapp, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_qapp), &c1_thisId);
  sf_mex_destroy(&c1_qapp);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_qapp;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_qapp = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_qapp), &c1_thisId);
  sf_mex_destroy(&c1_qapp);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i10;
  real_T c1_b_inData[3];
  int32_T c1_i11;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_b_inData[c1_i10] = (*(real_T (*)[3])c1_inData)[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    c1_u[c1_i11] = c1_b_inData[c1_i11];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv0[3];
  int32_T c1_i12;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_y[c1_i12] = c1_dv0[c1_i12];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Q;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i13;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_Q = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Q), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Q);
  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    (*(real_T (*)[3])c1_outData)[c1_i13] = c1_y[c1_i13];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_b_inData[18];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T c1_u[18];
  const mxArray *c1_y = NULL;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i14 = 0;
  for (c1_i15 = 0; c1_i15 < 6; c1_i15++) {
    for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
      c1_b_inData[c1_i16 + c1_i14] = (*(real_T (*)[18])c1_inData)[c1_i16 +
        c1_i14];
    }

    c1_i14 += 3;
  }

  c1_i17 = 0;
  for (c1_i18 = 0; c1_i18 < 6; c1_i18++) {
    for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
      c1_u[c1_i19 + c1_i17] = c1_b_inData[c1_i19 + c1_i17];
    }

    c1_i17 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 6), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[18])
{
  real_T c1_dv1[18];
  int32_T c1_i20;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 3, 6);
  for (c1_i20 = 0; c1_i20 < 18; c1_i20++) {
    c1_y[c1_i20] = c1_dv1[c1_i20];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_T;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[18];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_T = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_T), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_T);
  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 6; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
      (*(real_T (*)[18])c1_outData)[c1_i23 + c1_i21] = c1_y[c1_i23 + c1_i21];
    }

    c1_i21 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_dof2_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[16];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i24;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16), FALSE);
  for (c1_i24 = 0; c1_i24 < 16; c1_i24++) {
    c1_r0 = &c1_info[c1_i24];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i24);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i24);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i24);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i24);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i24);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i24);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i24);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i24);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[16])
{
  c1_info[0].context = "";
  c1_info[0].name = "mpower";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[0].fileTimeLo = 1286818842U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[1].name = "power";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[1].fileTimeLo = 1307651240U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[2].name = "eml_scalar_eg";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[2].fileTimeLo = 1286818796U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[3].name = "eml_scalexp_alloc";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[3].fileTimeLo = 1286818796U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[4].name = "eml_scalar_floor";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[4].fileTimeLo = 1286818726U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "";
  c1_info[5].name = "mrdivide";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[5].fileTimeLo = 1325124138U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 1319729966U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[6].name = "rdivide";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[6].fileTimeLo = 1286818844U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[7].name = "eml_div";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[7].fileTimeLo = 1313347810U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "";
  c1_info[8].name = "mtimes";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].fileTimeLo = 1289519692U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].name = "eml_index_class";
  c1_info[9].dominantType = "";
  c1_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[9].fileTimeLo = 1286818778U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].name = "eml_scalar_eg";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[10].fileTimeLo = 1286818796U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[11].name = "eml_xgemm";
  c1_info[11].dominantType = "int32";
  c1_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[11].fileTimeLo = 1299076772U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[12].name = "eml_blas_inline";
  c1_info[12].dominantType = "";
  c1_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[12].fileTimeLo = 1299076768U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[13].name = "mtimes";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[13].fileTimeLo = 1289519692U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[14].name = "eml_scalar_eg";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[14].fileTimeLo = 1286818796U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[15].name = "eml_refblas_xgemm";
  c1_info[15].dominantType = "int32";
  c1_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[15].fileTimeLo = 1299076774U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_dof2_testInstanceStruct *chartInstance)
{
}

static real_T c1_mpower(SFc1_dof2_testInstanceStruct *chartInstance, real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_b_a;
  return muDoubleScalarPower(c1_ak, 4.0);
}

static real_T c1_b_mpower(SFc1_dof2_testInstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_b_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_b_a;
  return muDoubleScalarPower(c1_ak, 3.0);
}

static real_T c1_c_mpower(SFc1_dof2_testInstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_b_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_b_a;
  return muDoubleScalarPower(c1_ak, 2.0);
}

static void c1_b_eml_scalar_eg(SFc1_dof2_testInstanceStruct *chartInstance)
{
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i25;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i25, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i25;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_dof2_test, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_dof2_test), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_dof2_test);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_dof2_testInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_dof2_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_dof2_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4019239917U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1850488247U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3422884802U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1312111565U);
}

mxArray *sf_c1_dof2_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("avpwvKaseon3HHemsDrN1D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_dof2_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[11],T\"qa\",},{M[1],M[12],T\"qap\",},{M[1],M[13],T\"qapp\",},{M[8],M[0],T\"is_active_c1_dof2_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_dof2_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_dof2_testInstanceStruct *chartInstance;
    chartInstance = (SFc1_dof2_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_dof2_testMachineNumber_,
          1,
          1,
          1,
          11,
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
          init_script_number_translation(_dof2_testMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_dof2_testMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_dof2_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"a0");
          _SFD_SET_DATA_PROPS(1,1,1,0,"a1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"a2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"a3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"a4");
          _SFD_SET_DATA_PROPS(5,1,1,0,"a5");
          _SFD_SET_DATA_PROPS(6,1,1,0,"t_sim");
          _SFD_SET_DATA_PROPS(7,2,0,1,"qa");
          _SFD_SET_DATA_PROPS(8,2,0,1,"qap");
          _SFD_SET_DATA_PROPS(9,2,0,1,"qapp");
          _SFD_SET_DATA_PROPS(10,1,1,0,"t");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,391);
        _SFD_CV_INIT_EML_IF(0,1,0,157,169,-1,184);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_a0;
          real_T *c1_a1;
          real_T *c1_a2;
          real_T *c1_a3;
          real_T *c1_a4;
          real_T *c1_a5;
          real_T *c1_t_sim;
          real_T *c1_qa;
          real_T *c1_qap;
          real_T *c1_qapp;
          real_T *c1_t;
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_qapp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_qap = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_qa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_t_sim = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_a5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_a4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_a2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_a1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_a0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_a0);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_a1);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_a2);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_a3);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_a4);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_a5);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_t_sim);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_qa);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_qap);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_qapp);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_t);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_dof2_testMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "NqrmIlbmo2HI7LER6Ata3D";
}

static void sf_opaque_initialize_c1_dof2_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_dof2_testInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_dof2_test((SFc1_dof2_testInstanceStruct*)
    chartInstanceVar);
  initialize_c1_dof2_test((SFc1_dof2_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_dof2_test(void *chartInstanceVar)
{
  enable_c1_dof2_test((SFc1_dof2_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_dof2_test(void *chartInstanceVar)
{
  disable_c1_dof2_test((SFc1_dof2_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_dof2_test(void *chartInstanceVar)
{
  sf_c1_dof2_test((SFc1_dof2_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_dof2_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_dof2_test((SFc1_dof2_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_dof2_test();/* state var info */
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

extern void sf_internal_set_sim_state_c1_dof2_test(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_dof2_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_dof2_test((SFc1_dof2_testInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_dof2_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_dof2_test(S);
}

static void sf_opaque_set_sim_state_c1_dof2_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_dof2_test(S, st);
}

static void sf_opaque_terminate_c1_dof2_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_dof2_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_dof2_test((SFc1_dof2_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_dof2_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_dof2_test((SFc1_dof2_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_dof2_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_dof2_test((SFc1_dof2_testInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_dof2_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dof2_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2529983988U));
  ssSetChecksum1(S,(2294647991U));
  ssSetChecksum2(S,(1815910616U));
  ssSetChecksum3(S,(1516820980U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_dof2_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_dof2_test(SimStruct *S)
{
  SFc1_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc1_dof2_testInstanceStruct *)malloc(sizeof
    (SFc1_dof2_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_dof2_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_dof2_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_dof2_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_dof2_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_dof2_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_dof2_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_dof2_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_dof2_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_dof2_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_dof2_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_dof2_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_dof2_test;
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

void c1_dof2_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_dof2_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_dof2_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_dof2_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_dof2_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
