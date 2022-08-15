#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        for (int i = m + n - 1 ; i >= n ; i -- ) {
            nums1[i] = nums1[i - n];
        }
        int p1 = n, p2 = 0;
        for (int i = 0 ; i < n + m ; i ++ )
        {
            if (p1 == n + m) {
                nums1[i] = nums2[p2 ++];
            }
            else if (p2 == n) {
                nums1[i] = nums1[p1 ++];
            }
            else if (nums2[p2] > nums1[p1]) {
                nums1[i] = nums1[p1 ++];
            } else {
                nums1[i] = nums2[p2 ++];
            }
        }
    }
};

void main() {
    vector<int> nums1 = {4,0,0,0,0,0};
    int m = 1;
    vector<int> nums2 = {1,2,3,5,6};
    int n = 5;
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    for (auto a: nums1) {
        cout << a << "\t";
    }
    cout << "\n";
} 