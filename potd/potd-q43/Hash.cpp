#include <vector>
#include "Hash.h"

void doubleHashInput(std::vector<int> &v, int elem)
{
	//your code here
  int size = v.size();
  int index = firstHash(elem, size);
  if (v[index] == -1)
  {
    v[index] = elem;
    return;
  }
  int step = secondHash(elem);
  while (v[index] != -1)
  {
    index = (index + step) % size;
  }
  v[index] = elem;
  return;
}

//make a hash function called firstHash
int firstHash(int elem, int len)
{
  return (elem * 4) % len;
}

//make a second function called secondHash
int secondHash(int elem)
{
  return 3 - (elem % 3);
}
