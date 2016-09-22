#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size() == 0)
    		return 0;
    	vector<int> results(nums.size(), 1);
    	int maxLCS = results[0];
    	for(int i = 1;i<results.size();i++) {
    		for(int j=0;j<i;j++) {
    			if(nums[j]<nums[i]) {
    				results[i] = max(results[i], results[j] + 1);
    			}
    		}
    		maxLCS = max(results[i], maxLCS);
    	}
    	return maxLCS;
    }
};

int main() {
	int size, tc, input;
	cin>>tc;
	while(tc--) {
		vector<int> nums;
		cin>>size;
		while(size--) {
			cin>>input;
			nums.push_back(input);
		}
		Solution solve;
		cout<<solve.lengthOfLIS(nums)<<endl;
	}
	return 0;	
}