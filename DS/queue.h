#include <stdio.h>
#include <string.h>
#include <malloc.h>

#ifndef _QUEUE_H_
#define	_QUEUE_H_

extern int DataSize;

typedef struct QueueNode
{
  void *Data;
  struct QueueNode *pNext;

}QueueNode;


int AddToQueue(void **, QueueNode **, QueueNode **);
int FreeQueue(QueueNode *);
void *RemoveFromQueue(QueueNode **, QueueNode**);

int IsQueueEmpty(QueueNode** head, QueueNode **tail);
//void DisplayQueue(QueueNode**);


#endif // _QUEUE_H_
