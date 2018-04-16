/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    vector<string> words;
    ifstream wordsFile(filename);
    string wd;
    if (wordsFile.is_open())
    {
        /* Reads a line from `wordsFile` into `word` until the file ends. */
        while (getline(wordsFile, wd))
        {
          words.push_back(wd);
        }
    }

    for (unsigned i = 0; i < words.size(); i++)
    {
      string ww = words[i];
      auto lookup = dict.find(ww);
      if (lookup == dict.end()) // new word
      {
        dict[ww].push_back(ww);
        dict[ww].pop_back();
        for (auto & key_val : dict)
        {
          if (hash(ww) == hash(key_val.first))
            key_val.second.push_back(ww);
        }
      }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for (unsigned i = 0; i < words.size(); i++)
    {
      string ww = words[i];
      auto lookup = dict.find(ww);
      if (lookup == dict.end()) // new word
      {
        dict[ww].push_back(ww);
        dict[ww].pop_back();
        for (auto & key_val : dict)
        {
          if (hash(ww) == hash(key_val.first))
            key_val.second.push_back(ww);
        }
      }
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    vector<string> ret;
    auto lookup = dict.find(word);
    if (lookup == dict.end()) //  word not found
    {
      return ret;
    }
    else
    {
      ret = lookup->second;
    } 

    return ret;
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    return vector<vector<string>>();
}

int AnagramDict::hash(string word)
{
  int sum = 0;
  for (unsigned i = 0; i < word.size(); i++)
    sum += word[i];
  sum *= word.size();
  return sum;
}
