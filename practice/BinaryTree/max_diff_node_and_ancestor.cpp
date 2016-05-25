#include<iostream>
#include<climits>
#include "bt.h"

using namespace std;

int get_max_diff_util(TreeNode *root, int *maxDiff)
{
  if (root == NULL) {
    return INT_MAX;
  }

  if (root->left == NULL && root->right == NULL) {
    return root->data;
  }

  int minVal = min(get_max_diff_util(root->left, maxDiff), get_max_diff_util(root->right, maxDiff));

  *maxDiff = max(*maxDiff, root->data - minVal);

  return minVal;
}


int get_max_diff(TreeNode* root)
{
  int maxDiff = INT_MIN;
  get_max_diff_util(root, &maxDiff);
  return maxDiff;
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

  int answer = get_max_diff(root);
  cout << "Maximum difference between any node and its ancestor is " << answer << endl;
  return 0;
}

