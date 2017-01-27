#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int> res) {
	vector<int>::iterator it;
	for (it = res.begin(); it != res.end(); it++)
			cout<<*it<<" ";
	cout<<endl;
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res, prev;
    	if(rowIndex == 0)
    		return (vector<int> (1, 1));
    	prev.push_back(1);
    	for (int i = 1; i <= rowIndex; i++) {
    		res.clear();
    		res.push_back(1);
    		for(int j = 1; j < prev.size(); j++)
    			res.push_back(prev[j] + prev[j - 1]);
    		res.push_back(1);
    		prev = res;
    	}
    	return res;
    }
};

int main() {
	Solution solve;
	vector<int> res;
	int rowIndex;
	cin>>rowIndex;
	res = solve.getRow(rowIndex);
	displayVector(res);
	return 0;
}