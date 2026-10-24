#include<stdio.h>
//7.1 Write a menu driven program to create a linear queue using array 
//and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.
#include<stdbool.h>
#define MAX 4
typedef struct queue{
    int items[MAX];
    int front;
    int rear;
}queue;

bool IsEmpty(queue *q){
    if(q->front==q->rear-1){
        return true;
    }
    else{
        return false;
    }
}

bool IsFull(queue *q){
    if(q->rear==MAX){
        return true;
    }
    else
        return false;
}

void Enqueue(queue *q){
    if(IsFull(q)){
        printf("Queue is Full\n");
        return;
    }
    int val;
    printf("Enter the valude u wuld like to ad din the queue: ");
    scanf("%d",&val);
    q->items[q->rear]=val;
    q->rear++;
}

void Traverse(queue *q){
    if(IsEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    for(int i=q->front+1;i<q->rear;i++){
        printf("%d ",q->items[i]);
    }
    printf("\n");
}

void Dequeue(queue *q){
    if(IsEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    q->front++;
}

int main(){
    queue *q;
    q->front=-1;     ////*****KEEP FRONT AND REAR SAME EITHER BOTH 0 OR -1 BUT BOTH********
    q->rear=0;
    IsEmpty(q);
    IsFull(q);
    Enqueue(q);
    Dequeue(q);
    Traverse(q);
}

