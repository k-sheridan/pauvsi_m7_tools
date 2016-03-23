//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polynomialTrajectorySolver.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//
#ifndef POLYNOMIALTRAJECTORYSOLVER_H
#define POLYNOMIALTRAJECTORYSOLVER_H

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "minimumTimeTrajectoryGenerator_types.h"

// Function Declarations
extern void polynomialTrajectorySolver(const float X[10], const float Y[10],
  const float Z[10], float Mass, const float Moment[3], float MinZForce, float
  MaxForce, float C[33]);

#endif

//
// File trailer for polynomialTrajectorySolver.h
//
// [EOF]
//
