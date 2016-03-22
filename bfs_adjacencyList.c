#include<stdio.h>
#include<stdlib.h>

//breadth first search for adjacency list representation

typedef struct Node {

    int index;
    struct Node *next;
}Node;

typedef struct List {

Node *head;

}List;

typedef struct Graph {
    List *array;
    int V;
}Graph;

void addEdge(Graph *graph,int src,int dest)
{

    Node *ptr=graph->array[src].head;

    Node *newNode=(Node *)calloc(1,sizeof(Node));
    newNode->index=dest;
    newNode->next=NULL;

    newNode->next=ptr->next;
    ptr->next=newNode;

    //adding the other undirected edge
    Node *newNode2=(Node *)calloc(1,sizeof(Node));
    newNode2->index=src;
    newNode2->next=NULL;

    ptr=graph->array[dest].head;
    newNode2->next=ptr->next;
    ptr->next=newNode2;
}

void printGraph(Graph *graph)
{
    int V=graph->V;
    int i;
    for(i=0;i<V;i++)
    {
        Node *ptr=graph->array[i].head;
        printf("->|%d|",ptr->index);
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            printf("->|%d|",ptr->index);
        }
        printf("\n");
    }
}

void traverseBFS(Graph *graph)
{
   int *visited=(int *)calloc(graph->V,sizeof(int));
   int *queue=(int *)calloc(graph->V,sizeof(int));

   int i=0; int front=0;int rear=0;

   Node *ptr=graph->array[0].head;

   while(i<graph->V)
   {
       while(ptr!=NULL)
       {
           if(visited[ptr->index]==0)
           {
                printf("->|%d|",ptr->index);
                visited[ptr->index]=1;

                queue[rear]=ptr->index;
                rear++;
                i++;
           }
           ptr=ptr->next;
       }
       ptr=graph->array[queue[front++]].head;
   }
}

int main(){


    Graph *graph=(Graph *)calloc(1,sizeof(Graph));
    graph->array=(List *)calloc(5,sizeof(List));
    graph->V=6;

    int i;

    for(i=0;i<graph->V;i++)
    {
        graph->array[i].head=(Node *)calloc(1,sizeof(Node));
        graph->array[i].head->next=NULL;
        graph->array[i].head->index=i;
    }
    //adding edges now to the graph
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,4,0);
    addEdge(graph,1,5);

    //printing the graph
    printGraph(graph);

    //traversing the graph using BFS
    printf("\nBreadth first traversal is as follows\n");
    traverseBFS(graph);

    return 0;
}
