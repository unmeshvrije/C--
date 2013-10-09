#include <stdio.h>

/*
Problem:
Merge two arrays into second array (no separate output array)

N = 5
a[N]

M = 10
b[N+M]

b should have sorted output array


Trick: Start from the end of output array i.e. M + N -1
*/

void insertionSort(int a[], int n)
{
  int i,j,key;
  for (i = 1; i < n; ++i)
  {
    key = a[i];
    j = i-1;
    while (j >= 0 && a[j-1] > key)
    {
      a[j] = a[j-1];
      j--;
    }
    a[j+1] = key;
  }
}

void PrintArray(int a[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
   printf("%d%s", a[i], (i == n-1) ? "" : ", ");

  printf("\n");
}

int main()
{
  int i,j,key,index;
  int N = 5;
  int M = 3;

  int a[5] = {10,20,30,40,50};

  //int b[15] = {5,13,18,25,30,31,41,47,49,51};//
  int b[8] = {5,13,51};//

  PrintArray(a, N);
  PrintArray(b, M+N);

  index = 0;
  for (i = M; i < M+N; ++i)
    b[i] = a[index++];

  /* Modified insertion sort*/
  for (i = M; i < M+N; ++i)
  {
    key = b[i];
    j  = i-1;
    while(j >= 0 && b[j] > key)
    {
      b[j+1] = b[j];
      j--;
    }
    b[j+1] = key;
  }

  PrintArray(b, M+N);

}
