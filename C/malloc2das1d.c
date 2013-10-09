#include <stdio.h>
#include <malloc.h>

int malloc_int_2d(int ***pppMatrix, int m, int n)
{
	int i;

	int *p = (int*) calloc(m*n, sizeof(int));
	if (NULL == p)
		return -1;

	*pppMatrix = (int**)malloc(sizeof(int*) * m);
	if (NULL == *pppMatrix)
	{
		free (p);
		return -1;
	}

	for (i = 0; i < m; ++i)
		(*pppMatrix)[i] = p + (i*n);

	return 0;
}


int free_int_2d(int ***pppMatrix)
{
	free (&((*pppMatrix)[0][0])); // Free 1D array

	free (*pppMatrix);
}


void PrintAdjMat(int **ppAdjMat, int M, int N)
{
	int i,j;
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
			printf("%5d" , ppAdjMat[i][j]);

		printf("\n");
	}
}


int main()
{
	int **mat = NULL;
	malloc_int_2d(&mat, 3,3);
	PrintAdjMat(mat, 3,3);
	free_int_2d(&mat);
}
