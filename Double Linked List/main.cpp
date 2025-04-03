#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *pre;
};

node *head = nullptr;

// Insert at the beginning
void insert(int n) {
    node *newnode = new node;
    newnode->data = n;
    newnode->next = head;
    newnode->pre = NULL;

    if (head != NULL) {
        head->pre = newnode;
    }
    head = newnode;
}

// Insert at the end
void insertAtEnd(int n) {
    node *newnode = new node;
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->pre = NULL;
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->pre = temp;
}

// Insert at a specific position
void insertAtPos(int pos, int n) {
    if (pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }

    node *newnode = new node;
    newnode->data = n;

    if (pos == 1) {
        newnode->next = head;
        newnode->pre = NULL;
        if (head != NULL) {
            head->pre = newnode;
        }
        head = newnode;
        return;
    }

    node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position " << pos << " does not exist" << endl;
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    newnode->pre = temp;

    if (temp->next != NULL) {
        temp->next->pre = newnode;
    }

    temp->next = newnode;
}

// Print list in forward order
void print() {
    cout << "Data elements (Forward): ";
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print list in reverse order
void printReverse() {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Data elements (Reverse): ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->pre;
    }
    cout << endl;
}

// Search for an element
bool search(int n) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == n) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Delete at the beginning
void deleteAtBeg() {
    if (head == NULL) {
        cout << "Doubly linked list is empty" << endl;
        return;
    }

    node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->pre = NULL;
    }
    delete temp;
}

// Delete at the end
void deleteAtEnd() {
    if (head == NULL) {
        cout << "Doubly linked list is empty" << endl;
        return;
    }

    if (head->next == NULL) {  // If only one node exists
        delete head;
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->pre->next = NULL;
    delete temp;
}

// Delete at a specific position
void deleteAtPos(int pos) {
    if (head == NULL || pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }

    node *temp = head;
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->pre = NULL;
        }
        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position " << pos << " does not exist" << endl;
        return;
    }

    if (temp->next != NULL) {
        temp->next->pre = temp->pre;
    }

    if (temp->pre != NULL) {
        temp->pre->next = temp->next;
    }

    delete temp;
}


int main() {
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insertAtEnd(12);
    insertAtPos(3, 15);

    print();
    printReverse();

    int valueToSearch = 15;
    if (search(valueToSearch)) {
        cout << "Value " << valueToSearch << " found in the list." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the list." << endl;
    }

    deleteAtBeg();
    print();

    deleteAtEnd();
    print();

    deleteAtPos(2);
    print();

    return 0;
}
