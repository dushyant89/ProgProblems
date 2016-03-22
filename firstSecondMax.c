#include<stdio.h>


int main()
{

   int input[]={5,3,4,2,1};
   int len=5;
   int i=0;
   int f_max=input[0];
   int s_max=0;

   for(i=0;i<len;i++)
    {
        if(input[i] >f_max)
        {
            f_max=input[i];
            s_max=f_max;
        }
        else if(input[i] >s_max && input[i]!=f_max)
        {
            s_max=input[i];
        }
    }
    printf("%d %d",s_max,f_max);
   return 1;
}
