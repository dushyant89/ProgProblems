#include<stdio.h>
#include<iostream>

#define V 4

using namespace std;

int main()
{
   int testCases;

   cin>>testCases;

   while(testCases-- >0)
   {
       int sud[V][V];

       int a[V][V][288]={{{1,2,3,4},{4,3,2,1},{3,1,4,2},{2,4,1,3}}
       ,{{1,2,3,4},{3,4,1,2},{2,1,4,3},{4,3,2,1}}
       ,{{2,1,4,3},{4,3,1,2},{1,2,3,4},{3,4,2,1}}};

       int min_variance=10000;

       for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           {
               cin>>sud[i][j];
           }
       }
    int variance=0;
    for(int k=0;k<3;k++)
    {
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           {
                int difference = sud[i][j] - a[i][j][k];
                int absolute_difference = (difference < 0 ? -difference : difference);
                int squared_absolute_difference = absolute_difference * absolute_difference;
                variance = variance + squared_absolute_difference;
           }
       }
       min_variance=(variance < min_variance) ? variance : min_variance;
    }
       cout<<min_variance<<endl;

   }
   return 0;
}
