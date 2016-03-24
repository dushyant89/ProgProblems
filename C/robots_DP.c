#include<stdio.h>

int main()
{

   printf("Please enter the size of the grid\n");
   int n;
   scanf("%d\n",&n);

   int x,y;

   while(~scanf("%d %d",&x,&y))
   {
       int i,j;
        int grid[n][n];
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                    grid[i][j]=0;
            }
        }
        grid[0][0]=1;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
              if(i-1 >=0)
                grid[i][j]+=grid[i-1][j];
               if(j-1 >=0)
                grid[i][j]+=grid[i][j-1];

               if(i==x && j==y) {
                    printf("%d",grid[x][y]);
                    goto x;
               }
            }
        }
        x:;
   }

   return 0;
}
