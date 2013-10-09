#include <stdio.h>

char str[]="abcdef\n";

int main()
{
  sscanf(str, "%s", str);
  printf("%s\n",str);
}
