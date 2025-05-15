#include<iostream>
using namespace std;

int Cirqueue[5],n=5,x,y,front=-1,rear=-1;

void insert(){
	if((rear+1) % n == front){
		cout<<"queue is full"<<endl;
	}
	else{
		if(front==-1)
		{
			front=0;
		}
		cout<<"insert the Element in Queue: ";
		cin>>x;
		rear=(rear+1)%n;
		Cirqueue[rear]=x;
	}
}
int peek(){
	if(front==-1){
		return 0;
	}
	else{
		return Cirqueue[front];
	}
}
void Display(){
	if(front==-1){
		cout<<"queue is Empty"<<endl;
	}
	else{
		cout<<"queue Elements are : "<<endl;
		int i=front;
		while(true){
			cout<<Cirqueue[i]<<" ";
			if(i==rear){
				break;
			}
			i=(i+1)%n;
		}
		cout<<endl;
	}
}
void Delete(){
	if(front==-1){
		cout<<"queue is Empty"<<endl;
	}
	else{
		cout<<" Elements Deleted from queue is : "<<Cirqueue[front]<<endl;
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else{
			front=(front+1)%n;
		}

	}
}
int main(){


	insert();
	insert();
	insert();
	insert();
	insert();
	y=peek();
	if(y==0){
		cout<<"Queue is Empty";
	}
	else{
		cout<<"Front Element of Queue is : "<<y<<endl;
	}
	Display();
	Delete();
	Display();
	return 0;

}
