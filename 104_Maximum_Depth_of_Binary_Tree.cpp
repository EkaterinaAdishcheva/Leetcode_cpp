#include <vector>

using namespace std;

/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    int getRootDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depthL = getRootDepth(root->left); 
        int depthR = getRootDepth(root->right);
        int res = max(depthL, depthR) + 1;
        return res;
    }   

public:
    int maxDepth(TreeNode* root) {
        int res;
        res = getRootDepth(root);
        return res;      
    }
};