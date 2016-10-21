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
  //ComplexNum A(3, 4);
  //ASSERT ( A.realNum() == 3 && A.imagNum() == 4 );
  Q.set(0,0,Q1); Q.set(0,1,Q2);
  Q.set(1,0,Q3); Q.set(1,1,Q4);

  std::cout << Q;

  matrix<ComplexNum> M = Q.add(Q);
  std::cout << M << std::endl;

  matrix<ComplexNum> N = Q.mult(Q);
  std::cout << N << std::endl;

  ComplexNum d = Q.det();
  std::cout << d << std::endl;

  matrix<ComplexNum> P = Q.inverse();
  std::cout << P << std::endl;

  matrix<ComplexNum> R = Q.mult(P);
  std::cout << R << std::endl;

  Q.scale(3);
  std::cout << Q << std::endl;

}
