// Pet.h
#ifndef PET_H_
#define PET_H_

#include "Animal.h"

using namespace std;

class Pet : public Animal
{
public:
  void setName(string);
  void setOwnerName(string);
  string getName();
  string getOwnerName();
  string print();
  Pet();
  Pet(string a, string f, string n, string on);
private:
  string name_;
  string owner_name_;
};

#endif
