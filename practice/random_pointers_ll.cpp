#include<iostream>
#include<map>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node* random;
  Node(int d): data(d), next(NULL), random(NULL){}
};

void print_list(Node *head)
{
  while (head)
  {
    cout << head->data;
    cout << "(";
    if (head->random) {
      cout << head->random->data;
    }
    cout << ")";
    if (head->next) {
      cout << "=>";
    }

    head = head->next;
  }
  cout << endl;
}

struct Node* copy_random_list(struct Node *head)
{
  struct Node* temp = head;
  std::map<Node*,Node*> address;

  while (temp) {

    // Check if this node is already present in the list
    struct Node* newnode = NULL;
    if (address.find(temp) == address.end()) {
      newnode = new Node(temp->data);
      address[temp] = newnode;
    } else {
      newnode = address[temp];
    }

    struct Node* next = NULL;
    if (temp->next){
      if (address.find(temp->next) == address.end()) {
        next = new Node(temp->next->data);
        address[temp->next] = next;
      } else {
        next = address[temp->next];
      }
    }

    newnode->next = next;

    struct Node* random = NULL;
    if (temp->random) {
      if (address.find(temp->random) == address.end()) {
        random = new Node(temp->random->data);
        address[temp->random] = random;
      } else {
        random = address[temp->random];
      }
    }

    newnode->random = random;

    temp = temp->next;
  }

  return address[head];
}

int main()
{
  Node* head = new Node(1);

  Node* one = head;
//  Node* two = one->next = new Node(2);
//  Node* four = two->next = new Node(4);
//  Node* seven = four->next = new Node(7);
//  Node* eight = seven->next = new Node(8);
//  Node* another_eight = eight->next = new Node(8);
//
//  one->random = four;
//  two->random = one;
//  four->random = one;
//  seven->random = seven;
//  eight->random = four;
//  another_eight->random = four;

  print_list(head);
  Node* newHead = copy_random_list(head);
  print_list(newHead);
}
