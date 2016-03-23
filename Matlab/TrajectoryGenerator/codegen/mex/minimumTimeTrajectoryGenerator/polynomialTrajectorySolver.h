/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polynomialTrajectorySolver.h
 *
 * Code generation for function 'polynomialTrajectorySolver'
 *
 */

#ifndef POLYNOMIALTRAJECTORYSOLVER_H
#define POLYNOMIALTRAJECTORYSOLVER_H

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
extern void polynomialTrajectorySolver(const emlrtStack *sp, const real32_T X[10],
  const real32_T Y[10], const real32_T Z[10], real32_T Mass, const real32_T
  Moment[3], real32_T MinZForce, real32_T MaxForce, real32_T C[33]);

#endif

/* End of code generation (polynomialTrajectorySolver.h) */
