#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        

        stack<TreeNode*> nodeMin;
        stack<TreeNode*> nodeMax;
        TreeNode* current;
        current = root;
        while (current != nullptr) {
            nodeMin.push(current);
            current = current->left;
        }
        current = root;
        while (current != nullptr) {
            nodeMax.push(current);
            current = current->right;
        }

        while(nodeMin.top()->val + nodeMax.top()->val != k && nodeMin.top()->val < nodeMax.top()->val) {
            cout << nodeMin.top()->val << "\t" << nodeMax.top()->val << "\n";
            if ( nodeMin.top()->val + nodeMax.top()->val < k ) {
                if (nodeMin.top()->right != nullptr) {
                    current = nodeMin.top()->right;
                    nodeMin.pop();
                    
                    while (current != nullptr ) {
                        nodeMin.push(current);
                        current = current->left;
                    }
                } else {
                    nodeMin.pop();
                    nodeMin.top()->left = nullptr;
                }
            } else {
                if (nodeMax.top()->left != nullptr) {
                    current = nodeMax.top()->left;
                    nodeMax.pop();
                    while (current != nullptr ) {
                        nodeMax.push(current);
                        current = current->right;
                    }
                } else {
                    nodeMax.pop();
                    nodeMax.top()->right = nullptr;
                }
            }
        }
        if ( nodeMin.top()->val + nodeMax.top()->val != k && nodeMin.top()->val < nodeMax.top()->val ) {
            return true;
        }
        return false;
    }
};