/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_minimumTimeTrajectoryGenerator_api.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 22-Mar-2016 21:24:49
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_minimumTimeTrajectoryGenerator_api.h"
#include "_coder_minimumTimeTrajectoryGenerator_mex.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131434U, NULL,
  "minimumTimeTrajectoryGenerator", NULL, false, { 2045744189U, 2170104910U,
    2743257031U, 4284093946U }, NULL };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[15]);
static const mxArray *b_emlrt_marshallOut(const real32_T u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mid, const
  char_T *identifier, emxArray_real32_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MIDPOINT_MODE, const char_T *identifier, char_T y_data[], int32_T y_size[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *start, const
  char_T *identifier, real32_T y[15]);
static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_real32_T(emxArray_real32_T **pEmxArray);
static void emxInit_real32_T(const emlrtStack *sp, emxArray_real32_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real32_T1(const emlrtStack *sp, emxArray_real32_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y_data[], int32_T y_size[2]);
static real32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Mass,
  const char_T *identifier);
static real32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Moment,
  const char_T *identifier, real32_T y[3]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[3]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[15]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret_data[], int32_T ret_size[2]);
static real32_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[3]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[15]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[15])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real32_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(real32_T *)mxGetData(m1) = u;
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *mid
 *                const char_T *identifier
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mid, const
  char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(mid), &thisId, y);
  emlrtDestroyArray(&mid);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real32_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *MIDPOINT_MODE
 *                const char_T *identifier
 *                char_T y_data[]
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MIDPOINT_MODE, const char_T *identifier, char_T y_data[], int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(MIDPOINT_MODE), &thisId, y_data, y_size);
  emlrtDestroyArray(&MIDPOINT_MODE);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *start
 *                const char_T *identifier
 *                real32_T y[15]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *start, const
  char_T *identifier, real32_T y[15])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(start), &thisId, y);
  emlrtDestroyArray(&start);
}

/*
 * Arguments    : const emxArray_real32_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  real32_T *pData;
  int32_T i0;
  int32_T i;
  int32_T b_i;
  int32_T c_i;
  y = NULL;
  m0 = emlrtCreateNumericArray(3, *(int32_T (*)[3])u->size, mxSINGLE_CLASS,
    mxREAL);
  pData = (real32_T *)mxGetData(m0);
  i0 = 0;
  for (i = 0; i < u->size[2]; i++) {
    for (b_i = 0; b_i < 11; b_i++) {
      for (c_i = 0; c_i < 3; c_i++) {
        pData[i0] = u->data[(c_i + u->size[0] * b_i) + u->size[0] * u->size[1] *
          i];
        i0++;
      }
    }
  }

  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : emxArray__common *emxArray
 *                int32_T oldNumel
 *                int32_T elementSize
 * Return Type  : void
 */
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real32_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real32_T(emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (real32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real32_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real32_T(const emlrtStack *sp, emxArray_real32_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real32_T *)emlrtMallocMex(sizeof(emxArray_real32_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real32_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real32_T1(const emlrtStack *sp, emxArray_real32_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_real32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real32_T *)emlrtMallocMex(sizeof(emxArray_real32_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                char_T y_data[]
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y_data[], int32_T y_size[2])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Mass
 *                const char_T *identifier
 * Return Type  : real32_T
 */
static real32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Mass,
  const char_T *identifier)
{
  real32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(Mass), &thisId);
  emlrtDestroyArray(&Mass);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T
 */
static real32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Moment
 *                const char_T *identifier
 *                real32_T y[3]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Moment,
  const char_T *identifier, real32_T y[3])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(Moment), &thisId, y);
  emlrtDestroyArray(&Moment);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[3]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[3])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[15]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[15])
{
  static const int32_T dims[2] = { 3, 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real32_T *ret
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret)
{
  static const int32_T dims[2] = { 6, -1 };

  boolean_T bv0[2] = { false, true };

  int32_T iv0[2];
  int32_T i1;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims,
    &bv0[0], iv0);
  i1 = ret->size[0] * ret->size[1];
  ret->size[0] = iv0[0];
  ret->size[1] = iv0[1];
  emxEnsureCapacity((emxArray__common *)ret, i1, (int32_T)sizeof(real32_T));
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                char_T ret_data[]
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 10 };

  boolean_T bv1[2] = { false, true };

  int32_T iv1[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv1[0],
    iv1);
  ret_size[0] = iv1[0];
  ret_size[1] = iv1[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 1, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T
 */
static real32_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 0U, &dims);
  emlrtImportArrayR2015b(sp, src, &ret, 4, false);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[3]
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[3])
{
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[10]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
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
  emxInit_real32_T(&st, &mid, 2, true);
  emxInit_real32_T1(&st, &Trajectory, 3, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[0]), "start", start);
  c_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[1]), "mid", mid);
  emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[2]), "final", final);
  e_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[3]), "MIDPOINT_MODE",
                     MIDPOINT_MODE_data, MIDPOINT_MODE_size);
  Mass = g_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[4]), "Mass");
  i_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[5]), "Moment",
                     Moment);
  MaxVel = g_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[6]),
    "MaxVel");
  MinZForce = g_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[7]),
    "MinZForce");
  MaxForce = g_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[8]),
    "MaxForce");
  MaxAngle = g_emlrt_marshallIn(&st, emlrtAliasP((const mxArray *)prhs[9]),
    "MaxAngle");

  /* Invoke the target function */
  minimumTimeTrajectoryGenerator(start, mid, final, MIDPOINT_MODE_data,
    MIDPOINT_MODE_size, Mass, Moment, MaxVel, MinZForce, MaxForce, MaxAngle,
    Trajectory, &totalFlightTime);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(Trajectory);
  plhs[1] = b_emlrt_marshallOut(totalFlightTime);
  emxFree_real32_T(&Trajectory);
  emxFree_real32_T(&mid);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void minimumTimeTrajectoryGenerator_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  minimumTimeTrajectoryGenerator_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void minimumTimeTrajectoryGenerator_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void minimumTimeTrajectoryGenerator_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_minimumTimeTrajectoryGenerator_api.c
 *
 * [EOF]
 */
