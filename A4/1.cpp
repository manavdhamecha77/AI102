/*
Given a linked list of n nodes and an integer k, write a function to rotate the
linked list counter clockwise by k nodes.
*/ 

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** head, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(Node* node)
{
    while(node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    printf("NULL");
}

Node* rotate(Node* head, int k)
{
    pass;
}

int main()
{
    Node* head = NULL;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter data : ";
        cin >> data;
        push(&head, data);
    }

    cout << "Given linked list: ";
    printList(head);

    int k;
    cout << "\nEnter the number of nodes to rotate: ";
    cin >> k;

    head = rotate(head, k);

    cout << "\nRotated linked list: ";
    printList(head);
    
    return 0;
}