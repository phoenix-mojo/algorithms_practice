#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve(vector<int> nums, int target) {
	int left = 0, right = 0, sum = 0;
	bool flag = false;
	if(nums.empty()) {
		cout<<"-1\n";
		return;
	}
	sum = nums[0];
	while (right<nums.size()-1 && left<=right) {
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
		cout<<"-1\n";
		return;
	}
	cout<<left + 1<<" "<<right + 1<<endl;
	return;
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
		solve(nums, target);
		nums.resize(0);
	}
	return 0;
}