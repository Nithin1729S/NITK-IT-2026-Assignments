// This cpp code finds dfs traversal of directed or undirected graph using iterative approach
//Please make sure the vertices numbering start from 0 ....

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> dfs(int V,vector<int>adj[],int src)
    {
        vector<int>res;
        int vis[V]={0};
        stack<int>stk;
        stk.push(src);
        while(!stk.empty())
        {
            int s = stk.top();
		    stk.pop();
            if(!vis[s])
            {
                res.push_back(s);
                vis[s]=1;
            }
            for(auto it:adj[s])
            {
                if(!vis[it])
                {
                    stk.push(it);
                }
            }

        }
        return res;
    }
};

int main()
{   
    Solution sol;
    cout<<"Enter the number of vertices and edges: "<<endl;
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    char choice;
    cout<<"Is it Directed Graph? (Y/N): ";
    cin>>choice;
    cout<<"Enter the edges of the graph(from to): "<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //for undirected graph
        adj[u].push_back(v);
        if(choice=='N') adj[v].push_back(u);
    }
    int src;
    cout<<"Enter starting vertex: ";
    cin>>src;
    vector<int>res=sol.dfs(n,adj,src);
    cout<<"DFS Traversal of given graph: ";
    for(auto i:res) cout<<i<<" ";
    return 0;
}