#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0]) {
            return false;
        }
        if (target > matrix[matrix.size() - 1][matrix[0].size() - 1]) {
            return false;
        }
        auto start = 0;
        auto end = matrix.size();

        while (start < end ) {
            int middle = start + (end - start) / 2;
            if (matrix[middle][matrix[0].size() - 1] < target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        auto r = start;
        
        if (matrix[r][0] > target) {return false;}
        start = 0;
        end = matrix[0].size();

        while (start < end ) {
            int middle = start + (end - start) / 2;
            if (matrix[r][middle] < target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        } 

        if (matrix[r][start] == target) {return true;}
        return false;
    }
};

void main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    auto target = 3;
    auto solution = Solution();

    bool res = solution.searchMatrix(matrix, target);
    cout << res << "\n";
}
