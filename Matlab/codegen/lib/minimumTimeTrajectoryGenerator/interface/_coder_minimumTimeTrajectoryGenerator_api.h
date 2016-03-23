/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_minimumTimeTrajectoryGenerator_api.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 22-Mar-2016 21:24:49
 */

#ifndef _CODER_MINIMUMTIMETRAJECTORYGENERATOR_API_H
#define _CODER_MINIMUMTIMETRAJECTORYGENERATOR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_minimumTimeTrajectoryGenerator_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T

typedef struct emxArray_real32_T emxArray_real32_T;

#endif                                 /*typedef_emxArray_real32_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void minimumTimeTrajectoryGenerator(real32_T start[15], emxArray_real32_T
  *mid, real32_T final[15], char_T MIDPOINT_MODE_data[], int32_T
  MIDPOINT_MODE_size[2], real32_T Mass, real32_T Moment[3], real32_T MaxVel,
  real32_T MinZForce, real32_T MaxForce, real32_T MaxAngle, emxArray_real32_T
  *Trajectory, real32_T *totalFlightTime);
extern void minimumTimeTrajectoryGenerator_api(const mxArray * const prhs[10],
  const mxArray *plhs[2]);
extern void minimumTimeTrajectoryGenerator_atexit(void);
extern void minimumTimeTrajectoryGenerator_initialize(void);
extern void minimumTimeTrajectoryGenerator_terminate(void);
extern void minimumTimeTrajectoryGenerator_xil_terminate(void);

#endif

/*
 * File trailer for _coder_minimumTimeTrajectoryGenerator_api.h
 *
 * [EOF]
 */
