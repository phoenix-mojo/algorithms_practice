#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	vector<int> result;
    	if (matrix.empty())
    		return result;
    	int row = matrix.size();
        int col = matrix[0].size();
        if (col == 0 || row == 0)
        	return result;
        pair<int, int> tl, tr, bl, br;
        tl = make_pair(0, 0);
        tr = make_pair(0, col - 1);
        bl = make_pair(row - 1, 0);
        br = make_pair(row - 1, col - 1);
  
        while (tr.second >= tl.second && br.second >= bl.second && bl.first >= tl.first && br.first >= tr.first) {
        		for (int j = tl.second; j <= tr.second; j++) {
        			result.push_back(matrix[tl.first][j]);
        		}
        		for (int j = tr.first + 1; j <= br.first; j++) {
        			result.push_back(matrix[j][tr.second]);
        		}
        		if (tr != br) {
        			for (int j = br.second - 1; j > bl.second; j--) {
        				result.push_back(matrix[bl.first][j]);
        			}
        		}
        		
        		if (bl != br) {
        			for (int j = bl.first; j > tl.first; j--) {
        				result.push_back(matrix[j][tl.second]);
        			}
        		}

        		tl.second++;
        		tl.first++;
        		tr.second--;
        		tr.first++;
        		bl.second++;
        		bl.first--;
        		br.second--;
        		br.first--;
        }
        return result;
    }
};

int main() {
	Solution solve;
	vector<int> res;
	vector<vector<int> > matrix;
	int m, n, ip;
	cin>>m>>n;
	matrix.resize(m);
	for (int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin>>ip;
			matrix[i].push_back(ip);
		}
	}
	res = solve.spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}