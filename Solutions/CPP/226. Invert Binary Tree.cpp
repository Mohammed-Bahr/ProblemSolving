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
    TreeNode* invert(TreeNode* node) {
        if (!node) return nullptr;

        TreeNode* left = invert(node->left);
        TreeNode* right = invert(node->right);

        node->left = right;
        node->right = left;

        return node;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        return invert(root);
    }
};



int main() {
    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution sol;
    TreeNode* invertedRoot = sol.invertTree(root);

    // Function to print the tree in level order to verify the result
    queue<TreeNode*> q;
    q.push(invertedRoot);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;

    return 0;
}