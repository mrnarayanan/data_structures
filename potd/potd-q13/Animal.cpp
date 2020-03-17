// Animal.cpp
#include "Animal.h"

using namespace std;

string Animal::getType()
{
  return type_;
}

string Animal::getFood()
{
  return food_;
}

void Animal::setFood(string f)
{
  food_ = f;
}
void Animal::setType(string t)
{
  type_ = t;
}

string Animal::print()
{
  string out = "I am a " + getType() + ".";
  return out;
}

Animal::Animal()
{
  type_ = "cat";
  food_ = "fish";
}

Animal::Animal(string t, string f)
{
  type_ = t;
  food_ = f;
}
