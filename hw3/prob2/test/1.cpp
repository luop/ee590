#include "test.h"
#include "ComplexNum.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  // Constructor Tests

  // Test 1:
  // Check 3/4 is positive with numerator equals to 3, denominator equals to 4
  cout << endl;

  ComplexNum A(3, 4);
  ASSERT ( A.realNum() == 3 && A.imagNum() == 4 );
  cout << A;

  ComplexNum B = 5;
  ASSERT ( B.realNum() == 5 && B.imagNum() == 0 );
  cout << B;

  ComplexNum C(-3, -4);
  ASSERT ( C.realNum() == -3 && C.imagNum() == -4 );
  cout << C;

  ComplexNum D(-3, 4);
  ASSERT ( D.realNum() == -3 && D.imagNum() == 4 );
  cout << D;

  ComplexNum E(3, -4);
  ASSERT ( E.realNum() == 3 && E.imagNum() == -4 );
  cout << E;

  ComplexNum F(0, 4);
  ASSERT ( F.realNum() == 0 && F.imagNum() == 4 );
  cout << F;

  ComplexNum G(0, -4);
  ASSERT ( G.realNum() == 0 && G.imagNum() == -4 );
  cout << G;

  ComplexNum H(0, 0);
  ASSERT ( H.realNum() == 0 && H.imagNum() == 0 );
  cout << H;

  ComplexNum I = -5;
  ASSERT ( I.realNum() == -5 && H.imagNum() == 0 );
  cout << I;

  SUCCEED;

}
