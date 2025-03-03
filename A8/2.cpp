#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class CircularQueue 
{
public:
    Node* front;
    Node* rear;

    CircularQueue() 
    {
        front = rear = NULL;
    }

    void enqueue(int data) 
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (rear == NULL) 
        {
            front = rear = newNode;
            rear->next = front;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    void dequeue() 
    {
        if (front == NULL) 
        {
            return;
        }

        if (front == rear) 
        {
            delete front;
            front = rear = NULL;
            return;
        } 

        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }

    int peek() 
    {
        if (front == NULL) 
        {
            return -1;
        }
        return front->data;
    }

    bool isEmpty() 
    {
        return front == NULL; 
    }

    void display() 
    {
        if (front == NULL)
        {
            return;
        }

        Node* temp = front;
        do 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != front);
        cout << "(Back to Front)" << endl;
    }
};

int main() 
{
    CircularQueue cq;
    int choice, data;

    while (true) 
    {
        cout << "***************** Circular Queue operations *****************" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cq.enqueue(data);
                cq.display();
                break;

            case 2:
                cq.dequeue();
                cq.display();
                break;
            
            case 3:
                cout << "Front element: " << cq.peek() << endl;
                break;

            case 4:
                cout << "Queue is empty: " << cq.isEmpty() << endl;
                break;

            case 5:
                cq.display();
                break;

            case 6:
                cout << "Exiting..." << endl;
                exit(0);        

            default:
                cout << "Invalid choice" << endl;
        }
    }
}
