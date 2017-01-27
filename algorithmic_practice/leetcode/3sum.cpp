#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    void normalizeVectorAndTarget(vector<int>& nums, int& target) {
        int lowest = nums[0];
        if(lowest>=0) {
            return;
        }
        else {
            for(vector<int>::iterator it = nums.begin();it!=nums.end();++it) {
                *it-=lowest;
            }
            target = target-2*lowest;
        }
    }

    vector<vector<int> > twoSum(vector<int> nums, int target, vector<vector<int> >&result) {
    	int min = nums[0] >=0 ? 0 : nums[0];
        normalizeVectorAndTarget(nums, target);
        vector<int>hash (nums[nums.size()-1]+1, -1);
        for(int i = 0;i<nums.size();i++) {
            if(nums[i]<=target && target - nums[i] <= nums[nums.size()-1] && hash[target - nums[i]] != -1 && (i == nums.size()-1 || nums.size() == 2 || (i != nums.size()-1 && nums[i+1] != nums[i]))) {
            	vector<int>temp;
            	temp.push_back(0-target - 2*min);
                temp.push_back(target - nums[i]+min);
                temp.push_back(nums[i]+min);
                result.push_back(temp);
            }
            hash[nums[i]] = i;
        }
        return result;
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
    	int target = 0;
    	sort(nums.begin(), nums.end());
        vector<vector<int> >result;
        if(nums.size()<3)
        	return result;
        for(int i = 0;i<nums.size()-2;i++) {
        	
        	if(i == 0 || (i != 0 && nums[i] != nums[i-1])) {
    			vector<int> my_nums(nums.begin()+i+1, nums.end());
        		result = twoSum(my_nums, target-nums[i], result);
        	}
        }
        return result;
    }
    void displayVector(vector<vector<int> >& results) {
		for(vector<vector<int> >::iterator it = results.begin(); it!= results.end(); it++) {
			for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
				cout<<*it2<<" ";
			cout<<endl;
		}
	}
	void displayVector1(vector<int>& results) {
		for(vector<int>::iterator it = results.begin(); it!= results.end(); it++) {
				cout<<*it<<" ";
		}
		cout<<endl;
	}
};

int main() {
    Solution obj;
    int size, input;
    cin>>size;
    if(size <= 0) {
        cout<<"Must input a non-zero vector! Fail.";
        return -1;
    }
    vector<int> nums;
    while(size-- > 0) {
        cin>>input;
        nums.push_back(input);
    }
    vector<vector<int> > result;
    result = obj.threeSum(nums);
    obj.displayVector(result);
    return 0;
}