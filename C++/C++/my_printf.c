#include <stdio.h>
#include <stdarg.h>

int
my_printf(const char *fmt, ...)
{
  int i;
  char *str;
  va_list argp;
  va_start(argp, fmt);
  while (*fmt)
  {
        if (*fmt == '%')
	{
	  fmt++;
          switch(*fmt)
 	  {
	   case 'd':
	     i = va_arg(argp, int);
	     printf("%d", i);
	     break;
	   case 's':
	     str = va_arg(argp, char*);
	     printf("%s", str);
	     break;
	  }
	}

        printf("%c", *fmt);
	fmt++;
  }
  
  va_end(argp);
}

int main()
{
   int i = 5, j =9;
   char str[] = "asdfsdf";
   my_printf("Hiii%d", i);
   my_printf("%d, %d", i, j);
   my_printf("%s ", str);
}
