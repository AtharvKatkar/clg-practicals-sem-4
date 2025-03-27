#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pre_cre.h"

void printMenu()
{
    printf("BST menu driven program ;) \n\n Menu:\n");
    printf("1) Insert data \n");
    printf("2) Preorder \n");
    printf("3) Exit \n\n");

    printf("Enter your choice: ");
}

void main()
{
    struct node *root = NULL;
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
            printf("preorder \n");
            preorder(root);
            printf("\n");
            break;

        case 3:
            exit(0);
        default:
            printf("!! Invalid choice selected !!");
        }
    }
}