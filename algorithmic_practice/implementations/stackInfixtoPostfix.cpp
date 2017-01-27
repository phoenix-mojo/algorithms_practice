#include<iostream>
#include<string>

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

string infixToPostfix(string input) {
	string result;
}

int main() {
	cout<<"Enter an expression in infix notation:";
	string str;
	cin>>str;
	cout<<"Resultant expression in post fix format is: "<<infixToPostfix(str);
	return 0;
}	