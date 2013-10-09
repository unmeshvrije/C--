#include<stdio.h>

#define MAX_SIZE 50

#define DBUG(msg)	printf("DEBUG: %s\n", msg);

void swap(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;

  return;
}


// builds min heap
void minheapify( int array[], int start, int size)
{
	int i, parent, count=0;
	
	for (i=size-1; i > start ; i--)
	{
		parent = (i-1)/2;
		if (parent < 0)
			break;
	
		if (array[i] < array[parent])
		{
			swap(array+i, array+parent);
		}
		count++;
	}
	printf("\tMIN heapify loop count: %d\n", count);
}

// builds max heap
void heapify( int array[], int start, int size)
{
	int i, parent, count=0;
	
	for (i=size-1; i > start ; i--)
	{
		parent = (i-1)/2;
		if (parent < 0)
			break;
	
		if (array[i] > array[parent])
		{
			swap(array+i, array+parent);
		}
		count++;
	}
	printf("\tHeapify loop count: %d\n", count);
}

void display(int arr[], int size)
{
  int i;

  for(i=0;i<size;i++)
	printf("%d ", arr[i]);
 
  printf("\n\n");
}

int main()
{
  int arr[MAX_SIZE], size, i;

  printf("Enter size of the array...\n");
  scanf("%d", &size);

  printf("Enter the array of integers...\n");

  for(i=0;i<size;i++)
	scanf("%d", &arr[i]);
  
  printf("Input array is:\n");
  display(arr, size);


 //ascending order
 for (i = 0; i < size; i++)
 {
	heapify(arr, 0, size-i);
	swap(arr+0, arr+(size-i-1));
 }
 printf("\nAscending order:\n");
 display(arr, size);

 //descending order
 for (i = 0; i < size; i++)
 {
	minheapify(arr, 0, size-i);
	swap(arr+0, arr+(size-i-1));
 }
 printf("\nDescending order:\n");
 display(arr, size);

 return 0;
}
