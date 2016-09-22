#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

void displayVector(vector<int> V) {
	for(vector<int>::iterator it=V.begin();it != V.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

int rodCuttingDP(vector<int> pricesForPieces, int size) {
	int dp[size+1];
	dp[0] = 0;
	for(int i = 1;i<=size;i++) {
		int maxima = INT_MIN;
		for(int j=0;j<i;j++) {
			maxima = max(maxima, pricesForPieces[j] + dp[i-j-1]);
		}
		dp[i] = maxima;
	}
	return dp[size];
}

int recursiveRodCuttingDP(vector<int> pricesForPieces, int size, vector<int>& recurse) {
	if(size == 0)
		return recurse[size] = 0;
	if(recurse[size] == -1) {
		int maxim = INT_MIN;
		for(int i = 1; i<=size;i++)
			maxim = max(maxim, pricesForPieces[i-1] + recursiveRodCuttingDP(pricesForPieces, size-i, recurse));
		return recurse[size] = maxim;
	}
	return recurse[size];
}

	

int main() {
	vector<int> pricesForPieces, recurse;
	int length, input;
	cin>>length;
	while(length--) {
		cin>>input;
		pricesForPieces.push_back(input);
		recurse.push_back(-1);
	}
	recurse.push_back(-1);
	cout<<rodCuttingDP(pricesForPieces, pricesForPieces.size())<<endl;
	cout<<recursiveRodCuttingDP(pricesForPieces, pricesForPieces.size(), recurse)<<endl;
	//displayVector(recurse);
	return 0;
}