// your code here
#ifndef BAR_H_
#define BAR_H_

#include "Foo.h"
#include <string>

using namespace std;

namespace potd
{
  class Bar
  {
  public:
    Bar(string);
    Bar(const Bar &);
    Bar & operator=(const Bar &);
    ~Bar();
    string get_name();
  private:
    Foo * f_;
  };

}




#endif
