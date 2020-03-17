#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {

    // Your code here
    TreeNode* axis = root->left_;
    root->left_ = axis->right_;
    if (axis->right_ != NULL)
      axis->right_->parent_ = root;
    axis->right_ = root;
    axis->parent_ = root->parent_;
    root->parent_ = axis;

}


void leftRotate(TreeNode* root) {

    // your code here
    TreeNode* axis = root->right_;
    root->right_ = axis->left_;
    if (axis->left_ != NULL)
      axis->left_->parent_ = root;
    axis->left_ = root;
    axis->parent_ = root->parent_;
    root->parent_ = axis;

}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
