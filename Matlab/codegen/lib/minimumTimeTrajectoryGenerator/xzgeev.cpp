//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeev.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "xzgeev.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "minimumTimeTrajectoryGenerator_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const creal32_T A_data[]
//                const int A_size[2]
//                int *info
//                creal32_T alpha1_data[]
//                int alpha1_size[1]
//                creal32_T beta1_data[]
//                int beta1_size[1]
// Return Type  : void
//
void xzgeev(const creal32_T A_data[], const int A_size[2], int *info, creal32_T
            alpha1_data[], int alpha1_size[1], creal32_T beta1_data[], int
            beta1_size[1])
{
  int At_size[2];
  int ii;
  int i3;
  creal32_T At_data[64];
  float anrm;
  boolean_T exitg7;
  float absxk;
  boolean_T ilascl;
  float anrmto;
  int ilo;
  float ctoc;
  int ihi;
  boolean_T notdone;
  int exitg2;
  float stemp_im;
  int i;
  float cto1;
  int j;
  float mul;
  boolean_T exitg5;
  int nzcount;
  creal32_T atmp;
  int jj;
  boolean_T exitg6;
  creal32_T b_A_data[64];
  int exitg1;
  boolean_T guard2 = false;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T guard1 = false;
  At_size[0] = A_size[0];
  At_size[1] = A_size[1];
  ii = A_size[0] * A_size[1];
  for (i3 = 0; i3 < ii; i3++) {
    At_data[i3] = A_data[i3];
  }

  *info = 0;
  anrm = 0.0F;
  i3 = A_size[0] * A_size[1];
  ii = 0;
  exitg7 = false;
  while ((!exitg7) && (ii <= i3 - 1)) {
    absxk = rt_hypotf_snf(A_data[ii].re, A_data[ii].im);
    if (rtIsNaNF(absxk)) {
      anrm = ((real32_T)rtNaN);
      exitg7 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      ii++;
    }
  }

  if (!((!rtIsInfF(anrm)) && (!rtIsNaNF(anrm)))) {
    alpha1_size[0] = A_size[0];
    ii = A_size[0];
    for (i3 = 0; i3 < ii; i3++) {
      alpha1_data[i3].re = ((real32_T)rtNaN);
      alpha1_data[i3].im = 0.0F;
    }

    beta1_size[0] = A_size[0];
    ii = A_size[0];
    for (i3 = 0; i3 < ii; i3++) {
      beta1_data[i3].re = ((real32_T)rtNaN);
      beta1_data[i3].im = 0.0F;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0F) && (anrm < 9.09494702E-13F)) {
      anrmto = 9.09494702E-13F;
      ilascl = true;
    } else {
      if (anrm > 1.09951163E+12F) {
        anrmto = 1.09951163E+12F;
        ilascl = true;
      }
    }

    if (ilascl) {
      absxk = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        stemp_im = absxk * 1.97215226E-31F;
        cto1 = ctoc / 5.0706024E+30F;
        if ((stemp_im > ctoc) && (ctoc != 0.0F)) {
          mul = 1.97215226E-31F;
          absxk = stemp_im;
        } else if (cto1 > absxk) {
          mul = 5.0706024E+30F;
          ctoc = cto1;
        } else {
          mul = ctoc / absxk;
          notdone = false;
        }

        ii = At_size[0] * At_size[1];
        for (i3 = 0; i3 < ii; i3++) {
          At_data[i3].re *= mul;
          At_data[i3].im *= mul;
        }
      }
    }

    ilo = 0;
    ihi = A_size[0];
    if (A_size[0] <= 1) {
      ihi = 1;
    } else {
      do {
        exitg2 = 0;
        i = 0;
        j = 0;
        notdone = false;
        ii = ihi;
        exitg5 = false;
        while ((!exitg5) && (ii > 0)) {
          nzcount = 0;
          i = ii;
          j = ihi;
          jj = 1;
          exitg6 = false;
          while ((!exitg6) && (jj <= ihi)) {
            guard2 = false;
            if ((At_data[(ii + At_size[0] * (jj - 1)) - 1].re != 0.0F) ||
                (At_data[(ii + At_size[0] * (jj - 1)) - 1].im != 0.0F) || (ii ==
                 jj)) {
              if (nzcount == 0) {
                j = jj;
                nzcount = 1;
                guard2 = true;
              } else {
                nzcount = 2;
                exitg6 = true;
              }
            } else {
              guard2 = true;
            }

            if (guard2) {
              jj++;
            }
          }

          if (nzcount < 2) {
            notdone = true;
            exitg5 = true;
          } else {
            ii--;
          }
        }

        if (!notdone) {
          exitg2 = 2;
        } else {
          nzcount = At_size[0];
          jj = At_size[1];
          ii = At_size[0] * At_size[1];
          for (i3 = 0; i3 < ii; i3++) {
            b_A_data[i3] = At_data[i3];
          }

          if (i != ihi) {
            for (ii = 0; ii + 1 <= At_size[0]; ii++) {
              atmp = b_A_data[(i + nzcount * ii) - 1];
              b_A_data[(i + nzcount * ii) - 1] = b_A_data[(ihi + nzcount * ii) -
                1];
              b_A_data[(ihi + nzcount * ii) - 1] = atmp;
            }
          }

          if (j != ihi) {
            for (ii = 0; ii + 1 <= ihi; ii++) {
              atmp = b_A_data[ii + nzcount * (j - 1)];
              b_A_data[ii + nzcount * (j - 1)] = b_A_data[ii + nzcount * (ihi -
                1)];
              b_A_data[ii + nzcount * (ihi - 1)] = atmp;
            }
          }

          ii = nzcount * jj;
          for (i3 = 0; i3 < ii; i3++) {
            At_data[i3] = b_A_data[i3];
          }

          ihi--;
          if (ihi == 1) {
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);

      if (exitg2 == 1) {
      } else {
        do {
          exitg1 = 0;
          i = 0;
          j = 0;
          notdone = false;
          jj = ilo + 1;
          exitg3 = false;
          while ((!exitg3) && (jj <= ihi)) {
            nzcount = 0;
            i = ihi;
            j = jj;
            ii = ilo + 1;
            exitg4 = false;
            while ((!exitg4) && (ii <= ihi)) {
              guard1 = false;
              if ((At_data[(ii + At_size[0] * (jj - 1)) - 1].re != 0.0F) ||
                  (At_data[(ii + At_size[0] * (jj - 1)) - 1].im != 0.0F) || (ii ==
                   jj)) {
                if (nzcount == 0) {
                  i = ii;
                  nzcount = 1;
                  guard1 = true;
                } else {
                  nzcount = 2;
                  exitg4 = true;
                }
              } else {
                guard1 = true;
              }

              if (guard1) {
                ii++;
              }
            }

            if (nzcount < 2) {
              notdone = true;
              exitg3 = true;
            } else {
              jj++;
            }
          }

          if (!notdone) {
            exitg1 = 1;
          } else {
            nzcount = At_size[0];
            jj = At_size[1];
            ii = At_size[0] * At_size[1];
            for (i3 = 0; i3 < ii; i3++) {
              b_A_data[i3] = At_data[i3];
            }

            if (i != ilo + 1) {
              for (ii = ilo; ii + 1 <= At_size[0]; ii++) {
                atmp = b_A_data[(i + nzcount * ii) - 1];
                b_A_data[(i + nzcount * ii) - 1] = b_A_data[ilo + nzcount * ii];
                b_A_data[ilo + nzcount * ii] = atmp;
              }
            }

            if (j != ilo + 1) {
              for (ii = 0; ii + 1 <= ihi; ii++) {
                atmp = b_A_data[ii + nzcount * (j - 1)];
                b_A_data[ii + nzcount * (j - 1)] = b_A_data[ii + nzcount * ilo];
                b_A_data[ii + nzcount * ilo] = atmp;
              }
            }

            ii = nzcount * jj;
            for (i3 = 0; i3 < ii; i3++) {
              At_data[i3] = b_A_data[i3];
            }

            ilo++;
            if (ilo + 1 == ihi) {
              exitg1 = 1;
            }
          }
        } while (exitg1 == 0);
      }
    }

    if ((At_size[0] <= 1) || (ihi < ilo + 3)) {
    } else {
      for (ii = ilo; ii + 1 < ihi - 1; ii++) {
        for (nzcount = ihi - 1; nzcount + 1 > ii + 2; nzcount--) {
          xzlartg(At_data[(nzcount + At_size[0] * ii) - 1], At_data[nzcount +
                  At_size[0] * ii], &absxk, &atmp, &At_data[(nzcount + At_size[0]
                   * ii) - 1]);
          At_data[nzcount + At_size[0] * ii].re = 0.0F;
          At_data[nzcount + At_size[0] * ii].im = 0.0F;
          for (j = ii + 1; j + 1 <= At_size[0]; j++) {
            ctoc = absxk * At_data[(nzcount + At_size[0] * j) - 1].re + (atmp.re
              * At_data[nzcount + At_size[0] * j].re - atmp.im * At_data[nzcount
              + At_size[0] * j].im);
            stemp_im = absxk * At_data[(nzcount + At_size[0] * j) - 1].im +
              (atmp.re * At_data[nzcount + At_size[0] * j].im + atmp.im *
               At_data[nzcount + At_size[0] * j].re);
            cto1 = At_data[(nzcount + At_size[0] * j) - 1].re;
            At_data[nzcount + At_size[0] * j].re = absxk * At_data[nzcount +
              At_size[0] * j].re - (atmp.re * At_data[(nzcount + At_size[0] * j)
              - 1].re + atmp.im * At_data[(nzcount + At_size[0] * j) - 1].im);
            At_data[nzcount + At_size[0] * j].im = absxk * At_data[nzcount +
              At_size[0] * j].im - (atmp.re * At_data[(nzcount + At_size[0] * j)
              - 1].im - atmp.im * cto1);
            At_data[(nzcount + At_size[0] * j) - 1].re = ctoc;
            At_data[(nzcount + At_size[0] * j) - 1].im = stemp_im;
          }

          atmp.re = -atmp.re;
          atmp.im = -atmp.im;
          for (i = 0; i + 1 <= ihi; i++) {
            ctoc = absxk * At_data[i + At_size[0] * nzcount].re + (atmp.re *
              At_data[i + At_size[0] * (nzcount - 1)].re - atmp.im * At_data[i +
              At_size[0] * (nzcount - 1)].im);
            stemp_im = absxk * At_data[i + At_size[0] * nzcount].im + (atmp.re *
              At_data[i + At_size[0] * (nzcount - 1)].im + atmp.im * At_data[i +
              At_size[0] * (nzcount - 1)].re);
            cto1 = At_data[i + At_size[0] * nzcount].re;
            At_data[i + At_size[0] * (nzcount - 1)].re = absxk * At_data[i +
              At_size[0] * (nzcount - 1)].re - (atmp.re * At_data[i + At_size[0]
              * nzcount].re + atmp.im * At_data[i + At_size[0] * nzcount].im);
            At_data[i + At_size[0] * (nzcount - 1)].im = absxk * At_data[i +
              At_size[0] * (nzcount - 1)].im - (atmp.re * At_data[i + At_size[0]
              * nzcount].im - atmp.im * cto1);
            At_data[i + At_size[0] * nzcount].re = ctoc;
            At_data[i + At_size[0] * nzcount].im = stemp_im;
          }
        }
      }
    }

    xzhgeqz(At_data, At_size, ilo + 1, ihi, info, alpha1_data, alpha1_size,
            beta1_data, beta1_size);
    if ((*info != 0) || (!ilascl)) {
    } else {
      notdone = true;
      while (notdone) {
        stemp_im = anrmto * 1.97215226E-31F;
        cto1 = anrm / 5.0706024E+30F;
        if ((stemp_im > anrm) && (anrm != 0.0F)) {
          mul = 1.97215226E-31F;
          anrmto = stemp_im;
        } else if (cto1 > anrmto) {
          mul = 5.0706024E+30F;
          anrm = cto1;
        } else {
          mul = anrm / anrmto;
          notdone = false;
        }

        ii = alpha1_size[0];
        for (i3 = 0; i3 < ii; i3++) {
          alpha1_data[i3].re *= mul;
          alpha1_data[i3].im *= mul;
        }
      }
    }
  }
}

//
// File trailer for xzgeev.cpp
//
// [EOF]
//
