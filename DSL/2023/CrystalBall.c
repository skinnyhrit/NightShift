#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main()
{
    int arr[5] = {0,0,0,0,1};
    int jumpDistance = sqrt(5);
    
    int indexAtWhichFirstBallFalls;    
    //first ball
    for(int i=0;i<5;i=i+jumpDistance)
    {
        if(arr[i] == 1)
        {
            indexAtWhichFirstBallFalls = i;
            break;
        }
    }

    int indexAtWhichSecondBallFalls;
    //second ball
    for(int j=indexAtWhichFirstBallFalls-jumpDistance;j<5 && j <=indexAtWhichFirstBallFalls;j++)
    {
        printf("j = %d\n",j);
        printf("indexAtWhichFirstBallFalls = %d\n",indexAtWhichFirstBallFalls);
        if(arr[j] == 1)
        {
            printf("second ball breaks at index %d\n", j);
            indexAtWhichSecondBallFalls = j;
            break;
        }
    }

}