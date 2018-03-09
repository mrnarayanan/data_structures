/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* axis = t->right;
    t->right = axis->left;
    axis->left = t;
    t = axis;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* axis = t->left;
    t->left = axis->right;
    axis->right = t;
    t = axis;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (subtree == NULL)
      return;
    else
    {
      if ( find_balance(subtree) < -1 && find_balance(subtree->left) < 0 )
        rotateRight(subtree);
      else if ( find_balance(subtree) < -1 && find_balance(subtree->left) > 0 )
        rotateLeftRight(subtree);
      else if ( find_balance(subtree) > 1 && find_balance(subtree->right) < 0 )
        rotateRightLeft(subtree);
      else if ( find_balance(subtree) > 1 && find_balance(subtree->right) > 0 )
        rotateLeft(subtree);

      // update height
      if (subtree->left != NULL)
        subtree->left->height = 1 + max( heightOrNeg1(subtree->left->left), heightOrNeg1(subtree->left->right) );
      if (subtree->right != NULL)
        subtree->right->height = 1 + max( heightOrNeg1(subtree->right->left), heightOrNeg1(subtree->right->right) );
      subtree->height = 1 + max( heightOrNeg1(subtree->left), heightOrNeg1(subtree->right) );
    }
}

template <class K, class V>
int AVLTree<K, V>::find_balance(const Node* node) const
{
  if (node == NULL)
    return 0;
  else
    return heightOrNeg1(node->right) - heightOrNeg1(node->left);
}

template <class K, class V>
typename AVLTree<K, V>::Node* AVLTree<K, V>::get_IOP(Node* subRoot)
{
  Node* ret = subRoot;
  while (ret->right != NULL)
    ret = ret->right;
  return ret;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == NULL)
      subtree = new Node(key, value);
    if (key < subtree->key && subtree->left != NULL)
    {
      insert(subtree->left, key, value);
      rebalance(subtree);
    }
    else if (key > subtree->key && subtree->right != NULL)
    {
      insert(subtree->right, key, value);
      rebalance(subtree);
    }
    else if (key < subtree->key && subtree->left == NULL)
    {
      subtree->left = new Node(key, value);
      rebalance(subtree);
    }
    else if (key > subtree->key && subtree->right == NULL)
    {
      subtree->right = new Node(key, value);
      rebalance(subtree);
    }
    else if (key == subtree->key)
      subtree->value = value;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key)
    {
      // your code here
      remove(subtree->left, key);
      rebalance(subtree);
    }
    else if (key > subtree->key)
    {
      // your code here
      remove(subtree->right, key);
      rebalance(subtree);
    }
    else // found node to remove
    {
      if (subtree->left == NULL && subtree->right == NULL)
      {
        /* no-child remove */
        // your code here
        subtree = NULL;
      }
      else if (subtree->left != NULL && subtree->right != NULL)
      {
        /* two-child remove */
        // your code here
        Node* iop = get_IOP(subtree->left);
        swap(subtree, iop);
        remove(subtree->left, key);
    //    iop = NULL;
      }
      else
      {
        /* one-child remove */
        // your code here
        if (subtree->left == NULL)
          subtree = subtree->right;
        else
          subtree = subtree->left;
      }
      // your code here
      rebalance(subtree);
    }
}
