/*++

Module Name:
	queue.c

Abstract:
	This module writes linked list functions.

Revision History:
	Date:	Oct 08 2012.
	Author:	Unmesh Joshi.
	Desc:	Created.

--*/


/////////////////////////////////////////////////////////////////////
//	H E A D E R S.
/////////////////////////////////////////////////////////////////////

#include "queue.h"


/////////////////////////////////////////////////////////////////////
//	M A C R O S.
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
//	C O N S T A N T S.
/////////////////////////////////////////////////////////////////////



//*******************************************************************
//
//	Function:
//		AddToList.
//
//	Parameters:
//
//	Description:
//		Linked list append function.
//
//	Returns:
//
//*******************************************************************
int
AddToQueue(
	void **pNodeData,
	QueueNode **ppListHead,
	QueueNode **ppListTail
	)
{
	QueueNode *pNewNode;

	if (NULL == pNodeData || NULL == ppListHead || NULL == ppListTail)
	{
		return -1;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (QueueNode *)malloc(sizeof(QueueNode));
	if (NULL == pNewNode)
	{
		return -1;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(QueueNode));
	pNewNode->pNext = NULL;
	pNewNode->Data = *pNodeData;

	//
	//	Append.
	//
	if (NULL == *ppListHead)
	{
		*ppListHead = *ppListTail = pNewNode;
	}
	else
	{
		(*ppListTail)->pNext = pNewNode;
		*ppListTail = pNewNode;
	}

//	printf("Added");
	return 0;
}


//*******************************************************************
//
//	Function:
//		FreeQueue.
//
//	Parameters:
//
//	Description:
//		This function frees the list.
//
//	Returns:
//
//*******************************************************************
int
FreeQueue(
	QueueNode *pListHead
	)
{
	QueueNode *pTemp;
	QueueNode *pNavigate;

	if (NULL == pListHead)
	{
		return -1;
	}

	pNavigate = pListHead;
	while (NULL != pNavigate)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}

	return 0;
}


void* RemoveFromQueue(QueueNode **ppListHead,	QueueNode **ppListTail)
{
	QueueNode *pTemp;
	void *ret;

	if (NULL == ppListHead || NULL == ppListTail)
	{
		  return NULL;
	}

	pTemp = *ppListHead;

	if (NULL == pTemp) // Queue already empty
	{
	  *ppListTail = NULL;
	  return NULL;
	}

	ret = (*ppListHead)->Data;
	*ppListHead = (*ppListHead)->pNext;
	      
	free(pTemp);
	pTemp = NULL;

	return ret;
}

int IsQueueEmpty(QueueNode **ppHead, QueueNode ** ppTail)
{
  if (NULL == ppHead || NULL == ppTail)
    return -1;

  if (NULL == *ppHead && NULL == *ppTail)
    return 1; // empty

  return 0; // Not empty
}
