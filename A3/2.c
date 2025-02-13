//  Write a program in C to insert a new node at the beginning of a Singly Linked List.

#include <stdio.h>
#include <stdlib.h>

// Define a typedef for struct Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert an element at the beginning of the linked list
void InsertBegin(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head; // Link the new node to the existing list
    *head = newNode;       // Update the head pointer
}

// Function to display elements of the linked list
void DisplayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Dynamic memory allocation for 3 nodes
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    // Input data for the nodes
    printf("Enter data for head node: ");
    scanf("%d", &head->data);
    head->next = second;

    printf("Enter data for second node: ");
    scanf("%d", &second->data);
    second->next = third;

    printf("Enter data for third node: ");
    scanf("%d", &third->data);
    third->next = NULL;

    // Display the initial list
    printf("Initial linked list: ");
    DisplayList(head);

    // Insert a new node at the beginning
    int data;
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    InsertBegin(&head, data);

    // Display the updated list
    printf("Updated linked list after insertion: ");
    DisplayList(head);

    // Free allocated memory to prevent memory leaks
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
