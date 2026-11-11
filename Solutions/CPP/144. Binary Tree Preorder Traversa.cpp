#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <optional>
#include <cassert>
using namespace std;

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            TreeNode* nt = stk.top(); stk.pop();
            result.push_back(nt->val);
            if (nt->right) stk.push(nt->right);
            if (nt->left) stk.push(nt->left);
        }
        return result;
    }
};

TreeNode* buildTree(const vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value()) return nullptr;
    TreeNode* root = new TreeNode(*arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < arr.size() && arr[i].has_value()) {
            cur->left = new TreeNode(*arr[i]);
            q.push(cur->left);
        }
        i++;
        if (i < arr.size() && arr[i].has_value()) {
            cur->right = new TreeNode(*arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "]" << endl;
}

int main() {
    vector<optional<int>> root = {1, 2, 3, 4, 5, nullopt, 8, nullopt, nullopt, 6, 7, 9};
    TreeNode* tree = buildTree(root);
    Solution sol;
    vector<int> result = sol.preorderTraversal(tree);
    vector<int> expected = {1, 2, 4, 5, 6, 7, 3, 8, 9};
    printVector(result);
    assert(result == expected);
    cout << "PASS" << endl;
    return 0;
}
