#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void canReachOcean(
                vector<vector<int>>& heights, vector<vector<bool>>& oceanWaterFlow,
                vector<vector<bool>>& oceanWaterFlowSeen, int i, int j) {
        if ( oceanWaterFlowSeen[i][j] ) return;
        oceanWaterFlowSeen[i][j] = true;
        vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto d: direction) {
            if ((i + d[0]) >= 0 && (i + d[0]) < heights.size() &&
                    (j + d[1]) >= 0 && (j + d[1]) < heights[0].size() &&
                    heights[i][j] <= heights[i + d[0]][j + d[1]] ) {
                oceanWaterFlow[i + d[0]][j + d[1]] = true;
                canReachOcean(heights, oceanWaterFlow, oceanWaterFlowSeen, i + d[0], j + d[1]);
            }
        }
    }    
    

    void showArray(vector<vector<bool>> matrix) {
        for (int i = 0 ; i < matrix.size(); i ++ ) {
            for (int j = 0 ; j < matrix[0].size(); j ++ ) {
                cout << matrix[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacificWaterFlow(
            heights.size(),
            vector<bool>(heights[0].size(), false));
        vector<vector<bool>> pacificWaterFlowSeen(
            heights.size(),
            vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlanticWaterFlow(
            heights.size(),
            vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlanticWaterFlowSeen(
            heights.size(),
            vector<bool>(heights[0].size(), false));

        for (int i = 0 ; i < heights.size(); i ++ ) {
            pacificWaterFlow[i][0] = true;
            atlanticWaterFlow[i][heights[0].size() - 1] = true;
        }
        for (int j = 0 ; j < heights[0].size(); j ++ ) {
            pacificWaterFlow[0][j] = true;
            atlanticWaterFlow[heights.size() - 1][j] = true;
        }
        for (int i = 0 ; i < heights.size(); i ++ ) {
            canReachOcean(heights, pacificWaterFlow, pacificWaterFlowSeen, i, 0);
            canReachOcean(heights, atlanticWaterFlow, atlanticWaterFlowSeen, i, heights[0].size() - 1);
        }
        for (int j = 0 ; j < heights[0].size(); j ++ ) {
            canReachOcean(heights, pacificWaterFlow, pacificWaterFlowSeen, 0, j);
            canReachOcean(heights, atlanticWaterFlow, atlanticWaterFlowSeen, heights.size() - 1, j);
        }

        showArray(pacificWaterFlow);
        showArray(atlanticWaterFlow);

        vector<vector<int>> res;
        for (int i = 0 ; i < heights.size(); i ++ ) {
            for (int j = 0 ; j < heights[0].size(); j ++ ) {
                if (pacificWaterFlow[i][j] && atlanticWaterFlow[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

void main() {
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution solution;
    auto res = solution.pacificAtlantic(heights);
    for (int i = 0 ; i < res.size(); i ++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "], ";
    }
    cout << "\n";
}