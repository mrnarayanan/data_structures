#include "Hash.h"

using namespace std;

unsigned long bernstein(string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for (unsigned i = 0; i < str.length(); i++)
 	{
   	b_hash = b_hash*33 + (int) str[i];
 	}
	return b_hash % M;
}

string reverse(string str)
{
  string output = "";
	//Your code here
	for (int i = str.length()-1; i >= 0; i--)
	 {
	   output.push_back(str[i]);
	 }
	return output;
}
