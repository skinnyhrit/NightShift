#include<stdio.h>

void BubbleSort(int*);

int main()
{
    int arr[5] = {6,2,3,1,5};
    BubbleSort(arr);    
    return 0;
}

void BubbleSort(int* arr)
{
    
    for(int i=0;i<5;i++)
    {
       for(int j=0;j<5-1-i;j++)
       {
         if(arr[j] > arr[j+1])
         {
            int swap = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = swap;
         }
       }
       for(int j=0;j<5;j++)
       {
            printf("%d\t",arr[j]);
       }
       printf("\n");
    } 
    
}
