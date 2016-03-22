#include<stdio.h>
/*
Factorial of large numbers
Date : 27/10/2014
*/
typedef long long int long_int;

int main()
{
   int a[5000]; //this size is anticipatory, need to work on it
   int n;
   while(~scanf("%d",&n))
   {
        int i=0;
        long_int sum=0;
        int temp=0;
        int m=1;
        a[0]=1;

        for(i=1;i<=n;i++)
        {
            int j=0;
            sum=0;
            while(j<m)
            {
                int x=i*a[j] +temp;
                a[j]=x%10;
                sum+=a[j];
                temp=x/10;
                j++;
            }
            while(temp >0)
            {
                a[m++]=temp;
                sum+=temp;
                temp=temp/10;
            }
        }

        for(i=m-1;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");
        printf("Sum=%lld\n",sum);
   }

   return 1;
}
