#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
}Node;

typedef struct List
{
    Node *head;
}List;

typedef struct Graph
{
    List *graph;
}Graph;

void addEdge(List *adjacencyList,int src,int dest)
{
    //creating a new node now
    Node *newNode=(Node *)calloc(1,sizeof(Node));
    newNode->value=dest;
    newNode->next=NULL;

    Node *ptr=adjacencyList[src].head;

    while(ptr->next!=NULL)
    {
       ptr=ptr->next;
    }
    ptr->next=newNode;

}

void printGraph(int V,List *adjList)
{
    int i;

    for(i=0;i<V;i++)
    {
        Node *ptr=adjList[i].head;
        printf("%d -> |",ptr->value);
        while(ptr->next!=NULL)
        {
           ptr=ptr->next;
           printf("%d->",ptr->value);
        }
        printf("\n");
    }
}

Graph *g;

int main(){

    int V=5;

    //creating the graph now
    g=(Graph *)calloc(1,sizeof(Graph));
    g->graph=(List *)calloc(V,sizeof(List));

    int i;
    for (i = 0; i < V; ++i)
    {
       g->graph[i].head = (Node *)calloc(1,sizeof(Node));
       g->graph[i].head->next=NULL;
       g->graph[i].head->value=i;
    }
    List *adjacencyList=g->graph;
    //adding edges now to the graph
    addEdge(adjacencyList,0,1);
    addEdge(adjacencyList,1,0);
    addEdge(adjacencyList,1,2);
    addEdge(adjacencyList,1,3);
    addEdge(adjacencyList,2,1);
    addEdge(adjacencyList,2,3);
    addEdge(adjacencyList,3,1);
    addEdge(adjacencyList,3,2);
    addEdge(adjacencyList,3,4);
    addEdge(adjacencyList,4,0);
    addEdge(adjacencyList,4,1);
    addEdge(adjacencyList,4,3);

    printGraph(V,adjacencyList);

    return 0;
}
