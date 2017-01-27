#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<map>
using namespace std;

void displayVector(vector<int> display) {
	for(vector<int>::iterator it = display.begin(); it != display.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

vector<int> solve(vector<int> inputVector) {
	sort(inputVector.begin(), inputVector.end());
	vector<int>result;
	if(inputVector.size()) {
		int minimum = inputVector[0];
		int maximum = inputVector[inputVector.size()-1];
		map<int, bool> myMap;
		for(int i = 0;i<inputVector.size();i++) {
			myMap[inputVector[i]] = true;
		}
		for(int i = minimum; i<=maximum; i++) {
			if(!myMap[i]) {
				result.push_back(i);
			}
		}
	}
	return result;
}


int main() {
	int inputs, x;
	vector<int> test;
	cin>>inputs;
	while(inputs--) {
		while(1) {
			int num;
			cin>>num;
			test.push_back(num);
		}
	}
	return 0;
}
