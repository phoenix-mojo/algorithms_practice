#include <stack>
#include <iostream>
#include <limits>

using namespace std;

class MinStack {
public:
    MinStack(): m_min(INT_MAX){}
    void push(int x) {
        if(x <= m_min){
            m_stack.push(m_min);
            m_min = x;
        }
        m_stack.push(x);
    }

    void pop() {
        if(m_stack.top() == m_min){
            m_stack.pop();
            m_min = m_stack.top();
            m_stack.pop();
        } else {
            m_stack.pop();
        }
        
        if(m_stack.empty()) m_min = INT_MAX;
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return m_min;
    }
private:
    stack<int> m_stack;
    int m_min;
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