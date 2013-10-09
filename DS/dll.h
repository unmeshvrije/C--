/*++

Module Name:
	dll.h.

Abstract:
	This module writes doubly linked list functions.

Revision History:
	Date:	Oct 08 2012.
	Author:	Unmesh Joshi.
	Desc:	Created.

--*/


#ifndef	_DLL_H_
#define	_DLL_H_


/////////////////////////////////////////////////////////////////////
//	H E A D E R S.
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <malloc.h>


/////////////////////////////////////////////////////////////////////
//	M A C R O S.
/////////////////////////////////////////////////////////////////////

#define	TRUE	0
#define	FALSE	-1

/////////////////////////////////////////////////////////////////////
//	C O N S T A N T S.
/////////////////////////////////////////////////////////////////////

typedef int INT;
/////////////////////////////////////////////////////////////////////
//	S T R U C T U R E S.
/////////////////////////////////////////////////////////////////////

//
//	Sructure description.
//
typedef struct tagINT_DOUBLY_LIST
{
	struct tagINT_DOUBLY_LIST	*pPrev;
	int				Data;
	struct tagINT_DOUBLY_LIST	*pNext;

} INT_DOUBLY_LIST, *P_int_DOUBLY_LIST;


/////////////////////////////////////////////////////////////////////
//	C L A S S E S.
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
//	E X T E R N  V A R I A B L E S.
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
//	P R O T O T Y P E S.
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
	int *pNodeData,
	INT_DOUBLY_LIST **ppListHead,
	INT_DOUBLY_LIST **ppListTail
	);

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
	);


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
	);

void DisplayList(INT_DOUBLY_LIST *pListHead);
int FindNthElementFromLast(INT_DOUBLY_LIST *pListHead, int n);

int RemoveFromList(int data, INT_DOUBLY_LIST **ppListHead,	INT_DOUBLY_LIST **ppListTail);

#endif	//_DLL_H_
