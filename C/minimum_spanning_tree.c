#include<stdio.h>
#include<stdlib.h>
/*
Beautiful implementation of Minimum spanning tree using Kruskal's algorithm
cycle detection using union and path compression
*/

typedef struct Edge {
    int src;
    int dest;
    int wt;
}Edge;

typedef struct subset{
int parent;
int rank;
}subset;

typedef struct Graph{
int V;
int E;
Edge *edges;
}Graph;

Graph *mst;
subset *set;

//in O(logn) time it finds the parent of the node
int find_parent(int x)
{
    int parent=set[x].parent;
    while(parent!=x)
    {
        x=parent;
        parent=set[x].parent;
    }
    return parent;
}

short int isCycle(Edge e)
{
  int xRoot=find_parent(e.src);
  int yRoot=find_parent(e.dest);

  if(xRoot!=yRoot)
  {
      if(set[xRoot].rank >set[yRoot].rank)
      {
          set[yRoot].parent=xRoot;
      }
      else if(set[xRoot].rank <set[yRoot].rank)
      {
         set[xRoot].parent=yRoot;
      }
      else
      {
          set[yRoot].parent=xRoot;
          set[xRoot].rank++;
      }
      return 0;
  }
  else
  {
     return 1;
  }
}

void find_mst(Graph *graph)
{
    int i;
    int count=0;

    set=(subset *)calloc(mst->V,sizeof(subset));
    for(i=0;i<mst->V;i++)
    {
        set[i].parent=i;
        set[i].rank=0;
    }

    for(i=0;i<graph->E;i++)
    {
        if(!isCycle(graph->edges[i]))
        {
            if(count < mst->E)
            {
                mst->edges[count]=graph->edges[i];
                count++;
            }
            else
            {
                break;
            }
        }
    }

}

int main()
{
    //preparing the graph first

    Graph *input_graph=(Graph *)calloc(1,sizeof(Graph));
    mst=(Graph *)calloc(1,sizeof(Graph));
    mst->V=5;
    mst->E=4;
    mst->edges=(Edge *)calloc(mst->E,sizeof(Edge));

    input_graph->V=5;
    input_graph->E=5;

    input_graph->edges=(Edge *)calloc(input_graph->E,sizeof(Edge));

    //let us assume the edges are sorted for convenience
    input_graph->edges[0].src=1;
    input_graph->edges[0].dest=2;
    input_graph->edges[0].wt=1;

    input_graph->edges[1].src=0;
    input_graph->edges[1].dest=3;
    input_graph->edges[1].wt=2;

    input_graph->edges[2].src=0;
    input_graph->edges[2].dest=1;
    input_graph->edges[2].wt=2;

    input_graph->edges[3].src=3;
    input_graph->edges[3].dest=4;
    input_graph->edges[3].wt=3;

    input_graph->edges[4].src=1;
    input_graph->edges[4].dest=4;
    input_graph->edges[4].wt=5;

    find_mst(input_graph);

    //traverse mst for the minimum tree
    int i;
    printf("Kruskals, minimum spanning tree is as follows\n");
    for(i=0;i<mst->E;i++)
    {
        printf("%d->%d\n",mst->edges[i].src+1,mst->edges[i].dest+1);
    }
}
