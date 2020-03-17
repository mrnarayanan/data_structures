#ifndef PATTERN_H
#define PATTERN_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool wordPattern(string pattern, string str);
int finder(vector<string> v, string word, unsigned start, unsigned end);

#endif
