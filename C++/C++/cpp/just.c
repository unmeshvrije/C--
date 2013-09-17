#include<stdio.h>



int i;

f()
{
  static int i;
  i++;
  printf("%d,",i);
}


main()
{
  f();
  f();
  f();
  f();
  f();
}
