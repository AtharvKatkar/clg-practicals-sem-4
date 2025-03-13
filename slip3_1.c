// Implementation of static hash table with Linear Probing.

#include <stdio.h>

#define SIZE 5

int table[SIZE];

void insert(int data, int org)
{
    int key = data % SIZE;

    if (table[key] == -1)
    {
        table[key] = org;
    }
    else
    {
        int newData = data + 1;
        insert(newData, org);
    }
}

void main()
{
    int data;

    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
    }

    printf("Enter elements (-1 to stop) \n");

    while (1)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        else
        {
            insert(data, data);
        }
    }

    printf("\nThe final hash table \n");
    printf("|\tkey\t|\tvalue\t|\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("|\t%d\t|\t%d\t|\n", i, table[i]);
    }
}

/*
Expected output:
Enter elements (-1 to stop)
Enter element: 50
Enter element: 70
Enter element: 76
Enter element: 85
Enter element: 93
Enter element: -1

The final hash table
|       key     |       value   |
|       0       |       50      |
|       1       |       70      |
|       2       |       76      |
|       3       |       85      |
|       4       |       93      |
*/