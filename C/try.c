#include <stdio.h>


unsigned char a [] = {0x0a,0x0b,0x0c,0x0d};

int main()
{
  unsigned char p[4];
  *((unsigned int*) &p[0]) = *((unsigned int*)(&a[0]));

  printf("%x %x %x %x\n",(unsigned int)p[0],(unsigned int) p[1], (unsigned int )p[2], (unsigned int )p[3]);
}
