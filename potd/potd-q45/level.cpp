#include "level.h"

using namespace std;

vector<int> lastLevel(MinHeap & heap)
{
    // Your code here
    vector<int> v;
    if (heap.elements.empty())
      return v;
    unsigned index = 1;
    unsigned size = heap.elements.size();
    unsigned levels = floor(log2(size));
    for (unsigned i = 0; i < levels; i++)
      index *= 2;
    for (unsigned i = index; i < size; i++)
      v.push_back(heap.elements[i]);
    return v; 
}
