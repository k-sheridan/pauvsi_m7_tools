//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyder.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//
#ifndef POLYDER_H
#define POLYDER_H

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "minimumTimeTrajectoryGenerator_types.h"

// Function Declarations
extern void b_polyder(const float u[8], float a_data[], int a_size[2]);
extern void c_polyder(const float u[10], float a_data[], int a_size[2]);
extern void polyder(const float u_data[], const int u_size[2], float a_data[],
                    int a_size[2]);

#endif

//
// File trailer for polyder.h
//
// [EOF]
//
