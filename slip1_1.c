//  Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, inorder.
//  Write a menu driven program that performs the above operations.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} Node;

Node *createNode(int data)
{
    Node *nn = malloc(sizeof(Node));
    nn->data = data;
    return nn;
}

void insert(Node *root, int data)
{
}

void main()
{
}