#define INF 350000
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int vertex;
    int key;
    int weight;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    int* visited;
    struct Node **adj;
};

struct Node* createNode(int v,int weight)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=NULL;
    newNode->key=INF;
    newNode->weight=weight;
    return newNode;
}

struct Graph*createGraph(int vertices)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices=vertices;
    graph->adj=(struct Node**)malloc(vertices*sizeof(struct Node*));
    graph->visited=(int*)malloc(vertices*sizeof(int));
    for(int i=0;i<vertices;i++)
    {
        graph->adj[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}


void addEdge(struct Graph*graph,int src,int dest,int weight)
{
    struct Node*newNode=createNode(dest,weight);
    newNode->next=graph->adj[src];
    graph->adj[src]=newNode;

    newNode=createNode(src,weight);
    newNode->next=graph->adj[dest];
    graph->adj[dest]=newNode;
}

void printGraph(struct Graph*graph)
{
    for(int i=0;i<graph->numVertices;i++)
    {
        struct Node*temp=graph->adj[i];
        printf("Vertex %d:",i);
        while(temp)
        {
            printf("(%d,%d)",temp->vertex,temp->weight);
            temp=temp->next;
        }
        printf("\n");
    }
}

struct minHeapNode
{
    int v;
    int key;
};

struct minHeap
{
    int size;
    int capacity;
    int *pos;
    struct minHeapNode**array;
};

struct minHeapNode*newMinHeapNode(int v,int key)
{
    struct minHeapNode*minHeapNode=(struct minHeapNode*)malloc(sizeof(struct minHeapNode));
    minHeapNode->v=v;
    minHeapNode->key=key;
    return minHeapNode;
}

struct minHeap*createMinHeap(int capacity)
{
    struct minHeap*minHeap=(struct minHeap*)malloc(sizeof(struct minHeap));
    minHeap->pos=(int*)malloc(capacity*sizeof(int));
    minHeap->size=0;
    minHeap->capacity=capacity;
    minHeap->array=(struct minHeapNode**)malloc(capacity*sizeof(struct minHeapNode*));

    return minHeap;
}

void swapMinHeapNode(struct minHeapNode**a,struct minHeapNode**b)
{
    struct minHeapNode*t=*a;
    *a=*b;
    *b=t;
}

void minHeapify(struct minHeap*minHeap,int idx)
{
    int smallest=idx;
    int left=2*idx+1;
    int right=2*idx+2;

    if(left<minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest=left;
    if(right<minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
    smallest=right;

    if(smallest!=idx)
    {
        struct minHeapNode* smallestNode=minHeap->array[smallest];
        struct minHeapNode*idxNode=minHeap->array[idx];

        minHeap->pos[smallestNode->v]=idx;
        minHeap->pos[idxNode->v]=smallest;

        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);

        minHeapify(minHeap,smallest);

    }
}

int isHeapEmpty(struct minHeap*minHeap)
{
    return minHeap->size==0;
}

struct minHeapNode* extractMin(struct minHeap*minHeap)
{
    if(isHeapEmpty(minHeap)) return NULL;

    struct minHeapNode*root=minHeap->array[0];

    struct minHeapNode*lastNode=minHeap->array[minHeap->size-1];
    minHeap->array[0]=lastNode;

    minHeap->pos[root->v]=minHeap->size-1;
    minHeap->pos[lastNode->v]=0;

    --minHeap->size;
    minHeapify(minHeap,0);

    return root;
}

void decreaseKey(struct minHeap*minHeap,int v,int key)
{
    int i=minHeap->pos[v];

    minHeap->array[i]->key=key;

    while(i && minHeap->array[i]->key<minHeap->array[(i-1)/2]->key)
    {
        minHeap->pos[minHeap->array[i]->v]=(i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v]=i;
        swapMinHeapNode(&minHeap->array[i],&minHeap->array[(i-1)/2]);

        i=(i-1)/2;
    }
}

bool isINMinHeap(struct minHeap*minHeap,int v)
{
    if(minHeap->pos[v]<minHeap->size)
        return true;
    return false;
}

void printArr(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}

void primMST(struct Graph*graph,int startNode)
{
    int V=graph->numVertices;
    int parent[V];
    int key[V];

    struct minHeap* minHeap=createMinHeap(V);

    for(int v=0;v<V;v++)
    {
        parent[v]=-1;
        key[v]=INF;
        minHeap->array[v]=newMinHeapNode(v,key[v]);
        minHeap->pos[v]=v;
    }
     minHeap->size=V;
    key[startNode]=0;
    decreaseKey(minHeap,startNode,key[startNode]);

    while(!isHeapEmpty(minHeap))
    {
        struct minHeapNode* minHeapNode=extractMin(minHeap);
        int u=minHeapNode->v;

        struct Node* pCrawl=graph->adj[u];

        while(pCrawl)
        {
            int v=pCrawl->vertex;

            if(isINMinHeap(minHeap,v) && pCrawl->weight<key[v])
            {
                key[v]=pCrawl->weight;
                parent[v]=u;
                decreaseKey(minHeap,v,key[v]);
            }
            pCrawl=pCrawl->next;
        }
        
    }
    printf("Edge   Weight\n");
    int totalWeight=0;
    for (int i = 1; i < V; ++i)
    {
        if(i!=startNode)
        {
            printf("%d - %d    %d\n", parent[i], i, key[i]);
        totalWeight += key[i];
        }
    }
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main()
{

    int V,E;
    cin>>V>>E;
    struct Graph* graph=createGraph(V+1);  //for one bases indexing
    for(int i=0;i<E;i++)
    {
        int u,w,wt;
        cin>>u>>w>>wt;
        addEdge(graph,u,w,wt);
    }
    //Assuming Starting vertex to be 1;
    primMST(graph,1);  
    return 0;
}

