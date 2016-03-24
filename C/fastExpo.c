#include<stdio.h>



int main()
{
   printf("Enter the base and exponent\n");
   int base; int exp;

   while(~scanf("%d %d",&base,&exp))
   {
        int number[exp];

        int temp=0;
        int i;
        int m=1;
        number[0]=1;
        exp=exp+1;
        for(i=1;i<=exp;i++)
        {
            int j=0;
            while(j<m)
            {
                int x=base*number[j] +temp;
                number[j++]=x%10;
                temp=x/10;
            }
            while(temp >0)
            {
                number[m++]=temp%10;
                temp=temp/10;
            }
        }

        for(i=m-1;i>=0;i--)
        {
            printf("%d ",number[i]);
        }
        printf("\n");
        temp=1;
        int denom=base-1;
        int x=0;
        if(denom >=1)
        {
            if(number[x] >denom) number[x]=number[x]-denom;
            else
            {
                 while(temp>0)
                 {
                    number[x]=number[x]+10-denom;
                    denom=1;
                    if(number[x+1]-1 <0)
                    {
                        temp=1;
                        x++;
                    }
                    else
                    {
                      number[x+1]=number[x+1]-1;
                      break;
                    }
                 }
            }
        }

        for(i=m-1;i>=0;i--)
        {
            printf("%d ",number[i]);
        }
        printf("\n");
   }

   return 1;
}
