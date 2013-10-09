#include <stdio.h>

int fun(int *a)
{
  a[3] = 1;
  a[6] = 1;
}

void print_array(int *p, int n)
{
  int i;
  for (i = 0; i < n; ++ i)
    printf("%d\n",p[i]);
}

int main()
{
  int *a = (int*)calloc(10, sizeof(int));

  fun(a);
  print_array(a, 10);
  free(a);

  int b = "abcdefghijklmnopqrstuvwxyz"[3];
  printf("b= %d\n", b);
  return 0;
}
