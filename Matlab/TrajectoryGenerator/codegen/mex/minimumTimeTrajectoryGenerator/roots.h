/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * roots.h
 *
 * Code generation for function 'roots'
 *
 */

#ifndef ROOTS_H
#define ROOTS_H

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

/* Type Definitions */
#include "lapacke.h"
#include <stdlib.h>

/* Function Declarations */
extern void roots(const emlrtStack *sp, const real32_T c_data[], const int32_T
                  c_size[2], creal32_T r_data[], int32_T r_size[1]);

#endif

/* End of code generation (roots.h) */
