// # include <bits/stdc++.h>
// using namespace std;
// // Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// class Solution
// {
//     bool compareTrees(TreeNode *p, TreeNode *q)
//     {
//         if(p ==nullptr)
//             return false;
//         if (p->val != q->val)
//             return false;
//         else{
//             if (p->left->val == q->left->val && p->right->val == q->right->val)
//                 return true;
//             else
//                 return false;
//         }

//         return compareTrees(p->left , q) && compareTrees(p->right, q);
//     }

// public:
//     bool isSubtree(TreeNode *root, TreeNode *subRoot)
//     {
//         TreeNode *current = root;
//         if (!current)
//             return false;
        
//         bool result = compareTrees(current, subRoot);
//         if (result)
//             return true;
//         else
//             return isSubtree(current->left, subRoot) || isSubtree(current->right, subRoot);
//     }
// };



// int main()
// {
//     // Example usage:
//     TreeNode *root = new TreeNode(3);
//     root->left = new TreeNode(4);
//     root->right = new TreeNode(5);
//     root->left->left = new TreeNode(1);
//     root->left->right = new TreeNode(2);

//     TreeNode *subRoot = new TreeNode(4);
//     subRoot->left = new TreeNode(1);
//     subRoot->right = new TreeNode(2);

//     Solution sol;
//     bool isSubtree = sol.isSubtree(root, subRoot);
//     cout << (isSubtree ? "Is Subtree" : "Not Subtree") << endl;

//     return 0;
// }








#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
    bool compareTrees(TreeNode *p, TreeNode *q)
    {
        // both null → equal
        if (!p && !q)
            return true;

        // one null → not equal
        if (!p || !q)
            return false;

        // values differ
        if (p->val != q->val)
            return false;

        // compare left and right subtrees
        return compareTrees(p->left, q->left) &&
               compareTrees(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        // check if trees match starting here
        if (compareTrees(root, subRoot))
            return true;

        // otherwise check left and right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    bool isSubtree = sol.isSubtree(root, subRoot);
    cout << (isSubtree ? "Is Subtree" : "Not Subtree") << endl;

    return 0;
}
