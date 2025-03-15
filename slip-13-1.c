// Write a C program which uses Binary search tree library and implements following function with recursion: int compare(T1, T2) – compares two binary search trees and returns 1 if they are equal and 0 otherwise.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node *create(int data){
	Node *nn = (Node *)malloc(sizeof(Node));
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}

Node *createBST(){
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	
	if(data == -1){
		return NULL;
	}
	
	Node *nn=create(data);
	nn->left=createBST();
	nn->right=createBST();
	
	return nn;
}

bool compare(Node *t1, Node *t2){
	if(t1 -> data == t2 -> data){
		return true;
	} else {
		return false;
	}
	
	return (compare(t1-> left, t2 -> left) && compare(t1 -> right, t2 -> right));
}

void main(){
	printf("Enter tree 1 \n");
	Node *t1=createBST();
	printf("\n\nEnter tree 2 \n");
	Node *t2=createBST();
	
	if(compare(t1, t2) == true){
		printf("Trees are identical \n");
	} else {
		printf("Trees are not identical");
	}
}


