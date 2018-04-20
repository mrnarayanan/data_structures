/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num)
{
  for (int i = 0; i < num; i++)
    arr_.push_back(-1);
}

int DisjointSets::find(int i)
{
  if (arr_[i] < 0)
    return i;
  else
    return find(arr_[i]);
}

void DisjointSets::setunion(int a, int b)
{
  // find roots
  int root1 = find(a);
  int root2 = find(b);

  int newSize = arr_[root1] + arr_[root2];

  // if arr_[root1] is less than (more negative), it is larger, so smaller gets unioned to it
  if (arr_[root1] <= arr_[root2])
  {
    arr_[root2] = root1;
    arr_[root1] = newSize;
  }
  else
  {
    arr_[root1] = root2;
    arr_[root2] = newSize;
  }
}

int DisjointSets::size(int elem)
{
  int root = find(elem);
  return arr_[root];
}
