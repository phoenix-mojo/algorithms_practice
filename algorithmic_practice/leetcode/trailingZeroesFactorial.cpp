#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int n;
	cin>>n;
	if(n<=4) {
		cout<<0;
		return 0;
	}
	int result = 0;
	int ctr = 1;
	while(n/pow(5, ctr)>=1) {
		result+=(n/pow(5, ctr++));
	}
	cout<<result;
	return 0;
}