#include <vector>
#include <string>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int sum = 0;
   for (unsigned i = 0; i < s.length(); i++)
   {
     sum += (int) s[i];
   }
   return sum % M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
  int contains[M];
  for (int i = 0; i < M; i++)
  {
    contains[i] = 0;
  }
  for (unsigned x = 0; x < inputs.size(); x++)
  {
    int res = hashFunction(inputs[x], M);
    if (contains[res] == 0)
      contains[res] = 1;
    else
      collisions++;
  }
	return collisions;
}
