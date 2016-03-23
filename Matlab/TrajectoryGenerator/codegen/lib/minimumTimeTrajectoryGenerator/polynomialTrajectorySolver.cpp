//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polynomialTrajectorySolver.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "polynomialTrajectorySolver.h"
#include "calculateActuatorFeasibility.h"
#include "mldivide.h"
#include "minimumTimeTrajectoryGenerator_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// UNTITLED Summary of this function goes here
//    Detailed explanation goes here
//    This will solve for the coefficients of a constrained 9 order
//    polynomial
//  END_POINT_MODES: 'FULL', 'VEL', 'NOVEL'
//  for vel and no vel use zeros in their place
// the number of iterations
// Arguments    : const float X[10]
//                const float Y[10]
//                const float Z[10]
//                float Mass
//                const float Moment[3]
//                float MinZForce
//                float MaxForce
//                float C[33]
// Return Type  : void
//
void polynomialTrajectorySolver(const float X[10], const float Y[10], const
  float Z[10], float Mass, const float Moment[3], float MinZForce, float
  MaxForce, float C[33])
{
  float t_start;
  float t_end;
  float t_mid;
  float Error;
  int it;
  float tf;
  int i1;
  float A[100];
  static const signed char iv0[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const signed char iv1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 };

  static const signed char iv2[10] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };

  static const signed char iv3[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const signed char iv4[10] = { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 };

  float b_C[30];
  float fv0[10];
  float b_tf[3];

  // declare ti as zero
  // this is a ball park estimate of tf for starting
  // in the future it should take into account the distance
  // create variables for newton's method
  t_start = 0.0F;
  t_end = 20.0F;
  t_mid = 10.0F;
  Error = 0.0F;
  for (it = 0; it < 10; it++) {
    // UNTITLED6 Summary of this function goes here
    //    This simply returns a 9 degree polynomial matrix
    // create the 10 x 10 matrix
    for (i1 = 0; i1 < 10; i1++) {
      A[10 * i1] = iv0[i1];
      A[1 + 10 * i1] = iv1[i1];
      A[2 + 10 * i1] = iv2[i1];
      A[3 + 10 * i1] = iv3[i1];
      A[4 + 10 * i1] = iv4[i1];
    }

    A[5] = rt_powf_snf(t_mid, 9.0F);
    A[15] = rt_powf_snf(t_mid, 8.0F);
    A[25] = rt_powf_snf(t_mid, 7.0F);
    A[35] = rt_powf_snf(t_mid, 6.0F);
    A[45] = rt_powf_snf(t_mid, 5.0F);
    A[55] = rt_powf_snf(t_mid, 4.0F);
    A[65] = rt_powf_snf(t_mid, 3.0F);
    A[75] = t_mid * t_mid;
    A[85] = t_mid;
    A[95] = 1.0F;
    A[6] = 9.0F * rt_powf_snf(t_mid, 8.0F);
    A[16] = 8.0F * rt_powf_snf(t_mid, 7.0F);
    A[26] = 7.0F * rt_powf_snf(t_mid, 6.0F);
    A[36] = 6.0F * rt_powf_snf(t_mid, 5.0F);
    A[46] = 5.0F * rt_powf_snf(t_mid, 4.0F);
    A[56] = 4.0F * rt_powf_snf(t_mid, 3.0F);
    A[66] = 3.0F * (t_mid * t_mid);
    A[76] = 2.0F * t_mid;
    A[86] = 1.0F;
    A[96] = 0.0F;
    A[7] = 72.0F * rt_powf_snf(t_mid, 7.0F);
    A[17] = 56.0F * rt_powf_snf(t_mid, 6.0F);
    A[27] = 42.0F * rt_powf_snf(t_mid, 5.0F);
    A[37] = 30.0F * rt_powf_snf(t_mid, 4.0F);
    A[47] = 20.0F * rt_powf_snf(t_mid, 3.0F);
    A[57] = 12.0F * (t_mid * t_mid);
    A[67] = 6.0F * t_mid;
    A[77] = 1.0F;
    A[87] = 0.0F;
    A[97] = 0.0F;
    A[8] = 504.0F * rt_powf_snf(t_mid, 6.0F);
    A[18] = 336.0F * rt_powf_snf(t_mid, 5.0F);
    A[28] = 210.0F * rt_powf_snf(t_mid, 4.0F);
    A[38] = 120.0F * rt_powf_snf(t_mid, 3.0F);
    A[48] = 60.0F * (t_mid * t_mid);
    A[58] = 24.0F * t_mid;
    A[68] = 1.0F;
    A[78] = 0.0F;
    A[88] = 0.0F;
    A[98] = 0.0F;
    A[9] = 3024.0F * rt_powf_snf(t_mid, 5.0F);
    A[19] = 1680.0F * rt_powf_snf(t_mid, 4.0F);
    A[29] = 840.0F * rt_powf_snf(t_mid, 3.0F);
    A[39] = 360.0F * (t_mid * t_mid);
    A[49] = 120.0F * t_mid;
    A[59] = 1.0F;
    A[69] = 0.0F;
    A[79] = 0.0F;
    A[89] = 0.0F;
    A[99] = 0.0F;

    // solve for the coefficient matrix
    memset(&b_C[0], 0, 30U * sizeof(float));
    for (i1 = 0; i1 < 10; i1++) {
      fv0[i1] = X[i1];
    }

    mldivide(A, fv0);
    for (i1 = 0; i1 < 10; i1++) {
      b_C[3 * i1] = fv0[i1];
      fv0[i1] = Y[i1];
    }

    mldivide(A, fv0);
    for (i1 = 0; i1 < 10; i1++) {
      b_C[1 + 3 * i1] = fv0[i1];
      fv0[i1] = Z[i1];
    }

    mldivide(A, fv0);
    for (i1 = 0; i1 < 10; i1++) {
      b_C[2 + 3 * i1] = fv0[i1];
    }

    // now that we have the Coefficient matrix run the calculate Actuator
    // feasibility function
    Error = calculateActuatorFeasibility(b_C, Mass, Moment, MinZForce, MaxForce,
      t_mid);

    //  reasses the bounding points of the newton's method variables
    if (Error == 1.0F) {
      t_start = t_mid;
      t_mid = (t_mid + t_end) / 2.0F;
    } else {
      t_end = t_mid;
      t_mid = (t_mid + t_start) / 2.0F;
    }
  }

  // set the tf to the answer
  if (Error == 1.0F) {
    tf = t_end;
  } else {
    tf = t_mid;
  }

  // recalculate the Coefficient matrix one last time
  // UNTITLED6 Summary of this function goes here
  //    This simply returns a 9 degree polynomial matrix
  // create the 10 x 10 matrix
  for (i1 = 0; i1 < 10; i1++) {
    A[10 * i1] = iv0[i1];
    A[1 + 10 * i1] = iv1[i1];
    A[2 + 10 * i1] = iv2[i1];
    A[3 + 10 * i1] = iv3[i1];
    A[4 + 10 * i1] = iv4[i1];
  }

  A[5] = rt_powf_snf(tf, 9.0F);
  A[15] = rt_powf_snf(tf, 8.0F);
  A[25] = rt_powf_snf(tf, 7.0F);
  A[35] = rt_powf_snf(tf, 6.0F);
  A[45] = rt_powf_snf(tf, 5.0F);
  A[55] = rt_powf_snf(tf, 4.0F);
  A[65] = rt_powf_snf(tf, 3.0F);
  A[75] = tf * tf;
  A[85] = tf;
  A[95] = 1.0F;
  A[6] = 9.0F * rt_powf_snf(tf, 8.0F);
  A[16] = 8.0F * rt_powf_snf(tf, 7.0F);
  A[26] = 7.0F * rt_powf_snf(tf, 6.0F);
  A[36] = 6.0F * rt_powf_snf(tf, 5.0F);
  A[46] = 5.0F * rt_powf_snf(tf, 4.0F);
  A[56] = 4.0F * rt_powf_snf(tf, 3.0F);
  A[66] = 3.0F * (tf * tf);
  A[76] = 2.0F * tf;
  A[86] = 1.0F;
  A[96] = 0.0F;
  A[7] = 72.0F * rt_powf_snf(tf, 7.0F);
  A[17] = 56.0F * rt_powf_snf(tf, 6.0F);
  A[27] = 42.0F * rt_powf_snf(tf, 5.0F);
  A[37] = 30.0F * rt_powf_snf(tf, 4.0F);
  A[47] = 20.0F * rt_powf_snf(tf, 3.0F);
  A[57] = 12.0F * (tf * tf);
  A[67] = 6.0F * tf;
  A[77] = 1.0F;
  A[87] = 0.0F;
  A[97] = 0.0F;
  A[8] = 504.0F * rt_powf_snf(tf, 6.0F);
  A[18] = 336.0F * rt_powf_snf(tf, 5.0F);
  A[28] = 210.0F * rt_powf_snf(tf, 4.0F);
  A[38] = 120.0F * rt_powf_snf(tf, 3.0F);
  A[48] = 60.0F * (tf * tf);
  A[58] = 24.0F * tf;
  A[68] = 1.0F;
  A[78] = 0.0F;
  A[88] = 0.0F;
  A[98] = 0.0F;
  A[9] = 3024.0F * rt_powf_snf(tf, 5.0F);
  A[19] = 1680.0F * rt_powf_snf(tf, 4.0F);
  A[29] = 840.0F * rt_powf_snf(tf, 3.0F);
  A[39] = 360.0F * (tf * tf);
  A[49] = 120.0F * tf;
  A[59] = 1.0F;
  A[69] = 0.0F;
  A[79] = 0.0F;
  A[89] = 0.0F;
  A[99] = 0.0F;

  // solve for the coefficient matrix
  memset(&C[0], 0, 33U * sizeof(float));
  for (i1 = 0; i1 < 10; i1++) {
    fv0[i1] = X[i1];
  }

  mldivide(A, fv0);
  for (i1 = 0; i1 < 10; i1++) {
    C[3 * i1] = fv0[i1];
    fv0[i1] = Y[i1];
  }

  mldivide(A, fv0);
  for (i1 = 0; i1 < 10; i1++) {
    C[1 + 3 * i1] = fv0[i1];
    fv0[i1] = Z[i1];
  }

  mldivide(A, fv0);
  for (i1 = 0; i1 < 10; i1++) {
    C[2 + 3 * i1] = fv0[i1];
  }

  b_tf[0] = tf;
  b_tf[1] = tf;
  b_tf[2] = tf;
  for (i1 = 0; i1 < 3; i1++) {
    C[30 + i1] = b_tf[i1];
  }
}

//
// File trailer for polynomialTrajectorySolver.cpp
//
// [EOF]
//
