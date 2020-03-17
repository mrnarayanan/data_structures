// Your code here! :)

#include "q6.h"

void graduate(potd::Student & kid)
{
  int grade = kid.get_grade();
  grade++;
  kid.set_grade(grade);
}
