#include<stdio.h>
#include<stdlib.h>

typedef struct node {

    int data;
    struct node* next;
}node;

int main()
{
   int a[11]={1,2,3,4,5,6,7,8,9,10,11};

   node *head=(node *)calloc(1,sizeof(node));
   head->data=a[0];
   head->next=NULL;

   node *ptr=head;
   node *mid=NULL;

   int i;
   for(i=1;i<11;i++) {


       node *newNode=(node *)calloc(1,sizeof(node));
       newNode->data=a[i];
       newNode->next=NULL;
       ptr->next=newNode;
       ptr=newNode;

       if(i==4) {
        mid=ptr;
       }
   }

   ptr->next=mid;

   node *slow=head;
   node *fast=head;

   while(fast!=NULL && fast->next!=NULL)
   {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) {
            break;
        }
   }

   slow=head;

   while(slow!=fast) {
    slow=slow->next;
    fast=fast->next;
   }

   printf("%d",slow->data);

   return 0;
}
