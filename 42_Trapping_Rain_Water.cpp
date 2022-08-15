#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int top_l = INT_MIN, top_r = INT_MIN;
        int sum_top_l = 0, sum_top_r = 0;

        int land_l = 0, land_r = 0;
        while( l <= r) {
            if (top_l < top_r) {
                land_l += height[l];
                if ( height[l] > top_l ) {
                    top_l = height[l];
                }
                sum_top_l += top_l;
                l ++;
            } else {
                land_r += height[r];
                if ( height[r] > top_r ) {
                    top_r = height[r];
                }
                sum_top_r += top_r;
                r --;                
            }
        }

        auto res =  sum_top_l + sum_top_r - land_l - land_r;
        return res;
    }
};

void main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout << solution.trap(height);

}