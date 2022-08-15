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
    void treeToList(TreeNode* root, vector<int>* tree_list) {
        if (root == nullptr) { return; }
        treeToList(root->left, tree_list);
        tree_list->push_back(root->val);
        treeToList(root->right, tree_list);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        treeToList(root, &res);
        return res[k-1];        
    }
};