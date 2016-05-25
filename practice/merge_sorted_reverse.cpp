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

struct Node* merge_sorted(struct Node *head1, struct Node *head2)
{
  if (head1 == NULL && head2 == NULL){
    return NULL;
  }

  if (head1 == NULL) {
    return head2;
  }

  if (head2 == NULL) {
    return head1;
  }

  struct Node *h1 = head1;
  struct Node *h2 = head2;
  struct Node *p1 = newnode(0); // dummy node
  p1->next = head1;

  while (h1) {

    if (h2 && h2->data < h1->data) {
      head2 = h2->next;
      h2->next = p1->next;
      p1->next = h2;
      p1 = h2;
      if (h1 == head1) {
        head1 = h2;
      }
      h2 = head2;
    } else {
      p1 = h1;
      h1 = h1->next;
    }
  }

  if (h2) {
    p1->next = h2;
  }

  return head1;
}

int main(void)
{
  Node *head1 = newnode(5);
  head1->next = newnode(10);
  head1->next->next = newnode(15);
  head1->next->next->next = newnode(40);
  head1->next->next->next->next = newnode(50);
  head1->next->next->next->next->next = newnode(60);

  Node *head2 = newnode(2);
  head2->next = newnode(3);
  head2->next->next = newnode(20);
  head2->next->next->next = newnode(70);
  head2->next->next->next = newnode(80);
  head2->next->next->next = newnode(90);

  display(head1);
  display(head2);
  struct Node *merged_head = merge_sorted(head1, head2);
  display(merged_head);
  return 0;
}
