#include<stdio.h>
#include<string.h>

//i/p: abcfedgh o/p: abcdefgh
//afbedcjihkg

int main()
{

   char input[100];
   int a[256]={0};

   printf("Please enter the input\n");
   scanf("%s",input);

   int len=strlen(input);
   int i;

   for(i=0;i<len;i++) {
        a[input[i]]=1;
   }
   printf("\n");
   for(i=0;i<256;i++) {
        if(a[i]) printf("%c",i);
   }


   return 0;
}
