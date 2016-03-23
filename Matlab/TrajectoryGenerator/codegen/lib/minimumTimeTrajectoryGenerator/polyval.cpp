//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyval.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "polyval.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const float p_data[]
//                const int p_size[2]
//                const float x[2]
//                float y[2]
// Return Type  : void
//
void polyval(const float p_data[], const int p_size[2], const float x[2], float
             y[2])
{
  int i4;
  int k;
  if (!(p_size[1] == 0)) {
    for (i4 = 0; i4 < 2; i4++) {
      y[i4] = p_data[0];
    }

    for (k = 0; k <= p_size[1] - 2; k++) {
      for (i4 = 0; i4 < 2; i4++) {
        y[i4] = x[i4] * y[i4] + p_data[k + 1];
      }
    }
  }
}

//
// File trailer for polyval.cpp
//
// [EOF]
//
