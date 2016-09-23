#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
    	if(grid.size() == 0 || grid[0].size() == 0)
    		return 0;
        vector<vector<int> >result = grid;
        for(int i = 0;i<result.size();i++) {
        	for(int j=0;j<result[0].size();j++) {
        		if(i == 0 && j == 0)
        			result[i][j] = grid[i][j];
        		else if(i == 0)
        			result[i][j] = result[i][j-1] + grid[i][j];
        		else if(j == 0)
        			result[i][j] = result[i-1][j] + grid[i][j];
        		else 
        			result[i][j] = grid[i][j] + min(result[i-1][j], result[i][j-1]);
        	}
        }
        return result[result.size()-1][result[0].size()-1];
    }
};

int main() {
	int m,n, input;
	cin>>m>>n;
	vector<vector<int> > grid (m, vector<int>(n, 0));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>grid[i][j];
		}
	}
	Solution solver;
	cout<<solver.minPathSum(grid)<<endl;
	return 0;
}	