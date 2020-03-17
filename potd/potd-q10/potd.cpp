// your code here!
#include "potd.h"
#include <math.h>


int * potd::raise(int * arr)
{
  int i = 0;
  while (arr[i] != -1)
    i++;

  int last = i - 1;
  int size = i + 1;

  int * out = new int[size];

  for (int x = 0; x < last; x++)
  {
    out[x] = pow(arr[x], arr[x+1]);
  }
  out[last] = arr[last];
  out[i] = arr[i];

  return out;

}
