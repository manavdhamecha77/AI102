// Write a program in C to copy the elements of the array to a singly linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to convert an array to a linked list
node* ArrayToLinkedList(int n, int arr[]) {
    if (n == 0) {
        return NULL; // If the array is empty, return NULL
    }

    node* head = (node*)malloc(sizeof(node)); // Create the head node
    head->data = arr[0];
    head->next = NULL;

    node* current = head;

    for (int i = 1; i < n; i++) {
        node* newNode = (node*)malloc(sizeof(node)); // Create a new node
        newNode->data = arr[i];
        newNode->next = NULL;
        current->next = newNode; // Link the new node to the list
        current = newNode;
    }

    return head;
}

// Function to traverse and print the linked list
void TraverseLinkedList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Convert the array to a linked list
    node* head = ArrayToLinkedList(n, arr);

    // Traverse and print the linked list
    printf("Linked list: ");
    TraverseLinkedList(head);

    // Free the allocated memory
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
