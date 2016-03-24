#include<stdio.h>

#define INF 1000

int main()
{
   int v[3]={1,3,5};
   int sum=20;
   int min[sum+1];

   int i,j;

   min[0]=INF;

   for(i=1;i<=sum;i++) {
    min[i]=INF;
    for(j=0;j<3;j++) {
        if(v[j] <= i && i-v[j] <min[i]) {
            min[i]=min[i-v[j]]+1;
        }
    }

   }

   printf("%d ",min[sum]-INF);

   return 0;
}
