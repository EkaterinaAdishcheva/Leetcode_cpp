struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    
        TreeNode *res = root;
        if (root == nullptr) {
            res = new TreeNode(val);
            return res;
        }
        while(root != nullptr) {
            if (val > root->val) {
                if (root->right == nullptr) {
                    root->right = new TreeNode(val);
                    return res;
                }
                root = root->right;
            } else {
                if (root->left == nullptr) {
                    root->left = new TreeNode(val);
                    return res;
                }
                root = root->left;
            }
        }
        return res;
    }
};