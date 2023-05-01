#include<stdio.h>
#include<stdbool.h>
bool BinarySearch(int arr[], int key,int low, int high);
int main()
{
    printf("Binary Search\n");
    int arr[5] = {1,2,3,4,5};
    printf("Enter a number to search in array 1,2,3,4,5\n");
    int key;
    scanf("%d",&key);
    
    bool a = BinarySearch(arr,key,0,5);
    printf("Exists: %s", a?"true":"false" );
    return 0;
}

bool BinarySearch(int arr[], int key,int low, int high)
{
    
    do
    {
        int m = low + ((high-low)/2); 
        int middleElement = arr[m];
        if(key == middleElement)
        {
            return true;
        }
        else if (key > middleElement)
        {
            low = m+1;
        }
        else
        {
            high = m;
        }
        printf("%d - %d\n", low,high);
        
    } while (low<high);
    
    return false;
} 
