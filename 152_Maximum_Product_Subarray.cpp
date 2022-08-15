#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int product_from_first_negative = INT_MIN;
        int profuct_til_last_negative = INT_MIN;
        bool first_negative = false;
        int full_product = INT_MIN;

        int i = 0;

        while (true) {
            if (i == nums.size()) {
                break;
            }
            if (nums[i] == 0) {
  //              cout << full_product << profuct_til_last_negative << product_from_first_negative << "\n"; 
                int max_product_current = max(0, max(full_product, max(
                    profuct_til_last_negative,
                    product_from_first_negative)));
                if (max_product < max_product_current) {
                    max_product = max_product_current;
                }
                cout << max_product << "\n";
                
                product_from_first_negative = INT_MIN;
                profuct_til_last_negative = INT_MIN;
                first_negative = false;
                full_product = INT_MIN;
                
                i ++;
                if (i == nums.size()) {
                    break;
                }
                while (nums[i] == 0){
                    i ++;
                    if (i == nums.size()) {
                        break;
                    }
                }
            } else {
                if ( nums[i] < 0 ) {
                    if (!first_negative) {
                        first_negative = true;
                    }
                    profuct_til_last_negative = full_product;
                }
                full_product = nums[i];
                i ++;
                if (i == nums.size()) {
                    break;
                }
                while (nums[i] != 0) {               
                    if ( nums[i] < 0 ) {
                        profuct_til_last_negative = full_product;
                    }
                    full_product *= nums[i];
                    if (first_negative) {
                        if (product_from_first_negative == INT_MIN) {
                            product_from_first_negative = nums[i];
                        } else { product_from_first_negative *= nums[i]; }
                    }
                    if ( nums[i] < 0 && !first_negative ) {
                        first_negative = true;
                    }
                    i ++;
                    if (i == nums.size()) {
                        break;
                    }
                }
            }
        }
        int max_product_current = max(full_product, max(
            profuct_til_last_negative,
            product_from_first_negative));
    //    cout << max_product_current << "\n";
        if (max_product < max_product_current) {
            max_product = max_product_current;
        }
        return max_product;
    }
};

void main() {
    vector<int> nums = {-1, -1, 0};

    Solution solution;

    auto res = solution.maxProduct(nums);
    cout << res << "\n";
}