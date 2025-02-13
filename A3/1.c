// Write a program in C to create and display a Singly link list.

#include <stdio.h>
#include <stdlib.h>

// Define a typedef for struct Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to display the linked list
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

    // Display the linked list
    printf("Linked list: ");
    DisplayList(head);

    // Free the allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
