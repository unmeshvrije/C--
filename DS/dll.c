/*++

Module Name:
	dll.c.

Abstract:
	This module writes doubly linked list functions.

Revision History:
	Date:	Jul 28 2013.
	Author:	Unmesh Joshi.
	Desc:	Created.

--*/


/////////////////////////////////////////////////////////////////////
//	H E A D E R S.
/////////////////////////////////////////////////////////////////////

#include "dll.h"


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
AddToList(
	INT *pNodeData,
	INT_DOUBLY_LIST **ppListHead,
	INT_DOUBLY_LIST **ppListTail
	)
{
	INT_DOUBLY_LIST *pNewNode;

	if (NULL == pNodeData || NULL == ppListHead || NULL == ppListTail)
	{
		return -1;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (INT_DOUBLY_LIST *)malloc(sizeof(INT_DOUBLY_LIST));
	if (NULL == pNewNode)
	{
		return -1;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(INT_DOUBLY_LIST));
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
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
		pNewNode->pPrev = (*ppListTail);
		(*ppListTail)->pNext = pNewNode;
		*ppListTail = pNewNode;
	}

	//printf("Added");
	return 0;
}


//*******************************************************************
//
//	Function:
//		AppendToList.
//
//	Parameters:
//
//	Description:
//
//	Returns:
//
//*******************************************************************
int
AppendToGenList(
	INT_DOUBLY_LIST **ppListToBeAppended,
	INT_DOUBLY_LIST **ppListHead,
	INT_DOUBLY_LIST **ppListTail
	)
{
	INT_DOUBLY_LIST *pNav;
	INT_DOUBLY_LIST *pPrev;

	if (NULL == ppListToBeAppended || NULL == ppListHead || NULL == ppListTail)
	{
		return FALSE;
	}

	if (NULL == *ppListHead)
	{
		*ppListHead = *ppListTail = *ppListToBeAppended;
	}
	else
	{
		(*ppListToBeAppended)->pPrev = (*ppListTail);
		(*ppListTail)->pNext = *ppListToBeAppended;
	}

	//TODO:
	pNav = *ppListTail;
	pPrev = *ppListTail;
	while (NULL != pNav)
	{
		pPrev = pNav;
		pNav = pNav->pNext;
	}

	*ppListTail = pPrev;
	return TRUE;
}

//TODO:
//*******************************************************************
//
//	Function:
//		FreeList.
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
FreeList(
	INT_DOUBLY_LIST *pListHead
	)
{
	INT_DOUBLY_LIST *pTemp;
	INT_DOUBLY_LIST *pNavigate;

	if (NULL == pListHead)
	{
		return FALSE;
	}

	pNavigate = pListHead;
	while (NULL != pNavigate)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}

	return TRUE;
}

void
DisplayList(
	INT_DOUBLY_LIST *pListHead
	)
{
	INT_DOUBLY_LIST *pNavigate;

	if (NULL == pListHead)
	{
		return;
	}

	pNavigate = pListHead;
	while (NULL != pNavigate)
	{
		printf("%-5d ", pNavigate->Data);
		pNavigate = pNavigate->pNext;
	}

	printf("\n");
}

//*******************************************************************
//
//	Function:
//		FreeList.
//
//	Parameters:
//
//	Description:
//		This function frees the list.
//
//	Returns:
//
//*******************************************************************
int RemoveFromList(int data,	INT_DOUBLY_LIST **ppListHead,	INT_DOUBLY_LIST **ppListTail	)
{
	char chFound;
	INT_DOUBLY_LIST *pFollow;
	INT_DOUBLY_LIST *pNavigate;

	if (NULL == ppListHead || NULL == ppListTail)
	{
		  return -1;
	}

	chFound = 'n';
	pFollow = *ppListHead;
	pNavigate = *ppListHead;
	while (NULL != pNavigate)
	{
	    if (pNavigate->Data == data)
	    {
	      if (*ppListHead == pNavigate)
	      {
			//
			//  Deleting first node: Adjust head
			//
			*ppListHead = (*ppListHead)->pNext;
	      }
	      else if (*ppListTail == pNavigate)
	      {
	        	//
			// Deleting last node: Adjust tail
			//
			*ppListTail = pFollow;
			(*ppListTail)->pNext = NULL;
	      }
	      else
	      {
			pFollow->pNext = pNavigate->pNext;
	      }
	      
	      chFound = 'y';
	      free(pNavigate);
	      break;
	    }
	    
	    pFollow = pNavigate;
	    pNavigate = pNavigate->pNext;
	}

	if ('n' == chFound)
		return -1;

	return 0;
}

int FindNthElementFromLast(INT_DOUBLY_LIST *pHead, int n)
{
  int cnt;
  INT_DOUBLY_LIST *pNthFromLast = NULL;
  INT_DOUBLY_LIST *pNav;

  if (NULL == pHead || n <= 0)
    return 0;

  pNav = pHead;

  cnt = 1;
  while (1)
  {
    pNav = pNav->pNext;

    if (cnt == n)
        pNthFromLast = pHead;

    if (NULL == pNav)
      break;

    if (cnt >= n)
    {

      if (NULL == pNthFromLast)
      printf("Nav = %d\n", pNav->Data);

      pNthFromLast = pNthFromLast->pNext;
    }

    cnt++;
  }

  if (NULL == pNthFromLast)
    return -1;

  return pNthFromLast->Data;
}
