#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 16


int findMeadian(int *a,int l,int k) {

    //group the array in size of 5 elements
    int *median=(int *)calloc((int)ceil(k/5),sizeof(int *));
    int i,j,m;

    for(i=l;i<k;i=i+5) {

        for(j=i;j<i+4 && j<k;j++) {
            int min=a[j];
            for(m=j+1; m<i+5 && m<k;m++) {
                if(a[m] < min) {
                    min=a[m];
                }
            }
        }
    }
}

int main()
{

   int a[]={22,5,10,11,23,15,9,8,2,0,4,20,25,1,29,24};

   printf("median of the group of elements is:\n",findMedian(a,0,size));

   return 0;
}
