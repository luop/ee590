#include "test.hh"
#include "matrix.hh"
#include "fraction.h"

int main ( int argc, char * argv[] ) {

  matrix<fraction> Q(2,2);
  fraction Q1(-2, 3);
  fraction Q2(1, 3);
  fraction Q3(1, 2);
  fraction Q4(-1, 6);

  Q.set(0,0,Q1); Q.set(0,1,Q2);
  Q.set(1,0,Q3); Q.set(1,1,Q4);

  std::cout << std::endl;
  std::cout << Q << std::endl;

  matrix<fraction> M = Q.add(Q);
  std::cout << M << std::endl;

  matrix<fraction> N = Q.mult(Q);
  std::cout << N << std::endl;

  fraction d = Q.det();
  std::cout << d << std::endl;

  matrix<fraction> P = Q.inverse();
  std::cout << P << std::endl;

  matrix<fraction> R = Q.mult(P);
  std::cout << R << std::endl;

  Q.scale(3);
  std::cout << Q << std::endl;

  return 0;

}
