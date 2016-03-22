//binary search not possible in a linked list since there is no O(1) retrieval in linked lists
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}list;

int main()
{
    int n;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);

    printf("Enter the elements in sorted order for the linked list creation\n");
    list *start=NULL;
    list *ptr=NULL;

    while(n >0)
    {
        if(start==NULL)
        {
            start= (list *)calloc(1,sizeof(list));
            list *newNode=(list *)calloc(1,sizeof(list));
            scanf("%d",&newNode->data);
            start=newNode;
            ptr=newNode;
        }
        else
        {
            list *newNode=(list *)calloc(1,sizeof(list));
            scanf("%d",&newNode->data);
            ptr->next=newNode;
            ptr=newNode;
        }
        n--;
    }

    int search;
    printf("Now enter the no. you want to search\n");
    scanf("%d",&search);
    ptr=start;

    while(ptr!=NULL)
    {
        if(ptr->data==search)
        {
            printf("Found");
            break;
        }
        ptr=ptr->next;
    }

    if(ptr==NULL)
    {
        printf("Not Found");
    }

    getch();
    return 1;
}
