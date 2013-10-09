#include <stdio.h>


unsigned char a [] = {0x0a,0x0b,0x0c,0x0d};

int main()
{
  unsigned int r = 0;
  int i;
  int shift = 0x000000ff;

  for (i = 0; i < 4; ++i)
  {
    //r <<= 8;
    
    r |= (shift & a[i]);

    shift <<= 8;
  }

  for (i = 0; i < 4; ++i)
  printf("r = %02X\n", (*((unsigned char*)&r) + i));

}
