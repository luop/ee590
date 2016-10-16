#include <iostream>
#include <cmath>
#include "fraction.h"

fraction::fraction (int n, int d) : numerator(abs(n)), denominator(abs(d)){

  if ( d == 0 ) {
    throw fraction_exception("Denominator cannot be 0");
  }

  if ( (n > 0 && d > 0) || (n < 0 && d < 0) || ( n == 0) ){
    positive = true;
  }else{
    positive = false;
  }

}

fraction::~fraction() {

}

fraction::fraction ( const fraction &f ) {

  numerator = f.numerator;
  denominator = f.denominator;
  positive = f.positive;

}

fraction &fraction::operator=(const fraction &other) {

  numerator = other.numerator;
  denominator = other.denominator;
  positive = other.positive;

  return *this;

}

std::ostream& operator<<(std::ostream& os, const fraction &f) {

  if (f.posi()){
    os << f.numer() << "/" << f.denom() << std::endl;
  }else{
    os << "- (" << f.numer() << "/" << f.denom() << ")" << std::endl;
  }

  return os;

}
