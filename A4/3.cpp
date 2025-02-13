/*
Given a singly linked list of n nodes, detect if it contains a loop or not.
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

bool detectLoop(Node* head)
{
   /* 
   
   
   
   */
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

    // Create a loop for testing
    head->next->next->next->next = head;

    if(detectLoop(head))
    {
        cout << "\nLoop found in the linked list";
    }
    else
    {
        cout << "\nNo loop found in the linked list";
    }

    return 0;
}