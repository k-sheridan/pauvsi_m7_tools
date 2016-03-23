//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minimumTimeTrajectoryGenerator_rtwutil.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "minimumTimeTrajectoryGenerator_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
float rt_hypotf_snf(float u0, float u1)
{
  float y;
  float a;
  float b;
  a = (float)fabs((double)u0);
  b = (float)fabs((double)u1);
  if (a < b) {
    a /= b;
    y = b * (float)sqrt((double)(a * a + 1.0F));
  } else if (a > b) {
    b /= a;
    y = a * (float)sqrt((double)(b * b + 1.0F));
  } else if (rtIsNaNF(b)) {
    y = b;
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
float rt_powf_snf(float u0, float u1)
{
  float y;
  float f0;
  float f1;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = ((real32_T)rtNaN);
  } else {
    f0 = (float)fabs((double)u0);
    f1 = (float)fabs((double)u1);
    if (rtIsInfF(u1)) {
      if (f0 == 1.0F) {
        y = ((real32_T)rtNaN);
      } else if (f0 > 1.0F) {
        if (u1 > 0.0F) {
          y = ((real32_T)rtInf);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = ((real32_T)rtInf);
      }
    } else if (f1 == 0.0F) {
      y = 1.0F;
    } else if (f1 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (float)sqrt((double)u0);
    } else if ((u0 < 0.0F) && (u1 > (float)floor((double)u1))) {
      y = ((real32_T)rtNaN);
    } else {
      y = (float)pow((double)u0, (double)u1);
    }
  }

  return y;
}

//
// File trailer for minimumTimeTrajectoryGenerator_rtwutil.cpp
//
// [EOF]
//
