#include <vector>
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
    void addNode(TreeNode* node, int level, vector<vector<int>>* nodes) {
        if (node->left) {
            addNode(node->left, level + 1, nodes);
        }
        if (nodes->size() < level + 2) {
            vector<int> v;
            nodes->push_back(v);
        }
        (*nodes[level])->push_back(node->val);
        if (node->right) {
            addNode(node->right, level + 1, nodes);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<vector<int>> nodes;
        vector<int> rightNodes;
        addNode(root, 0, nodes);
        for (int i = 0 ; i < nodes.size(); i ++) {
            rightNodes.push_back(nodes[i].pull_back());
        }
        return rightNodes;
    }
};