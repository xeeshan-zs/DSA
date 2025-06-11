#include <iostream>
using namespace std;

int Queue[5], n = 5, x, y, front = -1, rear = -1;

void enqueue() {
    if (rear == n - 1) {
        cout << "Queue is Full";
    } else {
        if (front == -1) {
            front = 0;
        }
        cout << "Insert the element in Queue: ";
        cin >> x;
        rear++;
        Queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Element deleted: " << Queue[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void Display() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue elements:" << endl;
        for (int i = front; i <= rear; i++) {
            cout << Queue[i] << endl;
        }
    }
}

void showFront() {
    if (front==-1) {   
        cout<<"Queue is Empty"<<endl;
    }else {
        cout<<"Front element is: "<<Queue[front]<<endl;
    }
}

int main() {

    enqueue();
    enqueue();

    Display();

}
