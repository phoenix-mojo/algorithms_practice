#include <iostream>

using namespace std;

class Solution {
public:
	void triangle(int a, int b, int c) {
		if (a <= 0 || b <= 0 || c <= 0) {
			cout<<"None of these\n";
			return;
		} 
		if (a + b > c && b + c > a && a + c > b) {
			if (a == b && b == c)
				cout<<"Equilateral\n";
			else if (a == b || b == c || a == c)
				cout<<"Isosceles\n";
			else 
				cout<<"None of these\n";
		}
		else
			cout<<"None of these\n"; 
	}
};
int main() {
	Solution solve;
	int tc, a, b, c;
	cin>>tc;
	while(tc--) {
		cin>>a>>b>>c;
		solve.triangle(a, b, c);
	}
	return 0;
}