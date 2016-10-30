#include "object.hh"

class String : public Object {

public:

  String(std::string s);

  // Destructors
  ~String();

  String ( const String &s ) { value = s.value; }

  String * clone() { return new String(*this); }
  inline void set(std::string s) { value = s; }
  std::string stringify();

private:

  std::string value;

};
