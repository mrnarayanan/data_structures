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

Node *listUnion(Node *first, Node *second);
bool findval(Node * ptr, int val);

////////////////////////////////////////////////

Node *listUnion(Node *first, Node *second) {
  // your code here
  Node * curr;
  Node * uni;
  if (first != NULL)
    uni = new Node(first->data_);
  else if (second != NULL)
    uni = new Node(second->data_);
  else
    uni = NULL;
  curr = uni;
  Node * add;
  Node * traveler = first;
  while (traveler != NULL)
  {
    if (!findval(uni, traveler->data_))
    {
      add = new Node(traveler->data_);
      curr->next_ = add;
      curr = add;
    }
    traveler = traveler->next_;
  }
  traveler = second;
  while (traveler != NULL)
  {
    if (!findval(uni, traveler->data_))
    {
      add = new Node(traveler->data_);
      curr->next_ = add;
      curr = add;
    }
    traveler = traveler->next_;
  }

  return uni;
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
