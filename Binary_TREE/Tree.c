#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *create(){
    int val;
    printf("Enter the value of the node: ");
    scanf("%d",&val);
    if(val==-1){
        return NULL;
    }
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    printf("Enter the Left child of %d\n",newnode->data);
    newnode->left=create();
    printf("Enter the Right child of %d\n",newnode->data);
    newnode->right=create();
    return newnode;
}

int main(){
    node *root=NULL;
    root=create();
    return 0;
}