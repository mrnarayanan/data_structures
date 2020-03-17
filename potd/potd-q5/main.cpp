// your code here

#include "Food.h"
#include "q5.h"

using namespace std;

int main()
{
  Food * yum = new Food();
  cout << "You have " << yum->get_quantity() << " " << yum->get_name() << ".\n";
  increase_quantity(yum);
  cout << "You have " << yum->get_quantity() << " " << yum->get_name() << ".\n";

  delete yum;
  return 0;
}
