// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//   int kthSmallest(TreeNode *root, int k) {
//     TreeNode *curr = root;
//     int count = 0;
//     int arr[count];
//     while (curr->left != NULL) {
//       arr[count] = curr->val
//       curr = curr->left;
//       count++;
//     }
//     return arr[k - 1];
//   }
// };

// int main() {
//   Solution s;
//   // Constructing tree:
//   //       3
//   //      / \
//     //     1   4
//   //    / \
//     //   0   2
//   TreeNode *root = new TreeNode(3);
//   root->left = new TreeNode(1);
//   root->right = new TreeNode(4);
//   root->left->right = new TreeNode(2);
//   // Note: new TreeNode(NULL) becomes new TreeNode(0) because NULL is 0
//   root->left->left = new TreeNode(0);

//   // 1st smallest element should be 0
//   cout << "Kth smallest: " << s.kthSmallest(root, 1) << endl;

//   // Clean up memory (simple approach for this demo)
//   delete root->left->left;
//   delete root->left->right;
//   delete root->left;
//   delete root->right;
//   delete root;
// }

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
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
    int kthSmallest(TreeNode *root, int k) {
        TreeNode *curr = root;
        int count = 1;
        vector<int> arr;   

        while (curr != nullptr || curr != 0) {
            arr.push_back(curr->val);   
            curr = curr->left;          
            count++;
        }
        sort (arr.begin() , arr.end());
        if (k <= count)
            return arr[k - 1];

        return -1; 
    }
};

int main() {
    Solution s;

    //       3
    //      / \
    //     1   4
    //    / \
    //   0   2
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    // root->left->left = new TreeNode(0);

    cout << "Kth smallest: " << s.kthSmallest(root, 1) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}
