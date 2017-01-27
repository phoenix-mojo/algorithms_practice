#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
    	if(s.length() == 0)
    		return "";
        unordered_map <char, bool> vowels;
        int i = 0, j = s.length() - 1;
        char temp;
        vowels['a'] = true;
        vowels['e'] = true;
        vowels['i'] = true;
        vowels['o'] = true;
        vowels['u'] = true;
        vowels['A'] = true;
        vowels['E'] = true;
        vowels['I'] = true;
        vowels['O'] = true;
        vowels['U'] = true;
        while (j > i) {
        	if (vowels.find(s[i]) == vowels.end())
        		i++;
        	if (vowels.find(s[j]) == vowels.end())
        		j--;
        	if (vowels.find(s[i]) != vowels.end() && vowels.find(s[j]) != vowels.end()) {
        		temp = s[i];
        		s[i] = s[j];
        		s[j] = temp;
        		i++;
        		j--;
        	}
        }
        return s;
    }
};

int main() {
	Solution solve;
	string s;
	cin>>s;
	cout<<solve.reverseVowels(s);
	return 0;
}