#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *top=NULL;

node *push(node *top){
    int data;
        node *newnode=(node*)malloc(sizeof(node));
        if(newnode==NULL){
            printf("STACK OVERFLOW");
            return top;
        }
        printf("Enter the value for the newnode: ");
        scanf("%d",&data);
        newnode->data=data;
        node *temp=top;
        newnode->next=top;
        top=newnode;
    return top;
}

node *pop(node *top){
    if(top==NULL){
            printf("STACK UNDERFLOW");
            return top;
        }
    node *temp=top;
    top=top->next;
    printf("POPED DATA %d \n",temp->data);
    free(temp);
    return top;
}

void print(node *top){
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    node *temp=top;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

node *reverse(node *top){
    node *prev,*curr,*next;
    prev= NULL;
    curr=top;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    node *data;
    int extr;
    int choice=1;
    while(choice==1){
        printf("What Stack operation would u like to go with, 1-> PUSH, 2-> POP, 3->Traverse, 4->Reverse: ");
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
                print(top);
                break;
            }
            case 4:{
                top=reverse(top);
                break;
            }
        }
        printf("Enter 1 if want to continue else any key: ");
        scanf("%d",&choice);
    }
    return 0;
}