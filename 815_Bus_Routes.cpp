#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void calculateNumBuses(vector<vector<int>>& routes, int target, vector<int>& stopsNumBuses) {
        
        for (int steps = 0; steps < routes.size(); steps ++ ) {
            for (int i = 0 ; i < routes.size(); i ++) {
                auto min_route = -1;
                for (int j = 0 ; j < routes[i].size(); j ++) {
                    if ( ( min_route == -1 || stopsNumBuses[routes[i][j]] < min_route ) && stopsNumBuses[routes[i][j]] != -1) {
                        min_route = stopsNumBuses[routes[i][j]];
                    }
                }
                if (min_route != -1) {
                    for (int j = 0 ; j < routes[i].size(); j ++) {
                        if (stopsNumBuses[routes[i][j]] != min_route) {
                            stopsNumBuses[routes[i][j]] = min_route + 1;
                        }
                    }
                }
            }
        }
    }

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<int> stopsNumBuses(100001, -1);
        stopsNumBuses[source] = 0;

        calculateNumBuses(routes, target, stopsNumBuses);
        return stopsNumBuses[target];
    }
};

void main() {
    vector<vector<int>> routes = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    int source = 15;
    int target = 12;
    Solution solution;
    auto res = solution.numBusesToDestination(routes, source, target);
    cout << res << "\n"; 
}
