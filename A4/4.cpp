
/*
Write a C/C++ program to implement doubly linked list with the following function :

(i) insertAtFirst(&head, new_data): This function should insert the new
data/element at the beginning of the linked list.

(ii) insertAtEnd(&head, new_data): This function should insert the new
data/element at the end of the linked list

(iii) insertAtMiddle(&head, new_data): This function should insert the new
data/element at the middle of the linked list

(iv) insertAfterNode(&head, given_node, new_data): This function should
insert the new data/element after the given node in the linked list.

Example: Suppose, you want to insert 60 after node 40 in the given linked

list 10 → 20 → 30 → 40 → 50, 
The updated linked list will be 10 → 20 → 30 → 40 → 60 → 50

(v) display(&head): This function should display the content of the linked list

*/

#include <iostream> 
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

void insertAtFirst(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    new_node->prev = NULL;

    if((*head) != NULL)
    {
        (*head)->prev = new_node;
    }

    (*head) = new_node;
}

void insertAtEnd(Node** head, int new_data)
{
    Node* new_node = new Node();
    Node* last = *head;
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void insertAtMiddle(Node** head, int new_data)
{
    Node* new_node = new Node();
    Node* slow = *head;
    Node* fast = (*head)->next;
    new_node->data = new_data;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    new_node->next = slow->next;
    slow->next = new_node;
    new_node->prev = slow;
    new_node->next->prev = new_node;
}

void insertAfterNode(Node** head, int given_node, int new_data)
{
    Node* new_node = new Node();
    Node* temp = *head;
    new_node->data = new_data;

    while(temp != NULL && temp->data != given_node)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Node not found in the linked list" << endl;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next->prev = new_node;
}

void display(Node* node)
{
    Node* last;
    cout << "Traversal in forward direction: ";
    while(node != NULL)
    {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }

    cout << endl;

    cout << "Traversal in reverse direction: ";
    while(last != NULL)
    {
        cout << last->data << " ";
        last = last->prev;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    insertAtFirst(&head, 40);
    insertAtFirst(&head, 50);
    insertAtFirst(&head, 60);
    


    cout << "Linked list after inserting at the beginning: ";
    display(head);

    insertAtEnd(&head, 60);
    cout << "Linked list after inserting at the end: ";
    display(head);

    insertAtMiddle(&head, 70);
    cout << "Linked list after inserting at the middle: ";
    display(head);

    insertAfterNode(&head, 40, 80);
    cout << "Linked list after inserting after node 40: ";
    display(head);

    return 0;
}
