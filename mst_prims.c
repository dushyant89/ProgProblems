#include<stdio.h>
#include<conio.h>
#define V 5
#define INF 10000
//adjacency matrix representation for prim's algorithm

int main()
{
    int graph[V][V]={{0, 2, 0, 16, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {16, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    int mst[V]={0};
    int openSet[V]={0,INF,INF,INF,INF};
    int i=0;
    int j=0;
    int totalCost=0;

    for(i;i<V;i++)
    {
          //now iterate through that vertex checking for connectedness
          int k=0;
          int min=INF;
          for(k;k<5;k++)
          {
            if(graph[j][k]!=0 && mst[k]!=1 && openSet[k]!=-1)
            {
                openSet[k]= (graph[j][k] < openSet[k]) ? graph[j][k] : openSet[k];
            }
          }
       printf("%d->",j);
       mst[j]=1; // j is in the mst
       openSet[j]=-1; //j is currently in the open set to be considered

       for(k=0;k<V;k++)
       {
            if(openSet[k]!=-1 && openSet[k] < min)
            {
                min=openSet[k];
                j=k; //next we will start from the minimum
            }
       }
       totalCost+=min;
       min=INF;
    }
    printf("\n");
    printf("%d",totalCost-INF);
    return 0;
}
