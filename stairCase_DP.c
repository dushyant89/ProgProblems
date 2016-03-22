#include<stdio.h>

int f(int n) {
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else {
        int count=1+f(n-1);
        count+=f(n-2);
        count+=f(n-3);

        return count;
    }
}

int main()
{
   int n;

   while(~scanf("%d",&n)) {

   int stair[n+1];
   stair[0]=0;
   stair[1]=1;
   stair[2]=2;

   int i;

   for(i=3;i<=n;i++) {
        stair[i]=stair[i-1]+stair[i-2]+stair[i-3];
   }

   printf("%d\n",stair[n]);
   }

   return 0;
}
