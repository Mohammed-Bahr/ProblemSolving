class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseBetween(self, head, left, right):

        stc = []

        curr = head
        pos = 1
        while pos < left:
            curr = curr.next
            pos += 1

        temp = curr
        while pos <= right:
            stc.append(temp.val)
            temp = temp.next
            pos += 1

        for v in reversed(stc):
            curr.val = v
            curr = curr.next    

        return head


def main():
    sol = Solution()
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    left = 2
    right = 4
    result = sol.reverseBetween(head, left, right)
    while result:
        print(result.val, end=" ")
        result = result.next

if __name__ == "__main__":
    main()
