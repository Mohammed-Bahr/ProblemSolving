"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None

        # Step 1: Create new nodes and insert them next to original nodes
        current = head
        while current:
            new_node = Node(current.val)
            new_node.next = current.next
            current.next = new_node
            current = new_node.next

        # Step 2: Assign random pointers for the new nodes
        current = head
        while current:
            if current.random:
                current.next.random = current.random.next
            current = current.next.next

        # Step 3: Separate the two lists
        original = head
        copy_head = head.next
        copy_current = copy_head

        while original:
            original.next = original.next.next
            if copy_current.next:
                copy_current.next = copy_current.next.next
            original = original.next
            copy_current = copy_current.next

        return copy_head
        