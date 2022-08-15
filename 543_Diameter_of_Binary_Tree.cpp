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
private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto res = max(height(root->left), height(root->right)) + 1;
        return res;
    }

    int diameter(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto heightL = height(root->left);
        auto heightR = height(root->right);

        auto res = max(diameter(root->left), diameter(root->right));
        res = max(res, heightL + heightR + 1);
        
        return res;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto res = diameter(root);
        return res - 1; 
    }
};