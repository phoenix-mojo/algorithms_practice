#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void display(vector<int> nums) {
		vector<int>::iterator vec_it;
		for (vec_it = nums.begin(); vec_it != nums.end(); vec_it++)
			cout<<*vec_it<<" ";
		cout<<endl;
	}
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        	return 0;
        if (nums.size() == 1)
        	return 1;
        int left = 1, right = nums.size() - 1;
        while (right >= left) {
        	if (nums[left] != nums[left - 1])
        		left ++;
        	else {
        		nums.erase(nums.begin() + left - 1);
        		right--;
        	}
        }
        display(nums);
        return nums.size();
    }
};

int main() {
	Solution solve;
	vector<int> nums;
	int sz, ip;
	cin>>sz;
	while (sz--) {
		cin>>ip;
		nums.push_back(ip);
	}
	cout<<solve.removeDuplicates(nums)<<endl;
	return 0;
}