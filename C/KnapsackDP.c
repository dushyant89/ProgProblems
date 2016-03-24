#include<stdio.h>

int max(int a , int b) {

    return (a >b) ? a: b;
}

int main()
{
   //capacity of the knapsack
   int k_wt=6;

   //array of weights of the balls
   int wt[5]={2,3,1,2,4};
   int p[5]={10,15,12,20,18};

   int v[5+1][k_wt+1];

   int i,j;

   for(i=0;i<=5;i++) {
    for(j=0;j<=k_wt;j++) {
        if(i==0 || j==0) {
            v[i][j]=0;
            continue;
        }
        if (wt[i-1] <= j)
            v[i][j] = max(v[i-1][j], v[i-1][j-wt[i-1]] + p[i-1]);
        else
            v[i][j] = v[i-1][j];

        printf("v[%d][%d]=%d ",i,j,v[i][j]);
    }
        printf("\n");
   }

   return 0;
}
