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
class BSTIterator {
    vector<int> treeNodeList;
    vector<int>::iterator it;
    
    void generateListFromTreeNode(TreeNode* node) {
        if (node == nullptr) {return; }
        generateListFromTreeNode(node->left);
        treeNodeList.push_back(node->val);
        generateListFromTreeNode(node->right);
    }
public:    
    BSTIterator(TreeNode* root) {
        generateListFromTreeNode(root);
        it = treeNodeList.begin();
    }
    
    int next() {
        return (*(it++)); 
    }
    
    bool hasNext() {
        if (it == treeNodeList.end()) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */