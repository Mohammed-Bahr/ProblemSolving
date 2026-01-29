from typing import *

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res: int = nums[0] + nums[1] + nums[2]
        n = len(nums)

        for i in range(2, n):
            left , right = i + 1 , n - 1

            while left < right :
                total = nums[i] + nums[left] + nums[right]

                if abs(total - target) < abs(res - target):
                    res = total
                    
                if total < target:
                    left += 1
                elif total > target:
                    right -= 1
                else:
                    return total  
        return res


def main():
    sol = Solution()
    nums = [4,0,5,-5,3,3,0,-4,-5]
    target = -2
    print(sol.threeSumClosest(nums, target))


if __name__ == "__main__":
    main()
