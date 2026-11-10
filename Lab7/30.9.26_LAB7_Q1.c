#include<stdio.h>
//7.1 Write a menu driven program to create a linear queue using array 
//and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
int isEmpty() {
    return (front == -1 || front > rear);
}
int isFull() {
    return (rear == MAX - 1);
}
void enqueue() {
    if (isFull()) {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }
    int val;
    printf("Enter element to insert: ");
    scanf("%d", &val);
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = val;
    printf("Element %d inserted successfully!\n", val);
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}
void traverse() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int choice;
    do {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Yes, the queue is empty.\n");
                } else {
                    printf("No, the queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull()) {
                    printf("Yes, the queue is full.\n");
                } else {
                    printf("No, the queue is not full.\n");
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter between 1 and 6.\n");
        }
    } while (choice != 6);
    return 0;
}
