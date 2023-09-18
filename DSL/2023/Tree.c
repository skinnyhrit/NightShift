#include<stdlib.h>
#include<stdio.h>


struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct QNode
{
	struct Node* data;
	struct QNode* next;

};



void enqueue(struct Node*);
struct Node* dequeue();
struct QNode* head = NULL;
struct QNode* tail = NULL;
void displayQueue();

struct Node* listToBinaryTree(struct Node*,int idx, int[]);
void printInOrder(struct Node*);
void printPreOrder(struct Node*);
void printPostOrder(struct Node*);
void printBreadthFirst(struct Node*);
struct Node* root;

int main()
{
	

	int arr[] = {1, 2, 3, 4, 5};	
	root = listToBinaryTree(root, 0, arr);
	printf("In order : ");
	printInOrder(root);
	printf("\nPre order : ");
	printPreOrder(root);
	printf("\nPost order : ");
	printPostOrder(root);
	printf("\nBreadth first : ");
	printBreadthFirst(root);	
	return 0;

}

struct Node* listToBinaryTree(struct Node* parent,int idx, int arr[])
{
	
	if(idx >= 5)
	{
		return NULL;                                          
	}	

	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	
	temp->data = arr[idx];
	temp->left = listToBinaryTree(temp, (idx+(idx+1)), arr);
	temp->right = listToBinaryTree(temp, (idx+(idx+1)+1), arr);

	return temp;
		
}


void printInOrder(struct Node* temp)
{
	if(temp != NULL)
	{
		printInOrder(temp->left);
		printf("%d ", temp->data);
		printInOrder(temp->right);
		
	}
	
}

void printPreOrder(struct Node* temp)
{
	if(temp != NULL)
	{
		printf("%d ", temp->data);
		printPreOrder(temp->left);
		printPreOrder(temp->right);	
	}
}

void printPostOrder(struct Node* temp)
{
	if(temp != NULL)
	{
		printPostOrder(temp->left);
		printPostOrder(temp->right);
		printf("%d ",temp->data);
	}
}

void printBreadthFirst(struct Node* temp)
{

	enqueue(temp);
	struct Node* trav = dequeue();	

	while(trav != NULL)
	{
		enqueue(trav->left);
		enqueue(trav->right);
		printf("%d ",trav->data);
		trav = dequeue();	
	}
			
}

void enqueue(struct Node* data)
{
	struct QNode* temp = (struct QNode*) malloc(sizeof(struct QNode));
	temp->data = data;
	temp->next = NULL;	
	if(head == NULL && tail == NULL)
	{
		tail = temp;
		head = tail;
	}
	else
	{
		tail->next = temp;
		tail = temp;	
	}
}

struct Node* dequeue()
{
	if(head == NULL && tail == NULL)
	{
		return NULL;
	}
	else
	{
		struct Node* data = head->data;
		struct QNode* temp = head;
		if(head == tail)
		{
			tail = NULL;	
		}
		head = head->next;
		free(temp);
		return data;
	}
	
}

void displayQueue()
{
	if(head == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		struct QNode* trav = head;
		while(trav != NULL)
		{
			printf("%d ",trav->data->data);
			trav = trav->next;
		}
		printf("\n");
	}
}


