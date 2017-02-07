#include <iostream>
#include <vector>

using namespace std;

class QuadTreeNode {

public:
	int val;
	bool unified;
	QuadTreeNode* neighbor[4];
	pair<int, int> leftTop;
    pair<int, int> rightBottom;
	QuadTreeNode(int init, pair<int, int> start, pair<int, int> end) {
		val = init;
		unified = false;
		leftTop = start;
		rightBottom = end;
	}
};

class QuadTree {
private:
    QuadTreeNode* root;
    bool checkUnified(vector<vector<int> >& matrix, pair<int, int> start, pair<int, int> end) {
    	int val = matrix[start.first][start.second];
    	for (int i = start.first; i <= end.first; i++) {
    		for (int j = start.second; j <= end.second; j++) {
    			//cout<<matrix[i][j]<<" "<<val<<endl;
    			if (matrix[i][j] != val)
    				return false;
    		}
    	}
    	return true; 
    }
    QuadTreeNode* createTree(vector<vector<int> > &matrix, pair<int, int> start, pair<int, int> end) {
        if (start.first > end.first || start.second > end.second)
            return NULL;
        QuadTreeNode* cur = new QuadTreeNode(0, start, end);
        if (start == end || checkUnified(matrix, start, end)) {
        	cur->unified = true;
            cur->val = matrix[start.first][start.second];
            return cur;
        }
    
        int midx = ( start.first + end.first ) / 2;
        int midy = (start.second + end.second) / 2;
        cur->neighbor[0] = createTree(matrix, start, make_pair(midx, midy));
        cur->neighbor[1] = createTree(matrix, make_pair(start.first, midy+1), make_pair(midx, end.second));
        cur->neighbor[2] = createTree(matrix, make_pair(midx+1, start.second), make_pair(end.first, midy));
        cur->neighbor[3] = createTree(matrix, make_pair(midx+1, midy+1), end);
        /*cout<<"---\n";
        for (int i = 0; i < 4; i++) {
            if (cur->neighbor[i])
                cout<<cur->neighbor[i]->val<<" ";
        }
        cout<<"\n---\n";*/
        return cur;
    }
    void walkQuadTree(QuadTreeNode* node) {
    	if (node == NULL)
    		return;
    	if (node->unified) {
			cout<<node->val<<" ";
			return;
    	}
		for (int i = 0; i < 4; i++)
				walkQuadTree(node->neighbor[i]);
    } 
public:
    QuadTree(vector<vector<int> >& matrix) {
        if (matrix.empty()) return;
        int row = matrix.size();
        if (row == 0) return;
        int col= matrix[0].size();
        root = createTree(matrix, make_pair(0,0), make_pair(row-1, col-1));
    }

   	void traverseQuadTree() {
   		walkQuadTree(root);
   	} 
};

vector<vector<int> > input() {
	int rows, cols;
	cout<<"Number of rows: ";
	cin>>rows;
	cout<<"Number of columns: ";
	cin>>cols;
	vector<vector<int> > matrix(rows, vector<int> (cols, 0));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin>>matrix[i][j];
	return matrix;
}

int main() {
	vector<vector<int> > matrix;
	matrix = input();
	QuadTree obj(matrix);
	obj.traverseQuadTree();
	return 0;
}