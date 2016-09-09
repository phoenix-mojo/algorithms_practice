#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
	vector<int> dp;
    NumArray(vector<int> &nums) {
    	if(nums.size()) {
    		dp = nums;
    		dp[0] = nums[0];
    		for(int i=1;i<nums.size();i++)
    		dp[i] = nums[i] + dp[i-1];
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