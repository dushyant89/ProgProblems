#include<stdio.h>


int main()
{
   int a[]={ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
            600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
            67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
            477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
            249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
   int sequenceCount[50];
   int min=0;
   int max=0;
   int i;

   for(i=0;i<50;i++) sequenceCount[i]=0;

   sequenceCount[0]=1;

   for(i=1;i<50;i++) {
        if(a[i] >a[i-1] && !max) {
           sequenceCount[i]=sequenceCount[i-1]+1;
            max=1;
            min=0;
        }
        else if(a[i] <a[i-1] && !min) {
            sequenceCount[i]=sequenceCount[i-1]+1;
            min=1;
            max=0;
        }
        else {
            sequenceCount[i]=sequenceCount[i-1];
        }
   }

printf("%d",sequenceCount[i-1]);

   return 0;
}
