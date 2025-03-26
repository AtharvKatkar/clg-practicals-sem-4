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

void printMenu()
{
    printf("BST menu driven program ;) \n\n Menu:\n");
    printf("1) Insert data \n");
    printf("2) Search tree \n");
    printf("3) Count total nodes \n");
    printf("4) Preorder \n");
    printf("5) Inorder \n");
    printf("6) Postorder \n");
    printf("7) Exit \n\n");

    printf("Enter your choice: ");
}

void main()
{
    Node *root = NULL;
    int ch, data;

    while (1)
    {
        printMenu();
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data you want to insert: ");
            scanf("%d", &data);
            if (root == NULL)
            {
                root = insert(root, data);
            }
            insert(root, data);
            printf("%d inserted to tree \n", data);
            break;
        case 2:
            printf("Enter data you want to search in tree: ");
            scanf("%d", &data);
            bool found = search(root, data);

            if (found)
                printf("%d found in the tree\n", data);
            else
                printf("%d not found\n", data);
            break;
        case 3:
            printf("There are %d total nodes", count(root));
            break;
        case 4:
            printf("Preorder \n");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Inorder \n");
            inorder(root);
            printf("\n");
            break;
        case 6:
            printf("Postorder \n");
            postorder(root);
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("!! Invalid choice selected !!");
        }
    }
}