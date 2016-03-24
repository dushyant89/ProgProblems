#include<stdio.h>
#include<math.h>

int main()
{
    int k;
    printf("Enter the no. for prime factorization\n");
    while(~scanf("%d",&k))
    {

        while(k%2==0)
        {
            printf("2 ");
            k=k/2;
        }
        int i;

        for(i=3;i<=sqrt(k);i=i+2)
        {
            while(k%i==0)
            {
                printf("%d ",i);
                k=k/i;
            }
        }
        if(k!=1)
         printf("%d\n",k);

    }

   return 1;
}
