//Kruskal implemented using union find DS
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#define INF 35000

struct Node
{
    int vertex;
    int weight;
    int key;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    int *parent;
    struct Node** adjList;
};

struct Node*createNode(int vertex,int weight)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=vertex;
    newNode->weight=weight;
    newNode->next=NULL;
    newNode->key=INF;

    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=vertices;
    graph->adjList=(struct Node**)malloc(sizeof(struct Node*)*vertices);
    graph->parent=(int*)malloc(sizeof(int)*vertices);
    for(int i=0;i<vertices;i++)
    {
        graph->adjList[i]=NULL;
        graph->parent[i]=i;
    }
    return graph;
}

void addEdge(struct Graph* graph,int src,int dest,int weight)
{
    struct Node*newNode=createNode(dest,weight);
    newNode->next=graph->adjList[src];
    graph->adjList[src]=newNode;

    newNode =createNode(src,weight);
    newNode->next=graph->adjList[dest];
    graph->adjList[dest]=newNode;
}

int find(int i,int parent[])
{
    while(parent[i]!=i)
        i=parent[i];
    return i;
}

void union1(int i,int j,int parent[])
{
    int a=find(i,parent);
    int b=find(j,parent);
    parent[a]=b;
}

void kruskalMST(struct Graph* graph)
{
    int minCost=0;
    int edgeCount=0;
    
    while(edgeCount<graph->numVertices-1)
    {
        int min=INF;
        int a=-1;
        int b=-1;
        for(int i=0;i<graph->numVertices;i++)
        {
            struct Node*temp=graph->adjList[i];
            while(temp)
            {
                if(find(i,graph->parent)!=find(temp->vertex,graph->parent)&& temp->weight<min)
                {
                    min=temp->weight;
                    a=i;
                    b=temp->vertex;
                }
                temp=temp->next;
            }
        }
        union1(a,b,graph->parent);
        printf("Edge %d:(%d, %d) cost:%d \n", edgeCount++, a+1, b+1, min);
        minCost += min;
    }
    printf("\n Minimum cost= %d \n", minCost);

}


int main()
{
    int V,E;
    cin>>V>>E;
    struct Graph* graph=createGraph(V);
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;      //for one based indexing
        v--;      //for one bases indexing
        addEdge(graph,u,v,w);
    }

    kruskalMST(graph);
}