#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
   int testCases;
   cin>>testCases;
   int n,m,x;
   while(testCases-- >0)
   {
        //taking input from the console
        cin>>n; cin>>m; cin>>x;
        int w[n+1];
        int c[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>w[i];
        }
        //assuming the here the colored inputs are separated
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
        }
        int table[x+1][m+1];

        //initializing the matrix to zero
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=m;j++)
            {
                table[i][j]=0;
            }
        }

        for(int i=1;i<=m;i++)
        {
            if(i==1)
            {
                for(int j=1;j<=n;j++)
                {
                    if(c[j]==i)
                    {
                        table[x-w[j]][i]=1;
                    }
                }
            }
            else
            {
                for(int j=1;j<=n;j++)
                {
                    if(c[j]==i)
                    {
                        for(int k=x;k>=1;k--)
                        {
                            if(table[k][i-1] && (k-w[j]) >=0)
                            {
                                table[k-w[j]][i]=1;
                            }
                        }
                    }
                }
            }
        }
        int found=-1;
        for(int i=0;i<=x;i++)
        {
            if(table[i][m])
            {
                found=i;
                break;
            }
        }
        cout<<found<<endl;
   }
   return 0;
}
