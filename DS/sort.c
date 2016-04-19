#include "sort.h"

static void swap(int *pa, int *pb)
{
  int t = *pa;
  *pa = *pb;
  *pb = t;
}

static void swapArray(int a[], int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void insertionSort(int a[], int n)
{
  int i,j,key;
  for (i = 1; i < n; ++i)
  {
    key = a[i];
    j = i-1;
    while (j >= 0 && a[j] > key)
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
}

static int quickPartition(int a[], int p, int r)
{
  int x = a[p]; // pivote
  int i = p;
  int j = r;

  while (i < j)
  {
    while (a[i] <= x)
     i++;

    while (a[j] > x)
     j--;

    if (i < j)
      swapArray(a,i,j);
    //else
    //  return j;
  }

  a[p] = a[j];
  a[j] = x;
  return j;
}

void quickSort(int a[], int p, int r)
{
  int q;
  if (p < r)
  {
    q = quickPartition(a, p, r);
    quickSort(a, p, q-1); // (a,p,q) leads to seg fault due to infinite recursion
    quickSort(a, q+1, r);
  }
}

void merge(int a[], int p, int q, int r) {
  int nLeft  = q-p+1;
  int nRight = r-q;

  int *L = (int*)malloc(sizeof(int) * nLeft);
  int *R = (int*)malloc(sizeof(int) * nRight);
  memcpy(L, a+p, nLeft*sizeof(int));
  memcpy(R, a+q+1, nRight*sizeof(int));

  printf("Left: \n");
  PrintArray(L, nLeft);
  printf("Right: \n");
  PrintArray(R, nRight);

  int i = 0;
  int j = 0;
  int k = p;
  while (i < nLeft && j < nRight) {
    if (L[i] <= R[j]) {
      a[k++] = L[i++];
    } else {
      a[k++] = R[j++];
    }
  }

  while(i < nLeft) {
    a[k++] = L[i++];
  }

  while (j <nRight) {
    a[k++] = R[j++];
  }

  printf("After merge: \n");
  PrintArray(a, r-p+1);

  free(L);
  free(R);
}

void mergeSort(int a[], int p, int r) {
  if (p < r) {
    int q = floor((p+r)/2);
    printf("Calling MergetSort(%d, %d)\n", p, q);
    mergeSort(a, p, q);
    printf("Calling MergetSort(%d, %d)\n", q+1, r);
    mergeSort(a, q+1, r);

    printf("Calling merge(%d, %d, %d)\n ", p, q, r);
    merge(a, p, q, r);
    //PrintArray(a, r-p+1);
  }
}

void PrintArray(int a[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
   printf("%d%s", a[i], (i == n-1) ? "" : ", ");

  printf("\n");
}
