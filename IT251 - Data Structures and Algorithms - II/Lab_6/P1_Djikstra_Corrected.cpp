#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

struct Graph {
    int numVertices;
    vector<int> visited;
    vector<Node*> adj;
};

Node* createNode(int v, int weight) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = nullptr;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = new Graph;
    graph->numVertices = vertices;
    graph->visited.assign(vertices, 0);
    graph->adj.assign(vertices, nullptr);
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    // For undirected graph, add an edge from dest to src also
    newNode = createNode(src, weight);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}



///////////////////////////////////////////////////////////////////////////////////
void printArr(int dist[], int n, vector<vector<int>>& paths) {
    cout << "Vertex   Distance from Source              Path\n";
    for (int i = 0; i < n; ++i) {
        cout << i+1 << "\t\t" << dist[i] << "\t\t\t";
        for (int j = 0; j < paths[i].size(); ++j) {
            cout << paths[i][j] + 1;
            if (j < paths[i].size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
}
/////////////////////////////////////////////////////////////////////////////

void dijkstra(Graph* graph, int start) {
    int V = graph->numVertices;
    int dist[V];
    vector<vector<int>> paths(V);   /////////////////////////////////////////////

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        paths[v].clear();       ///////////////////////////////////////////////////////
    }

    dist[start] = 0;
    paths[start].push_back(start);     /////////////////////////////////////////////////////////////////

    for (int count = 0; count < V - 1; count++) {
        int minDist = INT_MAX, u = -1;

        for (int v = 0; v < V; v++) {
            if (!graph->visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break; //////////////////////////////////no
        graph->visited[u] = 1;

        for (Node* pCrawl = graph->adj[u]; pCrawl != nullptr; pCrawl = pCrawl->next) {
            int v = pCrawl->vertex;

            if (!graph->visited[v] && dist[u] != INT_MAX && dist[u] + pCrawl->weight < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                paths[v] = paths[u]; ///////////////////////////////////////////////////////////////////////////////////
                paths[v].push_back(v); ///////////////////////////////////////////////////////////////////////
            }
        }
    }
    printArr(dist, V, paths);
}

int main() {
    int V;
    cin >> V;
    Graph* graph = createGraph(V);

    for(int i = 0; i < V; i++) {
        int a, b, c, d, e;
        char f, g;
        cin >> a >> b >> f >> c >> d >> g >> e;
        a--; b--; d--;
        addEdge(graph, a, b, c);
        addEdge(graph, a, d, e);
    }

    dijkstra(graph, 0); // Choosing 0 as the source vertex
    return 0;
}

