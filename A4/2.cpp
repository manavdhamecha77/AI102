
/*
Given an unsorted linked list of n nodes, remove duplicates from the list.
*/

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

// Insert a new node at the beginning
void push(Node** head, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

// Print the linked list
void printList(Node* node)
{
    while(node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    printf("NULL");
}

// Sort the linked list
void sortList(Node* head)
{
    Node* current = head;
    Node* index = NULL;
    int temp;

    if(head == NULL)
    {
        return;
    }
    else
    {
        // Traverse the linked list
        while(current != NULL)
        {
            // Compare each node with the rest of the linked list
            index = current->next;

            while(index != NULL)
            {
                // Swap the data if the current node is greater than the next node
                if(current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                // Move to the next node
                index = index->next;
            }
            // Move to the next node
            current = current->next;
        }
    }
}

// Remove duplicates from the linked list
void removeDuplicates(Node* head)
{
    Node* current = head;
    Node* next_next;

    if(current == NULL)
    {
        return;
    }

    while(current->next != NULL)
    {
        // Compare the current node with the next node
        if(current->data == current->next->data)
        {
            // Delete the next node if the data is the same
            next_next = current->next->next;
            delete current->next;
            current->next = next_next;
        }
        else
        {
            // Move to the next node
            current = current->next;
        }
    }
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

    sortList(head);
    removeDuplicates(head);

    cout << "\nLinked list after removing duplicates: ";
    printList(head);

    return 0;
}
