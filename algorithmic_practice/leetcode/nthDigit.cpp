#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
    	int ans = 0, shft = 0, ctr = 1, off;
    	if (n < 10)
    		return n;
        while (1) {
        	off = 9*ctr*pow(10, ctr - 1);
        	if (n - off < 0) {
        		ans += ceil((float)n/ctr);
        		cout<<ans<<endl;
        		if (n%ctr == 0)
        			shft = 0;
        		else
        			shft = ctr - (n%ctr);
        		break;
        	}
        	n -= off;
        	ctr++;
        	ans += off;
        	cout<<ans<<endl;
        }
        while(shft--)
        	ans /= 10;
        return ans%10;
    }
};

int main() {
	Solution solve;
	int n;
	cin>>n;
	cout<<solve.findNthDigit(n);
	return 0;
}