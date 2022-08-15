#include <vector>
#include <iostream>
#include <string>

using namespace std;

char EMPTY_CELL = '.';

class Solution {
private:
    bool checkRow(int r, vector<vector<char>>& board) {
        vector<bool> numberInd(board.size(), false);
        for (int i = 0 ; i < board.size(); i ++) {
            if (board[r][i] != EMPTY_CELL) {
                if ( (board[r][i] - '1') >= numberInd.size() || 
                    (board[r][i] - '1') < 0 ||
                    numberInd[board[r][i] - '1'] ) {
                    return false;
                }
                numberInd[board[r][i] - '1'] = true;
            }
        }
        return true;
    }

    bool checkColumn(int c, vector<vector<char>>& board) {
        vector<bool> numberInd(board.size(), false);
        for (int i = 0 ; i < board.size(); i ++) {
            if (board[i][c] != EMPTY_CELL) {
                if ( (board[i][c] - '1') >= numberInd.size() ||
                    (board[i][c] - '1') < 0 ||
                    numberInd[board[i][c] - '1'] ) {
                    return false;
                }
                numberInd[board[i][c] - '1'] = true;
            }
        }
        return true;
    }

    bool checkSquare(int c, int r, vector<vector<char>>& board) {
        vector<bool> numberInd(board.size(), false);
        c *= 3;
        r *= 3;
        for (int i = 0 ; i < board.size() / 3; i ++) {
            for (int j = 0 ; j < board[0].size() / 3; j ++) {
                    if (board[r + i][c + j] != EMPTY_CELL) {
                    if ( (board[r + i][c + j] - '1') >= numberInd.size() ||
                        (board[r + i][c + j] - '1') < 0 ||
                        numberInd[board[r + i][c + j] - '1'] ) {
                    return false;
                    }
                    numberInd[board[r + i][c + j] - '1'] = true;
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0 ; i < board.size() ; i ++ ) {
            auto res = checkColumn(i, board);
            if (!res) {
                return false;
            }
            res = checkRow(i, board);
            if (!res) {
                return false;
            }
            res = checkSquare(i % 3, i / 3, board);
            if (!res) {
                return false;
            }
        }
        return true;
    }
};

void main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    cout << '1' - '1' << "\n";
    cout << '9' - '1' << "\n";
    Solution solution;
    auto res = solution.isValidSudoku(board);
    cout << res * 1 << "\n";
}