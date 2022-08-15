#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* createBSTNode(vector<int>& nums, int l, int r) {
        if (r == l) {return nullptr;}
        auto m = l + (r - l)/ 2;
        auto node = new TreeNode(nums[m]);
        TreeNode* current_node = node;
        current_node->left = createBSTNode(nums, l, m);
        current_node->right = createBSTNode(nums, m + 1, r);
        return current_node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto n = nums.size();
        TreeNode* head = createBSTNode(nums, 0, n);
        return head;
    }
};