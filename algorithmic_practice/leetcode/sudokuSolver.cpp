#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void display(vector<vector<char> >& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++)
                cout<<board[i][j];
            cout<<endl;
        }
    }
    void input(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cin>>board[i][j];
        }
    }
    int countEmpty(vector<vector<char> >& board) {
        int ct = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    ct++;
        return ct;
    }

    bool isValidMove(vector<vector<char> >& board, int row, int col, char val) {
        bool inRow = false, inCol = false, inRect = false;
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == val) {
                inRow = true;
                break;
            }
        }

        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == val) {
                inCol = true;
                break;
            }
        }
        int gridRow = (row/3*3);
        int gridCol = (col/3*3);
        for (int i = gridRow; i < gridRow + 3; i++) {
            for (int j = gridCol; j < gridCol + 3; j++) {
                if (board[i][j] == val) {
                    inRect = true;
                    break;
                }
            }
        }
        if (!inRow && !inCol && !inRect) return true;
        return false;
    }
    void solveSudoku(vector<vector<char> >& board) {
        int empty = countEmpty(board), filled = 0;
        solveRecurse(board, empty, filled);
        return;
    }
    bool solveRecurse(vector<vector<char> >& board, int empty, int& filled) {
        if (filled == empty)
            return true;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValidMove(board, i, j, k)) {
                            board[i][j] = k;
                            filled++;
                            if(solveRecurse(board, empty, filled))
                                return true;
                            board[i][j] = '.';
                            filled--;
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solve;
    vector<vector<char> > board(9, vector<char>(9, '.'));
    solve.input(board);
    solve.display(board);
    solve.solveSudoku(board);
    solve.display(board);
    return 0;
}