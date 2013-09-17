#include <stdio.h>
#include <math.h>

typedef union
{
  float f;
  int i;
}Tweak;

int
main()
{
  int i;
  Tweak t;
  //t.f = 9.625;
  printf("\n\tEnter float number : "); 
  scanf("%f", &t.f);
  //= -3.3f;
  int mask = 1;
  
  //printf("n = %f, n (e) = %e, n (g) = %g\n,",n, n, n);

  for (i = 31; i >= 0; i--)
  {
    mask = 1 << i;
    
    if ((mask & t.i) != 0)
      printf("1");
    else
      printf("0");

   if (31 == i || 23 == i )
 	printf(" ");
  }  

  printf("\n");

  return 0;
}
