#include <stdio.h>

int main()
{
   int s = sizeof('x');
   char ch = 'x';
   printf("\nsizeof('x') = %d\n", s);
   printf("\nsizeof(ch) = %d\n", sizeof(ch));
   return 0;
}
