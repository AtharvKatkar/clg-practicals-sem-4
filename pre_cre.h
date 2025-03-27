//insert/postorder

#include<stdio.h>
#include<stdlib.h>

struct node;
{
    int data;
    struct node *left,*right;
    

}

struct node* createnode(int data)
{
    struct node* newnode=(struct node*)malloc(size of(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    return createnode(data);
    if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);

}

void preorder(struct node* root)
{
if(root==NULL)
{
    return;
}
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}