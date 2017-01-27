#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int>& nums1) {
	vector<int>::iterator it;
	for (it = nums1.begin(); it != nums1.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
        	if (nums1[i] > nums2[j])
        		nums1[k--] = nums1[i--];
        	else
        		nums1[k--] = nums2[j--];
        	if (j == -1)
        		return;
        }
        if (i == -1) {
    		while (k != -1) {
    			nums1[k--] = nums2[j--];
    		}
    	} 
    }
};

int main() {
	int sz1, sz2, ip, ct = 0;
	vector<int> nums1, nums2;
	Solution solve;
	cin>>sz1>>sz2;
	nums1.resize(sz1 + sz2);
	nums2.resize(sz2);
	while(ct < sz1) {
		cin>>ip;
		nums1[ct++] = ip;
	}
	ct = 0;
	while(ct < sz2) {
		cin>>ip;
		nums2[ct++] = ip;
	}
	solve.merge(nums1, sz1, nums2, sz2);
	displayVector(nums1);
	return 0;
}