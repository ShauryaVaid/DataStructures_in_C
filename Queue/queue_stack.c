#include<stdio.h>
#define Max 4
int queue[Max];
int rear=-1;
int front=-1;

void enqueue(){
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);
    if(rear==Max-1){
        printf("Overflow");
        return;
    }
    else if(rear==-1 && front==-1){
        front++;rear++;
        queue[rear]=val;
    }
    else{
        rear++;
        queue[rear]=val;
    }
}

void dequeue(){
    
}