#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL; // Global head pointer

// Insert at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Points to itself
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    cout << value << " inserted at the end." << endl;
}

// Insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    cout << value << " inserted at the beginning." << endl;
}

// Delete from the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    if (head->next == head) { // Only one node in the list
        head = NULL;
    } else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    cout << temp->data << " deleted from the beginning." << endl;
    delete temp;
}

// Delete from the end
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (head->next == head) { // Only one node
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
    cout << temp->data << " deleted from the end." << endl;
    delete temp;
}

// Display the circular linked list
void display() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    display();

    deleteAtBeginning();
    display();

    deleteAtEnd();
    display();

    return 0;
}
