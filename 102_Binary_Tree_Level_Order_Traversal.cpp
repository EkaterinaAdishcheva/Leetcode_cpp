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
    void addNode(TreeNode* head, int level, vector<vector<int>> &result) {
        
        if (head == nullptr) {
            return;
        }
        if (result.size() < (level + 1) ) {
            vector<int> new_level;
            result.push_back(new_level);
        }
        result[level].push_back(head->val);
        addNode(head->left, level + 1, result);
        addNode(head->right, level + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        addNode(root, 0, result);
        return result;
    }
};