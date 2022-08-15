#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> nums_qnt;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums_qnt.find(nums[i]) == nums_qnt.end() ) {
                nums_qnt.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};