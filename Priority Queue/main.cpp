#include<iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;

void insert(int p,int d) {
    Node *newNode = new Node;
    newNode -> data = d;
    newNode -> priority = p;
    newNode -> next = NULL;
    if (front==NULL && rear==NULL) {
        front=rear=newNode;
        return;
    }

    if (front->priority>=p) {
        newNode->next=front;
        front=newNode;
        return;
    }

    Node *temp = front;
    while (temp->next!=NULL && temp->next->priority<p) {
            temp = temp->next;
    }
    newNode -> next = temp -> next;
    temp->next = newNode;
}
void Display() {

    if (front == NULL) {
        cout << "List is empty, nothing to dissplay." << endl;
        return;
    }
    cout << "Data:\t";
    Node* temp = front;

    while (temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
int main() {

    insert(1,22);
    insert(2,12);
    insert(7,4);

    Display();

    insert(3,47);

    cout<<endl;

    Display();
}

