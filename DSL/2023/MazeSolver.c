#include<stdio.h>
#include<stdlib.h>

struct Point{
	int row;
	int coloumn;
};

int TraverseMaze(struct Point,struct Point, struct Point, char, char[6][12], int[6][12]);

int main()
{
	char arr[6][12] = {
        			"xxxxxxxxxx x",
        			"x        x x",
        			"x        x x",
        			"x xxxxxxxx x",
        			"x          x",
        			"x xxxxxxxxxx",
			};

	int visitedArr[6][12];

	for(int i=0;i<6;i++)
	{
		for(int j=0;j<12;j++)
		{
			visitedArr[i][j] = 0;
		}
	}

	int rows = 6;
	int columns = 12;
	struct Point start = {5,1};
	struct Point end = {0,10};
	struct Point curr = {4,1};
	char wall = '#';

	TraverseMaze(start,end,curr,wall,arr);	
	return 0;
}

int TraverseMaze(struct Point start, struct Point end, struct Point curr, char wall, char arr[6][12], int vistedArr[6][12])
{
	if((curr.row == end.row && curr.coloumn == end.coloumn))
	{
		return 1;
	}

	if(arr[curr.row][curr.coloumn] == wall)
	{
		return 0;
	}	

	if(visitedArr[curr.row][curr.coloumn] == 1)
	{
		return 0;
	}	
		
	return 0;
}
