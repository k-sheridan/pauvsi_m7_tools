/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "mpower.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
real32_T b_mpower(real32_T a)
{
  return muSingleScalarPower(a, 7.0F);
}

real32_T c_mpower(real32_T a)
{
  return muSingleScalarPower(a, 6.0F);
}

real32_T d_mpower(real32_T a)
{
  return muSingleScalarPower(a, 5.0F);
}

real32_T e_mpower(real32_T a)
{
  return muSingleScalarPower(a, 4.0F);
}

real32_T f_mpower(real32_T a)
{
  return muSingleScalarPower(a, 3.0F);
}

real32_T g_mpower(real32_T a)
{
  return a * a;
}

real32_T mpower(real32_T a)
{
  return muSingleScalarPower(a, 8.0F);
}

/* End of code generation (mpower.c) */
