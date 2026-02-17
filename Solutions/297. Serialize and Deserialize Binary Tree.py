# Definition for a binary tree node.
from asyncio.windows_events import NULL
from tokenize import String


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def DFS(self, node):
        if not node:
            self.result.append("null")
            return
        self.result.append(str(node.val))
        self.DFS(node.left)
        self.DFS(node.right)

        

    def serialize(self, root):
        self.result = []         
        self.DFS(root)
        return ",".join(self.result) 


    def deserialize(self, data):
        values = data.split(",")
        self.index = 0

        def dfs():
            if values[self.index] == "null":
                self.index += 1
                return None

            node = TreeNode(int(values[self.index]))
            self.index += 1
            node.left = dfs()
            node.right = dfs()
            return node

        return dfs()


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))


# Example:
# Tree: [1,2,3,null,null,4,5]

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)

codec = Codec()

s = codec.serialize(root)
print(s)  # serialized string

new_root = codec.deserialize(s)
print(codec.serialize(new_root))  # should be same
