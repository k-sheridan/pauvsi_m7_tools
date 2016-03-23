/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calculateMaximums.c
 *
 * Code generation for function 'calculateMaximums'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "calculateMaximums.h"
#include "polyder.h"
#include "roots.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo fc_emlrtRSI = { 20, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtRSInfo gc_emlrtRSI = { 19, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtRSInfo hc_emlrtRSI = { 18, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtRSInfo ic_emlrtRSI = { 11, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtRSInfo jc_emlrtRSI = { 10, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtRSInfo kc_emlrtRSI = { 9, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 44, 15, "rootsZ", "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 35, 15, "rootsY", "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 26, 15, "rootsX", "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 11, 4, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtECInfo b_emlrtECI = { -1, 10, 4, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

static emlrtECInfo c_emlrtECI = { -1, 9, 4, "calculateMaximums",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m"
};

/* Function Definitions */
void calculateMaximums(const emlrtStack *sp, real32_T startCoefficients[30],
  real32_T tf, real32_T maximums[9])
{
  int32_T it;
  int32_T loop_ub;
  int32_T k;
  real32_T b_startCoefficients[8];
  real32_T startCoefficients_data[10];
  int32_T tmp_data[9];
  int32_T b_loop_ub;
  real32_T b_tmp_data[7];
  int32_T tmp_size[2];
  int32_T fcnOutput_size[2];
  real32_T fcnOutput_data[9];
  int32_T iv12[2];
  creal32_T value_data[8];
  int32_T value_size[1];
  int32_T b_value_size[1];
  int32_T startCoefficients_size[2];
  int32_T iv13[2];
  int32_T c_value_size[1];
  int32_T b_startCoefficients_size[2];
  int32_T iv14[2];
  real32_T y;
  real32_T b_y;
  real32_T c_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 4U, 0);

  /* UNTITLED5 Summary of this function goes here */
  /*    this function uses a 3X10 coefficient matrix and a derivative count to */
  /*    calculate the maximums of a given set of functions at a given */
  /*    derivative */
  /* calculate the Coefficient matrix for the given derivative */
  it = 1;
  while (it - 1 < 2) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 0);
    loop_ub = 10 - it;
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] = k;
    }

    b_loop_ub = 11 - it;
    tmp_size[0] = 1;
    tmp_size[1] = b_loop_ub;
    for (k = 0; k < b_loop_ub; k++) {
      startCoefficients_data[k] = startCoefficients[3 * k];
    }

    st.site = &kc_emlrtRSI;
    polyder(&st, startCoefficients_data, tmp_size, fcnOutput_data,
            fcnOutput_size);
    iv12[0] = 1;
    iv12[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(iv12, 2, fcnOutput_size, 2, &c_emlrtECI, sp);
    loop_ub = fcnOutput_size[1];
    for (k = 0; k < loop_ub; k++) {
      startCoefficients[3 * tmp_data[k]] = fcnOutput_data[fcnOutput_size[0] * k];
    }

    loop_ub = 10 - it;
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] = k;
    }

    b_loop_ub = 11 - it;
    startCoefficients_size[0] = 1;
    startCoefficients_size[1] = b_loop_ub;
    for (k = 0; k < b_loop_ub; k++) {
      startCoefficients_data[k] = startCoefficients[1 + 3 * k];
    }

    st.site = &jc_emlrtRSI;
    polyder(&st, startCoefficients_data, startCoefficients_size, fcnOutput_data,
            fcnOutput_size);
    iv13[0] = 1;
    iv13[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(iv13, 2, fcnOutput_size, 2, &b_emlrtECI, sp);
    loop_ub = fcnOutput_size[1];
    for (k = 0; k < loop_ub; k++) {
      startCoefficients[1 + 3 * tmp_data[k]] = fcnOutput_data[fcnOutput_size[0] *
        k];
    }

    loop_ub = 10 - it;
    for (k = 0; k < loop_ub; k++) {
      tmp_data[k] = k;
    }

    b_loop_ub = 11 - it;
    b_startCoefficients_size[0] = 1;
    b_startCoefficients_size[1] = b_loop_ub;
    for (k = 0; k < b_loop_ub; k++) {
      startCoefficients_data[k] = startCoefficients[2 + 3 * k];
    }

    st.site = &ic_emlrtRSI;
    polyder(&st, startCoefficients_data, b_startCoefficients_size,
            fcnOutput_data, fcnOutput_size);
    iv14[0] = 1;
    iv14[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(iv14, 2, fcnOutput_size, 2, &emlrtECI, sp);
    loop_ub = fcnOutput_size[1];
    for (k = 0; k < loop_ub; k++) {
      startCoefficients[2 + 3 * tmp_data[k]] = fcnOutput_data[fcnOutput_size[0] *
        k];
    }

    it++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 1);

  /* reset the size of coeffs */
  /* find the roots of the next derivative and combine them into a roots vector */
  for (k = 0; k < 8; k++) {
    b_startCoefficients[k] = startCoefficients[3 * k];
  }

  st.site = &hc_emlrtRSI;
  b_polyder(&st, b_startCoefficients, b_tmp_data, tmp_size);
  fcnOutput_size[0] = 1;
  fcnOutput_size[1] = tmp_size[1];
  loop_ub = tmp_size[0] * tmp_size[1];
  for (k = 0; k < loop_ub; k++) {
    fcnOutput_data[k] = b_tmp_data[k];
  }

  st.site = &hc_emlrtRSI;
  roots(&st, fcnOutput_data, fcnOutput_size, value_data, value_size);
  for (k = 0; k < 8; k++) {
    b_startCoefficients[k] = startCoefficients[1 + 3 * k];
  }

  st.site = &gc_emlrtRSI;
  b_polyder(&st, b_startCoefficients, b_tmp_data, tmp_size);
  fcnOutput_size[0] = 1;
  fcnOutput_size[1] = tmp_size[1];
  loop_ub = tmp_size[0] * tmp_size[1];
  for (k = 0; k < loop_ub; k++) {
    fcnOutput_data[k] = b_tmp_data[k];
  }

  st.site = &gc_emlrtRSI;
  roots(&st, fcnOutput_data, fcnOutput_size, value_data, b_value_size);
  for (k = 0; k < 8; k++) {
    b_startCoefficients[k] = startCoefficients[2 + 3 * k];
  }

  st.site = &fc_emlrtRSI;
  b_polyder(&st, b_startCoefficients, b_tmp_data, tmp_size);
  fcnOutput_size[0] = 1;
  fcnOutput_size[1] = tmp_size[1];
  loop_ub = tmp_size[0] * tmp_size[1];
  for (k = 0; k < loop_ub; k++) {
    fcnOutput_data[k] = b_tmp_data[k];
  }

  st.site = &fc_emlrtRSI;
  roots(&st, fcnOutput_data, fcnOutput_size, value_data, c_value_size);

  /* combine the roots together without repeating for optimization */
  it = 0;
  while (it <= value_size[0] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 1, 1);
    k = (int32_T)(1.0F + (real32_T)it);
    if (!((k >= 1) && (k <= value_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, value_size[0], &db_emlrtBCI, sp);
    }

    covrtLogCond(&emlrtCoverageInstance, 4U, 0U, 0, false);
    covrtLogMcdc(&emlrtCoverageInstance, 4U, 0U, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 4U, 0U, 0, false);
    it++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 1, 0);
  it = 0;
  while (it <= b_value_size[0] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 2, 1);
    k = (int32_T)(1.0F + (real32_T)it);
    if (!((k >= 1) && (k <= b_value_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, b_value_size[0], &cb_emlrtBCI, sp);
    }

    covrtLogCond(&emlrtCoverageInstance, 4U, 0U, 4, false);
    covrtLogMcdc(&emlrtCoverageInstance, 4U, 0U, 2, false);
    covrtLogIf(&emlrtCoverageInstance, 4U, 0U, 2, false);
    it++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 2, 0);
  it = 0;
  while (it <= c_value_size[0] - 1) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 3, 1);
    k = (int32_T)(1.0F + (real32_T)it);
    if (!((k >= 1) && (k <= c_value_size[0]))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, c_value_size[0], &bb_emlrtBCI, sp);
    }

    covrtLogCond(&emlrtCoverageInstance, 4U, 0U, 8, false);
    covrtLogMcdc(&emlrtCoverageInstance, 4U, 0U, 4, false);
    covrtLogIf(&emlrtCoverageInstance, 4U, 0U, 4, false);
    it++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 3, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 5);
  for (k = 0; k < 9; k++) {
    maximums[k] = 0.0F;
  }

  it = 0;
  while (it < 2) {
    covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 4, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 6);
    y = startCoefficients[0];
    b_y = startCoefficients[1];
    c_y = startCoefficients[2];
    for (k = 0; k < 7; k++) {
      y = 0.0F * y + startCoefficients[3 * (k + 1)];
      b_y = 0.0F * b_y + startCoefficients[1 + 3 * (k + 1)];
      c_y = 0.0F * c_y + startCoefficients[2 + 3 * (k + 1)];
    }

    maximums[3 * it] = y;
    maximums[1 + 3 * it] = b_y;
    maximums[2 + 3 * it] = c_y;
    it++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 4U, 0U, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 7);
  y = startCoefficients[0];
  b_y = startCoefficients[1];
  c_y = startCoefficients[2];
  for (k = 0; k < 7; k++) {
    y = tf * y + startCoefficients[3 * (k + 1)];
    b_y = tf * b_y + startCoefficients[1 + 3 * (k + 1)];
    c_y = tf * c_y + startCoefficients[2 + 3 * (k + 1)];
  }

  maximums[6] = y;
  maximums[7] = b_y;
  maximums[8] = c_y;
}

/* End of code generation (calculateMaximums.c) */
