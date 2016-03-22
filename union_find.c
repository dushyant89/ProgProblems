#include<stdio.h>
#include<stdlib.h>
/*
*******Union find algorithm
using linked lists
*/
typedef struct node {
     int val;
     struct node *next;
     struct node *parent;
     int size;
}node;

node *list;

int union_find(int i,int j)
{
    if(list[i].parent->val!=list[j].parent->val)
    {
       //merging the lists
        node* ptr_1, *ptr_2;
        printf("%d %d\n",list[i].val,list[j].val);
        short int select;
        if(list[i].parent->size >=list[j].parent->size)
        {
           ptr_1=list[i].parent;
           ptr_2=list[j].parent;
           select=1;
        }
        else
        {
            ptr_1=list[j].parent;
            ptr_2=list[i].parent;
            select=0;
        }
        while(ptr_1->next!=NULL)
        {
            ptr_1=ptr_1->next;
            printf("%d->",ptr_1->val);
        }
        ptr_1->next=ptr_2;
        while(ptr_2!=NULL)
        {
            if(select)
            {
              ptr_2->parent=list[i].parent;
              list[i].parent->size++;
            }
            else
             {
                ptr_2->parent=list[j].parent;
                list[j].parent->size++;
             }
             printf("%d->",ptr_2->val);
            ptr_2=ptr_2->next;
        }
        printf("\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
   printf("Lets create the graph where the cycle has to be detected\n");
   int graph[4][4]={{0,1,0,1},{1,0,1,1},{0,1,0,0},{1,1,0,0}};
   int size=4;int i,j;

   list=(node *)calloc(size,sizeof(node));

   for(i=0;i<size;i++)
    {
        list[i].val=i+1;
        list[i].parent=&list[i];
        list[i].next=NULL;
    }

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
           if(graph[i][j]!=0 && j!=i)
           {
               if(!union_find(i,j))
               {
                   printf("There is a cycle in the graph");
                   break;
               }
           }
           graph[j][i]=0;
        }
    }

  return 0;
}
