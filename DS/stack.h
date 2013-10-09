#include <stdio.h>
#include <string.h>
#include <malloc.h>

#ifndef _STACK_H_
#define	_STACK_H_

extern int DataSize;

typedef struct StackNode
{
  void *Data;
  struct StackNode *pNext;

}StackNode;


int AddToStack(void **, StackNode **);
int FreeStack(StackNode *);
void *RemoveFromStack(StackNode **);

int IsStackEmpty(StackNode** top);
//void DisplayStack(StackNode**);


#endif // _STACK_H_
