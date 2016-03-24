#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef struct Edge {
    int src;
    int dest;
    int wt;
}Edge;

typedef struct subset{
int parent;
int order;
}subset;

typedef struct Graph{
int V;
int E;
vector<Edge> edges;
}Graph;

Graph *mst;

void find_mst(Graph *graph)
{


}

int main()
{
    //preparing the graph first

    Graph *input_graph=(Graph *)calloc(1,sizeof(Graph));
    mst=(Graph *)calloc(1,sizeof(Graph));
    mst->V=4;

    input_graph->V=5;
    input_graph->E=5;

    input_graph->edges=(Edge *)calloc(input_graph->E,sizeof(Edge));

    //let us assume the edges are sorted for convenience
    input_graph->edges[0].src=1;
    input_graph->edges[0].dest=2;
    input_graph->edges[0].wt=5;

    input_graph->edges[1].src=0;
    input_graph->edges[1].dest=3;
    input_graph->edges[1].wt=1;

    input_graph->edges[2].src=0;
    input_graph->edges[2].dest=1;
    input_graph->edges[2].wt=3;

    input_graph->edges[3].src=3;
    input_graph->edges[3].dest=4;
    input_graph->edges[3].wt=2;

    input_graph->edges[4].src=1;
    input_graph->edges[4].dest=4;
    input_graph->edges[4].wt=2;

}
