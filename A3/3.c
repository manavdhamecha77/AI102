// Write a program in C to traverse in a singly linked list.

#include<stdio.h>
#include<stdlib.h>

// Struct Declaration
typedef struct node
{
    int data;
    struct node* next; 
}node;

// Function to traverse the linked list
void TraverseLinkedList(node* head)
{

    node* temp = head;
    printf("Traversing the linked list : \n");
    while(temp!=NULL)
    {
        printf("%d \n",temp->data);
        temp = temp -> next;
    }
}


int main()
{
    // Memory Allocation for 3 nodes 
    node* head = (node*) malloc(sizeof(node));
    node* second = (node*) malloc(sizeof(node));
    node* third = (node*) malloc(sizeof(node));

    printf("Enter data for head node : ");
    scanf("%d",&head->data);
    head->next = second;

    printf("Enter data for second node : ");
    scanf("%d",&second->data);
    second->next = third;

    printf("Enter data for third node : ");
    scanf("%d",&third->data);
    third->next = NULL;

    // Traverse the linked list
    TraverseLinkedList(head);

    return 0;
}