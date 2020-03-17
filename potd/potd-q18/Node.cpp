#include "Node.h"

using namespace std;

void sortList(Node **head)
{
  // your code here!
  bool sorted = false;
  Node * cr = *head;
  if (*head == NULL) // empty list
    return;
  if ((*head)->next_ == NULL) // list with 1 node
    return;
  else
    Node * nx = (*head)->next_;
  while (sorted == false)
  {
    if (cr->data_ > nx->data_)
    {
      cr->next_ = nx->next_;
      nx->next_ = cr;
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
