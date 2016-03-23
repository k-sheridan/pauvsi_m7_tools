/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_minimumTimeTrajectoryGenerator_mex.cpp
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 22-Mar-2016 21:24:49
 */

/* Include Files */
#include "_coder_minimumTimeTrajectoryGenerator_api.h"
#include "_coder_minimumTimeTrajectoryGenerator_mex.h"
#include <stdio.h>

/* Function Declarations */
static void c_minimumTimeTrajectoryGenerato(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[10]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[10]
 * Return Type  : void
 */
static void c_minimumTimeTrajectoryGenerato(int32_T nlhs, mxArray *plhs[2],
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

/*
 * Arguments    : int32_T nlhs
 *                const mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(minimumTimeTrajectoryGenerator_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  minimumTimeTrajectoryGenerator_initialize();

  /* Dispatch the entry-point. */
  c_minimumTimeTrajectoryGenerato(nlhs, plhs, nrhs, prhs);
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_minimumTimeTrajectoryGenerator_mex.cpp
 *
 * [EOF]
 */
