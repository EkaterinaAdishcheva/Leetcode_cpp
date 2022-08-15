#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_position;
        map <int, int>::iterator it;
        for (int i = 0 ; i < nums.size(); i ++ )
        {
            it = nums_position.find(nums[i]);
            if (it != nums_position.end()) {
                vector<int>  res = {i, it->second};
                return res;
            }
            nums_position[target - nums[i]] = i;
        }
        vector<int>  res = {-1, -1};
        return res;
    }
};