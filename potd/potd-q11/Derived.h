#ifndef DERIVED_H_
#define DERIVED_H_

#include <string>
#include "Base.h"

using namespace std;

class Derived : public Base
{
public:
  string foo();
  string bar();
  ~Derived();
};

#endif
