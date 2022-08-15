#include <iostream>
using namespace std;

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
        if (root == nullptr) {return true; }
        auto lengthL = getLength(root->left);
        auto lengthR = getLength(root->right);
        
        auto res = isBalanced(root->left) && isBalanced(root->right) && abs(lengthL - lengthR) <= 1;
            
        return res;    
    }
    

private:
    int getLength(TreeNode* root) {
        if (root == nullptr) {return 0; }

        auto lengthL = getLength(root->left);
        auto lengthR = getLength(root->right);
        
        auto res = max(lengthL, lengthR) + 1;
        
        return res;
    }
};