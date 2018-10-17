#include <stdio.h>

void swap (int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int A[], int lo, int hi)
{
	int pivot = A[hi];
	int i = lo, j;
	for (j = lo; j <= hi - 1; j++)
	{
		if (A[j] < pivot)
		{
			if (i != j)
			{
				swap(&A[i], &A[j]);
			}
			i = i + 1;
		}
	}
	swap(&A[i], &A[hi]);
	return i;
}

void quicksort (int A[], int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition (A, lo, hi);
		quicksort(A, lo, p - 1);
		quicksort(A, p + 1, hi);
	}
}

int main ()
{
	int arr[10] = {6, 3, 1, 3, 9, 4, 5, 8, 1, 2};
	int lenarr = sizeof(arr)/sizeof(arr[0]), i;
	quicksort(arr, 0, lenarr - 1);
	for (i = 0; i < lenarr; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}