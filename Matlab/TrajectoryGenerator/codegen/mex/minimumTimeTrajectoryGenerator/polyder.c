/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyder.c
 *
 * Code generation for function 'polyder'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "polyder.h"
#include "eml_int_forloop_overflow_check.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo lc_emlrtRSI = { 21, "polyder",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/polyder.m" };

static emlrtRSInfo mc_emlrtRSI = { 23, "polyder",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/polyder.m" };

static emlrtRSInfo oc_emlrtRSI = { 113, "polyder",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/polyder.m" };

static emlrtRTEInfo h_emlrtRTEI = { 111, 9, "polyder",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/polyder.m" };

static emlrtDCInfo emlrtDCI = { 112, 36, "polyder",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/polyder.m", 4
};

/* Function Definitions */
void b_polyder(const emlrtStack *sp, const real32_T u[8], real32_T a_data[],
               int32_T a_size[2])
{
  int32_T nlead0;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nlead0 = 0;
  k = 1;
  while ((k < 7) && (u[k - 1] == 0.0F)) {
    nlead0++;
    k++;
  }

  if (7 - nlead0 <= 7) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  a_size[0] = 1;
  k = 7 - nlead0;
  if (!(k >= 0)) {
    emlrtNonNegativeCheckR2012b(k, &emlrtDCI, &st);
  }

  a_size[1] = k;
  b_st.site = &oc_emlrtRSI;
  if ((!(1 > 7 - nlead0)) && (7 - nlead0 > 2147483646)) {
    c_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= 7 - nlead0; k++) {
    a_data[k] = u[k + nlead0];
  }

  st.site = &mc_emlrtRSI;
  for (k = 1; k <= 6 - nlead0; k++) {
    a_data[k - 1] *= (real32_T)(7 - (nlead0 + k)) + 1.0F;
  }

  if (!((!muSingleScalarIsInf(u[7])) && (!muSingleScalarIsNaN(u[7])))) {
    a_data[6 - nlead0] = ((real32_T)rtNaN);
  }
}

void c_polyder(const emlrtStack *sp, const real32_T u[10], real32_T a_data[],
               int32_T a_size[2])
{
  int32_T nlead0;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nlead0 = 0;
  k = 1;
  while ((k < 9) && (u[k - 1] == 0.0F)) {
    nlead0++;
    k++;
  }

  if (9 - nlead0 <= 9) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  a_size[0] = 1;
  k = 9 - nlead0;
  if (!(k >= 0)) {
    emlrtNonNegativeCheckR2012b(k, &emlrtDCI, &st);
  }

  a_size[1] = k;
  b_st.site = &oc_emlrtRSI;
  if ((!(1 > 9 - nlead0)) && (9 - nlead0 > 2147483646)) {
    c_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= 9 - nlead0; k++) {
    a_data[k] = u[k + nlead0];
  }

  st.site = &mc_emlrtRSI;
  for (k = 1; k <= 8 - nlead0; k++) {
    a_data[k - 1] *= (real32_T)(9 - (nlead0 + k)) + 1.0F;
  }

  if (!((!muSingleScalarIsInf(u[9])) && (!muSingleScalarIsNaN(u[9])))) {
    a_data[8 - nlead0] = ((real32_T)rtNaN);
  }
}

void polyder(const emlrtStack *sp, const real32_T u_data[], const int32_T
             u_size[2], real32_T a_data[], int32_T a_size[2])
{
  int32_T nymax;
  int32_T nlead0;
  int32_T k;
  int32_T ny;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lc_emlrtRSI;
  if (u_size[1] < 2) {
    nymax = 1;
  } else {
    nymax = u_size[1] - 1;
  }

  a_size[0] = 1;
  a_size[1] = nymax;
  if ((u_size[1] == 0) || (u_size[1] == 1)) {
    a_data[0] = 0.0F;
  } else {
    nlead0 = 0;
    k = 1;
    while ((k <= nymax - 1) && (u_data[k - 1] == 0.0F)) {
      nlead0++;
      k++;
    }

    ny = nymax - nlead0;
    if (ny <= nymax) {
    } else {
      emlrtErrorWithMessageIdR2012b(&st, &h_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    a_size[0] = 1;
    if (!(ny >= 0)) {
      emlrtNonNegativeCheckR2012b(ny, &emlrtDCI, &st);
    }

    a_size[1] = ny;
    for (k = 0; k + 1 <= ny; k++) {
      a_data[k] = u_data[k + nlead0];
    }
  }

  nymax = a_size[1];
  st.site = &mc_emlrtRSI;
  for (k = 1; k < nymax; k++) {
    a_data[k - 1] *= (real32_T)(nymax - k) + 1.0F;
  }

  if ((!(u_size[1] == 0)) && (!((!muSingleScalarIsInf(u_data[u_size[1] - 1])) &&
        (!muSingleScalarIsNaN(u_data[u_size[1] - 1]))))) {
    a_data[a_size[1] - 1] = ((real32_T)rtNaN);
  }
}

/* End of code generation (polyder.c) */
