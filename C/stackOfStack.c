#include<stdio.h>
#include<stdlib.h>
#define T 5

typedef struct sos {

int stack[T];
int top;
struct sos *next;

}sos;

int popAt(sos *ptr,int index) {
    int count=0;
    while(count!=index && ptr!=NULL) {
        ptr=ptr->next;
        count++;
    }
    if(ptr==NULL)  { printf("The index entered is wrong\n"); return 0; }

    return ptr->stack[(ptr->top)--];
}

void printSos(sos *ptr) {
    while(ptr!=NULL) {
        int x=ptr->top;
        while(x!=-1){
            printf("%d ",ptr->stack[x--]);
        }
        ptr=ptr->next;
        printf("\n");
   }
}

int main()
{
   int x;
   sos *head=NULL;
   sos *ptr=NULL;

   int i;
  for(i=0;i<25;i++) {
    if(ptr==NULL){
        ptr=(sos *)calloc(1,sizeof(sos));
        head=ptr;
        ptr->top=-1;
    }

     scanf("%d",&x);
     ptr->stack[++(ptr->top)]=x;

     if(ptr->top==T-1) {
        sos *newNode=(sos *)calloc(1,sizeof(sos));
        newNode->top=-1;
        ptr->next=newNode;
        ptr=newNode;
     }
   }
   printf("\n");
   printSos(head);
   fflush(stdin);
   printf("\n*********************Now lets pop**************************\n");

   while(~scanf("%d",&x)) {
        printf("%d\n",popAt(head,x));
        printSos(head);
   }

   return 0;
}
