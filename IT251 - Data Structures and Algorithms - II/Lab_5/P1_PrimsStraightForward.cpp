#define INF 350000
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    int key;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    int* visited;
    struct Node **adj;
};

struct Node* createNode(int v, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    newNode->key = INF;
    newNode->weight = weight;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adj = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adj[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adj[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf("(%d,%d)", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void primMST(struct Graph* graph, int startNode) {
    int V = graph->numVertices;
    int parent[V];
    int key[V];

    for (int i = 0; i < V; ++i) {
        parent[i] = -1;
        key[i] = INF;
    }

    key[startNode] = 0;
    long long int totalWeight = 0;

    for (int count = 0; count < V - 1; ++count) {
        int min = INF, u;

        // Find the vertex with the minimum key value
        for (int v = 0; v < V; ++v) {
            if (graph->visited[v] == 0 && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // Include the minimum key vertex in the MST
        graph->visited[u] = 1;

        struct Node* pCrawl = graph->adj[u];
        while (pCrawl) {
            int v = pCrawl->vertex;
            if (graph->visited[v] == 0 && pCrawl->weight < key[v]) {
                parent[v] = u;
                key[v] = pCrawl->weight;
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < V; ++i) {
        if (i != startNode) {
            printf("%d - %d    %d\n", parent[i], i, key[i]);
            totalWeight += key[i];
        }
    }
    printf("Total Weight of MST: %lld\n", totalWeight);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    struct Graph* graph = createGraph(V + 1);  // for one-based indexing
    for (int i = 0; i < E; i++) {
        int u, w, wt;
        scanf("%d %d %d", &u, &w, &wt);
        addEdge(graph, u, w, wt);
    }
    // Assuming Starting vertex to be 1;
    primMST(graph, 1);
    return 0;
}
