/* Your code here! */
#include <string>
#include <iostream>
#include "hello.h"

using namespace std;

string hello()
{
  string name = "Murugan";
  int age = 19;
  string output = "Hello world! My name is " + name + " and I am " + to_string(age) + " years old.";
  return output;
}
