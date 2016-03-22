#include<stdio.h>

int min(int a,int b)
{
    return (a < b) ? a: b;
}

int main()
{

   int m=9; int n=5;
   int grid[m+1][n+1];

   int i; int j;
   grid[1][1]=1;

   for(i=0;i<=m;i++) {
        for(j=0;j<=n;j++) {
            if(i==0 || j==0)
            {
                grid[i][j]=0;
                continue;
            }

             if(i-j >=0)
                 grid[i][j]=1+ grid[i-j][j];
             else if(j-i >=0)
                grid[i][j]=1+ grid[i][j-i];
        }
   }
   printf("%d",(grid[m][n]-1==0)? -1 : grid[m][n]-1);

   return 0;
}
