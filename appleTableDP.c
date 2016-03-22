#include<stdio.h>
#include<stdlib.h>

typedef struct table {

int cost;
int value;
short int visited;

}tab;

tab **grid;
int n,m;

int findMax(int i,int j) {

    if(!grid[i][j].visited) {
       int max=0;
        if(i+1 <n){
            max=grid[i][j].value + findMax(i+1,j);
            grid[i][j].visited=1;
        }
        if(j+1 <m) {
            int temp=0;
            temp=grid[i][j].value + findMax(i,j+1);
            max=(temp >max) ? temp :max;
            grid[i][j].visited=1;
        }

        grid[i][j].cost=max;

        return max;
    }
    else
    {
        return grid[i][j].cost;
    }
}

int main()
{


   printf("Enter the size of rows and columns\n");
   scanf("%d %d",&n,&m);

   grid=(tab **)calloc(n*m,sizeof(tab *));
   int i=0;

   for(i;i<m;i++) {
        grid[i]=(tab *)calloc(m,sizeof(tab));
   }

   printf("Enter the values now\n");

   int j;
   for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
        scanf("%d",&grid[i][j].value);
        grid[i][j].visited=0;
    }
   }

   printf("%d",findMax(0,0));

   return 0;
}
