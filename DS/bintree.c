#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "bintree.h"
#include "queue.h"
#include "stack.h"


int appendBinTree(TreeNode **root, TreeNode *newnode)
{
  if (NULL == root)
    return -1;

  if (*root == NULL)
  {
    *root = (TreeNode*)malloc(sizeof(TreeNode));
    memcpy(*root, newnode, sizeof(TreeNode));
  }
  else if (newnode->data < (*root)->data)
    appendBinTree(&((*root)->left), newnode);
  else
    appendBinTree(&((*root)->right), newnode);

  return 0;
}

int appendNonRecursive(TreeNode **root, int data)
{
  if (NULL == root)
    return -1;

  TreeNode *newnode = (TreeNode*) malloc(sizeof(TreeNode));
  if (NULL == newnode)
    return -1;

  newnode->data = data;
  newnode->left = newnode->right = NULL;

  if (NULL == *root)
    *root = newnode;
  else
  {
    TreeNode *nav = *root;

    while (1)
    {
      if (data < (nav)->data)
      {
        if (NULL == nav->left)
	{
	  nav->left = newnode;
	  break;
	}

	nav = nav->left;
      }
      else
      {
        if (NULL == nav->right)
	{
	  nav->right = newnode;
	  break;
	}
        nav = nav->right;
      }
    }
  }
}

void inorder(TreeNode *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%5d ", root->data);
  inorder(root->right);
}

void preorder(TreeNode *root)
{
  if (root == NULL)
    return;
  printf("%5d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void preorderNonRecursive(TreeNode *root)
{
  StackNode *top = NULL;

  AddToStack((void**)&root, &top);

  while (!IsStackEmpty(&top))
  {
    TreeNode *node = RemoveFromStack(&top);
    printf("%5d", node->data);

    if (NULL != node->right)
      AddToStack((void**)(&(node->right)), &top);

    if (NULL != node->left)
    AddToStack((void**)(&(node->left)), &top);
  }
}


void LevelWiseDisplay(TreeNode *root)
{
  if (NULL == root)
    return;
 
  QueueNode *head=NULL, *tail=NULL;

  int CurrentLevel = 1;
  int NextLevel = 0;

  AddToQueue((void**)&root, &head, &tail);

  while (!IsQueueEmpty(&head, &tail))
  {
    TreeNode *node = (TreeNode*)RemoveFromQueue(&head, &tail);
    CurrentLevel--;

    if (node)
    {
      printf("%-5d ", node->data);
      if (node->left)
      {
        AddToQueue((void**)&(node->left), &head , &tail);
	NextLevel++;
      }
      if (node->right)
      {
        AddToQueue((void**)&(node->right), &head , &tail);
	NextLevel++;
      }
    }

    if (CurrentLevel == 0)
    {
      printf("\n");
      CurrentLevel = NextLevel;
      NextLevel = 0;
    }
  }


  FreeQueue(head);
}

/*
Print sum of values at Odd height
     -
      sum of values at Even height 

*/
int SumOfValuesOddEven(TreeNode *root)
{
  if (NULL == root)
    return 0;

  return -(root->data + SumOfValuesOddEven(root->left) + SumOfValuesOddEven(root->right));
}
