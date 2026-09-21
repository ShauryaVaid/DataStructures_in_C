#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;

void traverse(node *start){
    node *temp=start;
    while (temp->next!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
    return;
}

node *insert(node *start,int d,int pos)
{
    node *newNode=malloc(sizeof(node));
    newNode->data=d;
    newNode->next=NULL;
    if (pos==1){
        newNode->next=start;
        return newNode;
    }
    node *temp=start;
    int i;
    for (i=1;i<pos-1;i++){
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("Out of bounds.\n");
        free(newNode);
        return start;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return start;
}
node *delete(node *start,int pos)
{
    node *temp=start;
    int i;
    if (pos==1)
    {
        start=start->next;
        free(temp);
        return start;
    }
    for (i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL || temp->next==NULL)
    {
        printf("Out of bounds.\n");
        return start;
    }
    node *del=temp->next;
    temp->next=del->next;
    free(del);
    return start;
}
int count(node *start)
{
    node *temp=start;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
int main()
{
    node *head=NULL;
    node *last=NULL;
    int n,i;
    int choice;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for (i=0;i<n;i++)
    {
        node *temp=malloc(sizeof(node));
        scanf("%d",&temp->data);
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
            last=temp;
        }
        else
        {
            last->next=temp;
            last=temp;
        }
    }
    printf("MENU:\n1. Insert the node at a position\n2. Delete a node from specific position\n3. Count\n4. Traversal\n5. Exit\n");
    while(choice!=-1){
        printf("Enter choice: (to stop: -1)");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            int data,loc;
            printf("Enter element: ");
            scanf("%d",&data);
            printf("Enter position: ");
            scanf("%d",&loc);
            head=insert(head,data,loc);
            printf("Node inserted\n");
            break;
        }
        case 2: 
        {
            int loc;
            printf("Enter position: ");
            scanf("%d",&loc);
            head=delete(head,loc);
            printf("Node deleted\n");
            break;
        }
        case 3:
        {
            int total_nodes=count(head);
            printf("The total number of nodes: %d\n",total_nodes);
            break;
        }
        case 4: 
        {
            if (head==NULL)
            {
                printf("The list is empty.\n");
                break;
            }
            printf("The list is: ");
            traverse(head);
            break;
        }
        case 5:
        {
            break;
        }
        default:
            printf("Invalid option entered.\n");
            break;
        }
    }
    return 0;
}