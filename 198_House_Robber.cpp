#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> sumAmount;
        sumAmount.push_back(nums[nums.size() - 1]);
        if (nums.size() > 1) {
           sumAmount.push_back(max(nums[nums.size() - 1], nums[nums.size() - 2]));
        
            for (int i = 2; i < nums.size(); i ++ ) {
                sumAmount.push_back(max(
                    sumAmount[i - 1], (sumAmount[i - 2] + nums[nums.size() - 1 - i])
                    ));
            }
        }
        return sumAmount[nums.size() - 1];
    }
};