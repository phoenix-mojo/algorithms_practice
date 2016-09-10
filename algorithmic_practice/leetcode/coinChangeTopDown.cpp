#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int recursiveMinimumCoins(vector<int>& denominations, int amount, int cacheResults[]) {
	if(amount == 0)
		return 0;
	if(amount < 1)
		return -1;
	if(cacheResults[amount] != -1)
		return cacheResults[amount];
	else {
		int mini = INT_MAX;
		for(int i = 0; i<denominations.size();i++) {
			int val = recursiveMinimumCoins(denominations, amount-denominations[i], cacheResults);
			if(val<mini && val >= 0)
				mini = val + 1;
		}
		cacheResults[amount] = (mini != INT_MAX) ? mini : -1;
		return cacheResults[amount];
	}
}

int main() {
	vector<int>denominations;
	int totalCoins, input;
	cin>>totalCoins;
	while(totalCoins-->0) {
		cin>>input;
		denominations.push_back(input);
	}
	int amount;
	cin>>amount;
	int cacheResults[amount+1];
	memset(cacheResults, -1, sizeof(cacheResults));
	int result = recursiveMinimumCoins(denominations, amount, cacheResults);
	cout<<result;
	return 0;
}