#include<stdio.h>
#include<stdlib.h>

int max(int a,int b) {
    return (a >b) ? a : b;
}

int min(int a,int b) {
    return (a < b) ? a : b;
}

int main()
{
   int a[]={1,3,5,7,9};
   int b[]={2,4,6,8,10};

   int len_1=sizeof(a)/sizeof(int);
   int len_2=sizeof(b)/sizeof(int);
   int m1,l1,h1;
   int m2,l2,h2;

   l1=0; l2=0;
   h1=len_1; h2=len_2;
   m1=(l1+h1)/2; m2=(l2+h2)/2;
    int x;
   while(h1-l1!=1 && h2-l2!=1) {

        if(a[m1] >b[m2]) {
            h1=m1;
            m1=(l1+h1)/2;

            l2=m2;
            m2=(l2+h2)/2;
        }
        else if(b[m2] >a[m1]) {
            l1=m1;
            m1=(l1+h1)/2;

            h2=m2;
            m2=(l2+h2)/2;
        }
        else {
            printf("%d",a[m1]);
            break;
        }
       printf("%d %d\n",a[m1],b[m2]);
       printf("%d %d\n",l1,l2);
       scanf("%d",&x);

   }
   if(h1-l1==1 && h2-l2==1) {
        printf("%d",(min(a[h1],b[h2]) + max(a[l1],b[l2]))/2);
   }

   return 0;
}
