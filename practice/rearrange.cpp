#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
};

Node* newnode(int data)
{
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void display(struct Node *head)
{
  while (head) {
    cout << head->data;
    if (head->next) cout << "->";
    head = head->next;
  }
  cout << endl;
}

void reverse_list(struct Node **head)
{
  if (head == NULL || *head == NULL) {
    return;
  }
  Node *newHead = newnode(0);
  newHead->next = *head;
  Node *prev = newHead, *cur = *head, *mov;
  while (cur->next) {
    mov = cur->next;
    cur->next = mov->next;
    mov->next = prev->next;
    prev->next = mov;
  }

  *head = newHead->next;
}

void rearrange(struct Node **head)
{
  if (head == NULL || *head == NULL){
    return;
  }

  struct Node *slow = *head, *fast = *head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  struct Node *head1 = *head;
  struct Node *head2 = slow->next;
  slow->next = NULL; //Split the list into two

  reverse_list(&head2);

  *head = newnode(0); // Assign a dummy node at the head.
  struct Node *cur = *head;
  // Merge until we are done
  while (head1 || head2) {
    if (head1) {
      cur->next = head1;
      cur = cur->next;
      head1 = head1->next;
    }

    if (head2) {
      cur->next = head2;
      cur = cur->next;
      head2 = head2->next;
    }
  }

  *head = (*head)->next;
}

int main(void)
{
  Node *head = newnode(1);
//  head->next = newnode(2);
//  head->next->next = newnode(3);
//  head->next->next->next = newnode(4);
//  head->next->next->next->next = newnode(5);
//  head->next->next->next->next->next = newnode(6);
  display(head);
  rearrange(&head);
  display(head);
  return 0;
}
