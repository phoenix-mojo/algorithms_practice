#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
    	set<string> subs;
    	int reps,j;
    	string pattern, prev_pattern;
    	if (str.length() == 0 || str.length() == 1)
    		return false;
    	for (int i = 1; i <= str.length() / 2; i++) {
    		if (str.length() % i != 0)
    			continue;
    		else {
    			reps = 0;
    			j = 0;
    			pattern = str.substr(j, i);
    			prev_pattern = pattern;
    			while (!prev_pattern.compare(pattern) && j < str.length()) {
    				j+= i;
    				prev_pattern = pattern;
    				pattern = str.substr(j, i);
    				reps++;
    			}
    			if (reps == str.length() / i)
    				return true;
    		}
    	}
    	return false;
    }
};

int main() {
	Solution solve;
	string str;
	cin>>str;
	cout<<boolalpha<<solve.repeatedSubstringPattern(str)<<endl;
	return 0;
}