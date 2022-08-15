/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto res = getLength(root) >= 0;
        return res;
    }
    

private:
    int getLength(TreeNode* root) {
        if (root == nullptr) {return 0; }

        auto lengthL = getLength(root->left);
        if (lengthL == -1) {return -1;}

        auto lengthR = getLength(root->right);
        if (lengthR == -1) {return -1;}
        
        if (abs(lengthL - lengthR) >1 ) {return -1;}
        auto res = max(lengthL, lengthR) + 1;
        
        return res;
    }
};