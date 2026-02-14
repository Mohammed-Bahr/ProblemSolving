# # Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class Solution(object):
#     def unNamed (self, root):
#         if not root:
#             return 0
#         res = max(self.unNamed(root.left) , self.unNamed(root.right))

#     def maxPathSum(self, root):
#         """
#         :type root: Optional[TreeNode]
#         :rtype: int
#         """
#         longest_of_leftSubTree = self.unNamed(root.left)
#         longest_of_rightSubTree = self.unNamed(root.right)

#         return longest_of_leftSubTree + longest_of_rightSubTree
        

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def unNamed(self, root):
        if not root:
            return 0

        left = max(0, self.unNamed(root.left))
        right = max(0, self.unNamed(root.right))

        self.max_sum = max(self.max_sum, root.val + left + right)

        return root.val + max(left, right)

    def maxPathSum(self, root):
        self.max_sum = float('-inf')
        self.unNamed(root)
        return self.max_sum


# =========================
# main function (testing)
# =========================
def main():
    # Test Case 1
    # Tree:
    #      1
    #     / \
    #    2   3
    root1 = TreeNode(1, TreeNode(2), TreeNode(3))
    print("Test 1 Output:", Solution().maxPathSum(root1))  # Expected: 6

    # Test Case 2
    # Tree:
    #      -10
    #      /  \
    #     9   20
    #         / \
    #        15  7
    root2 = TreeNode(
        -10,
        TreeNode(9),
        TreeNode(20, TreeNode(15), TreeNode(7))
    )
    print("Test 2 Output:", Solution().maxPathSum(root2))  # Expected: 42

    # Test Case 3
    # Tree:
    #      -3
    root3 = TreeNode(-3)
    print("Test 3 Output:", Solution().maxPathSum(root3))  # Expected: -3


if __name__ == "__main__":
    main()
