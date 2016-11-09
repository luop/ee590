#include "number.hh"

Number::Number(double d) : value(d) {
}

Number::Number(double d, double e, bool b) : value(d), exponents(e), is_integer(b) {
}

std::string Number::stringify() {
  std::string s;
  if ( is_integer ) {
    s = std::to_string((int)value);
  } else {
    s = std::to_string(value);
  }

  if ( exponents != 0 ){
      s = s + "E" + std::to_string((int)exponents);
  }
  return s;
}
