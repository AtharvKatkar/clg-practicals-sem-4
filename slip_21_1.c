/*
C program to implement graph traversal method using depth first search.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int num_vertices;

void dfs(int start_vertex)
{
    visited[start_vertex] = 1;
    printf("%d ", start_vertex);

    for (int i = 0; i < num_vertices; i++)
    {
        if (graph[start_vertex][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < num_vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Depth-First Traversal: ");
    for (i = 0; i < num_vertices; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    printf("\n");

    return 0;
}
