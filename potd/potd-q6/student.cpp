// Your code here! :)

#include "student.h"

using namespace potd;

Student::Student() // default constructor
{
  name_ = "Timmy";
  grade_ = 7;
}

void Student::set_name(std::string n)
{
  name_ = n;
}

void Student::set_grade(int g)
{
  grade_ = g;
}

std::string Student::get_name()
{
  return name_;
}

int Student::get_grade()
{
  return grade_;
}
