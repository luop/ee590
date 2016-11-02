#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string>
#include "exception.hh"

class Object {

public:

  Object();
  Object ( const Object &m ) {}
  virtual ~Object();

  virtual Object * clone() = 0;
  virtual std::string stringify() = 0;

  virtual Object * get() { throw json_exception("Undefined getter: get()"); }
  virtual Object * get(std::string s) const { throw json_exception("Undefined getter: get(s)"); }
  virtual Object * get(int i) { throw json_exception("Undefined getter: get(i)"); }

};

#define DEBUG(_msg_) { std::cout << _msg_ << std::endl; }

#endif
