class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        for i in nums:
            if i == 0:
                nums.remove(i)
                nums.append(0)
        
        
def main():
    sol = Solution()
    nums = [0,1,0,3,12]
    sol.moveZeroes(nums)
    print(nums)


if __name__ == "__main__":
    main()

