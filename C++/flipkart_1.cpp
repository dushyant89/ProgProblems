#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct cell
{
    char c;
    int v;
    int h;
}cell;

int main()
{

   int m,n;
   int count=0;

   scanf("%d",&m); scanf("%d",&n);
   cell grid[m][n];

   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>grid[i][j].c;
           grid[i][j].v=0;
           grid[i][j].h=0;
       }
   }
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
            if(grid[i][j].c=='B' && !grid[i][j].v)
            {
                int col=i;
                int found=0;
                //going down first, so need to check if it is visited
                for(col;col<m;col++)
                {
                    if(grid[col][j].c=='B' || grid[col][j].c=='G' || grid[col][j].c=='R')
                    {
                        grid[col][j].v=1;
                        found=1;
                    }
                    else if(grid[col][j].c=='.')
                        break;
                }
                //going up now
                col=i-1;
                for(col;col>=0;col--)
                {
                    if(grid[col][j].c=='G' || grid[col][j].c=='R') //no use of checking for B
                    {
                        if(grid[col][j].c=='G' && grid[col][j].v)
                        {
                            count--; //merging into a bigger vertical list
                        }

                        grid[col][j].v=1;
                        found=1;
                    }
                    else if(grid[col][j].c=='.')
                        break;
                }
                if(found) count++;
            }
            //checking the horizontal case for R
            else if(grid[i][j].c=='R' && !grid[i][j].h)
            {
                int row=j;
                int found=0;
                //going right first, so need to check if it is visited
                for(row;row<n;row++)
                {
                    if(grid[i][row].c=='B' || grid[i][row].c=='G' || grid[i][row].c=='R')
                    {
                        grid[i][row].h=1;
                        found=1;
                    }
                    else if(grid[i][row].c=='.')
                        break;
                }
                //going left now
                row=j-1;
                for(row;row>=0;row--)
                {
                    if(grid[i][row].c=='G' || grid[i][row].c=='B') //no use of checking for R
                    {
                        if(grid[i][row].c=='G' && grid[i][row].h)
                        {
                            count--; //merging into a bigger list with R
                        }

                        grid[i][row].h=1;
                        found=1;
                    }
                    else if(grid[i][row].c=='.')
                        break;
                }
                if(found) count++;
            }
            //checking for G
            else if(grid[i][j].c=='G')
            {
                int found=0;
                if(grid[i][j].h!=1) //checking for horizontal chances
                {
                    int col=j;

                    for(col;col<n;col++)
                    {
                        if(grid[i][col].c=='G')
                        {
                            grid[i][col].h=1;
                            found=1;
                        }
                        else break;
                    }
                }
                if(found)
                {
                    count++; found=0;
                }
                if(grid[i][j].v!=1) //checking for vertical chances
                {
                    int row=i;

                    for(row;row<m;row++)
                    {
                        if(grid[row][j].c=='G')
                        {
                            grid[row][j].v=1;
                            found=1;
                        }
                        else break;
                    }
                }
                if(found)
                {
                    count++;
                }
            }
       }
   }

   cout<<count;

   return 0;
}
