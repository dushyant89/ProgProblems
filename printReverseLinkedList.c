#include<stdio.h>
#include<stdlib.h>

typedef struct node {

    int data;
    struct node* next;
}node;

//prints the list in recursive fashion
void printList(node *ptr) {
    if(ptr!=NULL) {
        printList(ptr->next);
        printf("%d ",ptr->data);
    }
    else
        return;

}

int main()
{
   int a[10]={23,11,14,15,1,25,9,12,4};

   node *head=(node *)calloc(1,sizeof(node));
   head->data=a[0];
   head->next=NULL;

   node *ptr=head;
   node *mid=NULL;

   int i;
   for(i=1;i<9;i++) {

       node *newNode=(node *)calloc(1,sizeof(node));
       newNode->data=a[i];
       newNode->next=NULL;
       ptr->next=newNode;
       ptr=newNode;
   }

   ptr=head;
   printList(ptr);

   return 0;
}
