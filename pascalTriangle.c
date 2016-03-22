#include<stdio.h>

int main()
{
   int n,i,c;

   int fact(int);

   printf("Enter the no. of rows Pascal Triangle\n");
   scanf("%d",&n);

   for(i=0;i<n;i++) {

        for(c=0;c<n-i-1;c++) {
            printf(" ");
        }

        for(c=0;c<=i;c++) {
            printf("%d ",fact(i)/(fact(c)*fact(i-c)));
        }
        printf("\n");
   }

   return 0;
}
int fact(int n) {
        if(n==0 || n==1) return 1;

        else return n*fact(n-1);
   }
