#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int getMax(vector<int>& nums) {
        int max = nums[0];
        for(vector<int>::iterator it = nums.begin();it!=nums.end();++it) {
            if(*it > max) {
                max = *it;
            }
        }
        return max;
    }
    int getMin(vector<int>& nums) {
        int min = nums[0];
        for(vector<int>::iterator it = nums.begin();it!=nums.end();++it) {
            if(*it < min) {
                min = *it;
            }
        }
        return min;
    }
    void normalizeVectorAndTarget(vector<int>& nums, int& target) {
        int lowest = getMin(nums);
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
    vector<int> twoSum(vector<int>& nums, int target) {
        normalizeVectorAndTarget(nums, target);
        vector<int>hash (getMax(nums)+1, -1);
        vector<int>result;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i]<=target && target - nums[i] <= getMax(nums) && hash[target - nums[i]] != -1) {
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

int main() {
    Solution obj;
    int target, size, input;
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
    cin>>target;
    vector<int> result = obj.twoSum(nums, target);
    for(vector<int>::iterator it = result.begin();it!=result.end();++it) {
        cout<<*it<<" ";
    }
    return 0;
}