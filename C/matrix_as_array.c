#include <stdio.h>
#include <malloc.h>

void malloc2dint(int *** array, int m, int n)
{
  int i;
  int *p = (int*)calloc(m*n, sizeof(int));
  if (NULL == p)
   return;

  *array = (int**)malloc(sizeof(int*) * m);
  if (NULL == *array)
  {
    free (p);
    return;
  }

  for (i = 0; i < m; ++i)
   (*array)[i] = &(p[i * n]);
}

int main()
{
  int ** mat = NULL;
  malloc2dint(&mat, 5, 5);
  mat[0][0] = 1;
  mat[1][0] = 2;
  mat[2][0] = 3;
  mat[3][0] = 4;
  mat[4][0] = 6;
  int *element = &mat[0][0];
  int cnt = 0;

  while (cnt < 25)
  {
    printf("%d\n",*element);
    element++;
    cnt++;
  }
  return 0;
}
