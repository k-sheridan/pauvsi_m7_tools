/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyval.c
 *
 * Code generation for function 'polyval'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "polyval.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
void polyval(const real32_T p_data[], const int32_T p_size[2], const real32_T x
             [2], real32_T y[2])
{
  int32_T i4;
  int32_T k;
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

/* End of code generation (polyval.c) */
