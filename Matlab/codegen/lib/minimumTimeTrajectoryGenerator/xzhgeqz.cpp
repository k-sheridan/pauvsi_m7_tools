//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzhgeqz.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "sqrt.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const creal32_T A_data[]
//                const int A_size[2]
//                int ilo
//                int ihi
//                int *info
//                creal32_T alpha1_data[]
//                int alpha1_size[1]
//                creal32_T beta1_data[]
//                int beta1_size[1]
// Return Type  : void
//
void xzhgeqz(const creal32_T A_data[], const int A_size[2], int ilo, int ihi,
             int *info, creal32_T alpha1_data[], int alpha1_size[1], creal32_T
             beta1_data[], int beta1_size[1])
{
  int A_size_idx_0;
  int jp1;
  int jm1;
  creal32_T b_A_data[64];
  float eshift_re;
  float eshift_im;
  creal32_T ctemp;
  float anorm;
  float scale;
  float sumsq;
  float reAij;
  boolean_T firstNonZero;
  float b_atol;
  int j;
  float ascale;
  int i;
  float bscale;
  boolean_T failed;
  float imAij;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int ifirst;
  float temp2;
  int istart;
  int ilast;
  int ilastm1;
  int ifrstm;
  int ilastm;
  int iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int jiter;
  int exitg1;
  boolean_T exitg3;
  boolean_T b_guard1 = false;
  creal32_T b_ascale;
  creal32_T shift;
  float ad22_re;
  float ad22_im;
  boolean_T exitg2;
  float t1_im;
  A_size_idx_0 = A_size[0];
  jp1 = A_size[0] * A_size[1];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    b_A_data[jm1] = A_data[jm1];
  }

  *info = 0;
  if ((A_size[0] == 1) && (A_size[1] == 1)) {
    ihi = 1;
  }

  alpha1_size[0] = A_size[0];
  jp1 = A_size[0];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    alpha1_data[jm1].re = 0.0F;
    alpha1_data[jm1].im = 0.0F;
  }

  beta1_size[0] = A_size[0];
  jp1 = A_size[0];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    beta1_data[jm1].re = 1.0F;
    beta1_data[jm1].im = 0.0F;
  }

  eshift_re = 0.0F;
  eshift_im = 0.0F;
  ctemp.re = 0.0F;
  ctemp.im = 0.0F;
  anorm = 0.0F;
  if (ilo > ihi) {
  } else {
    scale = 0.0F;
    sumsq = 0.0F;
    firstNonZero = true;
    for (j = ilo; j <= ihi; j++) {
      jm1 = j + 1;
      if (ihi < j + 1) {
        jm1 = ihi;
      }

      for (i = ilo; i <= jm1; i++) {
        reAij = A_data[(i + A_size[0] * (j - 1)) - 1].re;
        imAij = A_data[(i + A_size[0] * (j - 1)) - 1].im;
        if (reAij != 0.0F) {
          anorm = (float)fabs((double)reAij);
          if (firstNonZero) {
            sumsq = 1.0F;
            scale = anorm;
            firstNonZero = false;
          } else if (scale < anorm) {
            temp2 = scale / anorm;
            sumsq = 1.0F + sumsq * temp2 * temp2;
            scale = anorm;
          } else {
            temp2 = anorm / scale;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0F) {
          anorm = (float)fabs((double)imAij);
          if (firstNonZero) {
            sumsq = 1.0F;
            scale = anorm;
            firstNonZero = false;
          } else if (scale < anorm) {
            temp2 = scale / anorm;
            sumsq = 1.0F + sumsq * temp2 * temp2;
            scale = anorm;
          } else {
            temp2 = anorm / scale;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    anorm = scale * (float)sqrt((double)sumsq);
  }

  reAij = 1.1920929E-7F * anorm;
  b_atol = 1.17549435E-38F;
  if (reAij > 1.17549435E-38F) {
    b_atol = reAij;
  }

  reAij = 1.17549435E-38F;
  if (anorm > 1.17549435E-38F) {
    reAij = anorm;
  }

  ascale = 1.0F / reAij;
  bscale = 1.0F / (float)sqrt((double)(float)A_size[0]);
  failed = true;
  for (j = ihi; j + 1 <= A_size[0]; j++) {
    alpha1_data[j] = A_data[j + A_size[0] * j];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    ifrstm = ilo;
    ilastm = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1)) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if ((float)fabs((double)b_A_data[ilast + A_size_idx_0 * ilastm1].
                               re) + (float)fabs((double)b_A_data[ilast +
                    A_size_idx_0 * ilastm1].im) <= b_atol) {
          b_A_data[ilast + A_size_idx_0 * ilastm1].re = 0.0F;
          b_A_data[ilast + A_size_idx_0 * ilastm1].im = 0.0F;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg3 = false;
          while ((!exitg3) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              firstNonZero = true;
            } else if ((float)fabs((double)b_A_data[j + A_size_idx_0 * (j - 1)].
                                   re) + (float)fabs((double)b_A_data[j +
                        A_size_idx_0 * (j - 1)].im) <= b_atol) {
              b_A_data[j + A_size_idx_0 * (j - 1)].re = 0.0F;
              b_A_data[j + A_size_idx_0 * (j - 1)].im = 0.0F;
              firstNonZero = true;
            } else {
              firstNonZero = false;
            }

            if (firstNonZero) {
              ifirst = j + 1;
              goto70 = true;
              exitg3 = true;
            } else {
              j--;
            }
          }
        }

        if (goto60 || goto70) {
          firstNonZero = true;
        } else {
          firstNonZero = false;
        }

        if (!firstNonZero) {
          jp1 = alpha1_size[0];
          for (jm1 = 0; jm1 < jp1; jm1++) {
            alpha1_data[jm1].re = ((real32_T)rtNaN);
            alpha1_data[jm1].im = 0.0F;
          }

          jp1 = beta1_size[0];
          for (jm1 = 0; jm1 < jp1; jm1++) {
            beta1_data[jm1].re = ((real32_T)rtNaN);
            beta1_data[jm1].im = 0.0F;
          }

          *info = 1;
          exitg1 = 1;
        } else {
          b_guard1 = false;
          if (goto60) {
            goto60 = false;
            alpha1_data[ilast] = b_A_data[ilast + A_size_idx_0 * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0F;
              eshift_im = 0.0F;
              ilastm = ilast + 1;
              if (ifrstm > ilast + 1) {
                ifrstm = ilo;
              }

              b_guard1 = true;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              ifrstm = ifirst;
              if (iiter - iiter / 10 * 10 != 0) {
                anorm = ascale * b_A_data[ilastm1 + A_size_idx_0 * ilastm1].re;
                reAij = ascale * b_A_data[ilastm1 + A_size_idx_0 * ilastm1].im;
                if (reAij == 0.0F) {
                  shift.re = anorm / bscale;
                  shift.im = 0.0F;
                } else if (anorm == 0.0F) {
                  shift.re = 0.0F;
                  shift.im = reAij / bscale;
                } else {
                  shift.re = anorm / bscale;
                  shift.im = reAij / bscale;
                }

                anorm = ascale * b_A_data[ilast + A_size_idx_0 * ilast].re;
                reAij = ascale * b_A_data[ilast + A_size_idx_0 * ilast].im;
                if (reAij == 0.0F) {
                  ad22_re = anorm / bscale;
                  ad22_im = 0.0F;
                } else if (anorm == 0.0F) {
                  ad22_re = 0.0F;
                  ad22_im = reAij / bscale;
                } else {
                  ad22_re = anorm / bscale;
                  ad22_im = reAij / bscale;
                }

                temp2 = 0.5F * (shift.re + ad22_re);
                t1_im = 0.5F * (shift.im + ad22_im);
                anorm = ascale * b_A_data[ilastm1 + A_size_idx_0 * ilast].re;
                reAij = ascale * b_A_data[ilastm1 + A_size_idx_0 * ilast].im;
                if (reAij == 0.0F) {
                  sumsq = anorm / bscale;
                  imAij = 0.0F;
                } else if (anorm == 0.0F) {
                  sumsq = 0.0F;
                  imAij = reAij / bscale;
                } else {
                  sumsq = anorm / bscale;
                  imAij = reAij / bscale;
                }

                anorm = ascale * b_A_data[ilast + A_size_idx_0 * ilastm1].re;
                reAij = ascale * b_A_data[ilast + A_size_idx_0 * ilastm1].im;
                if (reAij == 0.0F) {
                  scale = anorm / bscale;
                  anorm = 0.0F;
                } else if (anorm == 0.0F) {
                  scale = 0.0F;
                  anorm = reAij / bscale;
                } else {
                  scale = anorm / bscale;
                  anorm = reAij / bscale;
                }

                reAij = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((temp2 * temp2 - t1_im * t1_im) + (sumsq * scale -
                  imAij * anorm)) - (shift.re * ad22_re - shift.im * ad22_im);
                shift.im = ((temp2 * t1_im + t1_im * temp2) + (sumsq * anorm +
                  imAij * scale)) - reAij;
                b_sqrt(&shift);
                if ((temp2 - ad22_re) * shift.re + (t1_im - ad22_im) * shift.im <=
                    0.0F) {
                  shift.re += temp2;
                  shift.im += t1_im;
                } else {
                  shift.re = temp2 - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                anorm = ascale * b_A_data[ilast + A_size_idx_0 * ilastm1].re;
                reAij = ascale * b_A_data[ilast + A_size_idx_0 * ilastm1].im;
                if (reAij == 0.0F) {
                  sumsq = anorm / bscale;
                  imAij = 0.0F;
                } else if (anorm == 0.0F) {
                  sumsq = 0.0F;
                  imAij = reAij / bscale;
                } else {
                  sumsq = anorm / bscale;
                  imAij = reAij / bscale;
                }

                eshift_re += sumsq;
                eshift_im += imAij;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp.re = ascale * b_A_data[j + A_size_idx_0 * j].re - shift.re
                  * bscale;
                ctemp.im = ascale * b_A_data[j + A_size_idx_0 * j].im - shift.im
                  * bscale;
                anorm = (float)fabs((double)ctemp.re) + (float)fabs((double)
                  ctemp.im);
                temp2 = ascale * ((float)fabs((double)b_A_data[jp1 +
                  A_size_idx_0 * j].re) + (float)fabs((double)b_A_data[jp1 +
                  A_size_idx_0 * j].im));
                reAij = anorm;
                if (temp2 > anorm) {
                  reAij = temp2;
                }

                if ((reAij < 1.0F) && (reAij != 0.0F)) {
                  anorm /= reAij;
                  temp2 /= reAij;
                }

                if (((float)fabs((double)b_A_data[j + A_size_idx_0 * (j - 1)].re)
                     + (float)fabs((double)b_A_data[j + A_size_idx_0 * (j - 1)].
                                   im)) * temp2 <= anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                ctemp.re = ascale * b_A_data[(ifirst + A_size_idx_0 * (ifirst -
                  1)) - 1].re - shift.re * bscale;
                ctemp.im = ascale * b_A_data[(ifirst + A_size_idx_0 * (ifirst -
                  1)) - 1].im - shift.im * bscale;
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              b_ascale.re = ascale * b_A_data[istart + A_size_idx_0 * (istart -
                1)].re;
              b_ascale.im = ascale * b_A_data[istart + A_size_idx_0 * (istart -
                1)].im;
              b_xzlartg(ctemp, b_ascale, &anorm, &shift);
              j = istart;
              jm1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  xzlartg(b_A_data[(j + A_size_idx_0 * jm1) - 1], b_A_data[j +
                          A_size_idx_0 * jm1], &anorm, &shift, &b_A_data[(j +
                           A_size_idx_0 * jm1) - 1]);
                  b_A_data[j + A_size_idx_0 * jm1].re = 0.0F;
                  b_A_data[j + A_size_idx_0 * jm1].im = 0.0F;
                }

                for (jp1 = j - 1; jp1 + 1 <= ilastm; jp1++) {
                  ad22_re = anorm * b_A_data[(j + A_size_idx_0 * jp1) - 1].re +
                    (shift.re * b_A_data[j + A_size_idx_0 * jp1].re - shift.im *
                     b_A_data[j + A_size_idx_0 * jp1].im);
                  ad22_im = anorm * b_A_data[(j + A_size_idx_0 * jp1) - 1].im +
                    (shift.re * b_A_data[j + A_size_idx_0 * jp1].im + shift.im *
                     b_A_data[j + A_size_idx_0 * jp1].re);
                  reAij = b_A_data[(j + A_size_idx_0 * jp1) - 1].re;
                  b_A_data[j + A_size_idx_0 * jp1].re = anorm * b_A_data[j +
                    A_size_idx_0 * jp1].re - (shift.re * b_A_data[(j +
                    A_size_idx_0 * jp1) - 1].re + shift.im * b_A_data[(j +
                    A_size_idx_0 * jp1) - 1].im);
                  b_A_data[j + A_size_idx_0 * jp1].im = anorm * b_A_data[j +
                    A_size_idx_0 * jp1].im - (shift.re * b_A_data[(j +
                    A_size_idx_0 * jp1) - 1].im - shift.im * reAij);
                  b_A_data[(j + A_size_idx_0 * jp1) - 1].re = ad22_re;
                  b_A_data[(j + A_size_idx_0 * jp1) - 1].im = ad22_im;
                }

                shift.re = -shift.re;
                shift.im = -shift.im;
                jp1 = j;
                if (ilast + 1 < j + 2) {
                  jp1 = ilast - 1;
                }

                for (i = ifrstm - 1; i + 1 <= jp1 + 2; i++) {
                  ad22_re = anorm * b_A_data[i + A_size_idx_0 * j].re +
                    (shift.re * b_A_data[i + A_size_idx_0 * (j - 1)].re -
                     shift.im * b_A_data[i + A_size_idx_0 * (j - 1)].im);
                  ad22_im = anorm * b_A_data[i + A_size_idx_0 * j].im +
                    (shift.re * b_A_data[i + A_size_idx_0 * (j - 1)].im +
                     shift.im * b_A_data[i + A_size_idx_0 * (j - 1)].re);
                  reAij = b_A_data[i + A_size_idx_0 * j].re;
                  b_A_data[i + A_size_idx_0 * (j - 1)].re = anorm * b_A_data[i +
                    A_size_idx_0 * (j - 1)].re - (shift.re * b_A_data[i +
                    A_size_idx_0 * j].re + shift.im * b_A_data[i + A_size_idx_0 *
                    j].im);
                  b_A_data[i + A_size_idx_0 * (j - 1)].im = anorm * b_A_data[i +
                    A_size_idx_0 * (j - 1)].im - (shift.re * b_A_data[i +
                    A_size_idx_0 * j].im - shift.im * reAij);
                  b_A_data[i + A_size_idx_0 * j].re = ad22_re;
                  b_A_data[i + A_size_idx_0 * j].im = ad22_im;
                }

                jm1 = j - 1;
                j++;
              }
            }

            b_guard1 = true;
          }

          if (b_guard1) {
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 + 1 <= ilast + 1; jp1++) {
        alpha1_data[jp1].re = ((real32_T)rtNaN);
        alpha1_data[jp1].im = 0.0F;
        beta1_data[jp1].re = ((real32_T)rtNaN);
        beta1_data[jp1].im = 0.0F;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (j = 0; j + 1 < ilo; j++) {
      alpha1_data[j] = b_A_data[j + A_size_idx_0 * j];
    }
  }
}

//
// File trailer for xzhgeqz.cpp
//
// [EOF]
//
