#include<stdio.h>

typedef enum emp_dept {
    assembly, manufacturing, accounts, stores
}emp;
int main()
{
   emp e;
   e=manufacturing;
   printf("%d",e);

   char name[]="skanyam";
   name[1]='a';
   printf("%s",name);

   return 0;
}
