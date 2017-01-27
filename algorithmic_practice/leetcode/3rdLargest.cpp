#include<map>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void displayMap(map<int, int>& myMap) {
        for(map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
            cout<<it->first<<"->"<<it->second<<endl;
    }

    int thirdMax(vector<int>& nums) {
        map<int, int> my_map;
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        for(int i = 0;i<nums.size();i++)
            my_map.insert(pair<int, int>(nums[i], 1));
        displayMap(my_map);
        map<int, int>::reverse_iterator it = my_map.rbegin();
        if(my_map.size() >= 3) {
            it++;
            it++;
        }
        return it->first;
    }
};

int main() {
    Solution obj;
    vector<int> nums;
    int size, inp;
    cin>>size;
    while(size--) {
        cin>>inp;
        nums.push_back(inp);
    }
    int result = obj.thirdMax(nums);
    cout<<result<<endl;
    return 0;
}