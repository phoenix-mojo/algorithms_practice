#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	stack<int> incr;
    	int max_area = -1;
    	int curr_area = 0, cached_top = -1;
    	if (heights.empty())
    		return 0;
    	heights.insert(heights.begin(), -1); // Insert dummy at front
    	heights.push_back(-1); // Insert dummy at back
    	incr.push(0);
    	for (int i = 1; i < heights.size(); i++) {
    		while (heights[i] < heights[incr.top()]) {
    			cached_top = incr.top();
    			incr.pop();
				curr_area = heights[cached_top] * (i - incr.top() - 1);
    			max_area = max (max_area, curr_area);
    		}
    		incr.push(i);
    	}
    	return max_area;
    }
};

int main() {
	int sz, ip;
	vector<int> heights;
	Solution s;
	cin>>sz;
	while (sz--) {
		cin>>ip;
		heights.push_back(ip);
	}
	cout<<s.largestRectangleArea(heights);
	return 0;
}