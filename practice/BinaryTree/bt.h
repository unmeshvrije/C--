using namespace std;

struct TreeNode
{
  struct TreeNode *left;
  int data;
  struct TreeNode *right;
};

struct TreeNode* newnode(int data)
{
  TreeNode* temp = new TreeNode;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(TreeNode *root)
{
  if (root != NULL) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void preorder(TreeNode *root)
{
  if (root != NULL) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
