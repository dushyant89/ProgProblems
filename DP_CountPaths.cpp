#include<stdio.h>
#include<iostream>
#define V 4

using namespace std;

int countwalks(int graph[V][V],int u,int v,int k)
{

    int m_count[V][V][k+1]; //matrix which stores possible counts from V->V using K edges

  for(int l=0;l<=k;l++)
  {
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
           m_count[i][j][l] = 0;
            //base cases
            if(l==0 && i==j)
                m_count[i][j][l]=1;
            else if(l==1 && graph[i][j])
                m_count[i][j][l]=1;
            else if(l >1)
            {
                for(int x=0;x<V;x++)
                {
                    if(graph[i][x])
                    {
                        m_count[i][j][l]+=m_count[x][j][l-1];
                    }
                }
            }
        }
    }
  }

  return m_count[u][v][k];
}
int main()
{
   /* Let us create the graph which is directed*/
     int graph[V][V] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << countwalks(graph, u, v, k);

   return 0;
}
