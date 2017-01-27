#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
	void printStack(stack<char> s) {
		cout<<"----\n";
		while(!s.empty()) {
			cout<<s.top()<<endl;
			s.pop();
		}
		cout<<"----\n";
	}
    bool isValid(string s) {
    	stack <char> paranthesis;
    	unordered_map <char, char> matches;
    	matches['['] = ']';
    	matches[']'] = '[';
    	matches['('] = ')';
    	matches[')'] = '(';
    	matches['{'] = '}';
    	matches['}'] = '{';
        for (int i = 0; s[i] != '\0'; i++) {
        	//printStack(paranthesis);
        	if (!paranthesis.empty() && paranthesis.top() == matches[s[i]])
        		paranthesis.pop();
        	else
        		paranthesis.push(s[i]);
        }
        if (!paranthesis.empty())
        	return false;
        return true;
    }
};

int main() {
	Solution solve;
	string s;
	cin>>s;
	cout<<boolalpha<<solve.isValid(s);
	return 0;
}