#include <vector>
#include "BTreeNode.h"

using namespace std;

void recurse(vector<int> * v, BTreeNode * node)
{
  if (node->is_leaf_ == true)
    copy_contents(node, v);
  else
  {
    for (unsigned i = 0; i < node->elements_.size(); i++)
    {
      if (node->children_[i]->elements_[0] < node->elements_[i])
        recurse(v, node->children_[i]);
      v->push_back(node->elements_[i]);
    }
    recurse(v, node->children_[node->elements_.size()]);
  }
}

vector<int> traverse(BTreeNode* root) {
    // your code here
    vector<int> v;
    recurse(&v, root);
    return v;
}

void copy_contents(BTreeNode* node, vector<int> * v)
{
  for (unsigned i = 0; i < node->elements_.size(); i++)
    v->push_back(node->elements_[i]);
}
