#include<stdio.h>
#include<stdlib.h>

int main()
{
	char arr[2][3] = {"xxx",
			  "xx2"};

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
