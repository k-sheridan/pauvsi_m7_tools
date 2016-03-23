//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "main.h"
#include "minimumTimeTrajectoryGenerator_terminate.h"
#include "minimumTimeTrajectoryGenerator_emxAPI.h"
#include "minimumTimeTrajectoryGenerator_initialize.h"
#include <stdio.h>

// Function Declarations
static void argInit_1x3_real32_T(float result[3]);
static void argInit_1xd10_char_T(char result_data[], int result_size[2]);
static void argInit_3x5_real32_T(float result[15]);
static emxArray_real32_T *argInit_6xUnbounded_real32_T();
static char argInit_char_T();
static float argInit_real32_T();
static void c_main_minimumTimeTrajectoryGen();

// Function Definitions

//
// Arguments    : float result[3]
// Return Type  : void
//
static void argInit_1x3_real32_T(float result[3])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 3; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real32_T();
  }
}

//
// Arguments    : char result_data[]
//                int result_size[2]
// Return Type  : void
//
static void argInit_1xd10_char_T(char result_data[], int result_size[2])
{
  int idx1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 1;
  result_size[1] = 2;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[idx1] = argInit_char_T();
  }
}

//
// Arguments    : float result[15]
// Return Type  : void
//
static void argInit_3x5_real32_T(float result[15])
{
  int idx0;
  int idx1;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < 5; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + 3 * idx1] = argInit_real32_T();
    }
  }
}

//
// Arguments    : void
// Return Type  : emxArray_real32_T *
//
static emxArray_real32_T *argInit_6xUnbounded_real32_T()
{
  emxArray_real32_T *result;
  static int iv5[2] = { 6, 2 };

  int idx0;
  int idx1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real32_T(2, *(int (*)[2])&iv5[0]);

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 6; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result->data[idx0 + result->size[0] * idx1] = argInit_real32_T();
    }
  }

  return result;
}

//
// Arguments    : void
// Return Type  : char
//
static char argInit_char_T()
{
  return '?';
}

//
// Arguments    : void
// Return Type  : float
//
static float argInit_real32_T()
{
  return 0.0F;
}

//
// Arguments    : void
// Return Type  : void
//
static void c_main_minimumTimeTrajectoryGen()
{
  emxArray_real32_T *Trajectory;
  float start[15];
  emxArray_real32_T *mid;
  float final[15];
  char MIDPOINT_MODE_data[10];
  int MIDPOINT_MODE_size[2];
  float fv3[3];
  float totalFlightTime;
  emxInitArray_real32_T(&Trajectory, 3);

  // Initialize function 'minimumTimeTrajectoryGenerator' input arguments.
  // Initialize function input argument 'start'.
  argInit_3x5_real32_T(start);

  // Initialize function input argument 'mid'.
  mid = argInit_6xUnbounded_real32_T();

  // Initialize function input argument 'final'.
  argInit_3x5_real32_T(final);

  // Initialize function input argument 'MIDPOINT_MODE'.
  argInit_1xd10_char_T(MIDPOINT_MODE_data, MIDPOINT_MODE_size);

  // Initialize function input argument 'Moment'.
  // Call the entry-point 'minimumTimeTrajectoryGenerator'.
  argInit_1x3_real32_T(fv3);
  minimumTimeTrajectoryGenerator(start, mid, final, MIDPOINT_MODE_data,
    MIDPOINT_MODE_size, argInit_real32_T(), fv3, argInit_real32_T(),
    argInit_real32_T(), argInit_real32_T(), argInit_real32_T(), Trajectory,
    &totalFlightTime);
  emxDestroyArray_real32_T(Trajectory);
  emxDestroyArray_real32_T(mid);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  minimumTimeTrajectoryGenerator_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  c_main_minimumTimeTrajectoryGen();

  // Terminate the application.
  // You do not need to do this more than one time.
  minimumTimeTrajectoryGenerator_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
