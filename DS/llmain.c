#include "ll.h"

#define	ARRAY_SIZE(X)	(sizeof(X) / sizeof((X)[0]))
int main()
{
  int i;
  INT_LIST *head = NULL, *tail = NULL;

  int a[] = {1,2,3,4,5,6,7,8,9,10};

  for (i = 0; i < ARRAY_SIZE(a); ++i)
  AddToList(&a[i], &head, &tail);

  DisplayList(head); 

  for (i = 1; i <= ARRAY_SIZE(a); ++i)
    printf ("%dth element from last = %d\n", i, FindNthElementFromLast(head, i));


    printf ("%dth element from last = %d\n", 11, FindNthElementFromLast(head, 11));
    printf ("%dth element from last = %d\n", 0, FindNthElementFromLast(head, 0));

  return 0;
}
