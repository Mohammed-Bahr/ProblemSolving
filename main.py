class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        def binary_search(arr, left, right, key):
            if right < left:
                return -1
            mid = (left + right) // 2
            if arr[mid] == key:
                return mid
            elif key > arr[mid]:
                return binary_search(arr, mid + 1, right, key)
            else:
                return binary_search(arr, left, mid - 1, key)
        
        return binary_search(nums, 0, len(nums) - 1, target)
        