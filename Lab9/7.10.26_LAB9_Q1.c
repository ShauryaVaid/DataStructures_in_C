#include<stdio.h>
#include<stdlib.h>
/*9.1 Write a program to create a binary search tree of n data elements using linked list and perform the following menu driven operations:
i. preorder traversal 
ii. postorder traversal
iii. inorder traversal
iv. search an element */
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
node *root=NULL;
node* insert(node *curr, int val) {
    if (curr == NULL) {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
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
    
    root = insert(root, val);
}

void preorder(node *root){
    if(root==NULL)return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void postorder(node *root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

void search(node *root, int val) {
    node *temp = root;
    while (temp != NULL) {
        if (val == temp->data) {
            printf("found\n");
            return;
        } 
        else if (val < temp->data) {
            temp = temp->left;
        } 
        else {
            temp = temp->right;
        }
    }
    printf("Element not found\n");
}

int main(){
    //menu driven pr.
    int extr;
    int choice=1;
    while(choice==1){
        printf("Yo! choose one: ,\n 1-> create, 2-> preorder, 3->inorder, 4->postorder, 5->search: ");
        scanf("%d",&extr);
        switch(extr){
            case 1:{
                create();
                break;
            }
            case 2:{
                preorder(root);
                break;
            }
            case 3:{
                inorder(root);
                break;
            }
            case 4:{
                postorder(root);
                break;
            }
            case 5:{
                int val;
                printf("Enter value u wuld like to search:\n");
                scanf("%d",&val);
                search(root,val);
                break;
            }
        }
        printf("\n");
        printf("Enter 1 if want to continue else any key: ");
        scanf("%d",&choice);
    }
    return 0;

}