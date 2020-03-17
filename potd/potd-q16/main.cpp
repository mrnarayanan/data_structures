#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  Node first;
  first.data_ = 100;
  first.next_ = NULL;
  head = &first;
  cout << stringList(head) << endl;

  // Test 3: A list with more than one node
  Node second, third;
  second.data_ = 200;
  third.data_ = 300;
  first.next_ = &second;
  second.next_ = &third;
  third.next_ = NULL;
  cout << stringList(head) << endl;

  return 0;
}
