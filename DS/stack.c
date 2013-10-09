#include "stack.h"


int
AddToStack(
	void **ppStackNode,
	StackNode **ppStackTop
	)
{
  if (NULL == ppStackTop || NULL == ppStackNode){
     return -1;
     }

  StackNode *newnode = (StackNode*)malloc(sizeof(StackNode));
  if (NULL == newnode)
    return -1;

  newnode->Data = *ppStackNode;
  newnode->pNext = *ppStackTop;
  *ppStackTop = newnode;

  return 0;
}

int
IsStackEmpty(StackNode **ppTop)
{
  if (NULL == ppTop)
    return -1;

  if (NULL == *ppTop)
    return 1;

  return 0;
}

void *
RemoveFromStack(
	StackNode **ppStackTop
	)
{
  if (NULL == ppStackTop)
    return NULL;

  if (IsStackEmpty(ppStackTop))
    return NULL;

  void *data = NULL;
  StackNode *temp = *ppStackTop;
  *ppStackTop = (*ppStackTop)->pNext;
  data = temp->Data;
  free(temp);
  temp = NULL;

  return data;
}


int
FreeStack(
	StackNode *pTop
	)
{
  StackNode *temp = pTop;
  while (NULL != pTop)
  {
    pTop = pTop->pNext;
    free(temp);
    temp = pTop;
  }

  return 0;
}
