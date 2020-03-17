#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  if (leftHeavy(subroot))
  {
    if (rightHeavy(subroot->left_))
      return TreeNode::leftRight;
    else
      return TreeNode::right;
  }
  else if (rightHeavy(subroot))
  {
    if (leftHeavy(subroot->right_))
      return TreeNode::rightLeft;
    else
      return TreeNode::left;
  }

  return TreeNode::right;
}
