#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<string>& str) {
	vector<string>::iterator it;
	for (it = str.begin(); it != str.end(); it++) {
		cout<<*it<<endl;
	}
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	int range_beg = 0, i;
    	string range_desc;
    	vector<string> result;
        if (nums.empty())
        	return (vector<string> (0, ""));
        if (nums.size() == 1)
        	return (vector<string> (1, to_string(nums[0])));
        for (i = 0; i < nums.size() - 1; i++) {
        	if (nums[i + 1] != nums[i] + 1) {
        		if (i == range_beg)
        			result.push_back(to_string(nums[i]));
        		else {
        			range_desc  = to_string (nums[range_beg]);
        			range_desc += "->";
        			range_desc += to_string (nums[i]);
        			result.push_back(range_desc);
        		}
        		range_beg =  i + 1;
        	}
        }
        if (nums[i] != nums[i - 1] + 1) {
        	if (i == range_beg)
        			result.push_back(to_string(nums[i]));
        		
        }
        else {
    			range_desc  = to_string (nums[range_beg]);
    			range_desc += "->";
    			range_desc += to_string (nums[i]);
    			result.push_back(range_desc);
        }

        return result;
    }
};

int main() {
	int sz, ip;
	vector<int> nums;
	vector<string> result;
	Solution solve;
	cin>>sz;
	while (sz--) {
		cin>>ip;
		nums.push_back(ip);
	}
	result = solve.summaryRanges(nums);
	displayVector(result);
	return 0;
}