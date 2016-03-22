#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct trie {

char V;
struct trie *next;
struct trie *child;

}trie;

typedef struct Dictionary
{
    trie *root;
}dict;

int l,d,n;

void prepareTrie(char *input,trie *ptr)
{
    input[-1]='1';
    int breakChild=0;
    int breakNext=0;

     int j; int insertNew=0;
     for(j=-1;j<l;j++)
     {
        if(!insertNew)
        {
             while(1)
             {
                if(ptr->V==input[j])
                {
                    j++;  //incrementing j since it is already there
                    if(ptr->child!=NULL)
                    {
                        ptr=ptr->child;
                    }
                    else
                    {
                        breakChild=1;
                        break;
                    }
                }
                else
                {
                    if(ptr->next!=NULL)
                    {
                        ptr=ptr->next;
                    }
                    else
                    {
                        breakNext=1;
                        break;
                    }
                }
             }
             if(breakChild && j<l)
             {
                trie *newNode=(trie *)calloc(1,sizeof(trie));
                newNode->next=NULL;
                newNode->child=NULL;
                newNode->V=input[j];
                ptr->child=newNode;
                ptr=newNode;
                breakChild=0;
                insertNew=1;
             }
             else if(breakNext && j<l)
             {
                trie *newNode=(trie *)calloc(1,sizeof(trie));
                newNode->next=NULL;
                newNode->child=NULL;
                newNode->V=input[j];
                ptr->next=newNode;
                ptr=newNode;
                breakNext=0;
                insertNew=1;
             }
        }
        else
        {
            trie *newNode=(trie *)calloc(1,sizeof(trie));
            newNode->next=NULL;
            newNode->child=NULL;
            newNode->V=input[j];
            ptr->child=newNode;
            ptr=newNode;
        }
     }
}

int findMatch(char *prefix,trie *ptr)
{
    int len=strlen(prefix);
    int i;
    for(i=0;i<len;i++)
    {
        while(ptr!=NULL && i<len)
        {
            if(ptr->V!=prefix[i])
            {
               ptr=ptr->next;
            }
            else
            {
                ptr=ptr->child;
                i++;
            }
        }
        if(i<len)
        {
            return 0;
        }
        else if(i==len)
        {
            return 1;
        }
    }
}

void prepareTrieForPattern(char *pattern,trie *ptr)
{

     int j=0; int k;
     trie *stack_node=(trie *)calloc(l,sizeof(trie));
     int *stack_index=(int *)calloc(l,sizeof(int));
     int top=-1;
     int len=strlen(pattern);
     trie *newNode;
     for(k=0;k<len;k++)
     {
            if(pattern[k]=='(')
            {
                k++;
                //adding the first node between the paranthesis
                newNode=(trie *)calloc(1,sizeof(trie));
                newNode->next=NULL;
                newNode->child=NULL;
                newNode->V=pattern[k++];
                ptr->child=newNode;
                ptr=newNode;
                trie *save_ptr=ptr;
                int top_snapshot=top;
                while(pattern[k]!=')')
                {
                    newNode=(trie *)calloc(1,sizeof(trie));
                    newNode->next=NULL;
                    newNode->child=NULL;
                    newNode->V=pattern[k++];
                    ptr->next=newNode;
                    ptr=newNode;

                    if(k!=len-1)
                    {
                        ++top;
                        stack_node[top]=*newNode;
                    }
                }
                    while(k!=len-1 && top_snapshot <=top)
                    stack_index[++top_snapshot]=k;
                 ptr=save_ptr;
            }
            else
            {
                newNode=(trie *)calloc(1,sizeof(trie));
                newNode->next=NULL;
                newNode->child=NULL;
                newNode->V=pattern[k];
                ptr->child=newNode;
                ptr=newNode;
            }
          if(k==len-1)
          {
                if(top!=-1)
                {
                    ptr=&stack_node[top];
                    k=stack_index[top];
                    top--;
                }
          }
     }
}

int main() {

  scanf("%d",&l);
  scanf("%d",&d);
  scanf("%d",&n);

  int i;
  //start making trie from now onwards
   dict *words=(dict *)calloc(1,sizeof(dict));
   words->root=(trie *)calloc(1,sizeof(trie));
   words->root->child=NULL;
   words->root->next=NULL;
   words->root->V='1';

   trie *ptr=words->root;

   for(i=0;i<d;i++)
   {
     char *input=(char *)calloc(l,sizeof(char));
     scanf("%s",input);
     //initializing the first child of the trie
     prepareTrie(input,ptr);
   }

    //l*l+2*l is the maximum length of the pattern
    char *pattern=(char *)calloc(26*l+2*l,sizeof(char));
    int count;
    for(i=0;i<n;i++)
    {
        count=0;
        scanf("%s",pattern);
        int len=strlen(pattern);
        //prepare trie for the pattern also
        dict *language=(dict *)calloc(1,sizeof(dict));
        language->root=(trie *)calloc(1,sizeof(trie));
        language->root->child=NULL;
        language->root->next=NULL;
        language->root->V='1';

        trie *l_ptr=language->root;

        prepareTrieForPattern(pattern,l_ptr);

        l_ptr=language->root->child;

        //start finding the string which are there int the language dict
        char *key=(char *)calloc(l,sizeof(char));
        int key_ptr=0;
        trie *save_node=(trie *)calloc(l,sizeof(trie));
        int  *save_index=(int *)calloc(l,sizeof(int));
        int top=-1;
        //printf("traversing\n");
        while(l_ptr!=NULL)
        {
            key[key_ptr++]=l_ptr->V;
            if(l_ptr->next!=NULL)
            {
                ++top;
                save_node[top]=*l_ptr->next;
                save_index[top]=key_ptr-1;
            }

            l_ptr=l_ptr->child;

            if(l_ptr==NULL)
            {
                printf("key=%s\n",key);
                if(findMatch(key,words->root->child))
                   {
                      count++;
                   }
                 if(top!=-1)
                 {
                     l_ptr=&save_node[top];
                     key_ptr=save_index[top];
                     top--;
                 }
            }
        }

        printf("\nCase #%d: %d\n",i+1,count);
    }

  return 0;
}
