#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;
  matrix<int> Q(2,2);

  Q.set(0,0,1); Q.set(0,1,0);
  Q.set(1,0,1); Q.set(1,1,1);

  // Test cout operator
  std::cout << "The matrix Q is:" << std::endl;
  std::cout << Q << std::endl;

  // Test operations

  /*Test 1
    calculate determinant of matrix Q
    verify determinant is not 0
  */
  int d = Q.det();
  ASSERT(d != 0);

  /*Test 2
    calculate the inverse of matrix Q
    multiply Q with its inverse
    verify their multiplication equals to identity matrix
  */
  matrix<int> P = Q.inverse();
  matrix<int> R = Q.mult(P);
  matrix<int> I = matrix<int>::identity(2);
  ASSERT(R == I);

  /*Test 3
    calculate Q plus Q
    calculate Q * 2
    verify the results are equal
  */
  matrix<int> M = Q.add(Q);
  Q.scale(2);
  ASSERT(M == Q);

  matrix<int> A(3,3);

  /*Test 4
    add two incompatible sizes matrix
    verify the exception is caught
  */
  try {
     matrix<int> D(3,4), E(4,5);
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
     matrix<int> D(3,4), E(3,5);
     A = D.mult(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

  return 0;

}
