#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int leftshift = 1;
        int res = 0;
        for (int i = 0; i < 32; ++ i ) {
            int c = 0;
            int mask = 1 << i;
            for (int j = 0 ; j < nums.size(); j ++ ) {
                if ( nums[j] & mask ) { c ++; }
            }
            if (c % 2 != 0) {res += leftshift; }
            leftshift *= 2; 
        }
        return res;
    }
};