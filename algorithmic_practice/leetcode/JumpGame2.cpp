#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void displayVector(vector<int> V) {
		for(vector<int>::iterator it = V.begin(); it != V.end(); it++)
			cout<<*it<<" ";
		cout<<endl;
	}

    int jump(vector<int>& nums) {
    	vector<int> results(nums.size(), INT_MAX);
    	if(nums.size()) {
    		results[0] = 0;
    		int start = 0;
    		for(int i = 1;i<nums.size();i++) {
    			bool flag = false;
    			for(int j=start;j<i;j++) {
    				if(i - j <= nums[j]) {
    					start = j;
    					results[i] = min(results[i], 1 + results[j]);
    					flag = true;
    					break;
    				}
    			}
    			if(!flag)
    				return -1;
    		}
    		return results[results.size()-1];
    	}
        return 0;
    }
};

int main() {
	int tc, size, input;
	cin>>tc;
	while(tc--) {
		vector<int> nums;
		cin>>size;
		while(size--) {
			cin>>input;
			nums.push_back(input);
		}
		Solution solver;
		cout<<solver.jump(nums)<<endl;
	}
	return 0;
}