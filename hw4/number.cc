#include "number.hh"

Number::Number(double d) : value(d) {
}

// Destructors
Number::~Number(){}

std::string Number::stringify() {
  return std::to_string(value);
}
