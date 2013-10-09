#include "xorll.h"

int main()
{
  XOR_Node * head = NULL, *tail = NULL;

  appendXOR(1, &head, &tail);
  appendXOR(2, &head, &tail);
  appendXOR(3, &head, &tail);
  appendXOR(4, &head, &tail);

  displayXOR(head);

  return 0;
}
