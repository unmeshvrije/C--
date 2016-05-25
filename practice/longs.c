#include<stdio.h>
#include<limits.h>

int main(void)
{
  int a =1;
  long i = (long)a - LONG_MIN;
  printf("i = %ld \n", i);
  a = 5;
  i =(long)a - LONG_MIN; 
  printf("i = %ld \n", i);
  return 0;
}
