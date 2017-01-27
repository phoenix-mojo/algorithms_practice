#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     int result = 0, sum, i, j, k;
     sort(nums.begin(), nums.end());

     if(nums.size() <= 3) {
        for(i = 0; i<nums.size(); i++)
            result += nums[i];
        return result;
     }
     result = nums[0] + nums[1] + nums[2];
     for(i = 0;i<nums.size()-2;i++) {
        j = i + 1;
        k = nums.size()-1;
        while(j<k) {
            sum =  nums[i] + nums[j] + nums[k];
            if (abs(target - result) > abs(target - sum)) {
                result = sum;
                if (result == target) return result;
            }
            (sum > target) ? k-- : j++;
        }
     }
     return result;
 }
};

int main() {
    Solution obj;
    int size, input, target;
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
    int result;
    result = obj.threeSumClosest(nums, target);
    cout<<result<<endl;
    return 0;
}