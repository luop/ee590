#include "test.h"
#include "ComplexNum.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  // Constructor Tests

  // Test 1:
  // Check 3/4 is positive with numerator equals to 3, denominator equals to 4
  ComplexNum A(3, 4);

  ComplexNum B = A.power(2);

  ComplexNum C = A.mult(A);

  cout << B;

  cout << C;

  ComplexNum D(-7, 24);

  ComplexNum E = A.power(3);
  cout << E;

  ComplexNum F = D.mult(A);
  cout << F;

  SUCCEED;

}
