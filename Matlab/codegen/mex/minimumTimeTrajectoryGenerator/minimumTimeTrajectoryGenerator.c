/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * minimumTimeTrajectoryGenerator.c
 *
 * Code generation for function 'minimumTimeTrajectoryGenerator'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "minimumTimeTrajectoryGenerator_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "polynomialTrajectorySolver.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 25, "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m" };

static emlrtRSInfo b_emlrtRSI = { 29, "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m" };

static emlrtRSInfo c_emlrtRSI = { 31, "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m" };

static emlrtRSInfo d_emlrtRSI = { 41, "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m" };

static emlrtRSInfo id_emlrtRSI = { 9, "sum",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/sum.m" };

static emlrtRSInfo jd_emlrtRSI = { 58, "sumprod",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo kd_emlrtRSI = { 69, "combine_vector_elements",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 44, "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 25, 75, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 25, 86, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 25, 121, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 25, 132, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 25, 167, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 25, 178, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtRTEInfo c_emlrtRTEI = { 27, 5, "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m" };

static emlrtRTEInfo d_emlrtRTEI = { 20, 15, "sumprod",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 48, 9, "sumprod",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtBCInfo g_emlrtBCI = { -1, -1, 31, 79, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 31, 96, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 31, 137, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 31, 154, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 31, 195, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 31, 212, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 31, 29, "Trajectory",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 29, 79, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 29, 96, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 29, 122, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 29, 143, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 29, 175, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 29, 192, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 29, 218, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 29, 239, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 29, 271, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 29, 288, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 29, 314, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 29, 335, "mid",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 29, 29, "Trajectory",
  "minimumTimeTrajectoryGenerator",
  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
  "enerator.m", 0 };

/* Function Definitions */
void minimumTimeTrajectoryGenerator(const emlrtStack *sp, const real32_T start
  [15], const emxArray_real32_T *mid, const real32_T final[15], const char_T
  MIDPOINT_MODE_data[], const int32_T MIDPOINT_MODE_size[2], real32_T Mass,
  const real32_T Moment[3], real32_T MaxVel, real32_T MinZForce, real32_T
  MaxForce, real32_T MaxAngle, emxArray_real32_T *Trajectory, real32_T
  *totalFlightTime)
{
  int32_T i0;
  int32_T kstr;
  boolean_T overflow;
  int32_T exitg5;
  static const char_T cv0[3] = { 'V', 'E', 'L' };

  int32_T exitg4;
  static const char_T cv1[6] = { 'N', 'O', '_', 'V', 'E', 'L' };

  boolean_T guard1 = false;
  boolean_T p;
  int32_T k;
  real32_T b_start[10];
  boolean_T exitg3;
  boolean_T exitg2;
  real32_T c_start[10];
  int32_T b_k;
  emxArray_real32_T *b_Trajectory;
  int32_T exitg1;
  real32_T y;
  real32_T d_start[10];
  int32_T z_index;
  real32_T b_mid[10];
  real32_T c_mid[10];
  real32_T d_mid[10];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  (void)MaxVel;
  (void)MaxAngle;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0);

  /* UNTITLED7 Summary of this function goes here */
  /*    This will generate a trajectory that is flable by a quadrotor it may */
  /*    take a second. */
  /*    The format for start and end is [x_0, x_1, x_2, x_3, x_4] */
  /*                                    [y_0, y_1, y_2, y_3, y_4] */
  /*                                    [z_0, z_1, z_2, z_3, z_4] */
  /*  */
  /*    the format for mid is [x_0, x2_0, ...]    [x_0, x2_0] */
  /*                          [y_0, y2_0, ...]    [y_0, y2_0] */
  /*                          [z_0, z2_0, ...]    [z_0, z2_0] */
  /*                          [x_1, x2_1, ...] */
  /*                          [y_1, y2_1, ...] */
  /*                          [z_1, z2_1, ...] */
  /*                     MODE:     'VEL'            'NO_VEL'    'NONE' */
  /*                     */
  /* define Trajectory */
  i0 = Trajectory->size[0] * Trajectory->size[1] * Trajectory->size[2];
  Trajectory->size[0] = 3;
  Trajectory->size[1] = 11;
  Trajectory->size[2] = (int32_T)((real32_T)mid->size[1] + 1.0F);
  emxEnsureCapacity(sp, (emxArray__common *)Trajectory, i0, (int32_T)sizeof
                    (real32_T), &emlrtRTEI);
  kstr = 33 * (int32_T)((real32_T)mid->size[1] + 1.0F);
  for (i0 = 0; i0 < kstr; i0++) {
    Trajectory->data[i0] = 0.0F;
  }

  /* if this is in velocity mode */
  overflow = false;
  if (MIDPOINT_MODE_size[1] != 3) {
  } else {
    kstr = 0;
    do {
      exitg5 = 0;
      if (kstr + 1 < 4) {
        if (MIDPOINT_MODE_data[kstr] != cv0[kstr]) {
          exitg5 = 1;
        } else {
          kstr++;
        }
      } else {
        overflow = true;
        exitg5 = 1;
      }
    } while (exitg5 == 0);
  }

  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, overflow)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1);
    i0 = mid->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &emlrtBCI, sp);
    }

    i0 = mid->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &b_emlrtBCI, sp);
    }

    i0 = mid->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &c_emlrtBCI, sp);
    }

    i0 = mid->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &d_emlrtBCI, sp);
    }

    i0 = mid->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &e_emlrtBCI, sp);
    }

    i0 = mid->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &f_emlrtBCI, sp);
    }

    for (i0 = 0; i0 < 5; i0++) {
      b_start[i0] = start[3 * i0];
    }

    b_start[5] = mid->data[0];
    b_start[6] = mid->data[3];
    b_start[7] = 0.0F;
    b_start[8] = 0.0F;
    b_start[9] = 0.0F;
    for (i0 = 0; i0 < 5; i0++) {
      c_start[i0] = start[1 + 3 * i0];
    }

    c_start[5] = mid->data[1];
    c_start[6] = mid->data[4];
    c_start[7] = 0.0F;
    c_start[8] = 0.0F;
    c_start[9] = 0.0F;
    for (i0 = 0; i0 < 5; i0++) {
      d_start[i0] = start[2 + 3 * i0];
    }

    d_start[5] = mid->data[2];
    d_start[6] = mid->data[5];
    d_start[7] = 0.0F;
    d_start[8] = 0.0F;
    d_start[9] = 0.0F;
    st.site = &emlrtRSI;
    polynomialTrajectorySolver(&st, b_start, c_start, d_start, Mass, Moment,
      MinZForce, MaxForce, *(real32_T (*)[33])&Trajectory->data[0]);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, (real32_T)mid->size[1],
      mxSINGLE_CLASS, (int32_T)(real32_T)mid->size[1], &c_emlrtRTEI, sp);
    z_index = 0;
    while (z_index <= (int32_T)(real32_T)mid->size[1] - 1) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, covrtLogMcdc
                     (&emlrtCoverageInstance, 0U, 0U, 0, !covrtLogCond
                      (&emlrtCoverageInstance, 0U, 0U, 0, 1.0F + (real32_T)
                       z_index == mid->size[1])))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2);
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &n_emlrtBCI, sp);
        }

        b_mid[0] = mid->data[mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &o_emlrtBCI, sp);
        }

        b_mid[1] = mid->data[3 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        b_mid[2] = 0.0F;
        b_mid[3] = 0.0F;
        b_mid[4] = 0.0F;
        i0 = mid->size[1];
        kstr = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &p_emlrtBCI, sp);
        }

        b_mid[5] = mid->data[mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &q_emlrtBCI, sp);
        }

        b_mid[6] = mid->data[3 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        b_mid[7] = 0.0F;
        b_mid[8] = 0.0F;
        b_mid[9] = 0.0F;
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &r_emlrtBCI, sp);
        }

        c_mid[0] = mid->data[1 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &s_emlrtBCI, sp);
        }

        c_mid[1] = mid->data[4 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        c_mid[2] = 0.0F;
        c_mid[3] = 0.0F;
        c_mid[4] = 0.0F;
        i0 = mid->size[1];
        kstr = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &t_emlrtBCI, sp);
        }

        c_mid[5] = mid->data[1 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &u_emlrtBCI, sp);
        }

        c_mid[6] = mid->data[4 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        c_mid[7] = 0.0F;
        c_mid[8] = 0.0F;
        c_mid[9] = 0.0F;
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &v_emlrtBCI, sp);
        }

        d_mid[0] = mid->data[2 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &w_emlrtBCI, sp);
        }

        d_mid[1] = mid->data[5 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        d_mid[2] = 0.0F;
        d_mid[3] = 0.0F;
        d_mid[4] = 0.0F;
        i0 = mid->size[1];
        kstr = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &x_emlrtBCI, sp);
        }

        d_mid[5] = mid->data[2 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &y_emlrtBCI, sp);
        }

        d_mid[6] = mid->data[5 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        d_mid[7] = 0.0F;
        d_mid[8] = 0.0F;
        d_mid[9] = 0.0F;
        kstr = Trajectory->size[2];
        i0 = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((i0 >= 1) && (i0 <= kstr))) {
          emlrtDynamicBoundsCheckR2012b(i0, 1, kstr, &ab_emlrtBCI, sp);
        }

        st.site = &b_emlrtRSI;
        polynomialTrajectorySolver(&st, b_mid, c_mid, d_mid, Mass, Moment,
          MinZForce, MaxForce, *(real32_T (*)[33])&Trajectory->data
          [Trajectory->size[0] * Trajectory->size[1] * ((int32_T)(real32_T)i0 -
          1)]);
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3);
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &g_emlrtBCI, sp);
        }

        b_start[0] = mid->data[mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &h_emlrtBCI, sp);
        }

        b_start[1] = mid->data[3 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        b_start[2] = 0.0F;
        b_start[3] = 0.0F;
        b_start[4] = 0.0F;
        for (i0 = 0; i0 < 5; i0++) {
          b_start[i0 + 5] = final[3 * i0];
        }

        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &i_emlrtBCI, sp);
        }

        c_start[0] = mid->data[1 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &j_emlrtBCI, sp);
        }

        c_start[1] = mid->data[4 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        c_start[2] = 0.0F;
        c_start[3] = 0.0F;
        c_start[4] = 0.0F;
        for (i0 = 0; i0 < 5; i0++) {
          c_start[i0 + 5] = final[1 + 3 * i0];
        }

        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &k_emlrtBCI, sp);
        }

        d_start[0] = mid->data[2 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        i0 = mid->size[1];
        kstr = (int32_T)(1.0F + (real32_T)z_index);
        if (!((kstr >= 1) && (kstr <= i0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, i0, &l_emlrtBCI, sp);
        }

        d_start[1] = mid->data[5 + mid->size[0] * ((int32_T)(real32_T)kstr - 1)];
        d_start[2] = 0.0F;
        d_start[3] = 0.0F;
        d_start[4] = 0.0F;
        for (i0 = 0; i0 < 5; i0++) {
          d_start[i0 + 5] = final[2 + 3 * i0];
        }

        kstr = Trajectory->size[2];
        i0 = (int32_T)((1.0F + (real32_T)z_index) + 1.0F);
        if (!((i0 >= 1) && (i0 <= kstr))) {
          emlrtDynamicBoundsCheckR2012b(i0, 1, kstr, &m_emlrtBCI, sp);
        }

        st.site = &c_emlrtRSI;
        polynomialTrajectorySolver(&st, b_start, c_start, d_start, Mass, Moment,
          MinZForce, MaxForce, *(real32_T (*)[33])&Trajectory->data
          [Trajectory->size[0] * Trajectory->size[1] * ((int32_T)(real32_T)i0 -
          1)]);
      }

      z_index++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  } else {
    overflow = false;
    if (MIDPOINT_MODE_size[1] != 6) {
    } else {
      kstr = 0;
      do {
        exitg4 = 0;
        if (kstr + 1 < 7) {
          if (MIDPOINT_MODE_data[kstr] != cv1[kstr]) {
            exitg4 = 1;
          } else {
            kstr++;
          }
        } else {
          overflow = true;
          exitg4 = 1;
        }
      } while (exitg4 == 0);
    }

    covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 2, overflow);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4);
  st.site = &d_emlrtRSI;
  b_st.site = &id_emlrtRSI;
  i0 = Trajectory->size[2];
  guard1 = false;
  if (i0 == 1) {
    guard1 = true;
  } else {
    i0 = Trajectory->size[2];
    if (i0 != 1) {
      guard1 = true;
    } else {
      overflow = false;
    }
  }

  if (guard1) {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &d_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  k = 3;
  exitg3 = false;
  while ((!exitg3) && (k > 2)) {
    i0 = Trajectory->size[2];
    if (i0 == 1) {
      k = 2;
    } else {
      exitg3 = true;
    }
  }

  if (k != 2) {
  } else {
    k = 3;
    exitg2 = false;
    while ((!exitg2) && (k > 2)) {
      i0 = Trajectory->size[2];
      if (i0 == 1) {
        k = 2;
      } else {
        exitg2 = true;
      }
    }

    b_k = 0;
    emxInit_real32_T(&b_st, &b_Trajectory, 3, &emlrtRTEI, true);
    do {
      exitg1 = 0;
      if (b_k <= k - 1) {
        kstr = Trajectory->size[2];
        i0 = b_Trajectory->size[0] * b_Trajectory->size[1] * b_Trajectory->size
          [2];
        b_Trajectory->size[0] = 1;
        b_Trajectory->size[1] = 1;
        b_Trajectory->size[2] = kstr;
        emxEnsureCapacity(&b_st, (emxArray__common *)b_Trajectory, i0, (int32_T)
                          sizeof(real32_T), &emlrtRTEI);
        for (i0 = 0; i0 < kstr; i0++) {
          b_Trajectory->data[b_Trajectory->size[0] * b_Trajectory->size[1] * i0]
            = Trajectory->data[Trajectory->size[0] * 10 + Trajectory->size[0] *
            Trajectory->size[1] * i0];
        }

        if (b_Trajectory->size[b_k] != !(1 + b_k <= 2)) {
          exitg1 = 1;
        } else {
          b_k++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_real32_T(&b_Trajectory);
  }

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  c_st.site = &jd_emlrtRSI;
  i0 = Trajectory->size[2];
  y = Trajectory->data[Trajectory->size[0] * 10];
  d_st.site = &kd_emlrtRSI;
  kstr = Trajectory->size[2];
  if (2 > kstr) {
    overflow = false;
  } else {
    kstr = Trajectory->size[2];
    overflow = (kstr > 2147483646);
  }

  if (overflow) {
    e_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 2; k <= i0; k++) {
    y += Trajectory->data[Trajectory->size[0] * 10 + Trajectory->size[0] *
      Trajectory->size[1] * (k - 1)];
  }

  *totalFlightTime = y;

  /* plot the trajectory */
  /* [p1, p2] = trajectoryPlotter(Trajectory); */
  /* daspect([5 5 5]) */
  /* axis([-1 11 -1 11 -10 10]) */
  /* hold on */
  /* arrow3(p1, p2, 'b', 0.4) */
  /* hold off */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (minimumTimeTrajectoryGenerator.c) */
