#include <string>

using namespace std;

class Node {
    public:
        int data_;
        Node *next_;
        Node();
        Node(Node &other);
        Node(int dt);
        ~Node();
        static int getNumNodes() {
            return numNodes;
        }
    private:
        static int numNodes;
};

Node *listSymmetricDifference(Node *first, Node *second);
bool findval(Node * ptr, int val);

//////////////////////////////////////////////////////////////

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
  Node * uni = NULL;
  Node * curr = uni;
  if (first == NULL && second == NULL)
    return NULL;
  else if (first == NULL)
  {
    Node * traveler = second;
    curr = new Node(traveler->data_);
    traveler = traveler->next_;
    while (traveler != NULL)
    {
      Node * add = new Node(traveler->data_);
      curr->next_ = add;
      curr = add;
      traveler = traveler->next_;
    }
    return curr;
  }
  else if (second == NULL)
  {
    Node * traveler = first;
    curr = new Node(traveler->data_);
    traveler = traveler->next_;
    while (traveler != NULL)
    {
      Node * add = new Node(traveler->data_);
      curr->next_ = add;
      curr = add;
      traveler = traveler->next_;
    }
    return curr;
  }
  else
  {
    Node * add;
    Node * traveler = first;
    while (traveler != NULL)
    {
      if (!findval(second, traveler->data_) && !findval(traveler->next_, traveler->data_))
      {
        add = new Node(traveler->data_);
        if (curr != NULL)
        curr->next_ = add;
        else
          uni = add;
        curr = add;
      }
      traveler = traveler->next_;
    }
    traveler = second;
    while (traveler != NULL)
    {
      if (!findval(first, traveler->data_) && !findval(traveler->next_, traveler->data_))
      {
        add = new Node(traveler->data_);
        if (curr != NULL)
          curr->next_ = add;
        else
          uni = add;
        curr = add;
      }
      traveler = traveler->next_;
    }
    return uni;
  }
}

bool findval(Node * ptr, int val)
{
  while (ptr != NULL)
  {
    if (ptr->data_ == val)
      return true;
    else
      ptr = ptr->next_;
  }
  return false;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::Node(int dt) {
    this->data_ = dt;
    this->next_ = NULL;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
