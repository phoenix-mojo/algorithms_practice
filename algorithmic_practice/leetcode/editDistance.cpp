#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> >results(word1.length()+1, vector<int>(word2.length()+1));
        for(int i=0;i<results.size();i++) {
        	for(int j=0;j<results[i].size();j++) {
        		if(i ==0 || j == 0)
        			results[i][j] = i==0 ? j : i;
        		else if(word1[i-1] == word2[j-1])
        			results[i][j] = results[i-1][j-1];
        		else results[i][j] = 1 + min(min(results[i-1][j], results[i][j-1]), results[i-1][j-1]);
        	}
        }
        return results[word1.length()][word2.length()];
    }
};

int main() {
	int tc, sizeFirst, sizeSecond;
	string first, second;
	cin>>tc;
	while(tc--) {
		Solution solver;
		cin>>sizeFirst>>sizeSecond;
		cin>>first>>second;
		cout<<solver.minDistance(first, second)<<endl;
	}
	return 0;
}