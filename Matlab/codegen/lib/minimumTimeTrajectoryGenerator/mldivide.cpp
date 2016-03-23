//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "mldivide.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const float A[100]
//                float B[10]
// Return Type  : void
//
void mldivide(const float A[100], float B[10])
{
  float b_A[100];
  signed char ipiv[10];
  int i5;
  int j;
  int k;
  int c;
  int kAcol;
  int ix;
  float smax;
  int jy;
  float s;
  int ijA;
  memcpy(&b_A[0], &A[0], 100U * sizeof(float));
  for (i5 = 0; i5 < 10; i5++) {
    ipiv[i5] = (signed char)(1 + i5);
  }

  for (j = 0; j < 9; j++) {
    c = j * 11;
    kAcol = 0;
    ix = c;
    smax = (float)fabs((double)b_A[c]);
    for (k = 2; k <= 10 - j; k++) {
      ix++;
      s = (float)fabs((double)b_A[ix]);
      if (s > smax) {
        kAcol = k - 1;
        smax = s;
      }
    }

    if (b_A[c + kAcol] != 0.0F) {
      if (kAcol != 0) {
        ipiv[j] = (signed char)((j + kAcol) + 1);
        ix = j;
        kAcol += j;
        for (k = 0; k < 10; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[kAcol];
          b_A[kAcol] = smax;
          ix += 10;
          kAcol += 10;
        }
      }

      i5 = (c - j) + 10;
      for (jy = c + 1; jy + 1 <= i5; jy++) {
        b_A[jy] /= b_A[c];
      }
    }

    kAcol = c;
    jy = c + 10;
    for (k = 1; k <= 9 - j; k++) {
      smax = b_A[jy];
      if (b_A[jy] != 0.0F) {
        ix = c + 1;
        i5 = (kAcol - j) + 20;
        for (ijA = 11 + kAcol; ijA + 1 <= i5; ijA++) {
          b_A[ijA] += b_A[ix] * -smax;
          ix++;
        }
      }

      jy += 10;
      kAcol += 10;
    }

    if (ipiv[j] != j + 1) {
      smax = B[j];
      B[j] = B[ipiv[j] - 1];
      B[ipiv[j] - 1] = smax;
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

  for (k = 9; k >= 0; k += -1) {
    kAcol = 10 * k;
    if (B[k] != 0.0F) {
      B[k] /= b_A[k + kAcol];
      for (jy = 0; jy + 1 <= k; jy++) {
        B[jy] -= B[k] * b_A[jy + kAcol];
      }
    }
  }
}

//
// File trailer for mldivide.cpp
//
// [EOF]
//
