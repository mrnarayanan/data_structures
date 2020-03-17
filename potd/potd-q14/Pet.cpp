// Pet.cpp
#include "Pet.h"

using namespace std;

void Pet::setName(string n)
{
  name_ = n;
}

void Pet::setOwnerName(string on)
{
  owner_name_ = on;
}

string Pet::getName()
{
  return name_;
}

string Pet::getOwnerName()
{
  return owner_name_;
}

string Pet::print()
{
    return "My name is " + name_;
}

Pet::Pet() : Animal("cat", "fish")
{
  name_ = "Fluffy";
  owner_name_ = "Cinda";
}

Pet::Pet(string a, string f, string n, string on) : Animal(a, f)
{
  name_ = n;
  owner_name_ = on;
}
