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

  fraction B = A.power(2);
  ASSERT ( B.numer() == 9 && B.denom() == 16 && B.posi() );
  //cout << A;

  fraction C = A.power(-2);;
  ASSERT ( C.numer() == 16 && C.denom() == 9 && C.posi() );
  //cout << B;

  //fraction C;
  fraction D(-3, 4);
  fraction E = D.power(2);
  ASSERT ( E.numer() == 9 && E.denom() == 16 && E.posi() );
  //cout << -B;

  fraction F = D.power(-2);;
  ASSERT ( F.numer() == 16 && F.denom() == 9 && F.posi() );

  fraction G = D.power(3);
  ASSERT ( G.numer() == 27 && G.denom() == 64 && !G.posi() );

  fraction H = D.power(-3);
  ASSERT ( H.numer() == 64 && H.denom() == 27 && !H.posi() );

  fraction I = A.power(0);
  ASSERT ( I.numer() == 1 && I.denom() == 1 && I.posi() );

  fraction J = D.power(0);
  ASSERT ( J.numer() == 1 && J.denom() == 1 && J.posi() );

  SUCCEED;

}
