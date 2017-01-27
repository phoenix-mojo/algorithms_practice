#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<vector<string> > createMap(vector<vector<string> > &maps) {
		maps[0].push_back("");
		maps[1].push_back("");
		maps[2].push_back("a");
		maps[2].push_back("b");
		maps[2].push_back("c");
		maps[3].push_back("d");
		maps[3].push_back("e");
		maps[3].push_back("f");
		maps[4].push_back("g");
		maps[4].push_back("h");
		maps[4].push_back("i");
		maps[5].push_back("j");
		maps[5].push_back("k");
		maps[5].push_back("l");
		maps[6].push_back("m");
		maps[6].push_back("n");
		maps[6].push_back("o");
		maps[7].push_back("p");
		maps[7].push_back("q");
		maps[7].push_back("r");
		maps[7].push_back("s");
		maps[8].push_back("t");
		maps[8].push_back("u");
		maps[8].push_back("v");
		maps[9].push_back("w");
		maps[9].push_back("x");
		maps[9].push_back("y");
		maps[9].push_back("z");
		return maps;
	}
    vector<string> letterCombinations(string digits) {
        vector<vector<string> > maps(10);
        vector<string> result, temp;
        maps = createMap(maps);
        if(digits.length() == 0)
        	return result;
        if(digits.length() == 1) {
        	for(int j = 0;j<maps[digits[0]-'0'].size();j++)
        		result.push_back(maps[digits[0]-'0'][j]);
        	return result;
        }
        else
        	temp = maps[digits[0]-'0'];
	        for(int i = 1;i<digits.length();i++) {
	        	result.clear();
	        	for(int j = 0;j<temp.size();j++) {
	        		for(int k = 0;k<maps[digits[i]-'0'].size(); k++) {
	        			result.push_back(temp[j] + maps[digits[i]-'0'][k]);
	        		}
	        	}
	        	temp = result;
	        }
	        return result;
    }

    void display(vector<string> str) {
    	for(vector<string>::iterator it = str.begin(); it != str.end(); it++)
    		cout<<*it<<" ";
    	cout<<endl;
    }
};

int main() {
	string digits;
	vector<string> result;
	cin>>digits;
	Solution obj;
	result = obj.letterCombinations(digits);
	obj.display(result);
	return 0;
}