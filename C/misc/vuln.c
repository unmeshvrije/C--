#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char buf[512];

  if (argc > 1)
    strcpy(buf, argv[1]);

  printf("<%p>Len = %d\nbuf = %s\n", buf, strlen(buf),buf);
  return 0;
}
