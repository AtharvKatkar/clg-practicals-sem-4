#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node *createNode(int data){
	Node *nn=(Node *)malloc(sizeof(Node));
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}

Node* createBST(){
	int data;

	printf("Enter data (Enter -1 to exit):");
	scanf("%d", &data);
	
	if(data == -1){
		return NULL;
	}
	
	Node *nn=createNode(data);
	nn->left=createBST();
	nn->right=createBST();
	return nn;
}

void preorder(Node *root){
	if(root==NULL){
		return;
	}
	
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void search(Node *root,int data){
	if(root == NULL){
		return;
	}
	
	if(root->data==data){
		printf("Key found in tree \n");
	}
	
	search(root->left, data);
	search(root->right, data);
}
