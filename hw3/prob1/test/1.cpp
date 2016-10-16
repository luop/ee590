#include "test.h"
#include "fraction.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  // Constructor Tests

  // Test 1:
  // Check 3/4 is positive with numerator equals to 3, denominator equals to 4
  fraction A(3, 4);
  ASSERT ( A.numer() == 3 && A.denom() == 4 && A.posi() );
  cout << A << endl;

  fraction B = 5;
  ASSERT ( B.numer() == 5 && B.denom() == 1 && B.posi() );
  cout << B << endl;

  SUCCEED;

}
