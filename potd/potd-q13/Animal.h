// Animal.h
#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

using namespace std;

class Animal
{
private:
  string type_;
protected:
  string food_;
public:
  string getType();
  string getFood();
  void setType(string);
  void setFood(string);
  virtual string print();
  Animal();
  Animal(string, string);
};


#endif
