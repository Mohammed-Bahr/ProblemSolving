// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//
//         if (root == nullptr)
//             return nullptr;
//
//         // Search for the node
//         if (key < root->val) {
//             root->left = deleteNode(root->left, key);
//         }
//         else if (key > root->val) {
//             root->right = deleteNode(root->right, key);
//         }
//         else {
//             // We found the node
//
//             // Case 1: No left child
//             if (root->left == nullptr) {
//                 TreeNode* temp = root->right;
//                 delete root;
//                 return temp;
//             }
//
//             // Case 2: No right child
//             if (root->right == nullptr) {
//                 TreeNode* temp = root->left;
//                 delete root;
//                 return temp;
//             }
//
//             // Case 3: Two children
//             // Find the largest element in the left subtree
//             TreeNode* largest = root->left;
//
//             while (largest->right != nullptr) {
//                 largest = largest->right;
//             }
//
//             // Copy predecessor's value
//             root->val = largest->val;
//
//             // Delete the predecessor
//             root->left = deleteNode(root->left, largest->val);
//         }
//
//         return root;
//     }
// };


#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        // Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // We found the node

            // Case 1: No left child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: No right child
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            // Find the largest element in the left subtree
            TreeNode* largest = root->left;
            while (largest->right != nullptr) {
                largest = largest->right;
            }

            // Copy predecessor's value
            root->val = largest->val;

            // Delete the predecessor
            root->left = deleteNode(root->left, largest->val);
        }

        return root;
    }
};

// Build a binary tree from level-order array with "null" for empty nodes
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

// Print tree in level-order, using "null" for empty nodes
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]";
        return;
    }

    vector<string> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        if (cur == nullptr) {
            res.push_back("null");
        } else {
            res.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        }
    }

    // Remove trailing "null"s
    while (!res.empty() && res.back() == "null") {
        res.pop_back();
    }

    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        if (i > 0) cout << ",";
        cout << res[i];
    }
    cout << "]";
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Example:
    // Input: root = [5,3,6,2,4,null,7], key = 3
    vector<string> nodes = {"5", "3", "6", "2", "4", "null", "7"};
    int key = 3;

    TreeNode* root = buildTree(nodes);

    Solution sol;
    root = sol.deleteNode(root, key);

    cout << "Output: ";
    printLevelOrder(root);
    cout << endl;

    // One valid output for this implementation:
    // [5,2,6,null,4,null,7]

    deleteTree(root);
    return 0;
}
