#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size()) {
            return mat;
        }
        vector<vector<int>> res(r, vector<int> (c));
        int i1 = 0, j1 = 0;
        for (int i = 0 ; i < mat.size(); i ++ ) {
            for (int j = 0 ; j < mat[0].size(); j ++ ) {
                res[i1][j1] = mat[i][j];
                j1 ++;
                if (j1 >= c ) {
                    j1 = 0;
                    i1 ++;
                }
            }    
        }
        return res;
    }
};