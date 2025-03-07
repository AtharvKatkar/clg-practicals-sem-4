#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

Node *createBST()
{
    int data;
    printf("Enter data (Enter -1 to stop):\n");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    Node *root = createNode(data);
    root->left = createBST();
    root->right = createBST();
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}