#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void fillFactorials(vector<int> &factorials) {
		factorials[0] = 1;
		for (int i = 1; i < factorials.size(); i++)
			factorials[i] = i * factorials[i-1];
	}

	void fillNums(vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++)
			nums[i] = i + 1;
	}

    string getPermutation(int n, int k) {
    	string res = "";
    	vector<int> nums(n, 0);
    	vector<int> factorials(n, 0);
    	if (n == 0 || k == 0)
    		return "";
    	fillFactorials(factorials);
    	fillNums(nums);
    	if (k == 1) {
    		for (int i = 0; i < nums.size(); i++) {
    			res += (nums[i] + '0');
    		}
    		return res;
    	}
    	k--;
    	for (int i = 0; i < n; i++) {
    		cout<<k<<" "<<factorials[n-i-1]<<" "<<k / factorials[n-i-1]<<" "<<nums[k / factorials[n-i-1]]<<" ";
    		res += (nums[k / factorials[n-i-1]] + '0');
    		nums.erase(nums.begin() + k / factorials[n-i-1]);
    		k = k - (k / factorials[n-i-1]) * factorials[n-i-1];
    		cout<<k<<endl;
    	}
    	return res;   
    }
};

int main() {
	int n, k;
	string res;
	cin>>n>>k;
	Solution s;
	res = s.getPermutation(n, k);
	cout<<res<<endl;
	return 0;
}