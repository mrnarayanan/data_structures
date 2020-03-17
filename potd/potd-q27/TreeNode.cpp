#include "TreeNode.h"

#include <cstddef>
#include <iostream>
#include <algorithm>

using namespace std;

int height_help(TreeNode * curr)
{
  if (curr == NULL)
    return -1;
  else
    return 1+max(height_help(curr->left_),height_help(curr->right_));
}

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  return height_help(this);
}
