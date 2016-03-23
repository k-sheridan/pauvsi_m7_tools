//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calculateActuatorFeasibility.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "calculateActuatorFeasibility.h"
#include "polyder.h"
#include "fprintf.h"
#include "norm.h"
#include "polyval.h"
#include "roots.h"
#include "minimumTimeTrajectoryGenerator_rtwutil.h"
#include <stdio.h>

// Type Definitions
#ifndef struct_emxArray_creal32_T_8
#define struct_emxArray_creal32_T_8

struct emxArray_creal32_T_8
{
  creal32_T data[8];
  int size[1];
};

#endif                                 //struct_emxArray_creal32_T_8

// Function Definitions

//
// UNTITLED4 Summary of this function goes here
//    This function will test a given set of polynomials to see if they fit
//    within the actuator constraints specified
//    ESSENTIALLY
//    Coefficients: a 3X10 Matrix of coefficients
//    Mass
//    Moment - moment vector
//    tf: the final time
// MinZForce = the minumum force in the z direction typlically gravity (-45)
// Arguments    : const float Coefficients[30]
//                float Mass
//                const float Moment[3]
//                float MinZForce
//                float MaxForce
//                float tf
// Return Type  : float
//
float calculateActuatorFeasibility(const float Coefficients[30], float Mass,
  const float Moment[3], float MinZForce, float MaxForce, float tf)
{
  float Error;
  float J[9];
  float startCoefficients[30];
  int it;
  float b_Coefficients[10];
  int kAcol;
  float b_startCoefficients[8];
  int tmp_size[2];
  int i2;
  float tmp_data[7];
  int fcnOutput_size[2];
  float fcnOutput_data[9];
  emxArray_creal32_T_8 b_fcnOutput_data;
  int startCoefficients_size[2];
  emxArray_creal32_T_8 c_fcnOutput_data;
  int b_startCoefficients_size[2];
  emxArray_creal32_T_8 d_fcnOutput_data;
  float maxima[9];
  float temp;
  float s;
  float y;
  int k;
  float f_total[6];
  boolean_T guard1 = false;
  int exitg2;
  float Fi[6];
  static const float fv1[3] = { 0.0F, 0.0F, 9.81F };

  float value_data[9];
  float fv2[2];
  int exitg1;
  float value[2];
  float A[16];
  static const float b_A[16] = { 1.0F, 0.4F, 0.0F, -2.0F, 1.0F, 0.0F, 0.4F, 2.0F,
    1.0F, -0.4F, 0.0F, -2.0F, 1.0F, 0.0F, -0.4F, 2.0F };

  signed char ipiv[4];
  int j;
  int c;
  float Y[4];
  float Mb[6];
  int ix;
  int jy;
  float motorForces[12];
  boolean_T x[4];
  boolean_T b_y;
  int ijA;
  float Fi_prime[6];
  boolean_T exitg4;
  float b_c;
  boolean_T exitg3;
  float Fi_prime_prime[6];
  float Fi_bar[6];
  float Fi_bar_prime[6];
  float Fi_bar_prime_prime[6];
  float Omega_desired[6];
  float Alpha_desired[6];
  float b_value;
  float b;
  float c_c;
  float d_c[3];
  float b_Omega_desired[3];
  float e_c[3];
  float c_Omega_desired[3];

  // the distance of each motor from the center of mass
  // coefficient of drag related to yaw drag
  // gravity
  // create the moment matrix
  J[0] = Moment[0];
  J[3] = 0.0F;
  J[6] = 0.0F;
  J[1] = 0.0F;
  J[4] = Moment[1];
  J[7] = 0.0F;
  J[2] = 0.0F;
  J[5] = 0.0F;
  J[8] = Moment[2];

  //  Find the maximum accelerations
  memcpy(&startCoefficients[0], &Coefficients[0], 30U * sizeof(float));

  // UNTITLED5 Summary of this function goes here
  //    this function uses a 3X10 coefficient matrix and a derivative count to
  //    calculate the maximums of a given set of functions at a given
  //    derivative
  // calculate the Coefficient matrix for the given derivative
  for (it = 0; it < 2; it++) {
    kAcol = 9 - it;
    tmp_size[0] = 1;
    tmp_size[1] = kAcol + 1;
    for (i2 = 0; i2 <= kAcol; i2++) {
      b_Coefficients[i2] = startCoefficients[3 * i2];
    }

    polyder(b_Coefficients, tmp_size, fcnOutput_data, fcnOutput_size);
    kAcol = fcnOutput_size[1];
    for (i2 = 0; i2 < kAcol; i2++) {
      startCoefficients[3 * i2] = fcnOutput_data[fcnOutput_size[0] * i2];
    }

    kAcol = 9 - it;
    startCoefficients_size[0] = 1;
    startCoefficients_size[1] = kAcol + 1;
    for (i2 = 0; i2 <= kAcol; i2++) {
      b_Coefficients[i2] = startCoefficients[1 + 3 * i2];
    }

    polyder(b_Coefficients, startCoefficients_size, fcnOutput_data,
            fcnOutput_size);
    kAcol = fcnOutput_size[1];
    for (i2 = 0; i2 < kAcol; i2++) {
      startCoefficients[1 + 3 * i2] = fcnOutput_data[fcnOutput_size[0] * i2];
    }

    kAcol = 9 - it;
    b_startCoefficients_size[0] = 1;
    b_startCoefficients_size[1] = kAcol + 1;
    for (i2 = 0; i2 <= kAcol; i2++) {
      b_Coefficients[i2] = startCoefficients[2 + 3 * i2];
    }

    polyder(b_Coefficients, b_startCoefficients_size, fcnOutput_data,
            fcnOutput_size);
    kAcol = fcnOutput_size[1];
    for (i2 = 0; i2 < kAcol; i2++) {
      startCoefficients[2 + 3 * i2] = fcnOutput_data[fcnOutput_size[0] * i2];
    }
  }

  // reset the size of coeffs
  // find the roots of the next derivative and combine them into a roots vector
  for (i2 = 0; i2 < 8; i2++) {
    b_startCoefficients[i2] = startCoefficients[3 * i2];
  }

  b_polyder(b_startCoefficients, tmp_data, tmp_size);
  fcnOutput_size[0] = 1;
  fcnOutput_size[1] = tmp_size[1];
  kAcol = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < kAcol; i2++) {
    fcnOutput_data[i2] = tmp_data[i2];
  }

  roots(fcnOutput_data, fcnOutput_size, b_fcnOutput_data.data,
        b_fcnOutput_data.size);
  for (i2 = 0; i2 < 8; i2++) {
    b_startCoefficients[i2] = startCoefficients[1 + 3 * i2];
  }

  b_polyder(b_startCoefficients, tmp_data, tmp_size);
  fcnOutput_size[0] = 1;
  fcnOutput_size[1] = tmp_size[1];
  kAcol = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < kAcol; i2++) {
    fcnOutput_data[i2] = tmp_data[i2];
  }

  roots(fcnOutput_data, fcnOutput_size, c_fcnOutput_data.data,
        c_fcnOutput_data.size);
  for (i2 = 0; i2 < 8; i2++) {
    b_startCoefficients[i2] = startCoefficients[2 + 3 * i2];
  }

  b_polyder(b_startCoefficients, tmp_data, tmp_size);
  fcnOutput_size[0] = 1;
  fcnOutput_size[1] = tmp_size[1];
  kAcol = tmp_size[0] * tmp_size[1];
  for (i2 = 0; i2 < kAcol; i2++) {
    fcnOutput_data[i2] = tmp_data[i2];
  }

  roots(fcnOutput_data, fcnOutput_size, d_fcnOutput_data.data,
        d_fcnOutput_data.size);

  // combine the roots together without repeating for optimization
  for (i2 = 0; i2 < 9; i2++) {
    maxima[i2] = 0.0F;
  }

  for (it = 0; it < 2; it++) {
    temp = startCoefficients[0];
    s = startCoefficients[1];
    y = startCoefficients[2];
    for (k = 0; k < 7; k++) {
      temp = 0.0F * temp + startCoefficients[3 * (k + 1)];
      s = 0.0F * s + startCoefficients[1 + 3 * (k + 1)];
      y = 0.0F * y + startCoefficients[2 + 3 * (k + 1)];
    }

    maxima[3 * it] = temp;
    maxima[1 + 3 * it] = s;
    maxima[2 + 3 * it] = y;
  }

  temp = startCoefficients[0];
  s = startCoefficients[1];
  y = startCoefficients[2];
  for (k = 0; k < 7; k++) {
    temp = tf * temp + startCoefficients[3 * (k + 1)];
    s = tf * s + startCoefficients[1 + 3 * (k + 1)];
    y = tf * y + startCoefficients[2 + 3 * (k + 1)];
  }

  maxima[6] = temp;
  maxima[7] = s;
  maxima[8] = y;

  // create the fTot
  for (i2 = 0; i2 < 6; i2++) {
    f_total[i2] = 0.0F;
  }

  // now test whether these maximums are within feasible limits
  it = 0;
  guard1 = false;
  do {
    exitg2 = 0;
    if (it < 2) {
      // calculate the magnitude of the acceleration gravity while taking into
      // account mass and gravity
      // mag is the [0, 0, 0, F_Total]' vector of the quadrotor. It must not
      // exceed the maximum possible acceleration
      for (i2 = 0; i2 < 3; i2++) {
        f_total[i2 + 3 * it] = Mass * (maxima[i2 + 3 * it] + fv1[i2]);
      }

      if ((norm(*(float (*)[3])&f_total[3 * it]) > MaxForce) || (f_total[2 + 3 *
           it] <= MinZForce)) {
        cfprintf();
        Error = 1.0F;
        exitg2 = 1;
      } else {
        it++;
        guard1 = false;
      }
    } else {
      // now use a lot of physics and math to calculate the force each motor must 
      // be exerting at each point
      // start by declaring the variables
      // inertial frame force vector
      for (i2 = 0; i2 < 6; i2++) {
        Fi[i2] = 0.0F;
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(value_data, tmp_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi[3 * i2] = Mass * value[i2];
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[1 + 3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(value_data, tmp_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi[1 + 3 * i2] = Mass * value[i2];
      }

      //  add g to the
      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[2 + 3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(value_data, tmp_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi[2 + 3 * i2] = Mass * (value[i2] + 9.81F);
      }

      //  create the first derivative of force vector
      for (i2 = 0; i2 < 6; i2++) {
        Fi_prime[i2] = 0.0F;
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      polyder(value_data, tmp_size, fcnOutput_data, fcnOutput_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(fcnOutput_data, fcnOutput_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi_prime[3 * i2] = Mass * value[i2];
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[1 + 3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      polyder(value_data, tmp_size, fcnOutput_data, fcnOutput_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(fcnOutput_data, fcnOutput_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi_prime[1 + 3 * i2] = Mass * value[i2];
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[2 + 3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      polyder(value_data, tmp_size, fcnOutput_data, fcnOutput_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(fcnOutput_data, fcnOutput_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi_prime[2 + 3 * i2] = Mass * value[i2];
      }

      //  create the first derivative of force vector
      for (i2 = 0; i2 < 6; i2++) {
        Fi_prime_prime[i2] = 0.0F;
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      polyder(value_data, tmp_size, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(value_data, tmp_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi_prime_prime[3 * i2] = Mass * value[i2];
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[1 + 3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      polyder(value_data, tmp_size, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(value_data, tmp_size, fv2, value);
      for (i2 = 0; i2 < 2; i2++) {
        Fi_prime_prime[1 + 3 * i2] = Mass * value[i2];
      }

      for (i2 = 0; i2 < 10; i2++) {
        b_Coefficients[i2] = Coefficients[2 + 3 * i2];
      }

      c_polyder(b_Coefficients, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      polyder(value_data, tmp_size, fcnOutput_data, fcnOutput_size);
      polyder(fcnOutput_data, fcnOutput_size, value_data, tmp_size);
      for (i2 = 0; i2 < 2; i2++) {
        fv2[i2] = 0.0F;
      }

      polyval(value_data, tmp_size, fv2, value);

      // calculate the desired omega vector
      // Aplha desired calculation
      // Fi_bar_prime calc
      // Fi_bar_prime_prime calc
      // create the bar vector of Fi
      // moments
      // caclculate the bar and prime and alpha
      for (it = 0; it < 2; it++) {
        Fi_prime_prime[2 + 3 * it] = Mass * value[it];
        b_value = norm(*(float (*)[3])&Fi[3 * it]);

        // Calculation of fi_bar_prime
        temp = norm(*(float (*)[3])&Fi[3 * it]);
        b_c = 0.0F;
        for (i2 = 0; i2 < 3; i2++) {
          Fi_bar[i2 + 3 * it] = Fi[i2 + 3 * it] / b_value;
          b_c += Fi[i2 + 3 * it] * Fi_prime[i2 + 3 * it];
        }

        b = rt_powf_snf(norm(*(float (*)[3])&Fi[3 * it]), 3.0F);

        //  calcing fi_bar_prime_prime
        b_value = norm(*(float (*)[3])&Fi[3 * it]);
        c_c = 0.0F;
        for (i2 = 0; i2 < 3; i2++) {
          Fi_bar_prime[i2 + 3 * it] = Fi_prime[i2 + 3 * it] / temp - Fi[i2 + 3 *
            it] * b_c / b;
          c_c += Fi[i2 + 3 * it] * Fi_prime[i2 + 3 * it];
        }

        b_c = 0.0F;
        for (i2 = 0; i2 < 3; i2++) {
          b_c += Fi_prime[i2 + 3 * it] * Fi_prime[i2 + 3 * it];
        }

        temp = 0.0F;
        for (i2 = 0; i2 < 3; i2++) {
          temp += Fi[i2 + 3 * it] * Fi_prime_prime[i2 + 3 * it];
        }

        b = rt_powf_snf(norm(*(float (*)[3])&Fi[3 * it]), 3.0F);
        s = 0.0F;
        for (i2 = 0; i2 < 3; i2++) {
          s += Fi[i2 + 3 * it] * Fi_prime[i2 + 3 * it];
        }

        y = rt_powf_snf(norm(*(float (*)[3])&Fi[3 * it]), 5.0F);

        // the omega desired calc
        Omega_desired[3 * it] = Fi_bar[1 + 3 * it] * Fi_bar_prime[2 + 3 * it] -
          Fi_bar[2 + 3 * it] * Fi_bar_prime[1 + 3 * it];
        Omega_desired[1 + 3 * it] = Fi_bar[2 + 3 * it] * Fi_bar_prime[3 * it] -
          Fi_bar[3 * it] * Fi_bar_prime[2 + 3 * it];
        Omega_desired[2 + 3 * it] = Fi_bar[3 * it] * Fi_bar_prime[1 + 3 * it] -
          Fi_bar[1 + 3 * it] * Fi_bar_prime[3 * it];

        // set the z moment to zero
        Omega_desired[2 + 3 * it] = 0.0F;

        // the alpha vector
        d_c[0] = Omega_desired[1 + 3 * it] * Fi_bar_prime[2 + 3 * it] -
          Omega_desired[2 + 3 * it] * Fi_bar_prime[1 + 3 * it];
        d_c[1] = Omega_desired[2 + 3 * it] * Fi_bar_prime[3 * it] -
          Omega_desired[3 * it] * Fi_bar_prime[2 + 3 * it];
        d_c[2] = Omega_desired[3 * it] * Fi_bar_prime[1 + 3 * it] -
          Omega_desired[1 + 3 * it] * Fi_bar_prime[3 * it];
        b_Omega_desired[0] = Omega_desired[1 + 3 * it] * d_c[2] - Omega_desired
          [2 + 3 * it] * d_c[1];
        b_Omega_desired[1] = Omega_desired[2 + 3 * it] * d_c[0] - Omega_desired
          [3 * it] * d_c[2];
        b_Omega_desired[2] = Omega_desired[3 * it] * d_c[1] - Omega_desired[1 +
          3 * it] * d_c[0];
        for (i2 = 0; i2 < 3; i2++) {
          Fi_bar_prime_prime[i2 + 3 * it] = (Fi_prime_prime[i2 + 3 * it] /
            b_value - ((2.0F * Fi_prime[i2 + 3 * it] * c_c + Fi[i2 + 3 * it] *
                        b_c) + Fi[i2 + 3 * it] * temp) / b) + 3.0F * Fi[i2 + 3 *
            it] * s / y;
          e_c[i2] = Fi_bar_prime_prime[i2 + 3 * it] - b_Omega_desired[i2];
          d_c[i2] = 0.0F;
          for (kAcol = 0; kAcol < 3; kAcol++) {
            d_c[i2] += J[i2 + 3 * kAcol] * Omega_desired[kAcol + 3 * it];
          }
        }

        Alpha_desired[3 * it] = Fi_bar[1 + 3 * it] * e_c[2] - Fi_bar[2 + 3 * it]
          * e_c[1];
        Alpha_desired[1 + 3 * it] = Fi_bar[2 + 3 * it] * e_c[0] - Fi_bar[3 * it]
          * e_c[2];
        Alpha_desired[2 + 3 * it] = Fi_bar[3 * it] * e_c[1] - Fi_bar[1 + 3 * it]
          * e_c[0];

        // set the z to zero
        Alpha_desired[2 + 3 * it] = 0.0F;

        // FINALLY! now that we have the desired omega and the simulated current 
        // omega, we can calcuate the exact forces that each motor must produce at a 
        // given time(the maximum accelerations along a polynomial)
        c_Omega_desired[0] = Omega_desired[1 + 3 * it] * d_c[2] - Omega_desired
          [2 + 3 * it] * d_c[1];
        c_Omega_desired[1] = Omega_desired[2 + 3 * it] * d_c[0] - Omega_desired
          [3 * it] * d_c[2];
        c_Omega_desired[2] = Omega_desired[3 * it] * d_c[1] - Omega_desired[1 +
          3 * it] * d_c[0];
        for (i2 = 0; i2 < 3; i2++) {
          e_c[i2] = 0.0F;
          for (kAcol = 0; kAcol < 3; kAcol++) {
            e_c[i2] += J[i2 + 3 * kAcol] * Alpha_desired[kAcol + 3 * it];
          }

          Mb[i2 + 3 * it] = e_c[i2] + c_Omega_desired[i2];
        }
      }

      for (i2 = 0; i2 < 12; i2++) {
        motorForces[i2] = 0.0F;
      }

      it = 0;
      exitg2 = 2;
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      if (it < 2) {
        memcpy(&A[0], &b_A[0], sizeof(float) << 4);
        for (i2 = 0; i2 < 4; i2++) {
          ipiv[i2] = (signed char)(1 + i2);
        }

        for (j = 0; j < 3; j++) {
          c = j * 5;
          kAcol = 0;
          ix = c;
          temp = (float)fabs((double)A[c]);
          for (k = 2; k <= 4 - j; k++) {
            ix++;
            s = (float)fabs((double)A[ix]);
            if (s > temp) {
              kAcol = k - 1;
              temp = s;
            }
          }

          if (A[c + kAcol] != 0.0F) {
            if (kAcol != 0) {
              ipiv[j] = (signed char)((j + kAcol) + 1);
              ix = j;
              kAcol += j;
              for (k = 0; k < 4; k++) {
                temp = A[ix];
                A[ix] = A[kAcol];
                A[kAcol] = temp;
                ix += 4;
                kAcol += 4;
              }
            }

            i2 = (c - j) + 4;
            for (jy = c + 1; jy + 1 <= i2; jy++) {
              A[jy] /= A[c];
            }
          }

          kAcol = c;
          jy = c + 4;
          for (k = 1; k <= 3 - j; k++) {
            temp = A[jy];
            if (A[jy] != 0.0F) {
              ix = c + 1;
              i2 = (kAcol - j) + 8;
              for (ijA = 5 + kAcol; ijA + 1 <= i2; ijA++) {
                A[ijA] += A[ix] * -temp;
                ix++;
              }
            }

            jy += 4;
            kAcol += 4;
          }
        }

        temp = norm(*(float (*)[3])&f_total[3 * it]);
        Y[0] = temp;
        Y[1] = Mb[3 * it];
        Y[2] = Mb[1 + 3 * it];
        Y[3] = Mb[2 + 3 * it];
        for (kAcol = 0; kAcol < 3; kAcol++) {
          if (ipiv[kAcol] != kAcol + 1) {
            temp = Y[kAcol];
            Y[kAcol] = Y[ipiv[kAcol] - 1];
            Y[ipiv[kAcol] - 1] = temp;
          }
        }

        for (k = 0; k < 4; k++) {
          kAcol = k << 2;
          if (Y[k] != 0.0F) {
            for (jy = k + 1; jy + 1 < 5; jy++) {
              Y[jy] -= Y[k] * A[jy + kAcol];
            }
          }
        }

        for (k = 3; k >= 0; k += -1) {
          kAcol = k << 2;
          if (Y[k] != 0.0F) {
            Y[k] /= A[k + kAcol];
            for (jy = 0; jy + 1 <= k; jy++) {
              Y[jy] -= Y[k] * A[jy + kAcol];
            }
          }
        }

        for (i2 = 0; i2 < 4; i2++) {
          motorForces[i2 + (it << 2)] = Y[i2];
        }

        //  while in the for loop check to see if the forces are within the
        //  bounds
        for (i2 = 0; i2 < 4; i2++) {
          x[i2] = (motorForces[i2 + (it << 2)] <= 1.0F);
        }

        b_y = false;
        k = 0;
        exitg4 = false;
        while ((!exitg4) && (k < 4)) {
          if (!!x[k]) {
            b_y = true;
            exitg4 = true;
          } else {
            k++;
          }
        }

        if (b_y) {
          guard1 = true;
          exitg1 = 1;
        } else {
          b_c = MaxForce / 4.0F;
          for (i2 = 0; i2 < 4; i2++) {
            x[i2] = (motorForces[i2 + (it << 2)] >= b_c);
          }

          b_y = false;
          k = 0;
          exitg3 = false;
          while ((!exitg3) && (k < 4)) {
            if (!!x[k]) {
              b_y = true;
              exitg3 = true;
            } else {
              k++;
            }
          }

          if (b_y) {
            guard1 = true;
            exitg1 = 1;
          } else {
            it++;
          }
        }
      } else {
        // IF YOU HAVE NOT RETURNED BY THIS POINT THE TRAJECTORY IS WITHIN FEASIBLE 
        // LIMITS
        Error = -1.0F;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (guard1) {
    b_cfprintf();
    Error = 1.0F;
  }

  return Error;
}

//
// File trailer for calculateActuatorFeasibility.cpp
//
// [EOF]
//
