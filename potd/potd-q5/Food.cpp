// Your code here

#include "Food.h"

using namespace std;

Food::Food() // default constructor
{
  name_ = "apple(s)";
  quantity_ = 1;
}

string Food::get_name()
{
  return name_;
}

int Food::get_quantity()
{
  return quantity_;
}

void Food::set_name(string n)
{
  name_ = n;
}

void Food::set_quantity(int q)
{
  quantity_ = q;
}
