//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: roots.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "roots.h"
#include "xzgeev.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const float c_data[]
//                const int c_size[2]
//                creal32_T r_data[]
//                int r_size[1]
// Return Type  : void
//
void roots(const float c_data[], const int c_size[2], creal32_T r_data[], int
           r_size[1])
{
  int k2;
  int k1;
  int nTrailingZeros;
  int companDim;
  float ctmp_data[9];
  boolean_T exitg1;
  int a_size[2];
  boolean_T exitg2;
  creal32_T a_data[64];
  creal32_T eiga_data[8];
  int eiga_size[1];
  creal32_T beta1_data[8];
  int beta1_size[1];
  float eiga_data_re;
  float brm;
  float bim;
  float d;
  k2 = c_size[1];
  for (k1 = 0; k1 <= k2 - 2; k1++) {
    r_data[k1].re = 0.0F;
    r_data[k1].im = 0.0F;
  }

  k1 = 1;
  while ((k1 <= c_size[1]) && (!(c_data[k1 - 1] != 0.0F))) {
    k1++;
  }

  k2 = c_size[1];
  while ((k2 >= k1) && (!(c_data[k2 - 1] != 0.0F))) {
    k2--;
  }

  nTrailingZeros = c_size[1] - k2;
  if (k1 < k2) {
    companDim = k2 - k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      k2 = 0;
      exitg2 = false;
      while ((!exitg2) && (k2 + 1 <= companDim)) {
        ctmp_data[k2] = c_data[k1 + k2] / c_data[k1 - 1];
        if (rtIsInfF((float)fabs((double)ctmp_data[k2]))) {
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
        r_size[0] = 0;
      } else {
        r_size[0] = nTrailingZeros;
      }
    } else {
      a_size[0] = companDim;
      a_size[1] = companDim;
      k2 = companDim * companDim;
      for (k1 = 0; k1 < k2; k1++) {
        a_data[k1].re = 0.0F;
        a_data[k1].im = 0.0F;
      }

      for (k2 = 0; k2 + 1 < companDim; k2++) {
        a_data[companDim * k2].re = -ctmp_data[k2];
        a_data[companDim * k2].im = 0.0F;
        a_data[(k2 + companDim * k2) + 1].re = 1.0F;
        a_data[(k2 + companDim * k2) + 1].im = 0.0F;
      }

      a_data[companDim * (companDim - 1)].re = -ctmp_data[companDim - 1];
      a_data[companDim * (companDim - 1)].im = 0.0F;
      for (k2 = 1; k2 <= nTrailingZeros; k2++) {
        r_data[k2 - 1].re = 0.0F;
        r_data[k2 - 1].im = 0.0F;
      }

      xzgeev(a_data, a_size, &k2, eiga_data, eiga_size, beta1_data, beta1_size);
      k2 = eiga_size[0];
      for (k1 = 0; k1 < k2; k1++) {
        eiga_data_re = eiga_data[k1].re;
        if (beta1_data[k1].im == 0.0F) {
          if (eiga_data[k1].im == 0.0F) {
            eiga_data[k1].re /= beta1_data[k1].re;
            eiga_data[k1].im = 0.0F;
          } else if (eiga_data[k1].re == 0.0F) {
            eiga_data[k1].re = 0.0F;
            eiga_data[k1].im /= beta1_data[k1].re;
          } else {
            eiga_data[k1].re /= beta1_data[k1].re;
            eiga_data[k1].im /= beta1_data[k1].re;
          }
        } else if (beta1_data[k1].re == 0.0F) {
          if (eiga_data[k1].re == 0.0F) {
            eiga_data[k1].re = eiga_data[k1].im / beta1_data[k1].im;
            eiga_data[k1].im = 0.0F;
          } else if (eiga_data[k1].im == 0.0F) {
            eiga_data[k1].re = 0.0F;
            eiga_data[k1].im = -(eiga_data_re / beta1_data[k1].im);
          } else {
            eiga_data[k1].re = eiga_data[k1].im / beta1_data[k1].im;
            eiga_data[k1].im = -(eiga_data_re / beta1_data[k1].im);
          }
        } else {
          brm = (float)fabs((double)beta1_data[k1].re);
          bim = (float)fabs((double)beta1_data[k1].im);
          if (brm > bim) {
            bim = beta1_data[k1].im / beta1_data[k1].re;
            d = beta1_data[k1].re + bim * beta1_data[k1].im;
            eiga_data[k1].re = (eiga_data[k1].re + bim * eiga_data[k1].im) / d;
            eiga_data[k1].im = (eiga_data[k1].im - bim * eiga_data_re) / d;
          } else if (bim == brm) {
            if (beta1_data[k1].re > 0.0F) {
              bim = 0.5F;
            } else {
              bim = -0.5F;
            }

            if (beta1_data[k1].im > 0.0F) {
              d = 0.5F;
            } else {
              d = -0.5F;
            }

            eiga_data[k1].re = (eiga_data[k1].re * bim + eiga_data[k1].im * d) /
              brm;
            eiga_data[k1].im = (eiga_data[k1].im * bim - eiga_data_re * d) / brm;
          } else {
            bim = beta1_data[k1].re / beta1_data[k1].im;
            d = beta1_data[k1].im + bim * beta1_data[k1].re;
            eiga_data[k1].re = (bim * eiga_data[k1].re + eiga_data[k1].im) / d;
            eiga_data[k1].im = (bim * eiga_data[k1].im - eiga_data_re) / d;
          }
        }
      }

      for (k2 = 0; k2 + 1 <= companDim; k2++) {
        r_data[k2 + nTrailingZeros] = eiga_data[k2];
      }

      k2 = nTrailingZeros + companDim;
      if (1 > k2) {
        r_size[0] = 0;
      } else {
        r_size[0] = k2;
      }
    }
  } else if (1 > nTrailingZeros) {
    r_size[0] = 0;
  } else {
    r_size[0] = nTrailingZeros;
  }
}

//
// File trailer for roots.cpp
//
// [EOF]
//
