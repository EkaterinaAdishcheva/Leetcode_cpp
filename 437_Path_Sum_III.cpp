#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
Definition for a binary tree node.
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
    int pathNode(TreeNode* node, int targetSum) {
        if (node == nullptr) {return 0;}
        auto add = 0;
        if (node->val == targetSum) {
            add = 1;
        }
        auto res = pathNode(node->left, targetSum - node->val) + pathNode(node->right, targetSum - node->val) + add;
        return res;
    }

    int countPath(TreeNode* head, int targetSum) {
        if (head == nullptr) {return 0;}
        auto res = pathNode(head, targetSum) + pathNode(head->left, targetSum) + pathNode(head->right, targetSum);
        return res;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        auto res = countPath(root, targetSum);
        return res;        
    }
};