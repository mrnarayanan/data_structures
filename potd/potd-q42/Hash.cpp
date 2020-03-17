#include <vector>
#include <string>
#include <iostream>
#include "Hash.h"

unsigned long HashTable::bernstein(std::string str, int M)
{
    unsigned long b_hash = 5381;
    for (int i = 0; i < (int)str.length(); ++i)
    {
        b_hash = b_hash * 33 + str[i];
    }
    return b_hash % M;
};

HashTable::HashTable(int M)        // M is the size of the hash table
{
    table = new std::vector<std::string>[M];
    this->M = M;
};

void HashTable::printKeys()        // Function to print all keys in the hash table
{
    for(int i = 0; i < M; ++i)
        for (auto it = table[i].begin(); it!= table[i].end(); ++it)
            std::cout<<*it<<std::endl;
};

void HashTable::insert(std::string str)         //Inserts str into the hash table; must handle duplicates!
{
    // your code here
    if (contains(str))
      return;
    else
    {
      unsigned long index = bernstein(str, M);
      table[index].push_back(str);
    }
};

bool HashTable::contains(std::string str)       //Checks if the hash table contains str
{
    // your code here
    unsigned long index = bernstein(str, M);
    for (unsigned i = 0; i < table[index].size(); i++)
    {
      if (table[index][i] == str)
        return true;
    }
    return false;
};
