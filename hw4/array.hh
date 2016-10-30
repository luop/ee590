#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "object.hh"

class Array : public Object {

public:

  Array();

  // Destructors
  ~Array();

  Array ( const Array &array );
  Array * clone() { return new Array(*this); }

  void set(int index, Object &object);
  Object * get(int index);
  std::string stringify();

private:

  int max;
  Object ** values;

};

#endif
