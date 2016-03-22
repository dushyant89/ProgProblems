#include<stdio.h>
#include<math.h>
#define INT_MAX 10000000

int main()
{
   int testCases;
   scanf("%d",&testCases);

   while(testCases-- >0) {

        int l1,u1;
        int l2,u2;
        int l3,u3;
        int min=INT_MAX;
        int max=0;

        scanf("%d",&l1); //the base of the polygon
        scanf("%d",&u1);
        scanf("%d",&l2);
        scanf("%d",&u2);
        scanf("%d",&l3);
        scanf("%d",&u3);

        if(l2 >l3) {
            int i;
            for(i=l3;i<u3;i++){
                if(l2-i < min) {
                    min=l2-i;
                }
                if(l2-i ==0){
                    break;
                }
            }
            max=u2-l3;
        }
        else if(l2==l3) {
            min=l2-l3;
            max=(u2-l3 >u3-l2)? u2-l3 : u3-l2;
        }
        else {
            int i;
            for(i=l2;i<u2;i++){
                if(l3-i < min) {
                    min=l3-i;
                }
                if(l3-i ==0){
                    break;
                }
            }
            max=u3-l2;
        }
       min=(int)sqrt(l1*l1 + min*min);
       max=(int)sqrt(u1*u1 + max*max);

       printf("\nOutput of testCase:%d %d %d\n",testCases,min,max);
   }

   return 0;
}
