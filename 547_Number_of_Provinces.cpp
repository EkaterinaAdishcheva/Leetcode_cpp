#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void dfs(int i, vector<bool> &seen, vector<vector<int>> &v) {
        seen[i] = true;
        for (int j = 0; j < v.size(); j ++ ) {
            if( i!= j && v[i][j] == 1 && !seen[j]) {
                dfs(j, seen, v);    
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<bool> seen(n, false);
        for (int i = 0 ; i < n ; i ++ ) {
            if (!seen[i]) {
                dfs(i, seen, isConnected);
                res ++;
            }
        }
        return res;
    }
};