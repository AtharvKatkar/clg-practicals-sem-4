// Write a C program that accepts the vertices and edges of a graph. Create adjacency list and
// display the adjacency list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node **adjacencyList, int source, int destination)
{
    Node *newNode = createNode(destination);

    newNode->next = adjacencyList[source];
    adjacencyList[source] = newNode;
}

void displayAdjacencyList(Node **adjacencyList, int numVertices)
{
    for (int i = 0; i < numVertices; i++)
    {
        printf("%d: ", i);
        Node *temp = adjacencyList[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Node **adjacencyList = (Node **)malloc(numVertices * sizeof(Node *));
    for (int i = 0; i < numVertices; i++)
    {
        adjacencyList[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++)
    {
        int source, destination;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(adjacencyList, source, destination);
    }

    printf("Adjacency List:\n");
    displayAdjacencyList(adjacencyList, numVertices);

    for (int i = 0; i < numVertices; i++)
    {
        Node *temp = adjacencyList[i];
        while (temp != NULL)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(adjacencyList);

    return 0;
}
