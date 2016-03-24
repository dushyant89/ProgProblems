#include<stdio.h>
#include<string.h>

int main()
{
   char s[10]="SANYAM";
   char temp[strlen(s)+1];
   int len=strlen(s);
   int i=0; int j;
   int count=0;
   for(i;i<len;i++){
        int k=0;
        for(j=i;j<len;j++) {
            temp[k++]=s[j];
            temp[k]='\0';
            printf("%s\n",temp);
            count++;
        }
   }
   printf("%d\n",count);
   return 0;
}
