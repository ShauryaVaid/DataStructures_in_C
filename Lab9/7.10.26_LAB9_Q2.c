/*i. insert an element to the BST
ii. display the largest_element
iii. display the smallest_element
iv. height of a node
v. count number of leaf nodes*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
node *root=NULL;
node* insert(node *curr, int val) {
    if (curr==NULL) {
        node *newnode =(node*)malloc(sizeof(node));
        newnode->data =val;
        newnode->left =NULL;
        newnode->right =NULL;
        return newnode;
    }
    
    if (val<curr->data) {
        curr->left = insert(curr->left, val);
    } 
    else if (val>curr->data) {
        curr->right = insert(curr->right, val);
    } 
    else {
        printf("Duplicate Entry!\n");
    }
    
    return curr;
}

void create() {
    int val;
    printf("Enter the value of the node: ");
    scanf("%d",&val);
    
    if (val==-1) {
        return;
    }
    
    root = insert(root,val);
}

void largest_element(node *root){
    if(root==NULL){
        printf("Empty");
        return;
    }
    node *curr=root;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    printf("%d",curr->data);
}

void smallest_element(node *root){
    if(root==NULL){
        printf("Empty");
        return;
    }
    node *curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    printf("%d",curr->data);
}

int height_of_a_node(node *curr){
    if(curr==NULL){
        return 0;
    }
    int l=height_of_a_node(curr->left);
    int r=height_of_a_node(curr->right);
    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
}

int count_number_of_leaf_nodes(node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return count_number_of_leaf_nodes(root->left) + count_number_of_leaf_nodes(root->right);
}

int main(){
    //menu driven pr.
    int extr;
    int choice=1;
    while(choice==1){
        printf("Yo! choose one: ,\n 1-> create, 2-> largest_element, 3->smallest_element, 4->height of a node, 5->count number of leaf nodes: ");
        scanf("%d",&extr);
        switch(extr){
            case 1:{
                create();
                break;
            }
            case 2:{
                largest_element(root);
                break;
            }
            case 3:{
                smallest_element(root);
                break;
            }
            case 4:{
                int heights;
                heights=height_of_a_node(root);
                printf("Count = %d",heights);
                break;
            }
            case 5:{
                int counts;
                counts=count_number_of_leaf_nodes(root);
                printf("Count = %d",counts);
                break;
            }
        }
        printf("\n");
        printf("Enter 1 if want to continue else any key: ");
        scanf("%d",&choice);
    }
    return 0;

}