#include "list.h"

int main() {
  List<int> mylist, list2;
  mylist.insertBack(1);
  mylist.insertBack(3);
  mylist.insertBack(2);
  mylist.insertBack(10);
  mylist.insertBack(6);
  mylist.insertBack(9);
  mylist.insertBack(7);
  mylist.insertBack(4);

  list2.insertBack(8);
  list2.insertBack(9);
  list2.insertBack(16);
  list2.insertBack(18);

  std::cout << std::endl;
  mylist.print(std::cout);
  std::cout << std::endl;
  mylist.sort();
  mylist.print(std::cout);
  std::cout << std::endl;


  return 0;
}
