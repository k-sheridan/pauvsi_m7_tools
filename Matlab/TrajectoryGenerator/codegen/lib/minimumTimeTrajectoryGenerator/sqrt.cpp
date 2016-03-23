//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sqrt.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "sqrt.h"
#include "xzlartg.h"
#include "minimumTimeTrajectoryGenerator_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : creal32_T *x
// Return Type  : void
//
void b_sqrt(creal32_T *x)
{
  float absxi;
  float absxr;
  if (x->im == 0.0F) {
    if (x->re < 0.0F) {
      absxi = 0.0F;
      absxr = (float)sqrt((double)(float)fabs((double)x->re));
    } else {
      absxi = (float)sqrt((double)x->re);
      absxr = 0.0F;
    }
  } else if (x->re == 0.0F) {
    if (x->im < 0.0F) {
      absxi = (float)sqrt((double)(-x->im / 2.0F));
      absxr = -absxi;
    } else {
      absxi = (float)sqrt((double)(x->im / 2.0F));
      absxr = absxi;
    }
  } else if (rtIsNaNF(x->re) || rtIsNaNF(x->im)) {
    absxi = ((real32_T)rtNaN);
    absxr = ((real32_T)rtNaN);
  } else if (rtIsInfF(x->im)) {
    absxi = ((real32_T)rtInf);
    absxr = x->im;
  } else if (rtIsInfF(x->re)) {
    if (x->re < 0.0F) {
      absxi = 0.0F;
      absxr = ((real32_T)rtInf);
    } else {
      absxi = ((real32_T)rtInf);
      absxr = 0.0F;
    }
  } else {
    absxr = (float)fabs((double)x->re);
    absxi = (float)fabs((double)x->im);
    if ((absxr > 8.50705867E+37F) || (absxi > 8.50705867E+37F)) {
      absxr *= 0.5F;
      absxi *= 0.5F;
      absxi = rt_hypotf_snf(absxr, absxi);
      if (absxi > absxr) {
        absxi = (float)sqrt((double)absxi) * (float)sqrt((double)(1.0F + absxr /
          absxi));
      } else {
        absxi = (float)sqrt((double)absxi) * 1.41421354F;
      }
    } else {
      absxi = (float)sqrt((double)((rt_hypotf_snf(absxr, absxi) + absxr) * 0.5F));
    }

    if (x->re > 0.0F) {
      absxr = 0.5F * (x->im / absxi);
    } else {
      if (x->im < 0.0F) {
        absxr = -absxi;
      } else {
        absxr = absxi;
      }

      absxi = 0.5F * (x->im / absxr);
    }
  }

  x->re = absxi;
  x->im = absxr;
}

//
// File trailer for sqrt.cpp
//
// [EOF]
//
