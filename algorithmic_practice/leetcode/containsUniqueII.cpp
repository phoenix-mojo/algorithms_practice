#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int> > positions;
        for (int i = 0; i < nums.size(); i++) {
        	if (positions.find(nums[i]) != positions.end()) {
        		if (i - positions[nums[i]].back() <= k)
        			return true;
        	}
        	positions[nums[i]].push_back(i);
        }
        return false;
    }
};

int main() {
	Solution s;
	int sz, k, ip;
	vector<int> nums;
	cin>>sz;
	while (sz--) {
		cin>>ip;
		nums.push_back(ip);
	}
	cin>>k;
	cout<<boolalpha<<s.containsNearbyDuplicate(nums, k);
	return 0;
}