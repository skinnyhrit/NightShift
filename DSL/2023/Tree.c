#include<stdlib.h>
#include<stdio.h>


struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* listToBinaryTree(struct Node*,int idx, int[], int);
void printInOrder(struct Node*);
struct Node* root;

int main()
{
	int arr[] = {1, 2, 3, 4, 5};	
	root = (struct Node*) malloc(sizeof(struct Node));
	root->data = arr[0];
	root->left = NULL;
	root->right = NULL;
	//root->left = listToBinaryTree(root,1, arr,2);
	root->right = listToBinaryTree(root,2, arr,2);
	//printInOrder(root);	
	return 0;

}

struct Node* listToBinaryTree(struct Node* parent,int idx, int arr[], int height)
{
	
	if(idx >= 5)
	{
		return NULL;                                          
	}	

	printf("%d\t", idx);
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = arr[idx];
	temp->left = listToBinaryTree(temp, idx + height , arr, height+1);
	temp->right = listToBinaryTree(temp, idx + 1 + height, arr, height+1);	
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

