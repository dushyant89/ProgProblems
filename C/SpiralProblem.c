#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Enter the size of the m*n matrix you want to print\n");
    scanf("%d",&m);
    scanf("%d",&n);

    int **a=(int **)calloc(m*n,sizeof(int *));
    int i;
    for(i=0;i<m;i++)
    {
       a[i] =(int *)calloc(n,sizeof(int));
    }
    int value=0;
    //setting the matrix
    for(i=0;i<m;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            a[i][j]=++value;
        }
    }

    int row, column;
    int columnBound=0;
    int rowBound=0;

  while(columnBound<=n/2)
  {

    //first horizontal row
    for(row=rowBound,column=columnBound;column<n-columnBound;column++)
    {
        printf("%d ",a[row][column]);
    }

    printf("\n");

    //first vertical column
    for(row=rowBound+1,column=n-1-rowBound;row<m-rowBound;row++)
    {
        printf("%d ",a[row][column]);
    }
    printf("\n");

    //second horizontal row
    for(row=m-1-rowBound,column=n-2-columnBound;column>=columnBound-0;column--)
    {
        printf("%d ",a[row][column]);
    }
    printf("\n");

    //second vertical column
    for(column=columnBound,row=m-2-rowBound;row>=1+rowBound;row--)
    {
        printf("%d ",a[row][column]);
    }
    printf("\n");

    rowBound++;
    columnBound++;
  }

    return 1;
}
