/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_minimumTimeTrajectoryGenerator_api.c
 *
 * Code generation for function '_coder_minimumTimeTrajectoryGenerator_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "_coder_minimumTimeTrajectoryGenerator_api.h"
#include "minimumTimeTrajectoryGenerator_emxutil.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, 1,
  "_coder_minimumTimeTrajectoryGenerator_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real32_T u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *start, const
  char_T *identifier, real32_T y[15]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[15]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mid, const
  char_T *identifier, emxArray_real32_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MIDPOINT_MODE, const char_T *identifier, char_T y_data[], int32_T y_size[2]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y_data[], int32_T y_size[2]);
static real32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Mass,
  const char_T *identifier);
static real32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Moment,
  const char_T *identifier, real32_T y[3]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[3]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[15]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret_data[], int32_T ret_size[2]);
static real32_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[3]);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real32_T u)
{
  const mxArray *y;
  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(real32_T *)mxGetData(m4) = u;
  emlrtAssign(&y, m4);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *start, const
  char_T *identifier, real32_T y[15])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(start), &thisId, y);
  emlrtDestroyArray(&start);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[15])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mid, const
  char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(mid), &thisId, y);
  emlrtDestroyArray(&mid);
}

static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  real32_T *pData;
  int32_T i5;
  int32_T i;
  int32_T b_i;
  int32_T c_i;
  y = NULL;
  m3 = emlrtCreateNumericArray(3, *(int32_T (*)[3])u->size, mxSINGLE_CLASS,
    mxREAL);
  pData = (real32_T *)mxGetData(m3);
  i5 = 0;
  for (i = 0; i < u->size[2]; i++) {
    for (b_i = 0; b_i < 11; b_i++) {
      for (c_i = 0; c_i < 3; c_i++) {
        pData[i5] = u->data[(c_i + u->size[0] * b_i) + u->size[0] * u->size[1] *
          i];
        i5++;
      }
    }
  }

  emlrtAssign(&y, m3);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y)
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MIDPOINT_MODE, const char_T *identifier, char_T y_data[], int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(MIDPOINT_MODE), &thisId, y_data, y_size);
  emlrtDestroyArray(&MIDPOINT_MODE);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y_data[], int32_T y_size[2])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static real32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Mass,
  const char_T *identifier)
{
  real32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(Mass), &thisId);
  emlrtDestroyArray(&Mass);
  return y;
}

static real32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Moment,
  const char_T *identifier, real32_T y[3])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(Moment), &thisId, y);
  emlrtDestroyArray(&Moment);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[3])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[15])
{
  static const int32_T dims[2] = { 3, 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret)
{
  static const int32_T dims[2] = { 6, -1 };

  boolean_T bv0[2] = { false, true };

  int32_T iv19[2];
  int32_T i6;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims,
    &bv0[0], iv19);
  i6 = ret->size[0] * ret->size[1];
  ret->size[0] = iv19[0];
  ret->size[1] = iv19[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i6, (int32_T)sizeof(real32_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 10 };

  boolean_T bv1[2] = { false, true };

  int32_T iv20[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv1[0],
    iv20);
  ret_size[0] = iv20[0];
  ret_size[1] = iv20[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 1, false);
  emlrtDestroyArray(&src);
}

static real32_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 0U, &dims);
  emlrtImportArrayR2015b(sp, src, &ret, 4, false);
  emlrtDestroyArray(&src);
  return ret;
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[3])
{
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

void minimumTimeTrajectoryGenerator_api(const mxArray * const prhs[10], const
  mxArray *plhs[2])
{
  emxArray_real32_T *mid;
  emxArray_real32_T *Trajectory;
  real32_T start[15];
  real32_T final[15];
  char_T MIDPOINT_MODE_data[10];
  int32_T MIDPOINT_MODE_size[2];
  real32_T Mass;
  real32_T Moment[3];
  real32_T MaxVel;
  real32_T MinZForce;
  real32_T MaxForce;
  real32_T MaxAngle;
  real32_T totalFlightTime;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real32_T1(&st, &mid, 2, &b_emlrtRTEI, true);
  emxInit_real32_T(&st, &Trajectory, 3, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "start", start);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "mid", mid);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "final", final);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "MIDPOINT_MODE",
                     MIDPOINT_MODE_data, MIDPOINT_MODE_size);
  Mass = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "Mass");
  k_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Moment", Moment);
  MaxVel = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "MaxVel");
  MinZForce = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "MinZForce");
  MaxForce = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "MaxForce");
  MaxAngle = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "MaxAngle");

  /* Invoke the target function */
  minimumTimeTrajectoryGenerator(&st, start, mid, final, MIDPOINT_MODE_data,
    MIDPOINT_MODE_size, Mass, Moment, MaxVel, MinZForce, MaxForce, MaxAngle,
    Trajectory, &totalFlightTime);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(Trajectory);
  plhs[1] = b_emlrt_marshallOut(totalFlightTime);
  emxFree_real32_T(&Trajectory);
  emxFree_real32_T(&mid);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_minimumTimeTrajectoryGenerator_api.c) */
