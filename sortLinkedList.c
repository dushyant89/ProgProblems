#include<stdio.h>
#include<stdlib.h>

typedef struct node {

    int data;
    struct node* next;
}node;

void merge(node *low, node* mid,node *high) {

  node *ptr1=low;
  node *ptr2=mid->next;

  node *ptr=NULL;
  node *start=NULL;

  while(ptr1!=mid->next && ptr2!=high->next){

    if(ptr1->data <= ptr2->data) {

        if(ptr==NULL){
            ptr=(node *)calloc(1,sizeof(node));
            ptr->data=ptr1->data;
            start=ptr;
            ptr->next=NULL;
        }
        else {
            node *newNode=(node *)calloc(1,sizeof(node));
            newNode->data=ptr1->data;
            newNode->next=NULL;
            ptr->next=newNode;
            ptr=ptr->next;
        }
        ptr1=ptr1->next;

    }
    else if(ptr2->data < ptr1->data){
            if(ptr==NULL){
                ptr=(node *)calloc(1,sizeof(node));
                ptr->data=ptr2->data;
                start=ptr;
                ptr->next=NULL;
            }
            else {
                node *newNode=(node *)calloc(1,sizeof(node));
                newNode->data=ptr2->data;
                newNode->next=NULL;
                ptr->next=newNode;
                ptr=ptr->next;
            }
        ptr2=ptr2->next;
    }

  }

  if(ptr2==high->next) {

        while(ptr1!=mid->next) {

                node *newNode=(node *)calloc(1,sizeof(node));
                newNode->data=ptr1->data;
                newNode->next=NULL;
                ptr->next=newNode;
                ptr=ptr->next;

                ptr1=ptr1->next;
        }
  }
  else if(ptr1==mid->next) {
        while(ptr2!=high->next) {

            node *newNode=(node *)calloc(1,sizeof(node));
            newNode->data=ptr2->data;
            newNode->next=NULL;
            ptr->next=newNode;
            ptr=ptr->next;

            ptr2=ptr2->next;
        }
  }

   ptr=low;

   while(start!=NULL) {

        ptr->data=start->data;
        printf("%d ",ptr->data);
        ptr=ptr->next;
        start=start->next;
   }
   printf("\n");
}

void mergeSort(node *low,node *high) {

    if(low!=high) {
        node *slowPtr=low;
        node *fastPtr=low;

       while(fastPtr!=high && fastPtr->next!=high) {
        fastPtr=fastPtr->next->next;
        slowPtr=slowPtr->next;
       }

       mergeSort(low,slowPtr);
       mergeSort(slowPtr->next,high);
       merge(low,slowPtr,high);
    }

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

   mergeSort(head,ptr);

   ptr=head;
    printf("Printing data\n");
   while(ptr!=NULL) {
     printf("%d ",ptr->data);
     ptr=ptr->next;
   }

   return 0;
}
