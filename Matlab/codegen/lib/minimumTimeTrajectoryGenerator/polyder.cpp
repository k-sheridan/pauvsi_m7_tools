//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyder.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "polyder.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const float u[8]
//                float a_data[]
//                int a_size[2]
// Return Type  : void
//
void b_polyder(const float u[8], float a_data[], int a_size[2])
{
  int nlead0;
  int k;
  nlead0 = 0;
  k = 1;
  while ((k < 7) && (u[k - 1] == 0.0F)) {
    nlead0++;
    k++;
  }

  a_size[0] = 1;
  a_size[1] = 7 - nlead0;
  for (k = 0; k + 1 <= 7 - nlead0; k++) {
    a_data[k] = u[k + nlead0];
  }

  for (k = 0; k + 1 <= 6 - nlead0; k++) {
    a_data[k] *= (float)(6 - (nlead0 + k)) + 1.0F;
  }

  if (!((!rtIsInfF(u[7])) && (!rtIsNaNF(u[7])))) {
    a_data[6 - nlead0] = ((real32_T)rtNaN);
  }
}

//
// Arguments    : const float u[10]
//                float a_data[]
//                int a_size[2]
// Return Type  : void
//
void c_polyder(const float u[10], float a_data[], int a_size[2])
{
  int nlead0;
  int k;
  nlead0 = 0;
  k = 1;
  while ((k < 9) && (u[k - 1] == 0.0F)) {
    nlead0++;
    k++;
  }

  a_size[0] = 1;
  a_size[1] = 9 - nlead0;
  for (k = 0; k + 1 <= 9 - nlead0; k++) {
    a_data[k] = u[k + nlead0];
  }

  for (k = 0; k + 1 <= 8 - nlead0; k++) {
    a_data[k] *= (float)(8 - (nlead0 + k)) + 1.0F;
  }

  if (!((!rtIsInfF(u[9])) && (!rtIsNaNF(u[9])))) {
    a_data[8 - nlead0] = ((real32_T)rtNaN);
  }
}

//
// Arguments    : const float u_data[]
//                const int u_size[2]
//                float a_data[]
//                int a_size[2]
// Return Type  : void
//
void polyder(const float u_data[], const int u_size[2], float a_data[], int
             a_size[2])
{
  int nymax;
  int nlead0;
  int k;
  if (u_size[1] < 2) {
    nymax = 0;
  } else {
    nymax = u_size[1] - 2;
  }

  a_size[0] = 1;
  a_size[1] = nymax + 1;
  if ((u_size[1] == 0) || (u_size[1] == 1)) {
    a_data[0] = 0.0F;
  } else {
    nlead0 = -1;
    k = 1;
    while ((k <= nymax) && (u_data[k - 1] == 0.0F)) {
      nlead0++;
      k++;
    }

    nymax -= nlead0;
    a_size[0] = 1;
    a_size[1] = nymax;
    for (k = 1; k <= nymax; k++) {
      a_data[k - 1] = u_data[k + nlead0];
    }
  }

  nymax = a_size[1] - 1;
  for (k = 0; k + 1 <= nymax; k++) {
    a_data[k] *= (float)(nymax - k) + 1.0F;
  }

  if ((!(u_size[1] == 0)) && (!((!rtIsInfF(u_data[u_size[1] - 1])) && (!rtIsNaNF
         (u_data[u_size[1] - 1]))))) {
    a_data[a_size[1] - 1] = ((real32_T)rtNaN);
  }
}

//
// File trailer for polyder.cpp
//
// [EOF]
//
