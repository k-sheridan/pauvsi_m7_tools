//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlartg.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 22-Mar-2016 21:24:49
//

// Include Files
#include "rt_nonfinite.h"
#include "minimumTimeTrajectoryGenerator.h"
#include "xzlartg.h"
#include "minimumTimeTrajectoryGenerator_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const creal32_T f
//                const creal32_T g
//                float *cs
//                creal32_T *sn
// Return Type  : void
//
void b_xzlartg(const creal32_T f, const creal32_T g, float *cs, creal32_T *sn)
{
  float scale;
  float g2;
  float f2s;
  float fs_re;
  float fs_im;
  float gs_re;
  float gs_im;
  boolean_T guard1 = false;
  float g2s;
  float d;
  scale = (float)fabs((double)f.re);
  g2 = (float)fabs((double)f.im);
  if (g2 > scale) {
    scale = g2;
  }

  f2s = (float)fabs((double)g.re);
  g2 = (float)fabs((double)g.im);
  if (g2 > f2s) {
    f2s = g2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  guard1 = false;
  if (scale >= 5.49755814E+11F) {
    do {
      fs_re *= 1.8189894E-12F;
      fs_im *= 1.8189894E-12F;
      gs_re *= 1.8189894E-12F;
      gs_im *= 1.8189894E-12F;
      scale *= 1.8189894E-12F;
    } while (!(scale < 5.49755814E+11F));

    guard1 = true;
  } else if (scale <= 1.8189894E-12F) {
    if ((g.re == 0.0F) && (g.im == 0.0F)) {
      *cs = 1.0F;
      sn->re = 0.0F;
      sn->im = 0.0F;
    } else {
      do {
        fs_re *= 5.49755814E+11F;
        fs_im *= 5.49755814E+11F;
        gs_re *= 5.49755814E+11F;
        gs_im *= 5.49755814E+11F;
        scale *= 5.49755814E+11F;
      } while (!(scale > 1.8189894E-12F));

      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0F > g2) {
      f2s = 1.0F;
    }

    if (scale <= f2s * 1.97215226E-31F) {
      if ((f.re == 0.0F) && (f.im == 0.0F)) {
        *cs = 0.0F;
        d = rt_hypotf_snf(gs_re, gs_im);
        sn->re = gs_re / d;
        sn->im = -gs_im / d;
      } else {
        g2s = (float)sqrt((double)g2);
        *cs = rt_hypotf_snf(fs_re, fs_im) / g2s;
        f2s = (float)fabs((double)f.re);
        g2 = (float)fabs((double)f.im);
        if (g2 > f2s) {
          f2s = g2;
        }

        if (f2s > 1.0F) {
          d = rt_hypotf_snf(f.re, f.im);
          fs_re = f.re / d;
          fs_im = f.im / d;
        } else {
          g2 = 5.49755814E+11F * f.re;
          scale = 5.49755814E+11F * f.im;
          d = rt_hypotf_snf(g2, scale);
          fs_re = g2 / d;
          fs_im = scale / d;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      f2s = (float)sqrt((double)(1.0F + g2 / scale));
      *cs = 1.0F / f2s;
      d = scale + g2;
      fs_re = f2s * fs_re / d;
      fs_im = f2s * fs_im / d;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
    }
  }
}

//
// Arguments    : const creal32_T f
//                const creal32_T g
//                float *cs
//                creal32_T *sn
//                creal32_T *r
// Return Type  : void
//
void xzlartg(const creal32_T f, const creal32_T g, float *cs, creal32_T *sn,
             creal32_T *r)
{
  float scale;
  float f2s;
  float x;
  float fs_re;
  float fs_im;
  float gs_re;
  float gs_im;
  int count;
  int rescaledir;
  boolean_T guard1 = false;
  float g2;
  float g2s;
  scale = (float)fabs((double)f.re);
  f2s = (float)fabs((double)f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  x = (float)fabs((double)g.re);
  f2s = (float)fabs((double)g.im);
  if (f2s > x) {
    x = f2s;
  }

  if (x > scale) {
    scale = x;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 5.49755814E+11F) {
    do {
      count++;
      fs_re *= 1.8189894E-12F;
      fs_im *= 1.8189894E-12F;
      gs_re *= 1.8189894E-12F;
      gs_im *= 1.8189894E-12F;
      scale *= 1.8189894E-12F;
    } while (!(scale < 5.49755814E+11F));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.8189894E-12F) {
    if ((g.re == 0.0F) && (g.im == 0.0F)) {
      *cs = 1.0F;
      sn->re = 0.0F;
      sn->im = 0.0F;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 5.49755814E+11F;
        fs_im *= 5.49755814E+11F;
        gs_re *= 5.49755814E+11F;
        gs_im *= 5.49755814E+11F;
        scale *= 5.49755814E+11F;
      } while (!(scale > 1.8189894E-12F));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    x = g2;
    if (1.0F > g2) {
      x = 1.0F;
    }

    if (scale <= x * 1.97215226E-31F) {
      if ((f.re == 0.0F) && (f.im == 0.0F)) {
        *cs = 0.0F;
        r->re = rt_hypotf_snf(g.re, g.im);
        r->im = 0.0F;
        g2 = rt_hypotf_snf(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        g2s = (float)sqrt((double)g2);
        *cs = rt_hypotf_snf(fs_re, fs_im) / g2s;
        x = (float)fabs((double)f.re);
        f2s = (float)fabs((double)f.im);
        if (f2s > x) {
          x = f2s;
        }

        if (x > 1.0F) {
          g2 = rt_hypotf_snf(f.re, f.im);
          fs_re = f.re / g2;
          fs_im = f.im / g2;
        } else {
          scale = 5.49755814E+11F * f.re;
          f2s = 5.49755814E+11F * f.im;
          g2 = rt_hypotf_snf(scale, f2s);
          fs_re = scale / g2;
          fs_im = f2s / g2;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
        r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
      }
    } else {
      f2s = (float)sqrt((double)(1.0F + g2 / scale));
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0F / f2s;
      g2 += scale;
      scale = r->re / g2;
      f2s = r->im / g2;
      sn->re = scale * gs_re - f2s * -gs_im;
      sn->im = scale * -gs_im + f2s * gs_re;
      if (rescaledir > 0) {
        for (rescaledir = 1; rescaledir <= count; rescaledir++) {
          r->re *= 5.49755814E+11F;
          r->im *= 5.49755814E+11F;
        }
      } else {
        if (rescaledir < 0) {
          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.8189894E-12F;
            r->im *= 1.8189894E-12F;
          }
        }
      }
    }
  }
}

//
// File trailer for xzlartg.cpp
//
// [EOF]
//
