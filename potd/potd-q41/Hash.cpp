#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
  std::vector<int>* array = new std::vector<int>(M);	// Hint: This comes in handy
	std::vector<std::string> perms;
	int permutation_count = 0;
	float goodness = 0;
	do {
		if (permutation_count == M) break;
		// Code for computing the hash and updating the array
		perms.push_back(str);
		permutation_count++;
	} while(std::next_permutation(str.begin(), str.end()));

	//Code for determining goodness
	int colls = countCollisions(M, perms, array);
	goodness = (float) colls / M;
	return goodness;
}

int countCollisions (int M, std::vector<std::string> inputs, std::vector<int> * contains)
{
	int collisions = 0;
	// Your Code Here
  for (int i = 0; i < M; i++)
  {
    (*contains)[i] = 0;
  }
  for (unsigned x = 0; x < inputs.size(); x++)
  {
    int res = bernstein(inputs[x], M);
    if ((*contains)[res] == 0)
      (*contains)[res] = 1;
    else
      collisions++;
  }
	return collisions;
}
