#include<stdio.h>
#include<stdlib.h>

void quicksort(int*,int,int,int);
int partition(int*,int,int);
int main()
{
	printf("hello world");
	int arr[5] = {6,2,1,3,4};
	quicksort(arr,0,3,4);
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

void partition(int* arr, int lo, int hi)
{
	
}
