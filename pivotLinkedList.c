#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int data;
    struct node* next;
}node;

int main()
{
   int a[10]={-1,7,5,3,1,2,4,6,0,8};

   int k=8;

   node *head=(node *)calloc(1,sizeof(node));
   head->data=a[0];
   head->next=NULL;

   node *ptr=head;
   int i;
   for(i=1;i<10;i++) {

       node *newNode=(node *)calloc(1,sizeof(node));
       newNode->data=a[i];
       newNode->next=NULL;
       ptr->next=newNode;
       ptr=newNode;
   }

   node *list=NULL;
   node *small=NULL;
   node *track=NULL;
   node *head_large=NULL;
   ptr=head;

   while(ptr!=NULL) {

        if(ptr->data < k) {
            if(small==NULL) {
                small=(node *)calloc(1,sizeof(node));
                small->data=ptr->data;
                small->next=NULL;
                head=small;
            }
            else {
                small->next=ptr;
                small=ptr;
            }
        }
        else if(ptr->data >k) {
            if(list==NULL) {
                list=(node *)calloc(1,sizeof(node));
                list->data=ptr->data;
                list->next=NULL;
                head_large=list;
            }
            else {
                list->next=ptr;
                list=ptr;
            }
        }
        else {
            track=ptr;
        }
        ptr=ptr->next;
   }

   small->next=track;
   track->next=head_large;

   ptr=head;

   while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
   }

   return 0;
}
