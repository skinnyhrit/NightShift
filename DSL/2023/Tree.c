#include<stdlib.h>
#include<stdio.h>


struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* listToBinaryTree(struct Node*,int idx, int[]);
void printInOrder(struct Node*);
void printPreOrder(struct Node*);
void printPostOrder(struct Node*);
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
