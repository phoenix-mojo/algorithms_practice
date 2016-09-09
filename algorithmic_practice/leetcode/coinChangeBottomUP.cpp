#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


void minimumCoins(vector<int> denominations, int amount, vector<int>& cacheResults) {
	cacheResults[0] = 0;
	for(int i=1; i<=amount;i++) {
		if(cacheResults[i] == -1) {
			int minimumCache = INT_MAX, val;
			for(int j = 0; j<denominations.size();j++) {
				if(denominations[j]<=i) {
					val = cacheResults[i-denominations[j]];
					if(val >=0)
						minimumCache = min(minimumCache, val);
				}
			}
			cacheResults[i] = minimumCache != INT_MAX? 1 + minimumCache : -1;		
		}
	}
}

int main() {
	vector<int>denominations;
	int totalCoins, input, amount;
	cin>>totalCoins;
	while(totalCoins-->0) {
		cin>>input;
		denominations.push_back(input);
	}
	cin>>amount;
	vector<int> cacheResults(amount+1, -1);
	minimumCoins(denominations, amount, cacheResults);
	cout<<cacheResults[amount];
	return 0;
}