#include <iostream>
#include <vector>

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
    vector<vector<int> > permute(vector<int>& nums) {
    	vector<vector<int> >result;
    	vector<int> perm;
        if (nums.empty())
        	return result;
        if (nums.size() == 1) {
        	result.push_back(nums);
        	return result;
    	}
    	vector<vector<int> > temp;
    	temp.push_back(vector<int> (0, 0));
    	temp[0].push_back(nums[0]);
    	for (int i = 1; i<nums.size(); i++) {
    		result.clear();
    		for (int j = 0; j < temp.size(); j++) {
    			for (int k = 0; k<temp[j].size() + 1; k++) {
    				perm.resize(temp[j].size() + 1);
    				perm = temp[j];
    				perm.insert(perm.begin() + k, nums[i]);
    				result.push_back(perm);
                    if (k < temp.size() && temp[j][k] == nums[i])
                        break;
    			}
    		}
    		temp = result;
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
	result = solve.permute(nums);
	display(result);
}