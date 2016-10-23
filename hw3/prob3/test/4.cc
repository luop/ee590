#include "test.hh"
#include "matrix.hh"
#include "fraction.h"

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;
  matrix<fraction> Q(2,2);
  fraction Q1(-2, 3);
  fraction Q2(1, 3);
  fraction Q3(1, 2);
  fraction Q4(-1, 6);

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
  fraction d = Q.det();
  fraction zero = 0;
  ASSERT(d != zero);

  /*Test 2
    calculate the inverse of matrix Q
    multiply Q with its inverse
    verify their multiplication equals to identity matrix
  */
  matrix<fraction> P = Q.inverse();
  matrix<fraction> R = Q.mult(P);
  matrix<fraction> I = matrix<fraction>::identity(2);
  ASSERT(R == I);

  /*Test 3
    calculate Q plus Q
    calculate Q * 2
    verify the results are equal
  */
  matrix<fraction> M = Q.add(Q);
  Q.scale(2);
  ASSERT(M == Q);

  /*Test 4
    calculate Q * Q
    calculate Q ^ 2
    verify the results are equal
  */
  matrix<fraction> N = Q.mult(Q);
  matrix<fraction> O = Q.power(2);
  ASSERT(N == O);

  matrix<fraction> A(3,3);

  /*Test 5
    add two incompatible sizes matrix
    verify the exception is caught
  */
  try {
     matrix<fraction> D(3,4), E(4,5);
     A = D.add(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

  /*Test 6
    multiply two matrix with num_rows != num_columns
    verify the exception is caught
  */
  try {
     matrix<fraction> D(3,4), E(3,5);
     A = D.mult(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

  return 0;

}
