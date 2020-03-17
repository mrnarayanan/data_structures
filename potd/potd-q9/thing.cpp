// Your code here!
#include "thing.h"

using namespace potd;
using namespace std;

Thing::Thing(int x)
{
  props_ct_ = 0;
  props_max_ = x;
  properties_ = new string[x];
  values_ = new string[x];
  for (int i = 0; i < x; i++)
  {
    properties_[i] = ""; // initializing to empty strings
    values_[i] = "";
  }
}

Thing::Thing(const Thing & that)
{
  _copy(that);
}

Thing & Thing::operator=(const Thing & that)
{
  if (this != &that)
  {
    _destroy();
    _copy(that);
  }
  return *this;
}

Thing::~Thing()
{
  _destroy();
}

int Thing::set_property(string x, string y)
{
  for (int i = 0; i < props_max_; i++)
  {
    if (properties_[i].compare(x) == 0 || properties_[i].compare("") == 0)
    {
      properties_[i] = x;
      values_[i] = y;
      return i;
    }
  }
  return -1;
}

string Thing::get_property(string x)
{
  for (int i = 0; i < props_max_; i++)
  {
    if (properties_[i].compare(x) == 0)
      return values_[i];
  }
  return "";
}

void Thing::_copy(const Thing & that)
{
  props_ct_ = that.props_ct_;
  props_max_ = that.props_max_;
  properties_ = new string[props_max_];
  values_ = new string[props_max_];
  for (int i = 0; i < props_max_; i++)
  {
    properties_[i] = that.properties_[i];
    values_[i] = that.values_[i];
  }
}

void Thing::_destroy()
{
  delete[] properties_;
  delete[] values_;
}
