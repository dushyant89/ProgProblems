#include<stdio.h>

#define MAX 10000
int main()
{
   int s1[]={2,5,1,3,5,11,19,5};
   int s2[]={0,0,0,0,0,0,0,0};

   int top1=7;
   int top2=-1;
   int topThreshold=-1;
   int min=MAX;

   while(topThreshold<=7) {
       while(top1!=topThreshold){

            if(s1[top1] <min) min=s1[top1];

            s2[++top2]=s1[top1--];
        }
        s1[++top1]=min;
        topThreshold=top1;
        int minCheck=0;

        while(top2!=-1){
            if(s2[top2]!=min || minCheck) {
                s1[++top1]=s2[top2];
            }
            else {
                minCheck=1;
            }
            top2--;
        }
        min=MAX;
   }

   int i;

   for(i=0;i<=7;i++) { printf("%d ",s1[i]); }

   return 0;
}
