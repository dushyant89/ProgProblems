#include<stdio.h>

int main()
{
int a[]={ 1,7,4,9,2,5 };
    const int size= 6;
   int sequenceCount[size];
   int min=0;
   int max=0;
   int i;

   for(i=0;i<size;i++) sequenceCount[i]=0;

   sequenceCount[0]=1;

   for(i=1;i<size;i++) {
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
