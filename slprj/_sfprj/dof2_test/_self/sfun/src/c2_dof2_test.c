/* Include files */

#include "blascompat32.h"
#include "dof2_test_sfun.h"
#include "c2_dof2_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dof2_test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[37] = { "l1", "l2", "m1", "m2", "I1",
  "I2", "kD1", "kP1", "kI1", "kD2", "kP2", "kI2", "u1", "u2", "D11", "D12",
  "D22", "D112", "D122", "nargin", "nargout", "qa1", "qa1p", "qa1pp", "q1d",
  "q1", "q1p", "qa2", "qa2p", "qa2pp", "q2d", "q2", "q2p", "T1", "T2", "tau1",
  "tau2" };

/* Function Declarations */
static void initialize_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance);
static void initialize_params_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance);
static void enable_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance);
static void disable_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance);
static void set_sim_state_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance);
static void sf_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance);
static void c2_chartstep_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance);
static void initSimStructsc2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_tau2, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[13]);
static real_T c2_mpower(SFc2_dof2_testInstanceStruct *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg(SFc2_dof2_testInstanceStruct *chartInstance);
static real_T c2_b_mpower(SFc2_dof2_testInstanceStruct *chartInstance, real_T
  c2_a);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_dof2_test, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_dof2_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_dof2_test = 0U;
}

static void initialize_params_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance)
{
}

static void enable_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T *c2_tau1;
  real_T *c2_tau2;
  c2_tau2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_tau1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  c2_hoistedGlobal = *c2_tau1;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_tau2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_dof2_test;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_tau1;
  real_T *c2_tau2;
  c2_tau2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_tau1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_tau1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "tau1");
  *c2_tau2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "tau2");
  chartInstance->c2_is_active_c2_dof2_test = c2_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)), "is_active_c2_dof2_test");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_dof2_test(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance)
{
}

static void sf_c2_dof2_test(SFc2_dof2_testInstanceStruct *chartInstance)
{
  real_T *c2_qa1;
  real_T *c2_qa1p;
  real_T *c2_qa1pp;
  real_T *c2_q1d;
  real_T *c2_q1;
  real_T *c2_q1p;
  real_T *c2_qa2;
  real_T *c2_qa2p;
  real_T *c2_tau1;
  real_T *c2_qa2pp;
  real_T *c2_q2d;
  real_T *c2_q2;
  real_T *c2_q2p;
  real_T *c2_T1;
  real_T *c2_tau2;
  real_T *c2_T2;
  c2_T2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c2_tau2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_T1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c2_q2p = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c2_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c2_q2d = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c2_qa2pp = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_tau1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_qa2p = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_qa2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_q1p = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_q1d = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_qa1pp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_qa1p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_qa1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_qa1, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_qa1p, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_qa1pp, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_q1d, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_q1, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_q1p, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_qa2, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_qa2p, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_tau1, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_qa2pp, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_q2d, 10U);
  _SFD_DATA_RANGE_CHECK(*c2_q2, 11U);
  _SFD_DATA_RANGE_CHECK(*c2_q2p, 12U);
  _SFD_DATA_RANGE_CHECK(*c2_T1, 13U);
  _SFD_DATA_RANGE_CHECK(*c2_tau2, 14U);
  _SFD_DATA_RANGE_CHECK(*c2_T2, 15U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_dof2_test(chartInstance);
  sf_debug_check_for_state_inconsistency(_dof2_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_g_hoistedGlobal;
  real_T c2_h_hoistedGlobal;
  real_T c2_i_hoistedGlobal;
  real_T c2_j_hoistedGlobal;
  real_T c2_k_hoistedGlobal;
  real_T c2_l_hoistedGlobal;
  real_T c2_m_hoistedGlobal;
  real_T c2_n_hoistedGlobal;
  real_T c2_qa1;
  real_T c2_qa1p;
  real_T c2_qa1pp;
  real_T c2_q1d;
  real_T c2_q1;
  real_T c2_q1p;
  real_T c2_qa2;
  real_T c2_qa2p;
  real_T c2_qa2pp;
  real_T c2_q2d;
  real_T c2_q2;
  real_T c2_q2p;
  real_T c2_T1;
  real_T c2_T2;
  uint32_T c2_debug_family_var_map[37];
  real_T c2_l1;
  real_T c2_l2;
  real_T c2_m1;
  real_T c2_m2;
  real_T c2_I1;
  real_T c2_I2;
  real_T c2_kD1;
  real_T c2_kP1;
  real_T c2_kI1;
  real_T c2_kD2;
  real_T c2_kP2;
  real_T c2_kI2;
  real_T c2_u1;
  real_T c2_u2;
  real_T c2_D11;
  real_T c2_D12;
  real_T c2_D22;
  real_T c2_D112;
  real_T c2_D122;
  real_T c2_nargin = 14.0;
  real_T c2_nargout = 2.0;
  real_T c2_tau1;
  real_T c2_tau2;
  real_T c2_B;
  real_T c2_y;
  real_T c2_b_y;
  real_T c2_b_B;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_c_B;
  real_T c2_e_y;
  real_T c2_f_y;
  real_T c2_d_B;
  real_T c2_g_y;
  real_T c2_h_y;
  real_T c2_e_B;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_f_B;
  real_T c2_k_y;
  real_T c2_l_y;
  real_T c2_a;
  real_T c2_b;
  real_T c2_m_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_n_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_o_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_p_y;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_q_y;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_r_y;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_g_b;
  real_T c2_s_y;
  real_T c2_h_b;
  real_T c2_t_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_i_b;
  real_T c2_u_y;
  real_T c2_j_b;
  real_T c2_v_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_k_b;
  real_T c2_g_a;
  real_T c2_l_b;
  real_T c2_w_y;
  real_T c2_h_a;
  real_T c2_m_b;
  real_T c2_x_y;
  real_T c2_n_b;
  real_T c2_y_y;
  real_T c2_i_a;
  real_T c2_o_b;
  real_T c2_ab_y;
  real_T c2_j_a;
  real_T c2_p_b;
  real_T c2_bb_y;
  real_T c2_k_a;
  real_T c2_q_b;
  real_T c2_cb_y;
  real_T c2_l_a;
  real_T c2_r_b;
  real_T c2_db_y;
  real_T c2_s_b;
  real_T c2_eb_y;
  real_T c2_m_a;
  real_T c2_t_b;
  real_T c2_fb_y;
  real_T *c2_b_tau2;
  real_T *c2_b_tau1;
  real_T *c2_b_T2;
  real_T *c2_b_T1;
  real_T *c2_b_q2p;
  real_T *c2_b_q2;
  real_T *c2_b_q2d;
  real_T *c2_b_qa2pp;
  real_T *c2_b_qa2p;
  real_T *c2_b_qa2;
  real_T *c2_b_q1p;
  real_T *c2_b_q1;
  real_T *c2_b_q1d;
  real_T *c2_b_qa1pp;
  real_T *c2_b_qa1p;
  real_T *c2_b_qa1;
  c2_b_T2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c2_b_tau2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_T1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c2_b_q2p = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c2_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c2_b_q2d = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c2_b_qa2pp = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_b_tau1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_qa2p = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_b_qa2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_q1p = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_q1d = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_qa1pp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_qa1p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_qa1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_qa1;
  c2_b_hoistedGlobal = *c2_b_qa1p;
  c2_c_hoistedGlobal = *c2_b_qa1pp;
  c2_d_hoistedGlobal = *c2_b_q1d;
  c2_e_hoistedGlobal = *c2_b_q1;
  c2_f_hoistedGlobal = *c2_b_q1p;
  c2_g_hoistedGlobal = *c2_b_qa2;
  c2_h_hoistedGlobal = *c2_b_qa2p;
  c2_i_hoistedGlobal = *c2_b_qa2pp;
  c2_j_hoistedGlobal = *c2_b_q2d;
  c2_k_hoistedGlobal = *c2_b_q2;
  c2_l_hoistedGlobal = *c2_b_q2p;
  c2_m_hoistedGlobal = *c2_b_T1;
  c2_n_hoistedGlobal = *c2_b_T2;
  c2_qa1 = c2_hoistedGlobal;
  c2_qa1p = c2_b_hoistedGlobal;
  c2_qa1pp = c2_c_hoistedGlobal;
  c2_q1d = c2_d_hoistedGlobal;
  c2_q1 = c2_e_hoistedGlobal;
  c2_q1p = c2_f_hoistedGlobal;
  c2_qa2 = c2_g_hoistedGlobal;
  c2_qa2p = c2_h_hoistedGlobal;
  c2_qa2pp = c2_i_hoistedGlobal;
  c2_q2d = c2_j_hoistedGlobal;
  c2_q2 = c2_k_hoistedGlobal;
  c2_q2p = c2_l_hoistedGlobal;
  c2_T1 = c2_m_hoistedGlobal;
  c2_T2 = c2_n_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 37U, 37U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_l1, 0U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_l2, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_m1, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_m2, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_I1, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_I2, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_kD1, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_kP1, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_kI1, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_kD2, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_kP2, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_kI2, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_u1, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_u2, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_D11, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_D12, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_D22, 16U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_D112, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_D122, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_qa1, 21U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_qa1p, 22U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_qa1pp, 23U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q1d, 24U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q1, 25U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q1p, 26U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_qa2, 27U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_qa2p, 28U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_qa2pp, 29U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q2d, 30U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q2, 31U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q2p, 32U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_T1, 33U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_T2, 34U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_tau1, 35U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_tau2, 36U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_l1 = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_l2 = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_m1 = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_m2 = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_I1 = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_I2 = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_B = c2_T1;
  c2_y = c2_B;
  c2_b_y = c2_y;
  c2_kD1 = 3.0 / c2_b_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_b_B = c2_mpower(chartInstance, c2_T1);
  c2_c_y = c2_b_B;
  c2_d_y = c2_c_y;
  c2_kP1 = 3.0 / c2_d_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_c_B = c2_b_mpower(chartInstance, c2_T1);
  c2_e_y = c2_c_B;
  c2_f_y = c2_e_y;
  c2_kI1 = 1.0 / c2_f_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_d_B = c2_T2;
  c2_g_y = c2_d_B;
  c2_h_y = c2_g_y;
  c2_kD2 = 3.0 / c2_h_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_e_B = c2_mpower(chartInstance, c2_T2);
  c2_i_y = c2_e_B;
  c2_j_y = c2_i_y;
  c2_kP2 = 3.0 / c2_j_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_f_B = c2_b_mpower(chartInstance, c2_T2);
  c2_k_y = c2_f_B;
  c2_l_y = c2_k_y;
  c2_kI2 = 1.0 / c2_l_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_a = c2_kP1;
  c2_b = c2_qa1 - c2_q1;
  c2_m_y = c2_a * c2_b;
  c2_b_a = c2_kI1;
  c2_b_b = c2_q1d;
  c2_n_y = c2_b_a * c2_b_b;
  c2_c_a = c2_kD1;
  c2_c_b = c2_qa1p - c2_q1p;
  c2_o_y = c2_c_a * c2_c_b;
  c2_u1 = ((c2_qa1pp + c2_m_y) + c2_n_y) + c2_o_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_d_a = c2_kP2;
  c2_d_b = c2_qa2 - c2_q2;
  c2_p_y = c2_d_a * c2_d_b;
  c2_e_a = c2_kI2;
  c2_e_b = c2_q2d;
  c2_q_y = c2_e_a * c2_e_b;
  c2_f_a = c2_kD2;
  c2_f_b = c2_qa2p - c2_q2p;
  c2_r_y = c2_f_a * c2_f_b;
  c2_u2 = ((c2_qa2pp + c2_p_y) + c2_q_y) + c2_r_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_x = c2_q2;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_g_b = c2_b_x;
  c2_s_y = c2_g_b;
  c2_h_b = (c2_mpower(chartInstance, 1.0) + c2_s_y) + c2_mpower(chartInstance,
    0.5);
  c2_t_y = 5.0 * c2_h_b;
  c2_D11 = ((10.0 + c2_t_y) + c2_I1) + c2_I2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_c_x = c2_q2;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarCos(c2_d_x);
  c2_i_b = c2_d_x;
  c2_u_y = c2_i_b;
  c2_j_b = c2_u_y + c2_l2;
  c2_v_y = 2.5 * c2_j_b;
  c2_D12 = c2_v_y + c2_I2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_D22 = 1.35;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_e_x = c2_q2;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_k_b = c2_f_x;
  c2_D112 = -2.5 * c2_k_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_D122 = c2_D112;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_g_a = c2_D11;
  c2_l_b = c2_u1;
  c2_w_y = c2_g_a * c2_l_b;
  c2_h_a = c2_D12;
  c2_m_b = c2_u2;
  c2_x_y = c2_h_a * c2_m_b;
  c2_n_b = c2_D112;
  c2_y_y = 2.0 * c2_n_b;
  c2_i_a = c2_y_y;
  c2_o_b = c2_q1p;
  c2_ab_y = c2_i_a * c2_o_b;
  c2_j_a = c2_ab_y;
  c2_p_b = c2_q2p;
  c2_bb_y = c2_j_a * c2_p_b;
  c2_k_a = c2_D122;
  c2_q_b = c2_mpower(chartInstance, c2_q2p);
  c2_cb_y = c2_k_a * c2_q_b;
  c2_tau1 = ((c2_w_y + c2_x_y) + c2_bb_y) + c2_cb_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_l_a = c2_D12;
  c2_r_b = c2_u1;
  c2_db_y = c2_l_a * c2_r_b;
  c2_s_b = c2_u2;
  c2_eb_y = 1.35 * c2_s_b;
  c2_m_a = c2_D112;
  c2_t_b = c2_mpower(chartInstance, c2_q1p);
  c2_fb_y = c2_m_a * c2_t_b;
  c2_tau2 = (c2_db_y + c2_eb_y) - c2_fb_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -29);
  sf_debug_symbol_scope_pop();
  *c2_b_tau1 = c2_tau1;
  *c2_b_tau2 = c2_tau2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_dof2_test(SFc2_dof2_testInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc2_dof2_testInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_tau2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_tau2), &c2_thisId);
  sf_mex_destroy(&c2_tau2);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_tau2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc2_dof2_testInstanceStruct *)chartInstanceVoid;
  c2_tau2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_tau2), &c2_thisId);
  sf_mex_destroy(&c2_tau2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_dof2_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[13];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c2_i0 = 0; c2_i0 < 13; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[13])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1325124138U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1319729966U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1286818844U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_div";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[2].fileTimeLo = 1313347810U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mpower";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[3].fileTimeLo = 1286818842U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[4].name = "power";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[4].fileTimeLo = 1307651240U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[5].name = "eml_scalar_eg";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[5].fileTimeLo = 1286818796U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[6].name = "eml_scalexp_alloc";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[6].fileTimeLo = 1286818796U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[7].name = "eml_scalar_floor";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[7].fileTimeLo = 1286818726U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "mtimes";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].fileTimeLo = 1289519692U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "cos";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[9].fileTimeLo = 1286818706U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[10].name = "eml_scalar_cos";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[10].fileTimeLo = 1286818722U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "sin";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[11].fileTimeLo = 1286818750U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[12].name = "eml_scalar_sin";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[12].fileTimeLo = 1286818736U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
}

static real_T c2_mpower(SFc2_dof2_testInstanceStruct *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_eml_scalar_eg(SFc2_dof2_testInstanceStruct *chartInstance)
{
}

static real_T c2_b_mpower(SFc2_dof2_testInstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 3.0);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc2_dof2_testInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc2_dof2_testInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_dof2_test, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_dof2_test), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_dof2_test);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_dof2_testInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_dof2_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_dof2_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2296763664U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(697476629U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3966850725U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3067382092U);
}

mxArray *sf_c2_dof2_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JvikDzfhbqvDrI4jVsvdN");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,14,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_dof2_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[12],T\"tau1\",},{M[1],M[18],T\"tau2\",},{M[8],M[0],T\"is_active_c2_dof2_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_dof2_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_dof2_testInstanceStruct *chartInstance;
    chartInstance = (SFc2_dof2_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_dof2_testMachineNumber_,
          2,
          1,
          1,
          16,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"qa1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"qa1p");
          _SFD_SET_DATA_PROPS(2,1,1,0,"qa1pp");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q1d");
          _SFD_SET_DATA_PROPS(4,1,1,0,"q1");
          _SFD_SET_DATA_PROPS(5,1,1,0,"q1p");
          _SFD_SET_DATA_PROPS(6,1,1,0,"qa2");
          _SFD_SET_DATA_PROPS(7,1,1,0,"qa2p");
          _SFD_SET_DATA_PROPS(8,2,0,1,"tau1");
          _SFD_SET_DATA_PROPS(9,1,1,0,"qa2pp");
          _SFD_SET_DATA_PROPS(10,1,1,0,"q2d");
          _SFD_SET_DATA_PROPS(11,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(12,1,1,0,"q2p");
          _SFD_SET_DATA_PROPS(13,1,1,0,"T1");
          _SFD_SET_DATA_PROPS(14,2,0,1,"tau2");
          _SFD_SET_DATA_PROPS(15,1,1,0,"T2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,683);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_qa1;
          real_T *c2_qa1p;
          real_T *c2_qa1pp;
          real_T *c2_q1d;
          real_T *c2_q1;
          real_T *c2_q1p;
          real_T *c2_qa2;
          real_T *c2_qa2p;
          real_T *c2_tau1;
          real_T *c2_qa2pp;
          real_T *c2_q2d;
          real_T *c2_q2;
          real_T *c2_q2p;
          real_T *c2_T1;
          real_T *c2_tau2;
          real_T *c2_T2;
          c2_T2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c2_tau2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_T1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c2_q2p = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c2_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c2_q2d = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c2_qa2pp = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c2_tau1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_qa2p = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c2_qa2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_q1p = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_q1d = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_qa1pp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_qa1p = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_qa1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_qa1);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_qa1p);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_qa1pp);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_q1d);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_q1);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_q1p);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_qa2);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_qa2p);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_tau1);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_qa2pp);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_q2d);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_q2);
          _SFD_SET_DATA_VALUE_PTR(12U, c2_q2p);
          _SFD_SET_DATA_VALUE_PTR(13U, c2_T1);
          _SFD_SET_DATA_VALUE_PTR(14U, c2_tau2);
          _SFD_SET_DATA_VALUE_PTR(15U, c2_T2);
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
  return "lWvWAK9uLqt6pc2B7jBfoB";
}

static void sf_opaque_initialize_c2_dof2_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_dof2_testInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_dof2_test((SFc2_dof2_testInstanceStruct*)
    chartInstanceVar);
  initialize_c2_dof2_test((SFc2_dof2_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_dof2_test(void *chartInstanceVar)
{
  enable_c2_dof2_test((SFc2_dof2_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_dof2_test(void *chartInstanceVar)
{
  disable_c2_dof2_test((SFc2_dof2_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_dof2_test(void *chartInstanceVar)
{
  sf_c2_dof2_test((SFc2_dof2_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_dof2_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_dof2_test((SFc2_dof2_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_dof2_test();/* state var info */
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

extern void sf_internal_set_sim_state_c2_dof2_test(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_dof2_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_dof2_test((SFc2_dof2_testInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_dof2_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_dof2_test(S);
}

static void sf_opaque_set_sim_state_c2_dof2_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_dof2_test(S, st);
}

static void sf_opaque_terminate_c2_dof2_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_dof2_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_dof2_test((SFc2_dof2_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_dof2_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_dof2_test((SFc2_dof2_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_dof2_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_dof2_test((SFc2_dof2_testInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_dof2_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dof2_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
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
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,14);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(802105713U));
  ssSetChecksum1(S,(2042072933U));
  ssSetChecksum2(S,(1571638201U));
  ssSetChecksum3(S,(4042253215U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_dof2_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_dof2_test(SimStruct *S)
{
  SFc2_dof2_testInstanceStruct *chartInstance;
  chartInstance = (SFc2_dof2_testInstanceStruct *)malloc(sizeof
    (SFc2_dof2_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_dof2_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_dof2_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_dof2_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_dof2_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_dof2_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_dof2_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_dof2_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_dof2_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_dof2_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_dof2_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_dof2_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_dof2_test;
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

void c2_dof2_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_dof2_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_dof2_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_dof2_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_dof2_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
