#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if(nums.size()) {
    		int max_overall = nums[0], sum_running = nums[0];
    		for(int i=1;i<nums.size();i++) {
    			sum_running = max(nums[i], sum_running+nums[i]);
    			max_overall = max(max_overall, sum_running);
    		}
    		return max_overall;
    	}
    	return 0;
    }

    int maxSubArrayExplicitNegativeFlagCheck(vector<int>& nums) {
		if(nums.size()) {
			int max_overall = nums[0], sum_running = nums[0], negative_max = nums[0];
			bool all_negative = nums[0] >= 0 ? false:true;
			for(int i=1;i<nums.size();i++) {
				if(nums[i]>=0)
					all_negative = false;
				negative_max = max(negative_max, nums[i]);
				if(sum_running<0)
					sum_running = 0;
				sum_running += nums[i];
				max_overall = max(max_overall, sum_running);
			}
			if(all_negative)
				return negative_max;
			return max_overall;
		}
		return 0;
    }
};

int main() {
	int size, input;
	vector<int> nums;
	cin>>size;
	while(size--) {
		cin>>input;
		nums.push_back(input);
	}
	Solution solve;
	cout<<solve.maxSubArray(nums);
	return 0;
}