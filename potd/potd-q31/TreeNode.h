#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>
#include <algorithm>
#include <cmath>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
    }
};

int getHeightBalance(TreeNode* root);

int height(TreeNode* root);

bool isHeightBalanced(TreeNode* root);

void deleteTree(TreeNode* root);

#endif
