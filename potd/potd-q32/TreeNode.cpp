#include "TreeNode.h"

using namespace std;

bool isHeightBalanced(TreeNode* root) {
  if ( abs(getHeightBalance(root)) <= 1 )
    return true;
  else
    return false;
}

int getHeightBalance(TreeNode* root) {
  if (root == NULL)
    return 0;
  else
    return height(root->left_) - height(root->right_);
}

int height(TreeNode* root)
{
  if (root == NULL)
    return -1;
  else
    return 1+max( height(root->left_), height(root->right_));
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  if (root == NULL)
    return NULL;
  if ( abs(getHeightBalance(root->left_)) > 1 )
    return findLastUnbalanced(root->left_);
  if ( abs(getHeightBalance(root->right_)) > 1 )
      return findLastUnbalanced(root->right_);
  if ( abs(getHeightBalance(root)) <= 1 )
    return NULL;
  if ( abs(getHeightBalance(root)) > 1 )
    return root;
  return NULL;

}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
