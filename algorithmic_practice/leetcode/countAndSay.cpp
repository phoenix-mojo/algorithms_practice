#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "11", temp;
        int ct = 0, iter, ctr;
        if (n == 0)
            return "";
            if (n == 1)
            return "1";
            if (n == 2)
            return "11";
        for (int i = 3; i <= n; i++) {
            temp = res;
            iter = 0;
            ctr = 1;
            res = "";
            while (iter < temp.length()) {
                
                while (temp[iter] == temp[iter+1]) {
                    ctr++;
                    iter++;
                }
                //cout<<temp[iter];
                res += temp[iter];
                iter++;
                res += to_string(ctr);
                ctr = 1;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solve;
    int n;
    cin>>n;
    cout<<solve.countAndSay(n)<<endl;
    return 0;
}