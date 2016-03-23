/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "mldivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 1, "mldivide",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/mldivide.p" };

static emlrtRSInfo v_emlrtRSI = { 42, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRSInfo w_emlrtRSI = { 101, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRSInfo x_emlrtRSI = { 99, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRSInfo y_emlrtRSI = { 144, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRSInfo ab_emlrtRSI = { 28, "xgetrf",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"
};

static emlrtRSInfo bb_emlrtRSI = { 36, "xzgetrf",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"
};

static emlrtRSInfo cb_emlrtRSI = { 50, "xzgetrf",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"
};

static emlrtRSInfo db_emlrtRSI = { 58, "xzgetrf",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+reflapack/xzgetrf.m"
};

static emlrtRSInfo eb_emlrtRSI = { 23, "ixamax",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+blas/ixamax.m"
};

static emlrtRSInfo fb_emlrtRSI = { 24, "ixamax",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+refblas/ixamax.m"
};

static emlrtRSInfo hb_emlrtRSI = { 45, "xgeru",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+blas/xgeru.m"
};

static emlrtRSInfo ib_emlrtRSI = { 45, "xger",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+blas/xger.m"
};

static emlrtRSInfo jb_emlrtRSI = { 15, "xger",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+refblas/xger.m"
};

static emlrtRSInfo kb_emlrtRSI = { 54, "xgerx",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"
};

static emlrtRSInfo lb_emlrtRSI = { 41, "xgerx",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+refblas/xgerx.m"
};

static emlrtRSInfo mb_emlrtRSI = { 76, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRSInfo nb_emlrtRSI = { 59, "xtrsm",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+blas/xtrsm.m"
};

static emlrtRSInfo ob_emlrtRSI = { 51, "xtrsm",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+refblas/xtrsm.m"
};

/* Function Definitions */
void b_mldivide(const emlrtStack *sp, const real32_T A[16], real32_T B[4])
{
  real32_T b_A[16];
  int8_T ipiv[4];
  int32_T kAcol;
  int32_T info;
  int32_T j;
  int32_T c;
  int32_T ix;
  real32_T temp;
  int32_T k;
  int32_T jy;
  real32_T s;
  int32_T b;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &u_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  b_st.site = &v_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  memcpy(&b_A[0], &A[0], sizeof(real32_T) << 4);
  for (kAcol = 0; kAcol < 4; kAcol++) {
    ipiv[kAcol] = (int8_T)(1 + kAcol);
  }

  info = 0;
  for (j = 0; j < 3; j++) {
    c = j * 5;
    e_st.site = &bb_emlrtRSI;
    f_st.site = &eb_emlrtRSI;
    kAcol = 0;
    ix = c;
    temp = muSingleScalarAbs(b_A[c]);
    g_st.site = &fb_emlrtRSI;
    for (k = 2; k <= 4 - j; k++) {
      ix++;
      s = muSingleScalarAbs(b_A[ix]);
      if (s > temp) {
        kAcol = k - 1;
        temp = s;
      }
    }

    if (b_A[c + kAcol] != 0.0F) {
      if (kAcol != 0) {
        ipiv[j] = (int8_T)((j + kAcol) + 1);
        ix = j;
        kAcol += j;
        for (k = 0; k < 4; k++) {
          temp = b_A[ix];
          b_A[ix] = b_A[kAcol];
          b_A[kAcol] = temp;
          ix += 4;
          kAcol += 4;
        }
      }

      b = (c - j) + 4;
      e_st.site = &cb_emlrtRSI;
      for (jy = c + 1; jy + 1 <= b; jy++) {
        b_A[jy] /= b_A[c];
      }
    } else {
      info = j + 1;
    }

    e_st.site = &db_emlrtRSI;
    f_st.site = &hb_emlrtRSI;
    g_st.site = &ib_emlrtRSI;
    h_st.site = &jb_emlrtRSI;
    kAcol = c;
    jy = c + 4;
    i_st.site = &lb_emlrtRSI;
    for (k = 1; k <= 3 - j; k++) {
      temp = b_A[jy];
      if (b_A[jy] != 0.0F) {
        ix = c + 1;
        b = (kAcol - j) + 8;
        i_st.site = &kb_emlrtRSI;
        if ((!(kAcol + 6 > b)) && (b > 2147483646)) {
          j_st.site = &gb_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }

        for (ijA = kAcol + 5; ijA + 1 <= b; ijA++) {
          b_A[ijA] += b_A[ix] * -temp;
          ix++;
        }
      }

      jy += 4;
      kAcol += 4;
    }
  }

  if ((info == 0) && (!(b_A[15] != 0.0F))) {
    info = 4;
  }

  if (info > 0) {
    c_st.site = &w_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    warning(&d_st);
  }

  for (kAcol = 0; kAcol < 3; kAcol++) {
    if (ipiv[kAcol] != kAcol + 1) {
      temp = B[kAcol];
      B[kAcol] = B[ipiv[kAcol] - 1];
      B[ipiv[kAcol] - 1] = temp;
    }
  }

  for (k = 0; k < 4; k++) {
    kAcol = k << 2;
    if (B[k] != 0.0F) {
      for (jy = k + 1; jy + 1 < 5; jy++) {
        B[jy] -= B[k] * b_A[jy + kAcol];
      }
    }
  }

  c_st.site = &y_emlrtRSI;
  d_st.site = &nb_emlrtRSI;
  for (k = 3; k >= 0; k += -1) {
    kAcol = k << 2;
    if (B[k] != 0.0F) {
      B[k] /= b_A[k + kAcol];
      e_st.site = &ob_emlrtRSI;
      for (jy = 0; jy + 1 <= k; jy++) {
        B[jy] -= B[k] * b_A[jy + kAcol];
      }
    }
  }
}

void mldivide(const emlrtStack *sp, const real32_T A[100], real32_T B[10])
{
  real32_T b_A[100];
  int8_T ipiv[10];
  int32_T kAcol;
  int32_T info;
  int32_T j;
  int32_T c;
  int32_T ix;
  real32_T temp;
  int32_T k;
  int32_T jy;
  real32_T s;
  int32_T b;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &u_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  b_st.site = &v_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  memcpy(&b_A[0], &A[0], 100U * sizeof(real32_T));
  for (kAcol = 0; kAcol < 10; kAcol++) {
    ipiv[kAcol] = (int8_T)(1 + kAcol);
  }

  info = 0;
  for (j = 0; j < 9; j++) {
    c = j * 11;
    e_st.site = &bb_emlrtRSI;
    f_st.site = &eb_emlrtRSI;
    kAcol = 0;
    ix = c;
    temp = muSingleScalarAbs(b_A[c]);
    g_st.site = &fb_emlrtRSI;
    for (k = 2; k <= 10 - j; k++) {
      ix++;
      s = muSingleScalarAbs(b_A[ix]);
      if (s > temp) {
        kAcol = k - 1;
        temp = s;
      }
    }

    if (b_A[c + kAcol] != 0.0F) {
      if (kAcol != 0) {
        ipiv[j] = (int8_T)((j + kAcol) + 1);
        ix = j;
        kAcol += j;
        for (k = 0; k < 10; k++) {
          temp = b_A[ix];
          b_A[ix] = b_A[kAcol];
          b_A[kAcol] = temp;
          ix += 10;
          kAcol += 10;
        }
      }

      b = (c - j) + 10;
      e_st.site = &cb_emlrtRSI;
      for (jy = c + 1; jy + 1 <= b; jy++) {
        b_A[jy] /= b_A[c];
      }
    } else {
      info = j + 1;
    }

    e_st.site = &db_emlrtRSI;
    f_st.site = &hb_emlrtRSI;
    g_st.site = &ib_emlrtRSI;
    h_st.site = &jb_emlrtRSI;
    kAcol = c;
    jy = c + 10;
    i_st.site = &lb_emlrtRSI;
    for (k = 1; k <= 9 - j; k++) {
      temp = b_A[jy];
      if (b_A[jy] != 0.0F) {
        ix = c + 1;
        b = (kAcol - j) + 20;
        i_st.site = &kb_emlrtRSI;
        if ((!(kAcol + 12 > b)) && (b > 2147483646)) {
          j_st.site = &gb_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }

        for (ijA = kAcol + 11; ijA + 1 <= b; ijA++) {
          b_A[ijA] += b_A[ix] * -temp;
          ix++;
        }
      }

      jy += 10;
      kAcol += 10;
    }
  }

  if ((info == 0) && (!(b_A[99] != 0.0F))) {
    info = 10;
  }

  if (info > 0) {
    c_st.site = &w_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    warning(&d_st);
  }

  for (kAcol = 0; kAcol < 9; kAcol++) {
    if (ipiv[kAcol] != kAcol + 1) {
      temp = B[kAcol];
      B[kAcol] = B[ipiv[kAcol] - 1];
      B[ipiv[kAcol] - 1] = temp;
    }
  }

  for (k = 0; k < 10; k++) {
    kAcol = 10 * k;
    if (B[k] != 0.0F) {
      for (jy = k + 1; jy + 1 < 11; jy++) {
        B[jy] -= B[k] * b_A[jy + kAcol];
      }
    }
  }

  c_st.site = &y_emlrtRSI;
  d_st.site = &nb_emlrtRSI;
  for (k = 9; k >= 0; k += -1) {
    kAcol = 10 * k;
    if (B[k] != 0.0F) {
      B[k] /= b_A[k + kAcol];
      e_st.site = &ob_emlrtRSI;
      for (jy = 0; jy + 1 <= k; jy++) {
        B[jy] -= B[k] * b_A[jy + kAcol];
      }
    }
  }
}

/* End of code generation (mldivide.c) */
