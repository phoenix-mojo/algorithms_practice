#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class NumArray {
public:
    vector<int> dp;
    int rec(int left, vector<int> &nums) {
    	if(left == 0)
    		return dp[left] = nums[left];
    	if(dp[left] == INT_MAX)
    		return dp[left] = rec(left-1, nums) + nums[left];
    	else
    		return dp[left];
    }
    NumArray(vector<int> &nums) {
        if(nums.size()) {
            dp = nums;
            fill(dp.begin(), dp.end(), INT_MAX);
            rec(nums.size()-1, nums);
        }
    }

    int sumRange(int i, int j) {
    	if(i == 0)
    		return dp[j];
        return dp[j] - dp[i-1];
    }
};

int main() {
	int arr [] = {-2, 0, 3, -5, 2, -1};
	vector<int> nums(&arr[0], &arr[0]+6);
	NumArray numArray(nums);
	cout<<numArray.sumRange(0, 2)<<endl;
	cout<<numArray.sumRange(2, 5)<<endl;
	cout<<numArray.sumRange(0, 5)<<endl;
	return 0;
}