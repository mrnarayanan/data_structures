// Your code here! :)
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

namespace potd
{
  class Student
  {
  public:
    Student();
    std::string get_name();
    int get_grade();
    void set_name(std::string);
    void set_grade(int);
  private:
    std::string name_;
    int grade_;
  };
}

#endif
