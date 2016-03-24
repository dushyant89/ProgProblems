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
int max_diff=0;
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
    printf("\n");

    printf("Now lets check for the height balancing\n");
    checkBalanceFactor(root);
    if(max_diff >1) {
        printf("tree is unbalanced with balance factor of %d\n",max_diff);
    }
    else {
        printf("tree is balanced\n");
    }

    return 1;
}

int max(int a,int b) {
    return (a > b) ? a : b;
}


int checkBalanceFactor(tree *ptr) {

    int height=0; int temp=0;
    if(ptr->left!=NULL){
        height=1+checkBalanceFactor(ptr->left);
    }
    if(ptr->right!=NULL){
        temp=1+checkBalanceFactor(ptr->right);
    }
    if(temp >height) {
        max_diff=max(temp-height,max_diff);
    }
    else if(temp <height) {
        max_diff=max(height-temp,max_diff);
    }

    return max(height,temp);
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

