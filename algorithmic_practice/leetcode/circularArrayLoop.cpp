#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int mod (int a, int b)
    {
       if(b < 0)
         return mod(a, -b);   
       int ret = a % b;
       if(ret < 0)
         ret+=b;
       return ret;
    }

    void displayVector(vector<int>& nums) {
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    void displayMap(map <int, int>& adj_list) {
        map <int, int>::iterator map_it;
        for (map_it = adj_list.begin(); map_it != adj_list.end(); map_it++)
            cout<<map_it->first<<"-> "<<map_it->second<<endl;
    }

    bool validateDirection(vector<int>& path, vector <int>& nums) {
        int i, j;
        for (i = 0; i < path.size() - 1; i++) {
            for (j = i + 1; j < path.size(); j++) {
                if (path[i] == path[j]) {
                    goto out;
                }
            }
        }
        out:
        //cout<<i<<" "<<j<<endl;
        for (int k = i; k < j; k++) {
            if (nums[path[k]] * nums[path[k + 1]] < 0)
                return false;
        }
        return true;
    }
    bool detectCycle(int origin, map <int, int>&adj_list, vector<int>& nums) {
        stack<int> dfs;
        int current_vertex;
        vector<int>path;
        vector<bool>visited (adj_list.size(), false);
        dfs.push(origin);
        visited[origin] = true;
        while(!dfs.empty()) {
            current_vertex = dfs.top();
            dfs.pop();
            path.push_back(current_vertex);
            if (visited[adj_list[current_vertex]] == true && current_vertex != adj_list[current_vertex]) {
                path.push_back(adj_list[current_vertex]);
                //displayVector(path);
                return validateDirection(path, nums);
            }
                
            else {
                if (visited[adj_list[current_vertex]] == false) {
                    visited[adj_list[current_vertex]] = true;
                    dfs.push(adj_list[current_vertex]);
                }
            }
        }
        return false;
    }

    bool circularArrayLoop(vector<int>& nums) {
        map <int, int> adj_list;
        map <int, int>::iterator map_it;
        if (!nums.size())
            return false;
        for (int i = 0; i < nums.size(); i++) {
            adj_list[i] = mod(i + nums[i], nums.size());
        }
        //displayMap(adj_list);

        for (map_it = adj_list.begin(); map_it != adj_list.end(); map_it++) {
            if (detectCycle(map_it->first, adj_list, nums))
                return true;
        }

        return false;
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
    cout<<boolalpha<<solve.circularArrayLoop(nums)<<endl;
    return 0;
}