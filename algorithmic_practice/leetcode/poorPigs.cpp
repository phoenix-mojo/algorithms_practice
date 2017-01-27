#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int min_pigs = 0;
        while (pow((minutesToTest/minutesToDie) + 1, min_pigs) < buckets) {
            min_pigs++;
        }
        return min_pigs;
    }
};

int main() {
	Solution solve;
	int b, mD, mT;
	cin>>b>>mD>>mT;
	cout<<solve.poorPigs(b, mD, mT)<<endl;
	return 0;
}