#include<iostream>
#include<climits>
#include<sstream>
#include<vector>
#include "bt.h"

using namespace std;


vector<TreeNode*> getTrees(int* arr, int start, int end)
{
  vector<TreeNode*> trees;

  if (start > end) {
    trees.push_back(NULL);
    return trees;
  }

  for (int i = start; i <= end; ++i){

    vector<TreeNode*> leftTrees = getTrees(arr, start, i-1);
    vector<TreeNode*> rightTrees= getTrees(arr, i+1, end);

    for (int j = 0; j < leftTrees.size(); ++j) {
      for (int k = 0; k < rightTrees.size(); ++k) {
        TreeNode *node = newnode(arr[i]);
        node->left = leftTrees[j];
        node->right = rightTrees[k];
        trees.push_back(node);
      }
    }
  }

  return trees;
}

string print_array(int *arr, int n)
{
  stringstream ss;
  for (int i = 0; i < n; ++i) {
    ss << arr[i];
    if (i+1 < n) {
      ss << ", ";
    }
  }

  return ss.str();
}

int main()
{
  int in[] = {4,5,7};
  int n = sizeof(in) / sizeof(*in);

  vector<TreeNode*> trees = getTrees(in, 0, n-1);

  cout << "Possible preorders of {" << print_array(in, n) << "} are " << endl;
  for (int i = 0; i < trees.size(); ++i) {
    preorder(trees[i]);
    cout << endl;
  }
  return 0;
}

