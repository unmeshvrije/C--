#include <stdio.h>

int main()
{
    char ch = 'x';
   int s = sizeof('x');
   printf("\nsizeof('x') = %d\n", s);
   printf("\nsizeof(ch) = %d\n", sizeof(ch));
   return 0;
}
