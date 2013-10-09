#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct XOR_Node
{
  int data;
  unsigned long link;

} XOR_Node;

void appendXOR(int data, XOR_Node **head, XOR_Node**tail);
void displayXOR(XOR_Node *head);
