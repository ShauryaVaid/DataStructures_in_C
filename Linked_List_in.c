#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct node {
    int data;
    struct node* next;
} node;

// Insert at beginning (matches your notes exactly)
node* insertAtFirst(node* start, int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        temp->next = start;
        start = temp;
    }
    return start; // Returns new head to main
}

// Insert at last without a tail pointer (O(n) time complexity)
node* insertAtLast(node* start, int val) {
    node* p;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    // Case 1: Empty list
    if (start == NULL) {
        start = temp;
    } 
    // Case 2: Non-empty list (traverse to the end)
    else {
        p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp; // Link the last node to the new node
    }
    return start;
}


// Display function
void display(node* start) {
    node* p = start;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    node* start = NULL; // Initially empty list

    start = insertAtFirst(start, 10);
    start = insertAtFirst(start, 5);

    display(start); // Output: 5 -> 10 -> NULL
    return 0;
}