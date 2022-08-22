#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> numsInd(nums.size(), false);
        for (int i = 0 ; i < nums.size(); i ++) {
            if (nums[i] > 0 && nums[i] <= nums.size()) {
                numsInd[nums[i] - 1] = true;
            }
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (numsInd[i] == false) {
                return i + 1;
            }
        }
        return -1;
    }
};