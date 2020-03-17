#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second)
{
  // your code here!
  while (first != NULL || second != NULL)
  {
    if (first != NULL && second != NULL)
    {
      Node * temp = second->next_;
      if (first->next_ == NULL)
      {
//        second->next_ = second->next_;
        first->next_ = second;
        return;
      }
      else if (second->next_ == NULL)
      {
        second->next_ = first->next_;
        first->next_ = second;
        return;
      }
      else
        second->next_ = first->next_;
      first->next_ = second;
      first = second->next_;
      second = temp;
    }
    else if (first == NULL && second != NULL)
    {
      first = second;
      return;
    }
    else if (first != NULL && second == NULL)
    {
      return;
    }
  }
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
