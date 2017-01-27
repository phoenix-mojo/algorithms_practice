#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = nums.size() + 1, left = 0, right = 0, sum = 0;
        if (nums.empty())
        	return 0;
        sum = nums[0];
        while (right < nums.size()) {
	        while (sum < s) {
	        	right++;
	        	sum += nums[right];
	        }
	        while (sum >= s) {
	        	sum -= nums[left];
	        	left++;
	        }
	        if (right - left + 1 < res)
	        	res = right - left + 1;
        }
        return res ==  nums.size() + 1 ? 0 : res;       
    }
};


int main() {
	int len, ip, res, target;
	vector<int> nums;
	cin>>target;
	cin>>len;
	while(len--) {
		cin>>ip;
		nums.push_back(ip);
	}
	Solution s;
	res = s.minSubArrayLen(target, nums);
	cout<<res<<endl;
	return 0;
}