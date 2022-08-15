#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    void defineConnectedSpace( int i, int j, int currentHeight,
    vector<vector<int>>& heightMap, vector<vector<int>>& maxHeightMap,
    vector<vector<bool>>& maxHeightMapSeen, vector<vector<int>>& border) {
        maxHeightMapSeen[i][j] = true;
        if (maxHeightMap[i][j] > currentHeight) {
            maxHeightMap[i][j] = currentHeight;
        }
        if (i + 1 < heightMap.size() && !maxHeightMapSeen[i + 1][j])  {
            if (heightMap[i + 1][j] <= currentHeight) {
                defineConnectedSpace(i + 1, j, currentHeight, heightMap, maxHeightMap, maxHeightMapSeen, border);
            } else {
                border.push_back({i + 1, j});
            }
        }
        if (i - 1 >= 0 && heightMap[i - 1][j] <= currentHeight && !maxHeightMapSeen[i - 1][j])  {
            defineConnectedSpace(i - 1, j, currentHeight, heightMap, maxHeightMap, maxHeightMapSeen, border);
        }
        if (j + 1 < heightMap[0].size() && heightMap[i][j + 1] <= currentHeight && !maxHeightMapSeen[i][j + 1])  {
            defineConnectedSpace(i, j + 1, currentHeight, heightMap, maxHeightMap, maxHeightMapSeen, border);
        }
        if (j - 1 >= 0 && heightMap[i][j - 1] <= currentHeight && !maxHeightMapSeen[i][j - 1])  {
            defineConnectedSpace(i, j - 1, currentHeight, heightMap, maxHeightMap, maxHeightMapSeen, border);
        }
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> maxHeightMap(heightMap.size(), vector<int> (heightMap[0].size(), INT_MAX));
        
        int maxHeight = 0;
        for (int i = 0 ; i < heightMap.size(); i ++ ) {
            for (int j = 0 ; j < heightMap[0].size(); j ++ ) {
                if (maxHeight < heightMap[i][j]) {
                    maxHeight = heightMap[i][j];
                } 
            }    
        }
        vector<vector<bool>> maxHeightMapSeen(heightMap.size(), vector<bool> (heightMap[0].size(), false));
        for (int h = 0 ; h <= maxHeight; h ++) {
            vector<vector<int>> border;
            for(int i = 0 ; i < maxHeightMap.size(); i ++) {
                if (!maxHeightMapSeen[i][0] && heightMap[i][0] <= h) {
                    defineConnectedSpace(i, 0, h, heightMap, maxHeightMap, maxHeightMapSeen, border);
                }
                if (!maxHeightMapSeen[i][maxHeightMap[0].size() - 1] && heightMap[i][maxHeightMap[0].size() - 1] <= h) {
                    defineConnectedSpace(i, maxHeightMap[0].size() - 1, h, heightMap, maxHeightMap, maxHeightMapSeen);
                }
            }
            for(int j = 0 ; j < maxHeightMap[0].size(); j ++) {
                if (!maxHeightMapSeen[0][j] && heightMap[0][j] <= h) {
                    defineConnectedSpace(0, j, h, heightMap, maxHeightMap, maxHeightMapSeen);
                }
                if (!maxHeightMapSeen[maxHeightMap.size() - 1][j] && heightMap[maxHeightMap.size() - 1][j] <= h) {
                    defineConnectedSpace(maxHeightMap.size() - 1, j, h, heightMap, maxHeightMap, maxHeightMapSeen);
                }
            }
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
                res += (maxHeightMap[i][j] - heightMap[i][j]);
            }
        }
        // cout << "\n";    
        // for (int i = 0 ; i < maxHeightMap.size(); i ++ ) {
        //     for (int j = 0 ; j < maxHeightMap[0].size(); j ++ ) {
        //         cout << maxHeightMap[i][j] << "\t"; 
        //     }
        //     cout << "\n";    
        // }
        // cout << "\n";    
        // for (int i = 0 ; i < maxHeightMap.size(); i ++ ) {
        //     for (int j = 0 ; j < maxHeightMap[0].size(); j ++ ) {
        //         cout << heightMap[i][j] << "\t"; 
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