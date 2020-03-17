#ifndef NODE_H
#define NODE_H

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

#endif
