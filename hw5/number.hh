#include "object.hh"

class Number : public Object {

public:

  Number(double d);
  Number(double d, double e);
  Number ( const Number &number ) { value = number.value; exponents = number.exponents;}

  Number * clone() { return new Number(*this); }
  inline void set(double d) { value = d; }
  std::string stringify();

private:

  double value;
  double exponents = 0;

};
