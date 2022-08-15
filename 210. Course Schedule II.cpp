#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    bool findNextCourse( vector<vector<int>>& adjusted, vector<bool>& active_course, vector<vector<int>>& coursers_order ) {
        vector<int> res;
        for (int i = 0 ; i < adjusted.size() ; i ++ ) {
            if (active_course[i]) {
                if ( adjusted[i].size() == 0 ) {
                    res.push_back(i);
                    active_course[i] = false;
                }
            }
        }

        if (res.size() == 0) {
            return false;
        }
        coursers_order.push_back(res);
        return true;
    }

    void deleteCoursers( vector<vector<int>>& adjusted, vector<int>& courses ) {
        for (auto c: courses) {
            for (int i = 0 ; i < adjusted.size(); i ++ ) {
                auto index =  find(adjusted[i].begin(), adjusted[i].end(), c);
                if  ( index != adjusted[i].end() ) {
                    adjusted[i].erase(index);
                }
            }
        }
    }

    bool checkLastLevel(vector<bool>& active_course) {
        bool res = true;
        for (int i = 0 ; i < active_course.size(); i ++ ) {
            if (active_course[i]) {
                res = false;
                break;
            }            
        }

        return res;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjusted(numCourses);
        vector<bool> active_course(numCourses, true);

        for ( int i = 0 ; i < prerequisites.size(); i ++ ) {
            adjusted[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<vector<int>> coursers_order;
        
        bool last_level = false;
        bool find_counrse = false;
        
        while ( !last_level ) {
            find_counrse = findNextCourse(adjusted, active_course, coursers_order);
            if ( !find_counrse ) {
                break;
            }
            deleteCoursers(adjusted, coursers_order[coursers_order.size() - 1]);
            last_level = checkLastLevel(active_course);
        }

        if (!find_counrse) {
            return {};
        }

        vector<int> res;
        for (auto i = 0; i < coursers_order.size(); i ++ ) {
            for (auto j = 0; j < coursers_order[i].size(); j ++ ) {
                res.push_back(coursers_order[i][j]);
            }
        }

        return res;
    }
};

void main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}, {0, 1}};
    Solution solution;
    auto res = solution.findOrder(numCourses, prerequisites);
    for (int i = 0 ; i < res.size(); i ++ ) {
        cout << res[i] << "\t";
    }
    cout <<  "\n";
}