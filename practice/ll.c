#include<stdio.h>
#include<malloc.h>

int menu()
{
  int ch;
  printf("\n");
  printf("0) Exit\n");
  printf("1) Append\n");
  printf("2) Display\n");
  printf("3) Insert\n");
  printf("4) Delete\n");
  printf("5) Reverse\n");
  printf("6) Reverse recursion\n");
  printf("Enter your choice: ");
  scanf("%d", &ch);
  return ch;
}

struct Node
{
  int data;
  struct Node* next;
};

void Append(struct Node** head, int data)
{
  struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = data;
  newnode->next = NULL;

  if (*head == NULL) {
    *head = newnode;
    return;
  }

  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
}

void Display(struct Node *head)
{
  struct Node*temp = head;
  printf("\n(");
  while (temp != NULL)
  {
    printf("%d", temp->data);
    if (temp->next) {
      printf("->");
    }
    temp = temp->next;
  }
  printf(")\n");
}


void Insert(struct Node **head, int data, int pos)
{
  struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = data;
  newnode->next = NULL;

  if (pos <= 0){
    printf("Invalid position\n");
    return;
  }

  if (pos == 1) {
    newnode->next = *head;
    *head = newnode;
    printf("%d inserted successfully at position %d", data, pos);
    return;
  }

  struct Node *temp = *head;
  int i = 0;
  while (i < pos-2 && temp != NULL) {
    temp = temp->next;
    i++;
  }

  if (temp == NULL){
    printf("Invalid position\n");
    return;
  }

  newnode->next = temp->next;
  temp->next = newnode;
  printf("%d inserted successfully at position %d", data, pos);
}

void Delete(struct Node **head, int data)
{
  struct Node *temp = *head;
  struct Node *prev = *head;

  if (*head == NULL) {
    printf("LL is empty.\n");
    return;
  }

  char found = 'f';

  if (temp->data == data){
    *head = (*head)->next;
    free(temp);
    found = 't';
  }

  do
  {
    prev = temp;
    temp = temp->next;
    if (temp == NULL) {
      break;
    }

    if (temp->data == data) {
      prev->next = temp->next;
      free(temp);
      printf("%d successfully deleted.\n", data);
      found = 't';
    }
  }while (temp != NULL);

  if (found == 'f') {
      printf("%d not found.\n", data);
  }
}

void reverse(struct Node **head)
{
  if (*head == NULL)
    return;

  struct Node *newHead = (struct Node*) malloc(sizeof(struct Node));
  newHead->data = 0;
  newHead->next = *head;
  struct Node *prev = newHead;
  struct Node *cur = prev->next;
  struct Node *mov;
  while (cur->next != NULL) {
      mov = cur->next;
      cur->next = mov->next;
      mov->next = prev->next;
      prev->next = mov;
  }

  *head = newHead->next;
}

int reverse_recurse(struct Node *head)
{
  if (head == NULL) {
    return 0;
  }

  if (head->next == NULL) {
    return head->data;
  }

 int data = reverse_recurse(head->next);
 printf("%d ", data);
 return head->data;
}

int main(int argc, char *argv[])
{
  int choice;
  int n;
  int p;
  struct Node *head = NULL;
  while(1)
  {
    choice = menu();
    switch(choice)
    {
      case 0: return 0;
      case 1: printf("Enter number: ");
              scanf("%d", &n);
              Append(&head, n);
              break;
      case 2: Display(head);
              break;
      case 3: printf("Enter number: ");
              scanf("%d", &n);
              printf("Enter position: ");
              scanf("%d", &p);
              Insert(&head, n, p);
              break;
      case 4: printf("Enter number: ");
              scanf("%d", &n);
              Delete(&head, n);
              break;
      case 5: reverse(&head);
              Display(head);
              break;
      case 6: reverse_recurse(head);
              break;
      default:return 0;

    }
  }
  return 0;
}
