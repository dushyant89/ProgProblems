#include<stdio.h>
#include<stdlib.h>
//only does a right 90 degrees rotation
int pixelsVisited,n;
int **a;
int cycles;

int findPosition(int i,int j)
{
    static int temp=0;
    pixelsVisited--;
    if(cycles <3)
    {
        int newI,newJ;
        newI=j;
        newJ=n-1-i;
        cycles++;
        findPosition(newI,newJ);
        a[newI][newJ]=a[i][j];
    }
    else
    {
        temp=a[i][j];
    }

    return temp;
}
int main()
{
    printf("Enter the size of square matrix\n");
    scanf("%d",&n);
    a=(int **)calloc(n*n,sizeof(int *));
    int i,j,count=1;
    for(i=0;i<n;i++)
    {
        a[i]=(int *)calloc(n,sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           a[i][j]=count++;
        }
    }
    if(n%2==0) pixelsVisited=n*n;
    else pixelsVisited=n*n -1;

    for(i=0;i>1;i=i/2)
    {
        for(j=i;j<n/2;j++)
        {
            cycles=0;
            a[i][j]=findPosition(i,j);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 1;
}
