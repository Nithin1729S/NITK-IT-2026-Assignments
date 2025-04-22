#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    void dfs(int node, vector<int> adj[], int vis[], int ver, int& res, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node); // Add the current node to the component list
        if (node == ver) {
            res = count;
        }
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ver, res, component);
            }
        }
    }

    void dfsCheck(int V, vector<int> adj[], int ver, int& res, vector<vector<int>>& components) {
        int vis[V + 1] = { 0 };
        for (int i = 1; i <= V; i++) {
            if (!vis[i]) {
                count++;
                vector<int> component;
                dfs(i, adj, vis, ver, res, component);
                components.push_back(component); // Add the component to the list of components
            }
        }
    }
};

int main() {
    Solution sol;
    cout << "Enter the number of vertices and edges: " << endl;
    int n, m;
    int res = -1;
    cin >> n >> m;
    vector<int> adj[n + 1];
    cout << "Enter the edges of the graph: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ver;
    cout << "Enter the vertex number whose component is to be given :" << endl;
    cin >> ver;
    vector<vector<int>> components; // Store all the components
    sol.dfsCheck(n, adj, ver, res, components);
    cout << "The number of components in the given graph are: ";
    cout << sol.count << endl;
    cout << "The vertex " << ver << " belongs to component #" << res << endl;
    for (int i = 0; i < min(3, sol.count); ++i) { // Loop over the first 3 components or the total number of components, whichever is smaller
        cout << "Vertices in component #" << i + 1 << ": ";
        for (int vertex : components[i]) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    return 0;
}
