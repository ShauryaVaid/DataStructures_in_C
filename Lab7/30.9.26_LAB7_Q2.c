#include<stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
}Queue;

void enqueue(Queue q, int data){
    Node *node= newNode(data);
    if(isEmpty(q)){
        q->front=q->rear=node;
        
    }
}