#include "sort.h"

#define	ARRAY_SIZE(X)	(sizeof(X) / (sizeof((X)[0])))

int a[] = {4,57,36,234,34,6,6,52,4,56,98,4,4343,23};

int main()
{
  PrintArray(a, ARRAY_SIZE(a));
 // insertionSort(a, ARRAY_SIZE(a));
 // quickSort(a, 0, ARRAY_SIZE(a) -1);
 mergeSort(a, 0, ARRAY_SIZE(a)-1);
  PrintArray(a, ARRAY_SIZE(a));
  return 0;
}
