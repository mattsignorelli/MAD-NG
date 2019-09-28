/*
 o-----------------------------------------------------------------------------o
 |
 | Monomial module implementation
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "mad_mono.h"

// --- implementation ---------------------------------------------------------o

ssz_t
mad_mono_str (ssz_t n, ord_t a[n], str_t s)
{
  assert(a && s);
  ssz_t i = 0;
  for (; i < n && s[i]; ++i) a[i] = s[i] - (s[i] > '9' ? 'A'-10 : '0');
  return i;
}

void
mad_mono_fill (ssz_t n, ord_t a[n], ord_t v)
{
  assert(a);
  memset(a, v, MAX(0,n));
}

void
mad_mono_copy (ssz_t n, const ord_t a[n], ord_t r[n])
{
  assert(a && r);
  if (a != r) memcpy(r, a, MAX(0,n));
}

void
mad_mono_rcopy (ssz_t n, const ord_t a[n], ord_t r[n])
{
  assert(a && r);
  ord_t t;
  if (a != r)
    for (idx_t i=0; i < n; ++i) r[i] = a[n-1-i];
  else
    for (idx_t i=0; i < n/2; ++i)
      t = r[i], r[i] = r[n-1-i], r[n-1-i] = t;
}

ord_t
mad_mono_min (ssz_t n, const ord_t a[n])
{
  assert(a);
  ord_t mo = ~0;
  for (idx_t i=0; i < n; ++i) if (a[i] < mo) mo = a[i];
  return mo;
}

ord_t
mad_mono_max (ssz_t n, const ord_t a[n])
{
  assert(a);
  ord_t mo = 0;
  for (idx_t i=0; i < n; ++i) if (a[i] > mo) mo = a[i];
  return mo;
}

int
mad_mono_ord (ssz_t n, const ord_t a[n])
{
  assert(a);
  int s = 0;
  for (idx_t i=0; i < n; ++i) s += a[i];
  return s;
}

int
mad_mono_equ (ssz_t n, const ord_t a[n], const ord_t b[n])
{
  assert(a && b);
  return !memcmp(a, b, MAX(0,n));
}

int
mad_mono_cmp (ssz_t n, const ord_t a[n], const ord_t b[n])
{
  assert(a && b);
  return memcmp(a, b, MAX(0,n));
}

int
mad_mono_rcmp (ssz_t n, const ord_t a[n], const ord_t b[n])
{
  assert(a && b);
  for (idx_t i=n-1; i >= 0; --i)
    if (a[i] != b[i]) return (int)a[i] - b[i];
  return 0;
}

void
mad_mono_add (ssz_t n, const ord_t a[n], const ord_t b[n], ord_t r[n])
{
  assert(a && b && r);
  for (idx_t i=0; i < n; ++i) r[i] = a[i] + b[i];
}

void
mad_mono_sub (ssz_t n, const ord_t a[n], const ord_t b[n], ord_t r[n])
{
  assert(a && b && r);
  for (idx_t i=0; i < n; ++i) r[i] = a[i] - b[i];
}

void
mad_mono_cat (ssz_t n, const ord_t a[n],
              ssz_t m, const ord_t b[m], ord_t r[n+m])
{
  mad_mono_copy(n, a, r  );
  mad_mono_copy(m, b, r+n);
}

void
mad_mono_print (ssz_t n, const ord_t m[n])
{
  assert(m);

  printf("[ ");
  for (idx_t i=0; i < n; ++i)
    printf("%d ", (int)m[i]);
  printf("]");
}

// --- end --------------------------------------------------------------------o
