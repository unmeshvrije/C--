#include <stdio.h>

int main()
{
  int i = 5;  
  int j = 6;
  int *p = &i;
  int *q = &j;

  printf("\n*p = %d, *q = %d\n", 
  *p, *q);

  int *t = p;
  p = q;
  q = t;

  printf("\n*p = %d, *q = %d\n", 
  *p, *q);
   return 0;
}
