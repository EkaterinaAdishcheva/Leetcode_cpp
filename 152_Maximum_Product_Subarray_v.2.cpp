#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max_result = 0;
        int running_min = 0, running_max = 0;
        
        for (int i = 0; i < nums.size() ; i ++ ) {
            int temp = nums[i];

            int running_max_save = max(temp, max(running_max*temp, running_min*temp));
            running_min = min(temp, min(running_max*temp, running_min*temp));
            running_max = running_max_save;

            max_result = max(max_result, running_max); 
        }
        return max_result;
    }
};

void main() {
    vector<int> nums = {-1, -1, 0};

    Solution solution;

    auto res = solution.maxProduct(nums);
    cout << res << "\n";
}