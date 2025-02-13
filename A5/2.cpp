/*

Q2: Write a C/C++ code to implement stack with following operations using
array.

a) create () = Create a stack.
b) push() = Pushing (storing) an element on the stack
c) pop() = Removing (accessing) an element from the stack.
d) peek() = Get the top data element of the stack, without removing it
e) isFull() = Check if stack is full.
f) isEmpty() = Check whether the stack is empty, and return true or false.

Note: 
(i) Create a separate function for each of the operations defined above.
(ii) Define the stack as follows.

*/
#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* stack;

public:
    Stack(int size) {
        this->size = size;
        stack = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        stack[++top] = data;
        cout << data << " pushed to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << stack[top] << " popped from stack." << endl;
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return stack[top];
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, data;
    
    cout << "Enter stack size: ";
    cin >> size;

    Stack stack(size);

    while (true) {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Full\n";
        cout << "5. Check if Empty\n";
        cout << "6. Display Stack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 4:
                cout << (stack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 5:
                cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 6:
                stack.display();
                break;
            case 0:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
