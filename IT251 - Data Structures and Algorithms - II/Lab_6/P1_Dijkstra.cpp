//Djistra implemented here in a brute force manner also prints path..assumes 1 to be the source vertex

#include<stdio.h>
#include<stdlib.h>
#define INF 35000
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    int *visited;
    struct Node** adj;
};

struct Node* createNode(int v, int weight)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->visited = (int*)malloc(sizeof(int) * vertices);
    graph->adj = (struct Node**)malloc(sizeof(struct Node*) * vertices);

    for(int i = 0; i < vertices; i++)
    {
        graph->adj[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

void printArr(int dist[], int n, int parent[])
{
    printf("Vertex   Distance from Source              Path\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d \t\t %d \t\t\t ", i+1, dist[i]);

        // Print path
        int j = i;
        while (j != -1)
        {
            printf("%d ", j+1);
            j = parent[j];
            if (j != -1)
                printf("-> ");
        }
        printf("\n");
    }
}

void dijkstra(struct Graph* graph, int start)
{
    int V = graph->numVertices;
    int dist[V];
    int parent[V];

    for (int v = 0; v < V; v++)
    {
        dist[v] = INF;
        parent[v] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int minDist = INF;
        int u;

        // Find the vertex with minimum distance value
        for (int v = 0; v < V; v++)
        {
            if (graph->visited[v] == 0 && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }

        graph->visited[u] = 1;

        struct Node* pCrawl = graph->adj[u];
        while (pCrawl)
        {
            int v = pCrawl->vertex;

            if (graph->visited[v] == 0 && dist[u] != INF && pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                parent[v] = u;
            }
            pCrawl = pCrawl->next;
        }
    }
    printArr(dist, V, parent);
}


int main()
{
    int V;
    std::cin>>V;
    struct Graph* graph=createGraph(V);

    for(int i=0;i<V;i++)
    {
        int a,b,c,d,e;
        char f,g;
        cin>>a>>b>>f>>c>>d>>g>>e;
        a--;
        b--;
        d--;
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;
        addEdge(graph,a,b,c);
        addEdge(graph,a,d,e);
    }
    dijkstra(graph,0);  //choosing an arbitrary vertex to start
}
