/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "norm.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
real32_T norm(const real32_T x[3])
{
  real32_T y;
  real32_T scale;
  int32_T k;
  real32_T absxk;
  real32_T t;
  y = 0.0F;
  scale = 1.17549435E-38F;
  for (k = 0; k < 3; k++) {
    absxk = muSingleScalarAbs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0F + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muSingleScalarSqrt(y);
}

/* End of code generation (norm.c) */
