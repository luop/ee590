#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  matrix<int> Q(2,2);

  Q.set(0,0,1); Q.set(0,1,2);
  Q.set(1,0,3); Q.set(1,1,4);

  std::cout << std::endl;
  matrix<int> M = Q.add(Q);
  std::cout << M << std::endl;

  matrix<int> N = Q.mult(Q);
  std::cout << N << std::endl;

  Q.scale(3);
  std::cout << Q << std::endl;

  matrix<int> Q1 = Q.minnor( 0, 0 );
  matrix<int> Q2 = Q.minnor( 0, 1 );
  matrix<int> Q3 = Q.minnor( 1, 0 );
  matrix<int> Q4 = Q.minnor( 1, 1 );

  int d = Q.det();
  std::cout << d << std::endl;

  return 0;

}
