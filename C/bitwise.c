#include <stdio.h>


int CountOnes(int n)
{
  int count = 0;

  unsigned int mask = 0x08000000;

  while (mask)
  {
    if (mask & n)
      count++ ;
    mask >>= 1;
  }

  return count;
}

int main()
{
  int i = 0x0A0B0C0D;
  //int i = 4;

//  printf("Lowest bit is ", (i & ~(i - 1)) ? "NOT set" : "SET");

 printf("%d has %d 1's\n",i, CountOnes(i));

  return 0;
}
