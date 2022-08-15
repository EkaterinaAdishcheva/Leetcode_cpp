#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_VALUE = 1000;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDelta = INT_MAX;
        int closestSum = INT_MAX;

        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() - 2; i ++) {
            auto j = i + 1;
            auto k = nums.size() - 1;
            while ( j < k ) {
                auto sum = nums[i] + nums[j] + nums[k];
                if (target == sum ) {
                    return target;
                } 
                if (target < sum ) {
                    auto d = abs(target - sum);
                    if ( d < minDelta ) {
                        minDelta = d;
                        closestSum = sum;
                    }
                    j ++;
                } else if (target > sum ) {
                    auto d = abs(target - sum);
                    if ( d < minDelta ) {
                        minDelta = d;
                        closestSum = sum;
                    }
                    k --;
                }
            } 
        }
        return closestSum;
    }
};

void main() {
    vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    int target = -2;
    Solution solution;
    auto res = solution.threeSumClosest(nums, target);
    cout << res << "\n";
}


