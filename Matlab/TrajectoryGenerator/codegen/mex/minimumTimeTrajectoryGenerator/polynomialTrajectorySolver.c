/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polynomialTrajectorySolver.c
 *
 * Code generation for function 'polynomialTrajectorySolver'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "polynomialTrajectorySolver.h"
#include "mpower.h"
#include "norm.h"
#include "mldivide.h"
#include "polyval.h"
#include "polyder.h"
#include "calculateMaximums.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = { 24, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo f_emlrtRSI = { 28, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo g_emlrtRSI = { 29, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo h_emlrtRSI = { 30, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo i_emlrtRSI = { 34, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo j_emlrtRSI = { 53, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo k_emlrtRSI = { 56, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo l_emlrtRSI = { 57, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo m_emlrtRSI = { 58, "polynomialTrajectorySolver",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
  "lver.m" };

static emlrtRSInfo n_emlrtRSI = { 11, "get9DegPolyMatrix",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/get9DegPolyMatrix.m"
};

static emlrtRSInfo o_emlrtRSI = { 12, "get9DegPolyMatrix",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/get9DegPolyMatrix.m"
};

static emlrtRSInfo p_emlrtRSI = { 13, "get9DegPolyMatrix",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/get9DegPolyMatrix.m"
};

static emlrtRSInfo q_emlrtRSI = { 14, "get9DegPolyMatrix",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/get9DegPolyMatrix.m"
};

static emlrtRSInfo r_emlrtRSI = { 15, "get9DegPolyMatrix",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/get9DegPolyMatrix.m"
};

static emlrtRSInfo s_emlrtRSI = { 37, "mpower",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/mpower.m" };

static emlrtRSInfo t_emlrtRSI = { 49, "power",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRSInfo pb_emlrtRSI = { 24, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo qb_emlrtRSI = { 37, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo rb_emlrtRSI = { 49, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo sb_emlrtRSI = { 50, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo tb_emlrtRSI = { 52, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo ub_emlrtRSI = { 56, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo vb_emlrtRSI = { 57, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo wb_emlrtRSI = { 58, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo xb_emlrtRSI = { 62, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo yb_emlrtRSI = { 63, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo ac_emlrtRSI = { 64, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo bc_emlrtRSI = { 85, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo cc_emlrtRSI = { 88, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo dc_emlrtRSI = { 114, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo ec_emlrtRSI = { 120, "calculateActuatorFeasibility",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
  "bility.m" };

static emlrtRSInfo hd_emlrtRSI = { 31, "fprintf",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtMCInfo c_emlrtMCI = { 65, 18, "fprintf",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo ld_emlrtRSI = { 65, "fprintf",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_feval,
  const char_T *identifier);
static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 3, pArrays, "feval", true, location);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_feval,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(d_feval), &thisId);
  emlrtDestroyArray(&d_feval);
  return y;
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void polynomialTrajectorySolver(const emlrtStack *sp, const real32_T X[10],
  const real32_T Y[10], const real32_T Z[10], real32_T Mass, const real32_T
  Moment[3], real32_T MinZForce, real32_T MaxForce, real32_T C[33])
{
  boolean_T b0;
  boolean_T b1;
  boolean_T b2;
  boolean_T b3;
  boolean_T b4;
  boolean_T b5;
  boolean_T b6;
  boolean_T b7;
  boolean_T b8;
  real32_T t_start;
  real32_T t_end;
  real32_T t_mid;
  int32_T Error;
  int32_T it;
  real32_T tf;
  real32_T b;
  real32_T b_b;
  real32_T c_b;
  real32_T d_b;
  real32_T e_b;
  real32_T f_b;
  real32_T g_b;
  real32_T h_b;
  real32_T i_b;
  real32_T j_b;
  real32_T k_b;
  real32_T l_b;
  real32_T m_b;
  real32_T n_b;
  real32_T o_b;
  real32_T p_b;
  real32_T q_b;
  real32_T r_b;
  real32_T s_b;
  real32_T t_b;
  real32_T u_b;
  real32_T v_b;
  real32_T f0;
  real32_T f1;
  real32_T f2;
  real32_T f3;
  real32_T f4;
  real32_T f5;
  real32_T f6;
  int32_T k;
  real32_T A[100];
  static const int8_T iv0[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const int8_T iv1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 };

  static const int8_T iv2[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };

  static const int8_T iv3[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T iv4[10] = { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 };

  real32_T b_C[30];
  real32_T c_C[10];
  real32_T b_tf[3];
  real32_T J[9];
  real32_T d_C[30];
  real32_T maxima[9];
  real32_T f_total[6];
  int32_T b_it;
  boolean_T guard1 = false;
  int32_T exitg2;
  real32_T Fi[6];
  static const real32_T fv0[3] = { 0.0F, 0.0F, 9.81F };

  real32_T value_data[9];
  int32_T value_size[2];
  real32_T b_value_data[9];
  int32_T b_value_size[2];
  real32_T fv1[2];
  real32_T fv2[2];
  const mxArray *y;
  char_T u[7];
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *m0;
  static const int32_T iv5[2] = { 1, 7 };

  int32_T exitg1;
  const mxArray *b_y;
  real32_T fv3[2];
  real32_T motorForces[12];
  const mxArray *c_y;
  char_T b_u[16];
  static const char_T formatSpec[16] = { 'F', 'O', 'R', 'C', 'E', ' ', 'T', 'O',
    'O', ' ', 'H', 'I', 'G', 'H', '\\', 'n' };

  real32_T Mb[6];
  static const int32_T iv6[2] = { 1, 16 };

  const mxArray *d_y;
  char_T c_u[7];
  static const real32_T fv4[16] = { 1.0F, 0.4F, 0.0F, -2.0F, 1.0F, 0.0F, 0.4F,
    2.0F, 1.0F, -0.4F, 0.0F, -2.0F, 1.0F, 0.0F, -0.4F, 2.0F };

  static const int32_T iv7[2] = { 1, 7 };

  boolean_T x[4];
  const mxArray *e_y;
  boolean_T f_y;
  real32_T fv5[2];
  boolean_T exitg4;
  const mxArray *g_y;
  char_T d_u[33];
  static const char_T b_formatSpec[33] = { 'I', 'N', 'D', 'I', 'V', 'I', 'D',
    'U', 'A', 'L', ' ', 'M', 'O', 'T', 'O', 'R', ' ', 'F', 'O', 'R', 'C', 'E',
    ' ', 'T', 'O', 'O', ' ', 'H', 'I', 'G', 'H', '\\', 'n' };

  static const int32_T iv8[2] = { 1, 33 };

  real32_T Fi_prime[6];
  boolean_T exitg3;
  real32_T fv6[2];
  real32_T fv7[2];
  real32_T fv8[2];
  real32_T Fi_prime_prime[6];
  real32_T fv9[2];
  real32_T fv10[2];
  real32_T fv11[2];
  real32_T Omega_desired[6];
  real32_T Alpha_desired[6];
  real32_T Fi_bar_prime[6];
  real32_T Fi_bar_prime_prime[6];
  real32_T Fi_bar[6];
  real32_T c[3];
  real32_T b_Omega_desired[3];
  real32_T b_c[3];
  int32_T i1;
  real32_T c_Omega_desired[3];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b0 = false;
  b1 = false;
  b2 = false;
  b3 = false;
  b4 = false;
  b5 = false;
  b6 = false;
  b7 = false;
  b8 = false;
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0);

  /* UNTITLED Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*    This will solve for the coefficients of a constrained 9 order */
  /*    polynomial */
  /*  END_POINT_MODES: 'FULL', 'VEL', 'NOVEL' */
  /*  for vel and no vel use zeros in their place */
  /* the number of iterations */
  /* declare ti as zero */
  /* this is a ball park estimate of tf for starting */
  /* in the future it should take into account the distance */
  /* create variables for newton's method */
  t_start = 0.0F;
  t_end = 20.0F;
  t_mid = 10.0F;
  Error = 0;
  it = 0;
  while (it < 10) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 1);
    st.site = &e_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 2U, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 0);

    /* UNTITLED6 Summary of this function goes here */
    /*    This simply returns a 9 degree polynomial matrix */
    /* create the 10 x 10 matrix */
    b_st.site = &n_emlrtRSI;
    c_st.site = &s_emlrtRSI;
    d_st.site = &t_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    b = mpower(t_mid);
    b_st.site = &o_emlrtRSI;
    b_b = b_mpower(t_mid);
    b_st.site = &o_emlrtRSI;
    c_b = c_mpower(t_mid);
    b_st.site = &o_emlrtRSI;
    d_b = d_mpower(t_mid);
    b_st.site = &o_emlrtRSI;
    e_b = e_mpower(t_mid);
    b_st.site = &o_emlrtRSI;
    f_b = f_mpower(t_mid);
    b_st.site = &o_emlrtRSI;
    g_b = g_mpower(t_mid);
    b_st.site = &p_emlrtRSI;
    h_b = b_mpower(t_mid);
    b_st.site = &p_emlrtRSI;
    i_b = c_mpower(t_mid);
    b_st.site = &p_emlrtRSI;
    j_b = d_mpower(t_mid);
    b_st.site = &p_emlrtRSI;
    k_b = e_mpower(t_mid);
    b_st.site = &p_emlrtRSI;
    l_b = f_mpower(t_mid);
    b_st.site = &p_emlrtRSI;
    m_b = g_mpower(t_mid);
    b_st.site = &q_emlrtRSI;
    n_b = c_mpower(t_mid);
    b_st.site = &q_emlrtRSI;
    o_b = d_mpower(t_mid);
    b_st.site = &q_emlrtRSI;
    p_b = e_mpower(t_mid);
    b_st.site = &q_emlrtRSI;
    q_b = f_mpower(t_mid);
    b_st.site = &q_emlrtRSI;
    r_b = g_mpower(t_mid);
    b_st.site = &r_emlrtRSI;
    s_b = d_mpower(t_mid);
    b_st.site = &r_emlrtRSI;
    t_b = e_mpower(t_mid);
    b_st.site = &r_emlrtRSI;
    u_b = f_mpower(t_mid);
    b_st.site = &r_emlrtRSI;
    v_b = g_mpower(t_mid);
    b_st.site = &n_emlrtRSI;
    f0 = mpower(t_mid);
    b_st.site = &n_emlrtRSI;
    f1 = b_mpower(t_mid);
    b_st.site = &n_emlrtRSI;
    f2 = c_mpower(t_mid);
    b_st.site = &n_emlrtRSI;
    f3 = d_mpower(t_mid);
    b_st.site = &n_emlrtRSI;
    f4 = e_mpower(t_mid);
    b_st.site = &n_emlrtRSI;
    f5 = f_mpower(t_mid);
    b_st.site = &n_emlrtRSI;
    f6 = g_mpower(t_mid);
    for (k = 0; k < 10; k++) {
      A[10 * k] = iv0[k];
      A[1 + 10 * k] = iv1[k];
      A[2 + 10 * k] = iv2[k];
      A[3 + 10 * k] = iv3[k];
      A[4 + 10 * k] = iv4[k];
    }

    A[5] = muSingleScalarPower(t_mid, 9.0F);
    A[15] = f0;
    A[25] = f1;
    A[35] = f2;
    A[45] = f3;
    A[55] = f4;
    A[65] = f5;
    A[75] = f6;
    A[85] = t_mid;
    A[95] = 1.0F;
    A[6] = 9.0F * b;
    A[16] = 8.0F * b_b;
    A[26] = 7.0F * c_b;
    A[36] = 6.0F * d_b;
    A[46] = 5.0F * e_b;
    A[56] = 4.0F * f_b;
    A[66] = 3.0F * g_b;
    A[76] = 2.0F * t_mid;
    A[86] = 1.0F;
    A[96] = 0.0F;
    A[7] = 72.0F * h_b;
    A[17] = 56.0F * i_b;
    A[27] = 42.0F * j_b;
    A[37] = 30.0F * k_b;
    A[47] = 20.0F * l_b;
    A[57] = 12.0F * m_b;
    A[67] = 6.0F * t_mid;
    A[77] = 1.0F;
    A[87] = 0.0F;
    A[97] = 0.0F;
    A[8] = 504.0F * n_b;
    A[18] = 336.0F * o_b;
    A[28] = 210.0F * p_b;
    A[38] = 120.0F * q_b;
    A[48] = 60.0F * r_b;
    A[58] = 24.0F * t_mid;
    A[68] = 1.0F;
    A[78] = 0.0F;
    A[88] = 0.0F;
    A[98] = 0.0F;
    A[9] = 3024.0F * s_b;
    A[19] = 1680.0F * t_b;
    A[29] = 840.0F * u_b;
    A[39] = 360.0F * v_b;
    A[49] = 120.0F * t_mid;
    A[59] = 1.0F;
    A[69] = 0.0F;
    A[79] = 0.0F;
    A[89] = 0.0F;
    A[99] = 0.0F;

    /* solve for the coefficient matrix */
    memset(&b_C[0], 0, 30U * sizeof(real32_T));
    for (k = 0; k < 10; k++) {
      c_C[k] = X[k];
    }

    st.site = &f_emlrtRSI;
    mldivide(&st, A, c_C);
    for (k = 0; k < 10; k++) {
      b_C[3 * k] = c_C[k];
      c_C[k] = Y[k];
    }

    st.site = &g_emlrtRSI;
    mldivide(&st, A, c_C);
    for (k = 0; k < 10; k++) {
      b_C[1 + 3 * k] = c_C[k];
      c_C[k] = Z[k];
    }

    st.site = &h_emlrtRSI;
    mldivide(&st, A, c_C);
    for (k = 0; k < 10; k++) {
      b_C[2 + 3 * k] = c_C[k];
    }

    /* now that we have the Coefficient matrix run the calculate Actuator */
    /* feasibility function */
    st.site = &i_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3U, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 0);

    /* UNTITLED4 Summary of this function goes here */
    /*    This function will test a given set of polynomials to see if they fit */
    /*    within the actuator constraints specified */
    /*    ESSENTIALLY */
    /*    Coefficients: a 3X10 Matrix of coefficients */
    /*    Mass */
    /*    Moment - moment vector */
    /*    tf: the final time */
    /* MinZForce = the minumum force in the z direction typlically gravity (-45) */
    /* the distance of each motor from the center of mass */
    /* coefficient of drag related to yaw drag */
    /* gravity */
    /* create the moment matrix */
    J[0] = Moment[0];
    J[3] = 0.0F;
    J[6] = 0.0F;
    J[1] = 0.0F;
    J[4] = Moment[1];
    J[7] = 0.0F;
    J[2] = 0.0F;
    J[5] = 0.0F;
    J[8] = Moment[2];

    /*  Find the maximum accelerations */
    memcpy(&d_C[0], &b_C[0], 30U * sizeof(real32_T));
    b_st.site = &pb_emlrtRSI;
    calculateMaximums(&b_st, d_C, t_mid, maxima);

    /* create the fTot */
    for (k = 0; k < 6; k++) {
      f_total[k] = 0.0F;
    }

    /* now test whether these maximums are within feasible limits */
    b_it = 0;
    guard1 = false;
    do {
      exitg2 = 0;
      if (b_it < 2) {
        covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 1);

        /* calculate the magnitude of the acceleration gravity while taking into */
        /* account mass and gravity */
        /* mag is the [0, 0, 0, F_Total]' vector of the quadrotor. It must not */
        /* exceed the maximum possible acceleration */
        for (k = 0; k < 3; k++) {
          f_total[k + 3 * b_it] = Mass * (maxima[k + 3 * b_it] + fv0[k]);
        }

        if (covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 0, norm(*(real32_T (*)
               [3])&f_total[3 * b_it]) > MaxForce) || covrtLogCond
            (&emlrtCoverageInstance, 3U, 0U, 1, f_total[2 + 3 * b_it] <=
             MinZForce)) {
          covrtLogMcdc(&emlrtCoverageInstance, 3U, 0U, 0, true);
          covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 0, true);
          covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 2);
          b_st.site = &qb_emlrtRSI;
          c_st.site = &hd_emlrtRSI;
          for (k = 0; k < 7; k++) {
            u[k] = cv2[k];
          }

          y = NULL;
          m0 = emlrtCreateCharArray(2, iv5);
          emlrtInitCharArrayR2013a(&c_st, 7, m0, &u[0]);
          emlrtAssign(&y, m0);
          b_y = NULL;
          m0 = emlrtCreateDoubleScalar(1.0);
          emlrtAssign(&b_y, m0);
          for (k = 0; k < 16; k++) {
            b_u[k] = formatSpec[k];
          }

          c_y = NULL;
          m0 = emlrtCreateCharArray(2, iv6);
          emlrtInitCharArrayR2013a(&c_st, 16, m0, &b_u[0]);
          emlrtAssign(&c_y, m0);
          d_st.site = &ld_emlrtRSI;
          emlrt_marshallIn(&d_st, c_feval(&d_st, y, b_y, c_y, &c_emlrtMCI),
                           "feval");
          Error = 1;
          exitg2 = 1;
        } else {
          covrtLogMcdc(&emlrtCoverageInstance, 3U, 0U, 0, false);
          covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 0, false);
          b_it++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }

          guard1 = false;
        }
      } else {
        covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 0);
        covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 3);

        /* now use a lot of physics and math to calculate the force each motor must */
        /* be exerting at each point */
        /* start by declaring the variables */
        /* inertial frame force vector */
        for (k = 0; k < 6; k++) {
          Fi[k] = 0.0F;
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[3 * k];
        }

        b_st.site = &rb_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &rb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        if (!b0) {
          for (k = 0; k < 2; k++) {
            fv1[k] = 0.0F;
          }

          b0 = true;
        }

        polyval(b_value_data, b_value_size, fv1, fv2);
        for (k = 0; k < 2; k++) {
          Fi[3 * k] = Mass * fv2[k];
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[1 + 3 * k];
        }

        b_st.site = &sb_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &sb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        if (!b1) {
          for (k = 0; k < 2; k++) {
            fv3[k] = 0.0F;
          }

          b1 = true;
        }

        polyval(b_value_data, b_value_size, fv3, fv2);
        for (k = 0; k < 2; k++) {
          Fi[1 + 3 * k] = Mass * fv2[k];
        }

        /*  add g to the  */
        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[2 + 3 * k];
        }

        b_st.site = &tb_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &tb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        if (!b2) {
          for (k = 0; k < 2; k++) {
            fv5[k] = 0.0F;
          }

          b2 = true;
        }

        polyval(b_value_data, b_value_size, fv5, fv2);
        for (k = 0; k < 2; k++) {
          Fi[2 + 3 * k] = Mass * (fv2[k] + 9.81F);
        }

        /*  create the first derivative of force vector */
        for (k = 0; k < 6; k++) {
          Fi_prime[k] = 0.0F;
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[3 * k];
        }

        b_st.site = &ub_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &ub_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        b_st.site = &ub_emlrtRSI;
        polyder(&b_st, b_value_data, b_value_size, value_data, value_size);
        if (!b3) {
          for (k = 0; k < 2; k++) {
            fv6[k] = 0.0F;
          }

          b3 = true;
        }

        polyval(value_data, value_size, fv6, fv2);
        for (k = 0; k < 2; k++) {
          Fi_prime[3 * k] = Mass * fv2[k];
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[1 + 3 * k];
        }

        b_st.site = &vb_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &vb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        b_st.site = &vb_emlrtRSI;
        polyder(&b_st, b_value_data, b_value_size, value_data, value_size);
        if (!b4) {
          for (k = 0; k < 2; k++) {
            fv7[k] = 0.0F;
          }

          b4 = true;
        }

        polyval(value_data, value_size, fv7, fv2);
        for (k = 0; k < 2; k++) {
          Fi_prime[1 + 3 * k] = Mass * fv2[k];
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[2 + 3 * k];
        }

        b_st.site = &wb_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &wb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        b_st.site = &wb_emlrtRSI;
        polyder(&b_st, b_value_data, b_value_size, value_data, value_size);
        if (!b5) {
          for (k = 0; k < 2; k++) {
            fv8[k] = 0.0F;
          }

          b5 = true;
        }

        polyval(value_data, value_size, fv8, fv2);
        for (k = 0; k < 2; k++) {
          Fi_prime[2 + 3 * k] = Mass * fv2[k];
        }

        /*  create the first derivative of force vector */
        for (k = 0; k < 6; k++) {
          Fi_prime_prime[k] = 0.0F;
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[3 * k];
        }

        b_st.site = &xb_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &xb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        b_st.site = &xb_emlrtRSI;
        polyder(&b_st, b_value_data, b_value_size, value_data, value_size);
        b_st.site = &xb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        if (!b6) {
          for (k = 0; k < 2; k++) {
            fv9[k] = 0.0F;
          }

          b6 = true;
        }

        polyval(b_value_data, b_value_size, fv9, fv2);
        for (k = 0; k < 2; k++) {
          Fi_prime_prime[3 * k] = Mass * fv2[k];
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[1 + 3 * k];
        }

        b_st.site = &yb_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &yb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        b_st.site = &yb_emlrtRSI;
        polyder(&b_st, b_value_data, b_value_size, value_data, value_size);
        b_st.site = &yb_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        if (!b7) {
          for (k = 0; k < 2; k++) {
            fv10[k] = 0.0F;
          }

          b7 = true;
        }

        polyval(b_value_data, b_value_size, fv10, fv2);
        for (k = 0; k < 2; k++) {
          Fi_prime_prime[1 + 3 * k] = Mass * fv2[k];
        }

        for (k = 0; k < 10; k++) {
          c_C[k] = b_C[2 + 3 * k];
        }

        b_st.site = &ac_emlrtRSI;
        c_polyder(&b_st, c_C, value_data, value_size);
        b_st.site = &ac_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        b_st.site = &ac_emlrtRSI;
        polyder(&b_st, b_value_data, b_value_size, value_data, value_size);
        b_st.site = &ac_emlrtRSI;
        polyder(&b_st, value_data, value_size, b_value_data, b_value_size);
        if (!b8) {
          for (k = 0; k < 2; k++) {
            fv11[k] = 0.0F;
          }

          b8 = true;
        }

        polyval(b_value_data, b_value_size, fv11, fv2);
        for (k = 0; k < 2; k++) {
          Fi_prime_prime[2 + 3 * k] = Mass * fv2[k];
        }

        /* calculate the desired omega vector */
        /* Aplha desired calculation */
        /* Fi_bar_prime calc */
        /* Fi_bar_prime_prime calc */
        /* create the bar vector of Fi */
        /* moments */
        for (k = 0; k < 6; k++) {
          Omega_desired[k] = 0.0F;
          Alpha_desired[k] = 0.0F;
          Fi_bar_prime[k] = 0.0F;
          Fi_bar_prime_prime[k] = 0.0F;
          Fi_bar[k] = 0.0F;
          Mb[k] = 0.0F;
        }

        /* caclculate the bar and prime and alpha */
        b_it = 0;
        while (b_it < 2) {
          covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 1, 1);
          covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 4);
          e_b = norm(*(real32_T (*)[3])&Fi[3 * b_it]);

          /* Calculation of fi_bar_prime */
          c_b = norm(*(real32_T (*)[3])&Fi[3 * b_it]);
          d_b = 0.0F;
          for (k = 0; k < 3; k++) {
            Fi_bar[k + 3 * b_it] = Fi[k + 3 * b_it] / e_b;
            d_b += Fi[k + 3 * b_it] * Fi_prime[k + 3 * b_it];
          }

          b_st.site = &bc_emlrtRSI;
          b = f_mpower(norm(*(real32_T (*)[3])&Fi[3 * b_it]));

          /*  calcing fi_bar_prime_prime */
          e_b = norm(*(real32_T (*)[3])&Fi[3 * b_it]);
          f_b = 0.0F;
          g_b = 0.0F;
          h_b = 0.0F;
          for (k = 0; k < 3; k++) {
            Fi_bar_prime[k + 3 * b_it] = Fi_prime[k + 3 * b_it] / c_b - Fi[k + 3
              * b_it] * d_b / b;
            f_b += Fi[k + 3 * b_it] * Fi_prime[k + 3 * b_it];
            g_b += Fi_prime[k + 3 * b_it] * Fi_prime[k + 3 * b_it];
            h_b += Fi[k + 3 * b_it] * Fi_prime_prime[k + 3 * b_it];
          }

          b_st.site = &cc_emlrtRSI;
          b = f_mpower(norm(*(real32_T (*)[3])&Fi[3 * b_it]));
          d_b = 0.0F;
          for (k = 0; k < 3; k++) {
            d_b += Fi[k + 3 * b_it] * Fi_prime[k + 3 * b_it];
          }

          b_st.site = &cc_emlrtRSI;
          b_b = d_mpower(norm(*(real32_T (*)[3])&Fi[3 * b_it]));
          for (k = 0; k < 3; k++) {
            Fi_bar_prime_prime[k + 3 * b_it] = (Fi_prime_prime[k + 3 * b_it] /
              e_b - ((2.0F * Fi_prime[k + 3 * b_it] * f_b + Fi[k + 3 * b_it] *
                      g_b) + Fi[k + 3 * b_it] * h_b) / b) + 3.0F * Fi[k + 3 *
              b_it] * d_b / b_b;
          }

          /* the omega desired calc */
          Omega_desired[3 * b_it] = Fi_bar[1 + 3 * b_it] * Fi_bar_prime[2 + 3 *
            b_it] - Fi_bar[2 + 3 * b_it] * Fi_bar_prime[1 + 3 * b_it];
          Omega_desired[1 + 3 * b_it] = Fi_bar[2 + 3 * b_it] * Fi_bar_prime[3 *
            b_it] - Fi_bar[3 * b_it] * Fi_bar_prime[2 + 3 * b_it];
          Omega_desired[2 + 3 * b_it] = Fi_bar[3 * b_it] * Fi_bar_prime[1 + 3 *
            b_it] - Fi_bar[1 + 3 * b_it] * Fi_bar_prime[3 * b_it];

          /* set the z moment to zero */
          Omega_desired[2 + 3 * b_it] = 0.0F;

          /* the alpha vector */
          c[0] = Omega_desired[1 + 3 * b_it] * Fi_bar_prime[2 + 3 * b_it] -
            Omega_desired[2 + 3 * b_it] * Fi_bar_prime[1 + 3 * b_it];
          c[1] = Omega_desired[2 + 3 * b_it] * Fi_bar_prime[3 * b_it] -
            Omega_desired[3 * b_it] * Fi_bar_prime[2 + 3 * b_it];
          c[2] = Omega_desired[3 * b_it] * Fi_bar_prime[1 + 3 * b_it] -
            Omega_desired[1 + 3 * b_it] * Fi_bar_prime[3 * b_it];
          b_Omega_desired[0] = Omega_desired[1 + 3 * b_it] * c[2] -
            Omega_desired[2 + 3 * b_it] * c[1];
          b_Omega_desired[1] = Omega_desired[2 + 3 * b_it] * c[0] -
            Omega_desired[3 * b_it] * c[2];
          b_Omega_desired[2] = Omega_desired[3 * b_it] * c[1] - Omega_desired[1
            + 3 * b_it] * c[0];
          for (k = 0; k < 3; k++) {
            b_c[k] = Fi_bar_prime_prime[k + 3 * b_it] - b_Omega_desired[k];
            c[k] = 0.0F;
            for (i1 = 0; i1 < 3; i1++) {
              c[k] += J[k + 3 * i1] * Omega_desired[i1 + 3 * b_it];
            }
          }

          Alpha_desired[3 * b_it] = Fi_bar[1 + 3 * b_it] * b_c[2] - Fi_bar[2 + 3
            * b_it] * b_c[1];
          Alpha_desired[1 + 3 * b_it] = Fi_bar[2 + 3 * b_it] * b_c[0] - Fi_bar[3
            * b_it] * b_c[2];
          Alpha_desired[2 + 3 * b_it] = Fi_bar[3 * b_it] * b_c[1] - Fi_bar[1 + 3
            * b_it] * b_c[0];

          /* set the z to zero */
          Alpha_desired[2 + 3 * b_it] = 0.0F;

          /* FINALLY! now that we have the desired omega and the simulated current */
          /* omega, we can calcuate the exact forces that each motor must produce at a */
          /* given time(the maximum accelerations along a polynomial) */
          c_Omega_desired[0] = Omega_desired[1 + 3 * b_it] * c[2] -
            Omega_desired[2 + 3 * b_it] * c[1];
          c_Omega_desired[1] = Omega_desired[2 + 3 * b_it] * c[0] -
            Omega_desired[3 * b_it] * c[2];
          c_Omega_desired[2] = Omega_desired[3 * b_it] * c[1] - Omega_desired[1
            + 3 * b_it] * c[0];
          for (k = 0; k < 3; k++) {
            b_c[k] = 0.0F;
            for (i1 = 0; i1 < 3; i1++) {
              b_c[k] += J[k + 3 * i1] * Alpha_desired[i1 + 3 * b_it];
            }

            Mb[k + 3 * b_it] = b_c[k] + c_Omega_desired[k];
          }

          b_it++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 1, 0);
        covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 5);
        for (k = 0; k < 12; k++) {
          motorForces[k] = 0.0F;
        }

        b_it = 0;
        exitg2 = 2;
      }
    } while (exitg2 == 0);

    if (exitg2 == 1) {
    } else {
      do {
        exitg1 = 0;
        if (b_it < 2) {
          covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 2, 1);
          covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 6);
          f0 = norm(*(real32_T (*)[3])&f_total[3 * b_it]);
          motorForces[b_it << 2] = f0;
          motorForces[1 + (b_it << 2)] = Mb[3 * b_it];
          motorForces[2 + (b_it << 2)] = Mb[1 + 3 * b_it];
          motorForces[3 + (b_it << 2)] = Mb[2 + 3 * b_it];
          b_st.site = &dc_emlrtRSI;
          b_mldivide(&b_st, fv4, *(real32_T (*)[4])&motorForces[b_it << 2]);

          /*  while in the for loop check to see if the forces are within the */
          /*  bounds */
          for (k = 0; k < 4; k++) {
            x[k] = (motorForces[k + (b_it << 2)] <= 1.0F);
          }

          f_y = false;
          k = 0;
          exitg4 = false;
          while ((!exitg4) && (k < 4)) {
            if (!!x[k]) {
              f_y = true;
              exitg4 = true;
            } else {
              k++;
            }
          }

          if (covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 2, f_y)) {
            guard1 = true;
            exitg1 = 1;
          } else {
            d_b = MaxForce / 4.0F;
            for (k = 0; k < 4; k++) {
              x[k] = (motorForces[k + (b_it << 2)] >= d_b);
            }

            f_y = false;
            k = 0;
            exitg3 = false;
            while ((!exitg3) && (k < 4)) {
              if (!!x[k]) {
                f_y = true;
                exitg3 = true;
              } else {
                k++;
              }
            }

            if (covrtLogCond(&emlrtCoverageInstance, 3U, 0U, 3, f_y)) {
              guard1 = true;
              exitg1 = 1;
            } else {
              covrtLogMcdc(&emlrtCoverageInstance, 3U, 0U, 1, false);
              covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 1, false);
              b_it++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(&st);
              }
            }
          }
        } else {
          covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 2, 0);
          covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 8);

          /* IF YOU HAVE NOT RETURNED BY THIS POINT THE TRAJECTORY IS WITHIN FEASIBLE */
          /* LIMITS */
          Error = -1;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (guard1) {
      covrtLogMcdc(&emlrtCoverageInstance, 3U, 0U, 1, true);
      covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 1, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 7);
      b_st.site = &ec_emlrtRSI;
      c_st.site = &hd_emlrtRSI;
      for (k = 0; k < 7; k++) {
        c_u[k] = cv2[k];
      }

      d_y = NULL;
      m0 = emlrtCreateCharArray(2, iv7);
      emlrtInitCharArrayR2013a(&c_st, 7, m0, &c_u[0]);
      emlrtAssign(&d_y, m0);
      e_y = NULL;
      m0 = emlrtCreateDoubleScalar(1.0);
      emlrtAssign(&e_y, m0);
      for (k = 0; k < 33; k++) {
        d_u[k] = b_formatSpec[k];
      }

      g_y = NULL;
      m0 = emlrtCreateCharArray(2, iv8);
      emlrtInitCharArrayR2013a(&c_st, 33, m0, &d_u[0]);
      emlrtAssign(&g_y, m0);
      d_st.site = &ld_emlrtRSI;
      emlrt_marshallIn(&d_st, c_feval(&d_st, d_y, e_y, g_y, &c_emlrtMCI),
                       "feval");
      Error = 1;
    }

    /*  reasses the bounding points of the newton's method variables */
    if (covrtLogIf(&emlrtCoverageInstance, 1U, 0U, 0, Error == 1)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 2);
      t_start = t_mid;
      t_mid = (t_mid + t_end) / 2.0F;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 3);
      t_end = t_mid;
      t_mid = (t_mid + t_start) / 2.0F;
    }

    it++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 0);

  /* set the tf to the answer */
  if (covrtLogIf(&emlrtCoverageInstance, 1U, 0U, 1, Error == 1)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 4);
    tf = t_end;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 5);
    tf = t_mid;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 6);

  /* recalculate the Coefficient matrix one last time */
  st.site = &j_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 2U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 0);

  /* UNTITLED6 Summary of this function goes here */
  /*    This simply returns a 9 degree polynomial matrix */
  /* create the 10 x 10 matrix */
  b_st.site = &n_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  b_st.site = &o_emlrtRSI;
  b = mpower(tf);
  b_st.site = &o_emlrtRSI;
  b_b = b_mpower(tf);
  b_st.site = &o_emlrtRSI;
  c_b = c_mpower(tf);
  b_st.site = &o_emlrtRSI;
  d_b = d_mpower(tf);
  b_st.site = &o_emlrtRSI;
  e_b = e_mpower(tf);
  b_st.site = &o_emlrtRSI;
  f_b = f_mpower(tf);
  b_st.site = &o_emlrtRSI;
  g_b = g_mpower(tf);
  b_st.site = &p_emlrtRSI;
  h_b = b_mpower(tf);
  b_st.site = &p_emlrtRSI;
  i_b = c_mpower(tf);
  b_st.site = &p_emlrtRSI;
  j_b = d_mpower(tf);
  b_st.site = &p_emlrtRSI;
  k_b = e_mpower(tf);
  b_st.site = &p_emlrtRSI;
  l_b = f_mpower(tf);
  b_st.site = &p_emlrtRSI;
  m_b = g_mpower(tf);
  b_st.site = &q_emlrtRSI;
  n_b = c_mpower(tf);
  b_st.site = &q_emlrtRSI;
  o_b = d_mpower(tf);
  b_st.site = &q_emlrtRSI;
  p_b = e_mpower(tf);
  b_st.site = &q_emlrtRSI;
  q_b = f_mpower(tf);
  b_st.site = &q_emlrtRSI;
  r_b = g_mpower(tf);
  b_st.site = &r_emlrtRSI;
  s_b = d_mpower(tf);
  b_st.site = &r_emlrtRSI;
  t_b = e_mpower(tf);
  b_st.site = &r_emlrtRSI;
  u_b = f_mpower(tf);
  b_st.site = &r_emlrtRSI;
  v_b = g_mpower(tf);
  b_st.site = &n_emlrtRSI;
  f0 = mpower(tf);
  b_st.site = &n_emlrtRSI;
  f1 = b_mpower(tf);
  b_st.site = &n_emlrtRSI;
  f2 = c_mpower(tf);
  b_st.site = &n_emlrtRSI;
  f3 = d_mpower(tf);
  b_st.site = &n_emlrtRSI;
  f4 = e_mpower(tf);
  b_st.site = &n_emlrtRSI;
  f5 = f_mpower(tf);
  b_st.site = &n_emlrtRSI;
  f6 = g_mpower(tf);
  for (k = 0; k < 10; k++) {
    A[10 * k] = iv0[k];
    A[1 + 10 * k] = iv1[k];
    A[2 + 10 * k] = iv2[k];
    A[3 + 10 * k] = iv3[k];
    A[4 + 10 * k] = iv4[k];
  }

  A[5] = muSingleScalarPower(tf, 9.0F);
  A[15] = f0;
  A[25] = f1;
  A[35] = f2;
  A[45] = f3;
  A[55] = f4;
  A[65] = f5;
  A[75] = f6;
  A[85] = tf;
  A[95] = 1.0F;
  A[6] = 9.0F * b;
  A[16] = 8.0F * b_b;
  A[26] = 7.0F * c_b;
  A[36] = 6.0F * d_b;
  A[46] = 5.0F * e_b;
  A[56] = 4.0F * f_b;
  A[66] = 3.0F * g_b;
  A[76] = 2.0F * tf;
  A[86] = 1.0F;
  A[96] = 0.0F;
  A[7] = 72.0F * h_b;
  A[17] = 56.0F * i_b;
  A[27] = 42.0F * j_b;
  A[37] = 30.0F * k_b;
  A[47] = 20.0F * l_b;
  A[57] = 12.0F * m_b;
  A[67] = 6.0F * tf;
  A[77] = 1.0F;
  A[87] = 0.0F;
  A[97] = 0.0F;
  A[8] = 504.0F * n_b;
  A[18] = 336.0F * o_b;
  A[28] = 210.0F * p_b;
  A[38] = 120.0F * q_b;
  A[48] = 60.0F * r_b;
  A[58] = 24.0F * tf;
  A[68] = 1.0F;
  A[78] = 0.0F;
  A[88] = 0.0F;
  A[98] = 0.0F;
  A[9] = 3024.0F * s_b;
  A[19] = 1680.0F * t_b;
  A[29] = 840.0F * u_b;
  A[39] = 360.0F * v_b;
  A[49] = 120.0F * tf;
  A[59] = 1.0F;
  A[69] = 0.0F;
  A[79] = 0.0F;
  A[89] = 0.0F;
  A[99] = 0.0F;

  /* solve for the coefficient matrix */
  memset(&C[0], 0, 33U * sizeof(real32_T));
  for (k = 0; k < 10; k++) {
    c_C[k] = X[k];
  }

  st.site = &k_emlrtRSI;
  mldivide(&st, A, c_C);
  for (k = 0; k < 10; k++) {
    C[3 * k] = c_C[k];
    c_C[k] = Y[k];
  }

  st.site = &l_emlrtRSI;
  mldivide(&st, A, c_C);
  for (k = 0; k < 10; k++) {
    C[1 + 3 * k] = c_C[k];
    c_C[k] = Z[k];
  }

  st.site = &m_emlrtRSI;
  mldivide(&st, A, c_C);
  for (k = 0; k < 10; k++) {
    C[2 + 3 * k] = c_C[k];
  }

  b_tf[0] = tf;
  b_tf[1] = tf;
  b_tf[2] = tf;
  for (k = 0; k < 3; k++) {
    C[30 + k] = b_tf[k];
  }
}

/* End of code generation (polynomialTrajectorySolver.c) */
