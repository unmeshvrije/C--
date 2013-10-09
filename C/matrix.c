#include <stdio.h>

int main()
{
  int mat[5][5] = {
  {1,2,3,4,5,},
  {11,2,3,4,5,},
  {12,2,3,4,5,},
  {13,2,3,4,5,},
  {14,2,3,4,5,},
  };
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
