#include<stdio.h>

int main()
{
   int n;

   scanf("%d",&n);

   int fib[n+1];
   int i=0;

   for(;i<=n;i++){
     if(i==0 || i==1) {
        fib[i]=1;
     }
     else {
        fib[i]=fib[i-1]+fib[i-2];
     }
   }
   printf("%d",fib[n]);
   return 0;
}
