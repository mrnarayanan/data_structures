#include "list.h"

int main() {
  List<int> mylist, list2;
  mylist.insertBack(1);
  mylist.insertBack(2);
  mylist.insertBack(5);
  mylist.insertBack(7);
  mylist.insertBack(12);
  mylist.insertBack(15);
  mylist.insertBack(17);
  mylist.insertBack(19);

  list2.insertBack(8);
  list2.insertBack(9);
  list2.insertBack(16);
  list2.insertBack(18);

  std::cout << std::endl;
  mylist.print(std::cout);
  std::cout << std::endl;
  mylist.mergeWith(list2);
  mylist.print(std::cout);
  std::cout << std::endl;


  return 0;
}
