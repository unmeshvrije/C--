#include <stdio.h>

int main(
	int argc,
	char *argv[],
	char *envp[]
	)
{
   int cnt = 0;
   printf("\nargc = %d\n",argc);
   printf("\nargv[] = \n");
   while (cnt < argc)
   {
      printf("%s\n", argv[cnt++]);

   }
   printf("\n");

   cnt = 0;
   int size = 50;
   printf("\nPredicted size of envp = %d\n", size);
   while (cnt < size)
   {
      printf("\n%s\n",envp[cnt++]);
   }
   return 0;
}
