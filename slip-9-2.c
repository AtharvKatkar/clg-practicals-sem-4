// C program to implement BST to perform following operations on BST-

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node *createNode(int data){
	Node *tree = (Node *)malloc(sizeof(Node));
	tree->data=data;
	tree->left=NULL;
	tree->right=NULL;
	
	return tree;
}

Node *createBST(){
	int data;
	printf("Enter data to insert (-1 to exit): ");
	scanf("%d", &data);
	
	if (data == -1){
		return NULL;
	}
	
	Node *nn=createNode(data);
	nn->left=createBST();
	nn->right=createBST();
	
	return nn;
}

int countLeaf(Node *tree){
	if(tree==NULL){
		return 1;
	}

	if(tree->left == NULL && tree->right == NULL){
		return 0;
	}
	
	return (countLeaf(tree->left) + countLeaf(tree->right));
}

int countNonLeaf(Node *tree){
	if(tree==NULL){
		return 0;
	}

	if(tree->left == NULL && tree->right == NULL){
		return 1;
	}
	
	return (countNonLeaf(tree->left) + countNonLeaf(tree->right));
}

void preorder(Node *root){
	if(root==NULL){
		return;
	}
	
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void main(){
	Node *tree=createBST();
	int leafCount = countLeaf(tree);
	int nonLeafCount = countNonLeaf(tree);
	
	preorder(tree);
	printf("\nTotal leaf nodes = %d\n", leafCount);
	printf("\nTotal non leaf nodes = %d\n", nonLeafCount);
}
