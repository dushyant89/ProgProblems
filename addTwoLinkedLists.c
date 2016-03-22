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

   int a[3]={9,8,9};
   int b[3]={2,3,7};

   node *head_1=(node *)calloc(1,sizeof(node));
   head_1->data=a[0];
   head_1->next=NULL;

   node *ptr_1=head_1;

   node *head_2=(node *)calloc(1,sizeof(node));
   head_2->data=b[0];
   head_2->next=NULL;

   node *ptr_2=head_2;

   int i;
   for(i=1;i<3;i++) {

       node *newNode=(node *)calloc(1,sizeof(node));
       newNode->data=a[i];
       newNode->next=NULL;
       ptr_1->next=newNode;
       ptr_1=newNode;

       newNode=(node *)calloc(1,sizeof(node));
       newNode->data=b[i];
       newNode->next=NULL;
       ptr_2->next=newNode;
       ptr_2=newNode;
   }

   int carry=0;

   ptr_1=head_1;
   ptr_2=head_2;
   node *temp;
   while(ptr_1!=NULL) {

        int sum=ptr_1->data + ptr_2->data +carry;
        ptr_1->data=sum%10;
        carry=sum/10;
        temp=ptr_1;
        ptr_1=ptr_1->next;
        ptr_2=ptr_2->next;
   }

   if(carry!=0) {
       ptr_1=temp;
       node *newNode=(node *)calloc(1,sizeof(node));
       newNode->data=carry;
       newNode->next=NULL;
       ptr_1->next=newNode;
       ptr_1=newNode;
   }

   ptr_1=head_1;

   printList(ptr_1);

   return 0;
}
