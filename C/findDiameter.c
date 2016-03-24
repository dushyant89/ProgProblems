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

int max=0;

int f_max(int a,int b) {
    return (a>b) ?a :b;
}

int main()
{

    printf("Creating a binary tree here folks, enter the rood node\n");
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
    preOrder(root);
    printf("Diameter of tree is as follows %d",max);

    return 1;
}

int findDiameter(tree *ptr,tree *save) {
    if(ptr==NULL)  return 0;
    else if(ptr==save) {
        return findDiameter(ptr->left,save) + findDiameter(ptr->right,save);
    }
    else {
        return 1+ f_max(findDiameter(ptr->left,save),findDiameter(ptr->right,save));
    }

}

void preOrder(tree *ptr)
{
    if(ptr!=NULL)
    {

        int temp=findDiameter(ptr,ptr);
        max=f_max(temp,max);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
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
    scanf("%d",&newNode->data);
    while(ptr!=NULL)
    {
        if(ptr->left!=NULL && ptr->right!= NULL)
        {
                printf("Do you want to enter %d as the left (l) grand child or right (r) grand child of %d\n",newNode->data,ptr->data);
                fflush(stdin);
                scanf("%c",&branchChoice);
                if(branchChoice=='l')
                    ptr=ptr->left;
                else if(branchChoice=='r')
                    ptr=ptr->right;
        }
        else if(ptr->left!=NULL || ptr->right!= NULL)
        {
            if(ptr->left!=NULL)
            {
                printf("Do you want to enter %d as the left (l) grand child or right (r) child of %d\n",newNode->data,ptr->data);
                fflush(stdin);
                scanf("%c",&branchChoice);
                if(branchChoice=='l')
                    ptr=ptr->left;
                else if(branchChoice=='r')
                    {
                        ptr->right=newNode;
                        return;
                    }
            }
            else
            {
                printf("Do you want to enter %d as the left (l) child or right (r) grand child of %d\n",newNode->data,ptr->data);
                fflush(stdin);
                scanf("%c",&branchChoice);
                if(branchChoice=='l')
                    {
                        ptr->left=newNode;
                        return;
                    }
                else if(branchChoice=='r')
                    ptr=ptr->right;
            }
        }
        else
        {
            printf("Do you want to enter %d as the left (l) child or right (r)child of %d\n",newNode->data,ptr->data);
                fflush(stdin);
                scanf("%c",&branchChoice);
                if(branchChoice=='l')
                    ptr->left=newNode;
                else if(branchChoice=='r')
                    ptr->right=newNode;

                    return;
        }

        }
}

