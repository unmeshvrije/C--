#include<stdio.h>
#include <malloc.h>

struct TreeNode
{
  struct TreeNode *left;
  int data;
  struct TreeNode *right;
};

struct Qnode
{
  struct TreeNode *leaf;
  struct Qnode *next;
};

void append(struct Qnode **front, struct Qnode**rear, struct TreeNode* leaf)
{
  struct Qnode *newnode = (struct Qnode*)malloc(sizeof(struct Qnode));
  newnode->leaf = leaf;
  newnode->next = NULL;

  if (*front == NULL && *rear == NULL) {
    *front = *rear = newnode;
    return;
  }

  (*rear)->next = newnode;
  *rear = newnode;
}

struct TreeNode* delete(struct Qnode **front, struct Qnode **rear)
{
  if (front == NULL || rear == NULL) {
    printf("front or rear are null\n");
    return NULL;
  }

  struct TreeNode* temp = (*front)->leaf;
  struct Qnode* deleted = *front;

  if (*front == *rear) {
    free(deleted);
    *front = NULL;
    *rear = NULL;
  } else {
    *front = (*front)->next;
    free(deleted);
  }

  return temp;
}

int queue_empty(struct Qnode *front, struct Qnode *rear)
{
  if (front == rear && front == NULL) {
    return 1;
  }
  return 0;
}


struct Stacknode
{
  struct TreeNode *leaf;
  struct Stacknode *next;
};

void push(struct Stacknode **top, struct TreeNode *branch)
{
  if (top == NULL || branch == NULL) {
    return;
  }

  struct Stacknode *newnode = (struct Stacknode*)malloc(sizeof(struct Stacknode));
  newnode->leaf = branch;
  newnode->next = *top;
  *top = newnode;
}

struct TreeNode* pop(struct Stacknode** top)
{
  if (top == NULL) {
    return NULL;
  }
  
  if (*top == NULL) {
    return NULL;
  }

  struct TreeNode *branch = (*top)->leaf;
  struct Stacknode *temp = (*top);
  (*top) = (*top)->next;
  free(temp);
  return branch;
}

void preorder_nonrecursive(struct TreeNode *root)
{
  struct Stacknode *top = NULL;
  struct TreeNode *temp = root;
  while (temp != NULL) {
    printf("%d ", temp->data);
    push(&top, temp->right);
    push(&top, temp->left);
    temp = pop(&top);
  }
}
void display_stack(struct Stacknode* top)
{
  struct Stacknode * temp = top;
  while (temp != NULL) {
    printf("%d\n", temp->leaf->data);
    temp = temp->next;
  }
}

void inorder_nonrecursive(struct TreeNode *root)
{
  struct Stacknode*top = NULL;
  struct TreeNode *temp = root;
  while (1) {
    while (temp != NULL) {
      push(&top, temp);
      temp = temp->left;
    }

    temp = pop(&top);

    if (temp == NULL) {
      break;
    }
    printf("%d ", temp->data);
    

    temp = temp->right;
  }
}


void postorder_nonrecursive(struct TreeNode *root)
{
  struct Stacknode *top = NULL;
  struct TreeNode *temp = root;
  struct TreeNode *dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  dummy->data = 0xdeadbeef;
  dummy->left = dummy->right = NULL;

  while (1) {
    while(temp!= NULL) {
      push(&top, temp);
      temp = temp->left;
    }

    temp = pop(&top);
    if (temp ==  NULL)
      break;

    if (temp->right == NULL) {
      printf("%d ", temp->data);
      temp = NULL;
    } else if (top && top->leaf->data == dummy->data) {
      printf("%d ", temp->data);
      struct TreeNode *ignore = pop(&top);
      temp = NULL;
    } else {
      push(&top, dummy);
      push(&top, temp);
      temp = temp->right;
    }
  }
}

void postorder_two_stacks(struct TreeNode *root)
{
  struct Stacknode *mainTop = NULL; // this stack will hold correct post-order
  struct Stacknode *leftTop = NULL; // this stack is there to track "left" of which elements is not yet dealt with

  if (root == NULL) {
    return;
  }

  push(&mainTop, root);
  push(&leftTop, root);
  struct TreeNode *temp = root->right;
  while (1) {
    while (temp != NULL) {
      push(&mainTop, temp);
      push(&leftTop, temp);
      temp = temp->right;
    }

    temp = pop(&leftTop);
    if (temp == NULL) {
      break;
    }

    temp = temp->left;
  }

  while(mainTop != NULL) {
    temp = pop(&mainTop);
    printf("%d ", temp->data);
  }
  printf("\n");
}

void level_wise_display(struct TreeNode *root)
{
  struct Qnode *front = NULL, *rear = NULL;
  append(&front, &rear, root);

  int n = 0;
  while(!queue_empty(front, rear)) {
    ++n;

    if ((n & (n-1)) == 0) {
      printf("\n");
    }

    struct TreeNode *element = delete(&front, &rear);
    if (element != NULL) {
      printf("%d ", element->data);
      append(&front, &rear, element->left);
      append(&front, &rear, element->right);
    }
  }
}

void insert(struct TreeNode **root, int data)
{
  if (*root == NULL) {
    struct TreeNode *newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    *root = newnode;
    return;
  }

  if (data < (*root)->data) {
    insert(&((*root)->left), data);
  } else {
    insert(&((*root)->right), data);
  }
}

void preorder(struct TreeNode *root)
{
  if (root != NULL) {
      printf("%d ", root->data);
      preorder(root->left);
      preorder(root->right);
  }
}

void inorder(struct TreeNode *root)
{
  if (root != NULL) {
      inorder(root->left);
      printf("%d ", root->data);
      inorder(root->right);
  }
}

int menu()
{
  int ch;
  printf("\n");
  printf("0) Exit\n");
  printf("1) insert\n");
  printf("2) preorder\n");
  printf("3) inorder\n");
  printf("4) Level wise\n");
  printf("5) Postorder\n");
  printf("Enter your choice: ");
  scanf("%d", &ch);
  return ch;
}

struct TreeNode* create_minimal_bst(int *arr, int start, int end)
{
  if (end < start) {
    return NULL;
  }

  struct TreeNode *newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  int mid = (start + end)/2;
  newnode->data = arr[mid];
  newnode->left = create_minimal_bst(arr, start, mid-1);
  newnode->right = create_minimal_bst(arr, mid+1, end);
  return newnode;
}


int main(int argc, char *argv[])
{
  int choice;
  int n;
  int p;
  struct TreeNode *root = NULL;
  int arr[] = {1,2,3,4,5,6,7,9,15,23};
  root = create_minimal_bst(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
    ;
  while(1)
  {
    choice = menu();
    switch(choice)
    {
      case 0: return 0;
      case 1: printf("Enter number: ");
              scanf("%d", &n);
              insert(&root, n);
              break;
      case 2: preorder_nonrecursive(root);
              break;
      case 3: inorder_nonrecursive(root);
              break;
      case 4: level_wise_display(root);
              break;
      case 5: 
              //postorder_nonrecursive(root);
              postorder_two_stacks(root);
              break;
      default:return 0;

    }
  }

    return 0;
}
