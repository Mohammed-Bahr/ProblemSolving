# Definition for a binary tree node.
from collections import deque
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def BFS (self , root , level, res):
        if not root :
            return
        if level == len(res):
            res.append(root.val)
            
        self.BFS(root.right , level + 1 , res)
        self.BFS(root.left , level + 1 , res)

    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        res = deque()
        level = 0

        self.BFS(root , level , res)
        
        return list(res)


# Build the binary tree
#        1
#       / \
#      2   3
#       \   \
#        5   4

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.left.left = TreeNode(5)

# Create Solution instance
sol = Solution()
result = sol.rightSideView(root)

print(result)  # Output should be [1, 3, 4]
