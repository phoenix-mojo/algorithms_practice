#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int>& res) {
	vector<int>::iterator it;
	for (it = res.begin(); it != res.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	vector<int> res;
    	int token;
        for (int i = 0; i < nums.size(); i++) {
        	if (nums[i] < 0) {
        		token = -nums[i];
            }
        	else
        		token = nums[i];
        	if (nums[token - 1] > 0)
        		nums[token - 1] = -nums[token - 1];
            else
                res.push_back(token);
        }
        displayVector(nums);
        return res;
    }
};

int main() {
	Solution solve;
	int sz, ip;
	vector<int> nums, res;
	cin>>sz;
	while (sz--) {
		cin>>ip;
		nums.push_back(ip);
	}
	res = solve.findDisappearedNumbers(nums);
	displayVector(res);
	return 0;
}