#include<iostream>
#include<string>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
	public:
    	int lengthOfLongestSubstring(string s) {
    		map<char, int> track_index;
    		int max_len = 0, left = 0, right = 0;
    		if(s.length() < 2)
    			return s.length();
			while(right != s.length()-1) {
				track_index[s[right]] = right;
				right = right + 1;
				if(!(track_index.find(s[right]) == track_index.end())) {
					left = max(left, track_index[s[right]] + 1);
				}
				max_len = max(max_len, right - left + 1);
			}
			return max_len;
    	}   	
};

int main() {
	string input;
	cin>>input;
	Solution obj;
	cout<<obj.lengthOfLongestSubstring(input);
	return 0;
}