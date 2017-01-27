#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void displayVector(vector<int> &nums) {
    while (!nums.empty()) {
        cout<<nums.front()<<" ";
        nums.erase(nums.begin());
    }
    cout<<endl;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lpos = -1, rpos = -1, temp;
        if (nums.empty() || nums.size() == 1)
            return;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                lpos = i;
                break;
            }
        }
        if (lpos == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > nums[lpos]) {
                rpos = i;
                break;
            }
        }
        temp = nums[lpos];
        nums[lpos] = nums[rpos];
        nums[rpos] = temp;
        
        reverse(nums.begin() + lpos + 1, nums.end());
    }
};

int main () {
    int sz, ip;
    cin>>sz;
    vector<int> nums;
    Solution s;
    while (sz--) {
        cin>>ip;
        nums.push_back(ip);
    }
    s.nextPermutation(nums);
    displayVector(nums);
    return 0;
}