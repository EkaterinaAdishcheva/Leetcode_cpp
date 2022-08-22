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
    void preorderTraversalStep(TreeNode* head, vector<int> &result) {
        if (head == nullptr) {
            return;
        }
        result.push_back(head->val);
        preorderTraversalStep(head->left, result);
        preorderTraversalStep(head->right, result);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalStep(root, result);
        return result;        
    }
};