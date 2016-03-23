//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minimumTimeTrajectoryGenerator.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "polynomialTrajectorySolver.h"
#include "minimumTimeTrajectoryGenerator_emxutil.h"
#include <stdio.h>

// Function Definitions

//
// UNTITLED7 Summary of this function goes here
//    This will generate a trajectory that is flable by a quadrotor it may
//    take a second.
//    The format for start and end is [x_0, x_1, x_2, x_3, x_4]
//                                    [y_0, y_1, y_2, y_3, y_4]
//                                    [z_0, z_1, z_2, z_3, z_4]
//
//    the format for mid is [x_0, x2_0, ...]    [x_0, x2_0]
//                          [y_0, y2_0, ...]    [y_0, y2_0]
//                          [z_0, z2_0, ...]    [z_0, z2_0]
//                          [x_1, x2_1, ...]
//                          [y_1, y2_1, ...]
//                          [z_1, z2_1, ...]
//                     MODE:     'VEL'            'NO_VEL'    'NONE'
// Arguments    : const float start[15]
//                const emxArray_real32_T *mid
//                const float final[15]
//                const char MIDPOINT_MODE_data[]
//                const int MIDPOINT_MODE_size[2]
//                float Mass
//                const float Moment[3]
//                float MaxVel
//                float MinZForce
//                float MaxForce
//                float MaxAngle
//                emxArray_real32_T *Trajectory
//                float *totalFlightTime
// Return Type  : void
//
void minimumTimeTrajectoryGenerator(const float start[15], const
  emxArray_real32_T *mid, const float final[15], const char MIDPOINT_MODE_data[],
  const int MIDPOINT_MODE_size[2], float Mass, const float Moment[3], float,
  float MinZForce, float MaxForce, float, emxArray_real32_T *Trajectory, float
  *totalFlightTime)
{
  int i0;
  int kstr;
  boolean_T b_bool;
  int exitg2;
  float b_start[10];
  float y;
  static const char cv0[3] = { 'V', 'E', 'L' };

  int exitg1;
  float c_start[10];
  float d_start[10];
  int z_index;
  float b_mid[10];
  float c_mid[10];
  float d_mid[10];

  // define Trajectory
  i0 = Trajectory->size[0] * Trajectory->size[1] * Trajectory->size[2];
  Trajectory->size[0] = 3;
  Trajectory->size[1] = 11;
  Trajectory->size[2] = (int)((float)mid->size[1] + 1.0F);
  emxEnsureCapacity((emxArray__common *)Trajectory, i0, (int)sizeof(float));
  kstr = 33 * (int)((float)mid->size[1] + 1.0F);
  for (i0 = 0; i0 < kstr; i0++) {
    Trajectory->data[i0] = 0.0F;
  }

  // if this is in velocity mode
  b_bool = false;
  if (MIDPOINT_MODE_size[1] != 3) {
  } else {
    kstr = 0;
    do {
      exitg2 = 0;
      if (kstr + 1 < 4) {
        if (MIDPOINT_MODE_data[kstr] != cv0[kstr]) {
          exitg2 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  if (b_bool) {
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
    polynomialTrajectorySolver(b_start, c_start, d_start, Mass, Moment,
      MinZForce, MaxForce, *(float (*)[33])&Trajectory->data[0]);
    for (z_index = 0; z_index < (int)(float)mid->size[1]; z_index++) {
      if (!(1.0F + (float)z_index == mid->size[1])) {
        b_mid[0] = mid->data[mid->size[0] * ((int)(1.0F + (float)z_index) - 1)];
        b_mid[1] = mid->data[3 + mid->size[0] * ((int)(1.0F + (float)z_index) -
          1)];
        b_mid[2] = 0.0F;
        b_mid[3] = 0.0F;
        b_mid[4] = 0.0F;
        b_mid[5] = mid->data[mid->size[0] * ((int)((1.0F + (float)z_index) +
          1.0F) - 1)];
        b_mid[6] = mid->data[3 + mid->size[0] * ((int)((1.0F + (float)z_index) +
          1.0F) - 1)];
        b_mid[7] = 0.0F;
        b_mid[8] = 0.0F;
        b_mid[9] = 0.0F;
        c_mid[0] = mid->data[1 + mid->size[0] * ((int)(1.0F + (float)z_index) -
          1)];
        c_mid[1] = mid->data[4 + mid->size[0] * ((int)(1.0F + (float)z_index) -
          1)];
        c_mid[2] = 0.0F;
        c_mid[3] = 0.0F;
        c_mid[4] = 0.0F;
        c_mid[5] = mid->data[1 + mid->size[0] * ((int)((1.0F + (float)z_index) +
          1.0F) - 1)];
        c_mid[6] = mid->data[4 + mid->size[0] * ((int)((1.0F + (float)z_index) +
          1.0F) - 1)];
        c_mid[7] = 0.0F;
        c_mid[8] = 0.0F;
        c_mid[9] = 0.0F;
        d_mid[0] = mid->data[2 + mid->size[0] * ((int)(1.0F + (float)z_index) -
          1)];
        d_mid[1] = mid->data[5 + mid->size[0] * ((int)(1.0F + (float)z_index) -
          1)];
        d_mid[2] = 0.0F;
        d_mid[3] = 0.0F;
        d_mid[4] = 0.0F;
        d_mid[5] = mid->data[2 + mid->size[0] * ((int)((1.0F + (float)z_index) +
          1.0F) - 1)];
        d_mid[6] = mid->data[5 + mid->size[0] * ((int)((1.0F + (float)z_index) +
          1.0F) - 1)];
        d_mid[7] = 0.0F;
        d_mid[8] = 0.0F;
        d_mid[9] = 0.0F;
        polynomialTrajectorySolver(b_mid, c_mid, d_mid, Mass, Moment, MinZForce,
          MaxForce, *(float (*)[33])&Trajectory->data[Trajectory->size[0] *
          Trajectory->size[1] * ((int)((1.0F + (float)z_index) + 1.0F) - 1)]);
      } else {
        b_start[0] = mid->data[mid->size[0] * ((int)(1.0F + (float)z_index) - 1)];
        b_start[1] = mid->data[3 + mid->size[0] * ((int)(1.0F + (float)z_index)
          - 1)];
        b_start[2] = 0.0F;
        b_start[3] = 0.0F;
        b_start[4] = 0.0F;
        for (i0 = 0; i0 < 5; i0++) {
          b_start[i0 + 5] = final[3 * i0];
        }

        c_start[0] = mid->data[1 + mid->size[0] * ((int)(1.0F + (float)z_index)
          - 1)];
        c_start[1] = mid->data[4 + mid->size[0] * ((int)(1.0F + (float)z_index)
          - 1)];
        c_start[2] = 0.0F;
        c_start[3] = 0.0F;
        c_start[4] = 0.0F;
        for (i0 = 0; i0 < 5; i0++) {
          c_start[i0 + 5] = final[1 + 3 * i0];
        }

        d_start[0] = mid->data[2 + mid->size[0] * ((int)(1.0F + (float)z_index)
          - 1)];
        d_start[1] = mid->data[5 + mid->size[0] * ((int)(1.0F + (float)z_index)
          - 1)];
        d_start[2] = 0.0F;
        d_start[3] = 0.0F;
        d_start[4] = 0.0F;
        for (i0 = 0; i0 < 5; i0++) {
          d_start[i0 + 5] = final[2 + 3 * i0];
        }

        polynomialTrajectorySolver(b_start, c_start, d_start, Mass, Moment,
          MinZForce, MaxForce, *(float (*)[33])&Trajectory->data
          [Trajectory->size[0] * Trajectory->size[1] * ((int)((1.0F + (float)
          z_index) + 1.0F) - 1)]);
      }
    }
  }

  y = Trajectory->data[Trajectory->size[0] * 10];
  kstr = 2;
  do {
    exitg1 = 0;
    i0 = Trajectory->size[2];
    if (kstr <= i0) {
      y += Trajectory->data[Trajectory->size[0] * 10 + Trajectory->size[0] *
        Trajectory->size[1] * (kstr - 1)];
      kstr++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  *totalFlightTime = y;

  // plot the trajectory
  // [p1, p2] = trajectoryPlotter(Trajectory);
  // daspect([5 5 5])
  // axis([-1 11 -1 11 -10 10])
  // hold on
  // arrow3(p1, p2, 'b', 0.4)
  // hold off
}

//
// File trailer for minimumTimeTrajectoryGenerator.cpp
//
// [EOF]
//
