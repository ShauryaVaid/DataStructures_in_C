#include<stdio.h>
#include<stdlib.h>

typedef struct prac{
    int data;
    struct prac *next;
}prac;


// if question specifically says:
// before pos=k;
// after pos=k+1;
prac *insertatpos(prac *head){
    int pos,val;
    printf("Enter the position where u would like to insert: ");
    scanf("%d",&pos);
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    printf("Enter the number u would like to insert: ");
    scanf("%d",&val);
    prac *newNode= (prac*)malloc(sizeof(prac));
    newNode->data=val;
    newNode->next=NULL;
    if(pos==1){
        newNode->data=val;
        newNode->next=head;
        return newNode;
    }
    prac *temp= head;
    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    
    temp->next=newNode;
    return head;
}

prac *delatpos(prac *head){
    if(head==NULL){
        printf("Underflow!");
        return head;
    }
    int pos,count=1;
    printf("Enter the position of the node u would like to delete: ");
    scanf("%d",&pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if(pos==1){
        prac *temp;
        temp=head;
        head=head->next;  
        free(temp);
        return head;
    }
    prac *prev=head;
    prac *curr=head;
    while(count!=pos && curr != NULL){
        prev=curr;
        curr=curr->next;
        count++;
    }
    if (curr == NULL) {
        printf("Position outside the linked list!\n");
        return head;
    }
    prev->next=curr->next;
    free(curr);
    return head;
}

void Display(prac *head,int n){
    prac *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
    return;
}

//find mid node of the list (class notes-->20/8/26)
prac *midnode(prac* head){
    prac *slow,*fast;
    slow=fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// find n/3rd node of the list  (class notes-->20/8/26)
prac* n3node(prac* head){
    prac *slow,*fast;
    slow=head;
    fast=head->next->next;
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next->next;
    }
    return slow;
}

int main(){
    prac *head=NULL;;
    int n,val;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements of the node: ");
    for(int i=0; i<n; i++){
        scanf("%d",&val);
        prac *newNode= (prac*) malloc(sizeof(prac));
        if(newNode==NULL){
            printf("Memory allocation failed!");
        }
        newNode->data=val;
        newNode->next=NULL;

        if (head==NULL){
            head=newNode;
        }
        else{
            prac *temp =head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next= newNode;
        }
    }
    //add at any pos
    int l;
    printf("Enter the options from the below Menu: \n");
    printf("------Menu:------ \n");
    printf("Insertion(limitless)--> 1\nDeletion(limitless)--> 2\nDisplay--> 3\nTo_Find_Midnode--> 4\nTo Stop--> -1\n");
    while(l!=-1){
        printf("Here ur choice--> ");
        scanf("%d",&l);
        switch (l)
        {
        case 1:
        {
            head = insertatpos(head);
            break;
        }
        case 2: 
        {
            head = delatpos(head);
            break;
        }
        case 3:
        {
            Display(head,n);
            break;
        }
        case 4:
        {
            midnode(head);
            break;
        }
        case 5:
        {
            n3node(head);
            break;
        }
        default:
            printf("Invalid option entered.\n");
            break;
        }
    }
    return 0;
}