#include<stdio.h>
#include<malloc.h>


int main()
{
   enum name {
        ram,jai,sam,raj
   } ;

   union big {
    int i;
    enum name n;
   } ;

   union small {
        float k;
        struct mid {
            char c;
            int k;
        }y;
   };

   union list {
        union big p;
        union small q;
   }*s;

   s=(union list*)malloc(sizeof(union list));
   s->p.n=raj;
   printf("%d %d\n",s->p.i,s->q.y.c);
   printf("%d",sizeof(s->p.n));

   int i=107, x=5;
   printf((x >7) ? "%d":"%c",i);

   return 0;
}
