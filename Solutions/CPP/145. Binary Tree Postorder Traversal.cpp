#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Definition for a binary tree node.
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
    void dfs(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;

        dfs(root->left, result);   // Left
        dfs(root->right, result);  // Right
        result.push_back(root->val); // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};

// Build tree from level-order array; INT_MIN represents "null"
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == INT_MIN) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)arr.size()) {
        TreeNode* curr = q.front(); q.pop();

        // left child
        if (i < (int)arr.size()) {
            if (arr[i] != INT_MIN) {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;
        }
        // right child
        if (i < (int)arr.size()) {
            if (arr[i] != INT_MIN) {
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

int main() {
    Solution solution;

    // {1,2,3,4,5,null,8,null,null,6,7,9}
    vector<int> input = {1, 2, 3, 4, 5, INT_MIN, 8,
                         INT_MIN, INT_MIN, 6, 7, 9};

    TreeNode* root = buildTree(input);

    vector<int> result = solution.postorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
