/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * minimumTimeTrajectoryGenerator_initialize.c
 *
 * Code generation for function 'minimumTimeTrajectoryGenerator_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "minimumTimeTrajectoryGenerator_initialize.h"
#include "_coder_minimumTimeTrajectoryGenerator_mex.h"
#include "minimumTimeTrajectoryGenerator_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Declarations */
static void c_minimumTimeTrajectoryGenerato(void);

/* Function Definitions */
static void c_minimumTimeTrajectoryGenerato(void)
{
  int32_T cond_starts_0_0[1] = { 1332 };

  int32_T cond_ends_0_0[1] = { 1350 };

  int32_T postfix_exprs_0_0[2] = { 0, -1 };

  int32_T cond_starts_3_0[2] = { 1308, 1343 };

  int32_T cond_ends_3_0[2] = { 1339, 1370 };

  int32_T postfix_exprs_3_0[3] = { 0, 1, -2 };

  int32_T cond_starts_3_1[2] = { 4931, 4963 };

  int32_T cond_ends_3_1[2] = { 4959, 5002 };

  int32_T postfix_exprs_3_1[3] = { 0, 1, -2 };

  int32_T cond_starts_4_0[3] = { 1086, 1108, 1128 };

  int32_T cond_ends_4_0[3] = { 1104, 1124, 1143 };

  int32_T postfix_exprs_4_0[5] = { 0, 1, -3, 2, -3 };

  int32_T cond_starts_4_1[1] = { 1156 };

  int32_T cond_ends_4_1[1] = { 1187 };

  int32_T postfix_exprs_4_1[2] = { 0, -1 };

  int32_T cond_starts_4_2[3] = { 1361, 1383, 1403 };

  int32_T cond_ends_4_2[3] = { 1379, 1399, 1418 };

  int32_T postfix_exprs_4_2[5] = { 0, 1, -3, 2, -3 };

  int32_T cond_starts_4_3[1] = { 1431 };

  int32_T cond_ends_4_3[1] = { 1462 };

  int32_T postfix_exprs_4_3[2] = { 0, -1 };

  int32_T cond_starts_4_4[3] = { 1636, 1658, 1678 };

  int32_T cond_ends_4_4[3] = { 1654, 1674, 1693 };

  int32_T postfix_exprs_4_4[5] = { 0, 1, -3, 2, -3 };

  int32_T cond_starts_4_5[1] = { 1706 };

  int32_T cond_ends_4_5[1] = { 1737 };

  int32_T postfix_exprs_4_5[2] = { 0, -1 };

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/minimumTimeTrajectoryG"
                  "enerator.m", 0, 1, 5, 3, 0, 0, 0, 1, 0, 1, 1);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0, 0, "minimumTimeTrajectoryGenerator", 0,
               -1, 2372);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 4, 2162, -1, 2205);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 3, 1787, -1, 2072);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 2, 1363, -1, 1762);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 1, 1041, -1, 1280);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 0, 899, -1, 963);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0, 0, 995, 1031, 2098, 2160);
  covrtIfInit(&emlrtCoverageInstance, 0, 1, 1327, 1351, 1771, 2084);
  covrtIfInit(&emlrtCoverageInstance, 0, 2, 2098, 2141, 2147, 2160);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 0, 0, 1330, 1351, 1, 0, cond_starts_0_0,
                cond_ends_0_0, 2, postfix_exprs_0_0);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0, 0, 1291, 1318, 2092);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/polynomialTrajectorySo"
                  "lver.m", 1, 1, 7, 2, 0, 0, 0, 1, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1, 0, "polynomialTrajectorySolver", 0, -1,
               1566);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 6, 1396, -1, 1560);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 5, 1329, -1, 1339);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 4, 1308, -1, 1318);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 3, 1198, -1, 1250);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 2, 1127, -1, 1179);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 1, 662, -1, 1027);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 0, 379, -1, 629);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1, 0, 1105, 1118, 1185, 1259);
  covrtIfInit(&emlrtCoverageInstance, 1, 1, 1290, 1303, 1320, 1344);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1, 0, 632, 657, 1263);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/get9DegPolyMatrix.m",
                  2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2, 0, "get9DegPolyMatrix", 0, -1, 1204);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2, 0, 169, -1, 1199);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateActuatorFeasi"
                  "bility.m", 3, 1, 9, 2, 0, 0, 0, 3, 0, 4, 2);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 3, 0, "calculateActuatorFeasibility", 0,
               -1, 5215);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 2, 1379, -1, 1441);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 1, 1246, -1, 1299);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 7, 5011, -1, 5090);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 6, 4741, -1, 4829);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 8, 5191, -1, 5209);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 5, 4548, -1, 4692);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 4, 3222, -1, 4541);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 3, 1620, -1, 3141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3, 0, 536, -1, 924);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 3, 0, 1305, 1370, -1, -2);
  covrtIfInit(&emlrtCoverageInstance, 3, 1, 4928, 5002, -1, -2);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 3, 0, 1308, 1370, 2, 0, cond_starts_3_0,
                cond_ends_3_0, 3, postfix_exprs_3_0);
  covrtMcdcInit(&emlrtCoverageInstance, 3, 1, 4931, 5002, 2, 2, cond_starts_3_1,
                cond_ends_3_1, 3, postfix_exprs_3_1);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 3, 0, 986, 1017, 1453);
  covrtForInit(&emlrtCoverageInstance, 3, 1, 3184, 3217, 4546);
  covrtForInit(&emlrtCoverageInstance, 3, 2, 4703, 4736, 5107);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 3U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/Users/kevinsheridan/Documents/Mac Library/Research & Development/IARC - Mission 7/Mission-7-Tools/Matlab/calculateMaximums.m",
                  4, 1, 8, 6, 0, 0, 0, 5, 0, 12, 6);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 4, 0, "calculateMaximums", 0, -1, 2303);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 7, 2135, -1, 2297);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 6, 1959, -1, 2128);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 5, 1875, -1, 1918);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 4, 1787, -1, 1848);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 3, 1512, -1, 1573);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 2, 1237, -1, 1298);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 1, 676, -1, 1047);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4, 0, 381, -1, 643);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 4, 0, 1083, 1143, -1, 1319);
  covrtIfInit(&emlrtCoverageInstance, 4, 1, 1152, 1187, -1, 1311);
  covrtIfInit(&emlrtCoverageInstance, 4, 2, 1358, 1418, -1, 1594);
  covrtIfInit(&emlrtCoverageInstance, 4, 3, 1427, 1462, -1, 1586);
  covrtIfInit(&emlrtCoverageInstance, 4, 4, 1633, 1693, -1, 1869);
  covrtIfInit(&emlrtCoverageInstance, 4, 5, 1702, 1737, -1, 1861);

  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 4, 0, 1086, 1143, 3, 0, cond_starts_4_0,
                cond_ends_4_0, 5, postfix_exprs_4_0);
  covrtMcdcInit(&emlrtCoverageInstance, 4, 1, 1155, 1187, 1, 3, cond_starts_4_1,
                cond_ends_4_1, 2, postfix_exprs_4_1);
  covrtMcdcInit(&emlrtCoverageInstance, 4, 2, 1361, 1418, 3, 4, cond_starts_4_2,
                cond_ends_4_2, 5, postfix_exprs_4_2);
  covrtMcdcInit(&emlrtCoverageInstance, 4, 3, 1430, 1462, 1, 7, cond_starts_4_3,
                cond_ends_4_3, 2, postfix_exprs_4_3);
  covrtMcdcInit(&emlrtCoverageInstance, 4, 4, 1636, 1693, 3, 8, cond_starts_4_4,
                cond_ends_4_4, 5, postfix_exprs_4_4);
  covrtMcdcInit(&emlrtCoverageInstance, 4, 5, 1705, 1737, 1, 11, cond_starts_4_5,
                cond_ends_4_5, 2, postfix_exprs_4_5);

  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 4, 0, 352, 377, 648);
  covrtForInit(&emlrtCoverageInstance, 4, 1, 1049, 1078, 1323);
  covrtForInit(&emlrtCoverageInstance, 4, 2, 1324, 1353, 1598);
  covrtForInit(&emlrtCoverageInstance, 4, 3, 1599, 1628, 1873);
  covrtForInit(&emlrtCoverageInstance, 4, 4, 1921, 1954, 2133);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 4U);
}

void minimumTimeTrajectoryGenerator_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    c_minimumTimeTrajectoryGenerato();
  }
}

/* End of code generation (minimumTimeTrajectoryGenerator_initialize.c) */
