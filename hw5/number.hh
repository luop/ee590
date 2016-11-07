#include "object.hh"

class Number : public Object {

public:

  Number(double d);
  Number(double d, double e);
  Number ( const Number &number ) { value = number.value; exponents = number.exponents;}

  Number * clone() { return new Number(*this); }
  inline void set(double d) { value = d; }
  inline double get_val() { return value; }
  inline void set_exp(double e) { exponents = e; }
  inline double get_exp() { return exponents; }
  std::string stringify();

private:

  double value;
  double exponents = 0;

};
