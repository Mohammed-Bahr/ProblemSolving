# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# class Solution(object):
#     def isValid(self, root , minValue , maxValue):
#         if not root:
#             return True

  

#         if root.right and root.right.val <= root.val:
#             return False

#         if root.left and root.left.val >= root.val:
#             return False

#         if root.val > maxValue

#         if not self.isValid(root.left):
#             return False

#         if not self.isValid(root.right):
#             return False

#         return True

#     def isValidBST(self, root):
#         return self.isValid(root)


# root = TreeNode(2)
# root.left = TreeNode(1)
# root.right = TreeNode(3)
# # root.right.left = TreeNode(3)   
# # root.right.right = TreeNode(6)

# print(Solution().isValidBST(root))  # False






class Solution(object):
    def isValid(self, root, low=float('-inf'), high=float('inf')):
        if not root:
            return True

        if not (low < root.val < high):
            return False

        return (self.isValid(root.left, low, root.val) and
                self.isValid(root.right, root.val, high))

    def isValidBST(self, root):
        return self.isValid(root)







root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.right.left = TreeNode(6)
root.right.right = TreeNode(20)

print(Solution().isValidBST(root))
