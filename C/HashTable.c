#include<stdio.h>
#include<stdlib.h>

//this program implements a hash table for an integer key
//using a binary search tree

typedef struct hashTable {
    int key;
    struct hashTable *left;
    struct hashTable *right;
    char names[20];

}hashTable;

void buildTree(hashTable *root)
{
    char choice='y';
    printf("Do you want to enter any more values \n");
    fflush(stdin);
    scanf("%c",&choice);
    while(choice=='y')
    {
        printf("Enter the value for the key, three digit code!\n");
        hashTable *newNode= (hashTable *)calloc(1,sizeof(hashTable));
        scanf("%d",&root->key);

        fflush(stdin);
        printf("Enter the value!\n");
        scanf("%s",root->names);

        hashTable *ptr=root;
        hashTable *parent;
        char childPos='r';

        while(ptr!=NULL)
        {
            parent=ptr;
            if(newNode->key > ptr->key)
            {
                ptr=ptr->right;
            }
            else
            {
                ptr=ptr->left;
                childPos='l';
            }
        }
        if(childPos=='l') parent->left=newNode;
        else parent->right=newNode;

        printf("Do you want to enter any more values \n");
        fflush(stdin);
        scanf("%c",&choice);
    }
}

char* getHashTable(hashTable *root,int key)
{
    hashTable *ptr=root;
    while(ptr!=NULL)
    {
        if(key > ptr->key)
        {
            ptr=ptr->right;
        }
        else if(key < ptr->key)
        {
            ptr=ptr->left;
        }
        else
        {
            return ptr->names;
        }
    }

    if(ptr==NULL)
    {
        return "Nothing found, you can insert this key";
    }
}

int main()
{
    printf("Enter the value for the key, three digit code!\n");
    hashTable *root= (hashTable *)calloc(1,sizeof(hashTable));
    scanf("%d",&root->key);

    fflush(stdin);
    printf("Enter the value!\n");
    scanf("%s",root->names);

    buildTree(root);

    printf("*******Now that the tree is prepared, lets retrieve values*******\n");
    printf("Enter the key\n");
    int key;
    fflush(stdin);
    scanf("%d",&key);

    printf("%s",getHashTable(root,key));

    return 1;
}
