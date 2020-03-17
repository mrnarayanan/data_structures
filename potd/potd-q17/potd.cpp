#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert)
{
  // your code here!
  // case 1 - inserting at head
  if (*head == NULL || (*head)->data_ >= insert->data_)
  {
    insert->next_ = *head;
    *head = insert;
    return;
  }

  // case 2 - inserting in position in middle somewhere
  Node * curr = *head;
  while (curr->next_ != NULL)
  {
    if (curr->next_->data_ >= insert->data_)
    {
      insert->next_ = curr->next_;
      curr->next_ = insert;
      return;
    }
    curr = curr->next_;
  }
  // case 3 - inserting at end of list
  curr->next_ = insert;
  insert->next_ = NULL;
  return;
}
