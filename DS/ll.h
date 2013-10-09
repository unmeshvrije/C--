/*++

Module Name:
	ll.h.

Abstract:
	This module writes linked list functions.

Revision History:
	Date:	Oct 08 2012.
	Author:	Unmesh Joshi.
	Desc:	Created.

--*/


#ifndef	_LL_H_
#define	_LL_H_


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
typedef struct tagINT_LIST
{
	int			Data;
	struct tagINT_LIST	*pNext;

} INT_LIST, *P_int_LIST;


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
	INT_LIST **ppListHead,
	INT_LIST **ppListTail
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
	INT_LIST **ppListToBeAppended,
	INT_LIST **ppListHead,
	INT_LIST **ppListTail
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
	INT_LIST *pListHead
	);

void DisplayList(INT_LIST *pListHead);
int FindNthElementFromLast(INT_LIST *pListHead, int n);

int RemoveFromList(int data, INT_LIST **ppListHead,	INT_LIST **ppListTail);

#endif	//_LL_H_
