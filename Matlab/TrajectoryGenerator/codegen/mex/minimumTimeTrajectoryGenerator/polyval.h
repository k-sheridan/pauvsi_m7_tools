/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyval.h
 *
 * Code generation for function 'polyval'
 *
 */

#ifndef POLYVAL_H
#define POLYVAL_H

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
extern void polyval(const real32_T p_data[], const int32_T p_size[2], const
                    real32_T x[2], real32_T y[2]);

#endif

/* End of code generation (polyval.h) */
