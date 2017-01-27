#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    char firstDuplicateChar(string s) {
        unordered_map<char, pair<int, int> > freq_index;
        unordered_map<char, pair<int, int> >::iterator map_it;
        int min_pos = s.length() + 1;
        if (!s.length())
            return -1;
        for (int i = 0; i < s.length(); i++) {
            if (freq_index[s[i]].first == 0)
                freq_index[s[i]].second = i;
            freq_index[s[i]].first++;
            
        }
        /*for (map_it = freq_index.begin(); map_it != freq_index.end(); map_it++)
            cout<<map_it->first<<" "<<map_it->second.first<<" "<<map_it->second.second<<endl;*/
        for (map_it = freq_index.begin(); map_it != freq_index.end(); map_it++) {
            if (map_it->second.first > 1) {
                min_pos = min (min_pos, map_it->second.second); 
            }
        }
        return min_pos != s.length() + 1 ? s[min_pos] : -1;
    }
};

int main() {
    string s;
    cin>>s;
    Solution solve;
    cout<<solve.firstDuplicateChar(s)<<endl;
    return 0;
}