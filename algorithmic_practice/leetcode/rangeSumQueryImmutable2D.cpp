#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
public:
	vector<vector<int> > dp;
	bool isMatrixEmpty;
    NumMatrix(vector<vector<int> > &matrix) {
    	isMatrixEmpty = matrix.empty() ? true : false;
    	if(isMatrixEmpty)
    		return;
    	fill2DVector(matrix, matrix.size(), matrix[0].size());
    	dp = matrix;
    	fillColumnSums(matrix, dp);
    	fillColumnSumsonRowSums(matrix, dp);
    	//display2DVector(dp, dp.size(), dp[0].size());
    }

    void fillColumnSums(vector<vector<int> > &matrix, vector<vector<int> > &dp) {
    	for(int i=0;i<dp.size();i++) {
    		for(int j=0;j<dp[0].size();j++){
    			if(j==0)
    				dp[i][j] = matrix[i][j];
    			else
    				dp[i][j] = dp[i][j-1] + matrix[i][j];
    		}
    	}
    }

    void fillColumnSumsonRowSums(vector<vector<int> > &matrix, vector<vector<int> > &dp) {
    	for(int j=0;j<dp[0].size();j++) {
    		for(int i=0;i<dp.size();i++){
    			if(i != 0)
    				dp[i][j] += dp[i-1][j];
    		}
    	}
    }

    void fill2DVector(vector<vector<int> > &matrix, int rows, int columns) {
    	for(int i=0;i<rows;i++)
    		for(int j = 0;j<columns;j++)
    			cin>>matrix[i][j];
    }

    void display2DVector(vector<vector<int> > &matrix, int rows, int columns) {
    	for(int i=0;i<rows;i++) {
    		for(int j = 0;j<columns;j++)
    			cout<<matrix[i][j]<<" ";
    		cout<<endl;
    	}
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
    	if(isMatrixEmpty)
    		return 0;
		int totalSumFromOriginTillLowerRightCorner = dp[row2][col2];
        int totalSumFromOriginTillUpperRightCorner = col1>0 ? dp[row2][col1-1] : 0;
        int totalSumFromOriginTillUpperLeftCorner = row1>0 && col1>0 ? dp[row1-1][col1-1] : 0;
        int totalSumFromOriginTillLowerLeftCorner = row1>0 ? dp[row1-1][col2] : 0;
        int result = totalSumFromOriginTillLowerRightCorner - totalSumFromOriginTillUpperRightCorner - totalSumFromOriginTillLowerLeftCorner + totalSumFromOriginTillUpperLeftCorner;
        return result;
    }
};

int main() {
	int m,n;
	cin>>m>>n;
	vector<vector<int> > matrix(m, vector<int>(n));
	NumMatrix numMatrix(matrix);
	cout<<numMatrix.sumRegion(0, 0, 0, 0)<<endl;
	cout<<numMatrix.sumRegion(0, 0, 0, 1)<<endl;
	cout<<numMatrix.sumRegion(0, 1, 0, 1)<<endl;
	return 0;

}