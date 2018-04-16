/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>
#include <iostream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;
    /* Your code goes here! */
    vector<string> words;

    ifstream wordsFile(word_list_fname);
    string wd;
    if (wordsFile.is_open())
    {
        /* Reads a line from `wordsFile` into `word` until the file ends. */
        while (getline(wordsFile, wd))
        {
          words.push_back(wd);
        }
    }

    string itself, first, second, sub;
    bool result1, result2;
    for (unsigned i = 0; i < words.size(); i++)
    {
      itself = words[i];
      if (itself.size() < 3)
        continue;
      first = itself.substr(1);
      sub = itself.substr(2);
      second = itself.substr(0,1);
      second += sub;
  //    std::cout << itself << "\t" << first << "\t" << second << std::endl;
      result1 = d.homophones(itself, first);
      result2 = d.homophones(itself, second);
  //    std::cout << result1 << "\t" << result2 << std::endl;
      if (result1 && result2)
      {
        auto entry = std::make_tuple(itself, first, second);
        ret.push_back(entry);
      }
    }

    return ret;
}
