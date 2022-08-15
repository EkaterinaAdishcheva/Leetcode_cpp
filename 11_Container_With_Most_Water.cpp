#include <vector>
#include <map>

using namespace std; 

class Solution {
public:

    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int current_area = (right - left) * min (height[left], height[right]);
            if ( current_area > res ) {
                res = current_area;
            } 
            if (height[left] > height[right]) {
                right -= 1;
            } else {
                left += 1;
            }
        }
        return res;
    }
};