#include <iostream>
#include "ComplexNum.h"

ComplexNum::ComplexNum (double r, double i) : real(r), imaginary(i){

}

ComplexNum::~ComplexNum() {

}

ComplexNum::ComplexNum ( const ComplexNum &c ) {

  real = c.real;
  imaginary = c.imaginary;

}

ComplexNum &ComplexNum::operator=(const ComplexNum &other) {

  real = other.real;
  imaginary = other.imaginary;

  return *this;

}

std::ostream& operator<<(std::ostream& os, const ComplexNum &c) {

  double r = c.realNum();
  double i = c.imagNum();

  if ( r == 0 && i == 0){
    os << 0 << std::endl;
  }else if ( r == 0 && i != 0){
    os << i << "i" << std::endl;
  }else if ( r != 0 && i == 0){
    os << r << std::endl;
  }else{
    if ( i > 0 ) {
      os << r << "+" << i << "i" << std::endl;
    }else{
      os << r << i << "i" << std::endl;
    }
  }

  return os;
}
