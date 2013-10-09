#include "xorll.h"

void appendXOR(int data, XOR_Node **ppHead, XOR_Node **ppTail)
{
  if (NULL == ppHead || NULL == ppTail)
    return;

  XOR_Node *newnode = (XOR_Node*) malloc(sizeof(XOR_Node));
  if (NULL == newnode)
    return;

  newnode->data = data;
  if (*ppHead == NULL && NULL == *ppTail)
  {
    newnode->link = (unsigned long) 0; // first node and only node
    *ppHead = *ppTail = newnode;
  }
  else
  {
    // Update TAIL's link as N ^=  NEW NODE's address
    (*ppTail)->link ^= (unsigned long)newnode;
    newnode->link = (unsigned long)(*ppTail);
    *ppTail = newnode;
  }
}

void displayXOR(XOR_Node *pHead)
{
  if (NULL == pHead)
    return;

  XOR_Node *nav = pHead;

  unsigned long cur = 0;
  while (1)
  {
    printf("%5d", nav->data);
    XOR_Node *NextNode = (XOR_Node*) (cur ^ nav->link);

    // XOR (n,n) = 0 (0 = NULL)
    if (NULL == NextNode)
      break;

    cur = (unsigned long) nav;
    nav = NextNode;
  }
}
