#ifndef BASE_H_
#define BASE_H_

#include <string>

using namespace std;

class Base
{
public:
  string foo();
  virtual string bar();
  virtual ~Base();
};

#endif
