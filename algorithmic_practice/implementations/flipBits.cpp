#include <iostream>

using namespace std;

int flipBits(int n, int k) {
    int mask = 1;
    for(int i = 1; i < k; ++i)
        mask |= mask << 1;

    return ~n & mask;
}

int main() {
	unsigned int x, y;
	cin>>x;
	y = x^(0xFFFFFFFF);
	cout<<y;
	return 0;
}