#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>

using std::string;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string str = "";
    HuffmanNode * current = huffmanTree;
    if (binaryString == "" || huffmanTree == NULL)
      return str;
    else
    {
      for (unsigned i = 0; i < binaryString.length(); i++)
      {
        if (binaryString[i] == '1')
          current = current->right_;
        else
          current = current->left_;
        if (current->right_ == NULL && current->left_ == NULL)
        {
          str += current->char_;
          current = huffmanTree;
        }
      }
      return str;
    }
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    return "";
}
