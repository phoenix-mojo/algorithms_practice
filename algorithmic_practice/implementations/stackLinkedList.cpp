#include<iostream>

using namespace std;

struct Stacknode {
	int data;
	Stacknode* next;
}*top = NULL;

void push(int data) {
	cout<<"push("<<data<<")\n";
	Stacknode* node = new Stacknode();
	node->data = data;
	node->next = NULL;
	if(top == NULL)
		cout<<"Entering node to an empty stack.\n";
	node->next = top;
	top = node;
}

int pop() {
	cout<<"pop()\n";
	if(top == NULL) {
		cout<<"Stack is empty, return -1 to indicate failure.\n";
		return -1;
	}
	else {
		Stacknode* temp = top;
		int poppedNode = temp->data;
		top = top->next;
		delete(temp);
		return poppedNode;
	}
}

int topElement() {
	cout<<"top()\n";
	if(top == NULL) {
		cout<<"Stack is empty, return -1 to indicate failure.\n";
		return -1;
	}
		return top->data;
}

void displayStack() {
	Stacknode* traverse = top;
	cout<<"displayStack()\n";
	while(traverse != NULL) {
		cout<<traverse->data<<" ";
		traverse = traverse->next;
	}
	cout<<endl;
}

int main() {
	displayStack();
	push(1);
	displayStack();
	push(2);
	push(3);
	cout<<topElement()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	displayStack();
	cout<<topElement()<<endl;
	displayStack();
	push(4);
	push(5);
	cout<<topElement()<<endl;
	displayStack();
	cout<<pop()<<endl;
	displayStack();
	cout<<pop()<<endl;
	displayStack();
	cout<<pop()<<endl;
	displayStack();
	cout<<pop()<<endl;
	displayStack();
	cout<<pop()<<endl;
	displayStack();
	return 0;
}	