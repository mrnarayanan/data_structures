// your code here

#include "q5.h"

using namespace std;

void increase_quantity(Food * mummum)
{
  int num = mummum->get_quantity();
  num++;
  mummum->set_quantity(num);
}
