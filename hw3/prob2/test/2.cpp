#include "test.h"
#include "ComplexNum.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  // Constructor Tests

  // Test 1:
  // Check 3/4 is positive with numerator equals to 3, denominator equals to 4
  ComplexNum A(3, 4);

  ComplexNum B = A.conjugate();
  ASSERT ( B.realNum() == 3 && B.imagNum() == -4 );

  ComplexNum C = A + B;
  ASSERT ( C.realNum() == 6 && C.imagNum() == 0 );

  ComplexNum D = A - B;
  ASSERT ( D.realNum() == 0 && D.imagNum() == 8 );

  ComplexNum E = A.mult(A);
  ASSERT ( E.realNum() == -7 && E.imagNum() == 24 );

  ComplexNum F = A.power(2);
  ASSERT ( F.realNum() == -7 && F.imagNum() == 24 );

  ASSERT ( E != A );
  ASSERT ( E == F );
  ASSERT ( ! (E != F) );

  ComplexNum G = A.power(3);
  ComplexNum H = E.mult(A);
  ASSERT ( G == H );

  ComplexNum I = A / B;

  double precision = 0.0001;
  ASSERT(( ( I.realNum() - precision ) < (-7.0/25.0) ) && ( ( ( I.realNum() + precision ) > (-7.0/25.0) ) ));
  ASSERT(( ( I.imagNum() - precision ) < (24.0/25.0) ) && ( ( ( I.imagNum() + precision ) > (24.0/25.0) ) ));

  double m = A.magnitude();
  ASSERT( m == 5);

  double a1 = A.angle();
  ASSERT(( ( a1 - precision ) < 53.1301 ) && ( ( ( a1 + precision ) > 53.1301 ) ));

  double a2 = B.angle();
  ASSERT(( ( a2 - precision ) < -53.1301 ) && ( ( ( a2 + precision ) > -53.1301 ) ));

  double a3 = D.angle();
  ASSERT( a3 == 90 );

  ComplexNum J = D.conjugate();
  double a4 = J.angle();
  ASSERT( a4 == -90 );

  ComplexNum K = E.conjugate();
  double a5 = K.angle();
  ASSERT(( ( a5 - 0.01 ) < -106.26 ) && ( ( ( a5 + 0.01 ) > -106.26 ) ));

  ComplexNum L = A.expPower();
  ASSERT(( ( L.realNum() - precision ) < -13.1288 ) && ( ( ( L.realNum() + precision ) > -13.1288 ) ));
  ASSERT(( ( L.imagNum() - precision ) < -15.2008 ) && ( ( ( L.imagNum() + precision ) > -15.2008 ) ));

  SUCCEED;

}
