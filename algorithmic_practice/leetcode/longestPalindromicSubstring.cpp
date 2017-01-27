#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (!s.size())
            return "";
        if (s.size() == 1)
            return s;
        int max_diff = -1, diff = -1, left, right, best_left = 0, best_right = 0;
        int i = 0;
        while (i < s.length() - 1) {
            left = i;
            while (s[i + 1] == s[i]) {
                i++;
            }
            right = i;
            while (left > 0 && right < s.length() - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            diff = (right - left + 1);
            //cout<<i<<" "<<left<<" "<<right<<" "<<diff<<" "<<s.substr(left, right - left + 1)<<endl;
            if (diff > max_diff) {
                best_left = left;
                best_right = right;
                max_diff = diff;
            }
            i++;
        }
        return s.substr(best_left, best_right - best_left + 1);
        
    }
};

int main() {
    Solution solve;
    string s, r;
    cin>>s;
    r = solve.longestPalindrome(s);
    cout<<r<<endl;
    return 0;
}