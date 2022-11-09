#ifndef MAD_VEC_H
#define MAD_VEC_H

/*
 o-----------------------------------------------------------------------------o
 |
 | Vector module interface
 |
 | Methodical Accelerator Design - Copyright (c) 2016+
 | Support: http://cern.ch/mad  - mad at cern.ch
 | Authors: L. Deniau, laurent.deniau at cern.ch
 | Contrib: -
 |
 o-----------------------------------------------------------------------------o
 | You can redistribute this file and/or modify it under the terms of the GNU
 | General Public License GPLv3 (or later), as published by the Free Software
 | Foundation. This file is distributed in the hope that it will be useful, but
 | WITHOUT ANY WARRANTY OF ANY KIND. See http://gnu.org/licenses for details.
 o-----------------------------------------------------------------------------o

  Purpose:
  - wrappers around functions of real and complex vectors for LuaJIT

 o-----------------------------------------------------------------------------o
 */

#include "mad_def.h"

// --- interface --------------------------------------------------------------o

void   mad_vec_fill   (       num_t x                          ,  num_t  r[], ssz_t n); //  num -> vec
void   mad_vec_roll   (       num_t x[],                                      ssz_t n, int nroll);
void   mad_vec_copy   (const  num_t x[],                          num_t  r[], ssz_t n); //  vec -> vec
void   mad_vec_copyv  (const  num_t x[],                         cnum_t  r[], ssz_t n); //  vec ->cvec
void   mad_vec_minmax (const  num_t x[],        log_t absf     ,  idx_t r[2], ssz_t n); // MinMax(vec)
num_t  mad_vec_eval   (const  num_t x[],        num_t x0,                     ssz_t n); // Horner scheme
num_t  mad_vec_sum    (const  num_t x[],                                      ssz_t n); // Sum(vec)
num_t  mad_vec_ksum   (const  num_t x[],                                      ssz_t n); // Sum(vec) (Kahan)
num_t  mad_vec_mean   (const  num_t x[],                                      ssz_t n); // Mean(vec)
num_t  mad_vec_var    (const  num_t x[],                                      ssz_t n); // Var(vec)
void   mad_vec_center (const  num_t x[],                          num_t  r[], ssz_t n); // vec -> vec-<vec>
num_t  mad_vec_norm   (const  num_t x[]                                     , ssz_t n); // |vec|
num_t  mad_vec_dist   (const  num_t x[], const  num_t y[]                   , ssz_t n); // |vec -  vec|
num_t  mad_vec_distv  (const  num_t x[], const cnum_t y[]                   , ssz_t n); // |vec - cvec|
num_t  mad_vec_dot    (const  num_t x[], const  num_t y[]                   , ssz_t n); // <vec ,  vec>
num_t  mad_vec_kdot   (const  num_t x[], const  num_t y[]                   , ssz_t n); // <vec ,  vec> (Kahan)
void   mad_vec_cplx   (const  num_t x[], const  num_t im[],      cnum_t  r[], ssz_t n); // vr,vi->cvec
void   mad_vec_abs    (const  num_t x[],                          num_t  r[], ssz_t n); // |vec_i|
void   mad_vec_add    (const  num_t x[], const  num_t y[]      ,  num_t  r[], ssz_t n); //  vec +  vec
void   mad_vec_addn   (const  num_t x[],        num_t y        ,  num_t  r[], ssz_t n); //  vec +  num
void   mad_vec_addc   (const  num_t x[],       cnum_t y        , cnum_t  r[], ssz_t n); //  vec +  cpx
void   mad_vec_addc_r (const  num_t x[], num_t y_re, num_t y_im, cnum_t  r[], ssz_t n); //  vec +  cpx
void   mad_vec_sub    (const  num_t x[], const  num_t y[]      ,  num_t  r[], ssz_t n); //  vec -  vec
void   mad_vec_subv   (const  num_t x[], const cnum_t y[]      , cnum_t  r[], ssz_t n); //  vec - cvec
void   mad_vec_subn   (const  num_t y[],        num_t x        ,  num_t  r[], ssz_t n); //  num -  vec
void   mad_vec_subc   (const  num_t y[],       cnum_t x        , cnum_t  r[], ssz_t n); //  cpx -  vec
void   mad_vec_subc_r (const  num_t y[], num_t x_re, num_t x_im, cnum_t  r[], ssz_t n); //  cpx -  vec
void   mad_vec_mul    (const  num_t x[], const  num_t y[]      ,  num_t  r[], ssz_t n); //  vec *  vec
void   mad_vec_muln   (const  num_t x[],        num_t y        ,  num_t  r[], ssz_t n); //  vec *  num
void   mad_vec_mulc   (const  num_t x[],       cnum_t y        , cnum_t  r[], ssz_t n); //  vec *  cpx
void   mad_vec_mulc_r (const  num_t x[], num_t y_re, num_t y_im, cnum_t  r[], ssz_t n); //  vec *  cpx
void   mad_vec_div    (const  num_t x[], const  num_t y[]      ,  num_t  r[], ssz_t n); //  vec /  vec
void   mad_vec_divv   (const  num_t x[], const cnum_t y[]      , cnum_t  r[], ssz_t n); //  vec / cvec
void   mad_vec_divn   (const  num_t y[],        num_t x        ,  num_t  r[], ssz_t n); //  num /  vec
void   mad_vec_divc   (const  num_t y[],       cnum_t x        , cnum_t  r[], ssz_t n); //  cpx /  vec
void   mad_vec_divc_r (const  num_t y[], num_t x_re, num_t x_im, cnum_t  r[], ssz_t n); //  cpx /  vec
void   mad_vec_fft    (const  num_t x[],                         cnum_t  r[], ssz_t n);          //  vec ->cvec
void   mad_vec_rfft   (const  num_t x[],                         cnum_t  r[], ssz_t n);          //  vec ->cvec
void   mad_vec_nfft   (const  num_t x[], const  num_t x_node[] , cnum_t  r[], ssz_t n, ssz_t nr);
void   mad_vec_kadd   (int k, const num_t a[], const num_t *x[],  num_t  r[], ssz_t n); //  sum_k ax

void   mad_cvec_fill  (      cnum_t x                          , cnum_t  r[], ssz_t n); //  cnum ->cvec
void   mad_cvec_fill_r(       num_t x_re,       num_t x_im     , cnum_t  r[], ssz_t n); //  cnum ->cvec
void   mad_cvec_roll  (      cnum_t x[],                                      ssz_t n, int nroll);
void   mad_cvec_copy  (const cnum_t x[],                         cnum_t  r[], ssz_t n); //  cvec ->cvec
void   mad_cvec_minmax(const cnum_t x[],                          idx_t r[2], ssz_t n); // MinMax(vec)
cnum_t mad_cvec_eval  (const cnum_t x[],       cnum_t x0,                     ssz_t n); // Horner scheme
void   mad_cvec_eval_r(const cnum_t x[],num_t x0_re,num_t x0_im, cnum_t *r  , ssz_t n);
cnum_t mad_cvec_sum   (const cnum_t x[],                                      ssz_t n); // Sum(vec)
void   mad_cvec_sum_r (const cnum_t x[],                         cnum_t *r  , ssz_t n); // Sum(vec)
cnum_t mad_cvec_ksum  (const cnum_t x[],                                      ssz_t n); // Sum(vec)
void   mad_cvec_ksum_r(const cnum_t x[],                         cnum_t *r  , ssz_t n); // Sum(vec)
cnum_t mad_cvec_mean  (const cnum_t x[],                                      ssz_t n); // Mean(vec)
void   mad_cvec_mean_r(const cnum_t x[],                         cnum_t *r  , ssz_t n); // Mean(vec)
cnum_t mad_cvec_var   (const cnum_t x[],                                      ssz_t n); // Var(vec)
void   mad_cvec_var_r (const cnum_t x[],                         cnum_t *r  , ssz_t n); // Var(vec)
void   mad_cvec_center(const cnum_t x[],                         cnum_t  r[], ssz_t n); //  cvec ->cvec-<cvec>
num_t  mad_cvec_norm  (const cnum_t x[]                                     , ssz_t n); // |cvec|
num_t  mad_cvec_dist  (const cnum_t x[], const cnum_t y[]                   , ssz_t n); // |cvec - cvec|
num_t  mad_cvec_distv (const cnum_t x[], const  num_t y[]                   , ssz_t n); // |cvec -  vec|
cnum_t mad_cvec_dot   (const cnum_t x[], const cnum_t y[]                   , ssz_t n); // <cvec , cvec>
void   mad_cvec_dot_r (const cnum_t x[], const cnum_t y[]      , cnum_t *r  , ssz_t n); // <cvec , cvec>
cnum_t mad_cvec_dotv  (const cnum_t x[], const  num_t y[]                   , ssz_t n); // <cvec ,  vec>
void   mad_cvec_dotv_r(const cnum_t x[], const  num_t y[]      , cnum_t *r  , ssz_t n); // <cvec ,  vec>
cnum_t mad_cvec_kdot  (const cnum_t x[], const cnum_t y[]                   , ssz_t n); // <cvec , cvec>
void   mad_cvec_kdot_r(const cnum_t x[], const cnum_t y[]      , cnum_t *r  , ssz_t n); // <cvec , cvec>
cnum_t mad_cvec_kdotv (const cnum_t x[], const  num_t y[]                   , ssz_t n); // <cvec ,  vec>
void   mad_cvec_kdotv_r(const cnum_t x[],const  num_t y[]      , cnum_t *r  , ssz_t n); // <cvec ,  vec>
void   mad_cvec_reim  (const cnum_t x[],        num_t re[]     ,  num_t ri[], ssz_t n); //  cvec->vr,vi
void   mad_cvec_conj  (const cnum_t x[],                         cnum_t  r[], ssz_t n); //  cvec ->cvec*
void   mad_cvec_abs   (const cnum_t x[],                          num_t  r[], ssz_t n); // |cvec_i|
void   mad_cvec_add   (const cnum_t x[], const cnum_t y[]      , cnum_t  r[], ssz_t n); //  cvec + cvec
void   mad_cvec_addv  (const cnum_t x[], const  num_t y[]      , cnum_t  r[], ssz_t n); //  cvec +  vec
void   mad_cvec_addn  (const cnum_t x[],        num_t y        , cnum_t  r[], ssz_t n); //  cvec +  num
void   mad_cvec_addc  (const cnum_t x[],       cnum_t y        , cnum_t  r[], ssz_t n); //  cvec +  cpx
void   mad_cvec_addc_r(const cnum_t x[], num_t y_re, num_t y_im, cnum_t  r[], ssz_t n); //  cvec +  cpx
void   mad_cvec_sub   (const cnum_t x[], const cnum_t y[]      , cnum_t  r[], ssz_t n); //  cvec - cvec
void   mad_cvec_subv  (const cnum_t x[], const  num_t y[]      , cnum_t  r[], ssz_t n); //  cvec -  vec
void   mad_cvec_subn  (const cnum_t y[],        num_t x        , cnum_t  r[], ssz_t n); //  num  - cvec
void   mad_cvec_subc  (const cnum_t y[],       cnum_t x        , cnum_t  r[], ssz_t n); //  cpx  - cvec
void   mad_cvec_subc_r(const cnum_t y[], num_t x_re, num_t x_im, cnum_t  r[], ssz_t n); //  cpx  - cvec
void   mad_cvec_mul   (const cnum_t x[], const cnum_t y[]      , cnum_t  r[], ssz_t n); //  cvec * cvec
void   mad_cvec_mulv  (const cnum_t x[], const  num_t y[]      , cnum_t  r[], ssz_t n); //  cvec *  vec
void   mad_cvec_muln  (const cnum_t x[],        num_t y        , cnum_t  r[], ssz_t n); //  cvec *  num
void   mad_cvec_mulc  (const cnum_t x[],       cnum_t y        , cnum_t  r[], ssz_t n); //  cvec *  cpx
void   mad_cvec_mulc_r(const cnum_t x[], num_t y_re, num_t y_im, cnum_t  r[], ssz_t n); //  cvec *  cpx
void   mad_cvec_div   (const cnum_t x[], const cnum_t y[]      , cnum_t  r[], ssz_t n); //  cvec / cvec
void   mad_cvec_divv  (const cnum_t x[], const  num_t y[]      , cnum_t  r[], ssz_t n); //  cvec /  vec
void   mad_cvec_divn  (const cnum_t y[],        num_t x        , cnum_t  r[], ssz_t n); //  num  / cvec
void   mad_cvec_divc  (const cnum_t y[],       cnum_t x        , cnum_t  r[], ssz_t n); //  cpx  / cvec
void   mad_cvec_divc_r(const cnum_t y[], num_t x_re, num_t x_im, cnum_t  r[], ssz_t n); //  cpx  / cvec
void   mad_cvec_fft   (const cnum_t x[],                         cnum_t  r[], ssz_t n);          //  cvec ->cvec
void   mad_cvec_nfft  (const cnum_t x[], const num_t x_node[]  , cnum_t  r[], ssz_t n, ssz_t nr);
void   mad_cvec_ifft  (const cnum_t x[],                         cnum_t  r[], ssz_t n);          //  cvec ->cvec
void   mad_cvec_irfft (const cnum_t x[],                          num_t  r[], ssz_t n);          //  cvec -> vec
void   mad_cvec_infft (const cnum_t x[], const num_t r_node[]  , cnum_t  r[], ssz_t n, ssz_t nx);
void   mad_cvec_kadd  (int k, const cnum_t a[],const cnum_t *x[],cnum_t  r[], ssz_t n); //  sum_k ax

void   mad_ivec_fill  (       idx_t x                          ,  idx_t  r[], ssz_t n); //  idx ->ivec
void   mad_ivec_roll  (       idx_t x[],                                      ssz_t n, int nroll);
void   mad_ivec_copy  (const  idx_t x[],                          idx_t  r[], ssz_t n); // ivec ->ivec
void   mad_ivec_minmax(const  idx_t x[],        log_t absf     ,  idx_t r[2], ssz_t n); // MinMax(ivec)
void   mad_ivec_add   (const  idx_t x[], const  idx_t y[]      ,  idx_t  r[], ssz_t n); // ivec + ivec
void   mad_ivec_addn  (const  idx_t x[],        idx_t y        ,  idx_t  r[], ssz_t n); // ivec +  idx
void   mad_ivec_sub   (const  idx_t x[], const  idx_t y[]      ,  idx_t  r[], ssz_t n); // ivec - ivec
void   mad_ivec_subn  (const  idx_t y[],        idx_t x        ,  idx_t  r[], ssz_t n); //  idx - ivec
void   mad_ivec_mul   (const  idx_t x[], const  idx_t y[]      ,  idx_t  r[], ssz_t n); // ivec * ivec
void   mad_ivec_muln  (const  idx_t x[],        idx_t y        ,  idx_t  r[], ssz_t n); // ivec *  num
void   mad_ivec_divn  (const  idx_t x[],        idx_t y        ,  idx_t  r[], ssz_t n); // ivec /  num
void   mad_ivec_modn  (const  idx_t x[],        idx_t y        ,  idx_t  r[], ssz_t n); // ivec %  num

// global fft cleanup
void   mad_fft_cleanup (void);

// ----------------------------------------------------------------------------o

#endif // MAD_VEC_H
