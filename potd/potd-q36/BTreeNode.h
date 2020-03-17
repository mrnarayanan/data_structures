#ifndef BTREENODE_H
#define BTREENODE_H

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct BTreeNode {
    bool is_leaf_=true;
    vector<int> elements_;
    vector<BTreeNode*> children_;
    BTreeNode() {}
    BTreeNode (vector<int> v) {
      this->elements_ = v;
    }
};

void recurse(vector<int> * v, BTreeNode * node);
vector<int> traverse(BTreeNode* root);
void copy_contents(BTreeNode* node, vector<int> * v);

#endif
