#include "object.hh"

class Boolean : public Object {

public:

  Boolean(bool b);

  // Destructors
  ~Boolean();

  Boolean ( const Boolean &b ) { value = b.value; }

  Boolean * clone() { return new Boolean(*this); }
  inline void set(bool b) { value = b; }
  std::string stringify();

private:

  bool value;

};
