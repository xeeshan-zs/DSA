#include <iostream>
using namespace std;

#define MAX 5  // Define maximum size of stack

class Stack {
private:
    int arr[MAX]; // Array to store stack elements
    int topIndex; // Index of the top element

public:
    // Constructor
    Stack() {
        topIndex = -1; // Stack is empty initially
    }

    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Check if stack is full
    bool isFull() {
        return topIndex == MAX - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << "." << endl;
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed into the stack." << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << arr[topIndex] << " popped from the stack." << endl;
        topIndex--;
    }

    // Get the top element of the stack
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
            return -1; // Return an invalid value
        }
        return arr[topIndex];
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.display();

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;

    return 0;
}
