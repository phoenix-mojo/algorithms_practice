#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool solve(vector<int> nums, int target) {
	int left = 0, right = 1, sum = 0;
	if(nums.empty()) {
		return false;
	}
	sum = nums[0];
	while (right <= nums.size()) {
		while (sum > target && left < right - 1)
			sum -= nums[left++];
		if (sum == target)
			return true;
		if (right < nums.size())
			sum += nums[right];
		right++;
	}
	return false;
}

int main() {
	int tc, sz, target, inp;
	vector<int> nums;
	cin>>tc;
	while(tc--) {
		cin>>sz>>target;
		while(sz--) {
			cin>>inp;
			nums.push_back(inp);
		}
		cout<<boolalpha<<solve(nums, target)<<endl;
		nums.resize(0);
	}
	return 0;
}