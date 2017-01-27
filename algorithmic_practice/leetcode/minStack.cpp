#include <stack>
#include <iostream>
#include <limits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> my_stack;
    stack<int> min_stack;
    MinStack() {
        while (!my_stack.empty())
            my_stack.pop();
        while (!min_stack.empty())
            min_stack.pop();
    }
    
    void push(int x) {
        my_stack.push(x);
        if (min_stack.empty() || min_stack.top() >= x)
            min_stack.push(x);
    }
    
    void pop() {
        if (!min_stack.empty() && my_stack.top() == min_stack.top())
            min_stack.pop();
        if (!my_stack.empty())
            my_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
     return min_stack.top();      
    }
};

int main() {
    MinStack obj;
    obj.push(-1);
    obj.push(0);
    obj.push(-2);
    cout<<"Current min: "<<obj.getMin()<<endl;
    obj.pop();
    cout<<"Current min: "<<obj.getMin()<<endl;
    return 0;
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */