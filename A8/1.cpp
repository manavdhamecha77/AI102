/*

*/

#include <iostream>
using namespace std;

struct Node 
{
    int data, priority;
    Node* next;
};

class PriorityQueue 
{
public:
    Node* front;
    
    PriorityQueue() 
    { 
        front = nullptr; 
    }

    void enqueue(int data, int priority) 
    {
        Node* temp = new Node{data, priority, nullptr};
        if (!front || priority < front->priority) 
        {
            temp->next = front;
            front = temp;
        } 
        else 
        {
            Node* current = front;
            while (current->next && current->next->priority <= priority)
                current = current->next;
            temp->next = current->next;
            current->next = temp;
        }
    }

    void dequeue() 
    {
        if (!front) 
        {
            cout << "Queue is empty.\n";
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek() 
    {
        return front ? front->data : -1;
    }

    bool isEmpty() 
    { 
        return front == nullptr; 
    }

    void display() 
    {
        if (!front) 
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;

        while (temp) 
        {
            cout << "[" << temp->data << " (Priority: " << temp->priority << ")] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() 
{
    PriorityQueue pq;
    int choice, data, priority;

    while (true) 
    {
        cout << "\nPriority Queue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority: ";
                cin >> priority;
                pq.enqueue(data, priority);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                cout << "Front element: " << pq.peek() << endl;
                break;
            case 4:
                pq.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}