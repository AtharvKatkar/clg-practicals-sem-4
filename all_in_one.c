#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    nn->left = nn->right = NULL;
    return nn;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data > root->data)
        root->right = insert(root->right, data);
    if (data < root->data)
        root->left = insert(root->left, data);
    return root;
}

int count(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

bool search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }

    bool left_found = search(root->left, data);
    if (left_found)
    {
        return true;
    }

    bool right_found = search(root->right, data);
    return right_found;
}

void main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Preorder \n");
    preorder(root);
    printf("\n");

    printf("Inorder \n");
    inorder(root);
    printf("\n");

    printf("Postorder \n");
    postorder(root);
    printf("\n");

    bool searchRes1 = search(root, 10);
    bool searchRes2 = search(root, 30);

    printf("Search 10 and 30 in tree \n");
    if (searchRes1 == true)
        printf("10 found in tree \n");
    else
        printf("10 not found in tree \n");

    if (searchRes2 == true)
        printf("30 found in tree \n");
    else
        printf("30 not found in tree \n");

    printf("Count total nodes in tree \n");
    printf("Total node = %d", count(root));
}