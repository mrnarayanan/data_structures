#include "Heap.h"
#include <iostream>
#include <algorithm>

void Heap::_percolateDown(int hole)
{
  // your code here
  while ( (unsigned) 2*hole < _data.size())
  {
    unsigned child1 = 2*hole; // left child
    unsigned child2 = 2*hole+1; // right child 

    unsigned largerChild = child1;
    if (child2 < _data.size()
        && _data[child2] > _data[child1])
      largerChild = child2;
    if (_data[largerChild] > _data[hole])
      {
        std::swap(_data[hole], _data[largerChild]);
        hole = largerChild;
      }
    else
      hole = _data.size();
  }
}

int Heap::size() const {
    return _data.size();
}

void Heap::enQueue(const int &x){
    _data.push_back(x);
    int hole = _data.size() - 1;
    for(; hole > 1 && x > _data[hole/2]; hole /= 2){
        _data[hole] = _data[hole/2];
    }
    _data[hole] = x;
}

int Heap::deQueue(){
    int minItem = _data[1];
    _data[1] = _data[_data.size() - 1];
    _data.pop_back();
    _percolateDown(1);
    return minItem;
}

void Heap::printQueue(){
    std::cout << "Current Priority Queue is: ";
    for(auto i = _data.begin() + 1; i != _data.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> & Heap::getData() {
    return _data;
}
