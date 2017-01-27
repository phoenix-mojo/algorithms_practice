#include <stack>
#include <iostream>

using namespace std;

class Queue {
public:
	stack<int> main_stack;
	stack<int> rev_stack;
    // Push element x to the back of queue.
    void push(int x) {
        main_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (rev_stack.empty()) {
        	while (!main_stack.empty()) {
        		rev_stack.push(main_stack.top());
        		main_stack.pop();
        	}
        }
        if (!rev_stack.empty())
        	rev_stack.pop();
    }

    // Get the front element.
    int peek(void) {
    	if (rev_stack.empty()) {
        	while (!main_stack.empty()) {
        		rev_stack.push(main_stack.top());
        		main_stack.pop();
        	}
        }
        return rev_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return main_stack.empty() && rev_stack.empty();
    }
};

int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.pop();
	cout<<"Q front: "<<q.peek()<<endl;
	cout<<"Is Q empty?: "<<boolalpha<<q.empty()<<endl;
	q.pop();
	cout<<"Is Q empty?: "<<boolalpha<<q.empty()<<endl;
	q.push(3);
	q.push(4);
	cout<<"Q front: "<<q.peek()<<endl;
	q.pop();
	cout<<"Q front: "<<q.peek()<<endl;
	q.pop();
	cout<<"Is Q empty?: "<<boolalpha<<q.empty()<<endl;
	return 0;
}