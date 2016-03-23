/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_minimumTimeTrajectoryGenerator_mex.c
 *
 * Code generation for function '_coder_minimumTimeTrajectoryGenerator_mex'
 *
 */

/* Include files */
#include "minimumTimeTrajectoryGenerator.h"
#include "_coder_minimumTimeTrajectoryGenerator_mex.h"
#include "minimumTimeTrajectoryGenerator_terminate.h"
#include "_coder_minimumTimeTrajectoryGenerator_api.h"
#include "minimumTimeTrajectoryGenerator_initialize.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Declarations */
static void d_minimumTimeTrajectoryGenerato(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[10]);

/* Function Definitions */
static void d_minimumTimeTrajectoryGenerato(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[10])
{
  int32_T n;
  const mxArray *inputs[10];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 10) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 10, 4,
                        30, "minimumTimeTrajectoryGenerator");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 30,
                        "minimumTimeTrajectoryGenerator");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  minimumTimeTrajectoryGenerator_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  minimumTimeTrajectoryGenerator_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(minimumTimeTrajectoryGenerator_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  minimumTimeTrajectoryGenerator_initialize();

  /* Dispatch the entry-point. */
  d_minimumTimeTrajectoryGenerato(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_minimumTimeTrajectoryGenerator_mex.c) */
