#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve(vector<int> nums, int target) {
	unordered_map <int, int> sum_map;
	bool flag = false;
	int i = 0, left = 0, right = 0, sum = 0;
	if (nums.empty()) {
		cout<<"-1\n";
		return;
	}
	for (i = 0; i<nums.size();i++) {
		sum += nums[i];
		if(sum == target) {
			left = 0;
			right = i;
			flag = true;
			break;
		}
		if (sum_map.find(sum-target) == sum_map.end()) {
			sum_map[sum] = i + 1;
		}
		else {
			left = sum_map[sum-target];
			right = i;
			flag = true;
			break;
		}
	}

	if(flag == false) {
		cout<<"-1\n";
		return;
	}
	cout<<left + 1<<" "<<right + 1<<endl;
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