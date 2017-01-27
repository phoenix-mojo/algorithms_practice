#include <stack>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <stdio.h>

using namespace std;

int solve(string s) {
	int count = -1;
	stack<char> rules;
	if (s.length() == 0 || s.length() == 1 || !isupper(s[0]))
		return -1;
	rules.push(s[0]);
	for(int i = 1; i < s.length(); i++) {
		if (rules.empty() && !isupper(s[i]))
			break;
		if (isupper(s[i]))
			rules.push(s[i]);
		else if (rules.top() == toupper(s[i])) {
			rules.pop();
			count = i;
		}
		else break;
	}
	return count;
}

int main() {
	string s;
	cin>>s;
	cout<<solve(s)<<endl;
	return 0;
}