// Your code here
#ifndef FOOD_H_
#define FOOD_H_

#include <string>
#include <iostream>

using namespace std;

class Food
{
public:
  Food();
  string get_name();
  void set_name(string n);
  int get_quantity();
  void set_quantity(int q);

private:
  string name_;
  int quantity_;
};

#endif
