#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_int_order;  
        vector<vector<int>> new_intervals;
        if (intervals.size() == 0) {
            new_intervals.push_back({newInterval[0], newInterval[1]});
            return new_intervals;
        }
        bool newIntervalAdded = false;
        if (newInterval[1] < intervals[0][0]) {
            new_intervals.push_back({newInterval[0], newInterval[1]});
            newIntervalAdded = true;
            new_int_order = 0;
        }
        for (int i = 0 ; i < intervals.size(); i ++) {
            if (!newIntervalAdded) {
                if ( intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0] ) {
                    new_intervals.push_back(
                        {
                            min(intervals[i][0], newInterval[0]), 
                            max(intervals[i][1], newInterval[1]), 
                        }
                    );
                    newIntervalAdded = true;
                    new_int_order = new_intervals.size() - 1;
                }
                else {
                    new_intervals.push_back({intervals[i][0], intervals[i][1]});
                    if ( i != intervals.size() - 1 && newInterval[0] > intervals[i][1] &&
                          newInterval[1] < intervals[i + 1][0]) {
                        new_intervals.push_back({newInterval[0], newInterval[1]});
                    }
                }
            } else {
                if (new_intervals[new_int_order][1] >= intervals[i][0] && new_intervals[new_int_order][1] <= intervals[i][1]) {
                    new_intervals[new_int_order][1] = intervals[i][1];
                } else if (new_intervals[new_int_order][1] < intervals[i][0]) {
                    new_intervals.push_back({intervals[i][0], intervals[i][1]});                  
                }
            }
        }
        if (newInterval[0] > intervals[intervals.size()-1][1]) {
            new_intervals.push_back({newInterval[0], newInterval[1]});
            newIntervalAdded = true;
        }
        return new_intervals;
    }
};

void main() {
    Solution solution;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    solution.insert(intervals, newInterval);
};