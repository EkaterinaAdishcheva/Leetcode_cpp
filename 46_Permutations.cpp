#include <vector>

using namespace std;

class Solution {
public:
    void generatePermutation(
        vector<int>& nums,
        vector<vector<int>>& result,
        vector<int> permutation,
        vector<bool> availableNums) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
        }
        for (int i = 0 ; i < nums.size(); i ++ ) {
            if (availableNums[i]) {
                availableNums[i] = false;
                permutation.push_back(nums[i]);
                generatePermutation(nums, result, permutation, availableNums);
                permutation.pop_back();
                availableNums[i] = true;
            }
        } 
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> availableNums (nums.size(), true);
        generatePermutation(nums, result, permutation, availableNums);
    }
};