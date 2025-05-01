#include <stdio.h>
#define MAX 50
int mat[MAX][MAX];

int main()
{
    int source;
    int destination;
    int vertex;
    int edges;
    int weight;
    printf("Enter Total Vertex: ");
    scanf("%d", &vertex);
    printf("Enter Total Edges: ");
    scanf("%d", &edges);
    for (int i = 1; i <= edges; i++)
    {
        printf("Enter source vertx: ");
        scanf("%d", &source);
        printf("Enter destination vertex: ");
        scanf("%d", &destination);
        printf("Enter weight: ");
        scanf("%d", &weight);

        if (!(source > vertex || destination > vertex || source <= 0 || destination <= 0))
            mat[source][destination] = weight;
        else
        {
            i--;
        }
    }
    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}