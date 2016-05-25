#include<iostream>
#include<climits>
#include<stack>
#include "bt.h"

using namespace std;

TreeNode* convert_cdll(TreeNode *root)
{
  stack<TreeNode*> s;
  TreeNode* prev = NULL, *head = NULL, *node = NULL;
  TreeNode* temp = root;

  while (1) {
    while(temp) {
      s.push(temp);
      temp = temp->left;
    }

    if (s.empty()) {
      break;
    }

    node = s.top();
    s.pop();
    if (prev == NULL) {
      prev = head = node;
    } else {
      prev->right = node;
      node->left = prev;
      prev = node;
    }

    temp = node->right;
  }

  head->left = node;
  node->right = head;

  return head;
}

void print_cdll(TreeNode *root)
{
  if (root == NULL) {
    return;
  }
  TreeNode *temp = root;
  do {
    cout << temp->data << " ";
    temp = temp->right;
  } while (temp != root);

}

int main()
{
  TreeNode *root = newnode(8);
  root->left = newnode(3);
  
  root->left->left = newnode(1);
  root->left->right = newnode(6);
  root->left->right->left = newnode(4);
  root->left->right->right = newnode(7);

  root->right = newnode(10);
  root->right->right = newnode(14);
  root->right->right->left = newnode(13);

  inorder(root);
  cout << endl;

  TreeNode* crazy = convert_cdll(root);
  print_cdll(crazy->left);
  cout << endl;
  return 0;
}

