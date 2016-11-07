#include "number.hh"

Number::Number(double d) : value(d) {
}

Number::Number(double d, double e) : value(d), exponents(e) {
}

std::string Number::stringify() {
  std::string s;
  if ( value - (int) value == 0 ) {
    s = std::to_string((int)value);
  } else {
    s = std::to_string(value);
  }

  if ( exponents != 0 ){
      s = s + "E" + std::to_string((int)exponents);
  }
  return s;
}
