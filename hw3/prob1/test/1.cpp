#include "test.h"
#include "fraction.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  cout << endl;

  // Constructor Tests
  // COUT TEST

  /*Test 1
    create a fraction 3/4
    verify numerator is 3, denominator is 4, and it is positive
    verify cout prints out the fraction correctly
  */
  fraction A(3, 4);
  ASSERT ( A.numer() == 3 && A.denom() == 4 && A.posi() );
  cout << A;

  /*Test 2
    Overload the '=' operation and write, fraction x = 5, for whole numbers.
    verify numerator is 5, denominator is 1, and it is positive
    verify cout prints out the fraction correctly
  */
  fraction B = 5;
  ASSERT ( B.numer() == 5 && B.denom() == 1 && B.posi() );
  cout << B;

  /*Test 3
    Overload '-', the unary minus operator to negate a fraction.
    verify numerator is 3, denominator is 4, and it is negative
    verify cout prints out the fraction correctly
  */
  fraction C = -A;
  ASSERT ( C.numer() == 3 && C.denom() == 4 && !C.posi() );
  cout << C;

  /*Test 4
    create a fraction -(3/4).
    verify numerator is 3, denominator is 4, and it is negative
    verify cout prints out the fraction correctly
  */
  fraction D(-3, 4);
  ASSERT ( D.numer() == 3 && D.denom() == 4 && !D.posi() );
  cout << D;

  /*Test 5
    create a fraction -(3/4).
    verify numerator is 3, denominator is 4, and it is negative
    verify cout prints out the fraction correctly
  */
  fraction E(3, -4);
  ASSERT ( E.numer() == 3 && E.denom() == 4 && !E.posi() );
  cout << E;

  /*Test 6
    create a fraction with denominator equals to 0.
    verify the exception is caught
  */
  try {
     fraction F(3, 0);
     FAIL;
  } catch ( fraction_exception &e ) {
    SUCCEED;
  }

  return 0;

}
