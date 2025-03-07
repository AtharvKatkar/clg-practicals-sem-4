// Implement a Binary search tree (BST) library (btree.h) with operations – create, preorder. Write a
// menu driven program that performs the above operations.

#include <stdio.h>
#include "btree19.h"

void main()
{
    int ch;
    Node *root = NULL;

    while (1)
    {
        printf("\nSelect one\n\n1) Create BST\n2) Preorder\n3) Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            root = createBST();
            printf("\nBST created! Select preorder to view your BST\n");
            break;
        case 2:
            if (root == NULL)
            {
                printf("No BST found\n");
                return;
            }
            printf("Preorder BST\n");
            preorder(root);
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
