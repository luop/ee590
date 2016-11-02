#include "object.hh"

class Null : public Object {

public:

  Null() {}

  // Destructors
  ~Null() {}

  Null * clone() { return new Null(*this); }
  std::string stringify() { return std::string("null"); }

};
