#include "test.h"
#include "fraction.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  // Constructor Tests

  // Test 1:
  // Check 3/4 is positive with numerator equals to 3, denominator equals to 4
  cout << endl;

  fraction A(3, 4);
  ASSERT ( A.numer() == 3 && A.denom() == 4 && A.posi() );
  //cout << A;

  fraction B = 5;
  ASSERT ( B.numer() == 5 && B.denom() == 1 && B.posi() );
  //cout << B;

  //fraction C;
  fraction C = -A;
  ASSERT ( C.numer() == 3 && C.denom() == 4 && !C.posi() );
  //cout << -B;

  fraction D(-3, 4);
  ASSERT ( D.numer() == 3 && D.denom() == 4 && !D.posi() );

  fraction E(3, -4);
  ASSERT ( E.numer() == 3 && E.denom() == 4 && !E.posi() );

  SUCCEED;

}
