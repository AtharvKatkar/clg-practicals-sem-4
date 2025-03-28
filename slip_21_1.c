/*
C program to implement graph traversal method using depth first search.
*/

#include <stdio.h>
#include <limits.h>

int stack[100];
int pt = -1;

int dfs_order[];

void push(int node)
{
    stack[++pt] = node;
}

int pop()
{
    return stack[pt--];
}
int checkInStack(int data)
{
    for (int i = 0; i < pt; i++)
    {
        if (data == stack[i])
        {
            return 1;
        }
    }

    return 0;
}

int dfs_stack(int n, int adj_matrix[n][n])
{
    int visited[n];
    int dfs_index = 0;

    push(0);
    visited[0] = 1;

    while (pt != -1)
    {
        int current = pop();
        dfs_order[dfs_index++] = current;

        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            if (adj_matrix[current][neighbor] && !visited[neighbor])
            {
                push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }

    return dfs_index;
}

void main()
{
    int n;
    printf("Enter total vertices: ");
    scanf("%d", &n);

    int m[n][n];
    int visited[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }

    // dfs start
    int dfs_order_length = dfs_stack(n, m);
    printf("DFS Traversal Order: ");
    for (int i = 0; i < dfs_order_length; i++)
    {
        printf("%d ", dfs_order[i]);
    }
    printf("\n");
}