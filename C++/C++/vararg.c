#include <stdio.h>
#include <stdarg.h>

int f(int a, ...)
{
  va_list arg;
  va_start(arg, a);

  va_arg(arg, char*);
  

  va_end(arg); 
  return 0;
}

int main()
{
   f(0);
   f(1,5);
   f(2,"asdf",4);
   f(3,4.565f,6,"abc");
   f(4,'A',67.4, 0x80);
   return 0;
}
