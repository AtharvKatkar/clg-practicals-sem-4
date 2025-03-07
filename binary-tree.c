#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create(int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

void printMenu()
{
    printf("Select your choice \n\n1) Insert Node\n2) Search Tree\n\nEnter your selection: ");
}

int main()
{
    int ch;
    int data;
    Node *root = NULL;
    while (1)
    {
        printMenu();
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter value to be searched: ");
            scanf("%d", &data);
            Node *found = search(root, data);
            if (found == NULL)
            {
                printf("No search found");
            }
            else
            {
                printf("Search found for %d", found->data);
            }
            break;
        default:
            printf("Invalid selection");
            break;
        }
    }
    return 0;
}