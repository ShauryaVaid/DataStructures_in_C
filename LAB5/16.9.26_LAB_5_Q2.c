//Write a program to create a circular linked list and display the elements of the list. 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;

node *create(){
    int n,data;
    node *head=NULL;
    printf("no. of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements for the corresponding nodeeeeeeeeeeee: ");
    for(int i=0; i<n; i++){
        scanf("%d",&data);
        node *newnode=(node*)malloc(sizeof(node));
        if(newnode==NULL){
            printf("MEMORY ALLOCATION FAILED!");
        }
        newnode->val=data;
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else{
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        newnode->next=head;
    }
    return head;
}

void traverse(node *head){
    if(head == NULL)
        return;
    node *temp=head;
    printf("%d-> ",temp->val);
    temp=temp->next;
    while(temp!=head){
        printf("%d-> ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int choice,k=0;
    node *head=NULL;
    while(k==0){
        printf("1->create, 2->traverse: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                head=create();
                break;
            }
            case 2:
            {
                traverse(head);
                break;
            }
        }
        printf("to continue press 0, else any number to stop: \n");
        scanf("%d",&k);
    }
}