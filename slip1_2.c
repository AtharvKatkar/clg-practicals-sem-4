// Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency
// matrix. Display the adjacency matrix. Implement functions to print indegree of all vertices of graph.

#include <stdio.h>

void calcIndegree(int v, int m[v][v])
{
    int in[v];
    int count = 0;

    for (int i = 0; i < v; i++)
    {
        in[i] = 0;
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (m[j][i] == 1)
            {
                count = count + 1;
            }
        }
        in[i] = count;
        count = 0;
    }

    printf("\nThe indegrees of all vertices are\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d: %d\n", i, in[i]);
    }
}

void main()
{
    int v;
    printf("Enter total vertices of graph: ");
    scanf("%d", &v);

    int m[v][v], data;

    printf("Enter 1 if edge is present or 0 if not: \n\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("Is edge present between %d -> %d: ", i, j);
            scanf("%d", &data);
            m[i][j] = data;
        }
    }

    printf("\n\nThe entered Adjaceny matrix is\n\n");
    for (int i = 0; i < v; i++)
    {
        printf("|\t");
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("|\n");
    }

    calcIndegree(v, m);
}