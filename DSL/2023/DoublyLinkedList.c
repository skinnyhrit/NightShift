#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head=NULL;
struct Node* tail=NULL;
int length = 0;

void insertAtBegining(int);
void insertAtEnd(int);
void insertAtPosition(int,int);
void Display();
int removeData(int);
int removeAt(int);
int get(int);

int main()
{
	int ch;
	int data;
	while(1)
	{
		printf("Welcom to Doubly Linked List!!\n");
		printf("\n1.Insert at begining");
		printf("\n2.Insert at end");
		printf("\n3.Dipslay");
		printf("\n4.Insert at Position");
		printf("\n5.Delete data");
		printf("\n6.Remove at Position");
		printf("\n7.Get from Position");
		printf("\n8.Exit");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	printf("Enter data to insert\n");
				scanf("%d",&data);
				insertAtBegining(data);
				break;
			case 2: printf("Enter data to insert\n");
				scanf("%d",&data);
				insertAtEnd(data);
				break;
			case 3: Display();
				break;
			case 4: printf("Enter data to insert\n");
				scanf("%d",&data);
				printf("Enter position\n");
				int position;
				scanf("%d",&position);
				insertAtPosition(position,data);
				break;
			case 5: printf("Enter data to remove\n");
				scanf("%d",&data);
				int removedData = removeData(data);
				printf("Data removed = %d\n",removedData);
				break;
			case 6: printf("Remove at position: Enter position\n");
				scanf("%d",&data);
				int removedDataAt = removeAt(data);
				printf("Data removed = %d\n",removedDataAt);
				break;
			case 7: printf("Get from position: Enter position\n");
				scanf("%d",&data);
				int gotData = get(data);
				printf("Data got = %d\n",gotData);
				break;
			case 8:	exit(0);
			
			default: printf("Wrong choice\n");
		}
	}	
	return 0;
}

void insertAtBegining(int data)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if(length == 0)
	{
		head = temp;
		head->next = NULL;
		head->prev = NULL;
		tail = head;	
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	length++;
	
}

void insertAtEnd(int data)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if(length == 0)
	{
		head = temp;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	length++;
}

void insertAtPosition(int pos, int data)
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if(length == 0 || pos == 0)
	{
		insertAtBegining(data);
	}
	else if(pos == length)
	{
		insertAtEnd(data);
	}
	else if(pos > length)
	{
		printf("Index out of range\n");
	}
	else
	{
		int idx = 1;
		struct Node* trav = head;
		while(idx < pos)
		{
			trav = trav->next;
			idx++;
		}

		temp->next = trav;
		temp->prev = trav->prev;
		trav->prev->next = temp;
		trav->next->prev = temp;
		length++;
	}

}

int removeData(int data)
{
	struct Node* trav = head;
	while(trav!=NULL)
	{
		if(trav->data == data)
		{
			if(trav->prev == NULL && trav->next == NULL)
			{
				head = NULL;
				tail = NULL;
				free(trav);
			}
			else if(trav->next == NULL)
			{
				trav->prev->next = NULL;
				tail = trav->prev;
				trav->prev = NULL;
				free(trav);
			}
			else if(trav->prev == NULL)
			{
				head = trav->next;
				trav->next->prev = NULL;
				trav->next = NULL;
				free(trav);	
			}
			else
			{
				trav->prev->next = trav->next;
				trav->next->prev = trav->prev;
				trav->next = NULL;
				trav->next = NULL;
				free(trav);
			}
			length--;
			return data;
		}
		trav = trav->next;
	}
	
		
	return 0;
}

int removeAt(int pos)
{
	if(length == 0 || pos>length)
	{

		printf("List is empty or pos is out of range\n");
	}
	else if(length == 1)
	{
		int data = head->data;
		struct Node* temp = head;
		head = NULL;
		tail = NULL;
		free(temp);
		length--;
		return data;

	}
	else if(pos == 1)
	{
		int data = head->data;
		struct Node* temp = head;
		head->next->prev = NULL;
		head = head->next;
		temp->next = NULL;
		free(temp);		
		length--;	
		return data;
	}
	else if(pos == length)
	{
		int data = tail->data;
		struct Node* temp = tail;
		tail = tail->prev;
		temp->prev = NULL;
		tail->next = NULL;
		free(temp);
		length--;
		return data;
	}
	else
	{
		struct Node* trav = head;
		for(int i=0;i<pos-1;i++)
		{

			trav = trav->next;
		}

		struct Node* temp = trav;
		int data = temp->data;
		trav->prev->next = trav->next;
		trav->next->prev = trav->prev;
		trav->next = NULL;
		trav->prev = NULL;
		free(temp);
		length--;
		return data;
	}

	return 0;

}

int get(int pos)
{
	if(length == 0 || pos > length)
	{
		return 0;
	}
	else
	{
		struct Node* trav = head;
		for(int i=0;i<pos-1;i++)
		{
			trav = trav->next;
		}
		return trav->data;
	}
	
	return 0;

}

void Display()
{
	if(length != 0)
	{
		struct Node* temp = head;
		while(temp != NULL)
		{
			printf("%d\t",temp->data);
			temp = temp->next;	
		}
	}
}
