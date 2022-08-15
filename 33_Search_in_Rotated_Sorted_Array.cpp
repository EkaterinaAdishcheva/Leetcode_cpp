#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) {return 0;}
            else {return -1;}
        }
        auto start = 0;
        auto end = nums.size();
        
        while (start < end - 1) {
            auto middle = start + (end - start) / 2;
            if (nums[start] <= nums[middle - 1]) {
                if (nums[start] <= target && nums[middle - 1] >= target) {
                    end = middle;
                } else {
                    start = middle;
                }
            } else {
                if (nums[middle] <= target && nums[end - 1] >= target) {
                    start = middle;
                } else {
                    end = middle;
                }
            }
        }
        if (nums[start] == target) {return start;}
        return -1;
    }
};

void main() {
    vector<int> nums = {6, 7, 4};
    auto target = 4;
    Solution solution;
    auto res = solution.search(nums, target);
    cout << res << "\n";
}