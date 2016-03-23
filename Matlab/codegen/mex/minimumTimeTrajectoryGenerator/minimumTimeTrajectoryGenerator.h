/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * minimumTimeTrajectoryGenerator.h
 *
 * Code generation for function 'minimumTimeTrajectoryGenerator'
 *
 */

#ifndef MINIMUMTIMETRAJECTORYGENERATOR_H
#define MINIMUMTIMETRAJECTORYGENERATOR_H

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
extern void minimumTimeTrajectoryGenerator(const emlrtStack *sp, const real32_T
  start[15], const emxArray_real32_T *mid, const real32_T final[15], const
  char_T MIDPOINT_MODE_data[], const int32_T MIDPOINT_MODE_size[2], real32_T
  Mass, const real32_T Moment[3], real32_T MaxVel, real32_T MinZForce, real32_T
  MaxForce, real32_T MaxAngle, emxArray_real32_T *Trajectory, real32_T
  *totalFlightTime);

#endif

/* End of code generation (minimumTimeTrajectoryGenerator.h) */
