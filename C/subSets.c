#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

   int a[]={1,2,3,4};
   int n=sizeof(a)/sizeof(int);


   int i;

   // Since subsets are always a power of 2 so its a better to do this way
   // than to use a power function.
   int limit= 1 << n;

   for(i=0; i<limit; i++) {
        int temp = i;
        // Array of ints of size n
        int *b = (int *)calloc(n,sizeof(int));

        if(0 == temp) {
            printf("NULL\n");
            continue;
        }

        int j=0;
        while(0 != temp) {
            // This checks if the no. is divisble by 2
            if(1 == (temp & 1)) {
                b[j++]=1;
            }
            else {
                b[j++]=0;
            }
            // This divides the no. by 2
            temp = temp >> 1;
        }

        for(j=0; j<n; j++) {
            if(b[j]) {
                printf("%d ",a[j]);
            }
        }

        printf("\n");
   }

   return 0;
}
