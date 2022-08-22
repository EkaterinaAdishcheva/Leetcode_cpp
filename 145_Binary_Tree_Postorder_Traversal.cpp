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
    void postorderTraversalStep(TreeNode* head, vector<int> &result) {
        if (head == nullptr) {
            return;
        }
        postorderTraversalStep(head->left, result);
        postorderTraversalStep(head->right, result);
        result.push_back(head->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalStep(root, result);
        return result;      
    }
};