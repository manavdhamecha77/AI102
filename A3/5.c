// Write a C program that converts a singly linked list into an array and returns it.

#include<stdio.h>
#include<stdlib.h>

// Structure Declaration
typedef struct node
{
    int data;
    struct node* next;
}node;

// Function to input elements of a linked list
void InputLinkedList(int n,node* head)
{
    node* current = head; // Make current node as head to traverse

    for(int i=0;i<n-1;i++)
    {
        node* newNode = (node*) malloc(sizeof(node));

        // Get data for node
        printf("Enter data : ");
        scanf("%d",&newNode->data);
        // Make newNode next to current node
        current -> next = newNode;
        // newNode to Current node
        current = newNode; 
        current -> next = NULL;
    } 
}

void LinkedlistToArray(int n,int arr[n],node* head)
{
    node* temp = head; // Temperory ptr for traversing
    int i = 0;
    while(temp != NULL)
    {
        // Store linked list data in array
        arr[i] = temp->data;
        i++;
        temp = temp -> next;
    }
}

int main()
{
    // Input size of Linked List
    int n;
    printf("Enter size of the linked list : ");
    scanf("%d",&n);

    // Declare head node in main function itself
    node* head = (node*) malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d",&head->data);
    head->next = NULL;

    // Input elements of linked list
    InputLinkedList(n,head);

    int arr[n];

    // Store LL elements in array
    LinkedlistToArray(n,arr,head);

    // Display Array's elements
    printf("The elements of the Array are :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}