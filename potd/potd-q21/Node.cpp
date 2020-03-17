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

Node *listIntersection(Node *first, Node *second);
bool findval(Node * ptr, int val);

//////////////////////////////////////////////////////////

Node *listIntersection(Node *first, Node *second) {
  // your code here
  Node * curr;
  Node * uni = NULL;
  if (first == NULL || second == NULL)
    return uni;
  curr = uni;
  Node * add;
  Node * traveler = first;
  while (traveler != NULL)
  {
    if (findval(second, traveler->data_))
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
