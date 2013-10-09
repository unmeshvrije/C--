#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "bintree.h"

int menu()
{
  int choice;

  printf("0. Exit\n");
  printf("1. Add\n");
  printf("2. Display\n");
  printf("3. Level Wise Display\n");
  printf("4. Add NonRecursive\n");
  printf("5. Pre-Order Display (NonRecursive)\n");

  printf("Enter choice:");
  scanf("%d", &choice);

  return choice;
}

int main()
{
  int choice;
  int data;
  TreeNode newnode;
  TreeNode *root = NULL;

  while ((choice = menu()) != 0)
  {
    switch (choice)
    {
      case 1:
      {
        printf("Enter data: \n");
	scanf("%d", &data);

	newnode.data = data;
        newnode.left = NULL;
        newnode.right = NULL;

        appendBinTree(&root, &newnode);
        break;
      }

      case 4:
      {
        printf("Enter data: \n");
	scanf("%d", &data);

        appendNonRecursive(&root, data);
        break;
      }

      case 2:
      {
        inorder(root);
	printf("\n");
        break;
      }

      case 3:
      {
        LevelWiseDisplay(root);
	printf("\n");
        break;
      }

      case 5:
      {
        preorderNonRecursive(root);
	printf("\n");
	break;
      }
    }
  }

  return 0;
}
