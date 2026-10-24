#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;

node* create_Tree(node *root){
    int val;
    node *new_node= (node*)malloc(sizeof(node));
    printf("Enter the value of the node:\n");
    scanf("%d",&val);
    new_node->data=val;
    new_node->right=NULL;
    new_node->left=NULL;

    if(root==NULL){
        return new_node;
    }
    node *curr=root;
    while(curr!=NULL){
        if(val>curr->data && curr->left==NULL){
            curr->left=new_node;
            break;
        }
        else if(val<curr->data && curr->right==NULL){
            curr->right=new_node;
            break;
        }
        else if(val>curr->data){
            curr=curr->left;
        }
        else if(val<curr->data){
            curr=curr->right;
        }
        else{
            printf("Duplicate value ignored.\n");
            free(new_node);
            break;
        }
    }
    return root;
}
/*
int count(node *root){
    if(root==NULL){
        return 0;
    }
    int l=count(root->left);
    int r=count(root->right);
    return l+r+1;
}
*/
void traversal(node *root){
    if(root==NULL){
        return 0;
    }
    node *temp=root;
    traversal(temp->left);
    printf("%d-> ",root->data);
    traversal(temp->right);
}
