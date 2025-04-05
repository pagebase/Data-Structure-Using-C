#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vertex;
    int edges;
    int source;
    int destination;
    int adj[50][50];
    printf("Enter total vertices: ");
    scanf("%d", &vertex);
    printf("Enter total edges: ");
    scanf("%d", &edges);
    for (int i = 1; i <= edges; i++)
    {
        printf("Enter %d edge\n", i);
        printf("Enter source vertex: ");
        scanf("%d", &source);
        printf("Enter destiination vertex: ");
        scanf("%d", &destination);

        if (source > vertex || destination > vertex || source <= 0 || destination <= 0)
        {
            printf("Invalid edges\n");
        }
        else
        {
            adj[source][destination] = adj[destination][source] = 1;
        }
    }

    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j < vertex; j++)
        {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}