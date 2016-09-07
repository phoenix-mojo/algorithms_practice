#include<iostream>
using namespace std;

struct Listnode {
	int data;
	Listnode* next;
}*head = NULL, *rear = NULL;

void displayList() {
	Listnode* node = head;
	cout<<"Display List: ";
	while(node != NULL) {
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

void createFirstNode(int data) {
	Listnode* node = new Listnode();
	node->data = data;
	node->next = NULL;
	rear = head = node;
}

void pushRear(int data) {
	if(head == NULL)
		createFirstNode(data);
	else {
		Listnode* node = new Listnode();
		node->data = data;
		node->next = NULL;
		rear->next = node;
		rear = node;
	}

}

void pushFront(int data) {
	if(head == NULL)
		createFirstNode(data);
	else {
		Listnode* node = new Listnode();
		node->data = data;
		node->next = head;
		head = node;
	}
}

void removeFront() {
	Listnode* node = NULL;
	if(head == rear) {
		if(head == NULL) {
			return;
		}
		node = head;
		head = NULL;
		rear = NULL;
		delete(node);
	}
	else {
		node = head;
		head = head->next;
		delete(node);
	}
}

void removeRear() {
	Listnode* node = NULL;
	if(head == rear) {
		if(head == NULL) {
			return;
		}
		node = head;
		head = NULL;
		rear = NULL;
		delete(node);
	}
	else {
		node = head;
		while(node->next->next != NULL){
			node = node->next;
		}
		rear = node;
		delete(rear->next);
		rear->next = NULL;
	}
}

void deleteList() {
	Listnode* node = NULL;
	while(head != NULL) {
		node = head;
		head = head->next;
		delete(node);
	}
}

int listLengthRecursive(Listnode* node) {
	if(node == NULL)
		return 0;
	return (1 + listLengthRecursive(node->next));
}

int searchElementRecursive(Listnode* node, int searchElement) {
	if(node == NULL)
		return -1;
	if(node->data == searchElement)
		return 1;
	return searchElementRecursive(node->next, searchElement);
}

void reverseList() {
	Listnode* prev = NULL;
	Listnode* forward = NULL;
	while(head != NULL) {
	    forward = head->next;
		head->next = prev;
		prev = head;
		head = forward;
	}
	head = prev;
	while(rear->next != NULL)
		rear = rear->next;
}

Listnode* reverseListRecursive(Listnode* node) {
	if(node == NULL || node->next == NULL) {
		return node;
	}
	Listnode* reversed = reverseListRecursive(node->next);
	node->next->next = node;
	node->next = NULL;
	rear = node;
	return reversed;
}

void printReversedRecursive(Listnode* node) {
	if(node == NULL) {
		return;
	}
	printReversedRecursive(node->next);
	cout<<node->data<<" ";
	if(node == head)
		cout<<endl;
}


int main() {
	Listnode* node;
	cout<<"pushRear(1)\n";
	pushRear(1);
	displayList();
	cout<<"pushFront(2)\n";
	pushFront(2);
	displayList();
	cout<<"pushRear(1)\n";
	pushRear(1);
	displayList();
	cout<<"pushRear(2)\n";
	pushRear(2);
	displayList();
	cout<<"pushRear(3)\n";
	pushRear(3);
	displayList();
	cout<<"pushRear(4)\n";
	pushRear(4);
	displayList();
	node = head;
	cout<<"printReversedRecursive(node): \n";
	printReversedRecursive(node);
	cout<<"reverseList()\n";
	reverseList();
	displayList();
	cout<<"reverseListRecursive(head)\n";
	head = reverseListRecursive(head);
	displayList();
	cout<<"removeRear()\n";
	removeRear();
	displayList();
	cout<<"removeRear()\n";
	removeRear();
	displayList();
	cout<<"removeFront()\n";
	removeFront();
	displayList();
	cout<<"pushRear(6)\n";
	pushRear(6);
	displayList();
	node = head;
	cout<<"listLengthRecursive(node): "<<listLengthRecursive(node)<<endl;
	removeRear();
	cout<<"searchElementRecursive(node, 2)\n";
	(searchElementRecursive(node, 2) == -1) ? cout<<"2 not found\n" : cout<<"2 found\n";
	cout<<"searchElementRecursive(node, 1)\n";
	(searchElementRecursive(node, 1) == -1) ? cout<<"1 not found\n" : cout<<"1 found\n";
	cout<<"searchElementRecursive(node, 7)\n";
	(searchElementRecursive(node, 7) == -1) ? cout<<"7 not found\n" : cout<<"7 found\n";
	displayList();
	cout<<"removeFront()\n";
	removeFront();
	displayList();
	cout<<"removeFront()\n";
	removeFront();
	displayList();
	cout<<"removeRear()\n";
	removeRear();
	displayList();
	cout<<"pushFront(7)\n";
	pushFront(7);
	displayList();
	cout<<"pushRear(8)\n";
	pushRear(8);
	displayList();
	cout<<"pushFront(5)\n";
	pushFront(5);
	displayList();
	cout<<"deleteList()\n";
	deleteList();
	displayList();
	return 0;
}