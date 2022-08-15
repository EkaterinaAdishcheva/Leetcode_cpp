#include <vector>
#include <iostream>
#include <utility>

using namespace std;

const int ROTTEN_IND = 2;
const int FRESH_IND = 1;
const int JUST_SPOILED = 3;

const int FINISH_WITH_FRESH = -1;
const int FINISH_WO_FRESH = 0;
const int CONTINUE = 1;


class Solution {
    private:
        int dayRotting(vector<vector<int>>& grid) {
            auto rotten_qnt = 0;
            for( int i = 0; i < grid.size(); i ++) {
                for( int j = 0; j < grid[0].size(); j ++) {
                    if (grid[i][j] == ROTTEN_IND) {
                        rotten_qnt ++;
                        if (i < grid.size() - 1) {
                            if (grid[i + 1][j] == FRESH_IND) {
                                grid[i + 1][j] = JUST_SPOILED;
                            }
                        }
                        if (j < grid[0].size() - 1) {
                            if (grid[i][j + 1] == FRESH_IND) {
                                grid[i][j + 1] = JUST_SPOILED;
                            }
                        }
                    }
                }    
            }
            cout << "Rotten was: " << rotten_qnt << "\n";
            auto new_rotten_qnt = 0;
            auto have_fresh_otanges = false;
            for( int i = grid.size() - 1; i >= 0; i --) {
                for( int j = grid[0].size() - 1; j >= 0; j --) {
                    if (grid[i][j] == ROTTEN_IND) {
                        new_rotten_qnt ++;
                        if (i > 0) {
                            if (grid[i - 1][j] == FRESH_IND) {
                                grid[i - 1][j] = JUST_SPOILED;
                            }
                        }
                        if (j > 0) {
                            if (grid[i][j - 1] == FRESH_IND) {
                                grid[i][j - 1] = JUST_SPOILED;
                            }
                        }
                    } else if (grid[i][j] == JUST_SPOILED) {
                        new_rotten_qnt ++;
                        grid[i][j] = ROTTEN_IND;
                    } else if (grid[i][j] == FRESH_IND) {
                        have_fresh_otanges = true;
                    }
                }    
            }
            cout << "Rotten now: " << new_rotten_qnt << "\n";
            for( int i = 0; i < grid.size(); i ++) {
                for( int j = 0; j < grid[0].size(); j ++) {
                    cout << grid[i][j] << "\t";            
                }
                cout << "\n";
            }
            if (rotten_qnt == new_rotten_qnt) {
                if (have_fresh_otanges) {return FINISH_WITH_FRESH;}
                return FINISH_WO_FRESH;
            }
            return CONTINUE;
        }


    public:
        int orangesRotting(vector<vector<int>>& grid) {
            auto step = 0;
            while(true) {
                step ++;
                auto res = dayRotting(grid);
                if (res == FINISH_WITH_FRESH) {return FINISH_WITH_FRESH;} 
                if (res == FINISH_WO_FRESH) {return --step;} 
            }
            return 4;
        }
    };

void main() {
    vector<vector<int>> grid = {{2,0,1,1,1,1,1,1,1,1},
{1,0,1,0,0,0,0,0,0,1},
{1,0,1,0,1,1,1,1,0,1},
{1,0,1,0,1,0,0,1,0,1},
{1,0,1,0,1,0,0,1,0,1},
{1,0,1,0,1,1,0,1,0,1},
{1,0,1,0,0,0,0,1,0,1},
{1,0,1,1,1,1,1,1,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}};
    for( int i = 0; i < grid.size(); i ++) {
        for( int j = 0; j < grid[0].size(); j ++) {
            cout << grid[i][j] << "\t";            
        }
        cout << "\n";
    }
    Solution solution;
    auto res = solution.orangesRotting(grid);
    cout << res << "\n";
}
