#include <stdio.h>
#include <stdlib.h>

//This program creates a new binary tree asking the user where to add the new value

typedef struct binaryTree
{
    struct binaryTree *left;
    int data;
    struct binaryTree *right;
}tree;

void buildTree(tree *);
void inOrderTraversal(tree *);

int main()
{

    printf("Creating a binary search tree here folks, enter the rood node\n");
    tree *root= (tree *)calloc(1,sizeof(tree));

    scanf("%d",&root->data);
    root->left=NULL;
    root->right=NULL;

    tree *ptr=root;

    char choice='y';
    char branchChoice;

    while(choice=='y')
    {
        printf("Do you want to continue adding nodes to the tree ? \n");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y')
        {
            buildTree(root);
        }
    }

    printf("In-order traversal of tree is as follows\n");
    inOrder(root);
    return 1;
}

void inOrder(tree *ptr)
{
    if(ptr!=NULL)
    {
        inOrder(ptr->left);
        printf("%d ",ptr->data);
        inOrder(ptr->right);
    }
}

void buildTree(tree *ptr)
{
    char branchChoice;
    printf("Enter the new value\n");

    tree *newNode= (tree *)calloc(1,sizeof(tree));
    tree *par=ptr;
    fflush(stdin);
    scanf("%d",&newNode->data);
    char childPosition;

    while(ptr!=NULL)
    {
        if(newNode->data >  ptr->data)
        {
            par=ptr;
            ptr=ptr->right;
            childPosition='r';
        }
        else
        {
            par=ptr;
            ptr=ptr->left;
            childPosition='l';
        }
    }
    if(childPosition=='l') par->left=newNode;
    else par->right=newNode;

}

