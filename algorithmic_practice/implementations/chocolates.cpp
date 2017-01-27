#include<vector>
#include<iostream>
using namespace std;

int reductionCost(vector < int > num) {
    vector<int> sums;
    sums.push_back(num[0]);
    for(int i = 1;i<num.size();i++) {
        sums.push_back(num[i]+sums[i-1]);
    }
    int sum = 0;
    for(int i =1;i<sums.size();i++) {
        sum+=sums[i];
    }
    return sum;

}

int main() {
	int t, inp;
	vector<int> arr;
	cin>>t;
	while(t--) {
		cin>>inp;
		arr.push_back(inp);
	}
	cout<<reductionCost(arr);
	return 0;
}