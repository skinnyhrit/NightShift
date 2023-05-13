#include<stdio.h>
#include<stdlib.h>

struct Node {

	int value;
	struct Node* next;
};

void displayQueue();
void enqueue(int);
int dequeue();

struct Node* head = NULL;
struct Node* tail = NULL;
int main()
{
	int ch;
	int value;
	while(1)
	{
		printf("\nWelcome to my Queue Program!!!\n");
		printf("Enter your choice\n");
		printf("1.Display your Queue\n");
		printf("2.Enqueue Operation\n");
		printf("3.Dequeue Operation\n");
		printf("4.Exit\n");
		printf("Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	displayQueue();
				break;
			case 2: printf("\nEnter value to enqueue\n");
				scanf("%d",&value);	
				enqueue(value);
				break;
			case 3: value = dequeue();
				printf("\nDequeued value: %d\n",value);
				break;
			case 4: exit(0);

		}
	}
}

void displayQueue()
{
	if(head == NULL && tail == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		struct Node* ptr = head;
		while(ptr != NULL)
		{
			printf("%d\t",ptr->value);
			ptr = ptr->next;	
		}	
	}
}

void enqueue(int value)
{
	struct Node* temp;
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->value = value;
	temp->next = NULL;

	if(tail == NULL)
	{
		head = temp;
		tail = head;	
	}
	else
	{
		tail->next = temp;
		tail = temp;
			
	}

}

int dequeue()
{
	if(head == NULL)
	{
		printf("\nQueue is empty\n");
		return 0;
	}
	else
	{
		int value = head->value;
		struct Node* temp;
		temp = head;
		head = head->next;
		free(temp);
		if(head == NULL)
		{
			tail = NULL;
		}
		return value;		
	}
}



