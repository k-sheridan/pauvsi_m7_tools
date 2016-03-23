/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * roots.c
 *
 * Code generation for function 'roots'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "roots.h"
#include "error.h"
#include "indexShapeCheck.h"
#include "warning.h"
#include "blas.h"
#include "lapacke.h"

/* Type Definitions */
#include "lapacke.h"
#include <stdlib.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = { 77, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo qc_emlrtRSI = { 103, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo rc_emlrtRSI = { 98, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo sc_emlrtRSI = { 97, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo tc_emlrtRSI = { 94, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo uc_emlrtRSI = { 88, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo vc_emlrtRSI = { 82, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo wc_emlrtRSI = { 28, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo xc_emlrtRSI = { 27, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo yc_emlrtRSI = { 110, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRSInfo bd_emlrtRSI = { 80, "eig",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/matfun/eig.m" };

static emlrtRSInfo cd_emlrtRSI = { 118, "eig",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/matfun/eig.m" };

static emlrtRSInfo dd_emlrtRSI = { 33, "xgeev",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m"
};

static emlrtRSInfo ed_emlrtRSI = { 101, "xgeev",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+lapack/xgeev.m"
};

static emlrtRSInfo fd_emlrtRSI = { 45, "infocheck",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"
};

static emlrtRSInfo gd_emlrtRSI = { 48, "infocheck",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 51, 1, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRTEInfo j_emlrtRTEI = { 54, 1, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRTEInfo k_emlrtRTEI = { 85, 5, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtRTEInfo l_emlrtRTEI = { 102, 5, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m" };

static emlrtDCInfo b_emlrtDCI = { 32, 19, "roots",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/polyfun/roots.m", 4 };

/* Function Definitions */
void roots(const emlrtStack *sp, const real32_T c_data[], const int32_T c_size[2],
           creal32_T r_data[], int32_T r_size[1])
{
  boolean_T p;
  int32_T k2;
  boolean_T exitg3;
  int32_T k1;
  int32_T nTrailingZeros;
  int32_T companDim;
  real32_T ctmp_data[9];
  boolean_T exitg1;
  int32_T iv15[2];
  boolean_T exitg2;
  creal32_T a_data[64];
  creal32_T vl;
  creal32_T A_data[64];
  creal32_T vr;
  creal32_T W_data[8];
  ptrdiff_t info_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  p = false;
  b_st.site = &yc_emlrtRSI;
  k2 = 0;
  exitg3 = false;
  while ((!exitg3) && (k2 + 1 <= c_size[1])) {
    if (!((!muSingleScalarIsInf(c_data[k2])) && (!muSingleScalarIsNaN(c_data[k2]))))
    {
      p = true;
      exitg3 = true;
    } else {
      k2++;
    }
  }

  if (p) {
    st.site = &wc_emlrtRSI;
    error(&st);
  }

  k2 = c_size[1] - 1;
  if (!(k2 >= 0)) {
    emlrtNonNegativeCheckR2012b(k2, &b_emlrtDCI, sp);
  }

  k1 = c_size[1] - 1;
  if (!(k1 >= 0)) {
    emlrtNonNegativeCheckR2012b(k1, &b_emlrtDCI, sp);
  }

  for (k2 = 0; k2 < k1; k2++) {
    r_data[k2].re = 0.0F;
    r_data[k2].im = 0.0F;
  }

  k1 = 1;
  while ((k1 <= c_size[1]) && (!(c_data[k1 - 1] != 0.0F))) {
    k1++;
  }

  k2 = c_size[1];
  while ((k2 >= k1) && (!(c_data[k2 - 1] != 0.0F))) {
    k2--;
  }

  if (k2 <= c_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &i_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  nTrailingZeros = c_size[1] - k2;
  if (nTrailingZeros <= c_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &j_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (k1 < k2) {
    companDim = k2 - k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      k2 = 0;
      exitg2 = false;
      while ((!exitg2) && (k2 + 1 <= companDim)) {
        ctmp_data[k2] = c_data[k1 + k2] / c_data[k1 - 1];
        if (muSingleScalarIsInf(muSingleScalarAbs(ctmp_data[k2]))) {
          exitg2 = true;
        } else {
          k2++;
        }
      }

      if (k2 + 1 > companDim) {
        exitg1 = true;
      } else {
        k1++;
        companDim--;
      }
    }

    if (companDim < 1) {
      if (1 > nTrailingZeros) {
        k2 = 0;
      } else {
        k2 = nTrailingZeros;
      }

      iv15[0] = 1;
      iv15[1] = k2;
      st.site = &vc_emlrtRSI;
      indexShapeCheck(&st, c_size[1] - 1, iv15);
      r_size[0] = k2;
    } else {
      if (companDim <= c_size[1]) {
      } else {
        emlrtErrorWithMessageIdR2012b(sp, &k_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      k1 = companDim * companDim;
      for (k2 = 0; k2 < k1; k2++) {
        a_data[k2].re = 0.0F;
        a_data[k2].im = 0.0F;
      }

      st.site = &uc_emlrtRSI;
      for (k2 = 0; k2 + 1 < companDim; k2++) {
        a_data[companDim * k2].re = -ctmp_data[k2];
        a_data[companDim * k2].im = 0.0F;
        a_data[(k2 + companDim * k2) + 1].re = 1.0F;
        a_data[(k2 + companDim * k2) + 1].im = 0.0F;
      }

      a_data[companDim * (companDim - 1)].re = -ctmp_data[companDim - 1];
      a_data[companDim * (companDim - 1)].im = 0.0F;
      st.site = &tc_emlrtRSI;
      for (k2 = 1; k2 <= nTrailingZeros; k2++) {
        r_data[k2 - 1].re = 0.0F;
        r_data[k2 - 1].im = 0.0F;
      }

      st.site = &sc_emlrtRSI;
      b_st.site = &bd_emlrtRSI;
      c_st.site = &dd_emlrtRSI;
      k1 = companDim * companDim;
      for (k2 = 0; k2 < k1; k2++) {
        A_data[k2] = a_data[k2];
      }

      info_t = LAPACKE_cgeev(102, 'N', 'N', (ptrdiff_t)companDim,
        (lapack_complex_float *)&A_data[0], (ptrdiff_t)companDim,
        (lapack_complex_float *)&W_data[0], (lapack_complex_float *)&vl,
        (ptrdiff_t)1, (lapack_complex_float *)&vr, (ptrdiff_t)1);
      k2 = (int32_T)info_t;
      d_st.site = &ed_emlrtRSI;
      if (k2 < 0) {
        if (k2 == -1010) {
          e_st.site = &fd_emlrtRSI;
          b_error(&e_st);
        } else {
          e_st.site = &gd_emlrtRSI;
          c_error(&e_st, k2);
        }
      }

      if (k2 != 0) {
        b_st.site = &cd_emlrtRSI;
        b_warning(&b_st);
      }

      st.site = &rc_emlrtRSI;
      for (k2 = 0; k2 + 1 <= companDim; k2++) {
        r_data[k2 + nTrailingZeros] = W_data[k2];
      }

      k2 = nTrailingZeros + companDim;
      if (k2 <= c_size[1]) {
      } else {
        emlrtErrorWithMessageIdR2012b(sp, &l_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (1 > k2) {
        k2 = 0;
      }

      iv15[0] = 1;
      iv15[1] = k2;
      st.site = &qc_emlrtRSI;
      indexShapeCheck(&st, c_size[1] - 1, iv15);
      r_size[0] = k2;
    }
  } else {
    if (1 > nTrailingZeros) {
      k2 = 0;
    } else {
      k2 = nTrailingZeros;
    }

    iv15[0] = 1;
    iv15[1] = k2;
    st.site = &pc_emlrtRSI;
    indexShapeCheck(&st, c_size[1] - 1, iv15);
    r_size[0] = k2;
  }
}

/* End of code generation (roots.c) */
