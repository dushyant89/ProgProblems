#include<stdio.h>

char* printMonth(int m){

    return (m/3==1) ? "00" : ((m/3==0)? "03":((m/3==2)? "01" :"02"));
}

int main()
{
   int month;
   scanf("%d",&month);

   printf("%s",printMonth(month));
   return 0;
}
