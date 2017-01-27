#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool solve(vector<int> nums, int target) {
	int left = 0, right = 0, sum = 0;
	bool flag = false;
	if(nums.empty()) {
		return false;
	}
	sum = nums[0];
	while (right<nums.size() && left <= right) {
		if (sum < target)
			sum += nums[++right];
		else if (sum > target)
			sum -= nums[left++];
		else {
			flag = true;
			break;
		}
	}
	if (flag == false) {
		return false;
	}
	return true;
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