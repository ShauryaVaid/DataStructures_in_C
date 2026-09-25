#include<stdio.h>
#include<stdlib.h>
/*6.2 Write a menu driven program to create a stack using linked list and perform the following operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements*/

typedef struct node{
    int data;
    struct node *next;
}node;

node *top=NULL;
node *push(node *top){
    int val;
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Stack OVERFLOW");
        return top;
    }
    printf("Enter the value u would like too push: ");
    scanf("%d",&val);
    newnode->data=val;
    node *temp=top;
    newnode->next=top;
    top=newnode;
    return top;
}

node *pop(node *top){
    if(top==NULL){
        printf("Stack UNDERFLOW\n");
        return top;
    }
    else{
        printf("Poped Data: %d\n",top->data);
        top=top->next;
        return top;
    }
}

node *isEmpty(node *top){
    if(top==NULL){
        printf("Stack IS EMPTY\n");
        return top;
    }
    else{
        printf("Stack is NOT EMPTY\n");
        return top;
    }
}

node *display(node *top){
    if(top==NULL){
        printf("Stack is Empty!\n");
        return top;
    }
    else{
        node *curr=top;
        while(curr!=NULL){
            printf("%d->",curr->data);
            curr=curr->next;
        }
        printf("\n");
    }
    return top;
}

int main(){
    node *data;
    int extr;
    int choice=1;
    while(choice==1){
        printf("What Stack operation would u like to go with, 1-> PUSH, 2-> POP, 3->Traverse, 4->IsEmpty: ");
        scanf("%d",&extr);
        switch(extr){
            case 1:{
                top=push(top);
                break;
            }
            case 2:{
                top=pop(top);
                break;
            }
            case 3:{
                display(top);
                break;
            }
            case 4:{
                top=isEmpty(top);
                break;
            }
        }
        printf("Enter 1 if want to continue else any key: ");
        scanf("%d",&choice);
    }
    return 0;
}