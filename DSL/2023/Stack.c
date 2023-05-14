#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	struct Node* prev;
};

struct Node* top = NULL;

void display();
void push(int);
int pop();

int main()
{
	int ch;
	int value;
	while(1)
	{
		printf("\nWelcome to Stack in C\n");
		printf("1.Display Stack\n");
		printf("2.Push\n");
		printf("3.Pop\n");
		printf("4.Exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	display();
				break;
			case 2: printf("\nEnter value to push\n");
				scanf("%d",&value);
				push(value);
				break;
			case 3: value = pop();
				printf("\nPopped value is: %d\n",value);
				break;
			case 4:exit(0);
			default: printf("\nWrong choice\n");
		}
	}
	return 0;
}

void display()
{
	if(top == NULL)
	{
		printf("\nStack is empty!\n");
	}
	else
	{
		struct Node* current = top;
		while(current != NULL)
		{
			printf("%d\t",current->value);
			current = current->prev;
		}	
	}
}

void push(int value)
{
	struct Node* temp;
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->value = value;
	temp->prev = NULL;
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

int pop()
{
	if(top == NULL)
	{
		printf("\nStack is empty!!\n");
		return 0;
	}
	else
	{
		int value = top->value;
		struct Node* temp;
		temp = top;
		top = top->prev;
		free(temp);
		return value;
	}
}
