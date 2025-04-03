#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = nullptr;

// Insert at beginning
void insert(int n) {
    node* newNode = new node{n, head};
    head = newNode;
}

// Insert at end
void insertAtEnd(int n) {
    node* newNode = new node{n, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a given position
void insertAtPos(int pos, int n) {
    if (pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }

    node* newNode = new node{n, nullptr};

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Invalid position" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display the list
void Display() {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Data:\t";
    for (node* temp = head; temp; temp = temp->next) {
        cout << temp->data << "\t";
    }
    cout << endl;
}

// Search for a value
bool search(int n) {
    for (node* temp = head; temp; temp = temp->next) {
        if (temp->data == n) return true;
    }
    return false;
}

// Delete first node
void deleteAtBeginning() {
    if (!head) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}

// Delete last node
void deleteAtEnd() {
    if (!head) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Delete node at a specific position
void deleteAtPos(int pos) {
    if (!head || pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Invalid position" << endl;
        return;
    }

    node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Free all memory before exiting
void deleteList() {
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insertAtEnd(5);
    insertAtPos(3, 10);
    Display();

    int valueToSearch = 10;
    cout << (search(valueToSearch) ? "Found\n" : "Not Found\n");

    deleteAtBeginning();
    Display();

    deleteAtEnd();
    Display();

    deleteAtPos(2);
    Display();

    deleteList();  // Cleanup before exiting
    return 0;
}
