#include<stdio.h>
#include<stdlib.h>

struct Node {

	int value;
	struct Node* next;
};

void displayQueue(struct Node*, struct Node*);

int main()
{
	int ch;
	struct Node* head = NULL;
	struct Node* tail = NULL;
	while(1)
	{
		printf("Welcome to my Queue Program!!!\n");
		printf("Enter your choice\n");
		printf("1.Display your Queue\n");
		printf("2.Enqueue Operation\n");
		printf("3.Dequeue Operation\n");
		printf("4.Peek\n");
		printf("5.Exit\n");
		printf("Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	displayQueue(head, tail);
				break;
			case 2: printf("Performing Enqueue Operation\n");
				break;
			case 3: printf("Performing Dequeue Operation\n");
				break;
			case 4: printf("Getting peak value\n");
				break;
			case 5: exit(0);
				break;
			default: printf("Incorrect choice\n");	
		}

	}
	return 0;
}


void displayQueue(struct Node* head, struct Node* tail)
{
	struct Node* ptr = head;
	while(ptr != NULL)
	{
		printf("%d\t",ptr->value);
		ptr = ptr->next;
	}
}
