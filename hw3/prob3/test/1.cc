#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;
  matrix<double> A(3,3);

  matrix<double> Q(2,2);

  Q.set(0,0,1); Q.set(0,1,2);
  Q.set(1,0,3); Q.set(1,1,4);


  matrix<double> P = Q.inverse();
  std::cout << P << std::endl;

  matrix<double> R = Q.mult(P);
  std::cout << R << std::endl;

  try {
     matrix<double> D(3,4), E(4,5);
     A = D.add(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

}
