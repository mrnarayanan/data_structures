#include "Pattern.h"

using namespace std;

bool wordPattern(string pattern, string str)
{
    //write your code here
    if (pattern.length() == 0 || str.length() == 0)
      return false;
    vector<string> words;
    unsigned start = 0, len = 0;
    string sub;
    string space = " ";
    for (unsigned i = 0; i < str.length(); i++)
    {
      string comp = str.substr(i, 1);
      if (comp.compare(space) == 0) // space
      {
        sub = str.substr(start, len);
        words.push_back(sub);
        start = i + 1;
        len = 0;
      }
      else if (i + 1 >= str.length()) // reached end of string
      {
        sub = str.substr(start);
        words.push_back(sub);
      }
      else
        len++;
    }

    // used for testing
    // for (unsigned i = 0; i < words.size(); i++)
    //   cout << words[i] << endl;
    // return true;
    vector<int> patt;
    patt.resize(words.size());
    int letter = 'a';
    int idx;
    for (unsigned i = 0; i < patt.size(); i++)
      patt[i] = 0;
    for (unsigned i = 0; i < words.size(); i++)
    {
      if (i == 0)
      {
        patt[i] = letter;
        continue;
      }
      idx = finder(words, words[i], 0, i-1);
  //    cout << "i= " << i << "\tidx= " << idx << endl;
      if (idx >= 0) // word already exists, so repeated letter
      {
        patt[i] = patt[idx];
      }
      else
      {
        letter++;
        patt[i] = letter;
      }
    }

    for (unsigned i = 0; i < patt.size(); i++)
    {
    //  cout << (char) patt[i] << endl;
      if (patt[i] != pattern[i])
        return false;
    }
    return true;
}

int finder(vector<string> v, string word, unsigned start, unsigned end)
{
  for (unsigned i = start; i <= end; i++)
  {
    if (word.compare(v[i]) == 0)
      return i;
  }
  return -1;
}
