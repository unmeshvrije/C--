#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>


int main()
{
   int sd;
   sd = socket(AF_INET, SOCK_STREAM, 0);
   if (-1 == sd)
   {
     return -1;
   }
   printf ("Socket created\n");

   close(sd);

   return 0;
}
