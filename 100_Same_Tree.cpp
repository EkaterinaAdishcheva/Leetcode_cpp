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
    bool checkNode(TreeNode* node_p, TreeNode* node_q) {
        if (node_p->val != node_q->val) { return false; }
        if (node_p->left != nullptr && node_q->left == nullptr) { return false; }
        if (node_p->right != nullptr && node_q->right == nullptr) { return false; }
        if (node_q->left != nullptr && node_p->left == nullptr) { return false; }
        if (node_q->right != nullptr && node_p->right == nullptr) { return false; }
        if (node_q->right != nullptr) { 
            auto res = checkNode(node_p->right, node_q->right);
            if (res == false) {return false; } 
        };
        if (node_q->left != nullptr) { 
            auto res = checkNode(node_p->left, node_q->left);
            if (res == false) {return false; } 
        };
        return true;
    };
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {return true;}
        if (p == nullptr && q != nullptr) {return false;}
        if (p != nullptr && q == nullptr) {return false;}

        auto res = checkNode(p, q);
        return res;
    }         
};