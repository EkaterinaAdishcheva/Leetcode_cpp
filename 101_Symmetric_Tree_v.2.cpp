class Solution {
private:
    bool checkNode(TreeNode* node_p, TreeNode* node_q) {
        if (node_p->val != node_q->val) { return false; }
        if (node_p->left != nullptr && node_q->right == nullptr) { return false; }
        if (node_p->right != nullptr && node_q->left == nullptr) { return false; }
        if (node_q->left != nullptr && node_p->right == nullptr) { return false; }
        if (node_q->right != nullptr && node_p->left == nullptr) { return false; }
        if (node_q->right != nullptr) { 
            auto res = checkNode(node_p->left, node_q->right);
            if (res == false) {return false; } 
        };
        if (node_q->left != nullptr) { 
            auto res = checkNode(node_p->right, node_q->left);
            if (res == false) {return false; } 
        };
        return true;
    };
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {return true;}
        if (root->right == nullptr && root->left == nullptr) {return true;}
        if (root->right == nullptr && root->left != nullptr) {return false;}
        if (root->right != nullptr && root->left == nullptr) {return false;}

        auto res = checkNode(root->right, root->left);
        return res;
    }         
};