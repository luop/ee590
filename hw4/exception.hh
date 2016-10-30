#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <iostream>
#include <stdexcept>

class json_exception : public std::runtime_error {
public:
  json_exception(const char msg[]) : std::runtime_error(msg) { }
};

#endif
