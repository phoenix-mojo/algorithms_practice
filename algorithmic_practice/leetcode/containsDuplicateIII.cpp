#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
	int get_min(vector<int> nums, int l, int r) {
		int min = INT_MAX;
		sort(nums.begin() + l, nums.begin() + r + 1);
		if (r == l)
			return 0;
		while(l < r) {
			if ((nums[l] == INT_MAX && nums[l + 1] != 0) || (nums[l + 1] == INT_MAX && nums[l] != 0))
				return -1;
			int temp = abs(nums[l] - nums[l + 1]);
			if (min > temp)
				min = temp;
			l++;
		}
		return min;
	}
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if (nums.size() == 0 || nums.size() == 1 || k == 0)
    		return false;
    	if (k >= nums.size())
    		if (get_min(nums, 0, nums.size() - 1) <= t)
    			return true;
    	for (int i = 0;  i + k <nums.size(); i++) {
    		if (get_min(nums, 0, nums.size() - 1) == -1)
    			return false;
    		if(get_min(nums, i, i + k) <= t)
    			return true;
    	}
    	return false;
    }
};

int main() {
	Solution solve;
	vector<int> nums;
	int sz, ip, k, t;
	cin>>sz;
	while (sz--) {
		cin>>ip;
		nums.push_back(ip);
	}
	cin>>k>>t;
	cout<<boolalpha<<solve.containsNearbyAlmostDuplicate(nums, k, t);
	return 0;
}