/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyder.h
 *
 * Code generation for function 'polyder'
 *
 */

#ifndef POLYDER_H
#define POLYDER_H

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
extern void b_polyder(const emlrtStack *sp, const real32_T u[8], real32_T
                      a_data[], int32_T a_size[2]);
extern void c_polyder(const emlrtStack *sp, const real32_T u[10], real32_T
                      a_data[], int32_T a_size[2]);
extern void polyder(const emlrtStack *sp, const real32_T u_data[], const int32_T
                    u_size[2], real32_T a_data[], int32_T a_size[2]);

#endif

/* End of code generation (polyder.h) */
