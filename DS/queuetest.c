#include "queue.h"

#define	NON_STANDARD_WAY 0
#define	STANDARD_WAY	1


#if NON_STANDARD_WAY
int main()
{
 int i;
 
 QueueNode *head=NULL, *tail=NULL;

 for (i = 0; i < 5; ++i)
 {
   AddToQueue((void**)&i, &head, &tail);
 }

 for (i = 0; i < 5; ++i)
 {
  int temp = (int)RemoveFromQueue(&head, &tail);
  printf("%5d ", temp);
 }
 FreeQueue(head);

}

#endif


#if STANDARD_WAY

typedef struct Node
{
   int i;

}Node;

int main()
{
  int i;
  Node newnode[5];
  QueueNode *head = NULL, *tail = NULL;

  for (i = 0; i < 5; i++)
  {
    newnode[i].i = i;

    Node *ptr = &newnode[i];
    AddToQueue((void**)&ptr, &head, &tail);
  }
  for (i = 1; i <5; i++ )
  {
    Node *newnode = RemoveFromQueue(&head, &tail);
    printf("%5d", newnode->i);
  }

  return 0;
}
#endif
