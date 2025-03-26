//Write a C program which uses Binary search tree library and implements following function with recursion: int compare(T1, T2) – compares two binary search trees and returns 1 if they are equal and 0

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int compare(struct Node* T1, struct Node* T2) {
    if (T1 == NULL && T2 == NULL) return 1;
    if (T1 == NULL || T2 == NULL) return 0;
    return (T1->data == T2->data) && compare(T1->left, T2->left) && compare(T1->right, T2->right);
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    
    root1 = insert(root1, 50);
    insert(root1, 30);
    insert(root1, 70);
    
    root2 = insert(root2, 50);
    insert(root2, 30);
    insert(root2, 70);
    
    if (compare(root1, root2))
        printf("The BSTs are equal.\n");
    else
        printf("The BSTs are not equal.\n");
    
    return 0;
}

