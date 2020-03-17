#include <iostream>
#include "functions.h"
#include <string>
using namespace std;

int main() {
//  for (int i = 0; i < 13; i++)
  cout << validUsername("a222") << endl;
  cout << validUsername("12a") << endl;
  cout << validUsername("aaas3") << endl;
  cout << validUsername("aaa22") << endl;
  cout << validUsername("2aa") << endl;
  cout << validUsername("aa3") << endl;
  cout << validUsername("a1") << endl;


  return 0;
}
