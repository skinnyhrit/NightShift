#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Point{
	int row;
	int coloumn;
};

struct Node{
	struct Node* prev;
	struct Point point;
};

int TraverseMaze(struct Point,struct Point, struct Point, char, char[6][12], int[6][12]);
void push(struct Point);
struct Point pop();
void display();

struct Node* top = NULL;

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
	char wall = 'x';
		
	
	TraverseMaze(start,end,start,wall,arr,visitedArr);

	display();

	return 0;
}

int TraverseMaze(struct Point start, struct Point end, struct Point curr, char wall, char arr[6][12], int visitedArr[6][12])
{
	if(curr.row < 0 || curr.row >= 6 || curr.coloumn < 0 || curr.coloumn >=12)
	{
		return 0;
	}

	if((curr.row == end.row && curr.coloumn == end.coloumn))
	{
		push(curr);
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
	
		
	visitedArr[curr.row][curr.coloumn] = 1;
	
	push(curr);
	
	struct Point top  = curr;
	top.row = top.row - 1;
	int topResult = TraverseMaze(start, end, top, wall, arr, visitedArr);

	struct Point right = curr;
       	right.coloumn = right.coloumn + 1;
	int rightResult = TraverseMaze(start, end, right, wall, arr, visitedArr);

	struct Point bottom = curr;
        bottom.row = bottom.row + 1;
	int bottomResult = TraverseMaze(start, end, bottom, wall, arr, visitedArr);

	struct Point left = curr;
	left.coloumn = left.coloumn - 1;	
	int leftResult = TraverseMaze(start, end, left, wall, arr, visitedArr);

	if(topResult == 1 || rightResult == 1 || leftResult == 1 || rightResult == 1)
	{
		return 1;
	}

	pop();	

	return 0;
}


void push(struct Point point)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->prev = NULL;
	temp->point = point;
	if(top == NULL)
	{
		top = temp;	
	}
	else
	{
		temp->prev = top;
		top = temp;
	}
}

struct Point pop()
{
	if(top == NULL)
	{
		struct Point retPoint;
		return retPoint;
	}
	else
	{
		struct Node* temp = top;
		top = top->prev;
		
		struct Point retPoint = temp->point;	
		free(temp);

		return retPoint;
	}
	
}


void display()
{
	struct Node* temp = top;

	while(temp != NULL)
	{
		printf("%d - %d\n", temp->point.row, temp->point.coloumn);
		temp = temp->prev;
	}
}
