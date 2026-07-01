#include <bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
        int checkBalance(TreeNode* node) {
            if (!node) return 0;
    
            int leftHeight = checkBalance(node->left);
            if (leftHeight == -1) return -1; 
    
            int rightHeight = checkBalance(node->right);
            if (rightHeight == -1) return -1; 
    
            if (abs(leftHeight - rightHeight) > 1) return -1; 
    
            return max(leftHeight, rightHeight) + 1;
        }
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};




int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    bool balanced = sol.isBalanced(root);
    cout << (balanced ? "Balanced" : "Not Balanced") << endl;

    return 0;
}