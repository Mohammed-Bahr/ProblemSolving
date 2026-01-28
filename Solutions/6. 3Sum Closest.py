from typing import *

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res: int = nums[0] + nums[1] + nums[2]
        n = len(nums)

        for i in range(2, n):
            
            total = nums[i] + nums[i-1] + nums[i-2]

            if abs(total - target) < abs(res - target):
                res = total

            if res == target:
                return res

        return res


def main():
    sol = Solution()
    nums = [-1, 2, 1, -4]
    target = 1
    print(sol.threeSumClosest(nums, target))


if __name__ == "__main__":
    main()
