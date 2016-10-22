#include "test.hh"
#include "matrix.hh"
#include "ComplexNum.h"

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;

  matrix<ComplexNum> Q(2,2);
  ComplexNum Q1(1, 1);
  ComplexNum Q2(-1, 1);
  ComplexNum Q3(1, -1);
  ComplexNum Q4(-1, -1);

  Q.set(0,0,Q1); Q.set(0,1,Q2);
  Q.set(1,0,Q3); Q.set(1,1,Q4);

  // Test cout operator
  std::cout << "The matrix Q is:" << std::endl;
  std::cout << Q << std::endl;

  // Test operations

  /*Test 1
    calculate determinant of matrix Q
    verify determinant is not 0
  */
  ComplexNum d = Q.det();
  ComplexNum zero = 0;
  ASSERT(d != zero);

  /*Test 2
    calculate the inverse of matrix Q
    multiply Q with its inverse
    verify their multiplication equals to identity matrix
  */
  matrix<ComplexNum> P = Q.inverse();
  matrix<ComplexNum> R = Q.mult(P);
  matrix<ComplexNum> I = matrix<ComplexNum>::identity(2);
  ASSERT(R == I);

  /*Test 3
    calculate Q plus Q
    calculate Q * 2
    verify the results are equal
  */
  matrix<ComplexNum> M = Q.add(Q);
  Q.scale(2);
  ASSERT(M == Q);

  matrix<ComplexNum> A(3,3);

  /*Test 4
    add two incompatible sizes matrix
    verify the exception is caught
  */
  try {
     matrix<ComplexNum> D(3,4), E(4,5);
     A = D.add(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

  /*Test 5
    multiply two matrix with num_rows != num_columns
    verify the exception is caught
  */
  try {
     matrix<ComplexNum> D(3,4), E(3,5);
     A = D.mult(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

  return 0;

}
