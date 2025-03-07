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
        printf("\nSelect one\n\n1) Create BST\n2) Preorder\n3) Search item\n4) Exit\n");
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
            printf("Enter key to search: \n");
            int srcKey;
            scanf("%d", &srcKey);
            int srcOut = search(root, srcKey);
            if (srcOut == 1)
            {
                printf("Key found \n");
            }
            else
            {
                printf("Key not found\n");
            }
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
