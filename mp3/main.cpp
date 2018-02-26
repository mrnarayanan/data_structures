#include "list.h"

int main() {
  List<int> mylist;
  mylist.insertBack(1);
  mylist.insertBack(2);
  mylist.insertBack(3);
  mylist.insertBack(4);
  mylist.insertBack(5);
  mylist.insertBack(6);
  mylist.insertBack(7);
  mylist.insertBack(8);
  mylist.reverse();
  std::cout << std::endl;
  mylist.reverse();
  mylist.print(std::cout);
  std::cout << std::endl;
  std::cout << "Head: " << mylist.head_->data << std::endl;
  std::cout << "Tail: " << mylist.tail_->data << std::endl;
  mylist.reverseNth(4);
  mylist.print(std::cout);
  std::cout << std::endl;
  std::cout << "Head: " << mylist.head_->data << std::endl;
  std::cout << "Tail: " << mylist.tail_->data << std::endl;
  return 0;
}
