# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):

    def DFS(self, preorder, inorder):
        if not preorder or not inorder:
            return None

        # root is always first element in preorder
        root = TreeNode(preorder[0])

        # find root in inorder
        root_index = 0
        for i in range(len(inorder)):
            if inorder[i] == root.val:
                root_index = i
                break

        # split inorder
        left_inorder = inorder[:root_index]
        right_inorder = inorder[root_index + 1:]

        # split preorder based on inorder sizes
        left_preorder = preorder[1: 1 + len(left_inorder)]
        right_preorder = preorder[1 + len(left_inorder):]

        # recursive calls
        root.left = self.DFS(left_preorder, left_inorder)
        root.right = self.DFS(right_preorder, right_inorder)

        return root

    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Optional[TreeNode]
        """
        if not preorder or not inorder:
            return None

        return self.DFS(preorder, inorder)


def print_inorder(root):
    if not root:
        return
    print_inorder(root.left)
    print(root.val, end=" ")
    print_inorder(root.right)

s = Solution()
root = s.buildTree(
    preorder=[3, 9, 20, 15, 7],
    inorder=[9, 3, 15, 20, 7]
)

print_inorder(root)
# Output: 9 3 15 20 7
