#include<stdio.h>
#include<stdbool.h>
bool exists(int arr[], int n, int searchNumber);

int main()
{
    int arr[5] = {0,1,2,3,4};
    int n = 5;
    printf("Enter number to search \n");
    int searchNumber;
    scanf("%d",&n);
    bool a = exists(arr,n,searchNumber);
    printf("Exists: %d", a?"true":"false" );
    return 0;
}

bool exists(int arr[], int n, int searchNumber)
{
   for(int i=0;i<n;i++)
   {
       if (arr[i] == searchNumber)
       {
            return true;
       }
   }
   return false; 
}