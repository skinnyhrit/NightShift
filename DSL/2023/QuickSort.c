#include<stdio.h>
#include<stdlib.h>

void quicksort(int*,int,int);
int partition(int*,int,int);
int main()
{
	int arr[11] = {-5, -6, -7, 0, 0, 0, 0, -8, 1, 2, 3};
	quicksort(arr,0,10);
	for(int i=0;i<11;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}


void quicksort(int* arr, int lo, int hi)
{
	if(lo >= hi)
	{
		return;
	}

	int pivot = partition(arr, lo, hi);
	quicksort(arr,lo,pivot-1);
	quicksort(arr,pivot+1,hi);

		
}

int partition(int* arr, int lo, int hi)
{
	int pivot = hi;
	hi = hi - 1;
	int idx = lo;

	for(int i=lo;i<=hi;i++)
	{
		if(arr[i] < arr[pivot])
		{
			int temp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = temp;
			idx = idx+1;
		}
	}

	int temp = arr[idx];
	arr[idx] = arr[pivot];
	arr[pivot] = temp;
	return idx;	
}
