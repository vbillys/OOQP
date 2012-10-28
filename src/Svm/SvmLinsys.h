/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#ifndef SVMLINSYS_H
#define SVMLINSYS_H

#include "LinearSystem.h"
#include "SimpleVectorHandle.h"

class Data;
class Variables;
class Residuals;
class DoubleLinearSolver;

/**
 * @ingroup Svm
 *
 * LinearSystem class for Svm.
 *
 */

#include "DenseSymMatrixHandle.h"

class SvmData;
  
class SvmLinsys : public LinearSystem
{
public:
  SvmLinsys(SvmData * prob);
  ~SvmLinsys();
  void factor(Data *prob, Variables *vars);

  void solve(Data *prob, Variables *vars, Residuals *rhs,
	     Variables *step);

private:
  /** stores Cholesky factor of the mtrix (X^T DX) that is calculated
      in factor */
  DenseSymMatrixHandle mL;
  
  /** */
  SimpleVectorHandle mYd;
  
  /** */
  double mGamma;

  /** pointer to dense symmetric positive definite solver used to
      factor the compressed matrix */
  DoubleLinearSolver *solver;

  /** stores the complicated diagonal matrix that arises during the
   *  block elimination */
  SimpleVectorHandle mDinv;
};
  

#endif
