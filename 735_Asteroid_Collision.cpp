#include <vector>
#include <iostream>
#include <stack>

using namespace std;



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        bool checker;
        for (auto ast: asteroids) {
            checker = true;
            while (!ans.empty() && ast < 0 && ans[ans.size() - 1] > 0) {
                if (ans[ans.size() - 1] < -ast) {
                    ans.pop_back();
                    continue;
                } else if (ans[ans.size() - 1] == -ast) {
                    ans.pop_back();
                }
                checker = false;
                break;
            }
            if (checker) {
                ans.push_back(ast);    
            }
        } 
        return ans;
    }
};

void main() {
    vector<int> asteroids = {5, 10, -5};
    Solution solution;
    vector<int> asteroids_remain = solution.asteroidCollision(asteroids);
    for (int i = 0 ; i < asteroids_remain.size(); i ++) {
        cout << asteroids_remain[i] << "\t";
    }
    cout << "\n";
}
