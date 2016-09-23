#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void printLCS(vector<vector<int> > &results, string first, string second) {
	string lcs;
	for(int i = results.size()-1;i>=1;) {
		for(int j = results[i].size()-1;j>=1;) {
			if(first[i-1] == second[j-1]) {
				lcs+=first[i-1];
				i--;
				j--;
			}
			else {
				if(results[i][j-1]>results[i-1][j])
					j--;
				else
					i--;
			}
		}
 	}
 	reverse(lcs.begin(), lcs.end());
 	cout<<lcs;
}

int LCS(string first, string second, int sizeFirst, int sizeSecond) {
	/*
		  a b c
		0 0 0 0
	   a0 1 1 1
	   b0 1 2 2"
	*/
	vector<vector<int> > results(sizeFirst+1, vector<int>(sizeSecond+1, 0));
	for(int i = 1;i<results.size();i++) {
		for(int j = 1;j<results[i].size();j++) {
			if(first[i-1] == second[j-1]) 
				results[i][j] = 1 + results[i-1][j-1];
			else
				results[i][j] = max(results[i][j-1], results[i-1][j]);
		}
	}
	printLCS(results, first, second);
	cout<<" with length: ";
	return results[sizeFirst][sizeSecond];
}

int main() {
	int tc, size1, size2;
	cin>>tc;
	while(tc--) {
		string first, second;
		cin>>size1>>size2;
		cin>>first>>second;
		cout<<"The LCS is: "<<LCS(first, second, size1, size2)<<endl;
	}
	return 0;
}