#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int k = 0;
        int width = matrix[0].size();
        int height = matrix.size();
        vector<int> res;
        while (k < height / 2 && k < width / 2 ) {
            for (size_t i = k; i < width - k - 1; i ++) {
                res.push_back( matrix[k][i] );
            }
            for (size_t i = k; i < height - k - 1; i ++) {
                res.push_back( matrix[i][width - k - 1] );
            }
            for (size_t i = k; i < width - k - 1; i ++) {
                res.push_back( matrix[height - k - 1][width - 1 - i] );
            }
            for (size_t i = k; i < height - k - 1; i ++) {
                res.push_back( matrix[height - 1 - i][k] );
            }
            k ++;
        }
        if (height % 2 == 1 && k == height / 2) {
            for (size_t j = k ; j < width - k; j ++ ) {
                res.push_back( matrix[k][j] );
            }
        }         
        else if (width % 2 == 1 && k == width / 2) {
            for (size_t j = k ; j < height - k; j ++ ) {
                res.push_back( matrix[j][k] );
            }
        }         
        return res;
    }
};



void main() {
    vector<vector<int>> matrix = {{1,2,3},};
    vector<int> res;
    Solution solution;
    std::cout << "res" << "\n";
    res = solution.spiralOrder(matrix);
    for (auto x: res) {
        std::cout << x << "\n";
    }
}
