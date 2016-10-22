#include "test.h"
#include "fraction.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  cout << endl;

  // power operation Tests
  fraction A(3, 4);

  /*Test 1
    Raise 3/4 to power of 2
    verify numerator is 9, denominator is 16, and it is positive
  */
  fraction B = A.power(2);
  ASSERT ( B.numer() == 9 && B.denom() == 16 && B.posi() );

  /*Test 2
    Raise 3/4 to power of -2
    verify numerator is 16, denominator is 9, and it is positive
  */
  fraction C = A.power(-2);;
  ASSERT ( C.numer() == 16 && C.denom() == 9 && C.posi() );

  /*Test 3
    Raise -(3/4) to power of -2
    verify numerator is 9, denominator is 16, and it is positive
  */
  fraction D(-3, 4);
  fraction E = D.power(2);
  ASSERT ( E.numer() == 9 && E.denom() == 16 && E.posi() );

  /*Test 4
    Raise -(3/4) to power of -2
    verify numerator is 16, denominator is 9, and it is positive
  */
  fraction F = D.power(-2);;
  ASSERT ( F.numer() == 16 && F.denom() == 9 && F.posi() );

  /*Test 5
    Raise -(3/4) to power of 3
    verify numerator is 27, denominator is 64, and it is negative
  */
  fraction G = D.power(3);
  ASSERT ( G.numer() == 27 && G.denom() == 64 && !G.posi() );

  /*Test 6
    Raise -(3/4) to power of -3
    verify numerator is 64, denominator is 27, and it is negative
  */
  fraction H = D.power(-3);
  ASSERT ( H.numer() == 64 && H.denom() == 27 && !H.posi() );

  /*Test 7
    Raise 3/4 to power of 0
    verify numerator is 1, denominator is 1, and it is positive
  */
  fraction I = A.power(0);
  ASSERT ( I.numer() == 1 && I.denom() == 1 && I.posi() );

  /*Test 8
    Raise -(3/4) to power of 0
    verify numerator is 1, denominator is 1, and it is positive
  */
  fraction J = D.power(0);
  ASSERT ( J.numer() == 1 && J.denom() == 1 && J.posi() );

  /*Test 9
    Raise -(0/3) to negavtive power
    verify the exception is caught
  */
  try {
     fraction K(0, 3);
     K.power(-2);
     FAIL;
  } catch ( fraction_exception &e ) {
    SUCCEED;
  }

  return 0;

}
