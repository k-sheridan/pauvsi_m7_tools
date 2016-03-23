/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "warning.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 14, 25, "warning",
  "/Applications/MATLAB_R2016a.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"
};

static emlrtMCInfo b_emlrtMCI = { 14, 9, "warning",
  "/Applications/MATLAB_R2016a.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"
};

static emlrtRSInfo md_emlrtRSI = { 14, "warning",
  "/Applications/MATLAB_R2016a.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 2, pArrays, "feval", true, location);
}

void b_warning(const emlrtStack *sp)
{
  int32_T i3;
  const mxArray *y;
  char_T u[7];
  static const char_T cv5[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m2;
  static const int32_T iv16[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv6[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv17[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[24];
  static const char_T msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'i',
    'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  static const int32_T iv18[2] = { 1, 24 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i3 = 0; i3 < 7; i3++) {
    u[i3] = cv5[i3];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  for (i3 = 0; i3 < 7; i3++) {
    b_u[i3] = cv6[i3];
  }

  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv17);
  emlrtInitCharArrayR2013a(sp, 7, m2, &b_u[0]);
  emlrtAssign(&b_y, m2);
  for (i3 = 0; i3 < 24; i3++) {
    c_u[i3] = msgID[i3];
  }

  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv18);
  emlrtInitCharArrayR2013a(sp, 24, m2, &c_u[0]);
  emlrtAssign(&c_y, m2);
  st.site = &md_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  int32_T i2;
  const mxArray *y;
  char_T u[7];
  static const char_T cv3[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m1;
  static const int32_T iv9[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv4[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv10[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[27];
  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  static const int32_T iv11[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i2 = 0; i2 < 7; i2++) {
    u[i2] = cv3[i2];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 7, m1, &u[0]);
  emlrtAssign(&y, m1);
  for (i2 = 0; i2 < 7; i2++) {
    b_u[i2] = cv4[i2];
  }

  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 7, m1, &b_u[0]);
  emlrtAssign(&b_y, m1);
  for (i2 = 0; i2 < 27; i2++) {
    c_u[i2] = msgID[i2];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 27, m1, &c_u[0]);
  emlrtAssign(&c_y, m1);
  st.site = &md_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

/* End of code generation (warning.c) */
