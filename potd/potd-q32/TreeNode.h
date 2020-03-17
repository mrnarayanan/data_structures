#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>
#include <algorithm>
#include <cmath>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    int balance_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
      balance_ = 0;
    }
};

int getHeightBalance(TreeNode* root);

int height(TreeNode* root);

bool isHeightBalanced(TreeNode* root);

TreeNode* findLastUnbalanced(TreeNode* root);

void deleteTree(TreeNode* root);

#endif
