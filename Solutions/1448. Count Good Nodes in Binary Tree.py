# # Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


# class Solution(object):
#     result = 0

#     def DFS(self , root , max):
#         if not root :
#             return 0
#         if root.val >= max:
#             max = root.val
#             global result
#             result += 1
        
#         self.DFS(root.left , max)
#         self.DFS(root.right , max)
#         return result


        
#     def goodNodes(self, root):
#         """
#         :type root: TreeNode
#         :rtype: int
#         """
#         res = self.DFS(root , root.val)
#         return res


# sol = Solution()

# root = TreeNode(3)
# root.left = TreeNode(1)
# root.right = TreeNode(4)
# root.right.right = TreeNode(5)
# root.right.left = TreeNode(1)
# root.left.left = TreeNode(3)



# print(sol.goodNodes(root))







# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def DFS(self, root, max_val):
        if not root:
            return
        
        if root.val >= max_val:
            self.result += 1
            max_val = root.val
        
        self.DFS(root.left, max_val)
        self.DFS(root.right, max_val)

    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.result = 0   
        self.DFS(root, root.val)
        return self.result


sol = Solution()

root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.right.right = TreeNode(5)
root.right.left = TreeNode(1)
root.left.left = TreeNode(3)

print(sol.goodNodes(root))
