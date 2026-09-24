// Definition for a binary tree node.
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }
    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};

void inorder(TreeNode *root) {
  if (root == nullptr) return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main() {
  Solution solution;

  // Build the example tree:
  // root = [4,2,7,1,3]
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  int val = 5;

  // Insert 5 into the BST
  root = solution.insertIntoBST(root, val);

  // Expected inorder traversal: 1 2 3 4 5 7
  inorder(root);
  cout << endl;

  // The new node should be 7's left child
  cout << "Inserted node value: " << root->right->left->val << endl;

  return 0;
}
