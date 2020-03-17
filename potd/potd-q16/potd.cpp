#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    // your code here!
    if (head == NULL)
      return "Empty list";
    else
    {
      string output = "";
      int count = 0;
      Node * curr = head;
      while (curr != NULL)
      {
        output += "Node " + to_string(count) + ": " + to_string(curr->data_);
        if (curr->next_ != NULL)
          output += " -> ";
        curr = curr->next_;
        count++;
      }
      return output;
    }
}
