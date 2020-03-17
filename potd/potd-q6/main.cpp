// Your code here! :)

#include "student.h"
#include "q6.h"
#include <iostream>

int main()
{
  potd::Student* child = new potd::Student();
  std::cout << child->get_name() << " is in grade " << child->get_grade() << "." << std::endl;
  graduate(*child);
  std::cout << child->get_name() << " is in grade " << child->get_grade() << "." << std::endl;
  delete child;
  return 0;
}
