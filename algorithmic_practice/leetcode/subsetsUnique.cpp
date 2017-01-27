#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void display(vector<vector<int> >& result) {
	vector<vector<int> >::iterator vec_it;
	vector<int>::iterator vec_it2;
	for (vec_it = result.begin(); vec_it != result.end(); vec_it++) {
		for (vec_it2 = (vec_it->begin()); vec_it2 != (vec_it->end()); vec_it2++)
			cout<<*vec_it2<<" ";
		cout<<endl;
	}
}


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> >result;
        sort(nums.begin(), nums.end());
        int prev_size, curr_dup;
        map<int, int> freq;
        result.push_back(vector<int>(0, 0));
        if (nums.size() == 1) {	
       		result.push_back(result[0]);
        	result.back().push_back(nums[0]);
        }
        if (nums.size() <= 1)
        	return result;
        for (int i = 0; i <nums.size();i++)
        	freq[nums[i]]++;
        		
        for (int i = 0;i < nums.size();i+=freq[nums[i]]) {
        	prev_size = result.size();
        	for (int j = 0; j < prev_size;j++) {	
        		for (int k = 1; k<=freq[nums[i]]; k++) {
        			result.push_back(result[j]);
        			for (int p = 1; p<=k; p++) {
        				result.back().push_back(nums[i]);
    				}
				}
        	}
        }
        return result;
    }
};

int main() {
	Solution solve;
	vector<int> nums;
	vector<vector<int> >result;
	int sz, ip;
	cin>>sz;
	while (sz--) {
		cin>>ip;
		nums.push_back(ip);
	}
	result = solve.subsetsWithDup(nums);
	display(result);
}