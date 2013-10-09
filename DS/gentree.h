typedef struct GenTreeNode
{
  int data;
  struct GenTreeNode *firstChild;
  struct GenTreeNode *nextSibling;

}GenTreeNode;
