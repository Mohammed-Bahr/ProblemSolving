from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        res = []
        n = len(nums)
        if n == 1:
            return nums[0]
        if nums[0] > nums[1]:
            res.append([nums[0], 0])
        if nums[n - 1] > nums[n - 2]:
            res.append([nums[n - 1], n - 1])
            
        for i in range(1, n - 1):
            if nums[i] > nums[i + 1] and nums[i] > nums[i - 1]:
                res.append([nums[i] , i])

        res.sort(reverse=True)  
        return res[0][1]


def main():
    nums = [1, 2, 3, 1]
    
    solution = Solution()
    result = solution.findPeakElement(nums)
    
    print("Peak element index:", result)


if __name__ == "__main__":
    main()
