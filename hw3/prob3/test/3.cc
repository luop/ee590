#include <iostream>
#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;
  matrix<bool> Q(2,2);

  Q.set(0,0,true); Q.set(0,1,false);
  Q.set(1,0,false); Q.set(1,1,true);

  // Test cout operator
  std::cout << "The matrix Q is:" << std::endl;
  std::cout << std::boolalpha;
  std::cout << std::endl << Q << std::endl;

  // Test operations

  /*Test 1
    calculate determinant of matrix Q
    verify determinant is not 0
  */
  bool d = Q.det();
  bool zero = 0;
  ASSERT(d != zero);

  /*Test 2
    calculate the inverse of matrix Q
    multiply Q with its inverse
    verify their multiplication equals to identity matrix
  */
  matrix<bool> P = Q.inverse();
  matrix<bool> R = Q.mult(P);
  matrix<bool> I = matrix<bool>::identity(2);
  ASSERT(R == I);

  /*Test 3
    calculate Q plus Q
    calculate Q * 2
    verify the results are equal
  */
  matrix<bool> M = Q.add(Q);
  Q.scale(2);
  ASSERT(M == Q);

  /*Test 4
    calculate Q * Q
    calculate Q ^ 2
    verify the results are equal
  */
  matrix<bool> N = Q.mult(Q);
  matrix<bool> O = Q.power(2);
  ASSERT(N == O);

  matrix<bool> A(3,3);

  /*Test 5
    add two incompatible sizes matrix
    verify the exception is caught
  */
  try {
     matrix<bool> D(3,4), E(4,5);
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
     matrix<bool> D(3,4), E(3,5);
     A = D.mult(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

  return 0;

}
