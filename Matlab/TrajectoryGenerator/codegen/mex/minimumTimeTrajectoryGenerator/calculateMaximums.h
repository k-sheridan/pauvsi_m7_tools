/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculateMaximums.h
 *
 * Code generation for function 'calculateMaximums'
 *
 */

#ifndef CALCULATEMAXIMUMS_H
#define CALCULATEMAXIMUMS_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "minimumTimeTrajectoryGenerator_types.h"

/* Function Declarations */
extern void calculateMaximums(const emlrtStack *sp, real32_T startCoefficients
  [30], real32_T tf, real32_T maximums[9]);

#endif

/* End of code generation (calculateMaximums.h) */
