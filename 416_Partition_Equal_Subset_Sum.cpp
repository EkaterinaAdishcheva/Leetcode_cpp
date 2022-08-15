#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

class Solution {

private:
    bool checkSums(vector<int>& nums, int position, int target, vector<bool>& sums) {
        int n = sums.size();
        if (position == -1) {
            return false;
        }
        // cout << "nums[position]" << nums[position] << "\n";
 
        if ( target - nums[position] >=0 && target - nums[position] < n && sums[target - nums[position]] ) {
            return true;    
        }
        int start = min(n, target - nums[position]);
        for (int i = start - 1; i >= 0; i -- ) {
            if (sums[i]) {
                sums[nums[position] + i] = true;
            }
        }
        sums[nums[position]] = true;
        if (nums[position] == target) {
            return true;
        }
        // for (int i = 0; i < sums.size(); i ++ ) {
        //     if (sums[i]) {
        //         cout << i << "\t";
        //     }
        // }
        // cout << "\n";

        bool res = checkSums(nums, position-1, target, sums);
        return res;
    }

public:
    bool canPartition(vector<int>& nums) {
        vector<bool> sums(nums.size() * 100, false);
        int numsSum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size(); i ++) {
            numsSum += nums[i];
        }
        if (numsSum % 2 == 1) {return false;}
        int halfSum = numsSum / 2;
        cout << "halfSum:\t" << halfSum << "\n";

        bool res = checkSums(nums, nums.size()-1, halfSum, sums);
        return res;            
    }
};


void main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 5, 5, 5};
    auto res = solution.canPartition(nums);
    cout << res << "\n";
}