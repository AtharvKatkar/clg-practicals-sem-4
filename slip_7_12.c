//Write a C program that accepts the vertices and edges of a graph and store it as an adjacency
//matrix. Implement function to traverse the graph using Depth First Search (DFS) traversal


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX], vertices;

void initGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void addEdge(int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initGraph();
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }
    
    printf("DFS Traversal: ");
    DFS(0);
    
    return 0;
}

