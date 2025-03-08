// Write a C program that accepts the vertices and edges of a graph. Create adjacency list and
// display the adjacency list.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node *createNode(int data){
	Node *nn=(Node *)malloc(sizeof(Node));
	nn->data=data;
	nn->next=NULL;
	return nn;
}

void attachNodes(Node *current, Node *next){
	Node *temp=current;
	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	temp->next=next;
}

void printLinkedList(Node *root){
	Node *temp=root;
	
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp=temp->next;
	}
}

void main(){
	int v, data;
	printf("Enter total count of vertices \n");
	scanf("%d", &v);
	
	int m[v][v];
	
	printf("Enter adjacency matix: \n");
	printf("Enter 1 for edge present and 0 for not present\n\n");
	
	for (int i=0; i<v; i++){
		for (int j=0; j<v;j++){
			printf("Is edge present between %d -> %d: ", i, j);
			scanf("%d", &data);
			m[i][j]=data;
		}
	}
	
	printf("Adjacency matrix entered: \n");
	for (int i=0; i<v; i++){
		for (int j=0; j<v;j++){
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	
	printf("Adjacency list: \n");
	
	Node *list[v];
	
	for (int i=0; i<v; i++){
		Node *ln=createNode(i);
		list[i]=ln;
	}
	
	// Debug block
	/* for (int i=0; i<v; i++){
		printf("%d ->", list[i]->data);
		printf("\n");
	} */
	
	for (int i=0; i<v; i++){
		for (int j=0; j<v;j++){
			if(m[i][j]==1){
				Node *ln=createNode(j);
				attachNodes(list[i], ln);
			}
		}
	}
	
	for (int i=0; i<v; i++){
		printLinkedList(list[i]);
		printf("\n");
	}
}
