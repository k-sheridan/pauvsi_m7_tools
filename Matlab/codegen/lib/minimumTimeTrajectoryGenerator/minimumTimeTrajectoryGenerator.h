//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minimumTimeTrajectoryGenerator.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//
#ifndef MINIMUMTIMETRAJECTORYGENERATOR_H
#define MINIMUMTIMETRAJECTORYGENERATOR_H

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "minimumTimeTrajectoryGenerator_types.h"

// Function Declarations
extern void minimumTimeTrajectoryGenerator(const float start[15], const
  emxArray_real32_T *mid, const float final[15], const char MIDPOINT_MODE_data[],
  const int MIDPOINT_MODE_size[2], float Mass, const float Moment[3], float
  MaxVel, float MinZForce, float MaxForce, float MaxAngle, emxArray_real32_T
  *Trajectory, float *totalFlightTime);

#endif

//
// File trailer for minimumTimeTrajectoryGenerator.h
//
// [EOF]
//
