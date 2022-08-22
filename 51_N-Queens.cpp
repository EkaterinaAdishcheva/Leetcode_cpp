#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

private:
    vector<bool> possiblePositions(const vector<int> &queensPositions, int n) {
        vector<bool> res (n, true);
        for(int i = 0; i < queensPositions.size(); i ++) {
            res[queensPositions[i]] = false;
            if (queensPositions[i] - (int(queensPositions.size()) - i) >= 0) {
                res[queensPositions[i] - (int(queensPositions.size()) - i)] = false;
            }
            if (queensPositions[i] + (int(queensPositions.size()) - i) < n) {
                res[queensPositions[i] + (int(queensPositions.size()) - i)] = false;
            }
        }
        return res;
    }
    void placeQueen(vector<int> &queensPositions, int n, vector<vector<int>> &results)  {
        vector<bool> positions = possiblePositions(queensPositions, n);
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( positions[i] ) {
                queensPositions.push_back(i);
                if (queensPositions.size() == n) {
                    results.push_back(queensPositions);
                } else {
                    placeQueen(queensPositions, n, results);
                }
                queensPositions.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> res;
        vector<int> positions;
        placeQueen(positions, n, res);
        string basicString = "";
        for (int i = 0 ; i < n ; i ++ ) {
            basicString += ".";
        }
        vector<string> stringRes (n, basicString);
        vector<vector<string>> finalRes;
        for (int k = 0; k < res.size(); k ++ )  {
            vector<string> stringRes (n, basicString);
            for(int i = 0; i < n ; i ++ ) {
                stringRes[i][res[k][i]] = 'Q';
            }
            finalRes.push_back(stringRes);
        }
        return finalRes;
    }
};

void main() {
    int n = 4;
    Solution solution;
    auto res = solution.solveNQueens(n);
    cout << res.size() << "\t" << res[0].size() << "\n";
}