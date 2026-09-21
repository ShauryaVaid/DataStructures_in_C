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
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    return head;
}

void traverse(node *head){
    node *temp=head;
    while (temp!=NULL){
        printf("%d-> ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

node *inputatfirst(node *head){
    int am;
    printf("Enter the data of the first node: ");
    scanf("%d",&am);
    node *newnode=(node*)malloc(sizeof(node));
    newnode->val=am;
    newnode->next=head;
    head=newnode;
    return head;
}

node *inputatlast(node *head){
    int am;
    printf("Enter the data of the last node: ");
    scanf("%d",&am);
    node *newnode=(node*)malloc(sizeof(node));
    newnode->val=am;
    newnode->next=NULL;
    node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=newnode;
    return head;
}

node *inputatanypos(node *head){
    int am,pos,count;
    printf("Enter the Position of the node: ");
    scanf("%d",&pos);
    printf("Enter the data of the node: ");
    scanf("%d",&am);
    count=1;
    if(pos==1){
        head = inputatfirst(head);
        return head;
    }
    else{
        node *newnode=(node*)malloc(sizeof(node));
        newnode->val=am;
        newnode->next=NULL;
        node* prev,*curr;
        prev=head;
        curr=head->next;
        while(count<pos-1){
            curr=curr->next;
            prev=prev->next;
            count++;
        }
        newnode->next=curr;
        prev->next=newnode;
    }
    return head;
}

node *deleteatfirst(node *head){
    node *temp=head;
    head=temp->next;
    free(temp);
    return head;
}

node *deleteatlast(node *head){
    // If there is only one node, delete it and return NULL
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node *curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    free(curr->next);
    curr->next=NULL;
    return head;
}

node *deleteatbtw(node *head){
    int pos,count=1;
    printf("Enter the Position of the node: ");
    scanf("%d",&pos);
    if(pos==1){
        deleteatfirst(head);
        return head;
    }
    else{
        node *prev,*curr;prev=head;curr=head->next;
        while(count<pos-1){
            curr=curr->next;
            prev=prev->next;
            count++;
        }
        prev->next=curr->next;
        free(curr);
    }
    return head;
}

node *midnode(node *head){
    node *slow,*fast;slow=head;fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

/*node *sort(node *head){
    if (head == NULL || head->next == NULL) 
        return head;
    node *temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->val>temp->next->val){
            int tem=temp->val;
            temp->val=temp->next->val;
            temp->next->val=tem;
        }
        temp=temp->next;
    }
    return head;
}*/

node *reverse(node *head){
    node *prev,*curr,*next;
    prev=NULL;
    curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    int choice,k=0;
    node *head=NULL;
    while(k==0){
        printf("1->create, 2->traverse, 3->inputatfirst, 4->inputatlast, 5->inputatanypos, 6->deleteatfirst, 7->deleteatlast, 8->deleteatbtw, 9->mid, 10->sort, 11->reverse: \n");
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
                head=inputatanypos(head);
                break;
            }
            case 6:
            {
                head=deleteatfirst(head);
                break;
            }
            case 7:
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
            }
        }
        printf("to continue press 0, else any number to stop: \n");
        scanf("%d",&k);
    }
}