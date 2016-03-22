#include<stdio.h>
//#include<iostream>

//using namespace std;

void swap(int &a, int &b){
    a = a^b;
    b= a^b;
    a= a^b;
}

int main()
{

   int a[] = {0, 3, 1, 2,0};

   for(int i=0;i<5; i++){
    if(i==0 || a[i]==i+1)
    {
        continue;
    }
    else{
        while(a[i]!=i+1){
            swap(a[i],a[a[i]-1);
        }
    }

   }

   for(int i=0;i<5; i++){
    if(a[i]==0)
    printf("%d",i+1);

   }
   return 1;
}
