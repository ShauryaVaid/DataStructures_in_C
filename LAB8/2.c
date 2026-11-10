#include <stdio.h>
#include <stdlib.h>

// Define structure for Priority Queue node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

// Enqueue operation: Insert element based on priority
void enqueue() {
    int val, pri;
    printf("Enter data: ");
    scanf("%d", &val);
    printf("Enter priority (lower number = higher priority): ");
    scanf("%d", &pri);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->priority = pri;
    newNode->next = NULL;

    // If queue is empty or new node has higher priority than front
    if (front == NULL || front->priority > pri) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= pri) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Element inserted successfully!\n");
}

// Dequeue operation: Remove the highest priority element
void dequeue() {
    if (front == NULL) {
        printf("Priority Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted Element: %d (Priority: %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

// Traverse operation: Display all elements in the priority queue
void traverse() {
    if (front == NULL) {
        printf("Priority Queue is Empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Priority Queue elements (Data [Priority]):\n");
    while (temp != NULL) {
        printf("%d [Pri: %d] -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Quit\n");
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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}