#include <vector>
using namespace std;

class Solution {
public:
    void generateSum(vector<int>& candidates, int start, vector<int> sum, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(sum);
            return;
        }
        if (target < 0) {
            return;
        }
        for ( int i = start; i < candidates.size(); i ++ ) {
            sum.push_back(candidates[i]);
            generateSum(candidates, i, sum, target - candidates[i], result);
            sum.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sum;
        generateSum(candidates, 0, sum, target, result);
        return result;
    }
};

void main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution solution;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
}