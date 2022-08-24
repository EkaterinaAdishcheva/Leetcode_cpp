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
bool checkSymmetrick(TreeNode* rootL, TreeNode* rootR) {
    if ( rootL == nullptr && rootR == nullptr ) {
        return true;
    } 
    if ( rootL != nullptr && rootR != nullptr && rootL->val == rootR->val ) {
        bool res = checkSymmetrick(rootL->left, rootR->right) & 
        checkSymmetrick(rootL->right, rootR->left);
        return res; 
    }
    return false;
}

public:
    bool isSymmetric(TreeNode* root) {
        auto res = checkSymmetrick(root, root);
        return res;
    }         
};