//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calculateActuatorFeasibility.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//
#ifndef CALCULATEACTUATORFEASIBILITY_H
#define CALCULATEACTUATORFEASIBILITY_H

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "minimumTimeTrajectoryGenerator_types.h"

// Function Declarations
extern float calculateActuatorFeasibility(const float Coefficients[30], float
  Mass, const float Moment[3], float MinZForce, float MaxForce, float tf);

#endif

//
// File trailer for calculateActuatorFeasibility.h
//
// [EOF]
//
