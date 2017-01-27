#include <iostream>
#include <queue>

using namespace std;


class Stack {
public:
    queue<int> main_q;
    queue<int> rev_q;
    // Push element x onto stack.
    void push(int x) {
        main_q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (main_q.size() == 1)
            main_q.pop();
        else {
            while (main_q.size() > 1) {
                rev_q.push(main_q.front());
                main_q.pop();
            }
            main_q.pop();
            queue<int> temp;
            temp = main_q;
            main_q = rev_q;
            rev_q = temp;
        }            
    }

    // Get the top element.
    int top() {
        int top_ele;
        if (main_q.size() == 1)
            return main_q.front();
        while (main_q.size() > 1) {
            rev_q.push(main_q.front());
            main_q.pop();
        }
        top_ele = main_q.front();
        rev_q.push(main_q.front());
        main_q.pop();
        queue<int> temp;
        temp = main_q;
        main_q = rev_q;
        rev_q = temp;
        return top_ele;
    }

    // Return whether the stack is empty.
    bool empty() {
        return main_q.empty() && rev_q.empty();
    }
};

int main() {
    Stack q;
    q.push(1);
    q.push(2);
    q.pop();
    cout<<"S front: "<<q.top()<<endl;
    cout<<"Is S empty?: "<<boolalpha<<q.empty()<<endl;
    q.pop();
    cout<<"Is S empty?: "<<boolalpha<<q.empty()<<endl;
    q.push(3);
    q.push(4);
    cout<<"S front: "<<q.top()<<endl;
    q.pop();
    cout<<"S front: "<<q.top()<<endl;
    q.pop();
    cout<<"Is S empty?: "<<boolalpha<<q.empty()<<endl;
    return 0;
}