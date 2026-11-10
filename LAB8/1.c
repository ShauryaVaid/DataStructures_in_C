#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert at right (Rear insertion)
void insertRear(int val) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert.\n");
        return;
    }
    if (front == -1) { // First element
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0; // Wrap around
    } else {
        rear++;
    }
    deque[rear] = val;
}

// Delete from left (Front deletion)
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Deque is empty.\n");
        return;
    }
    printf("Deleted element from left: %d\n", deque[front]);
    if (front == rear) { // Single element left
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0; // Wrap around
    } else {
        front++;
    }
}

// Delete from right (Rear deletion)
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Deque is empty.\n");
        return;
    }
    printf("Deleted element from right: %d\n", deque[rear]);
    if (front == rear) { // Single element left
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1; // Wrap around
    } else {
        rear--;
    }
}

// Display elements in the Deque
void display() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    
    do {
        printf("\nInput restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                deleteRear();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}