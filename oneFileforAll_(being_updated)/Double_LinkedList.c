#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *prev;
    struct node *next;
}node;

node *create(int n){
    node *head=NULL;
    node *temp=NULL;;
    printf("Enter the values of the nodes: ");
    for(int i=0; i<n; i++){
        node *newnode= (node*)malloc(sizeof(node));
        newnode->next = NULL;
        scanf("%d",&newnode->val);
        if(head==NULL){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    return head;
}

void traverse(node *head){
    printf("\nForward Traversal of created list:\n");
    node *curr = head;
    while (curr != NULL) {
        printf("%d <-> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
    return;
}

node *inputatfirst(node *head){
    if(head==NULL){
        printf("Enter the value of the node: ");
        node *newnode= (node*)malloc(sizeof(node));
        scanf("%d",&newnode->val);
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }
    printf("Enter the value of the node: ");
    node *newnode= (node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->prev=NULL;
    scanf("%d",&newnode->val);
    node *temp=head;
    newnode->next=temp;
    temp->prev=newnode;
    head=newnode;
    return head;
}

node *inputatlast(node *head){
    if(head==NULL){
        printf("Enter the value of the node: ");
        node *newnode= (node*)malloc(sizeof(node));
        scanf("%d",&newnode->val);
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }
    else{
        printf("Enter the value of the node: ");
        node *newnode= (node*)malloc(sizeof(node));
        scanf("%d",&newnode->val);
        newnode->next=NULL;
        newnode->prev=NULL;

        node *temp=head;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        return head;
    }
}

node *inputatanypos(node *head, int n){
    int pos;
    printf("Enter the position where u would like to insert the node: ");
    scanf("%d",&pos);
    if(pos==1){
        head=inputatfirst(head);
        return head;
    }
    else if(pos==n){
        head=inputatlast(head);
        return head;
    }
    node *newnode= (node*)malloc(sizeof(node));
    printf("Enter the value of the newnode: ");
    scanf("%d",&newnode->val);
    newnode->next=NULL;
    newnode->prev=NULL;
    node *prev,*curr; prev=head; curr=head->next;
    int count=1;
    while(count<pos-1){
        prev=prev->next;
        curr=curr->next;
        count++;
    }
    newnode->next=curr;
    curr->prev=newnode;
    newnode->prev=prev;
    prev->next=newnode;
    return head;
}

node *deleteatfirst(node *head){
    node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    int choice,k=0;
    node *head=NULL;
    while(k==0){
        printf("1->create, 2->traverse, 3->inputatfirst, 4->inputatlast, 5->inputatanypos, 6->deleteatfirst, 7->deleteatlast, 8->deleteatbtw, 9->mid, 10->sort, 11->reverse: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                head=create(n);
                break;
            }
            case 2:
            {
                traverse(head);
                break;
            }
            case 3:
            {
                head = inputatfirst(head);
                break;
            }
            case 4:
            {
                head= inputatlast(head);
                break;
            }
            case 5:
            {
                head=inputatanypos(head,n);
                break;
            }
            case 6:
            {
                head=deleteatfirst(head);
                break;
            }
            /*case 7:
            {
                head=deleteatlast(head);
                break;
            }
            case 8:
            {
                head=deleteatbtw(head);
                break;
            }
            case 9:
            {
                node *mid;
                mid=midnode(head);
                printf("printing from mid to last");
                head=mid;
                break;
            }
            case 10:
            {
                head=sort(head);
                break;
            }
            case 11:
            {
                head=reverse(head);
                break;
            }*/
        }
        printf("to continue press 0, else any number to stop: \n");
        scanf("%d",&k);
    }
}