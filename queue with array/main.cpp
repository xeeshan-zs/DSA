#include <iostream>
using namespace std;

int arr[10];
int front=-1;
int rear=-1;
void enqueue(int);
void dequeue();
void display();
void peek();
int main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    enqueue(4);
    display();



}
void enqueue(int n) {
    if(front==-1 && rear==-1) {
        front=0;
        rear=0;
        arr[rear]=n;
    }
    else {
        rear=(rear+1)%10;
        arr[rear]=n;
    }
}
void dequeue() {
    if(front==-1 && rear==-1) {
        cout<<"Queue is empty"<<endl;
    }else {
        cout<<"Dequeued -> "<<arr[front]<<endl;
        front=(front+1)%10;
    }
}
void display() {
    if(front==-1 && rear==-1) {
        cout<<"Queue is empty"<<endl;
    }else {
        for(int i=front;i<=rear;i++) {
            cout<<arr[i]<<"\n";
        }
    }
}
void peek(){
    cout<<"Peek = "<< arr[front];

}