#include "test.h"
#include "ComplexNum.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  cout << endl;

  //Operation and relation Tests
  ComplexNum A(3, 4);

  /*Test 1
    The conjugate of A is 3-4i
    verify real is 3, imaginary is -4
  */
  ComplexNum B = A.conjugate();
  ASSERT ( B.realNum() == 3 && B.imagNum() == -4 );

  /*Test 2
    A + B is 6
    verify real is 6, imaginary is 0
  */
  ComplexNum C = A + B;
  ASSERT ( C.realNum() == 6 && C.imagNum() == 0 );

  /*Test 3
    A - B is 8i
    verify real is 0, imaginary is 8i
  */
  ComplexNum D = A - B;
  ASSERT ( D.realNum() == 0 && D.imagNum() == 8 );

  /*Test 4
    A * B is -7+24i
    verify real is -7, imaginary is 24
  */
  ComplexNum E = A.mult(A);
  ASSERT ( E.realNum() == -7 && E.imagNum() == 24 );

  /*Test 5
    Raise A to power of 2
    verify real is -7, imaginary is 24
  */
  ComplexNum F = A.power(2);
  ASSERT ( F.realNum() == -7 && F.imagNum() == 24 );

  /*Test 6
    verify E != A is true
  */
  ASSERT ( E != A );

  /*Test 7
    verify E == F is true, A * A equals to A^2
  */
  ASSERT ( E == F );

  /*Test 8
    verify E != F is false, A * A equals to A^2
  */
  ASSERT ( ! (E != F) );

  /*Test 9
    Raise A to power of 3
    verify A * A * A equals to A^3
  */
  ComplexNum G = A.power(3);
  ComplexNum H = E.mult(A);
  ASSERT ( G == H );

  /*Test 10
    A / B is -(7/25) + (24/25)i
    verify real is close to -(7/25), imaginary is (24/25)
  */
  ComplexNum I = A / B;
  double precision = 0.0001;
  ASSERT(( ( I.realNum() - precision ) < (-7.0/25.0) ) && ( ( ( I.realNum() + precision ) > (-7.0/25.0) ) ));
  ASSERT(( ( I.imagNum() - precision ) < (24.0/25.0) ) && ( ( ( I.imagNum() + precision ) > (24.0/25.0) ) ));


  /*Test 11
    The magnitude of A
    verify it equals to 5
  */
  double m = A.magnitude();
  ASSERT( m == 5);

  /*Test 12
    The angle of A and B
    verify they are close to 53.1301 degree
  */
  double a1 = A.angle();
  ASSERT(( ( a1 - precision ) < 53.1301 ) && ( ( ( a1 + precision ) > 53.1301 ) ));

  double a2 = B.angle();
  ASSERT(( ( a2 - precision ) < -53.1301 ) && ( ( ( a2 + precision ) > -53.1301 ) ));

  /*Test 13
    The angle D
    verify they equals to 90 degree
  */
  double a3 = D.angle();
  ASSERT( a3 == 90 );

  /*Test 14
    The angle of the conjugate of D
    verify they equals to -90 degree
  */
  ComplexNum J = D.conjugate();
  double a4 = J.angle();
  ASSERT( a4 == -90 );

  /*Test 15
    The angle of the conjugate of E
    verify it is close to -106.26 degree
  */
  ComplexNum K = E.conjugate();
  double a5 = K.angle();
  ASSERT(( ( a5 - 0.01 ) < -106.26 ) && ( ( ( a5 + 0.01 ) > -106.26 ) ));

  /*Test 16
    e^(A)
    verify real is close to -13.1288 and imaginary is close to -15.2008
  */
  ComplexNum L = A.expPower();
  ASSERT(( ( L.realNum() - precision ) < -13.1288 ) && ( ( ( L.realNum() + precision ) > -13.1288 ) ));
  ASSERT(( ( L.imagNum() - precision ) < -15.2008 ) && ( ( ( L.imagNum() + precision ) > -15.2008 ) ));

  /*Test 17
    A^0
    verify it equals to 1
  */
  ComplexNum O = A.power(0);
  ASSERT ( O.realNum() == 1 && O.imagNum() == 0 );

  /*Test 18
    Angle of 0 is Indeterminate
    verify exception is caught
  */
  try {
     ComplexNum M(0, 0);
     M.angle();
     FAIL;
  } catch ( ComplexNum_exception &e ) {
    SUCCEED;
  }

  /*Test 19
    Divide 0 should fail
    verify exception is caught
  */
  try {
     ComplexNum N(0, 0);
     A / N;
     FAIL;
  } catch ( ComplexNum_exception &e ) {
    SUCCEED;
  }

  return 0;

}
