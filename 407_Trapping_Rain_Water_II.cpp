#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    void defineConnectedSpace( int i, int j, int currentHeight,
    vector<vector<int>>& heightMapExpanded, vector<vector<int>>& maxHeightMap,
    vector<vector<bool>>& maxHeightMapSeen) {
        maxHeightMapSeen[i][j] = true;
        if (maxHeightMap[i][j] > currentHeight) {
            maxHeightMap[i][j] = currentHeight;
        }
        if (i + 1 < heightMapExpanded.size() && heightMapExpanded[i + 1][j] <= currentHeight && !maxHeightMapSeen[i + 1][j])  {
            defineConnectedSpace(i + 1, j, currentHeight, heightMapExpanded, maxHeightMap, maxHeightMapSeen);
        }
        if (i - 1 >= 0 && heightMapExpanded[i - 1][j] <= currentHeight && !maxHeightMapSeen[i - 1][j])  {
            defineConnectedSpace(i - 1, j, currentHeight, heightMapExpanded, maxHeightMap, maxHeightMapSeen);
        }
        if (j + 1 < heightMapExpanded[0].size() && heightMapExpanded[i][j + 1] <= currentHeight && !maxHeightMapSeen[i][j + 1])  {
            defineConnectedSpace(i, j + 1, currentHeight, heightMapExpanded, maxHeightMap, maxHeightMapSeen);
        }
        if (j - 1 >= 0 && heightMapExpanded[i][j - 1] <= currentHeight && !maxHeightMapSeen[i][j - 1])  {
            defineConnectedSpace(i, j - 1, currentHeight, heightMapExpanded, maxHeightMap, maxHeightMapSeen);
        }
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> heightMapExpanded(heightMap.size() + 2, vector<int> (heightMap[0].size() + 2, 0));
        vector<vector<int>> maxHeightMap(heightMap.size() + 2, vector<int> (heightMap[0].size() + 2, INT_MAX));
        
        int maxHeight = 0;
        for (int i = 0 ; i < heightMap.size(); i ++ ) {
            for (int j = 0 ; j < heightMap[0].size(); j ++ ) {
                heightMapExpanded[i+1][j+1] = heightMap[i][j];
                if (maxHeight < heightMap[i][j]) {
                    maxHeight = heightMap[i][j];
                } 
            }    
        }
        for (int h = 0 ; h <= maxHeight; h ++) {
            vector<vector<bool>> maxHeightMapSeen(heightMap.size() + 2, vector<bool> (heightMap[0].size() + 2, false));
            defineConnectedSpace(0, 0, h, heightMapExpanded, maxHeightMap, maxHeightMapSeen);
            // cout << "\n";    
            // for (int i = 0 ; i < maxHeightMap.size(); i ++ ) {
            //     for (int j = 0 ; j < maxHeightMap[0].size(); j ++ ) {
            //         cout << maxHeightMapSeen[i][j] << "\t"; 
            //     }
            //     cout << "\n";    
            // }
            // cout << "\n";    
            // for (int i = 0 ; i < maxHeightMap.size(); i ++ ) {
            //     for (int j = 0 ; j < maxHeightMap[0].size(); j ++ ) {
            //         cout << maxHeightMap[i][j] << "\t"; 
            //     }
            //     cout << "\n";    
            // }
        }

        int res = 0;

        for (int i = 0 ; i < maxHeightMap.size(); i ++ ) {
            for (int j = 0 ; j < maxHeightMap[0].size(); j ++ ) {
                // cout << maxHeightMap[i][j] << "\t"; 
                res += (maxHeightMap[i][j] - heightMapExpanded[i][j]);
            }
            // cout << "\n";    
        }
        // cout << "\n";    
        // for (int i = 0 ; i < maxHeightMap.size(); i ++ ) {
        //     for (int j = 0 ; j < maxHeightMap[0].size(); j ++ ) {
        //         cout << heightMapExpanded[i][j] << "\t"; 
        //     }
        //     cout << "\n";    
        // }
        return res;
    }
};

void main() {
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    Solution solution;
    auto res = solution.trapRainWater(heightMap);
    cout << res << "\n";
};