// your code here

#include "Bar.h"

using namespace potd;
using namespace std;

Bar::Bar(string str)
{
  this->f_ = new Foo(str);
}

Bar::Bar(const Bar & that)
{
  this->f_ = that.f_;
}

Bar & Bar::operator=(const Bar & that)
{
  this->f_ = that.f_;
  return *this;
}

Bar::~Bar()
{
  delete this->f_;
}

string Bar::get_name()
{
  return f_->get_name();
}
