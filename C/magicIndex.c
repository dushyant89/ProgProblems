#include<stdio.h>

int main()
{
   int a[]={0,-2,-1,2,4,7,8};
   int len=sizeof(a)/sizeof(int);
   int i;

   int low=1; int high=len-1; int mid=(low+high)/2;

   while(low<=high){
        if(a[mid]==mid){
            printf("%d\n",mid);
            break;
        }
        else if(a[mid] >mid){
            high=mid-1;
            mid=(low+high)/2;
        }
        else {
            low=mid+1;
            mid=(low+high)/2;
        }
   }

   return 0;
}
