typedef struct TreeNode
{
  struct TreeNode *left;
  int data;
  struct TreeNode *right;

} TreeNode;

int appendBinTree(TreeNode **root, TreeNode *newnode);
int appendNonRecursive(TreeNode **root, int data);

void inorder(TreeNode *root);
void preorderNonRecursive(TreeNode *root);

void LevelWiseDisplay(TreeNode *root);

int SumOfValuesOddEven(TreeNode *root);
