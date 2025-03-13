// C program to implement graph traversal method using depth first search

#include <stdio.h>

int stack[10];
int top = -1;

int visited[10];
int vp = 0;

void push(int data)
{
    if (top < 10)
    {
        stack[top++] = data;
    }
    else
    {
        printf("Stack overflow!\n");
    }
}

int pop()
{
    if (top >= -1)
    {
        return stack[top--];
    }
    else
    {
        printf("Stack underflow \n");
        return -1;
    }
}

int checkInStack(int data)
{
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        if (stack[i] == data)
        {
            found = 1;
            break;
        }
    }
    return found;
}

int alreadyVisited(int data)
{
    int found = 0;
    for (int i = 0; i < vp; i++)
    {
        if (visited[i] == data)
        {
            found = 1;
            break;
        }
    }

    return found;
}

void printVisited()
{
    for (int i = 0; i < vp; i++)
    {
        printf("%d ", visited[i]);
    }
}

void pushVisisted(int data)
{
    visited[vp] = data;
    vp = vp + 1;
    printf("Visited array \n");
    printVisited();
}

void printStack()
{
    for (int i = top; i > -1; i--)
    {
        printf("%d ", stack[i]);
    }
}

void dfs(int v, int adj[v][v], int data)
{
    printf("Calling dfs for edge %d", data);
    if (checkInStack(data) == 0 && alreadyVisited(data) == 0)
    {
        printf("%d not found in stack and not visited pushing to stack\n", data);
        push(data);
        printf("Current stack \n");
        printStack();
    }
    else
    {
        int popedEdge = pop();
        printf("popped %d\n", popedEdge);
        if (popedEdge != -1)
        {
            printf("push %d to visited\n", popedEdge);
            pushVisisted(popedEdge);
            dfs(v, adj, data);
        }
    }
    printf("\n\n");
}

void main()
{
    int v, data;
    printf("Enter total vertices of matrix \n");
    scanf("%d", &v);

    int m[v][v];
    printf("Enter 1 is edge is present and 0 if not \n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("Is there any edge %d -> %d: ", i, j);
            scanf("%d", &data);
            m[i][j] = data;
        }
    }

    // calc adgency matrix
    int adj[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (m[i][j] == 1)
            {
                adj[i][j] = j;
            }
            else
            {
                adj[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        printf("%d: \t", i);
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] != -1)
            {
                printf("%d ", adj[i][j]);
            }
        }
        printf("\n");
    }

    // Call dfs function
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] != -1)
            {
                dfs(v, adj, adj[i][j]);
            }
        }
    }

    printVisited();
}