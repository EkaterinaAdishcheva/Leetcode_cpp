#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        for (size_t j = 0; j < grid[0].size(); j ++ ) {
            res.push_back(j);
        }
        for (size_t i = 0; i < grid.size(); i ++ ) {
            for (size_t j = 0; j < grid[0].size(); j ++ ) {
                if ( res[j] == - 1) {
                    continue;
                }
                else if ( res[j] < grid[0].size() - 1 && grid[i][res[j]] == 1 && grid[i][res[j] + 1] == -1) {
                    res[j] = -1;
                }
                else if ( res[j] > 0 && grid[i][res[j]] == -1 && grid[i][res[j] - 1] == 1) {
                    res[j] = -1;
                }
                else if ( res[j] > 0 && grid[i][res[j]] == -1 && grid[i][res[j] - 1] == 1) {
                    res[j] = -1;
                }
                else {
                    res[j] += grid[i][res[j]];
                    if ( res[j] == grid[0].size() || res[j] == -1) {
                        res[j] = -1;
                    }
                }
            }   
        }
        return res;        
    }
};

void main() {
    vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    vector<int> res;
    Solution solution;
    std::cout << "res" << "\n";
    res = solution.findBall(grid);
    for (auto x: res) {
        std::cout << x << "\n";
    }
};