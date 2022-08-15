#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_VALUE = 1000;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minNums = nums[0];
        int maxNums = nums[nums.size() - 1];
        
        vector<int> sumOne(2 * MAX_VALUE, false);
        
        for (int i = 0 ; i < nums.size() ; i ++ ) {
            sumOne[nums[i] + MAX_VALUE] = true;
        }

        int res = INT_MAX;
        int minDifference = INT_MAX;
        
        for (int i = 0 ; i < nums.size() - 2; i ++ ) {
            for (int j = i + 1 ; j < nums.size() - 1 ; j ++ ) {
                int diff = 0;
                auto n3 = target - nums[i] - nums[j];
                while ((n3 - diff >= nums[j + 1] || n3 + diff <= maxNums ) && diff < minDifference) {
                    if (n3 - diff >= nums[j + 1] && sumOne[n3 - diff + MAX_VALUE] && n3 - diff <= maxNums) {
                        minDifference = diff;
                        res = target - diff;
//                        cout << nums[i] << "\t" << nums[j] << "\t" << (n3 - diff) << ": -" <<  diff << "\n";
                        break;
                    }
                    if (diff > 0 && n3 + diff <= maxNums && sumOne[n3 + diff + MAX_VALUE] && n3 + diff >= nums[j + 1]) {
                        minDifference = diff;
                        res = target + diff;
//                        cout << nums[i] << "\t" << nums[j] << "\t" << (n3 + diff) << ": +" <<  diff << "\n";
                        break;
                    }
                    diff ++;
                }
                if (minDifference == 0 ) {
                    return target;
                }
            }
        }
        return res;
    }
};

void main() {
    vector<int> nums = {-461,80,-437,-405,393,-653,-436,-493,-972,28,483,360,-810,857,508,-86,105,-930,-580,592,342,-476,373,-225,-171,-414,-247,-694,-674,161,624,-931,318,-107,-693,-221,685,-28,-853,872,-211,-608,284,-722,669,629,-246,848,-911,-8,-442};
    int target = -9708;
    Solution solution;
    auto res = solution.threeSumClosest(nums, target);
    cout << res << "\n";
}


