//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fprintf.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "fprintf.h"
#include "fileManager.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : void
// Return Type  : int
//
int b_cfprintf()
{
  int nbytesint;
  FILE * b_NULL;
  FILE * filestar;
  boolean_T autoflush;
  static const char cfmt[33] = { 'I', 'N', 'D', 'I', 'V', 'I', 'D', 'U', 'A',
    'L', ' ', 'M', 'O', 'T', 'O', 'R', ' ', 'F', 'O', 'R', 'C', 'E', ' ', 'T',
    'O', 'O', ' ', 'H', 'I', 'G', 'H', '\x0a', '\x00' };

  b_NULL = NULL;
  nbytesint = 0;
  b_fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt);
    fflush(filestar);
  }

  return nbytesint;
}

//
// Arguments    : void
// Return Type  : int
//
int cfprintf()
{
  int nbytesint;
  FILE * b_NULL;
  FILE * filestar;
  boolean_T autoflush;
  static const char cfmt[16] = { 'F', 'O', 'R', 'C', 'E', ' ', 'T', 'O', 'O',
    ' ', 'H', 'I', 'G', 'H', '\x0a', '\x00' };

  b_NULL = NULL;
  nbytesint = 0;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt);
    fflush(filestar);
  }

  return nbytesint;
}

//
// File trailer for fprintf.cpp
//
// [EOF]
//
