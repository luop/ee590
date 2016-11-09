#include "object.hh"

class Number : public Object {

public:

  Number(double d);
  Number(double d, double e, bool b);
  Number ( const Number &number ) { value = number.value; exponents = number.exponents; is_integer = number.is_integer;}

  Number * clone() { return new Number(*this); }
  inline void set(double d) { value = d; }
  inline double get_val() { return value; }
  inline void set_exp(double e) { exponents = e; }
  inline double get_exp() { return exponents; }
  inline bool is_int(void) { return is_integer; }
  std::string stringify();

private:

  double value;
  double exponents = 0;
  bool is_integer;

};
