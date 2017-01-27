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
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> >result;
        int prev_size;
        result.push_back(vector<int>(0, 0));
        for (int i = 0;i <nums.size(); i++) {
        	prev_size = result.size();
        	for (int j = 0; j < prev_size;j++) {
        		result.push_back(result[j]);
        		result.back().push_back(nums[i]);
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
	result = solve.subsets(nums);
	display(result);
}