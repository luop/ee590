#include "test.h"
#include "ComplexNum.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  cout << endl;

  // Constructor Tests
  // COUT TEST

  /*Test 1
    create a complex number 3+4i
    verify real is 3, imaginary is 4
    verify cout prints out the fraction correctly
  */
  ComplexNum A(3, 4);
  ASSERT ( A.realNum() == 3 && A.imagNum() == 4 );
  cout << A;

  /*Test 2
    Overload the '=' operation and write, complex number x = 5
    verify real is 5, imaginary is 0
    verify cout prints out the fraction correctly
  */
  ComplexNum B = 5;
  ASSERT ( B.realNum() == 5 && B.imagNum() == 0 );
  cout << B;

  /*Test 3
    create a complex number -3-4i
    verify real is -3, imaginary is -4
    verify cout prints out the fraction correctly
  */
  ComplexNum C(-3, -4);
  ASSERT ( C.realNum() == -3 && C.imagNum() == -4 );
  cout << C;

  /*Test 4
    create a complex number -3+4i
    verify real is -3, imaginary is 4
    verify cout prints out the fraction correctly
  */
  ComplexNum D(-3, 4);
  ASSERT ( D.realNum() == -3 && D.imagNum() == 4 );
  cout << D;

  /*Test 5
    create a complex number -3+4i
    verify real is 3, imaginary is -4
    verify cout prints out the fraction correctly
  */
  ComplexNum E(3, -4);
  ASSERT ( E.realNum() == 3 && E.imagNum() == -4 );
  cout << E;

  /*Test 6
    create a complex number 4i
    verify real is 0, imaginary is 4
    verify cout prints out the fraction correctly
  */
  ComplexNum F(0, 4);
  ASSERT ( F.realNum() == 0 && F.imagNum() == 4 );
  cout << F;

  /*Test 7
    create a complex number -4i
    verify real is 0, imaginary is -4
    verify cout prints out the fraction correctly
  */
  ComplexNum G(0, -4);
  ASSERT ( G.realNum() == 0 && G.imagNum() == -4 );
  cout << G;

  /*Test 8
    create a complex number 0
    verify real is 0, imaginary is 0
    verify cout prints out the fraction correctly
  */
  ComplexNum H(0, 0);
  ASSERT ( H.realNum() == 0 && H.imagNum() == 0 );
  cout << H;

  /*Test 9
    Unary negation of -3-4i
    verify real is 3, imaginary is 4
    verify cout prints out the fraction correctly
  */
  ComplexNum I = -C;
  ASSERT ( I.realNum() == 3 && I.imagNum() == 4 );
  cout << I;

  SUCCEED;

}
