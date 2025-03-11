// Implementation of static hash table with Linear Probing.

#include <stdio.h>

#define SIZE 5

int table[SIZE];

void insert(int data)
{
    int hash = data % SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
        {
            table[i] = data;
        }
        else
        {
            for (int j = i; j < SIZE; j++)
            {
                printf("Collision occured probing for place %d", j);
                // Add code for linear probing
            }
        }
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
    }
}