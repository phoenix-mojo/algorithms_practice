#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<vector<int> > res) {
	vector<vector<int> >::iterator it;
	vector<int>::iterator inner;
	if (res.empty())
		return;
	for (it = res.begin(); it != res.end(); it++) {
		for(inner = it->begin(); inner != it->end(); inner++)
			cout<<*inner<<" ";
		cout<<endl;
	}
}
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0)
        	return res;
        res.push_back(vector<int>(1, 1));
        if (numRows == 1)
        	return res;
        numRows--;
        for (int row = 1; row <= numRows; row++) {
        	res.push_back(vector<int>(1, 1));
        	for (int prev_row_iter = 1; prev_row_iter < res[row - 1].size(); prev_row_iter++) {
        		res[row].push_back(res[row - 1][prev_row_iter - 1] + res[row - 1][prev_row_iter]);
        	}
        	res[row].push_back(1);
        }
        return res;
    }
};

int main() {
	Solution solve;
	vector<vector<int> > res;
	int numRows;
	cin>>numRows;
	res = solve.generate(numRows);
	displayVector(res);
	return 0;
}