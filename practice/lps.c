#include<stdio.h>
#include<string.h>
#include<malloc.h>
 
// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
  int i, j;
  int n = strlen(str);
  int **L = (int**)malloc(sizeof(int*) * n);
  for (i = 0; i < n; ++i) {
    L[i] = (int*)malloc(sizeof(int) * n);
    L[i][i] = 1;
  }

  for(j = 1; j < n; ++j) {
    for (i = j-1; i >=0; --i) {
      if (str[i] == str[j] && i == j-1) {
        L[i][j] = 2;
      } else if (str[i] == str[j]) {
        L[i][j] = L[i+1][j-1] + 2;
      } else {
        L[i][j] = max(L[i][j-1], L[i+1][j]);
      }
    }
  }

  for (i = 0; i < n; ++i) {
    printf("%3c ", str[i]);
  }
  printf("\n");

  for (i = 0; i < n; ++i) {
    int spaces = 0;
    while (spaces != i) {
      printf("    ");
      spaces++;
    }
    for (j = i; j<n; ++j ) {
      printf("%3d ", L[i][j]);
    }
    printf("\n");
  }

  int ret = L[0][n-1];
  for (i = 0; i < n; ++i) {
    free(L[i]);
  }
  free(L);

  return ret;
}
 
/* Driver program to test above functions */
int main()
{
    char seq[] = "BBABCBABACBAB";
    //char seq[] = "ABABCBABC";

    int n = strlen(seq);
    printf ("The length of the LPS is %d\n", lps(seq));
    return 0;
}
