/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "error.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo f_emlrtRTEI = { 17, 9, "error",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/error.m" };

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &f_emlrtRTEI, "MATLAB:nomem", 0);
}

void c_error(const emlrtStack *sp, int32_T varargin_2)
{
  emlrtErrorWithMessageIdR2012b(sp, &f_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 13, "LAPACKE_cgeev", 12,
    varargin_2);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &f_emlrtRTEI, "MATLAB:roots:NonFiniteInput",
    0);
}

/* End of code generation (error.c) */
