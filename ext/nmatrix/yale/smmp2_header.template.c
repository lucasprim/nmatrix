/////////////////////////////////////////////////////////////////////
// = NMatrix
//
// A linear algebra library for scientific computation in Ruby.
// NMatrix is part of SciRuby.
//
// NMatrix was originally inspired by and derived from NArray, by
// Masahiro Tanaka: http://narray.rubyforge.org
//
// == Copyright Information
//
// SciRuby is Copyright (c) 2010 - 2012, Ruby Science Foundation
// NMatrix is Copyright (c) 2012, Ruby Science Foundation
//
// Please see LICENSE.txt for additional copyright notices.
//
// == Contributing
//
// By contributing source code to SciRuby, you agree to be bound by
// our Contributor Agreement:
//
// * https://github.com/SciRuby/sciruby/wiki/Contributor-Agreement
//
// == smmp2.c
//
/* ======================================================================= *
 * Sparse Matrix Multiplication Package                                    *
 * Randolph E. Bank and Craig C. Douglas                                   *
 * na.bank@na-net.ornl.gov and na.cdouglas@na-net.ornl.gov                 *
 * ======================================================================= */
// This was originally derived from the above paper, but the algorithm they
// give, in Fortran, uses 1-based indexing, and I simply could not make it
// work. So I went back to where I found the link to that paper -- SciPy's
// CSR type -- and looked at what they had done:
//
// https://github.com/scipy/scipy/blob/master/scipy/sparse/sparsetools/csr.h
//
// However, the SciPy version does not use the "new Yale" format, but rather
// "old Yale." Thus, some modification was necessary -- reincorporating some
// stuff from the original Bank & Douglas paper.
//
//
// DO NOT MODIFY smmp2.c DIRECTLY, as it is autogenerated by generator.rb.

#include <stdio.h>
#include "nmatrix.h"
